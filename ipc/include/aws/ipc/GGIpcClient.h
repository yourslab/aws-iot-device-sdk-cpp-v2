#include <aws/ipc/GGIpcModel.h>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace Ipc
        {
            class GreengrassIpcClient
            {
              public:
                GreengrassIpcClient(
                    Crt::Io::ClientBootstrap &clientBootstrap,
                    Crt::Allocator *allocator = Crt::g_allocator) noexcept;
                std::future<RpcError> Connect(
                    ConnectionLifecycleHandler &lifecycleHandler,
                    const Crt::Optional<Crt::String> &ipcSocket = Crt::Optional<Crt::String>(),
                    const Crt::Optional<Crt::String> &authToken = Crt::Optional<Crt::String>()) noexcept;
                void Close() noexcept;
                SubscribeToIoTCoreOperation NewSubscribeToIoTCore(SubscribeToIoTCoreStreamHandler &) noexcept;
                ResumeComponentOperation NewResumeComponent() noexcept;
                PublishToIoTCoreOperation NewPublishToIoTCore() noexcept;
                SubscribeToConfigurationUpdateOperation NewSubscribeToConfigurationUpdate(
                    SubscribeToConfigurationUpdateStreamHandler &) noexcept;
                DeleteThingShadowOperation NewDeleteThingShadow() noexcept;
                DeferComponentUpdateOperation NewDeferComponentUpdate() noexcept;
                SubscribeToValidateConfigurationUpdatesOperation NewSubscribeToValidateConfigurationUpdates(
                    SubscribeToValidateConfigurationUpdatesStreamHandler &) noexcept;
                GetConfigurationOperation NewGetConfiguration() noexcept;
                SubscribeToTopicOperation NewSubscribeToTopic(SubscribeToTopicStreamHandler &) noexcept;
                GetComponentDetailsOperation NewGetComponentDetails() noexcept;
                PublishToTopicOperation NewPublishToTopic() noexcept;
                ListComponentsOperation NewListComponents() noexcept;
                CreateDebugPasswordOperation NewCreateDebugPassword() noexcept;
                GetThingShadowOperation NewGetThingShadow() noexcept;
                SendConfigurationValidityReportOperation NewSendConfigurationValidityReport() noexcept;
                UpdateThingShadowOperation NewUpdateThingShadow() noexcept;
                UpdateConfigurationOperation NewUpdateConfiguration() noexcept;
                ValidateAuthorizationTokenOperation NewValidateAuthorizationToken() noexcept;
                RestartComponentOperation NewRestartComponent() noexcept;
                GetLocalDeploymentStatusOperation NewGetLocalDeploymentStatus() noexcept;
                GetSecretValueOperation NewGetSecretValue() noexcept;
                UpdateStateOperation NewUpdateState() noexcept;
                ListNamedShadowsForThingOperation NewListNamedShadowsForThing() noexcept;
                SubscribeToComponentUpdatesOperation NewSubscribeToComponentUpdates(
                    SubscribeToComponentUpdatesStreamHandler &) noexcept;
                ListLocalDeploymentsOperation NewListLocalDeployments() noexcept;
                StopComponentOperation NewStopComponent() noexcept;
                PauseComponentOperation NewPauseComponent() noexcept;
                CreateLocalDeploymentOperation NewCreateLocalDeployment() noexcept;
                ~GreengrassIpcClient() noexcept;

              private:
                GreengrassServiceModel m_greengrassServiceModel;
                ClientConnection m_connection;
                Crt::Io::ClientBootstrap &m_clientBootstrap;
                Crt::Allocator *m_allocator;
                MessageAmendment m_connectAmendment;
            };
        } // namespace Ipc
    }     // namespace Eventstreamrpc
} // namespace Aws
