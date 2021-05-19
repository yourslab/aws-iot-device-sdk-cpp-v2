#include <aws/crt/Api.h>
#include <aws/ipc/GGCoreIpcClient.h>

#include <iostream>
#include <sstream>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace Ipc
        {
            BinaryMessage::BinaryMessage(
                Crt::Optional<Crt::Vector<uint8_t>> &&message,
                Crt::Allocator *allocator) noexcept
                : AbstractShapeBase(allocator), m_message(message)
            {
            }

            BinaryMessage::BinaryMessage(
                const Crt::Optional<Crt::Vector<uint8_t>> &message,
                Crt::Allocator *allocator) noexcept
                : AbstractShapeBase(allocator), m_message(message)
            {
            }

            void BinaryMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const
            {
                if (m_message.has_value())
                {
                    if (m_message.value().size() > 0)
                        payloadObject.WithString("message", Crt::Base64Encode(m_message.value()));
                }
            }

            void BinaryMessage::LoadFromJsonView(BinaryMessage &message, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    message.m_message =
                        Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("message")));
                }
            }

            Crt::String BinaryMessage::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#BinaryMessage");
            }

            BinaryMessage::BinaryMessage(Crt::Allocator *allocator) noexcept : AbstractShapeBase(allocator) {}

            JsonMessage::JsonMessage(Crt::Allocator *allocator) noexcept : AbstractShapeBase(allocator) {}

            JsonMessage::JsonMessage(Crt::Optional<Crt::JsonObject> &&jsonObject, Crt::Allocator *allocator) noexcept
                : AbstractShapeBase(allocator), m_jsonObject(jsonObject)
            {
            }

            JsonMessage::JsonMessage(
                const Crt::Optional<Crt::JsonObject> &jsonObject,
                Crt::Allocator *allocator) noexcept
                : AbstractShapeBase(allocator), m_jsonObject(jsonObject)
            {
            }

            Crt::String JsonMessage::GetModelName() const noexcept { return Crt::String("aws.greengrass#JsonMessage"); }

            void JsonMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const
            {
                /* May want to std::move(m_jsonObject) instead, but ideally, it should be up to the application. */
                if (m_jsonObject.has_value())
                {
                    payloadObject.WithObject("message", m_jsonObject.value());
                }
            }

            void JsonMessage::LoadFromJsonView(JsonMessage &message, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    message.m_jsonObject =
                        Crt::Optional<Crt::JsonObject>(Crt::JsonObject(jsonView.GetString("message")));
                }
            }

            PublishMessage::PublishMessage(Crt::Allocator *allocator) noexcept : AbstractShapeBase(allocator) {}

            PublishMessage::PublishMessage(
                const Crt::Optional<JsonMessage> &jsonMessage,
                Crt::Allocator *allocator) noexcept
                : AbstractShapeBase(allocator), m_jsonMessage(jsonMessage), m_binaryMessage()
            {
            }

            PublishMessage::PublishMessage(
                const Crt::Optional<BinaryMessage> &binaryMessage,
                Crt::Allocator *allocator) noexcept
                : AbstractShapeBase(allocator), m_jsonMessage(), m_binaryMessage(binaryMessage)
            {
            }

            PublishToTopicOperation::PublishToTopicOperation(
                ClientConnection &connection,
                const GreengrassModelRetriever &greengrassModelRetriever,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, greengrassModelRetriever, allocator)
            {
            }

            std::future<RpcStatusResult> PublishToTopicOperation::Activate(
                const PublishToTopicRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate((const OperationRequest *)&request, onMessageFlushCallback);
            }

            SubscribeToTopicOperation::SubscribeToTopicOperation(
                ClientConnection &connection,
                SubscribeToTopicStreamHandler *streamHandler,
                const GreengrassModelRetriever &greengrassModelRetriever,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, streamHandler, greengrassModelRetriever, allocator)
            {
            }

            std::future<RpcStatusResult> SubscribeToTopicOperation::Activate(
                const SubscribeToTopicRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate((const OperationRequest *)&request, onMessageFlushCallback);
            }

            Crt::String SubscribeToTopicOperation::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopic");
            }

            void PublishMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const
            {
                if (m_jsonMessage.has_value())
                {
                    Aws::Crt::JsonObject jsonObject;
                    m_jsonMessage.value().SerializeToJsonObject(jsonObject);
                    payloadObject.WithObject("jsonMessage", std::move(jsonObject));
                    return;
                }
                if (m_binaryMessage.has_value())
                {
                    Aws::Crt::JsonObject jsonObject;
                    m_binaryMessage.value().SerializeToJsonObject(jsonObject);
                    payloadObject.WithObject("binaryMessage", std::move(jsonObject));
                }
            }

            Crt::String PublishToTopicRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopicRequest");
            }

            PublishToTopicRequest::PublishToTopicRequest(
                const Crt::Optional<Crt::String> &topic,
                const Crt::Optional<PublishMessage> &publishMessage,
                Crt::Allocator *allocator) noexcept
                : OperationRequest(allocator), m_topic(topic), m_publishMessage(publishMessage)
            {
            }
            PublishToTopicRequest::PublishToTopicRequest(
                Crt::Optional<Crt::String> &&topic,
                Crt::Optional<PublishMessage> &&publishMessage,
                Crt::Allocator *allocator) noexcept
                : OperationRequest(allocator), m_topic(topic), m_publishMessage(publishMessage)
            {
            }

            void PublishToTopicRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const
            {
                if (m_topic.has_value())
                {
                    payloadObject.WithString("topic", m_topic.value());
                }
                if (m_publishMessage.has_value())
                {
                    Aws::Crt::JsonObject jsonObject;
                    m_publishMessage.value().SerializeToJsonObject(jsonObject);
                    payloadObject.WithObject("publishMessage", std::move(jsonObject));
                }
            }

            Crt::String PublishToTopicOperation::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopic");
            }

            PublishToTopicResponse::PublishToTopicResponse(Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator)
            {
            }

            Crt::String PublishToTopicResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopicResponse");
            }

            Crt::ScopedResource<OperationResponse> PublishToTopicResponse::s_loadFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::ScopedResource<PublishToTopicResponse> derivedResponse(
                    Crt::New<PublishToTopicResponse>(allocator), PublishToTopicResponse::s_customDeleter);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void PublishToTopicResponse::s_customDeleter(PublishToTopicResponse *response) noexcept
            {
                OperationResponse::s_customDeleter((OperationResponse *)response);
            }

            void SubscribeToTopicResponse::s_customDeleter(SubscribeToTopicResponse *response) noexcept
            {
                OperationResponse::s_customDeleter((OperationResponse *)response);
            }

            Crt::String SubscribeToTopicRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopicRequest");
            }

            SubscribeToTopicRequest::SubscribeToTopicRequest(
                const Crt::Optional<Crt::String> &topic,
                Crt::Allocator *allocator) noexcept
                : OperationRequest(allocator), m_topic(topic)
            {
            }
            SubscribeToTopicRequest::SubscribeToTopicRequest(
                Crt::Optional<Crt::String> &&topic,
                Crt::Allocator *allocator) noexcept
                : OperationRequest(allocator), m_topic(topic)
            {
            }

            void SubscribeToTopicRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const
            {
                if (m_topic.has_value())
                {
                    payloadObject.WithString("topic", m_topic.value());
                }
            }

            Crt::String SubscribeToTopicResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopicResponse");
            }

            SubscribeToTopicResponse::SubscribeToTopicResponse(Crt::Allocator *allocator) noexcept {}
            SubscribeToTopicResponse::SubscribeToTopicResponse(
                const Crt::Optional<Crt::String> &topic,
                Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator), m_topic(topic)
            {
            }
            SubscribeToTopicResponse::SubscribeToTopicResponse(
                Crt::Optional<Crt::String> &&topic,
                Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator), m_topic(topic)
            {
            }

            Crt::ScopedResource<OperationResponse> SubscribeToTopicResponse::s_loadFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);

                Crt::ScopedResource<SubscribeToTopicResponse> derivedResponse(
                    Crt::New<SubscribeToTopicResponse>(allocator), SubscribeToTopicResponse::s_customDeleter);

                if (jsonView.ValueExists("topic"))
                {
                    Crt::ScopedResource<SubscribeToTopicResponse> unionResponse(
                        Crt::New<SubscribeToTopicResponse>(allocator, jsonView.GetString("topic"), allocator),
                        SubscribeToTopicResponse::s_customDeleter);
                    derivedResponse = std::move(unionResponse);
                }

                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            SubscriptionResponseMessage::SubscriptionResponseMessage(Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator)
            {
            }

            SubscriptionResponseMessage::SubscriptionResponseMessage(
                const Crt::Optional<JsonMessage> &jsonMessage,
                Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator), m_jsonMessage(jsonMessage), m_binaryMessage()
            {
            }

            SubscriptionResponseMessage::SubscriptionResponseMessage(
                const Crt::Optional<BinaryMessage> &binaryMessage,
                Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator), m_jsonMessage(), m_binaryMessage(binaryMessage)
            {
            }

            SubscriptionResponseMessage::SubscriptionResponseMessage(
                Crt::Optional<JsonMessage> &&jsonMessage,
                Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator), m_jsonMessage(jsonMessage), m_binaryMessage()
            {
            }

            SubscriptionResponseMessage::SubscriptionResponseMessage(
                Crt::Optional<BinaryMessage> &&binaryMessage,
                Crt::Allocator *allocator) noexcept
                : OperationResponse(allocator), m_jsonMessage(), m_binaryMessage(binaryMessage)
            {
            }

            void SubscriptionResponseMessage::s_customDeleter(SubscriptionResponseMessage *response) noexcept
            {
                OperationResponse::s_customDeleter((OperationResponse *)response);
            }

            GreengrassIpcClient::GreengrassIpcClient(
                Crt::Io::ClientBootstrap &clientBootstrap,
                Crt::Allocator *allocator) noexcept
                : m_connection(allocator), m_clientBootstrap(clientBootstrap), m_allocator(allocator)
            {
                m_greengrassModelRetriever
                    .m_ModelNameToInitialResponseMap[Crt::String("aws.greengrass#PublishToTopic")] =
                    PublishToTopicResponse::s_loadFromPayload;
                m_greengrassModelRetriever
                    .m_ModelNameToInitialResponseMap[Crt::String("aws.greengrass#SubscribeToTopic")] =
                    SubscribeToTopicResponse::s_loadFromPayload;
                m_greengrassModelRetriever
                    .m_ModelNameToStreamingResponseMap[Crt::String("aws.greengrass#SubscribeToTopic")] =
                    SubscriptionResponseMessage::s_loadFromPayload;
            }

            std::future<RpcStatusResult> GreengrassIpcClient::Connect(
                ConnectionLifecycleHandler &lifecycleHandler,
                const Crt::Optional<Crt::String> &ipcSocket,
                const Crt::Optional<Crt::String> &authToken) noexcept
            {
                std::promise<RpcStatusResult> initializationPromise;
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

            ExpectedResponseFactory GreengrassModelRetriever::GetInitialResponseFromModelName(
                const Crt::String &modelName) const noexcept
            {
                auto it = m_ModelNameToInitialResponseMap.find(modelName);
                if (it == m_ModelNameToInitialResponseMap.end())
                {
                    return nullptr;
                }
                else
                {
                    return it->second;
                }
            }

            ExpectedResponseFactory GreengrassModelRetriever::GetStreamingResponseFromModelName(
                const Crt::String &modelName) const noexcept
            {
                auto it = m_ModelNameToStreamingResponseMap.find(modelName);
                if (it == m_ModelNameToStreamingResponseMap.end())
                {
                    return nullptr;
                }
                else
                {
                    return it->second;
                }
            }

            ErrorResponseFactory GreengrassModelRetriever::GetErrorResponseFromModelName(
                const Crt::String &modelName) const noexcept
            {
                auto it = m_ModelNameToErrorResponse.find(modelName);
                if (it == m_ModelNameToErrorResponse.end())
                {
                    return nullptr;
                }
                else
                {
                    return it->second;
                }
            }

            PublishToTopicOperation GreengrassIpcClient::NewPublishToTopic() noexcept
            {
                return PublishToTopicOperation(m_connection, m_greengrassModelRetriever, m_allocator);
            }

            SubscribeToTopicOperation GreengrassIpcClient::NewSubscribeToTopic(
                SubscribeToTopicStreamHandler &streamHandler) noexcept
            {
                return SubscribeToTopicOperation(m_connection, &streamHandler, m_greengrassModelRetriever, m_allocator);
            }

            void SubscribeToTopicStreamHandler::OnStreamEvent(Crt::ScopedResource<OperationResponse> response)
            {
                OnStreamEvent(static_cast<SubscriptionResponseMessage *>(response.get()));
            }

            void SubscribeToTopicStreamHandler::OnStreamEvent(SubscriptionResponseMessage *response) {}

            bool SubscribeToTopicStreamHandler::OnStreamError(Crt::ScopedResource<OperationError> response)
            {
                // TODO: return OnStreamError(static_cast<SubscriptionResponseError *> response.get());
                return true;
            }

            Crt::String SubscriptionResponseMessage::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscriptionResponseMessage");
            }

            Crt::ScopedResource<OperationResponse> SubscriptionResponseMessage::s_loadFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);

                Crt::ScopedResource<SubscriptionResponseMessage> derivedResponse(
                    Crt::New<SubscriptionResponseMessage>(allocator), SubscriptionResponseMessage::s_customDeleter);
                ;

                if (jsonView.ValueExists("jsonMessage"))
                {
                    JsonMessage jsonMessage;
                    JsonMessage::LoadFromJsonView(jsonMessage, jsonView.GetJsonObject("jsonMessage"));
                    Crt::ScopedResource<SubscriptionResponseMessage> unionResponse(
                        Crt::New<SubscriptionResponseMessage>(allocator, std::move(jsonMessage), allocator),
                        SubscriptionResponseMessage::s_customDeleter);
                    derivedResponse = std::move(unionResponse);
                }
                else if (jsonView.ValueExists("binaryMessage"))
                {
                    BinaryMessage binaryMessage;
                    BinaryMessage::LoadFromJsonView(binaryMessage, jsonView.GetJsonObject("binaryMessage"));
                    Crt::ScopedResource<SubscriptionResponseMessage> unionResponse(
                        Crt::New<SubscriptionResponseMessage>(allocator, binaryMessage, allocator),
                        SubscriptionResponseMessage::s_customDeleter);
                    derivedResponse = std::move(unionResponse);
                }

                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }
        } // namespace Ipc
    }     // namespace Eventstreamrpc
} // namespace Aws
