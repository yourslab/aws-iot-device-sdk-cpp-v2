#include <aws/ipc/EchoTestRpcModel.h>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace EchoTestRpc
        {
            class ConnectionConfig
            {
              public:
                ConnectionConfig() noexcept {}
                Crt::Optional<Crt::String> GetHostName() const noexcept { return m_hostName; }
                Crt::Optional<uint16_t> GetPort() const noexcept { return m_port; }
                Crt::Optional<Crt::Io::SocketDomain> GetSocketDomain() const noexcept { return m_socketDomain; }
                Crt::Optional<Crt::Io::SocketType> GetSocketType() const noexcept { return m_socketType; }
                Crt::Optional<MessageAmendment> GetConnectAmendment() const noexcept { return m_connectAmendment; }

                void SetHostName(Crt::String hostName) noexcept { m_hostName = hostName; }
                void SetPort(uint16_t port) noexcept { m_port = port; }
                void SetSocketDomain(Crt::Io::SocketDomain socketDomain) noexcept { m_socketDomain = socketDomain; }
                void SetSocketType(Crt::Io::SocketType socketType) noexcept { m_socketType = socketType; }
                void SetConnectAmendment(MessageAmendment connectAmendment) noexcept
                {
                    m_connectAmendment = connectAmendment;
                }

              protected:
                Crt::Optional<Crt::String> m_hostName;
                Crt::Optional<uint16_t> m_port;
                Crt::Optional<Crt::Io::SocketDomain> m_socketDomain;
                Crt::Optional<Crt::Io::SocketType> m_socketType;
                Crt::Optional<MessageAmendment> m_connectAmendment;
            };

            class DefaultConnectionConfig : public ConnectionConfig
            {
              public:
                DefaultConnectionConfig() noexcept;
            };

            class EchoTestRpcClient
            {
              public:
                EchoTestRpcClient(
                    Crt::Io::ClientBootstrap &clientBootstrap,
                    Crt::Allocator *allocator = Crt::g_allocator) noexcept;
                std::future<RpcError> Connect(
                    ConnectionLifecycleHandler &lifecycleHandler,
                    const ConnectionConfig &connectionConfig = DefaultConnectionConfig()) noexcept;
                void Close() noexcept;
                GetAllProductsOperation NewGetAllProducts() noexcept;
                CauseServiceErrorOperation NewCauseServiceError() noexcept;
                CauseStreamServiceToErrorOperation NewCauseStreamServiceToError(
                    CauseStreamServiceToErrorStreamHandler &) noexcept;
                EchoStreamMessagesOperation NewEchoStreamMessages(EchoStreamMessagesStreamHandler &) noexcept;
                EchoMessageOperation NewEchoMessage() noexcept;
                GetAllCustomersOperation NewGetAllCustomers() noexcept;
                ~EchoTestRpcClient() noexcept;

              private:
                EchoTestRpcServiceModel m_echoTestRpcServiceModel;
                ClientConnection m_connection;
                Crt::Io::ClientBootstrap &m_clientBootstrap;
                Crt::Allocator *m_allocator;
                MessageAmendment m_connectAmendment;
            };
        } // namespace EchoTestRpc
    }     // namespace Eventstreamrpc
} // namespace Aws
