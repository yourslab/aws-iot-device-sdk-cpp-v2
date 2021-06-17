#pragma once
/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/eventstreamrpc/Exports.h>

#include <aws/crt/DateTime.h>
#include <aws/crt/JsonObject.h>
#include <aws/crt/StlAllocator.h>
#include <aws/crt/Types.h>
#include <aws/crt/UUID.h>
#include <aws/crt/io/EventLoopGroup.h>
#include <aws/crt/io/SocketOptions.h>
#include <aws/crt/io/TlsOptions.h>

#include <aws/crt/io/HostResolver.h>

#include <aws/event-stream/event_stream_rpc_client.h>
#include <aws/io/host_resolver.h>

#include <atomic>
#include <functional>
#include <future>
#include <memory>

namespace Aws
{
    namespace Crt
    {
        namespace Io
        {
            class ClientBootstrap;
        }
    } // namespace Crt
    namespace Eventstreamrpc
    {
        class EventStreamHeader;
        class MessageAmendment;
        class ClientConnection;
        class ClientContinuation;
        class ClientOperation;

        using HeaderValueType = aws_event_stream_header_value_type;
        using MessageType = aws_event_stream_rpc_message_type;

        /**
         * A callback prototype that is called upon flushing a message over the wire.
         * @param errorCode A non-zero value if an error occured while attempting to flush the message. 
         */
        using OnMessageFlushCallback = std::function<void(int errorCode)>;

        /**
         * Allows the application to add headers and change the payload of the CONNECT
         * packet sent out by the client.
         * @return The `MessageAmendment` for the client to use during an attempt to connect.
         */
        using ConnectMessageAmender = std::function<MessageAmendment &(void)>;

        /**
         * A wrapper around an `aws_event_stream_header_value_pair` object.
         */
        class AWS_EVENTSTREAMRPC_API EventStreamHeader final
        {
          public:
            EventStreamHeader(const EventStreamHeader &lhs) noexcept;
            EventStreamHeader(EventStreamHeader &&rhs) noexcept;
            EventStreamHeader &operator=(const EventStreamHeader &lhs) noexcept;
            ~EventStreamHeader() noexcept;
            EventStreamHeader(
                const struct aws_event_stream_header_value_pair &header,
                Crt::Allocator *allocator = Crt::g_allocator);
            EventStreamHeader(const Crt::String &name, bool value);
            EventStreamHeader(const Crt::String &name, int8_t value);
            EventStreamHeader(const Crt::String &name, int16_t value);
            EventStreamHeader(const Crt::String &name, int32_t value);
            EventStreamHeader(const Crt::String &name, int64_t value);
            EventStreamHeader(const Crt::String &name, Crt::DateTime &value);
            EventStreamHeader(
                const Crt::String &name,
                const Crt::String &value,
                Crt::Allocator *allocator = Crt::g_allocator) noexcept;
            EventStreamHeader(const Crt::String &name, Crt::ByteBuf &value);
            EventStreamHeader(const Crt::String &name, Crt::UUID value);

            HeaderValueType GetHeaderValueType();
            Crt::String GetHeaderName() const noexcept;
            void SetHeaderName(const Crt::String &);

            bool GetValueAsBoolean(bool &);
            bool GetValueAsByte(int8_t &);
            bool GetValueAsShort(int16_t &);
            bool GetValueAsInt(int32_t &);
            bool GetValueAsLong(int64_t &);
            bool GetValueAsTimestamp(Crt::DateTime &);
            bool GetValueAsString(Crt::String &) const noexcept;
            bool GetValueAsBytes(Crt::ByteBuf &);
            bool GetValueAsUUID(Crt::UUID &);

            const struct aws_event_stream_header_value_pair *GetUnderlyingHandle() const;

            bool operator==(const EventStreamHeader &other) const noexcept;

          private:
            Crt::Allocator *m_allocator;
            Crt::ByteBuf m_valueByteBuf;
            struct aws_event_stream_header_value_pair m_underlyingHandle;
        };

        /**
         * A means to append headers or modify the payload of a message to be sent by the client.
         * @note The exception specifiers for move, copy constructors & assignment operators are required since
         * this class is usually wrapped with `Crt::Optional`.
         */
        class AWS_EVENTSTREAMRPC_API MessageAmendment final
        {
          public:
            MessageAmendment(const MessageAmendment &lhs) = default;
            MessageAmendment(MessageAmendment &&rhs) = default;
            MessageAmendment &operator=(const MessageAmendment &rhs) = default;
            ~MessageAmendment() noexcept;
            explicit MessageAmendment(Crt::Allocator *allocator = Crt::g_allocator) noexcept;
            MessageAmendment(
                const Crt::List<EventStreamHeader> &headers,
                Crt::Optional<Crt::ByteBuf> &payload,
                Crt::Allocator *allocator) noexcept;
            MessageAmendment(
                const Crt::List<EventStreamHeader> &headers,
                Crt::Allocator *allocator = Crt::g_allocator) noexcept;
            MessageAmendment(
                Crt::List<EventStreamHeader> &&headers,
                Crt::Allocator *allocator = Crt::g_allocator) noexcept;
            MessageAmendment(const Crt::ByteBuf &payload, Crt::Allocator *allocator = Crt::g_allocator) noexcept;
            void AddHeader(EventStreamHeader &&header) noexcept;
            void SetPayload(const Crt::Optional<Crt::ByteBuf> &payload) noexcept;
            Crt::List<EventStreamHeader> &GetHeaders() noexcept;
            const Crt::Optional<Crt::ByteBuf> &GetPayload() const noexcept;

          private:
            Crt::List<EventStreamHeader> m_headers;
            Crt::Optional<Crt::ByteBuf> m_payload;
            Crt::Allocator *m_allocator;
        };

        /**
         * Configuration structure holding all options relating to eventstream RPC connection establishment
         */
        struct AWS_EVENTSTREAMRPC_API ClientConnectionOptions final
        {
            ClientConnectionOptions();
            ClientConnectionOptions(const ClientConnectionOptions &rhs) = default;
            ClientConnectionOptions(ClientConnectionOptions &&rhs) = default;

            ~ClientConnectionOptions() = default;

            ClientConnectionOptions &operator=(const ClientConnectionOptions &rhs) = default;
            ClientConnectionOptions &operator=(ClientConnectionOptions &&rhs) = default;

            Crt::Io::ClientBootstrap *Bootstrap;
            Crt::Io::SocketOptions SocketOptions;
            Crt::Optional<Crt::Io::TlsConnectionOptions> TlsOptions;
            Crt::String HostName;
            uint16_t Port;
            OnMessageFlushCallback ConnectRequestCallback;
        };

        class AWS_EVENTSTREAMRPC_API ConnectionLifecycleHandler
        {
          public:
            /**
             * This callback is only invoked upon receiving a CONNECT_ACK with the
             * CONNECTION_ACCEPTED flag set by the server. Therefore, once this callback
             * is invoked, the `ClientConnection` is ready to be used for sending messages.
             */
            virtual void OnConnectCallback();
            /**
             * Invoked upon connection shutdown. `errorCode` will specify
             * shutdown reason. A graceful connection close will set `errorCode` to
             * `AWS_ERROR_SUCCESS` or 0.
             */
            virtual void OnDisconnectCallback(int errorCode);
            /**
             * Invoked upon receiving an error. Use the return value to determine
             * whether or not to force the connection to close. Keep in mind that once
             * closed, the `ClientConnection` can no longer send messages.
             */
            virtual bool OnErrorCallback(int errorCode);
            /**
             * Invoked upon receiving a ping from the server. The `headers` and `payload`
             * refer to what is contained in the ping message.
             */
            virtual void OnPingCallback(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload);
        };

        class AWS_EVENTSTREAMRPC_API ClientContinuationHandler
        {
          public:
            /**
             * Invoked when a message is received on this continuation.
             */
            virtual void OnContinuationMessage(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                MessageType messageType,
                uint32_t messageFlags) = 0;
            /**
             * Invoked when the continuation is closed.
             *
             * Once the continuation is closed, no more messages may be sent or received.
             * The continuation is closed when a message is sent or received with
             * the TERMINATE_STREAM flag, or when the connection shuts down.
             */
            virtual void OnContinuationClosed() = 0;
        };

        enum EventStreamRpcError
        {
            EVENT_STREAM_RPC_SUCCESS = 0,
            EVENT_STREAM_RPC_NULL_PARAMETER,
            EVENT_STREAM_RPC_INITIALIZATION_ERROR,
            EVENT_STREAM_RPC_CONNECTION_CLOSED_BEFORE_CONNACK,
            EVENT_STREAM_RPC_UNKNOWN_PROTOCOL_MESSAGE,
            EVENT_STREAM_RPC_UNMAPPED_DATA,
            EVENT_STREAM_RPC_UNSUPPORTED_CONTENT_TYPE,
            EVENT_STREAM_RPC_STREAM_CLOSED_PREMATURELY,
            EVENT_STREAM_RPC_CRT_ERROR
        };

        struct RpcError
        {
            EventStreamRpcError baseStatus;
            int crtError;
            operator bool() const noexcept { return baseStatus == EVENT_STREAM_RPC_SUCCESS; }
        };

        template <class T> class ProtectedPromise
        {
            /* A wrapper around std::promise so that it cannot be set twice without having to catch exceptions. */
          public:
            ProtectedPromise();
            ProtectedPromise(const ProtectedPromise &lhs) = delete;
            ProtectedPromise(ProtectedPromise &&rhs);
            ProtectedPromise &operator=(ProtectedPromise &&);
            ProtectedPromise(std::promise<T> &&promise);
            void SetValue(T &&r);
            void SetValue(const T &r);
            std::future<T> GetFuture();
            void Reset();

          private:
            bool m_fulfilled;
            std::promise<T> m_promise;
            std::mutex m_mutex;
        };

        class AWS_EVENTSTREAMRPC_API ClientConnection final
        {
          public:
            ClientConnection(Crt::Allocator *allocator = Crt::g_allocator) noexcept;
            ~ClientConnection() noexcept;
            ClientConnection(const ClientConnection &) noexcept = delete;
            ClientConnection &operator=(const ClientConnection &) noexcept = delete;
            ClientConnection(ClientConnection &&) noexcept;
            ClientConnection &operator=(ClientConnection &&) noexcept;

            std::future<RpcError> Connect(
                const ClientConnectionOptions &connectionOptions,
                ConnectionLifecycleHandler *connectionLifecycleHandler,
                ConnectMessageAmender connectMessageAmender) noexcept;

            std::future<RpcError> SendPing(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;

            std::future<RpcError> SendPingResponse(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;

            ClientContinuation NewStream(ClientContinuationHandler &clientContinuationHandler) noexcept;

            void Close() noexcept;

            /**
             * @return true if the instance is in a valid state, false otherwise.
             */
            operator bool() const noexcept;
            /**
             * @return the value of the last aws error encountered by operations on this instance.
             */
            int LastError() const noexcept;

          private:
            friend class ClientContinuation;
            enum ClientState
            {
                DISCONNECTED = 1,
                WAITING_FOR_CONNECT_ACK,
                CONNECTED,
                DISCONNECTING,
            };
            std::mutex m_stateMutex;
            Crt::Allocator *m_allocator;
            struct aws_event_stream_rpc_client_connection *m_underlyingConnection;
            ClientState m_clientState;
            ConnectionLifecycleHandler *m_lifecycleHandler;
            ConnectMessageAmender m_connectMessageAmender;
            ProtectedPromise<RpcError> m_connectAckedPromise;
            std::promise<RpcError> m_closedPromise;
            OnMessageFlushCallback m_onConnectRequestCallback;
            static void s_customDeleter(ClientConnection *connection) noexcept;
            std::future<RpcError> SendProtocolMessage(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                MessageType messageType,
                uint32_t messageFlags,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;

            static void s_onConnectionShutdown(
                struct aws_event_stream_rpc_client_connection *connection,
                int errorCode,
                void *userData) noexcept;
            static void s_onConnectionSetup(
                struct aws_event_stream_rpc_client_connection *connection,
                int errorCode,
                void *userData) noexcept;
            static void s_onProtocolMessage(
                struct aws_event_stream_rpc_client_connection *connection,
                const struct aws_event_stream_rpc_message_args *messageArgs,
                void *userData) noexcept;

            static void s_protocolMessageCallback(int errorCode, void *userData) noexcept;
            static std::future<RpcError> s_sendProtocolMessage(
                ClientConnection *connection,
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                MessageType messageType,
                uint32_t messageFlags,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;

            static std::future<RpcError> s_sendPing(
                ClientConnection *connection,
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;

            static std::future<RpcError> s_sendPingResponse(
                ClientConnection *connection,
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;
        };

        class AWS_EVENTSTREAMRPC_API ClientContinuation final
        {
          public:
            ClientContinuation(
                ClientConnection *connection,
                ClientContinuationHandler &continuationHandler,
                Crt::Allocator *allocator) noexcept;
            ~ClientContinuation() noexcept;
            std::future<RpcError> Activate(
                const Crt::String &operation,
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                MessageType messageType,
                uint32_t messageFlags,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;
            bool IsClosed() noexcept;
            std::future<RpcError> SendMessage(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                MessageType messageType,
                uint32_t messageFlags,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;

          private:
            Crt::Allocator *m_allocator;
            ClientContinuationHandler &m_continuationHandler;
            struct aws_event_stream_rpc_client_continuation_token *m_continuationToken;
            static void s_onContinuationMessage(
                struct aws_event_stream_rpc_client_continuation_token *continuationToken,
                const struct aws_event_stream_rpc_message_args *messageArgs,
                void *userData) noexcept;
            static void s_onContinuationClosed(
                struct aws_event_stream_rpc_client_continuation_token *continuationToken,
                void *userData) noexcept;
        };

        class AWS_EVENTSTREAMRPC_API AbstractShapeBase
        {
          public:
            AbstractShapeBase() noexcept;
            virtual ~AbstractShapeBase() noexcept;
            static void s_customDeleter(AbstractShapeBase *shape) noexcept;
            virtual void SerializeToJsonObject(Crt::JsonObject &payloadObject) const = 0;
            virtual Crt::String GetModelName() const noexcept = 0;

          private:
            Crt::Allocator *m_allocator;
        };

        class AWS_EVENTSTREAMRPC_API OperationResponse : public AbstractShapeBase
        {
          public:
            OperationResponse() noexcept;
            static void s_customDeleter(OperationResponse *shape) noexcept;
            /* A response does not necessarily have to be serialized so provide a default implementation. */
            virtual void SerializeToJsonObject(Crt::JsonObject &payloadObject) const override;
        };

        class AWS_EVENTSTREAMRPC_API OperationRequest : public AbstractShapeBase
        {
          public:
            OperationRequest() noexcept;
        };

        class AWS_EVENTSTREAMRPC_API OperationError : public AbstractShapeBase
        {
          public:
            explicit OperationError() noexcept;
            static void s_customDeleter(OperationError *shape) noexcept;
            virtual void SerializeToJsonObject(Crt::JsonObject &payloadObject) const override;
            virtual Crt::Optional<Crt::String> GetMessage() noexcept = 0;
        };

        /**
         * Base class for all operation stream handlers.
         * For operations with a streaming response (0+ messages that may arrive
         * after the initial response).
         */
        class AWS_EVENTSTREAMRPC_API StreamResponseHandler
        {
          public:
            /**
             * Invoked when stream is closed, so no more messages will be receivied.
             */
            virtual void OnStreamClosed();

          protected:
            friend class ClientOperation;
            /**
             * Invoked when a message is received on this continuation.
             */
            virtual void OnStreamEvent(Crt::ScopedResource<OperationResponse> response);
            /**
             * Invoked when a message is received on this continuation but results in an error.
             *
             * This callback can return true so that the stream is closed afterwards.
             */
            virtual bool OnStreamError(Crt::ScopedResource<OperationError> operationError, RpcError rpcError);
        };

        enum AWS_EVENTSTREAMRPC_API ResultType
        {
            OPERATION_RESPONSE,
            OPERATION_ERROR,
            RPC_ERROR
        };

        class AWS_EVENTSTREAMRPC_API TaggedResult
        {
          public:
            TaggedResult() noexcept;
            explicit TaggedResult(Crt::ScopedResource<OperationResponse> response) noexcept;
            explicit TaggedResult(Crt::ScopedResource<OperationError> error) noexcept;
            explicit TaggedResult(RpcError rpcError) noexcept;
            TaggedResult(TaggedResult &&rhs) noexcept;
            ~TaggedResult() noexcept;
            /**
             * @return true if the response is associated with an expected response;
             * false if the response is associated with an error.
             */
            operator bool() const noexcept;

            OperationResponse *GetOperationResponse() const noexcept;
            OperationError *GetOperationError() const noexcept;
            RpcError GetRpcError() const noexcept;
            ResultType GetResultType() const noexcept { return m_responseType; }

          private:
            union AWS_EVENTSTREAMRPC_API OperationResult
            {
                OperationResult(Crt::ScopedResource<OperationResponse> &&response) noexcept
                    : m_response(std::move(response))
                {
                }
                OperationResult(Crt::ScopedResource<OperationError> &&error) noexcept : m_error(std::move(error)) {}
                OperationResult() noexcept : m_response(nullptr) {}
                ~OperationResult() noexcept {};
                Crt::ScopedResource<OperationResponse> m_response;
                Crt::ScopedResource<OperationError> m_error;
            };
            ResultType m_responseType;
            OperationResult m_operationResult;
            RpcError m_rpcError;
        };

        using ExpectedResponseFactory = std::function<
            Crt::ScopedResource<OperationResponse>(const Crt::StringView &payload, Crt::Allocator *allocator)>;
        using ErrorResponseFactory = std::function<
            Crt::ScopedResource<OperationError>(const Crt::StringView &payload, Crt::Allocator *allocator)>;

        using LoneResponseRetriever = std::function<ExpectedResponseFactory(const Crt::String &modelName)>;
        using StreamingResponseRetriever = std::function<ExpectedResponseFactory(const Crt::String &modelName)>;
        using ErrorResponseRetriever = std::function<ErrorResponseFactory(const Crt::String &modelName)>;

        class AWS_EVENTSTREAMRPC_API ResponseRetriever
        {
            /* An interface shared by all operations for retrieving the response object given the model name. */
          public:
            virtual ExpectedResponseFactory GetInitialResponseFromModelName(
                const Crt::String &modelName) const noexcept = 0;
            virtual ExpectedResponseFactory GetStreamingResponseFromModelName(
                const Crt::String &modelName) const noexcept = 0;
            virtual ErrorResponseFactory GetOperationErrorFromModelName(
                const Crt::String &modelName) const noexcept = 0;
        };

        class AWS_EVENTSTREAMRPC_API ServiceModel
        {
          public:
            virtual Crt::ScopedResource<OperationError> AllocateOperationErrorFromPayload(
                const Crt::String &errorModelName,
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept = 0;
        };

        class AWS_EVENTSTREAMRPC_API OperationModelContext
        {
          public:
            OperationModelContext(const ServiceModel &serviceModel) noexcept;
            virtual Crt::ScopedResource<OperationResponse> AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept = 0;
            virtual Crt::ScopedResource<OperationResponse> AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept = 0;
            virtual Crt::String GetInitialResponseModelName() const noexcept = 0;
            virtual Crt::String GetRequestModelName() const noexcept = 0;
            virtual Crt::Optional<Crt::String> GetStreamingResponseModelName() const noexcept = 0;
            virtual Crt::String GetOperationName() const noexcept = 0;
            Crt::ScopedResource<OperationError> AllocateOperationErrorFromPayload(
                const Crt::String &errorModelName,
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return m_serviceModel.AllocateOperationErrorFromPayload(errorModelName, stringView, allocator);
            }

          private:
            const ServiceModel &m_serviceModel;
        };

        class AWS_EVENTSTREAMRPC_API ClientOperation : private ClientContinuationHandler
        {
          public:
            ClientOperation(
                ClientConnection &connection,
                StreamResponseHandler *streamHandler,
                const OperationModelContext &operationModelContext,
                Crt::Allocator *allocator) noexcept;
            ~ClientOperation() noexcept;
            ClientOperation(const ClientOperation &clientOperation) noexcept = delete;
            ClientOperation(ClientOperation &&clientOperation) noexcept;
            std::future<RpcError> Close(OnMessageFlushCallback onMessageFlushCallback = nullptr) noexcept;
            std::future<TaggedResult> GetOperationResult() noexcept;
            // virtual bool IsStreaming() = 0;

          protected:
            std::future<RpcError> Activate(
                const OperationRequest *shape,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;
            std::future<RpcError> SendStreamEvent(
                OperationRequest *shape,
                OnMessageFlushCallback onMessageFlushCallback) noexcept;
            virtual Crt::String GetModelName() const noexcept = 0;
            const OperationModelContext &m_operationModelContext;

          private:
            EventStreamRpcError HandleData(const Crt::String &modelName, const Crt::Optional<Crt::ByteBuf> &payload);
            EventStreamRpcError HandleError(
                const Crt::String &modelName,
                const Crt::Optional<Crt::ByteBuf> &payload,
                uint16_t messageFlags);
            /**
             * Invoked when a message is received on this continuation.
             */
            void OnContinuationMessage(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::Optional<Crt::ByteBuf> &payload,
                MessageType messageType,
                uint32_t messageFlags) override;
            /**
             * Invoked when the continuation is closed.
             *
             * Once the continuation is closed, no more messages may be sent or received.
             * The continuation is closed when a message is sent or received with
             * the TERMINATE_STREAM flag, or when the connection shuts down.
             */
            void OnContinuationClosed() override;

            const EventStreamHeader *GetHeaderByName(
                const Crt::List<EventStreamHeader> &headers,
                const Crt::String &name) noexcept;
            uint32_t m_messageCount;
            Crt::Allocator *m_allocator;
            StreamResponseHandler *m_streamHandler;
            ClientContinuation m_clientContinuation;
            ProtectedPromise<TaggedResult> m_initialResponsePromise;
            /* ProtectedPromise not necessary because it's only ever being set by one thread. */
            std::promise<void> m_closedPromise;
            std::atomic<bool> m_isClosed;
        };
    } // namespace Eventstreamrpc
} // namespace Aws
