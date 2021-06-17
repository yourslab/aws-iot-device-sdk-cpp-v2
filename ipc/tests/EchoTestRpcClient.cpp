#include <aws/crt/io/Bootstrap.h>
#include <aws/ipc/EchoTestRpcClient.h>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace EchoTestRpc
        {
            EchoTestRpcClient::EchoTestRpcClient(
                Crt::Io::ClientBootstrap &clientBootstrap,
                Crt::Allocator *allocator) noexcept
                : m_connection(allocator), m_clientBootstrap(clientBootstrap), m_allocator(allocator)
            {
                m_echoTestRpcServiceModel.AssignModelNameToErrorResponse(
                    Crt::String("awstest#ServiceError"), ServiceError::s_allocateFromPayload);
            }

            std::future<RpcError> EchoTestRpcClient::Connect(
                ConnectionLifecycleHandler &lifecycleHandler,
                const ConnectionConfig &connectionConfig) noexcept
            {
                std::promise<RpcError> initializationPromise;
                EventStreamRpcError baseError = EVENT_STREAM_RPC_SUCCESS;

                if (!m_clientBootstrap)
                {
                    initializationPromise.set_value({EVENT_STREAM_RPC_INITIALIZATION_ERROR, 0});
                    return initializationPromise.get_future();
                }

                Crt::Io::SocketOptions socketOptions;
                if (connectionConfig.GetSocketDomain().has_value())
                {
                    socketOptions.SetSocketDomain(connectionConfig.GetSocketDomain().value());
                }

                if (connectionConfig.GetSocketType().has_value())
                {
                    socketOptions.SetSocketType(connectionConfig.GetSocketType().value());
                }

                ClientConnectionOptions connectionOptions;
                connectionOptions.Bootstrap = &m_clientBootstrap;

                connectionOptions.SocketOptions = std::move(socketOptions);
                if (connectionConfig.GetHostName().has_value())
                {
                    connectionOptions.HostName = connectionConfig.GetHostName().value();
                }
                else
                {
                    baseError = EVENT_STREAM_RPC_NULL_PARAMETER;
                }
                if (connectionConfig.GetPort().has_value())
                {
                    connectionOptions.Port = connectionConfig.GetPort().value();
                }
                else
                {
                    baseError = EVENT_STREAM_RPC_NULL_PARAMETER;
                }

                if (baseError)
                {
                    initializationPromise.set_value({baseError, 0});
                    return initializationPromise.get_future();
                }

                if (connectionConfig.GetConnectAmendment().has_value())
                {
                    m_connectAmendment = connectionConfig.GetConnectAmendment().value();
                }
                auto messageAmender = [&](void) -> MessageAmendment & { return m_connectAmendment; };

                return m_connection.Connect(connectionOptions, &lifecycleHandler, messageAmender);
            }

            void EchoTestRpcClient::Close() noexcept { m_connection.Close(); }

            EchoTestRpcClient::~EchoTestRpcClient() noexcept { Close(); }

            GetAllProductsOperation EchoTestRpcClient::NewGetAllProducts() noexcept
            {
                return GetAllProductsOperation(
                    m_connection, m_echoTestRpcServiceModel.m_getAllProductsOperationContext, m_allocator);
            }
            CauseServiceErrorOperation EchoTestRpcClient::NewCauseServiceError() noexcept
            {
                return CauseServiceErrorOperation(
                    m_connection, m_echoTestRpcServiceModel.m_causeServiceErrorOperationContext, m_allocator);
            }
            CauseStreamServiceToErrorOperation EchoTestRpcClient::NewCauseStreamServiceToError(
                CauseStreamServiceToErrorStreamHandler &streamHandler) noexcept
            {
                return CauseStreamServiceToErrorOperation(
                    m_connection,
                    &streamHandler,
                    m_echoTestRpcServiceModel.m_causeStreamServiceToErrorOperationContext,
                    m_allocator);
            }
            EchoStreamMessagesOperation EchoTestRpcClient::NewEchoStreamMessages(
                EchoStreamMessagesStreamHandler &streamHandler) noexcept
            {
                return EchoStreamMessagesOperation(
                    m_connection,
                    &streamHandler,
                    m_echoTestRpcServiceModel.m_echoStreamMessagesOperationContext,
                    m_allocator);
            }
            EchoMessageOperation EchoTestRpcClient::NewEchoMessage() noexcept
            {
                return EchoMessageOperation(
                    m_connection, m_echoTestRpcServiceModel.m_echoMessageOperationContext, m_allocator);
            }
            GetAllCustomersOperation EchoTestRpcClient::NewGetAllCustomers() noexcept
            {
                return GetAllCustomersOperation(
                    m_connection, m_echoTestRpcServiceModel.m_getAllCustomersOperationContext, m_allocator);
            }

        } // namespace EchoTestRpc
    }     // namespace Eventstreamrpc
} // namespace Aws
