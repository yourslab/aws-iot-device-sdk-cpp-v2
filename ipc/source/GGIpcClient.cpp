#include <aws/crt/io/Bootstrap.h>
#include <aws/ipc/GGIpcClient.h>

#include <sstream>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace Ipc
        {
            GreengrassIpcClient::GreengrassIpcClient(
                Crt::Io::ClientBootstrap &clientBootstrap,
                Crt::Allocator *allocator) noexcept
                : m_connection(allocator), m_clientBootstrap(clientBootstrap), m_allocator(allocator)
            {
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#InvalidArtifactsDirectoryPathError"),
                    InvalidArtifactsDirectoryPathError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#InvalidRecipeDirectoryPathError"),
                    InvalidRecipeDirectoryPathError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#ComponentNotFoundError"),
                    ComponentNotFoundError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#InvalidTokenError"), InvalidTokenError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#FailedUpdateConditionCheckError"),
                    FailedUpdateConditionCheckError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#ConflictError"), ConflictError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#InvalidArgumentsError"), InvalidArgumentsError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#ResourceNotFoundError"), ResourceNotFoundError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#UnauthorizedError"), UnauthorizedError::s_allocateFromPayload);
                m_greengrassServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("aws.greengrass#ServiceError"), ServiceError::s_allocateFromPayload);
            }

            std::future<RpcError> GreengrassIpcClient::Connect(
                ConnectionLifecycleHandler &lifecycleHandler,
                const Crt::Optional<Crt::String> &ipcSocket,
                const Crt::Optional<Crt::String> &authToken) noexcept
            {
                std::promise<RpcError> initializationPromise;
                EventStreamRpcError baseError = EVENT_STREAM_RPC_SUCCESS;

                Crt::String finalIpcSocket;
                if (ipcSocket.has_value())
                {
                    finalIpcSocket = ipcSocket.value();
                }
                else
                {
                    const char *ipcSocketCStr = std::getenv("AWS_GG_NUCLEUS_DOMAIN_SOCKET_FILEPATH_FOR_COMPONENT");
                    if (ipcSocketCStr == nullptr)
                    {
                        baseError = EVENT_STREAM_RPC_NULL_PARAMETER;
                    }
                    else
                    {
                        finalIpcSocket = Crt::String(ipcSocketCStr);
                    }
                }

                Crt::String finalAuthToken;
                if (authToken.has_value())
                {
                    finalAuthToken = authToken.value();
                }
                else
                {
                    const char *authTokenCStr = std::getenv("SVCUID");
                    if (authTokenCStr == nullptr)
                    {
                        baseError = EVENT_STREAM_RPC_NULL_PARAMETER;
                    }
                    else
                    {
                        finalAuthToken = Crt::String(authTokenCStr);
                    }
                }

                if (baseError)
                {
                    initializationPromise.set_value({baseError, 0});
                    return initializationPromise.get_future();
                }

                /* Encode authToken as JSON. */
                Crt::StringStream authTokenPayloadSS;
                authTokenPayloadSS << "{\"authToken\":\"" << finalAuthToken << "\"}";

                if (!m_clientBootstrap)
                {
                    initializationPromise.set_value({EVENT_STREAM_RPC_INITIALIZATION_ERROR, 0});
                    return initializationPromise.get_future();
                }

                Crt::Io::SocketOptions socketOptions;
                socketOptions.SetSocketDomain(Crt::Io::SocketDomain::Local);
                socketOptions.SetSocketType(Crt::Io::SocketType::Stream);

                ClientConnectionOptions connectionOptions;
                connectionOptions.Bootstrap = &m_clientBootstrap;
                connectionOptions.SocketOptions = std::move(socketOptions);
                connectionOptions.HostName = finalIpcSocket;
                connectionOptions.Port = 0;

                m_connectAmendment.SetPayload(Crt::ByteBufFromCString(authTokenPayloadSS.str().c_str()));
                auto messageAmender = [&](void) -> MessageAmendment & { return m_connectAmendment; };

                return m_connection.Connect(connectionOptions, &lifecycleHandler, messageAmender);
            }

            void GreengrassIpcClient::Close() noexcept { m_connection.Close(); }

            GreengrassIpcClient::~GreengrassIpcClient() noexcept { Close(); }

            SubscribeToIoTCoreOperation GreengrassIpcClient::NewSubscribeToIoTCore(
                SubscribeToIoTCoreStreamHandler &streamHandler) noexcept
            {
                return SubscribeToIoTCoreOperation(
                    m_connection,
                    &streamHandler,
                    m_greengrassServiceModel.m_subscribeToIoTCoreOperationContext,
                    m_allocator);
            }
            ResumeComponentOperation GreengrassIpcClient::NewResumeComponent() noexcept
            {
                return ResumeComponentOperation(
                    m_connection, m_greengrassServiceModel.m_resumeComponentOperationContext, m_allocator);
            }
            PublishToIoTCoreOperation GreengrassIpcClient::NewPublishToIoTCore() noexcept
            {
                return PublishToIoTCoreOperation(
                    m_connection, m_greengrassServiceModel.m_publishToIoTCoreOperationContext, m_allocator);
            }
            SubscribeToConfigurationUpdateOperation GreengrassIpcClient::NewSubscribeToConfigurationUpdate(
                SubscribeToConfigurationUpdateStreamHandler &streamHandler) noexcept
            {
                return SubscribeToConfigurationUpdateOperation(
                    m_connection,
                    &streamHandler,
                    m_greengrassServiceModel.m_subscribeToConfigurationUpdateOperationContext,
                    m_allocator);
            }
            DeleteThingShadowOperation GreengrassIpcClient::NewDeleteThingShadow() noexcept
            {
                return DeleteThingShadowOperation(
                    m_connection, m_greengrassServiceModel.m_deleteThingShadowOperationContext, m_allocator);
            }
            DeferComponentUpdateOperation GreengrassIpcClient::NewDeferComponentUpdate() noexcept
            {
                return DeferComponentUpdateOperation(
                    m_connection, m_greengrassServiceModel.m_deferComponentUpdateOperationContext, m_allocator);
            }
            SubscribeToValidateConfigurationUpdatesOperation GreengrassIpcClient::
                NewSubscribeToValidateConfigurationUpdates(
                    SubscribeToValidateConfigurationUpdatesStreamHandler &streamHandler) noexcept
            {
                return SubscribeToValidateConfigurationUpdatesOperation(
                    m_connection,
                    &streamHandler,
                    m_greengrassServiceModel.m_subscribeToValidateConfigurationUpdatesOperationContext,
                    m_allocator);
            }
            GetConfigurationOperation GreengrassIpcClient::NewGetConfiguration() noexcept
            {
                return GetConfigurationOperation(
                    m_connection, m_greengrassServiceModel.m_getConfigurationOperationContext, m_allocator);
            }
            SubscribeToTopicOperation GreengrassIpcClient::NewSubscribeToTopic(
                SubscribeToTopicStreamHandler &streamHandler) noexcept
            {
                return SubscribeToTopicOperation(
                    m_connection,
                    &streamHandler,
                    m_greengrassServiceModel.m_subscribeToTopicOperationContext,
                    m_allocator);
            }
            GetComponentDetailsOperation GreengrassIpcClient::NewGetComponentDetails() noexcept
            {
                return GetComponentDetailsOperation(
                    m_connection, m_greengrassServiceModel.m_getComponentDetailsOperationContext, m_allocator);
            }
            PublishToTopicOperation GreengrassIpcClient::NewPublishToTopic() noexcept
            {
                return PublishToTopicOperation(
                    m_connection, m_greengrassServiceModel.m_publishToTopicOperationContext, m_allocator);
            }
            ListComponentsOperation GreengrassIpcClient::NewListComponents() noexcept
            {
                return ListComponentsOperation(
                    m_connection, m_greengrassServiceModel.m_listComponentsOperationContext, m_allocator);
            }
            CreateDebugPasswordOperation GreengrassIpcClient::NewCreateDebugPassword() noexcept
            {
                return CreateDebugPasswordOperation(
                    m_connection, m_greengrassServiceModel.m_createDebugPasswordOperationContext, m_allocator);
            }
            GetThingShadowOperation GreengrassIpcClient::NewGetThingShadow() noexcept
            {
                return GetThingShadowOperation(
                    m_connection, m_greengrassServiceModel.m_getThingShadowOperationContext, m_allocator);
            }
            SendConfigurationValidityReportOperation GreengrassIpcClient::NewSendConfigurationValidityReport() noexcept
            {
                return SendConfigurationValidityReportOperation(
                    m_connection,
                    m_greengrassServiceModel.m_sendConfigurationValidityReportOperationContext,
                    m_allocator);
            }
            UpdateThingShadowOperation GreengrassIpcClient::NewUpdateThingShadow() noexcept
            {
                return UpdateThingShadowOperation(
                    m_connection, m_greengrassServiceModel.m_updateThingShadowOperationContext, m_allocator);
            }
            UpdateConfigurationOperation GreengrassIpcClient::NewUpdateConfiguration() noexcept
            {
                return UpdateConfigurationOperation(
                    m_connection, m_greengrassServiceModel.m_updateConfigurationOperationContext, m_allocator);
            }
            ValidateAuthorizationTokenOperation GreengrassIpcClient::NewValidateAuthorizationToken() noexcept
            {
                return ValidateAuthorizationTokenOperation(
                    m_connection, m_greengrassServiceModel.m_validateAuthorizationTokenOperationContext, m_allocator);
            }
            RestartComponentOperation GreengrassIpcClient::NewRestartComponent() noexcept
            {
                return RestartComponentOperation(
                    m_connection, m_greengrassServiceModel.m_restartComponentOperationContext, m_allocator);
            }
            GetLocalDeploymentStatusOperation GreengrassIpcClient::NewGetLocalDeploymentStatus() noexcept
            {
                return GetLocalDeploymentStatusOperation(
                    m_connection, m_greengrassServiceModel.m_getLocalDeploymentStatusOperationContext, m_allocator);
            }
            GetSecretValueOperation GreengrassIpcClient::NewGetSecretValue() noexcept
            {
                return GetSecretValueOperation(
                    m_connection, m_greengrassServiceModel.m_getSecretValueOperationContext, m_allocator);
            }
            UpdateStateOperation GreengrassIpcClient::NewUpdateState() noexcept
            {
                return UpdateStateOperation(
                    m_connection, m_greengrassServiceModel.m_updateStateOperationContext, m_allocator);
            }
            ListNamedShadowsForThingOperation GreengrassIpcClient::NewListNamedShadowsForThing() noexcept
            {
                return ListNamedShadowsForThingOperation(
                    m_connection, m_greengrassServiceModel.m_listNamedShadowsForThingOperationContext, m_allocator);
            }
            SubscribeToComponentUpdatesOperation GreengrassIpcClient::NewSubscribeToComponentUpdates(
                SubscribeToComponentUpdatesStreamHandler &streamHandler) noexcept
            {
                return SubscribeToComponentUpdatesOperation(
                    m_connection,
                    &streamHandler,
                    m_greengrassServiceModel.m_subscribeToComponentUpdatesOperationContext,
                    m_allocator);
            }
            ListLocalDeploymentsOperation GreengrassIpcClient::NewListLocalDeployments() noexcept
            {
                return ListLocalDeploymentsOperation(
                    m_connection, m_greengrassServiceModel.m_listLocalDeploymentsOperationContext, m_allocator);
            }
            StopComponentOperation GreengrassIpcClient::NewStopComponent() noexcept
            {
                return StopComponentOperation(
                    m_connection, m_greengrassServiceModel.m_stopComponentOperationContext, m_allocator);
            }
            PauseComponentOperation GreengrassIpcClient::NewPauseComponent() noexcept
            {
                return PauseComponentOperation(
                    m_connection, m_greengrassServiceModel.m_pauseComponentOperationContext, m_allocator);
            }
            CreateLocalDeploymentOperation GreengrassIpcClient::NewCreateLocalDeployment() noexcept
            {
                return CreateLocalDeploymentOperation(
                    m_connection, m_greengrassServiceModel.m_createLocalDeploymentOperationContext, m_allocator);
            }

        } // namespace Ipc
    }     // namespace Eventstreamrpc
} // namespace Aws
