/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

/* This file is generated. */

#include <aws/eventstreamrpc/EventStreamClient.h>

#include <aws/crt/DateTime.h>
#include <aws/ipc/Exports.h>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace EchoTestRpc
        {
            class EchoTestRpcClient;
            class EchoTestRpcServiceModel;
            class Product : public AbstractShapeBase
            {
              public:
                Product() noexcept {}
                Product(const Product &) = default;
                void SetName(const Crt::String &name) noexcept { m_name = name; }
                Crt::Optional<Crt::String> GetName() noexcept { return m_name; }
                void SetPrice(const double &price) noexcept { m_price = price; }
                Crt::Optional<double> GetPrice() noexcept { return m_price; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(Product &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(Product *) noexcept;
                /* This needs to be defined so that `Product` can be used as a key in maps. */
                bool operator<(const Product &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_name;
                Crt::Optional<double> m_price;
            };

            class Customer : public AbstractShapeBase
            {
              public:
                Customer() noexcept {}
                Customer(const Customer &) = default;
                void SetId(const int &id) noexcept { m_id = id; }
                Crt::Optional<int> GetId() noexcept { return m_id; }
                void SetFirstName(const Crt::String &firstName) noexcept { m_firstName = firstName; }
                Crt::Optional<Crt::String> GetFirstName() noexcept { return m_firstName; }
                void SetLastName(const Crt::String &lastName) noexcept { m_lastName = lastName; }
                Crt::Optional<Crt::String> GetLastName() noexcept { return m_lastName; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(Customer &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(Customer *) noexcept;
                /* This needs to be defined so that `Customer` can be used as a key in maps. */
                bool operator<(const Customer &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<int> m_id;
                Crt::Optional<Crt::String> m_firstName;
                Crt::Optional<Crt::String> m_lastName;
            };

            enum FruitEnum
            {
                FRUIT_ENUM_APPLE,
                FRUIT_ENUM_ORANGE,
                FRUIT_ENUM_BANANA,
                FRUIT_ENUM_PINEAPPLE
            };

            class Pair : public AbstractShapeBase
            {
              public:
                Pair() noexcept {}
                Pair(const Pair &) = default;
                void SetKey(const Crt::String &key) noexcept { m_key = key; }
                Crt::Optional<Crt::String> GetKey() noexcept { return m_key; }
                void SetValue(const Crt::String &value) noexcept { m_value = value; }
                Crt::Optional<Crt::String> GetValue() noexcept { return m_value; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(Pair &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(Pair *) noexcept;
                /* This needs to be defined so that `Pair` can be used as a key in maps. */
                bool operator<(const Pair &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_key;
                Crt::Optional<Crt::String> m_value;
            };

            class MessageData : public AbstractShapeBase
            {
              public:
                MessageData() noexcept {}
                MessageData(const MessageData &) = default;
                void SetStringMessage(const Crt::String &stringMessage) noexcept { m_stringMessage = stringMessage; }
                Crt::Optional<Crt::String> GetStringMessage() noexcept { return m_stringMessage; }
                void SetBooleanMessage(const bool &booleanMessage) noexcept { m_booleanMessage = booleanMessage; }
                Crt::Optional<bool> GetBooleanMessage() noexcept { return m_booleanMessage; }
                void SetTimeMessage(const Crt::DateTime &timeMessage) noexcept { m_timeMessage = timeMessage; }
                Crt::Optional<Crt::DateTime> GetTimeMessage() noexcept { return m_timeMessage; }
                void SetDocumentMessage(const Crt::JsonObject &documentMessage) noexcept
                {
                    m_documentMessage = documentMessage;
                }
                Crt::Optional<Crt::JsonObject> GetDocumentMessage() noexcept { return m_documentMessage; }
                void SetEnumMessage(FruitEnum enumMessage) noexcept;
                Crt::Optional<FruitEnum> GetEnumMessage() noexcept;
                void SetBlobMessage(const Crt::Vector<uint8_t> &blobMessage) noexcept { m_blobMessage = blobMessage; }
                Crt::Optional<Crt::Vector<uint8_t>> GetBlobMessage() noexcept { return m_blobMessage; }
                void SetStringListMessage(const Crt::Vector<Crt::String> &stringListMessage) noexcept
                {
                    m_stringListMessage = stringListMessage;
                }
                Crt::Optional<Crt::Vector<Crt::String>> GetStringListMessage() noexcept { return m_stringListMessage; }
                void SetKeyValuePairList(const Crt::Vector<Pair> &keyValuePairList) noexcept
                {
                    m_keyValuePairList = keyValuePairList;
                }
                Crt::Optional<Crt::Vector<Pair>> GetKeyValuePairList() noexcept { return m_keyValuePairList; }
                void SetStringToValue(const Crt::Map<Crt::String, Product> &stringToValue) noexcept
                {
                    m_stringToValue = stringToValue;
                }
                Crt::Optional<Crt::Map<Crt::String, Product>> GetStringToValue() noexcept { return m_stringToValue; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(MessageData &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(MessageData *) noexcept;
                /* This needs to be defined so that `MessageData` can be used as a key in maps. */
                bool operator<(const MessageData &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_stringMessage;
                Crt::Optional<bool> m_booleanMessage;
                Crt::Optional<Crt::DateTime> m_timeMessage;
                Crt::Optional<Crt::JsonObject> m_documentMessage;
                Crt::Optional<Crt::String> m_enumMessage;
                Crt::Optional<Crt::Vector<uint8_t>> m_blobMessage;
                Crt::Optional<Crt::Vector<Crt::String>> m_stringListMessage;
                Crt::Optional<Crt::Vector<Pair>> m_keyValuePairList;
                Crt::Optional<Crt::Map<Crt::String, Product>> m_stringToValue;
            };

            class EchoStreamingMessage : public OperationResponse
            {
              public:
                EchoStreamingMessage() noexcept {}
                EchoStreamingMessage &operator=(const EchoStreamingMessage &) noexcept;
                EchoStreamingMessage(const EchoStreamingMessage &objectToCopy) { *this = objectToCopy; }
                void SetStreamMessage(const MessageData &streamMessage) noexcept
                {
                    m_streamMessage = streamMessage;
                    m_chosenMember = TAG_STREAM_MESSAGE;
                }
                Crt::Optional<MessageData> GetStreamMessage() noexcept
                {
                    if (m_chosenMember == TAG_STREAM_MESSAGE)
                    {
                        return m_streamMessage;
                    }
                    else
                    {
                        return Crt::Optional<MessageData>();
                    }
                }
                void SetKeyValuePair(const Pair &keyValuePair) noexcept
                {
                    m_keyValuePair = keyValuePair;
                    m_chosenMember = TAG_KEY_VALUE_PAIR;
                }
                Crt::Optional<Pair> GetKeyValuePair() noexcept
                {
                    if (m_chosenMember == TAG_KEY_VALUE_PAIR)
                    {
                        return m_keyValuePair;
                    }
                    else
                    {
                        return Crt::Optional<Pair>();
                    }
                }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(EchoStreamingMessage &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(EchoStreamingMessage *) noexcept;
                /* This needs to be defined so that `EchoStreamingMessage` can be used as a key in maps. */
                bool operator<(const EchoStreamingMessage &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                enum ChosenMember
                {
                    TAG_STREAM_MESSAGE,
                    TAG_KEY_VALUE_PAIR
                } m_chosenMember;
                Crt::Optional<MessageData> m_streamMessage;
                Crt::Optional<Pair> m_keyValuePair;
            };

            class GetAllProductsResponse : public OperationResponse
            {
              public:
                GetAllProductsResponse() noexcept {}
                GetAllProductsResponse(const GetAllProductsResponse &) = default;
                void SetProducts(const Crt::Map<Crt::String, Product> &products) noexcept { m_products = products; }
                Crt::Optional<Crt::Map<Crt::String, Product>> GetProducts() noexcept { return m_products; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetAllProductsResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetAllProductsResponse *) noexcept;
                /* This needs to be defined so that `GetAllProductsResponse` can be used as a key in maps. */
                bool operator<(const GetAllProductsResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Map<Crt::String, Product>> m_products;
            };

            class GetAllProductsRequest : public OperationRequest
            {
              public:
                GetAllProductsRequest() noexcept {}
                GetAllProductsRequest(const GetAllProductsRequest &) = default;
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetAllProductsRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetAllProductsRequest *) noexcept;
                /* This needs to be defined so that `GetAllProductsRequest` can be used as a key in maps. */
                bool operator<(const GetAllProductsRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class GetAllCustomersResponse : public OperationResponse
            {
              public:
                GetAllCustomersResponse() noexcept {}
                GetAllCustomersResponse(const GetAllCustomersResponse &) = default;
                void SetCustomers(const Crt::Vector<Customer> &customers) noexcept { m_customers = customers; }
                Crt::Optional<Crt::Vector<Customer>> GetCustomers() noexcept { return m_customers; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetAllCustomersResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetAllCustomersResponse *) noexcept;
                /* This needs to be defined so that `GetAllCustomersResponse` can be used as a key in maps. */
                bool operator<(const GetAllCustomersResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<Customer>> m_customers;
            };

            class GetAllCustomersRequest : public OperationRequest
            {
              public:
                GetAllCustomersRequest() noexcept {}
                GetAllCustomersRequest(const GetAllCustomersRequest &) = default;
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetAllCustomersRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetAllCustomersRequest *) noexcept;
                /* This needs to be defined so that `GetAllCustomersRequest` can be used as a key in maps. */
                bool operator<(const GetAllCustomersRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class EchoMessageResponse : public OperationResponse
            {
              public:
                EchoMessageResponse() noexcept {}
                EchoMessageResponse(const EchoMessageResponse &) = default;
                void SetMessage(const MessageData &message) noexcept { m_message = message; }
                Crt::Optional<MessageData> GetMessage() noexcept { return m_message; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(EchoMessageResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(EchoMessageResponse *) noexcept;
                /* This needs to be defined so that `EchoMessageResponse` can be used as a key in maps. */
                bool operator<(const EchoMessageResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<MessageData> m_message;
            };

            class EchoMessageRequest : public OperationRequest
            {
              public:
                EchoMessageRequest() noexcept {}
                EchoMessageRequest(const EchoMessageRequest &) = default;
                void SetMessage(const MessageData &message) noexcept { m_message = message; }
                Crt::Optional<MessageData> GetMessage() noexcept { return m_message; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(EchoMessageRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(EchoMessageRequest *) noexcept;
                /* This needs to be defined so that `EchoMessageRequest` can be used as a key in maps. */
                bool operator<(const EchoMessageRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<MessageData> m_message;
            };

            class EchoStreamingResponse : public OperationResponse
            {
              public:
                EchoStreamingResponse() noexcept {}
                EchoStreamingResponse(const EchoStreamingResponse &) = default;
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(EchoStreamingResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(EchoStreamingResponse *) noexcept;
                /* This needs to be defined so that `EchoStreamingResponse` can be used as a key in maps. */
                bool operator<(const EchoStreamingResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class EchoStreamingRequest : public OperationRequest
            {
              public:
                EchoStreamingRequest() noexcept {}
                EchoStreamingRequest(const EchoStreamingRequest &) = default;
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(EchoStreamingRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(EchoStreamingRequest *) noexcept;
                /* This needs to be defined so that `EchoStreamingRequest` can be used as a key in maps. */
                bool operator<(const EchoStreamingRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class ServiceError : public OperationError
            {
              public:
                ServiceError() noexcept {}
                ServiceError(const ServiceError &) = default;
                void SetMessage(const Crt::String &message) noexcept { m_message = message; }
                Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
                void SetValue(const Crt::String &value) noexcept { m_value = value; }
                Crt::Optional<Crt::String> GetValue() noexcept { return m_value; }
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ServiceError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ServiceError *) noexcept;
                /* This needs to be defined so that `ServiceError` can be used as a key in maps. */
                bool operator<(const ServiceError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
                Crt::Optional<Crt::String> m_value;
            };

            class CauseServiceErrorResponse : public OperationResponse
            {
              public:
                CauseServiceErrorResponse() noexcept {}
                CauseServiceErrorResponse(const CauseServiceErrorResponse &) = default;
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(CauseServiceErrorResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(CauseServiceErrorResponse *) noexcept;
                /* This needs to be defined so that `CauseServiceErrorResponse` can be used as a key in maps. */
                bool operator<(const CauseServiceErrorResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class CauseServiceErrorRequest : public OperationRequest
            {
              public:
                CauseServiceErrorRequest() noexcept {}
                CauseServiceErrorRequest(const CauseServiceErrorRequest &) = default;
                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(CauseServiceErrorRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(CauseServiceErrorRequest *) noexcept;
                /* This needs to be defined so that `CauseServiceErrorRequest` can be used as a key in maps. */
                bool operator<(const CauseServiceErrorRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class GetAllProductsOperationContext : public OperationModelContext
            {
              public:
                GetAllProductsOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept;
                Crt::ScopedResource<OperationResponse> AllocateInitialResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::ScopedResource<OperationResponse> AllocateStreamingResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::String GetRequestModelName() const noexcept override;
                Crt::String GetInitialResponseModelName() const noexcept override;
                Crt::Optional<Crt::String> GetStreamingResponseModelName() const noexcept override;
                Crt::String GetOperationName() const noexcept override;
            };

            class GetAllProductsOperation : public ClientOperation
            {
              public:
                GetAllProductsOperation(
                    ClientConnection &connection,
                    const GetAllProductsOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const GetAllProductsRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class CauseServiceErrorOperationContext : public OperationModelContext
            {
              public:
                CauseServiceErrorOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept;
                Crt::ScopedResource<OperationResponse> AllocateInitialResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::ScopedResource<OperationResponse> AllocateStreamingResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::String GetRequestModelName() const noexcept override;
                Crt::String GetInitialResponseModelName() const noexcept override;
                Crt::Optional<Crt::String> GetStreamingResponseModelName() const noexcept override;
                Crt::String GetOperationName() const noexcept override;
            };

            class CauseServiceErrorOperation : public ClientOperation
            {
              public:
                CauseServiceErrorOperation(
                    ClientConnection &connection,
                    const CauseServiceErrorOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const CauseServiceErrorRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class CauseStreamServiceToErrorStreamHandler : public StreamResponseHandler
            {
              public:
                virtual void OnStreamEvent(EchoStreamingMessage *response) { (void)response; }
                virtual bool OnStreamError(ServiceError *operationError, RpcError rpcError)
                {
                    (void)operationError;
                    (void)rpcError;
                    return true;
                }

              private:
                /**
                 * Invoked when a message is received on this continuation.
                 */
                void OnStreamEvent(Crt::ScopedResource<OperationResponse> response) override;
                /**
                 * Invoked when a message is received on this continuation but results in an error.
                 *
                 * This callback can return true so that the stream is closed afterwards.
                 */
                bool OnStreamError(Crt::ScopedResource<OperationError> error, RpcError rpcError) override;
            };
            class CauseStreamServiceToErrorOperationContext : public OperationModelContext
            {
              public:
                CauseStreamServiceToErrorOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept;
                Crt::ScopedResource<OperationResponse> AllocateInitialResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::ScopedResource<OperationResponse> AllocateStreamingResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::String GetRequestModelName() const noexcept override;
                Crt::String GetInitialResponseModelName() const noexcept override;
                Crt::Optional<Crt::String> GetStreamingResponseModelName() const noexcept override;
                Crt::String GetOperationName() const noexcept override;
            };

            class CauseStreamServiceToErrorOperation : public ClientOperation
            {
              public:
                CauseStreamServiceToErrorOperation(
                    ClientConnection &connection,
                    CauseStreamServiceToErrorStreamHandler *streamHandler,
                    const CauseStreamServiceToErrorOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const CauseStreamServiceToErrorRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class EchoStreamMessagesStreamHandler : public StreamResponseHandler
            {
              public:
                virtual void OnStreamEvent(EchoStreamingMessage *response) { (void)response; }

              private:
                /**
                 * Invoked when a message is received on this continuation.
                 */
                void OnStreamEvent(Crt::ScopedResource<OperationResponse> response) override;
                /**
                 * Invoked when a message is received on this continuation but results in an error.
                 *
                 * This callback can return true so that the stream is closed afterwards.
                 */
                bool OnStreamError(Crt::ScopedResource<OperationError> error, RpcError rpcError) override;
            };
            class EchoStreamMessagesOperationContext : public OperationModelContext
            {
              public:
                EchoStreamMessagesOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept;
                Crt::ScopedResource<OperationResponse> AllocateInitialResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::ScopedResource<OperationResponse> AllocateStreamingResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::String GetRequestModelName() const noexcept override;
                Crt::String GetInitialResponseModelName() const noexcept override;
                Crt::Optional<Crt::String> GetStreamingResponseModelName() const noexcept override;
                Crt::String GetOperationName() const noexcept override;
            };

            class EchoStreamMessagesOperation : public ClientOperation
            {
              public:
                EchoStreamMessagesOperation(
                    ClientConnection &connection,
                    EchoStreamMessagesStreamHandler *streamHandler,
                    const EchoStreamMessagesOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const EchoStreamMessagesRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class EchoMessageOperationContext : public OperationModelContext
            {
              public:
                EchoMessageOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept;
                Crt::ScopedResource<OperationResponse> AllocateInitialResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::ScopedResource<OperationResponse> AllocateStreamingResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::String GetRequestModelName() const noexcept override;
                Crt::String GetInitialResponseModelName() const noexcept override;
                Crt::Optional<Crt::String> GetStreamingResponseModelName() const noexcept override;
                Crt::String GetOperationName() const noexcept override;
            };

            class EchoMessageOperation : public ClientOperation
            {
              public:
                EchoMessageOperation(
                    ClientConnection &connection,
                    const EchoMessageOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const EchoMessageRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class GetAllCustomersOperationContext : public OperationModelContext
            {
              public:
                GetAllCustomersOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept;
                Crt::ScopedResource<OperationResponse> AllocateInitialResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::ScopedResource<OperationResponse> AllocateStreamingResponseFromPayload(
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                Crt::String GetRequestModelName() const noexcept override;
                Crt::String GetInitialResponseModelName() const noexcept override;
                Crt::Optional<Crt::String> GetStreamingResponseModelName() const noexcept override;
                Crt::String GetOperationName() const noexcept override;
            };

            class GetAllCustomersOperation : public ClientOperation
            {
              public:
                GetAllCustomersOperation(
                    ClientConnection &connection,
                    const GetAllCustomersOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const GetAllCustomersRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class EchoTestRpcServiceModel : public ServiceModel
            {
              public:
                EchoTestRpcServiceModel() noexcept;
                Crt::ScopedResource<OperationError> AllocateOperationErrorFromPayload(
                    const Crt::String &errorModelName,
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                void AssignModelNameToErrorResponse(Crt::String, ErrorResponseFactory) noexcept;

              private:
                friend class EchoTestRpcClient;
                GetAllProductsOperationContext m_getAllProductsOperationContext;
                CauseServiceErrorOperationContext m_causeServiceErrorOperationContext;
                CauseStreamServiceToErrorOperationContext m_causeStreamServiceToErrorOperationContext;
                EchoStreamMessagesOperationContext m_echoStreamMessagesOperationContext;
                EchoMessageOperationContext m_echoMessageOperationContext;
                GetAllCustomersOperationContext m_getAllCustomersOperationContext;
                Crt::Map<Crt::String, ErrorResponseFactory> m_modelNameToErrorResponse;
            };
        } // namespace EchoTestRpc
    }     // namespace Eventstreamrpc
} // namespace Aws
