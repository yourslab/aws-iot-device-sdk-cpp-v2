#include <awstest/EchoTestRpcClient.h>

namespace Awstest
{
    DefaultConnectionConfig::DefaultConnectionConfig() noexcept
    {
        m_hostName = Aws::Crt::String("127.0.0.1");
        m_port = 8033;
        m_socketDomain = Aws::Crt::Io::SocketDomain::IPv4;
        m_socketType = Aws::Crt::Io::SocketType::Stream;
    }
} // namespace Awstest
