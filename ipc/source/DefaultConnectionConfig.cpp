#include <aws/greengrass/GreengrassCoreIpcClient.h>

#include <sstream>

namespace Aws
{
    namespace Greengrass
    {
        DefaultConnectionConfig::DefaultConnectionConfig() noexcept
        {
            const char *ipcSocketCStr = std::getenv("AWS_GG_NUCLEUS_DOMAIN_SOCKET_FILEPATH_FOR_COMPONENT");
            if (ipcSocketCStr != nullptr)
            {
                m_hostName = Crt::String(ipcSocketCStr);
            }

            const char *authTokenCStr = std::getenv("SVCUID");
            if (authTokenCStr != nullptr)
            {
                /* Encode authToken as JSON. */
                Crt::StringStream authTokenPayloadSS;
                authTokenPayloadSS << "{\"authToken\":\"" << Crt::String(authTokenCStr) << "\"}";
                m_connectAmendment = MessageAmendment(Crt::ByteBufFromCString(authTokenPayloadSS.str().c_str()));
            }

            m_port = 0;
            m_socketDomain = Crt::Io::SocketDomain::Local;
            m_socketType = Crt::Io::SocketType::Stream;
        }
    } // namespace Greengrass
} // namespace Aws
