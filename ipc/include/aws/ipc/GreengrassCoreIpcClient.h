#include <aws/ipc/GreengrassCoreIpcModel.h>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace GreengrassCoreIpc
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

            class GreengrassCoreIpcClient
            {
              public:
                GreengrassCoreIpcClient(
                    Crt::Io::ClientBootstrap &clientBootstrap,
                    Crt::Allocator *allocator = Crt::g_allocator) noexcept;
                std::future<RpcError> Connect(
                    ConnectionLifecycleHandler &lifecycleHandler,
                    const ConnectionConfig &connectionConfig = DefaultConnectionConfig()) noexcept;
                void Close() noexcept;
                SubscribeToIoTCoreOperation NewSubscribeToIoTCore(SubscribeToIoTCoreStreamHandler &) noexcept;
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
                CreateLocalDeploymentOperation NewCreateLocalDeployment() noexcept;
                ~GreengrassCoreIpcClient() noexcept;

              private:
                GreengrassCoreIpcServiceModel m_greengrassCoreIpcServiceModel;
                ClientConnection m_connection;
                Crt::Io::ClientBootstrap &m_clientBootstrap;
                Crt::Allocator *m_allocator;
                MessageAmendment m_connectAmendment;
            };
        } // namespace GreengrassCoreIpc
    }     // namespace Eventstreamrpc
} // namespace Aws
