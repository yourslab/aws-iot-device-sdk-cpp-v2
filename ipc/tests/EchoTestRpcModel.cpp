#include <aws/crt/Api.h>
#include <awstest/EchoTestRpcModel.h>

namespace Awstest
{
    void Product::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_name.has_value())
        {
            payloadObject.WithString("name", m_name.value());
        }
        if (m_price.has_value())
        {
            payloadObject.WithDouble("price", static_cast<double>(m_price.value()));
        }
    }

    void Product::s_loadFromJsonView(Product &product, const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("name"))
        {
            product.m_name = Crt::Optional<Crt::String>(jsonView.GetString("name"));
        }
        if (jsonView.ValueExists("price"))
        {
            product.m_price = Crt::Optional<float>(static_cast<float>(jsonView.GetDouble("price")));
        }
    }

    Crt::String Product::GetModelName() const noexcept { return Crt::String("awstest#Product"); }

    Crt::ScopedResource<AbstractShapeBase> Product::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<Product> shape(Crt::New<Product>(allocator), Product::s_customDeleter);
        shape->m_allocator = allocator;
        Product::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<AbstractShapeBase *>(shape.release());
        return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
    }

    void Product::s_customDeleter(Product *shape) noexcept
    {
        AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
    }

    void Customer::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_id.has_value())
        {
            payloadObject.WithInt64("id", m_id.value());
        }
        if (m_firstName.has_value())
        {
            payloadObject.WithString("firstName", m_firstName.value());
        }
        if (m_lastName.has_value())
        {
            payloadObject.WithString("lastName", m_lastName.value());
        }
    }

    void Customer::s_loadFromJsonView(Customer &customer, const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("id"))
        {
            customer.m_id = Crt::Optional<int64_t>(jsonView.GetInt64("id"));
        }
        if (jsonView.ValueExists("firstName"))
        {
            customer.m_firstName = Crt::Optional<Crt::String>(jsonView.GetString("firstName"));
        }
        if (jsonView.ValueExists("lastName"))
        {
            customer.m_lastName = Crt::Optional<Crt::String>(jsonView.GetString("lastName"));
        }
    }

    Crt::String Customer::GetModelName() const noexcept { return Crt::String("awstest#Customer"); }

    Crt::ScopedResource<AbstractShapeBase> Customer::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<Customer> shape(Crt::New<Customer>(allocator), Customer::s_customDeleter);
        shape->m_allocator = allocator;
        Customer::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<AbstractShapeBase *>(shape.release());
        return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
    }

    void Customer::s_customDeleter(Customer *shape) noexcept
    {
        AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
    }

    void Pair::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_key.has_value())
        {
            payloadObject.WithString("key", m_key.value());
        }
        if (m_value.has_value())
        {
            payloadObject.WithString("value", m_value.value());
        }
    }

    void Pair::s_loadFromJsonView(Pair &pair, const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("key"))
        {
            pair.m_key = Crt::Optional<Crt::String>(jsonView.GetString("key"));
        }
        if (jsonView.ValueExists("value"))
        {
            pair.m_value = Crt::Optional<Crt::String>(jsonView.GetString("value"));
        }
    }

    Crt::String Pair::GetModelName() const noexcept { return Crt::String("awstest#Pair"); }

    Crt::ScopedResource<AbstractShapeBase> Pair::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<Pair> shape(Crt::New<Pair>(allocator), Pair::s_customDeleter);
        shape->m_allocator = allocator;
        Pair::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<AbstractShapeBase *>(shape.release());
        return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
    }

    void Pair::s_customDeleter(Pair *shape) noexcept
    {
        AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
    }

    void MessageData::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_stringMessage.has_value())
        {
            payloadObject.WithString("stringMessage", m_stringMessage.value());
        }
        if (m_booleanMessage.has_value())
        {
            payloadObject.WithBool("booleanMessage", m_booleanMessage.value());
        }
        if (m_timeMessage.has_value())
        {
            payloadObject.WithDouble("timeMessage", m_timeMessage.value().SecondsWithMSPrecision());
        }
        if (m_documentMessage.has_value())
        {
            payloadObject.WithObject("documentMessage", m_documentMessage.value());
        }
        if (m_enumMessage.has_value())
        {
            payloadObject.WithString("enumMessage", m_enumMessage.value());
        }
        if (m_blobMessage.has_value())
        {
            if (m_blobMessage.value().size() > 0)
            {
                payloadObject.WithString("blobMessage", Crt::Base64Encode(m_blobMessage.value()));
            }
        }
        if (m_stringListMessage.has_value())
        {
            Crt::JsonObject stringList;
            Crt::Vector<Crt::JsonObject> stringListJsonArray;
            for (const auto &stringListItem : m_stringListMessage.value())
            {
                Crt::JsonObject stringListJsonArrayItem;
                stringListJsonArrayItem.AsString(stringListItem);
                stringListJsonArray.emplace_back(std::move(stringListJsonArrayItem));
            }
            stringList.AsArray(std::move(stringListJsonArray));
            payloadObject.WithObject("stringListMessage", std::move(stringList));
        }
        if (m_keyValuePairList.has_value())
        {
            Crt::JsonObject keyValuePairList;
            Crt::Vector<Crt::JsonObject> keyValuePairListJsonArray;
            for (const auto &keyValuePairListItem : m_keyValuePairList.value())
            {
                Crt::JsonObject keyValuePairListJsonArrayItem;
                keyValuePairListItem.SerializeToJsonObject(keyValuePairListJsonArrayItem);
                keyValuePairListJsonArray.emplace_back(std::move(keyValuePairListJsonArrayItem));
            }
            keyValuePairList.AsArray(std::move(keyValuePairListJsonArray));
            payloadObject.WithObject("keyValuePairList", std::move(keyValuePairList));
        }
        if (m_stringToValue.has_value())
        {
            Crt::JsonObject stringToValueValue;
            for (const auto &stringToValueItem : m_stringToValue.value())
            {
                Crt::JsonObject stringToValueJsonObject;
                stringToValueItem.second.SerializeToJsonObject(stringToValueJsonObject);
                stringToValueValue.WithObject(stringToValueItem.first, std::move(stringToValueJsonObject));
            }
            payloadObject.WithObject("stringToValue", std::move(stringToValueValue));
        }
    }

    void MessageData::s_loadFromJsonView(MessageData &messageData, const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("stringMessage"))
        {
            messageData.m_stringMessage = Crt::Optional<Crt::String>(jsonView.GetString("stringMessage"));
        }
        if (jsonView.ValueExists("booleanMessage"))
        {
            messageData.m_booleanMessage = Crt::Optional<bool>(jsonView.GetBool("booleanMessage"));
        }
        if (jsonView.ValueExists("timeMessage"))
        {
            messageData.m_timeMessage = Crt::Optional<Crt::DateTime>(Crt::DateTime(jsonView.GetDouble("timeMessage")));
        }
        if (jsonView.ValueExists("documentMessage"))
        {
            messageData.m_documentMessage =
                Crt::Optional<Crt::JsonObject>(jsonView.GetJsonObject("documentMessage").Materialize());
        }
        if (jsonView.ValueExists("enumMessage"))
        {
            messageData.m_enumMessage = Crt::Optional<Crt::String>(jsonView.GetString("enumMessage"));
        }
        if (jsonView.ValueExists("blobMessage"))
        {
            if (jsonView.GetString("blobMessage").size() > 0)
            {
                messageData.m_blobMessage =
                    Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("blobMessage")));
            }
        }
        if (jsonView.ValueExists("stringListMessage"))
        {
            messageData.m_stringListMessage = Crt::Vector<Crt::String>();
            for (const Crt::JsonView &stringListJsonView : jsonView.GetArray("stringListMessage"))
            {
                Crt::Optional<Crt::String> stringListItem;
                stringListItem = Crt::Optional<Crt::String>(stringListJsonView.AsString());
                messageData.m_stringListMessage.value().push_back(stringListItem.value());
            }
        }
        if (jsonView.ValueExists("keyValuePairList"))
        {
            messageData.m_keyValuePairList = Crt::Vector<Pair>();
            for (const Crt::JsonView &keyValuePairListJsonView : jsonView.GetArray("keyValuePairList"))
            {
                Crt::Optional<Pair> keyValuePairListItem;
                keyValuePairListItem = Pair();
                Pair::s_loadFromJsonView(keyValuePairListItem.value(), keyValuePairListJsonView);
                messageData.m_keyValuePairList.value().push_back(keyValuePairListItem.value());
            }
        }
        if (jsonView.ValueExists("stringToValue"))
        {
            messageData.m_stringToValue = Crt::Map<Crt::String, Product>();
            for (const auto &stringToValuePair : jsonView.GetJsonObject("stringToValue").GetAllObjects())
            {
                Crt::Optional<Product> stringToValueValue;
                stringToValueValue = Product();
                Product::s_loadFromJsonView(stringToValueValue.value(), stringToValuePair.second);
                messageData.m_stringToValue.value()[stringToValuePair.first] = stringToValueValue.value();
            }
        }
    }

    void MessageData::SetEnumMessage(FruitEnum enumMessage) noexcept
    {
        switch (enumMessage)
        {
            case FRUIT_ENUM_APPLE:
                m_enumMessage = Crt::String("apl");
                break;
            case FRUIT_ENUM_ORANGE:
                m_enumMessage = Crt::String("org");
                break;
            case FRUIT_ENUM_BANANA:
                m_enumMessage = Crt::String("ban");
                break;
            case FRUIT_ENUM_PINEAPPLE:
                m_enumMessage = Crt::String("pin");
                break;
            default:
                break;
        }
    }

    Crt::Optional<FruitEnum> MessageData::GetEnumMessage() noexcept
    {
        if (!m_enumMessage.has_value())
            return Crt::Optional<FruitEnum>();
        if (m_enumMessage.value() == Crt::String("apl"))
        {
            return Crt::Optional<FruitEnum>(FRUIT_ENUM_APPLE);
        }
        if (m_enumMessage.value() == Crt::String("org"))
        {
            return Crt::Optional<FruitEnum>(FRUIT_ENUM_ORANGE);
        }
        if (m_enumMessage.value() == Crt::String("ban"))
        {
            return Crt::Optional<FruitEnum>(FRUIT_ENUM_BANANA);
        }
        if (m_enumMessage.value() == Crt::String("pin"))
        {
            return Crt::Optional<FruitEnum>(FRUIT_ENUM_PINEAPPLE);
        }

        return Crt::Optional<FruitEnum>();
    }

    Crt::String MessageData::GetModelName() const noexcept { return Crt::String("awstest#MessageData"); }

    Crt::ScopedResource<AbstractShapeBase> MessageData::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<MessageData> shape(Crt::New<MessageData>(allocator), MessageData::s_customDeleter);
        shape->m_allocator = allocator;
        MessageData::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<AbstractShapeBase *>(shape.release());
        return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
    }

    void MessageData::s_customDeleter(MessageData *shape) noexcept
    {
        AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
    }

    void EchoStreamingMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_chosenMember == TAG_STREAM_MESSAGE && m_streamMessage.has_value())
        {
            Crt::JsonObject messageDataValue;
            m_streamMessage.value().SerializeToJsonObject(messageDataValue);
            payloadObject.WithObject("streamMessage", std::move(messageDataValue));
        }
        else if (m_chosenMember == TAG_KEY_VALUE_PAIR && m_keyValuePair.has_value())
        {
            Crt::JsonObject pairValue;
            m_keyValuePair.value().SerializeToJsonObject(pairValue);
            payloadObject.WithObject("keyValuePair", std::move(pairValue));
        }
    }

    void EchoStreamingMessage::s_loadFromJsonView(
        EchoStreamingMessage &echoStreamingMessage,
        const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("streamMessage"))
        {
            echoStreamingMessage.m_streamMessage = MessageData();
            MessageData::s_loadFromJsonView(
                echoStreamingMessage.m_streamMessage.value(), jsonView.GetJsonObject("streamMessage"));
            echoStreamingMessage.m_chosenMember = TAG_STREAM_MESSAGE;
        }
        else if (jsonView.ValueExists("keyValuePair"))
        {
            echoStreamingMessage.m_keyValuePair = Pair();
            Pair::s_loadFromJsonView(
                echoStreamingMessage.m_keyValuePair.value(), jsonView.GetJsonObject("keyValuePair"));
            echoStreamingMessage.m_chosenMember = TAG_KEY_VALUE_PAIR;
        }
    }

    EchoStreamingMessage &EchoStreamingMessage::operator=(const EchoStreamingMessage &objectToCopy) noexcept
    {
        if (objectToCopy.m_chosenMember == TAG_STREAM_MESSAGE)
        {
            m_streamMessage = objectToCopy.m_streamMessage;
            m_chosenMember = objectToCopy.m_chosenMember;
        }
        else if (objectToCopy.m_chosenMember == TAG_KEY_VALUE_PAIR)
        {
            m_keyValuePair = objectToCopy.m_keyValuePair;
            m_chosenMember = objectToCopy.m_chosenMember;
        }
        return *this;
    }

    Crt::String EchoStreamingMessage::GetModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingMessage");
    }

    Crt::ScopedResource<OperationResponse> EchoStreamingMessage::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<EchoStreamingMessage> shape(
            Crt::New<EchoStreamingMessage>(allocator), EchoStreamingMessage::s_customDeleter);
        shape->m_allocator = allocator;
        EchoStreamingMessage::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationResponse *>(shape.release());
        return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
    }

    void EchoStreamingMessage::s_customDeleter(EchoStreamingMessage *shape) noexcept
    {
        OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
    }

    void GetAllProductsResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_products.has_value())
        {
            Crt::JsonObject productMapValue;
            for (const auto &productMapItem : m_products.value())
            {
                Crt::JsonObject productMapJsonObject;
                productMapItem.second.SerializeToJsonObject(productMapJsonObject);
                productMapValue.WithObject(productMapItem.first, std::move(productMapJsonObject));
            }
            payloadObject.WithObject("products", std::move(productMapValue));
        }
    }

    void GetAllProductsResponse::s_loadFromJsonView(
        GetAllProductsResponse &getAllProductsResponse,
        const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("products"))
        {
            getAllProductsResponse.m_products = Crt::Map<Crt::String, Product>();
            for (const auto &productMapPair : jsonView.GetJsonObject("products").GetAllObjects())
            {
                Crt::Optional<Product> productMapValue;
                productMapValue = Product();
                Product::s_loadFromJsonView(productMapValue.value(), productMapPair.second);
                getAllProductsResponse.m_products.value()[productMapPair.first] = productMapValue.value();
            }
        }
    }

    Crt::String GetAllProductsResponse::GetModelName() const noexcept
    {
        return Crt::String("awstest#GetAllProductsResponse");
    }

    Crt::ScopedResource<OperationResponse> GetAllProductsResponse::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<GetAllProductsResponse> shape(
            Crt::New<GetAllProductsResponse>(allocator), GetAllProductsResponse::s_customDeleter);
        shape->m_allocator = allocator;
        GetAllProductsResponse::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationResponse *>(shape.release());
        return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
    }

    void GetAllProductsResponse::s_customDeleter(GetAllProductsResponse *shape) noexcept
    {
        OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
    }

    void GetAllProductsRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        (void)payloadObject;
    }

    void GetAllProductsRequest::s_loadFromJsonView(
        GetAllProductsRequest &getAllProductsRequest,
        const Crt::JsonView &jsonView) noexcept
    {
        (void)getAllProductsRequest;
        (void)jsonView;
    }

    Crt::String GetAllProductsRequest::GetModelName() const noexcept
    {
        return Crt::String("awstest#GetAllProductsRequest");
    }

    Crt::ScopedResource<OperationRequest> GetAllProductsRequest::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<GetAllProductsRequest> shape(
            Crt::New<GetAllProductsRequest>(allocator), GetAllProductsRequest::s_customDeleter);
        shape->m_allocator = allocator;
        GetAllProductsRequest::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationRequest *>(shape.release());
        return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
    }

    void GetAllProductsRequest::s_customDeleter(GetAllProductsRequest *shape) noexcept
    {
        OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
    }

    void GetAllCustomersResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_customers.has_value())
        {
            Crt::JsonObject customerList;
            Crt::Vector<Crt::JsonObject> customerListJsonArray;
            for (const auto &customerListItem : m_customers.value())
            {
                Crt::JsonObject customerListJsonArrayItem;
                customerListItem.SerializeToJsonObject(customerListJsonArrayItem);
                customerListJsonArray.emplace_back(std::move(customerListJsonArrayItem));
            }
            customerList.AsArray(std::move(customerListJsonArray));
            payloadObject.WithObject("customers", std::move(customerList));
        }
    }

    void GetAllCustomersResponse::s_loadFromJsonView(
        GetAllCustomersResponse &getAllCustomersResponse,
        const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("customers"))
        {
            getAllCustomersResponse.m_customers = Crt::Vector<Customer>();
            for (const Crt::JsonView &customerListJsonView : jsonView.GetArray("customers"))
            {
                Crt::Optional<Customer> customerListItem;
                customerListItem = Customer();
                Customer::s_loadFromJsonView(customerListItem.value(), customerListJsonView);
                getAllCustomersResponse.m_customers.value().push_back(customerListItem.value());
            }
        }
    }

    Crt::String GetAllCustomersResponse::GetModelName() const noexcept
    {
        return Crt::String("awstest#GetAllCustomersResponse");
    }

    Crt::ScopedResource<OperationResponse> GetAllCustomersResponse::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<GetAllCustomersResponse> shape(
            Crt::New<GetAllCustomersResponse>(allocator), GetAllCustomersResponse::s_customDeleter);
        shape->m_allocator = allocator;
        GetAllCustomersResponse::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationResponse *>(shape.release());
        return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
    }

    void GetAllCustomersResponse::s_customDeleter(GetAllCustomersResponse *shape) noexcept
    {
        OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
    }

    void GetAllCustomersRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        (void)payloadObject;
    }

    void GetAllCustomersRequest::s_loadFromJsonView(
        GetAllCustomersRequest &getAllCustomersRequest,
        const Crt::JsonView &jsonView) noexcept
    {
        (void)getAllCustomersRequest;
        (void)jsonView;
    }

    Crt::String GetAllCustomersRequest::GetModelName() const noexcept
    {
        return Crt::String("awstest#GetAllCustomersRequest");
    }

    Crt::ScopedResource<OperationRequest> GetAllCustomersRequest::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<GetAllCustomersRequest> shape(
            Crt::New<GetAllCustomersRequest>(allocator), GetAllCustomersRequest::s_customDeleter);
        shape->m_allocator = allocator;
        GetAllCustomersRequest::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationRequest *>(shape.release());
        return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
    }

    void GetAllCustomersRequest::s_customDeleter(GetAllCustomersRequest *shape) noexcept
    {
        OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
    }

    void EchoMessageResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_message.has_value())
        {
            Crt::JsonObject messageDataValue;
            m_message.value().SerializeToJsonObject(messageDataValue);
            payloadObject.WithObject("message", std::move(messageDataValue));
        }
    }

    void EchoMessageResponse::s_loadFromJsonView(
        EchoMessageResponse &echoMessageResponse,
        const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("message"))
        {
            echoMessageResponse.m_message = MessageData();
            MessageData::s_loadFromJsonView(echoMessageResponse.m_message.value(), jsonView.GetJsonObject("message"));
        }
    }

    Crt::String EchoMessageResponse::GetModelName() const noexcept
    {
        return Crt::String("awstest#EchoMessageResponse");
    }

    Crt::ScopedResource<OperationResponse> EchoMessageResponse::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<EchoMessageResponse> shape(
            Crt::New<EchoMessageResponse>(allocator), EchoMessageResponse::s_customDeleter);
        shape->m_allocator = allocator;
        EchoMessageResponse::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationResponse *>(shape.release());
        return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
    }

    void EchoMessageResponse::s_customDeleter(EchoMessageResponse *shape) noexcept
    {
        OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
    }

    void EchoMessageRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_message.has_value())
        {
            Crt::JsonObject messageDataValue;
            m_message.value().SerializeToJsonObject(messageDataValue);
            payloadObject.WithObject("message", std::move(messageDataValue));
        }
    }

    void EchoMessageRequest::s_loadFromJsonView(
        EchoMessageRequest &echoMessageRequest,
        const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("message"))
        {
            echoMessageRequest.m_message = MessageData();
            MessageData::s_loadFromJsonView(echoMessageRequest.m_message.value(), jsonView.GetJsonObject("message"));
        }
    }

    Crt::String EchoMessageRequest::GetModelName() const noexcept { return Crt::String("awstest#EchoMessageRequest"); }

    Crt::ScopedResource<OperationRequest> EchoMessageRequest::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<EchoMessageRequest> shape(
            Crt::New<EchoMessageRequest>(allocator), EchoMessageRequest::s_customDeleter);
        shape->m_allocator = allocator;
        EchoMessageRequest::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationRequest *>(shape.release());
        return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
    }

    void EchoMessageRequest::s_customDeleter(EchoMessageRequest *shape) noexcept
    {
        OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
    }

    void EchoStreamingResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        (void)payloadObject;
    }

    void EchoStreamingResponse::s_loadFromJsonView(
        EchoStreamingResponse &echoStreamingResponse,
        const Crt::JsonView &jsonView) noexcept
    {
        (void)echoStreamingResponse;
        (void)jsonView;
    }

    Crt::String EchoStreamingResponse::GetModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingResponse");
    }

    Crt::ScopedResource<OperationResponse> EchoStreamingResponse::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<EchoStreamingResponse> shape(
            Crt::New<EchoStreamingResponse>(allocator), EchoStreamingResponse::s_customDeleter);
        shape->m_allocator = allocator;
        EchoStreamingResponse::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationResponse *>(shape.release());
        return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
    }

    void EchoStreamingResponse::s_customDeleter(EchoStreamingResponse *shape) noexcept
    {
        OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
    }

    void EchoStreamingRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        (void)payloadObject;
    }

    void EchoStreamingRequest::s_loadFromJsonView(
        EchoStreamingRequest &echoStreamingRequest,
        const Crt::JsonView &jsonView) noexcept
    {
        (void)echoStreamingRequest;
        (void)jsonView;
    }

    Crt::String EchoStreamingRequest::GetModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingRequest");
    }

    Crt::ScopedResource<OperationRequest> EchoStreamingRequest::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<EchoStreamingRequest> shape(
            Crt::New<EchoStreamingRequest>(allocator), EchoStreamingRequest::s_customDeleter);
        shape->m_allocator = allocator;
        EchoStreamingRequest::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationRequest *>(shape.release());
        return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
    }

    void EchoStreamingRequest::s_customDeleter(EchoStreamingRequest *shape) noexcept
    {
        OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
    }

    void ServiceError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        if (m_message.has_value())
        {
            payloadObject.WithString("message", m_message.value());
        }
        if (m_value.has_value())
        {
            payloadObject.WithString("value", m_value.value());
        }
    }

    void ServiceError::s_loadFromJsonView(ServiceError &serviceError, const Crt::JsonView &jsonView) noexcept
    {
        if (jsonView.ValueExists("message"))
        {
            serviceError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
        }
        if (jsonView.ValueExists("value"))
        {
            serviceError.m_value = Crt::Optional<Crt::String>(jsonView.GetString("value"));
        }
    }

    Crt::String ServiceError::GetModelName() const noexcept { return Crt::String("awstest#ServiceError"); }

    Crt::ScopedResource<OperationError> ServiceError::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<ServiceError> shape(Crt::New<ServiceError>(allocator), ServiceError::s_customDeleter);
        shape->m_allocator = allocator;
        ServiceError::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationError *>(shape.release());
        return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
    }

    void ServiceError::s_customDeleter(ServiceError *shape) noexcept
    {
        OperationError::s_customDeleter(static_cast<OperationError *>(shape));
    }

    void CauseServiceErrorResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        (void)payloadObject;
    }

    void CauseServiceErrorResponse::s_loadFromJsonView(
        CauseServiceErrorResponse &causeServiceErrorResponse,
        const Crt::JsonView &jsonView) noexcept
    {
        (void)causeServiceErrorResponse;
        (void)jsonView;
    }

    Crt::String CauseServiceErrorResponse::GetModelName() const noexcept
    {
        return Crt::String("awstest#CauseServiceErrorResponse");
    }

    Crt::ScopedResource<OperationResponse> CauseServiceErrorResponse::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<CauseServiceErrorResponse> shape(
            Crt::New<CauseServiceErrorResponse>(allocator), CauseServiceErrorResponse::s_customDeleter);
        shape->m_allocator = allocator;
        CauseServiceErrorResponse::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationResponse *>(shape.release());
        return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
    }

    void CauseServiceErrorResponse::s_customDeleter(CauseServiceErrorResponse *shape) noexcept
    {
        OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
    }

    void CauseServiceErrorRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
    {
        (void)payloadObject;
    }

    void CauseServiceErrorRequest::s_loadFromJsonView(
        CauseServiceErrorRequest &causeServiceErrorRequest,
        const Crt::JsonView &jsonView) noexcept
    {
        (void)causeServiceErrorRequest;
        (void)jsonView;
    }

    Crt::String CauseServiceErrorRequest::GetModelName() const noexcept
    {
        return Crt::String("awstest#CauseServiceErrorRequest");
    }

    Crt::ScopedResource<OperationRequest> CauseServiceErrorRequest::s_allocateFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) noexcept
    {
        Crt::String payload = {stringView.begin(), stringView.end()};
        Crt::JsonObject jsonObject(payload);
        Crt::JsonView jsonView(jsonObject);

        Crt::ScopedResource<CauseServiceErrorRequest> shape(
            Crt::New<CauseServiceErrorRequest>(allocator), CauseServiceErrorRequest::s_customDeleter);
        shape->m_allocator = allocator;
        CauseServiceErrorRequest::s_loadFromJsonView(*shape, jsonView);
        auto operationResponse = static_cast<OperationRequest *>(shape.release());
        return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
    }

    void CauseServiceErrorRequest::s_customDeleter(CauseServiceErrorRequest *shape) noexcept
    {
        OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
    }

    GetAllProductsOperationContext::GetAllProductsOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept
        : OperationModelContext(serviceModel)
    {
    }

    Crt::ScopedResource<OperationResponse> GetAllProductsOperationContext::AllocateInitialResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return GetAllProductsResponse::s_allocateFromPayload(stringView, allocator);
    }

    Crt::ScopedResource<OperationResponse> GetAllProductsOperationContext::AllocateStreamingResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return nullptr;
    }

    Crt::String GetAllProductsOperationContext::GetRequestModelName() const noexcept
    {
        return Crt::String("awstest#GetAllProductsRequest");
    }

    Crt::String GetAllProductsOperationContext::GetInitialResponseModelName() const noexcept
    {
        return Crt::String("awstest#GetAllProductsResponse");
    }

    Crt::Optional<Crt::String> GetAllProductsOperationContext::GetStreamingResponseModelName() const noexcept
    {
        return Crt::Optional<Crt::String>();
    }

    Crt::String GetAllProductsOperationContext::GetOperationName() const noexcept
    {
        return Crt::String("awstest#GetAllProducts");
    }

    std::future<GetAllProductsResult> GetAllProductsOperation::GetResult() noexcept
    {
        std::promise<GetAllProductsResult> result;
        result.set_value(GetAllProductsResult(std::move(GetOperationResult().get())));
        return result.get_future();
    }

    GetAllProductsOperation::GetAllProductsOperation(
        ClientConnection &connection,
        const GetAllProductsOperationContext &operationContext,
        Crt::Allocator *allocator) noexcept
        : ClientOperation(connection, nullptr, operationContext, allocator)
    {
    }

    std::future<RpcError> GetAllProductsOperation::Activate(
        const GetAllProductsRequest &request,
        OnMessageFlushCallback onMessageFlushCallback) noexcept
    {
        return ClientOperation::Activate(static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
    }

    Crt::String GetAllProductsOperation::GetModelName() const noexcept
    {
        return m_operationModelContext.GetOperationName();
    }

    CauseServiceErrorOperationContext::CauseServiceErrorOperationContext(
        const EchoTestRpcServiceModel &serviceModel) noexcept
        : OperationModelContext(serviceModel)
    {
    }

    Crt::ScopedResource<OperationResponse> CauseServiceErrorOperationContext::AllocateInitialResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return CauseServiceErrorResponse::s_allocateFromPayload(stringView, allocator);
    }

    Crt::ScopedResource<OperationResponse> CauseServiceErrorOperationContext::AllocateStreamingResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return nullptr;
    }

    Crt::String CauseServiceErrorOperationContext::GetRequestModelName() const noexcept
    {
        return Crt::String("awstest#CauseServiceErrorRequest");
    }

    Crt::String CauseServiceErrorOperationContext::GetInitialResponseModelName() const noexcept
    {
        return Crt::String("awstest#CauseServiceErrorResponse");
    }

    Crt::Optional<Crt::String> CauseServiceErrorOperationContext::GetStreamingResponseModelName() const noexcept
    {
        return Crt::Optional<Crt::String>();
    }

    Crt::String CauseServiceErrorOperationContext::GetOperationName() const noexcept
    {
        return Crt::String("awstest#CauseServiceError");
    }

    std::future<CauseServiceErrorResult> CauseServiceErrorOperation::GetResult() noexcept
    {
        std::promise<CauseServiceErrorResult> result;
        result.set_value(CauseServiceErrorResult(std::move(GetOperationResult().get())));
        return result.get_future();
    }

    CauseServiceErrorOperation::CauseServiceErrorOperation(
        ClientConnection &connection,
        const CauseServiceErrorOperationContext &operationContext,
        Crt::Allocator *allocator) noexcept
        : ClientOperation(connection, nullptr, operationContext, allocator)
    {
    }

    std::future<RpcError> CauseServiceErrorOperation::Activate(
        const CauseServiceErrorRequest &request,
        OnMessageFlushCallback onMessageFlushCallback) noexcept
    {
        return ClientOperation::Activate(static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
    }

    Crt::String CauseServiceErrorOperation::GetModelName() const noexcept
    {
        return m_operationModelContext.GetOperationName();
    }

    void CauseStreamServiceToErrorStreamHandler::OnStreamEvent(Crt::ScopedResource<OperationResponse> response)
    {
        OnStreamEvent(static_cast<EchoStreamingMessage *>(response.get()));
    }

    bool CauseStreamServiceToErrorStreamHandler::OnStreamError(
        Crt::ScopedResource<OperationError> operationError,
        RpcError rpcError)
    {
        if (operationError->GetModelName() == Crt::String("awstest#ServiceError"))
        {
            return OnStreamError(static_cast<ServiceError *>(operationError.get()), rpcError);
        }
        return true;
    }

    CauseStreamServiceToErrorOperationContext::CauseStreamServiceToErrorOperationContext(
        const EchoTestRpcServiceModel &serviceModel) noexcept
        : OperationModelContext(serviceModel)
    {
    }

    Crt::ScopedResource<OperationResponse> CauseStreamServiceToErrorOperationContext::
        AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
    {
        return EchoStreamingResponse::s_allocateFromPayload(stringView, allocator);
    }

    Crt::ScopedResource<OperationResponse> CauseStreamServiceToErrorOperationContext::
        AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
    {
        return EchoStreamingMessage::s_allocateFromPayload(stringView, allocator);
    }

    Crt::String CauseStreamServiceToErrorOperationContext::GetRequestModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingRequest");
    }

    Crt::String CauseStreamServiceToErrorOperationContext::GetInitialResponseModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingResponse");
    }

    Crt::Optional<Crt::String> CauseStreamServiceToErrorOperationContext::GetStreamingResponseModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingMessage");
    }

    Crt::String CauseStreamServiceToErrorOperationContext::GetOperationName() const noexcept
    {
        return Crt::String("awstest#CauseStreamServiceToError");
    }

    std::future<CauseStreamServiceToErrorResult> CauseStreamServiceToErrorOperation::GetResult() noexcept
    {
        std::promise<CauseStreamServiceToErrorResult> result;
        result.set_value(CauseStreamServiceToErrorResult(std::move(GetOperationResult().get())));
        return result.get_future();
    }

    CauseStreamServiceToErrorOperation::CauseStreamServiceToErrorOperation(
        ClientConnection &connection,
        CauseStreamServiceToErrorStreamHandler *streamHandler,
        const CauseStreamServiceToErrorOperationContext &operationContext,
        Crt::Allocator *allocator) noexcept
        : ClientOperation(connection, streamHandler, operationContext, allocator)
    {
    }

    std::future<RpcError> CauseStreamServiceToErrorOperation::Activate(
        const CauseStreamServiceToErrorRequest &request,
        OnMessageFlushCallback onMessageFlushCallback) noexcept
    {
        return ClientOperation::Activate(static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
    }

    Crt::String CauseStreamServiceToErrorOperation::GetModelName() const noexcept
    {
        return m_operationModelContext.GetOperationName();
    }

    void EchoStreamMessagesStreamHandler::OnStreamEvent(Crt::ScopedResource<OperationResponse> response)
    {
        OnStreamEvent(static_cast<EchoStreamingMessage *>(response.get()));
    }

    bool EchoStreamMessagesStreamHandler::OnStreamError(
        Crt::ScopedResource<OperationError> operationError,
        RpcError rpcError)
    {
        return true;
    }

    EchoStreamMessagesOperationContext::EchoStreamMessagesOperationContext(
        const EchoTestRpcServiceModel &serviceModel) noexcept
        : OperationModelContext(serviceModel)
    {
    }

    Crt::ScopedResource<OperationResponse> EchoStreamMessagesOperationContext::AllocateInitialResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return EchoStreamingResponse::s_allocateFromPayload(stringView, allocator);
    }

    Crt::ScopedResource<OperationResponse> EchoStreamMessagesOperationContext::AllocateStreamingResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return EchoStreamingMessage::s_allocateFromPayload(stringView, allocator);
    }

    Crt::String EchoStreamMessagesOperationContext::GetRequestModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingRequest");
    }

    Crt::String EchoStreamMessagesOperationContext::GetInitialResponseModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingResponse");
    }

    Crt::Optional<Crt::String> EchoStreamMessagesOperationContext::GetStreamingResponseModelName() const noexcept
    {
        return Crt::String("awstest#EchoStreamingMessage");
    }

    Crt::String EchoStreamMessagesOperationContext::GetOperationName() const noexcept
    {
        return Crt::String("awstest#EchoStreamMessages");
    }

    std::future<EchoStreamMessagesResult> EchoStreamMessagesOperation::GetResult() noexcept
    {
        std::promise<EchoStreamMessagesResult> result;
        result.set_value(EchoStreamMessagesResult(std::move(GetOperationResult().get())));
        return result.get_future();
    }

    EchoStreamMessagesOperation::EchoStreamMessagesOperation(
        ClientConnection &connection,
        EchoStreamMessagesStreamHandler *streamHandler,
        const EchoStreamMessagesOperationContext &operationContext,
        Crt::Allocator *allocator) noexcept
        : ClientOperation(connection, streamHandler, operationContext, allocator)
    {
    }

    std::future<RpcError> EchoStreamMessagesOperation::Activate(
        const EchoStreamMessagesRequest &request,
        OnMessageFlushCallback onMessageFlushCallback) noexcept
    {
        return ClientOperation::Activate(static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
    }

    Crt::String EchoStreamMessagesOperation::GetModelName() const noexcept
    {
        return m_operationModelContext.GetOperationName();
    }

    EchoMessageOperationContext::EchoMessageOperationContext(const EchoTestRpcServiceModel &serviceModel) noexcept
        : OperationModelContext(serviceModel)
    {
    }

    Crt::ScopedResource<OperationResponse> EchoMessageOperationContext::AllocateInitialResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return EchoMessageResponse::s_allocateFromPayload(stringView, allocator);
    }

    Crt::ScopedResource<OperationResponse> EchoMessageOperationContext::AllocateStreamingResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return nullptr;
    }

    Crt::String EchoMessageOperationContext::GetRequestModelName() const noexcept
    {
        return Crt::String("awstest#EchoMessageRequest");
    }

    Crt::String EchoMessageOperationContext::GetInitialResponseModelName() const noexcept
    {
        return Crt::String("awstest#EchoMessageResponse");
    }

    Crt::Optional<Crt::String> EchoMessageOperationContext::GetStreamingResponseModelName() const noexcept
    {
        return Crt::Optional<Crt::String>();
    }

    Crt::String EchoMessageOperationContext::GetOperationName() const noexcept
    {
        return Crt::String("awstest#EchoMessage");
    }

    std::future<EchoMessageResult> EchoMessageOperation::GetResult() noexcept
    {
        std::promise<EchoMessageResult> result;
        result.set_value(EchoMessageResult(std::move(GetOperationResult().get())));
        return result.get_future();
    }

    EchoMessageOperation::EchoMessageOperation(
        ClientConnection &connection,
        const EchoMessageOperationContext &operationContext,
        Crt::Allocator *allocator) noexcept
        : ClientOperation(connection, nullptr, operationContext, allocator)
    {
    }

    std::future<RpcError> EchoMessageOperation::Activate(
        const EchoMessageRequest &request,
        OnMessageFlushCallback onMessageFlushCallback) noexcept
    {
        return ClientOperation::Activate(static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
    }

    Crt::String EchoMessageOperation::GetModelName() const noexcept
    {
        return m_operationModelContext.GetOperationName();
    }

    GetAllCustomersOperationContext::GetAllCustomersOperationContext(
        const EchoTestRpcServiceModel &serviceModel) noexcept
        : OperationModelContext(serviceModel)
    {
    }

    Crt::ScopedResource<OperationResponse> GetAllCustomersOperationContext::AllocateInitialResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return GetAllCustomersResponse::s_allocateFromPayload(stringView, allocator);
    }

    Crt::ScopedResource<OperationResponse> GetAllCustomersOperationContext::AllocateStreamingResponseFromPayload(
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        return nullptr;
    }

    Crt::String GetAllCustomersOperationContext::GetRequestModelName() const noexcept
    {
        return Crt::String("awstest#GetAllCustomersRequest");
    }

    Crt::String GetAllCustomersOperationContext::GetInitialResponseModelName() const noexcept
    {
        return Crt::String("awstest#GetAllCustomersResponse");
    }

    Crt::Optional<Crt::String> GetAllCustomersOperationContext::GetStreamingResponseModelName() const noexcept
    {
        return Crt::Optional<Crt::String>();
    }

    Crt::String GetAllCustomersOperationContext::GetOperationName() const noexcept
    {
        return Crt::String("awstest#GetAllCustomers");
    }

    std::future<GetAllCustomersResult> GetAllCustomersOperation::GetResult() noexcept
    {
        std::promise<GetAllCustomersResult> result;
        result.set_value(GetAllCustomersResult(std::move(GetOperationResult().get())));
        return result.get_future();
    }

    GetAllCustomersOperation::GetAllCustomersOperation(
        ClientConnection &connection,
        const GetAllCustomersOperationContext &operationContext,
        Crt::Allocator *allocator) noexcept
        : ClientOperation(connection, nullptr, operationContext, allocator)
    {
    }

    std::future<RpcError> GetAllCustomersOperation::Activate(
        const GetAllCustomersRequest &request,
        OnMessageFlushCallback onMessageFlushCallback) noexcept
    {
        return ClientOperation::Activate(static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
    }

    Crt::String GetAllCustomersOperation::GetModelName() const noexcept
    {
        return m_operationModelContext.GetOperationName();
    }

    EchoTestRpcServiceModel::EchoTestRpcServiceModel() noexcept
        : m_getAllProductsOperationContext(*this), m_causeServiceErrorOperationContext(*this),
          m_causeStreamServiceToErrorOperationContext(*this), m_echoStreamMessagesOperationContext(*this),
          m_echoMessageOperationContext(*this), m_getAllCustomersOperationContext(*this)
    {
    }

    Crt::ScopedResource<OperationError> EchoTestRpcServiceModel::AllocateOperationErrorFromPayload(
        const Crt::String &errorModelName,
        Crt::StringView stringView,
        Crt::Allocator *allocator) const noexcept
    {
        auto it = m_modelNameToErrorResponse.find(errorModelName);
        if (it == m_modelNameToErrorResponse.end())
        {
            return nullptr;
        }
        else
        {
            return it->second(stringView, allocator);
        }
    }

    void EchoTestRpcServiceModel::AssignModelNameToErrorResponse(
        Crt::String modelName,
        ErrorResponseFactory factory) noexcept
    {
        m_modelNameToErrorResponse[modelName] = factory;
    }
} // namespace Awstest
