#include <aws/crt/Api.h>
#include <aws/ipc/GGIpcModel.h>

namespace Aws
{
    namespace Eventstreamrpc
    {
        namespace Ipc
        {
            void LinuxSystemResourceLimits::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_memory.has_value())
                {
                    payloadObject.WithInteger("memory", m_memory.value());
                }
                if (m_cpu.has_value())
                {
                    payloadObject.WithDouble("cpu", m_cpu.value());
                }
            }

            void LinuxSystemResourceLimits::s_loadFromJsonView(
                LinuxSystemResourceLimits &linuxSystemResourceLimits,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("memory"))
                {
                    linuxSystemResourceLimits.m_memory = Crt::Optional<int>(jsonView.GetInteger("memory"));
                }
                if (jsonView.ValueExists("cpu"))
                {
                    linuxSystemResourceLimits.m_cpu = Crt::Optional<double>(jsonView.GetDouble("cpu"));
                }
            }

            Crt::String LinuxSystemResourceLimits::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#LinuxSystemResourceLimits");
            }

            Crt::ScopedResource<AbstractShapeBase> LinuxSystemResourceLimits::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<LinuxSystemResourceLimits> derivedResponse(
                    Crt::New<LinuxSystemResourceLimits>(allocator), LinuxSystemResourceLimits::s_customDeleter);
                LinuxSystemResourceLimits::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void LinuxSystemResourceLimits::s_customDeleter(LinuxSystemResourceLimits *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void SystemResourceLimits::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_linuxSystemResourceLimits.has_value())
                {
                    Crt::JsonObject linuxSystemResourceLimitsValue;
                    m_linuxSystemResourceLimits.value().SerializeToJsonObject(linuxSystemResourceLimitsValue);
                    payloadObject.WithObject("linuxSystemResourceLimits", std::move(linuxSystemResourceLimitsValue));
                }
            }

            void SystemResourceLimits::s_loadFromJsonView(
                SystemResourceLimits &systemResourceLimits,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("linuxSystemResourceLimits"))
                {
                    systemResourceLimits.m_linuxSystemResourceLimits = LinuxSystemResourceLimits();
                    LinuxSystemResourceLimits::s_loadFromJsonView(
                        systemResourceLimits.m_linuxSystemResourceLimits.value(),
                        jsonView.GetJsonObject("linuxSystemResourceLimits"));
                }
            }

            Crt::String SystemResourceLimits::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SystemResourceLimits");
            }

            Crt::ScopedResource<AbstractShapeBase> SystemResourceLimits::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SystemResourceLimits> derivedResponse(
                    Crt::New<SystemResourceLimits>(allocator), SystemResourceLimits::s_customDeleter);
                SystemResourceLimits::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void SystemResourceLimits::s_customDeleter(SystemResourceLimits *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void RunWithInfo::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_posixUser.has_value())
                {
                    payloadObject.WithString("posixUser", m_posixUser.value());
                }
                if (m_systemResourceLimits.has_value())
                {
                    Crt::JsonObject systemResourceLimitsValue;
                    m_systemResourceLimits.value().SerializeToJsonObject(systemResourceLimitsValue);
                    payloadObject.WithObject("systemResourceLimits", std::move(systemResourceLimitsValue));
                }
            }

            void RunWithInfo::s_loadFromJsonView(RunWithInfo &runWithInfo, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("posixUser"))
                {
                    runWithInfo.m_posixUser = Crt::Optional<Crt::String>(jsonView.GetString("posixUser"));
                }
                if (jsonView.ValueExists("systemResourceLimits"))
                {
                    runWithInfo.m_systemResourceLimits = SystemResourceLimits();
                    SystemResourceLimits::s_loadFromJsonView(
                        runWithInfo.m_systemResourceLimits.value(), jsonView.GetJsonObject("systemResourceLimits"));
                }
            }

            Crt::String RunWithInfo::GetModelName() const noexcept { return Crt::String("aws.greengrass#RunWithInfo"); }

            Crt::ScopedResource<AbstractShapeBase> RunWithInfo::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<RunWithInfo> derivedResponse(
                    Crt::New<RunWithInfo>(allocator), RunWithInfo::s_customDeleter);
                RunWithInfo::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void RunWithInfo::s_customDeleter(RunWithInfo *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void PostComponentUpdateEvent::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
            }

            void PostComponentUpdateEvent::s_loadFromJsonView(
                PostComponentUpdateEvent &postComponentUpdateEvent,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("deploymentId"))
                {
                    postComponentUpdateEvent.m_deploymentId =
                        Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
            }

            Crt::String PostComponentUpdateEvent::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PostComponentUpdateEvent");
            }

            Crt::ScopedResource<AbstractShapeBase> PostComponentUpdateEvent::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PostComponentUpdateEvent> derivedResponse(
                    Crt::New<PostComponentUpdateEvent>(allocator), PostComponentUpdateEvent::s_customDeleter);
                PostComponentUpdateEvent::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void PostComponentUpdateEvent::s_customDeleter(PostComponentUpdateEvent *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void PreComponentUpdateEvent::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
                if (m_isGgcRestarting.has_value())
                {
                    payloadObject.WithBool("isGgcRestarting", m_isGgcRestarting.value());
                }
            }

            void PreComponentUpdateEvent::s_loadFromJsonView(
                PreComponentUpdateEvent &preComponentUpdateEvent,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("deploymentId"))
                {
                    preComponentUpdateEvent.m_deploymentId =
                        Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
                if (jsonView.ValueExists("isGgcRestarting"))
                {
                    preComponentUpdateEvent.m_isGgcRestarting =
                        Crt::Optional<bool>(jsonView.GetBool("isGgcRestarting"));
                }
            }

            Crt::String PreComponentUpdateEvent::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PreComponentUpdateEvent");
            }

            Crt::ScopedResource<AbstractShapeBase> PreComponentUpdateEvent::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PreComponentUpdateEvent> derivedResponse(
                    Crt::New<PreComponentUpdateEvent>(allocator), PreComponentUpdateEvent::s_customDeleter);
                PreComponentUpdateEvent::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void PreComponentUpdateEvent::s_customDeleter(PreComponentUpdateEvent *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void BinaryMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    if (m_message.value().size() > 0)
                    {
                        payloadObject.WithString("message", Crt::Base64Encode(m_message.value()));
                    }
                }
            }

            void BinaryMessage::s_loadFromJsonView(BinaryMessage &binaryMessage, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    if (jsonView.GetString("message").size() > 0)
                    {
                        binaryMessage.m_message =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("message")));
                    }
                }
            }

            Crt::String BinaryMessage::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#BinaryMessage");
            }

            Crt::ScopedResource<AbstractShapeBase> BinaryMessage::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<BinaryMessage> derivedResponse(
                    Crt::New<BinaryMessage>(allocator), BinaryMessage::s_customDeleter);
                BinaryMessage::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void BinaryMessage::s_customDeleter(BinaryMessage *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void JsonMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithObject("message", m_message.value());
                }
            }

            void JsonMessage::s_loadFromJsonView(JsonMessage &jsonMessage, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    jsonMessage.m_message =
                        Crt::Optional<Crt::JsonObject>(jsonView.GetJsonObject("message").Materialize());
                }
            }

            Crt::String JsonMessage::GetModelName() const noexcept { return Crt::String("aws.greengrass#JsonMessage"); }

            Crt::ScopedResource<AbstractShapeBase> JsonMessage::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<JsonMessage> derivedResponse(
                    Crt::New<JsonMessage>(allocator), JsonMessage::s_customDeleter);
                JsonMessage::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void JsonMessage::s_customDeleter(JsonMessage *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void ValidateConfigurationUpdateEvent::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_configuration.has_value())
                {
                    payloadObject.WithObject("configuration", m_configuration.value());
                }
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
            }

            void ValidateConfigurationUpdateEvent::s_loadFromJsonView(
                ValidateConfigurationUpdateEvent &validateConfigurationUpdateEvent,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("configuration"))
                {
                    validateConfigurationUpdateEvent.m_configuration =
                        Crt::Optional<Crt::JsonObject>(jsonView.GetJsonObject("configuration").Materialize());
                }
                if (jsonView.ValueExists("deploymentId"))
                {
                    validateConfigurationUpdateEvent.m_deploymentId =
                        Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
            }

            Crt::String ValidateConfigurationUpdateEvent::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateConfigurationUpdateEvent");
            }

            Crt::ScopedResource<AbstractShapeBase> ValidateConfigurationUpdateEvent::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ValidateConfigurationUpdateEvent> derivedResponse(
                    Crt::New<ValidateConfigurationUpdateEvent>(allocator),
                    ValidateConfigurationUpdateEvent::s_customDeleter);
                ValidateConfigurationUpdateEvent::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void ValidateConfigurationUpdateEvent::s_customDeleter(ValidateConfigurationUpdateEvent *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void ConfigurationUpdateEvent::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
                if (m_keyPath.has_value())
                {
                    Crt::JsonObject keyPath;
                    Crt::Vector<Crt::JsonObject> keyPathJsonArray;
                    for (const auto &keyPathItem : m_keyPath.value())
                    {
                        Crt::JsonObject keyPathJsonArrayItem;
                        keyPathJsonArrayItem.AsString(keyPathItem);
                        keyPathJsonArray.emplace_back(std::move(keyPathJsonArrayItem));
                    }
                    keyPath.AsArray(std::move(keyPathJsonArray));
                    payloadObject.WithObject("keyPath", std::move(keyPath));
                }
            }

            void ConfigurationUpdateEvent::s_loadFromJsonView(
                ConfigurationUpdateEvent &configurationUpdateEvent,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    configurationUpdateEvent.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
                if (jsonView.ValueExists("keyPath"))
                {
                    configurationUpdateEvent.m_keyPath = Crt::Vector<Crt::String>();
                    for (const Crt::JsonView &keyPathJsonView : jsonView.GetArray("keyPath"))
                    {
                        Crt::Optional<Crt::String> keyPathItem;
                        keyPathItem = Crt::Optional<Crt::String>(keyPathJsonView.AsString());
                        configurationUpdateEvent.m_keyPath.value().push_back(keyPathItem.value());
                    }
                }
            }

            Crt::String ConfigurationUpdateEvent::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ConfigurationUpdateEvent");
            }

            Crt::ScopedResource<AbstractShapeBase> ConfigurationUpdateEvent::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ConfigurationUpdateEvent> derivedResponse(
                    Crt::New<ConfigurationUpdateEvent>(allocator), ConfigurationUpdateEvent::s_customDeleter);
                ConfigurationUpdateEvent::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void ConfigurationUpdateEvent::s_customDeleter(ConfigurationUpdateEvent *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void MQTTMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_topicName.has_value())
                {
                    payloadObject.WithString("topicName", m_topicName.value());
                }
                if (m_payload.has_value())
                {
                    if (m_payload.value().size() > 0)
                    {
                        payloadObject.WithString("payload", Crt::Base64Encode(m_payload.value()));
                    }
                }
            }

            void MQTTMessage::s_loadFromJsonView(MQTTMessage &mQTTMessage, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("topicName"))
                {
                    mQTTMessage.m_topicName = Crt::Optional<Crt::String>(jsonView.GetString("topicName"));
                }
                if (jsonView.ValueExists("payload"))
                {
                    if (jsonView.GetString("payload").size() > 0)
                    {
                        mQTTMessage.m_payload =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("payload")));
                    }
                }
            }

            Crt::String MQTTMessage::GetModelName() const noexcept { return Crt::String("aws.greengrass#MQTTMessage"); }

            Crt::ScopedResource<AbstractShapeBase> MQTTMessage::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<MQTTMessage> derivedResponse(
                    Crt::New<MQTTMessage>(allocator), MQTTMessage::s_customDeleter);
                MQTTMessage::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void MQTTMessage::s_customDeleter(MQTTMessage *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void ComponentUpdatePolicyEvents::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_chosenMember == TAG_PRE_UPDATE_EVENT && m_preUpdateEvent.has_value())
                {
                    Crt::JsonObject preComponentUpdateEventValue;
                    m_preUpdateEvent.value().SerializeToJsonObject(preComponentUpdateEventValue);
                    payloadObject.WithObject("preUpdateEvent", std::move(preComponentUpdateEventValue));
                }
                else if (m_chosenMember == TAG_POST_UPDATE_EVENT && m_postUpdateEvent.has_value())
                {
                    Crt::JsonObject postComponentUpdateEventValue;
                    m_postUpdateEvent.value().SerializeToJsonObject(postComponentUpdateEventValue);
                    payloadObject.WithObject("postUpdateEvent", std::move(postComponentUpdateEventValue));
                }
            }

            void ComponentUpdatePolicyEvents::s_loadFromJsonView(
                ComponentUpdatePolicyEvents &componentUpdatePolicyEvents,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("preUpdateEvent"))
                {
                    componentUpdatePolicyEvents.m_preUpdateEvent = PreComponentUpdateEvent();
                    PreComponentUpdateEvent::s_loadFromJsonView(
                        componentUpdatePolicyEvents.m_preUpdateEvent.value(), jsonView.GetJsonObject("preUpdateEvent"));
                    componentUpdatePolicyEvents.m_chosenMember = TAG_PRE_UPDATE_EVENT;
                }
                else if (jsonView.ValueExists("postUpdateEvent"))
                {
                    componentUpdatePolicyEvents.m_postUpdateEvent = PostComponentUpdateEvent();
                    PostComponentUpdateEvent::s_loadFromJsonView(
                        componentUpdatePolicyEvents.m_postUpdateEvent.value(),
                        jsonView.GetJsonObject("postUpdateEvent"));
                    componentUpdatePolicyEvents.m_chosenMember = TAG_POST_UPDATE_EVENT;
                }
            }

            ComponentUpdatePolicyEvents &ComponentUpdatePolicyEvents::operator=(
                const ComponentUpdatePolicyEvents &objectToCopy) noexcept
            {
                if (objectToCopy.m_chosenMember == TAG_PRE_UPDATE_EVENT)
                {
                    m_preUpdateEvent = objectToCopy.m_preUpdateEvent;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                else if (objectToCopy.m_chosenMember == TAG_POST_UPDATE_EVENT)
                {
                    m_postUpdateEvent = objectToCopy.m_postUpdateEvent;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                return *this;
            }

            Crt::String ComponentUpdatePolicyEvents::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ComponentUpdatePolicyEvents");
            }

            Crt::ScopedResource<OperationResponse> ComponentUpdatePolicyEvents::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ComponentUpdatePolicyEvents> derivedResponse(
                    Crt::New<ComponentUpdatePolicyEvents>(allocator), ComponentUpdatePolicyEvents::s_customDeleter);
                ComponentUpdatePolicyEvents::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ComponentUpdatePolicyEvents::s_customDeleter(ComponentUpdatePolicyEvents *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void SecretValue::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_chosenMember == TAG_SECRET_STRING && m_secretString.has_value())
                {
                    payloadObject.WithString("secretString", m_secretString.value());
                }
                else if (m_chosenMember == TAG_SECRET_BINARY && m_secretBinary.has_value())
                {
                    if (m_secretBinary.value().size() > 0)
                    {
                        payloadObject.WithString("secretBinary", Crt::Base64Encode(m_secretBinary.value()));
                    }
                }
            }

            void SecretValue::s_loadFromJsonView(SecretValue &secretValue, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("secretString"))
                {
                    secretValue.m_secretString = Crt::Optional<Crt::String>(jsonView.GetString("secretString"));
                    secretValue.m_chosenMember = TAG_SECRET_STRING;
                }
                else if (jsonView.ValueExists("secretBinary"))
                {
                    if (jsonView.GetString("secretBinary").size() > 0)
                    {
                        secretValue.m_secretBinary =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("secretBinary")));
                    }
                    secretValue.m_chosenMember = TAG_SECRET_BINARY;
                }
            }

            SecretValue &SecretValue::operator=(const SecretValue &objectToCopy) noexcept
            {
                if (objectToCopy.m_chosenMember == TAG_SECRET_STRING)
                {
                    m_secretString = objectToCopy.m_secretString;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                else if (objectToCopy.m_chosenMember == TAG_SECRET_BINARY)
                {
                    m_secretBinary = objectToCopy.m_secretBinary;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                return *this;
            }

            Crt::String SecretValue::GetModelName() const noexcept { return Crt::String("aws.greengrass#SecretValue"); }

            Crt::ScopedResource<AbstractShapeBase> SecretValue::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SecretValue> derivedResponse(
                    Crt::New<SecretValue>(allocator), SecretValue::s_customDeleter);
                SecretValue::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void SecretValue::s_customDeleter(SecretValue *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void LocalDeployment::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
                if (m_status.has_value())
                {
                    payloadObject.WithString("status", m_status.value());
                }
            }

            void LocalDeployment::s_loadFromJsonView(
                LocalDeployment &localDeployment,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("deploymentId"))
                {
                    localDeployment.m_deploymentId = Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
                if (jsonView.ValueExists("status"))
                {
                    localDeployment.m_status = Crt::Optional<Crt::String>(jsonView.GetString("status"));
                }
            }

            void LocalDeployment::SetStatus(Crt::Optional<DeploymentStatus> status) noexcept
            {
                switch (status.value())
                {
                    case DEPLOYMENT_STATUS_QUEUED:
                        m_status = Crt::String("QUEUED");
                        break;
                    case DEPLOYMENT_STATUS_IN_PROGRESS:
                        m_status = Crt::String("IN_PROGRESS");
                        break;
                    case DEPLOYMENT_STATUS_SUCCEEDED:
                        m_status = Crt::String("SUCCEEDED");
                        break;
                    case DEPLOYMENT_STATUS_FAILED:
                        m_status = Crt::String("FAILED");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<DeploymentStatus> LocalDeployment::GetStatus() noexcept
            {
                if (!m_status.has_value())
                    return Crt::Optional<DeploymentStatus>();
                if (m_status.value() == Crt::String("QUEUED"))
                {
                    return Crt::Optional<DeploymentStatus>(DEPLOYMENT_STATUS_QUEUED);
                }
                if (m_status.value() == Crt::String("IN_PROGRESS"))
                {
                    return Crt::Optional<DeploymentStatus>(DEPLOYMENT_STATUS_IN_PROGRESS);
                }
                if (m_status.value() == Crt::String("SUCCEEDED"))
                {
                    return Crt::Optional<DeploymentStatus>(DEPLOYMENT_STATUS_SUCCEEDED);
                }
                if (m_status.value() == Crt::String("FAILED"))
                {
                    return Crt::Optional<DeploymentStatus>(DEPLOYMENT_STATUS_FAILED);
                }

                return Crt::Optional<DeploymentStatus>();
            }

            Crt::String LocalDeployment::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#LocalDeployment");
            }

            Crt::ScopedResource<AbstractShapeBase> LocalDeployment::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<LocalDeployment> derivedResponse(
                    Crt::New<LocalDeployment>(allocator), LocalDeployment::s_customDeleter);
                LocalDeployment::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void LocalDeployment::s_customDeleter(LocalDeployment *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void ConfigurationValidityReport::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_status.has_value())
                {
                    payloadObject.WithString("status", m_status.value());
                }
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void ConfigurationValidityReport::s_loadFromJsonView(
                ConfigurationValidityReport &configurationValidityReport,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("status"))
                {
                    configurationValidityReport.m_status = Crt::Optional<Crt::String>(jsonView.GetString("status"));
                }
                if (jsonView.ValueExists("deploymentId"))
                {
                    configurationValidityReport.m_deploymentId =
                        Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
                if (jsonView.ValueExists("message"))
                {
                    configurationValidityReport.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            void ConfigurationValidityReport::SetStatus(Crt::Optional<ConfigurationValidityStatus> status) noexcept
            {
                switch (status.value())
                {
                    case CONFIGURATION_VALIDITY_STATUS_ACCEPTED:
                        m_status = Crt::String("ACCEPTED");
                        break;
                    case CONFIGURATION_VALIDITY_STATUS_REJECTED:
                        m_status = Crt::String("REJECTED");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<ConfigurationValidityStatus> ConfigurationValidityReport::GetStatus() noexcept
            {
                if (!m_status.has_value())
                    return Crt::Optional<ConfigurationValidityStatus>();
                if (m_status.value() == Crt::String("ACCEPTED"))
                {
                    return Crt::Optional<ConfigurationValidityStatus>(CONFIGURATION_VALIDITY_STATUS_ACCEPTED);
                }
                if (m_status.value() == Crt::String("REJECTED"))
                {
                    return Crt::Optional<ConfigurationValidityStatus>(CONFIGURATION_VALIDITY_STATUS_REJECTED);
                }

                return Crt::Optional<ConfigurationValidityStatus>();
            }

            Crt::String ConfigurationValidityReport::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ConfigurationValidityReport");
            }

            Crt::ScopedResource<AbstractShapeBase> ConfigurationValidityReport::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ConfigurationValidityReport> derivedResponse(
                    Crt::New<ConfigurationValidityReport>(allocator), ConfigurationValidityReport::s_customDeleter);
                ConfigurationValidityReport::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void ConfigurationValidityReport::s_customDeleter(ConfigurationValidityReport *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void PublishMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_chosenMember == TAG_JSON_MESSAGE && m_jsonMessage.has_value())
                {
                    Crt::JsonObject jsonMessageValue;
                    m_jsonMessage.value().SerializeToJsonObject(jsonMessageValue);
                    payloadObject.WithObject("jsonMessage", std::move(jsonMessageValue));
                }
                else if (m_chosenMember == TAG_BINARY_MESSAGE && m_binaryMessage.has_value())
                {
                    Crt::JsonObject binaryMessageValue;
                    m_binaryMessage.value().SerializeToJsonObject(binaryMessageValue);
                    payloadObject.WithObject("binaryMessage", std::move(binaryMessageValue));
                }
            }

            void PublishMessage::s_loadFromJsonView(
                PublishMessage &publishMessage,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("jsonMessage"))
                {
                    publishMessage.m_jsonMessage = JsonMessage();
                    JsonMessage::s_loadFromJsonView(
                        publishMessage.m_jsonMessage.value(), jsonView.GetJsonObject("jsonMessage"));
                    publishMessage.m_chosenMember = TAG_JSON_MESSAGE;
                }
                else if (jsonView.ValueExists("binaryMessage"))
                {
                    publishMessage.m_binaryMessage = BinaryMessage();
                    BinaryMessage::s_loadFromJsonView(
                        publishMessage.m_binaryMessage.value(), jsonView.GetJsonObject("binaryMessage"));
                    publishMessage.m_chosenMember = TAG_BINARY_MESSAGE;
                }
            }

            PublishMessage &PublishMessage::operator=(const PublishMessage &objectToCopy) noexcept
            {
                if (objectToCopy.m_chosenMember == TAG_JSON_MESSAGE)
                {
                    m_jsonMessage = objectToCopy.m_jsonMessage;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                else if (objectToCopy.m_chosenMember == TAG_BINARY_MESSAGE)
                {
                    m_binaryMessage = objectToCopy.m_binaryMessage;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                return *this;
            }

            Crt::String PublishMessage::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishMessage");
            }

            Crt::ScopedResource<AbstractShapeBase> PublishMessage::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PublishMessage> derivedResponse(
                    Crt::New<PublishMessage>(allocator), PublishMessage::s_customDeleter);
                PublishMessage::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void PublishMessage::s_customDeleter(PublishMessage *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void ComponentDetails::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
                if (m_version.has_value())
                {
                    payloadObject.WithString("version", m_version.value());
                }
                if (m_state.has_value())
                {
                    payloadObject.WithString("state", m_state.value());
                }
                if (m_configuration.has_value())
                {
                    payloadObject.WithObject("configuration", m_configuration.value());
                }
            }

            void ComponentDetails::s_loadFromJsonView(
                ComponentDetails &componentDetails,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    componentDetails.m_componentName = Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
                if (jsonView.ValueExists("version"))
                {
                    componentDetails.m_version = Crt::Optional<Crt::String>(jsonView.GetString("version"));
                }
                if (jsonView.ValueExists("state"))
                {
                    componentDetails.m_state = Crt::Optional<Crt::String>(jsonView.GetString("state"));
                }
                if (jsonView.ValueExists("configuration"))
                {
                    componentDetails.m_configuration =
                        Crt::Optional<Crt::JsonObject>(jsonView.GetJsonObject("configuration").Materialize());
                }
            }

            void ComponentDetails::SetState(Crt::Optional<LifecycleState> state) noexcept
            {
                switch (state.value())
                {
                    case LIFECYCLE_STATE_RUNNING:
                        m_state = Crt::String("RUNNING");
                        break;
                    case LIFECYCLE_STATE_ERRORED:
                        m_state = Crt::String("ERRORED");
                        break;
                    case LIFECYCLE_STATE_NEW:
                        m_state = Crt::String("NEW");
                        break;
                    case LIFECYCLE_STATE_FINISHED:
                        m_state = Crt::String("FINISHED");
                        break;
                    case LIFECYCLE_STATE_INSTALLED:
                        m_state = Crt::String("INSTALLED");
                        break;
                    case LIFECYCLE_STATE_BROKEN:
                        m_state = Crt::String("BROKEN");
                        break;
                    case LIFECYCLE_STATE_STARTING:
                        m_state = Crt::String("STARTING");
                        break;
                    case LIFECYCLE_STATE_STOPPING:
                        m_state = Crt::String("STOPPING");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<LifecycleState> ComponentDetails::GetState() noexcept
            {
                if (!m_state.has_value())
                    return Crt::Optional<LifecycleState>();
                if (m_state.value() == Crt::String("RUNNING"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_RUNNING);
                }
                if (m_state.value() == Crt::String("ERRORED"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_ERRORED);
                }
                if (m_state.value() == Crt::String("NEW"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_NEW);
                }
                if (m_state.value() == Crt::String("FINISHED"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_FINISHED);
                }
                if (m_state.value() == Crt::String("INSTALLED"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_INSTALLED);
                }
                if (m_state.value() == Crt::String("BROKEN"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_BROKEN);
                }
                if (m_state.value() == Crt::String("STARTING"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_STARTING);
                }
                if (m_state.value() == Crt::String("STOPPING"))
                {
                    return Crt::Optional<LifecycleState>(LIFECYCLE_STATE_STOPPING);
                }

                return Crt::Optional<LifecycleState>();
            }

            Crt::String ComponentDetails::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ComponentDetails");
            }

            Crt::ScopedResource<AbstractShapeBase> ComponentDetails::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ComponentDetails> derivedResponse(
                    Crt::New<ComponentDetails>(allocator), ComponentDetails::s_customDeleter);
                ComponentDetails::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<AbstractShapeBase *>(derivedResponse.release());
                return Crt::ScopedResource<AbstractShapeBase>(operationResponse, AbstractShapeBase::s_customDeleter);
            }

            void ComponentDetails::s_customDeleter(ComponentDetails *shape) noexcept
            {
                AbstractShapeBase::s_customDeleter(static_cast<AbstractShapeBase *>(shape));
            }

            void SubscriptionResponseMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_chosenMember == TAG_JSON_MESSAGE && m_jsonMessage.has_value())
                {
                    Crt::JsonObject jsonMessageValue;
                    m_jsonMessage.value().SerializeToJsonObject(jsonMessageValue);
                    payloadObject.WithObject("jsonMessage", std::move(jsonMessageValue));
                }
                else if (m_chosenMember == TAG_BINARY_MESSAGE && m_binaryMessage.has_value())
                {
                    Crt::JsonObject binaryMessageValue;
                    m_binaryMessage.value().SerializeToJsonObject(binaryMessageValue);
                    payloadObject.WithObject("binaryMessage", std::move(binaryMessageValue));
                }
            }

            void SubscriptionResponseMessage::s_loadFromJsonView(
                SubscriptionResponseMessage &subscriptionResponseMessage,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("jsonMessage"))
                {
                    subscriptionResponseMessage.m_jsonMessage = JsonMessage();
                    JsonMessage::s_loadFromJsonView(
                        subscriptionResponseMessage.m_jsonMessage.value(), jsonView.GetJsonObject("jsonMessage"));
                    subscriptionResponseMessage.m_chosenMember = TAG_JSON_MESSAGE;
                }
                else if (jsonView.ValueExists("binaryMessage"))
                {
                    subscriptionResponseMessage.m_binaryMessage = BinaryMessage();
                    BinaryMessage::s_loadFromJsonView(
                        subscriptionResponseMessage.m_binaryMessage.value(), jsonView.GetJsonObject("binaryMessage"));
                    subscriptionResponseMessage.m_chosenMember = TAG_BINARY_MESSAGE;
                }
            }

            SubscriptionResponseMessage &SubscriptionResponseMessage::operator=(
                const SubscriptionResponseMessage &objectToCopy) noexcept
            {
                if (objectToCopy.m_chosenMember == TAG_JSON_MESSAGE)
                {
                    m_jsonMessage = objectToCopy.m_jsonMessage;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                else if (objectToCopy.m_chosenMember == TAG_BINARY_MESSAGE)
                {
                    m_binaryMessage = objectToCopy.m_binaryMessage;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                return *this;
            }

            Crt::String SubscriptionResponseMessage::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscriptionResponseMessage");
            }

            Crt::ScopedResource<OperationResponse> SubscriptionResponseMessage::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscriptionResponseMessage> derivedResponse(
                    Crt::New<SubscriptionResponseMessage>(allocator), SubscriptionResponseMessage::s_customDeleter);
                SubscriptionResponseMessage::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void SubscriptionResponseMessage::s_customDeleter(SubscriptionResponseMessage *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void ValidateConfigurationUpdateEvents::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_chosenMember == TAG_VALIDATE_CONFIGURATION_UPDATE_EVENT &&
                    m_validateConfigurationUpdateEvent.has_value())
                {
                    Crt::JsonObject validateConfigurationUpdateEventValue;
                    m_validateConfigurationUpdateEvent.value().SerializeToJsonObject(
                        validateConfigurationUpdateEventValue);
                    payloadObject.WithObject(
                        "validateConfigurationUpdateEvent", std::move(validateConfigurationUpdateEventValue));
                }
            }

            void ValidateConfigurationUpdateEvents::s_loadFromJsonView(
                ValidateConfigurationUpdateEvents &validateConfigurationUpdateEvents,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("validateConfigurationUpdateEvent"))
                {
                    validateConfigurationUpdateEvents.m_validateConfigurationUpdateEvent =
                        ValidateConfigurationUpdateEvent();
                    ValidateConfigurationUpdateEvent::s_loadFromJsonView(
                        validateConfigurationUpdateEvents.m_validateConfigurationUpdateEvent.value(),
                        jsonView.GetJsonObject("validateConfigurationUpdateEvent"));
                    validateConfigurationUpdateEvents.m_chosenMember = TAG_VALIDATE_CONFIGURATION_UPDATE_EVENT;
                }
            }

            ValidateConfigurationUpdateEvents &ValidateConfigurationUpdateEvents::operator=(
                const ValidateConfigurationUpdateEvents &objectToCopy) noexcept
            {
                if (objectToCopy.m_chosenMember == TAG_VALIDATE_CONFIGURATION_UPDATE_EVENT)
                {
                    m_validateConfigurationUpdateEvent = objectToCopy.m_validateConfigurationUpdateEvent;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                return *this;
            }

            Crt::String ValidateConfigurationUpdateEvents::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateConfigurationUpdateEvents");
            }

            Crt::ScopedResource<OperationResponse> ValidateConfigurationUpdateEvents::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ValidateConfigurationUpdateEvents> derivedResponse(
                    Crt::New<ValidateConfigurationUpdateEvents>(allocator),
                    ValidateConfigurationUpdateEvents::s_customDeleter);
                ValidateConfigurationUpdateEvents::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ValidateConfigurationUpdateEvents::s_customDeleter(ValidateConfigurationUpdateEvents *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void ConfigurationUpdateEvents::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_chosenMember == TAG_CONFIGURATION_UPDATE_EVENT && m_configurationUpdateEvent.has_value())
                {
                    Crt::JsonObject configurationUpdateEventValue;
                    m_configurationUpdateEvent.value().SerializeToJsonObject(configurationUpdateEventValue);
                    payloadObject.WithObject("configurationUpdateEvent", std::move(configurationUpdateEventValue));
                }
            }

            void ConfigurationUpdateEvents::s_loadFromJsonView(
                ConfigurationUpdateEvents &configurationUpdateEvents,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("configurationUpdateEvent"))
                {
                    configurationUpdateEvents.m_configurationUpdateEvent = ConfigurationUpdateEvent();
                    ConfigurationUpdateEvent::s_loadFromJsonView(
                        configurationUpdateEvents.m_configurationUpdateEvent.value(),
                        jsonView.GetJsonObject("configurationUpdateEvent"));
                    configurationUpdateEvents.m_chosenMember = TAG_CONFIGURATION_UPDATE_EVENT;
                }
            }

            ConfigurationUpdateEvents &ConfigurationUpdateEvents::operator=(
                const ConfigurationUpdateEvents &objectToCopy) noexcept
            {
                if (objectToCopy.m_chosenMember == TAG_CONFIGURATION_UPDATE_EVENT)
                {
                    m_configurationUpdateEvent = objectToCopy.m_configurationUpdateEvent;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                return *this;
            }

            Crt::String ConfigurationUpdateEvents::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ConfigurationUpdateEvents");
            }

            Crt::ScopedResource<OperationResponse> ConfigurationUpdateEvents::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ConfigurationUpdateEvents> derivedResponse(
                    Crt::New<ConfigurationUpdateEvents>(allocator), ConfigurationUpdateEvents::s_customDeleter);
                ConfigurationUpdateEvents::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ConfigurationUpdateEvents::s_customDeleter(ConfigurationUpdateEvents *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void IoTCoreMessage::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_chosenMember == TAG_MESSAGE && m_message.has_value())
                {
                    Crt::JsonObject mQTTMessageValue;
                    m_message.value().SerializeToJsonObject(mQTTMessageValue);
                    payloadObject.WithObject("message", std::move(mQTTMessageValue));
                }
            }

            void IoTCoreMessage::s_loadFromJsonView(
                IoTCoreMessage &ioTCoreMessage,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    ioTCoreMessage.m_message = MQTTMessage();
                    MQTTMessage::s_loadFromJsonView(
                        ioTCoreMessage.m_message.value(), jsonView.GetJsonObject("message"));
                    ioTCoreMessage.m_chosenMember = TAG_MESSAGE;
                }
            }

            IoTCoreMessage &IoTCoreMessage::operator=(const IoTCoreMessage &objectToCopy) noexcept
            {
                if (objectToCopy.m_chosenMember == TAG_MESSAGE)
                {
                    m_message = objectToCopy.m_message;
                    m_chosenMember = objectToCopy.m_chosenMember;
                }
                return *this;
            }

            Crt::String IoTCoreMessage::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#IoTCoreMessage");
            }

            Crt::ScopedResource<OperationResponse> IoTCoreMessage::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<IoTCoreMessage> derivedResponse(
                    Crt::New<IoTCoreMessage>(allocator), IoTCoreMessage::s_customDeleter);
                IoTCoreMessage::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void IoTCoreMessage::s_customDeleter(IoTCoreMessage *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void InvalidArtifactsDirectoryPathError::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void InvalidArtifactsDirectoryPathError::s_loadFromJsonView(
                InvalidArtifactsDirectoryPathError &invalidArtifactsDirectoryPathError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    invalidArtifactsDirectoryPathError.m_message =
                        Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String InvalidArtifactsDirectoryPathError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#InvalidArtifactsDirectoryPathError");
            }

            Crt::ScopedResource<OperationError> InvalidArtifactsDirectoryPathError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<InvalidArtifactsDirectoryPathError> derivedResponse(
                    Crt::New<InvalidArtifactsDirectoryPathError>(allocator),
                    InvalidArtifactsDirectoryPathError::s_customDeleter);
                InvalidArtifactsDirectoryPathError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void InvalidArtifactsDirectoryPathError::s_customDeleter(InvalidArtifactsDirectoryPathError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void InvalidRecipeDirectoryPathError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void InvalidRecipeDirectoryPathError::s_loadFromJsonView(
                InvalidRecipeDirectoryPathError &invalidRecipeDirectoryPathError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    invalidRecipeDirectoryPathError.m_message =
                        Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String InvalidRecipeDirectoryPathError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#InvalidRecipeDirectoryPathError");
            }

            Crt::ScopedResource<OperationError> InvalidRecipeDirectoryPathError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<InvalidRecipeDirectoryPathError> derivedResponse(
                    Crt::New<InvalidRecipeDirectoryPathError>(allocator),
                    InvalidRecipeDirectoryPathError::s_customDeleter);
                InvalidRecipeDirectoryPathError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void InvalidRecipeDirectoryPathError::s_customDeleter(InvalidRecipeDirectoryPathError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void CreateLocalDeploymentResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
            }

            void CreateLocalDeploymentResponse::s_loadFromJsonView(
                CreateLocalDeploymentResponse &createLocalDeploymentResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("deploymentId"))
                {
                    createLocalDeploymentResponse.m_deploymentId =
                        Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
            }

            Crt::String CreateLocalDeploymentResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateLocalDeploymentResponse");
            }

            Crt::ScopedResource<OperationResponse> CreateLocalDeploymentResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<CreateLocalDeploymentResponse> derivedResponse(
                    Crt::New<CreateLocalDeploymentResponse>(allocator), CreateLocalDeploymentResponse::s_customDeleter);
                CreateLocalDeploymentResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void CreateLocalDeploymentResponse::s_customDeleter(CreateLocalDeploymentResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void CreateLocalDeploymentRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_groupName.has_value())
                {
                    payloadObject.WithString("groupName", m_groupName.value());
                }
                if (m_rootComponentVersionsToAdd.has_value())
                {
                    Crt::JsonObject componentToVersionMapValue;
                    for (const auto &componentToVersionMapItem : m_rootComponentVersionsToAdd.value())
                    {
                        Crt::JsonObject componentToVersionMapJsonObject;
                        componentToVersionMapJsonObject.AsString(componentToVersionMapItem.second);
                        componentToVersionMapValue.WithObject(
                            componentToVersionMapItem.first, std::move(componentToVersionMapJsonObject));
                    }
                    payloadObject.WithObject("rootComponentVersionsToAdd", std::move(componentToVersionMapValue));
                }
                if (m_rootComponentsToRemove.has_value())
                {
                    Crt::JsonObject componentList;
                    Crt::Vector<Crt::JsonObject> componentListJsonArray;
                    for (const auto &componentListItem : m_rootComponentsToRemove.value())
                    {
                        Crt::JsonObject componentListJsonArrayItem;
                        componentListJsonArrayItem.AsString(componentListItem);
                        componentListJsonArray.emplace_back(std::move(componentListJsonArrayItem));
                    }
                    componentList.AsArray(std::move(componentListJsonArray));
                    payloadObject.WithObject("rootComponentsToRemove", std::move(componentList));
                }
                if (m_componentToConfiguration.has_value())
                {
                    Crt::JsonObject componentToConfigurationValue;
                    for (const auto &componentToConfigurationItem : m_componentToConfiguration.value())
                    {
                        Crt::JsonObject componentToConfigurationJsonObject;
                        componentToConfigurationJsonObject.AsObject(componentToConfigurationItem.second);
                        componentToConfigurationValue.WithObject(
                            componentToConfigurationItem.first, std::move(componentToConfigurationJsonObject));
                    }
                    payloadObject.WithObject("componentToConfiguration", std::move(componentToConfigurationValue));
                }
                if (m_componentToRunWithInfo.has_value())
                {
                    Crt::JsonObject componentToRunWithInfoValue;
                    for (const auto &componentToRunWithInfoItem : m_componentToRunWithInfo.value())
                    {
                        Crt::JsonObject componentToRunWithInfoJsonObject;
                        componentToRunWithInfoItem.second.SerializeToJsonObject(componentToRunWithInfoJsonObject);
                        componentToRunWithInfoValue.WithObject(
                            componentToRunWithInfoItem.first, std::move(componentToRunWithInfoJsonObject));
                    }
                    payloadObject.WithObject("componentToRunWithInfo", std::move(componentToRunWithInfoValue));
                }
                if (m_recipeDirectoryPath.has_value())
                {
                    payloadObject.WithString("recipeDirectoryPath", m_recipeDirectoryPath.value());
                }
                if (m_artifactsDirectoryPath.has_value())
                {
                    payloadObject.WithString("artifactsDirectoryPath", m_artifactsDirectoryPath.value());
                }
            }

            void CreateLocalDeploymentRequest::s_loadFromJsonView(
                CreateLocalDeploymentRequest &createLocalDeploymentRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("groupName"))
                {
                    createLocalDeploymentRequest.m_groupName =
                        Crt::Optional<Crt::String>(jsonView.GetString("groupName"));
                }
                if (jsonView.ValueExists("rootComponentVersionsToAdd"))
                {
                    createLocalDeploymentRequest.m_rootComponentVersionsToAdd = Crt::Map<Crt::String, Crt::String>();
                    for (const auto &componentToVersionMapPair :
                         jsonView.GetJsonObject("rootComponentVersionsToAdd").GetAllObjects())
                    {
                        Crt::Optional<Crt::String> componentToVersionMapValue;
                        componentToVersionMapValue =
                            Crt::Optional<Crt::String>(componentToVersionMapPair.second.AsString());
                        createLocalDeploymentRequest.m_rootComponentVersionsToAdd
                            .value()[componentToVersionMapPair.first] = componentToVersionMapValue.value();
                    }
                }
                if (jsonView.ValueExists("rootComponentsToRemove"))
                {
                    createLocalDeploymentRequest.m_rootComponentsToRemove = Crt::Vector<Crt::String>();
                    for (const Crt::JsonView &componentListJsonView : jsonView.GetArray("rootComponentsToRemove"))
                    {
                        Crt::Optional<Crt::String> componentListItem;
                        componentListItem = Crt::Optional<Crt::String>(componentListJsonView.AsString());
                        createLocalDeploymentRequest.m_rootComponentsToRemove.value().push_back(
                            componentListItem.value());
                    }
                }
                if (jsonView.ValueExists("componentToConfiguration"))
                {
                    createLocalDeploymentRequest.m_componentToConfiguration = Crt::Map<Crt::String, Crt::JsonObject>();
                    for (const auto &componentToConfigurationPair :
                         jsonView.GetJsonObject("componentToConfiguration").GetAllObjects())
                    {
                        Crt::Optional<Crt::JsonObject> componentToConfigurationValue;
                        componentToConfigurationValue = Crt::Optional<Crt::JsonObject>(
                            componentToConfigurationPair.second.AsObject().Materialize());
                        createLocalDeploymentRequest.m_componentToConfiguration
                            .value()[componentToConfigurationPair.first] = componentToConfigurationValue.value();
                    }
                }
                if (jsonView.ValueExists("componentToRunWithInfo"))
                {
                    createLocalDeploymentRequest.m_componentToRunWithInfo = Crt::Map<Crt::String, RunWithInfo>();
                    for (const auto &componentToRunWithInfoPair :
                         jsonView.GetJsonObject("componentToRunWithInfo").GetAllObjects())
                    {
                        Crt::Optional<RunWithInfo> componentToRunWithInfoValue;
                        componentToRunWithInfoValue = RunWithInfo();
                        RunWithInfo::s_loadFromJsonView(
                            componentToRunWithInfoValue.value(), componentToRunWithInfoPair.second);
                        createLocalDeploymentRequest.m_componentToRunWithInfo
                            .value()[componentToRunWithInfoPair.first] = componentToRunWithInfoValue.value();
                    }
                }
                if (jsonView.ValueExists("recipeDirectoryPath"))
                {
                    createLocalDeploymentRequest.m_recipeDirectoryPath =
                        Crt::Optional<Crt::String>(jsonView.GetString("recipeDirectoryPath"));
                }
                if (jsonView.ValueExists("artifactsDirectoryPath"))
                {
                    createLocalDeploymentRequest.m_artifactsDirectoryPath =
                        Crt::Optional<Crt::String>(jsonView.GetString("artifactsDirectoryPath"));
                }
            }

            Crt::String CreateLocalDeploymentRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateLocalDeploymentRequest");
            }

            Crt::ScopedResource<OperationRequest> CreateLocalDeploymentRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<CreateLocalDeploymentRequest> derivedResponse(
                    Crt::New<CreateLocalDeploymentRequest>(allocator), CreateLocalDeploymentRequest::s_customDeleter);
                CreateLocalDeploymentRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void CreateLocalDeploymentRequest::s_customDeleter(CreateLocalDeploymentRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void PauseComponentResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void PauseComponentResponse::s_loadFromJsonView(
                PauseComponentResponse &pauseComponentResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)pauseComponentResponse;
                (void)jsonView;
            }

            Crt::String PauseComponentResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PauseComponentResponse");
            }

            Crt::ScopedResource<OperationResponse> PauseComponentResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PauseComponentResponse> derivedResponse(
                    Crt::New<PauseComponentResponse>(allocator), PauseComponentResponse::s_customDeleter);
                PauseComponentResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void PauseComponentResponse::s_customDeleter(PauseComponentResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void PauseComponentRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
            }

            void PauseComponentRequest::s_loadFromJsonView(
                PauseComponentRequest &pauseComponentRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    pauseComponentRequest.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
            }

            Crt::String PauseComponentRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PauseComponentRequest");
            }

            Crt::ScopedResource<OperationRequest> PauseComponentRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PauseComponentRequest> derivedResponse(
                    Crt::New<PauseComponentRequest>(allocator), PauseComponentRequest::s_customDeleter);
                PauseComponentRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void PauseComponentRequest::s_customDeleter(PauseComponentRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void StopComponentResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_stopStatus.has_value())
                {
                    payloadObject.WithString("stopStatus", m_stopStatus.value());
                }
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void StopComponentResponse::s_loadFromJsonView(
                StopComponentResponse &stopComponentResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("stopStatus"))
                {
                    stopComponentResponse.m_stopStatus = Crt::Optional<Crt::String>(jsonView.GetString("stopStatus"));
                }
                if (jsonView.ValueExists("message"))
                {
                    stopComponentResponse.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            void StopComponentResponse::SetStopStatus(Crt::Optional<RequestStatus> stopStatus) noexcept
            {
                switch (stopStatus.value())
                {
                    case REQUEST_STATUS_SUCCEEDED:
                        m_stopStatus = Crt::String("SUCCEEDED");
                        break;
                    case REQUEST_STATUS_FAILED:
                        m_stopStatus = Crt::String("FAILED");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<RequestStatus> StopComponentResponse::GetStopStatus() noexcept
            {
                if (!m_stopStatus.has_value())
                    return Crt::Optional<RequestStatus>();
                if (m_stopStatus.value() == Crt::String("SUCCEEDED"))
                {
                    return Crt::Optional<RequestStatus>(REQUEST_STATUS_SUCCEEDED);
                }
                if (m_stopStatus.value() == Crt::String("FAILED"))
                {
                    return Crt::Optional<RequestStatus>(REQUEST_STATUS_FAILED);
                }

                return Crt::Optional<RequestStatus>();
            }

            Crt::String StopComponentResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#StopComponentResponse");
            }

            Crt::ScopedResource<OperationResponse> StopComponentResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<StopComponentResponse> derivedResponse(
                    Crt::New<StopComponentResponse>(allocator), StopComponentResponse::s_customDeleter);
                StopComponentResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void StopComponentResponse::s_customDeleter(StopComponentResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void StopComponentRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
            }

            void StopComponentRequest::s_loadFromJsonView(
                StopComponentRequest &stopComponentRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    stopComponentRequest.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
            }

            Crt::String StopComponentRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#StopComponentRequest");
            }

            Crt::ScopedResource<OperationRequest> StopComponentRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<StopComponentRequest> derivedResponse(
                    Crt::New<StopComponentRequest>(allocator), StopComponentRequest::s_customDeleter);
                StopComponentRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void StopComponentRequest::s_customDeleter(StopComponentRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void ListLocalDeploymentsResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_localDeployments.has_value())
                {
                    Crt::JsonObject listOfLocalDeployments;
                    Crt::Vector<Crt::JsonObject> listOfLocalDeploymentsJsonArray;
                    for (const auto &listOfLocalDeploymentsItem : m_localDeployments.value())
                    {
                        Crt::JsonObject listOfLocalDeploymentsJsonArrayItem;
                        listOfLocalDeploymentsItem.SerializeToJsonObject(listOfLocalDeploymentsJsonArrayItem);
                        listOfLocalDeploymentsJsonArray.emplace_back(std::move(listOfLocalDeploymentsJsonArrayItem));
                    }
                    listOfLocalDeployments.AsArray(std::move(listOfLocalDeploymentsJsonArray));
                    payloadObject.WithObject("localDeployments", std::move(listOfLocalDeployments));
                }
            }

            void ListLocalDeploymentsResponse::s_loadFromJsonView(
                ListLocalDeploymentsResponse &listLocalDeploymentsResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("localDeployments"))
                {
                    listLocalDeploymentsResponse.m_localDeployments = Crt::Vector<LocalDeployment>();
                    for (const Crt::JsonView &listOfLocalDeploymentsJsonView : jsonView.GetArray("localDeployments"))
                    {
                        Crt::Optional<LocalDeployment> listOfLocalDeploymentsItem;
                        listOfLocalDeploymentsItem = LocalDeployment();
                        LocalDeployment::s_loadFromJsonView(
                            listOfLocalDeploymentsItem.value(), listOfLocalDeploymentsJsonView);
                        listLocalDeploymentsResponse.m_localDeployments.value().push_back(
                            listOfLocalDeploymentsItem.value());
                    }
                }
            }

            Crt::String ListLocalDeploymentsResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListLocalDeploymentsResponse");
            }

            Crt::ScopedResource<OperationResponse> ListLocalDeploymentsResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ListLocalDeploymentsResponse> derivedResponse(
                    Crt::New<ListLocalDeploymentsResponse>(allocator), ListLocalDeploymentsResponse::s_customDeleter);
                ListLocalDeploymentsResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ListLocalDeploymentsResponse::s_customDeleter(ListLocalDeploymentsResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void ListLocalDeploymentsRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void ListLocalDeploymentsRequest::s_loadFromJsonView(
                ListLocalDeploymentsRequest &listLocalDeploymentsRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)listLocalDeploymentsRequest;
                (void)jsonView;
            }

            Crt::String ListLocalDeploymentsRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListLocalDeploymentsRequest");
            }

            Crt::ScopedResource<OperationRequest> ListLocalDeploymentsRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ListLocalDeploymentsRequest> derivedResponse(
                    Crt::New<ListLocalDeploymentsRequest>(allocator), ListLocalDeploymentsRequest::s_customDeleter);
                ListLocalDeploymentsRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void ListLocalDeploymentsRequest::s_customDeleter(ListLocalDeploymentsRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void SubscribeToComponentUpdatesResponse::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void SubscribeToComponentUpdatesResponse::s_loadFromJsonView(
                SubscribeToComponentUpdatesResponse &subscribeToComponentUpdatesResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)subscribeToComponentUpdatesResponse;
                (void)jsonView;
            }

            Crt::String SubscribeToComponentUpdatesResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToComponentUpdatesResponse");
            }

            Crt::ScopedResource<OperationResponse> SubscribeToComponentUpdatesResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToComponentUpdatesResponse> derivedResponse(
                    Crt::New<SubscribeToComponentUpdatesResponse>(allocator),
                    SubscribeToComponentUpdatesResponse::s_customDeleter);
                SubscribeToComponentUpdatesResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void SubscribeToComponentUpdatesResponse::s_customDeleter(
                SubscribeToComponentUpdatesResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void SubscribeToComponentUpdatesRequest::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void SubscribeToComponentUpdatesRequest::s_loadFromJsonView(
                SubscribeToComponentUpdatesRequest &subscribeToComponentUpdatesRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)subscribeToComponentUpdatesRequest;
                (void)jsonView;
            }

            Crt::String SubscribeToComponentUpdatesRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToComponentUpdatesRequest");
            }

            Crt::ScopedResource<OperationRequest> SubscribeToComponentUpdatesRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToComponentUpdatesRequest> derivedResponse(
                    Crt::New<SubscribeToComponentUpdatesRequest>(allocator),
                    SubscribeToComponentUpdatesRequest::s_customDeleter);
                SubscribeToComponentUpdatesRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void SubscribeToComponentUpdatesRequest::s_customDeleter(SubscribeToComponentUpdatesRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void ListNamedShadowsForThingResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_results.has_value())
                {
                    Crt::JsonObject namedShadowList;
                    Crt::Vector<Crt::JsonObject> namedShadowListJsonArray;
                    for (const auto &namedShadowListItem : m_results.value())
                    {
                        Crt::JsonObject namedShadowListJsonArrayItem;
                        namedShadowListJsonArrayItem.AsString(namedShadowListItem);
                        namedShadowListJsonArray.emplace_back(std::move(namedShadowListJsonArrayItem));
                    }
                    namedShadowList.AsArray(std::move(namedShadowListJsonArray));
                    payloadObject.WithObject("results", std::move(namedShadowList));
                }
                if (m_timestamp.has_value())
                {
                    payloadObject.WithDouble("timestamp", m_timestamp.value().SecondsWithMSPrecision());
                }
                if (m_nextToken.has_value())
                {
                    payloadObject.WithString("nextToken", m_nextToken.value());
                }
            }

            void ListNamedShadowsForThingResponse::s_loadFromJsonView(
                ListNamedShadowsForThingResponse &listNamedShadowsForThingResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("results"))
                {
                    listNamedShadowsForThingResponse.m_results = Crt::Vector<Crt::String>();
                    for (const Crt::JsonView &namedShadowListJsonView : jsonView.GetArray("results"))
                    {
                        Crt::Optional<Crt::String> namedShadowListItem;
                        namedShadowListItem = Crt::Optional<Crt::String>(namedShadowListJsonView.AsString());
                        listNamedShadowsForThingResponse.m_results.value().push_back(namedShadowListItem.value());
                    }
                }
                if (jsonView.ValueExists("timestamp"))
                {
                    listNamedShadowsForThingResponse.m_timestamp =
                        Crt::Optional<Crt::DateTime>(Crt::DateTime(jsonView.GetDouble("timestamp")));
                }
                if (jsonView.ValueExists("nextToken"))
                {
                    listNamedShadowsForThingResponse.m_nextToken =
                        Crt::Optional<Crt::String>(jsonView.GetString("nextToken"));
                }
            }

            Crt::String ListNamedShadowsForThingResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListNamedShadowsForThingResponse");
            }

            Crt::ScopedResource<OperationResponse> ListNamedShadowsForThingResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ListNamedShadowsForThingResponse> derivedResponse(
                    Crt::New<ListNamedShadowsForThingResponse>(allocator),
                    ListNamedShadowsForThingResponse::s_customDeleter);
                ListNamedShadowsForThingResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ListNamedShadowsForThingResponse::s_customDeleter(ListNamedShadowsForThingResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void ListNamedShadowsForThingRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_thingName.has_value())
                {
                    payloadObject.WithString("thingName", m_thingName.value());
                }
                if (m_nextToken.has_value())
                {
                    payloadObject.WithString("nextToken", m_nextToken.value());
                }
                if (m_pageSize.has_value())
                {
                    payloadObject.WithInteger("pageSize", m_pageSize.value());
                }
            }

            void ListNamedShadowsForThingRequest::s_loadFromJsonView(
                ListNamedShadowsForThingRequest &listNamedShadowsForThingRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("thingName"))
                {
                    listNamedShadowsForThingRequest.m_thingName =
                        Crt::Optional<Crt::String>(jsonView.GetString("thingName"));
                }
                if (jsonView.ValueExists("nextToken"))
                {
                    listNamedShadowsForThingRequest.m_nextToken =
                        Crt::Optional<Crt::String>(jsonView.GetString("nextToken"));
                }
                if (jsonView.ValueExists("pageSize"))
                {
                    listNamedShadowsForThingRequest.m_pageSize = Crt::Optional<int>(jsonView.GetInteger("pageSize"));
                }
            }

            Crt::String ListNamedShadowsForThingRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListNamedShadowsForThingRequest");
            }

            Crt::ScopedResource<OperationRequest> ListNamedShadowsForThingRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ListNamedShadowsForThingRequest> derivedResponse(
                    Crt::New<ListNamedShadowsForThingRequest>(allocator),
                    ListNamedShadowsForThingRequest::s_customDeleter);
                ListNamedShadowsForThingRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void ListNamedShadowsForThingRequest::s_customDeleter(ListNamedShadowsForThingRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void UpdateStateResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void UpdateStateResponse::s_loadFromJsonView(
                UpdateStateResponse &updateStateResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)updateStateResponse;
                (void)jsonView;
            }

            Crt::String UpdateStateResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateStateResponse");
            }

            Crt::ScopedResource<OperationResponse> UpdateStateResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<UpdateStateResponse> derivedResponse(
                    Crt::New<UpdateStateResponse>(allocator), UpdateStateResponse::s_customDeleter);
                UpdateStateResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void UpdateStateResponse::s_customDeleter(UpdateStateResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void UpdateStateRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_state.has_value())
                {
                    payloadObject.WithString("state", m_state.value());
                }
            }

            void UpdateStateRequest::s_loadFromJsonView(
                UpdateStateRequest &updateStateRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("state"))
                {
                    updateStateRequest.m_state = Crt::Optional<Crt::String>(jsonView.GetString("state"));
                }
            }

            void UpdateStateRequest::SetState(Crt::Optional<ReportedLifecycleState> state) noexcept
            {
                switch (state.value())
                {
                    case REPORTED_LIFECYCLE_STATE_RUNNING:
                        m_state = Crt::String("RUNNING");
                        break;
                    case REPORTED_LIFECYCLE_STATE_ERRORED:
                        m_state = Crt::String("ERRORED");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<ReportedLifecycleState> UpdateStateRequest::GetState() noexcept
            {
                if (!m_state.has_value())
                    return Crt::Optional<ReportedLifecycleState>();
                if (m_state.value() == Crt::String("RUNNING"))
                {
                    return Crt::Optional<ReportedLifecycleState>(REPORTED_LIFECYCLE_STATE_RUNNING);
                }
                if (m_state.value() == Crt::String("ERRORED"))
                {
                    return Crt::Optional<ReportedLifecycleState>(REPORTED_LIFECYCLE_STATE_ERRORED);
                }

                return Crt::Optional<ReportedLifecycleState>();
            }

            Crt::String UpdateStateRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateStateRequest");
            }

            Crt::ScopedResource<OperationRequest> UpdateStateRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<UpdateStateRequest> derivedResponse(
                    Crt::New<UpdateStateRequest>(allocator), UpdateStateRequest::s_customDeleter);
                UpdateStateRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void UpdateStateRequest::s_customDeleter(UpdateStateRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void GetSecretValueResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_secretId.has_value())
                {
                    payloadObject.WithString("secretId", m_secretId.value());
                }
                if (m_versionId.has_value())
                {
                    payloadObject.WithString("versionId", m_versionId.value());
                }
                if (m_versionStage.has_value())
                {
                    Crt::JsonObject secretVersionList;
                    Crt::Vector<Crt::JsonObject> secretVersionListJsonArray;
                    for (const auto &secretVersionListItem : m_versionStage.value())
                    {
                        Crt::JsonObject secretVersionListJsonArrayItem;
                        secretVersionListJsonArrayItem.AsString(secretVersionListItem);
                        secretVersionListJsonArray.emplace_back(std::move(secretVersionListJsonArrayItem));
                    }
                    secretVersionList.AsArray(std::move(secretVersionListJsonArray));
                    payloadObject.WithObject("versionStage", std::move(secretVersionList));
                }
                if (m_secretValue.has_value())
                {
                    Crt::JsonObject secretValueValue;
                    m_secretValue.value().SerializeToJsonObject(secretValueValue);
                    payloadObject.WithObject("secretValue", std::move(secretValueValue));
                }
            }

            void GetSecretValueResponse::s_loadFromJsonView(
                GetSecretValueResponse &getSecretValueResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("secretId"))
                {
                    getSecretValueResponse.m_secretId = Crt::Optional<Crt::String>(jsonView.GetString("secretId"));
                }
                if (jsonView.ValueExists("versionId"))
                {
                    getSecretValueResponse.m_versionId = Crt::Optional<Crt::String>(jsonView.GetString("versionId"));
                }
                if (jsonView.ValueExists("versionStage"))
                {
                    getSecretValueResponse.m_versionStage = Crt::Vector<Crt::String>();
                    for (const Crt::JsonView &secretVersionListJsonView : jsonView.GetArray("versionStage"))
                    {
                        Crt::Optional<Crt::String> secretVersionListItem;
                        secretVersionListItem = Crt::Optional<Crt::String>(secretVersionListJsonView.AsString());
                        getSecretValueResponse.m_versionStage.value().push_back(secretVersionListItem.value());
                    }
                }
                if (jsonView.ValueExists("secretValue"))
                {
                    getSecretValueResponse.m_secretValue = SecretValue();
                    SecretValue::s_loadFromJsonView(
                        getSecretValueResponse.m_secretValue.value(), jsonView.GetJsonObject("secretValue"));
                }
            }

            Crt::String GetSecretValueResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetSecretValueResponse");
            }

            Crt::ScopedResource<OperationResponse> GetSecretValueResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetSecretValueResponse> derivedResponse(
                    Crt::New<GetSecretValueResponse>(allocator), GetSecretValueResponse::s_customDeleter);
                GetSecretValueResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void GetSecretValueResponse::s_customDeleter(GetSecretValueResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void GetSecretValueRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_secretId.has_value())
                {
                    payloadObject.WithString("secretId", m_secretId.value());
                }
                if (m_versionId.has_value())
                {
                    payloadObject.WithString("versionId", m_versionId.value());
                }
                if (m_versionStage.has_value())
                {
                    payloadObject.WithString("versionStage", m_versionStage.value());
                }
            }

            void GetSecretValueRequest::s_loadFromJsonView(
                GetSecretValueRequest &getSecretValueRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("secretId"))
                {
                    getSecretValueRequest.m_secretId = Crt::Optional<Crt::String>(jsonView.GetString("secretId"));
                }
                if (jsonView.ValueExists("versionId"))
                {
                    getSecretValueRequest.m_versionId = Crt::Optional<Crt::String>(jsonView.GetString("versionId"));
                }
                if (jsonView.ValueExists("versionStage"))
                {
                    getSecretValueRequest.m_versionStage =
                        Crt::Optional<Crt::String>(jsonView.GetString("versionStage"));
                }
            }

            Crt::String GetSecretValueRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetSecretValueRequest");
            }

            Crt::ScopedResource<OperationRequest> GetSecretValueRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetSecretValueRequest> derivedResponse(
                    Crt::New<GetSecretValueRequest>(allocator), GetSecretValueRequest::s_customDeleter);
                GetSecretValueRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void GetSecretValueRequest::s_customDeleter(GetSecretValueRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void GetLocalDeploymentStatusResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_deployment.has_value())
                {
                    Crt::JsonObject localDeploymentValue;
                    m_deployment.value().SerializeToJsonObject(localDeploymentValue);
                    payloadObject.WithObject("deployment", std::move(localDeploymentValue));
                }
            }

            void GetLocalDeploymentStatusResponse::s_loadFromJsonView(
                GetLocalDeploymentStatusResponse &getLocalDeploymentStatusResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("deployment"))
                {
                    getLocalDeploymentStatusResponse.m_deployment = LocalDeployment();
                    LocalDeployment::s_loadFromJsonView(
                        getLocalDeploymentStatusResponse.m_deployment.value(), jsonView.GetJsonObject("deployment"));
                }
            }

            Crt::String GetLocalDeploymentStatusResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetLocalDeploymentStatusResponse");
            }

            Crt::ScopedResource<OperationResponse> GetLocalDeploymentStatusResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetLocalDeploymentStatusResponse> derivedResponse(
                    Crt::New<GetLocalDeploymentStatusResponse>(allocator),
                    GetLocalDeploymentStatusResponse::s_customDeleter);
                GetLocalDeploymentStatusResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void GetLocalDeploymentStatusResponse::s_customDeleter(GetLocalDeploymentStatusResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void GetLocalDeploymentStatusRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
            }

            void GetLocalDeploymentStatusRequest::s_loadFromJsonView(
                GetLocalDeploymentStatusRequest &getLocalDeploymentStatusRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("deploymentId"))
                {
                    getLocalDeploymentStatusRequest.m_deploymentId =
                        Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
            }

            Crt::String GetLocalDeploymentStatusRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetLocalDeploymentStatusRequest");
            }

            Crt::ScopedResource<OperationRequest> GetLocalDeploymentStatusRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetLocalDeploymentStatusRequest> derivedResponse(
                    Crt::New<GetLocalDeploymentStatusRequest>(allocator),
                    GetLocalDeploymentStatusRequest::s_customDeleter);
                GetLocalDeploymentStatusRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void GetLocalDeploymentStatusRequest::s_customDeleter(GetLocalDeploymentStatusRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void ComponentNotFoundError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void ComponentNotFoundError::s_loadFromJsonView(
                ComponentNotFoundError &componentNotFoundError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    componentNotFoundError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String ComponentNotFoundError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ComponentNotFoundError");
            }

            Crt::ScopedResource<OperationError> ComponentNotFoundError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ComponentNotFoundError> derivedResponse(
                    Crt::New<ComponentNotFoundError>(allocator), ComponentNotFoundError::s_customDeleter);
                ComponentNotFoundError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void ComponentNotFoundError::s_customDeleter(ComponentNotFoundError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void RestartComponentResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_restartStatus.has_value())
                {
                    payloadObject.WithString("restartStatus", m_restartStatus.value());
                }
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void RestartComponentResponse::s_loadFromJsonView(
                RestartComponentResponse &restartComponentResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("restartStatus"))
                {
                    restartComponentResponse.m_restartStatus =
                        Crt::Optional<Crt::String>(jsonView.GetString("restartStatus"));
                }
                if (jsonView.ValueExists("message"))
                {
                    restartComponentResponse.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            void RestartComponentResponse::SetRestartStatus(Crt::Optional<RequestStatus> restartStatus) noexcept
            {
                switch (restartStatus.value())
                {
                    case REQUEST_STATUS_SUCCEEDED:
                        m_restartStatus = Crt::String("SUCCEEDED");
                        break;
                    case REQUEST_STATUS_FAILED:
                        m_restartStatus = Crt::String("FAILED");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<RequestStatus> RestartComponentResponse::GetRestartStatus() noexcept
            {
                if (!m_restartStatus.has_value())
                    return Crt::Optional<RequestStatus>();
                if (m_restartStatus.value() == Crt::String("SUCCEEDED"))
                {
                    return Crt::Optional<RequestStatus>(REQUEST_STATUS_SUCCEEDED);
                }
                if (m_restartStatus.value() == Crt::String("FAILED"))
                {
                    return Crt::Optional<RequestStatus>(REQUEST_STATUS_FAILED);
                }

                return Crt::Optional<RequestStatus>();
            }

            Crt::String RestartComponentResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#RestartComponentResponse");
            }

            Crt::ScopedResource<OperationResponse> RestartComponentResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<RestartComponentResponse> derivedResponse(
                    Crt::New<RestartComponentResponse>(allocator), RestartComponentResponse::s_customDeleter);
                RestartComponentResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void RestartComponentResponse::s_customDeleter(RestartComponentResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void RestartComponentRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
            }

            void RestartComponentRequest::s_loadFromJsonView(
                RestartComponentRequest &restartComponentRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    restartComponentRequest.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
            }

            Crt::String RestartComponentRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#RestartComponentRequest");
            }

            Crt::ScopedResource<OperationRequest> RestartComponentRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<RestartComponentRequest> derivedResponse(
                    Crt::New<RestartComponentRequest>(allocator), RestartComponentRequest::s_customDeleter);
                RestartComponentRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void RestartComponentRequest::s_customDeleter(RestartComponentRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void InvalidTokenError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void InvalidTokenError::s_loadFromJsonView(
                InvalidTokenError &invalidTokenError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    invalidTokenError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String InvalidTokenError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#InvalidTokenError");
            }

            Crt::ScopedResource<OperationError> InvalidTokenError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<InvalidTokenError> derivedResponse(
                    Crt::New<InvalidTokenError>(allocator), InvalidTokenError::s_customDeleter);
                InvalidTokenError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void InvalidTokenError::s_customDeleter(InvalidTokenError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void ValidateAuthorizationTokenResponse::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_isValid.has_value())
                {
                    payloadObject.WithBool("isValid", m_isValid.value());
                }
            }

            void ValidateAuthorizationTokenResponse::s_loadFromJsonView(
                ValidateAuthorizationTokenResponse &validateAuthorizationTokenResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("isValid"))
                {
                    validateAuthorizationTokenResponse.m_isValid = Crt::Optional<bool>(jsonView.GetBool("isValid"));
                }
            }

            Crt::String ValidateAuthorizationTokenResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateAuthorizationTokenResponse");
            }

            Crt::ScopedResource<OperationResponse> ValidateAuthorizationTokenResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ValidateAuthorizationTokenResponse> derivedResponse(
                    Crt::New<ValidateAuthorizationTokenResponse>(allocator),
                    ValidateAuthorizationTokenResponse::s_customDeleter);
                ValidateAuthorizationTokenResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ValidateAuthorizationTokenResponse::s_customDeleter(ValidateAuthorizationTokenResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void ValidateAuthorizationTokenRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_token.has_value())
                {
                    payloadObject.WithString("token", m_token.value());
                }
            }

            void ValidateAuthorizationTokenRequest::s_loadFromJsonView(
                ValidateAuthorizationTokenRequest &validateAuthorizationTokenRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("token"))
                {
                    validateAuthorizationTokenRequest.m_token = Crt::Optional<Crt::String>(jsonView.GetString("token"));
                }
            }

            Crt::String ValidateAuthorizationTokenRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateAuthorizationTokenRequest");
            }

            Crt::ScopedResource<OperationRequest> ValidateAuthorizationTokenRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ValidateAuthorizationTokenRequest> derivedResponse(
                    Crt::New<ValidateAuthorizationTokenRequest>(allocator),
                    ValidateAuthorizationTokenRequest::s_customDeleter);
                ValidateAuthorizationTokenRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void ValidateAuthorizationTokenRequest::s_customDeleter(ValidateAuthorizationTokenRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void FailedUpdateConditionCheckError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void FailedUpdateConditionCheckError::s_loadFromJsonView(
                FailedUpdateConditionCheckError &failedUpdateConditionCheckError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    failedUpdateConditionCheckError.m_message =
                        Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String FailedUpdateConditionCheckError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#FailedUpdateConditionCheckError");
            }

            Crt::ScopedResource<OperationError> FailedUpdateConditionCheckError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<FailedUpdateConditionCheckError> derivedResponse(
                    Crt::New<FailedUpdateConditionCheckError>(allocator),
                    FailedUpdateConditionCheckError::s_customDeleter);
                FailedUpdateConditionCheckError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void FailedUpdateConditionCheckError::s_customDeleter(FailedUpdateConditionCheckError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void UpdateConfigurationResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void UpdateConfigurationResponse::s_loadFromJsonView(
                UpdateConfigurationResponse &updateConfigurationResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)updateConfigurationResponse;
                (void)jsonView;
            }

            Crt::String UpdateConfigurationResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateConfigurationResponse");
            }

            Crt::ScopedResource<OperationResponse> UpdateConfigurationResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<UpdateConfigurationResponse> derivedResponse(
                    Crt::New<UpdateConfigurationResponse>(allocator), UpdateConfigurationResponse::s_customDeleter);
                UpdateConfigurationResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void UpdateConfigurationResponse::s_customDeleter(UpdateConfigurationResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void UpdateConfigurationRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_keyPath.has_value())
                {
                    Crt::JsonObject keyPath;
                    Crt::Vector<Crt::JsonObject> keyPathJsonArray;
                    for (const auto &keyPathItem : m_keyPath.value())
                    {
                        Crt::JsonObject keyPathJsonArrayItem;
                        keyPathJsonArrayItem.AsString(keyPathItem);
                        keyPathJsonArray.emplace_back(std::move(keyPathJsonArrayItem));
                    }
                    keyPath.AsArray(std::move(keyPathJsonArray));
                    payloadObject.WithObject("keyPath", std::move(keyPath));
                }
                if (m_timestamp.has_value())
                {
                    payloadObject.WithDouble("timestamp", m_timestamp.value().SecondsWithMSPrecision());
                }
                if (m_valueToMerge.has_value())
                {
                    payloadObject.WithObject("valueToMerge", m_valueToMerge.value());
                }
            }

            void UpdateConfigurationRequest::s_loadFromJsonView(
                UpdateConfigurationRequest &updateConfigurationRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("keyPath"))
                {
                    updateConfigurationRequest.m_keyPath = Crt::Vector<Crt::String>();
                    for (const Crt::JsonView &keyPathJsonView : jsonView.GetArray("keyPath"))
                    {
                        Crt::Optional<Crt::String> keyPathItem;
                        keyPathItem = Crt::Optional<Crt::String>(keyPathJsonView.AsString());
                        updateConfigurationRequest.m_keyPath.value().push_back(keyPathItem.value());
                    }
                }
                if (jsonView.ValueExists("timestamp"))
                {
                    updateConfigurationRequest.m_timestamp =
                        Crt::Optional<Crt::DateTime>(Crt::DateTime(jsonView.GetDouble("timestamp")));
                }
                if (jsonView.ValueExists("valueToMerge"))
                {
                    updateConfigurationRequest.m_valueToMerge =
                        Crt::Optional<Crt::JsonObject>(jsonView.GetJsonObject("valueToMerge").Materialize());
                }
            }

            Crt::String UpdateConfigurationRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateConfigurationRequest");
            }

            Crt::ScopedResource<OperationRequest> UpdateConfigurationRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<UpdateConfigurationRequest> derivedResponse(
                    Crt::New<UpdateConfigurationRequest>(allocator), UpdateConfigurationRequest::s_customDeleter);
                UpdateConfigurationRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void UpdateConfigurationRequest::s_customDeleter(UpdateConfigurationRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void ConflictError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void ConflictError::s_loadFromJsonView(ConflictError &conflictError, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    conflictError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String ConflictError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ConflictError");
            }

            Crt::ScopedResource<OperationError> ConflictError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ConflictError> derivedResponse(
                    Crt::New<ConflictError>(allocator), ConflictError::s_customDeleter);
                ConflictError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void ConflictError::s_customDeleter(ConflictError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void UpdateThingShadowResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_payload.has_value())
                {
                    if (m_payload.value().size() > 0)
                    {
                        payloadObject.WithString("payload", Crt::Base64Encode(m_payload.value()));
                    }
                }
            }

            void UpdateThingShadowResponse::s_loadFromJsonView(
                UpdateThingShadowResponse &updateThingShadowResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("payload"))
                {
                    if (jsonView.GetString("payload").size() > 0)
                    {
                        updateThingShadowResponse.m_payload =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("payload")));
                    }
                }
            }

            Crt::String UpdateThingShadowResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateThingShadowResponse");
            }

            Crt::ScopedResource<OperationResponse> UpdateThingShadowResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<UpdateThingShadowResponse> derivedResponse(
                    Crt::New<UpdateThingShadowResponse>(allocator), UpdateThingShadowResponse::s_customDeleter);
                UpdateThingShadowResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void UpdateThingShadowResponse::s_customDeleter(UpdateThingShadowResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void UpdateThingShadowRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_thingName.has_value())
                {
                    payloadObject.WithString("thingName", m_thingName.value());
                }
                if (m_shadowName.has_value())
                {
                    payloadObject.WithString("shadowName", m_shadowName.value());
                }
                if (m_payload.has_value())
                {
                    if (m_payload.value().size() > 0)
                    {
                        payloadObject.WithString("payload", Crt::Base64Encode(m_payload.value()));
                    }
                }
            }

            void UpdateThingShadowRequest::s_loadFromJsonView(
                UpdateThingShadowRequest &updateThingShadowRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("thingName"))
                {
                    updateThingShadowRequest.m_thingName = Crt::Optional<Crt::String>(jsonView.GetString("thingName"));
                }
                if (jsonView.ValueExists("shadowName"))
                {
                    updateThingShadowRequest.m_shadowName =
                        Crt::Optional<Crt::String>(jsonView.GetString("shadowName"));
                }
                if (jsonView.ValueExists("payload"))
                {
                    if (jsonView.GetString("payload").size() > 0)
                    {
                        updateThingShadowRequest.m_payload =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("payload")));
                    }
                }
            }

            Crt::String UpdateThingShadowRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateThingShadowRequest");
            }

            Crt::ScopedResource<OperationRequest> UpdateThingShadowRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<UpdateThingShadowRequest> derivedResponse(
                    Crt::New<UpdateThingShadowRequest>(allocator), UpdateThingShadowRequest::s_customDeleter);
                UpdateThingShadowRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void UpdateThingShadowRequest::s_customDeleter(UpdateThingShadowRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void SendConfigurationValidityReportResponse::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void SendConfigurationValidityReportResponse::s_loadFromJsonView(
                SendConfigurationValidityReportResponse &sendConfigurationValidityReportResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)sendConfigurationValidityReportResponse;
                (void)jsonView;
            }

            Crt::String SendConfigurationValidityReportResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SendConfigurationValidityReportResponse");
            }

            Crt::ScopedResource<OperationResponse> SendConfigurationValidityReportResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SendConfigurationValidityReportResponse> derivedResponse(
                    Crt::New<SendConfigurationValidityReportResponse>(allocator),
                    SendConfigurationValidityReportResponse::s_customDeleter);
                SendConfigurationValidityReportResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void SendConfigurationValidityReportResponse::s_customDeleter(
                SendConfigurationValidityReportResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void SendConfigurationValidityReportRequest::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_configurationValidityReport.has_value())
                {
                    Crt::JsonObject configurationValidityReportValue;
                    m_configurationValidityReport.value().SerializeToJsonObject(configurationValidityReportValue);
                    payloadObject.WithObject(
                        "configurationValidityReport", std::move(configurationValidityReportValue));
                }
            }

            void SendConfigurationValidityReportRequest::s_loadFromJsonView(
                SendConfigurationValidityReportRequest &sendConfigurationValidityReportRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("configurationValidityReport"))
                {
                    sendConfigurationValidityReportRequest.m_configurationValidityReport =
                        ConfigurationValidityReport();
                    ConfigurationValidityReport::s_loadFromJsonView(
                        sendConfigurationValidityReportRequest.m_configurationValidityReport.value(),
                        jsonView.GetJsonObject("configurationValidityReport"));
                }
            }

            Crt::String SendConfigurationValidityReportRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SendConfigurationValidityReportRequest");
            }

            Crt::ScopedResource<OperationRequest> SendConfigurationValidityReportRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SendConfigurationValidityReportRequest> derivedResponse(
                    Crt::New<SendConfigurationValidityReportRequest>(allocator),
                    SendConfigurationValidityReportRequest::s_customDeleter);
                SendConfigurationValidityReportRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void SendConfigurationValidityReportRequest::s_customDeleter(
                SendConfigurationValidityReportRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void GetThingShadowResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_payload.has_value())
                {
                    if (m_payload.value().size() > 0)
                    {
                        payloadObject.WithString("payload", Crt::Base64Encode(m_payload.value()));
                    }
                }
            }

            void GetThingShadowResponse::s_loadFromJsonView(
                GetThingShadowResponse &getThingShadowResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("payload"))
                {
                    if (jsonView.GetString("payload").size() > 0)
                    {
                        getThingShadowResponse.m_payload =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("payload")));
                    }
                }
            }

            Crt::String GetThingShadowResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetThingShadowResponse");
            }

            Crt::ScopedResource<OperationResponse> GetThingShadowResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetThingShadowResponse> derivedResponse(
                    Crt::New<GetThingShadowResponse>(allocator), GetThingShadowResponse::s_customDeleter);
                GetThingShadowResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void GetThingShadowResponse::s_customDeleter(GetThingShadowResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void GetThingShadowRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_thingName.has_value())
                {
                    payloadObject.WithString("thingName", m_thingName.value());
                }
                if (m_shadowName.has_value())
                {
                    payloadObject.WithString("shadowName", m_shadowName.value());
                }
            }

            void GetThingShadowRequest::s_loadFromJsonView(
                GetThingShadowRequest &getThingShadowRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("thingName"))
                {
                    getThingShadowRequest.m_thingName = Crt::Optional<Crt::String>(jsonView.GetString("thingName"));
                }
                if (jsonView.ValueExists("shadowName"))
                {
                    getThingShadowRequest.m_shadowName = Crt::Optional<Crt::String>(jsonView.GetString("shadowName"));
                }
            }

            Crt::String GetThingShadowRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetThingShadowRequest");
            }

            Crt::ScopedResource<OperationRequest> GetThingShadowRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetThingShadowRequest> derivedResponse(
                    Crt::New<GetThingShadowRequest>(allocator), GetThingShadowRequest::s_customDeleter);
                GetThingShadowRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void GetThingShadowRequest::s_customDeleter(GetThingShadowRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void CreateDebugPasswordResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_password.has_value())
                {
                    payloadObject.WithString("password", m_password.value());
                }
                if (m_username.has_value())
                {
                    payloadObject.WithString("username", m_username.value());
                }
                if (m_passwordExpiration.has_value())
                {
                    payloadObject.WithDouble(
                        "passwordExpiration", m_passwordExpiration.value().SecondsWithMSPrecision());
                }
                if (m_certificateSHA256Hash.has_value())
                {
                    payloadObject.WithString("certificateSHA256Hash", m_certificateSHA256Hash.value());
                }
                if (m_certificateSHA1Hash.has_value())
                {
                    payloadObject.WithString("certificateSHA1Hash", m_certificateSHA1Hash.value());
                }
            }

            void CreateDebugPasswordResponse::s_loadFromJsonView(
                CreateDebugPasswordResponse &createDebugPasswordResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("password"))
                {
                    createDebugPasswordResponse.m_password = Crt::Optional<Crt::String>(jsonView.GetString("password"));
                }
                if (jsonView.ValueExists("username"))
                {
                    createDebugPasswordResponse.m_username = Crt::Optional<Crt::String>(jsonView.GetString("username"));
                }
                if (jsonView.ValueExists("passwordExpiration"))
                {
                    createDebugPasswordResponse.m_passwordExpiration =
                        Crt::Optional<Crt::DateTime>(Crt::DateTime(jsonView.GetDouble("passwordExpiration")));
                }
                if (jsonView.ValueExists("certificateSHA256Hash"))
                {
                    createDebugPasswordResponse.m_certificateSHA256Hash =
                        Crt::Optional<Crt::String>(jsonView.GetString("certificateSHA256Hash"));
                }
                if (jsonView.ValueExists("certificateSHA1Hash"))
                {
                    createDebugPasswordResponse.m_certificateSHA1Hash =
                        Crt::Optional<Crt::String>(jsonView.GetString("certificateSHA1Hash"));
                }
            }

            Crt::String CreateDebugPasswordResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateDebugPasswordResponse");
            }

            Crt::ScopedResource<OperationResponse> CreateDebugPasswordResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<CreateDebugPasswordResponse> derivedResponse(
                    Crt::New<CreateDebugPasswordResponse>(allocator), CreateDebugPasswordResponse::s_customDeleter);
                CreateDebugPasswordResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void CreateDebugPasswordResponse::s_customDeleter(CreateDebugPasswordResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void CreateDebugPasswordRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void CreateDebugPasswordRequest::s_loadFromJsonView(
                CreateDebugPasswordRequest &createDebugPasswordRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)createDebugPasswordRequest;
                (void)jsonView;
            }

            Crt::String CreateDebugPasswordRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateDebugPasswordRequest");
            }

            Crt::ScopedResource<OperationRequest> CreateDebugPasswordRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<CreateDebugPasswordRequest> derivedResponse(
                    Crt::New<CreateDebugPasswordRequest>(allocator), CreateDebugPasswordRequest::s_customDeleter);
                CreateDebugPasswordRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void CreateDebugPasswordRequest::s_customDeleter(CreateDebugPasswordRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void ListComponentsResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_components.has_value())
                {
                    Crt::JsonObject listOfComponents;
                    Crt::Vector<Crt::JsonObject> listOfComponentsJsonArray;
                    for (const auto &listOfComponentsItem : m_components.value())
                    {
                        Crt::JsonObject listOfComponentsJsonArrayItem;
                        listOfComponentsItem.SerializeToJsonObject(listOfComponentsJsonArrayItem);
                        listOfComponentsJsonArray.emplace_back(std::move(listOfComponentsJsonArrayItem));
                    }
                    listOfComponents.AsArray(std::move(listOfComponentsJsonArray));
                    payloadObject.WithObject("components", std::move(listOfComponents));
                }
            }

            void ListComponentsResponse::s_loadFromJsonView(
                ListComponentsResponse &listComponentsResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("components"))
                {
                    listComponentsResponse.m_components = Crt::Vector<ComponentDetails>();
                    for (const Crt::JsonView &listOfComponentsJsonView : jsonView.GetArray("components"))
                    {
                        Crt::Optional<ComponentDetails> listOfComponentsItem;
                        listOfComponentsItem = ComponentDetails();
                        ComponentDetails::s_loadFromJsonView(listOfComponentsItem.value(), listOfComponentsJsonView);
                        listComponentsResponse.m_components.value().push_back(listOfComponentsItem.value());
                    }
                }
            }

            Crt::String ListComponentsResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListComponentsResponse");
            }

            Crt::ScopedResource<OperationResponse> ListComponentsResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ListComponentsResponse> derivedResponse(
                    Crt::New<ListComponentsResponse>(allocator), ListComponentsResponse::s_customDeleter);
                ListComponentsResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ListComponentsResponse::s_customDeleter(ListComponentsResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void ListComponentsRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void ListComponentsRequest::s_loadFromJsonView(
                ListComponentsRequest &listComponentsRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)listComponentsRequest;
                (void)jsonView;
            }

            Crt::String ListComponentsRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListComponentsRequest");
            }

            Crt::ScopedResource<OperationRequest> ListComponentsRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ListComponentsRequest> derivedResponse(
                    Crt::New<ListComponentsRequest>(allocator), ListComponentsRequest::s_customDeleter);
                ListComponentsRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void ListComponentsRequest::s_customDeleter(ListComponentsRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void PublishToTopicResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void PublishToTopicResponse::s_loadFromJsonView(
                PublishToTopicResponse &publishToTopicResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)publishToTopicResponse;
                (void)jsonView;
            }

            Crt::String PublishToTopicResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopicResponse");
            }

            Crt::ScopedResource<OperationResponse> PublishToTopicResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PublishToTopicResponse> derivedResponse(
                    Crt::New<PublishToTopicResponse>(allocator), PublishToTopicResponse::s_customDeleter);
                PublishToTopicResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void PublishToTopicResponse::s_customDeleter(PublishToTopicResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void PublishToTopicRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_topic.has_value())
                {
                    payloadObject.WithString("topic", m_topic.value());
                }
                if (m_publishMessage.has_value())
                {
                    Crt::JsonObject publishMessageValue;
                    m_publishMessage.value().SerializeToJsonObject(publishMessageValue);
                    payloadObject.WithObject("publishMessage", std::move(publishMessageValue));
                }
            }

            void PublishToTopicRequest::s_loadFromJsonView(
                PublishToTopicRequest &publishToTopicRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("topic"))
                {
                    publishToTopicRequest.m_topic = Crt::Optional<Crt::String>(jsonView.GetString("topic"));
                }
                if (jsonView.ValueExists("publishMessage"))
                {
                    publishToTopicRequest.m_publishMessage = PublishMessage();
                    PublishMessage::s_loadFromJsonView(
                        publishToTopicRequest.m_publishMessage.value(), jsonView.GetJsonObject("publishMessage"));
                }
            }

            Crt::String PublishToTopicRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopicRequest");
            }

            Crt::ScopedResource<OperationRequest> PublishToTopicRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PublishToTopicRequest> derivedResponse(
                    Crt::New<PublishToTopicRequest>(allocator), PublishToTopicRequest::s_customDeleter);
                PublishToTopicRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void PublishToTopicRequest::s_customDeleter(PublishToTopicRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void GetComponentDetailsResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentDetails.has_value())
                {
                    Crt::JsonObject componentDetailsValue;
                    m_componentDetails.value().SerializeToJsonObject(componentDetailsValue);
                    payloadObject.WithObject("componentDetails", std::move(componentDetailsValue));
                }
            }

            void GetComponentDetailsResponse::s_loadFromJsonView(
                GetComponentDetailsResponse &getComponentDetailsResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentDetails"))
                {
                    getComponentDetailsResponse.m_componentDetails = ComponentDetails();
                    ComponentDetails::s_loadFromJsonView(
                        getComponentDetailsResponse.m_componentDetails.value(),
                        jsonView.GetJsonObject("componentDetails"));
                }
            }

            Crt::String GetComponentDetailsResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetComponentDetailsResponse");
            }

            Crt::ScopedResource<OperationResponse> GetComponentDetailsResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetComponentDetailsResponse> derivedResponse(
                    Crt::New<GetComponentDetailsResponse>(allocator), GetComponentDetailsResponse::s_customDeleter);
                GetComponentDetailsResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void GetComponentDetailsResponse::s_customDeleter(GetComponentDetailsResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void GetComponentDetailsRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
            }

            void GetComponentDetailsRequest::s_loadFromJsonView(
                GetComponentDetailsRequest &getComponentDetailsRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    getComponentDetailsRequest.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
            }

            Crt::String GetComponentDetailsRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetComponentDetailsRequest");
            }

            Crt::ScopedResource<OperationRequest> GetComponentDetailsRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetComponentDetailsRequest> derivedResponse(
                    Crt::New<GetComponentDetailsRequest>(allocator), GetComponentDetailsRequest::s_customDeleter);
                GetComponentDetailsRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void GetComponentDetailsRequest::s_customDeleter(GetComponentDetailsRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void SubscribeToTopicResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_topicName.has_value())
                {
                    payloadObject.WithString("topicName", m_topicName.value());
                }
            }

            void SubscribeToTopicResponse::s_loadFromJsonView(
                SubscribeToTopicResponse &subscribeToTopicResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("topicName"))
                {
                    subscribeToTopicResponse.m_topicName = Crt::Optional<Crt::String>(jsonView.GetString("topicName"));
                }
            }

            Crt::String SubscribeToTopicResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopicResponse");
            }

            Crt::ScopedResource<OperationResponse> SubscribeToTopicResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToTopicResponse> derivedResponse(
                    Crt::New<SubscribeToTopicResponse>(allocator), SubscribeToTopicResponse::s_customDeleter);
                SubscribeToTopicResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void SubscribeToTopicResponse::s_customDeleter(SubscribeToTopicResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void SubscribeToTopicRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_topic.has_value())
                {
                    payloadObject.WithString("topic", m_topic.value());
                }
            }

            void SubscribeToTopicRequest::s_loadFromJsonView(
                SubscribeToTopicRequest &subscribeToTopicRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("topic"))
                {
                    subscribeToTopicRequest.m_topic = Crt::Optional<Crt::String>(jsonView.GetString("topic"));
                }
            }

            Crt::String SubscribeToTopicRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopicRequest");
            }

            Crt::ScopedResource<OperationRequest> SubscribeToTopicRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToTopicRequest> derivedResponse(
                    Crt::New<SubscribeToTopicRequest>(allocator), SubscribeToTopicRequest::s_customDeleter);
                SubscribeToTopicRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void SubscribeToTopicRequest::s_customDeleter(SubscribeToTopicRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void GetConfigurationResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
                if (m_value.has_value())
                {
                    payloadObject.WithObject("value", m_value.value());
                }
            }

            void GetConfigurationResponse::s_loadFromJsonView(
                GetConfigurationResponse &getConfigurationResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    getConfigurationResponse.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
                if (jsonView.ValueExists("value"))
                {
                    getConfigurationResponse.m_value =
                        Crt::Optional<Crt::JsonObject>(jsonView.GetJsonObject("value").Materialize());
                }
            }

            Crt::String GetConfigurationResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetConfigurationResponse");
            }

            Crt::ScopedResource<OperationResponse> GetConfigurationResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetConfigurationResponse> derivedResponse(
                    Crt::New<GetConfigurationResponse>(allocator), GetConfigurationResponse::s_customDeleter);
                GetConfigurationResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void GetConfigurationResponse::s_customDeleter(GetConfigurationResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void GetConfigurationRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
                if (m_keyPath.has_value())
                {
                    Crt::JsonObject keyPath;
                    Crt::Vector<Crt::JsonObject> keyPathJsonArray;
                    for (const auto &keyPathItem : m_keyPath.value())
                    {
                        Crt::JsonObject keyPathJsonArrayItem;
                        keyPathJsonArrayItem.AsString(keyPathItem);
                        keyPathJsonArray.emplace_back(std::move(keyPathJsonArrayItem));
                    }
                    keyPath.AsArray(std::move(keyPathJsonArray));
                    payloadObject.WithObject("keyPath", std::move(keyPath));
                }
            }

            void GetConfigurationRequest::s_loadFromJsonView(
                GetConfigurationRequest &getConfigurationRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    getConfigurationRequest.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
                if (jsonView.ValueExists("keyPath"))
                {
                    getConfigurationRequest.m_keyPath = Crt::Vector<Crt::String>();
                    for (const Crt::JsonView &keyPathJsonView : jsonView.GetArray("keyPath"))
                    {
                        Crt::Optional<Crt::String> keyPathItem;
                        keyPathItem = Crt::Optional<Crt::String>(keyPathJsonView.AsString());
                        getConfigurationRequest.m_keyPath.value().push_back(keyPathItem.value());
                    }
                }
            }

            Crt::String GetConfigurationRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetConfigurationRequest");
            }

            Crt::ScopedResource<OperationRequest> GetConfigurationRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<GetConfigurationRequest> derivedResponse(
                    Crt::New<GetConfigurationRequest>(allocator), GetConfigurationRequest::s_customDeleter);
                GetConfigurationRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void GetConfigurationRequest::s_customDeleter(GetConfigurationRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void SubscribeToValidateConfigurationUpdatesResponse::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void SubscribeToValidateConfigurationUpdatesResponse::s_loadFromJsonView(
                SubscribeToValidateConfigurationUpdatesResponse &subscribeToValidateConfigurationUpdatesResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)subscribeToValidateConfigurationUpdatesResponse;
                (void)jsonView;
            }

            Crt::String SubscribeToValidateConfigurationUpdatesResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToValidateConfigurationUpdatesResponse");
            }

            Crt::ScopedResource<OperationResponse> SubscribeToValidateConfigurationUpdatesResponse::
                s_allocateFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToValidateConfigurationUpdatesResponse> derivedResponse(
                    Crt::New<SubscribeToValidateConfigurationUpdatesResponse>(allocator),
                    SubscribeToValidateConfigurationUpdatesResponse::s_customDeleter);
                SubscribeToValidateConfigurationUpdatesResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void SubscribeToValidateConfigurationUpdatesResponse::s_customDeleter(
                SubscribeToValidateConfigurationUpdatesResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void SubscribeToValidateConfigurationUpdatesRequest::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void SubscribeToValidateConfigurationUpdatesRequest::s_loadFromJsonView(
                SubscribeToValidateConfigurationUpdatesRequest &subscribeToValidateConfigurationUpdatesRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)subscribeToValidateConfigurationUpdatesRequest;
                (void)jsonView;
            }

            Crt::String SubscribeToValidateConfigurationUpdatesRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToValidateConfigurationUpdatesRequest");
            }

            Crt::ScopedResource<OperationRequest> SubscribeToValidateConfigurationUpdatesRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToValidateConfigurationUpdatesRequest> derivedResponse(
                    Crt::New<SubscribeToValidateConfigurationUpdatesRequest>(allocator),
                    SubscribeToValidateConfigurationUpdatesRequest::s_customDeleter);
                SubscribeToValidateConfigurationUpdatesRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void SubscribeToValidateConfigurationUpdatesRequest::s_customDeleter(
                SubscribeToValidateConfigurationUpdatesRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void DeferComponentUpdateResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void DeferComponentUpdateResponse::s_loadFromJsonView(
                DeferComponentUpdateResponse &deferComponentUpdateResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)deferComponentUpdateResponse;
                (void)jsonView;
            }

            Crt::String DeferComponentUpdateResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeferComponentUpdateResponse");
            }

            Crt::ScopedResource<OperationResponse> DeferComponentUpdateResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<DeferComponentUpdateResponse> derivedResponse(
                    Crt::New<DeferComponentUpdateResponse>(allocator), DeferComponentUpdateResponse::s_customDeleter);
                DeferComponentUpdateResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void DeferComponentUpdateResponse::s_customDeleter(DeferComponentUpdateResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void DeferComponentUpdateRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_deploymentId.has_value())
                {
                    payloadObject.WithString("deploymentId", m_deploymentId.value());
                }
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
                if (m_recheckAfterMs.has_value())
                {
                    payloadObject.WithInteger("recheckAfterMs", m_recheckAfterMs.value());
                }
            }

            void DeferComponentUpdateRequest::s_loadFromJsonView(
                DeferComponentUpdateRequest &deferComponentUpdateRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("deploymentId"))
                {
                    deferComponentUpdateRequest.m_deploymentId =
                        Crt::Optional<Crt::String>(jsonView.GetString("deploymentId"));
                }
                if (jsonView.ValueExists("message"))
                {
                    deferComponentUpdateRequest.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
                if (jsonView.ValueExists("recheckAfterMs"))
                {
                    deferComponentUpdateRequest.m_recheckAfterMs =
                        Crt::Optional<int>(jsonView.GetInteger("recheckAfterMs"));
                }
            }

            Crt::String DeferComponentUpdateRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeferComponentUpdateRequest");
            }

            Crt::ScopedResource<OperationRequest> DeferComponentUpdateRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<DeferComponentUpdateRequest> derivedResponse(
                    Crt::New<DeferComponentUpdateRequest>(allocator), DeferComponentUpdateRequest::s_customDeleter);
                DeferComponentUpdateRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void DeferComponentUpdateRequest::s_customDeleter(DeferComponentUpdateRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void InvalidArgumentsError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void InvalidArgumentsError::s_loadFromJsonView(
                InvalidArgumentsError &invalidArgumentsError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    invalidArgumentsError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String InvalidArgumentsError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#InvalidArgumentsError");
            }

            Crt::ScopedResource<OperationError> InvalidArgumentsError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<InvalidArgumentsError> derivedResponse(
                    Crt::New<InvalidArgumentsError>(allocator), InvalidArgumentsError::s_customDeleter);
                InvalidArgumentsError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void InvalidArgumentsError::s_customDeleter(InvalidArgumentsError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void DeleteThingShadowResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_payload.has_value())
                {
                    if (m_payload.value().size() > 0)
                    {
                        payloadObject.WithString("payload", Crt::Base64Encode(m_payload.value()));
                    }
                }
            }

            void DeleteThingShadowResponse::s_loadFromJsonView(
                DeleteThingShadowResponse &deleteThingShadowResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("payload"))
                {
                    if (jsonView.GetString("payload").size() > 0)
                    {
                        deleteThingShadowResponse.m_payload =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("payload")));
                    }
                }
            }

            Crt::String DeleteThingShadowResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeleteThingShadowResponse");
            }

            Crt::ScopedResource<OperationResponse> DeleteThingShadowResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<DeleteThingShadowResponse> derivedResponse(
                    Crt::New<DeleteThingShadowResponse>(allocator), DeleteThingShadowResponse::s_customDeleter);
                DeleteThingShadowResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void DeleteThingShadowResponse::s_customDeleter(DeleteThingShadowResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void DeleteThingShadowRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_thingName.has_value())
                {
                    payloadObject.WithString("thingName", m_thingName.value());
                }
                if (m_shadowName.has_value())
                {
                    payloadObject.WithString("shadowName", m_shadowName.value());
                }
            }

            void DeleteThingShadowRequest::s_loadFromJsonView(
                DeleteThingShadowRequest &deleteThingShadowRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("thingName"))
                {
                    deleteThingShadowRequest.m_thingName = Crt::Optional<Crt::String>(jsonView.GetString("thingName"));
                }
                if (jsonView.ValueExists("shadowName"))
                {
                    deleteThingShadowRequest.m_shadowName =
                        Crt::Optional<Crt::String>(jsonView.GetString("shadowName"));
                }
            }

            Crt::String DeleteThingShadowRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeleteThingShadowRequest");
            }

            Crt::ScopedResource<OperationRequest> DeleteThingShadowRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<DeleteThingShadowRequest> derivedResponse(
                    Crt::New<DeleteThingShadowRequest>(allocator), DeleteThingShadowRequest::s_customDeleter);
                DeleteThingShadowRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void DeleteThingShadowRequest::s_customDeleter(DeleteThingShadowRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void SubscribeToConfigurationUpdateResponse::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void SubscribeToConfigurationUpdateResponse::s_loadFromJsonView(
                SubscribeToConfigurationUpdateResponse &subscribeToConfigurationUpdateResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)subscribeToConfigurationUpdateResponse;
                (void)jsonView;
            }

            Crt::String SubscribeToConfigurationUpdateResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToConfigurationUpdateResponse");
            }

            Crt::ScopedResource<OperationResponse> SubscribeToConfigurationUpdateResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToConfigurationUpdateResponse> derivedResponse(
                    Crt::New<SubscribeToConfigurationUpdateResponse>(allocator),
                    SubscribeToConfigurationUpdateResponse::s_customDeleter);
                SubscribeToConfigurationUpdateResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void SubscribeToConfigurationUpdateResponse::s_customDeleter(
                SubscribeToConfigurationUpdateResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void SubscribeToConfigurationUpdateRequest::SerializeToJsonObject(
                Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
                if (m_keyPath.has_value())
                {
                    Crt::JsonObject keyPath;
                    Crt::Vector<Crt::JsonObject> keyPathJsonArray;
                    for (const auto &keyPathItem : m_keyPath.value())
                    {
                        Crt::JsonObject keyPathJsonArrayItem;
                        keyPathJsonArrayItem.AsString(keyPathItem);
                        keyPathJsonArray.emplace_back(std::move(keyPathJsonArrayItem));
                    }
                    keyPath.AsArray(std::move(keyPathJsonArray));
                    payloadObject.WithObject("keyPath", std::move(keyPath));
                }
            }

            void SubscribeToConfigurationUpdateRequest::s_loadFromJsonView(
                SubscribeToConfigurationUpdateRequest &subscribeToConfigurationUpdateRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    subscribeToConfigurationUpdateRequest.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
                if (jsonView.ValueExists("keyPath"))
                {
                    subscribeToConfigurationUpdateRequest.m_keyPath = Crt::Vector<Crt::String>();
                    for (const Crt::JsonView &keyPathJsonView : jsonView.GetArray("keyPath"))
                    {
                        Crt::Optional<Crt::String> keyPathItem;
                        keyPathItem = Crt::Optional<Crt::String>(keyPathJsonView.AsString());
                        subscribeToConfigurationUpdateRequest.m_keyPath.value().push_back(keyPathItem.value());
                    }
                }
            }

            Crt::String SubscribeToConfigurationUpdateRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToConfigurationUpdateRequest");
            }

            Crt::ScopedResource<OperationRequest> SubscribeToConfigurationUpdateRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToConfigurationUpdateRequest> derivedResponse(
                    Crt::New<SubscribeToConfigurationUpdateRequest>(allocator),
                    SubscribeToConfigurationUpdateRequest::s_customDeleter);
                SubscribeToConfigurationUpdateRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void SubscribeToConfigurationUpdateRequest::s_customDeleter(
                SubscribeToConfigurationUpdateRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void PublishToIoTCoreResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void PublishToIoTCoreResponse::s_loadFromJsonView(
                PublishToIoTCoreResponse &publishToIoTCoreResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)publishToIoTCoreResponse;
                (void)jsonView;
            }

            Crt::String PublishToIoTCoreResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToIoTCoreResponse");
            }

            Crt::ScopedResource<OperationResponse> PublishToIoTCoreResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PublishToIoTCoreResponse> derivedResponse(
                    Crt::New<PublishToIoTCoreResponse>(allocator), PublishToIoTCoreResponse::s_customDeleter);
                PublishToIoTCoreResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void PublishToIoTCoreResponse::s_customDeleter(PublishToIoTCoreResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void PublishToIoTCoreRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_topicName.has_value())
                {
                    payloadObject.WithString("topicName", m_topicName.value());
                }
                if (m_qos.has_value())
                {
                    payloadObject.WithString("qos", m_qos.value());
                }
                if (m_payload.has_value())
                {
                    if (m_payload.value().size() > 0)
                    {
                        payloadObject.WithString("payload", Crt::Base64Encode(m_payload.value()));
                    }
                }
            }

            void PublishToIoTCoreRequest::s_loadFromJsonView(
                PublishToIoTCoreRequest &publishToIoTCoreRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("topicName"))
                {
                    publishToIoTCoreRequest.m_topicName = Crt::Optional<Crt::String>(jsonView.GetString("topicName"));
                }
                if (jsonView.ValueExists("qos"))
                {
                    publishToIoTCoreRequest.m_qos = Crt::Optional<Crt::String>(jsonView.GetString("qos"));
                }
                if (jsonView.ValueExists("payload"))
                {
                    if (jsonView.GetString("payload").size() > 0)
                    {
                        publishToIoTCoreRequest.m_payload =
                            Crt::Optional<Crt::Vector<uint8_t>>(Crt::Base64Decode(jsonView.GetString("payload")));
                    }
                }
            }

            void PublishToIoTCoreRequest::SetQos(Crt::Optional<QOS> qos) noexcept
            {
                switch (qos.value())
                {
                    case QOS_AT_MOST_ONCE:
                        m_qos = Crt::String("0");
                        break;
                    case QOS_AT_LEAST_ONCE:
                        m_qos = Crt::String("1");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<QOS> PublishToIoTCoreRequest::GetQos() noexcept
            {
                if (!m_qos.has_value())
                    return Crt::Optional<QOS>();
                if (m_qos.value() == Crt::String("0"))
                {
                    return Crt::Optional<QOS>(QOS_AT_MOST_ONCE);
                }
                if (m_qos.value() == Crt::String("1"))
                {
                    return Crt::Optional<QOS>(QOS_AT_LEAST_ONCE);
                }

                return Crt::Optional<QOS>();
            }

            Crt::String PublishToIoTCoreRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToIoTCoreRequest");
            }

            Crt::ScopedResource<OperationRequest> PublishToIoTCoreRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<PublishToIoTCoreRequest> derivedResponse(
                    Crt::New<PublishToIoTCoreRequest>(allocator), PublishToIoTCoreRequest::s_customDeleter);
                PublishToIoTCoreRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void PublishToIoTCoreRequest::s_customDeleter(PublishToIoTCoreRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void ResourceNotFoundError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
                if (m_resourceType.has_value())
                {
                    payloadObject.WithString("resourceType", m_resourceType.value());
                }
                if (m_resourceName.has_value())
                {
                    payloadObject.WithString("resourceName", m_resourceName.value());
                }
            }

            void ResourceNotFoundError::s_loadFromJsonView(
                ResourceNotFoundError &resourceNotFoundError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    resourceNotFoundError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
                if (jsonView.ValueExists("resourceType"))
                {
                    resourceNotFoundError.m_resourceType =
                        Crt::Optional<Crt::String>(jsonView.GetString("resourceType"));
                }
                if (jsonView.ValueExists("resourceName"))
                {
                    resourceNotFoundError.m_resourceName =
                        Crt::Optional<Crt::String>(jsonView.GetString("resourceName"));
                }
            }

            Crt::String ResourceNotFoundError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ResourceNotFoundError");
            }

            Crt::ScopedResource<OperationError> ResourceNotFoundError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ResourceNotFoundError> derivedResponse(
                    Crt::New<ResourceNotFoundError>(allocator), ResourceNotFoundError::s_customDeleter);
                ResourceNotFoundError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void ResourceNotFoundError::s_customDeleter(ResourceNotFoundError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void ResumeComponentResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void ResumeComponentResponse::s_loadFromJsonView(
                ResumeComponentResponse &resumeComponentResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)resumeComponentResponse;
                (void)jsonView;
            }

            Crt::String ResumeComponentResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ResumeComponentResponse");
            }

            Crt::ScopedResource<OperationResponse> ResumeComponentResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ResumeComponentResponse> derivedResponse(
                    Crt::New<ResumeComponentResponse>(allocator), ResumeComponentResponse::s_customDeleter);
                ResumeComponentResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void ResumeComponentResponse::s_customDeleter(ResumeComponentResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void ResumeComponentRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_componentName.has_value())
                {
                    payloadObject.WithString("componentName", m_componentName.value());
                }
            }

            void ResumeComponentRequest::s_loadFromJsonView(
                ResumeComponentRequest &resumeComponentRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("componentName"))
                {
                    resumeComponentRequest.m_componentName =
                        Crt::Optional<Crt::String>(jsonView.GetString("componentName"));
                }
            }

            Crt::String ResumeComponentRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ResumeComponentRequest");
            }

            Crt::ScopedResource<OperationRequest> ResumeComponentRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ResumeComponentRequest> derivedResponse(
                    Crt::New<ResumeComponentRequest>(allocator), ResumeComponentRequest::s_customDeleter);
                ResumeComponentRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void ResumeComponentRequest::s_customDeleter(ResumeComponentRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void UnauthorizedError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void UnauthorizedError::s_loadFromJsonView(
                UnauthorizedError &unauthorizedError,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    unauthorizedError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String UnauthorizedError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UnauthorizedError");
            }

            Crt::ScopedResource<OperationError> UnauthorizedError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<UnauthorizedError> derivedResponse(
                    Crt::New<UnauthorizedError>(allocator), UnauthorizedError::s_customDeleter);
                UnauthorizedError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void UnauthorizedError::s_customDeleter(UnauthorizedError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void ServiceError::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_message.has_value())
                {
                    payloadObject.WithString("message", m_message.value());
                }
            }

            void ServiceError::s_loadFromJsonView(ServiceError &serviceError, const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("message"))
                {
                    serviceError.m_message = Crt::Optional<Crt::String>(jsonView.GetString("message"));
                }
            }

            Crt::String ServiceError::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ServiceError");
            }

            Crt::ScopedResource<OperationError> ServiceError::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<ServiceError> derivedResponse(
                    Crt::New<ServiceError>(allocator), ServiceError::s_customDeleter);
                ServiceError::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationError *>(derivedResponse.release());
                return Crt::ScopedResource<OperationError>(operationResponse, OperationError::s_customDeleter);
            }

            void ServiceError::s_customDeleter(ServiceError *shape) noexcept
            {
                OperationError::s_customDeleter(static_cast<OperationError *>(shape));
            }

            void SubscribeToIoTCoreResponse::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                (void)payloadObject;
            }

            void SubscribeToIoTCoreResponse::s_loadFromJsonView(
                SubscribeToIoTCoreResponse &subscribeToIoTCoreResponse,
                const Crt::JsonView &jsonView) noexcept
            {
                (void)subscribeToIoTCoreResponse;
                (void)jsonView;
            }

            Crt::String SubscribeToIoTCoreResponse::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToIoTCoreResponse");
            }

            Crt::ScopedResource<OperationResponse> SubscribeToIoTCoreResponse::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToIoTCoreResponse> derivedResponse(
                    Crt::New<SubscribeToIoTCoreResponse>(allocator), SubscribeToIoTCoreResponse::s_customDeleter);
                SubscribeToIoTCoreResponse::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationResponse *>(derivedResponse.release());
                return Crt::ScopedResource<OperationResponse>(operationResponse, OperationResponse::s_customDeleter);
            }

            void SubscribeToIoTCoreResponse::s_customDeleter(SubscribeToIoTCoreResponse *shape) noexcept
            {
                OperationResponse::s_customDeleter(static_cast<OperationResponse *>(shape));
            }

            void SubscribeToIoTCoreRequest::SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept
            {
                if (m_topicName.has_value())
                {
                    payloadObject.WithString("topicName", m_topicName.value());
                }
                if (m_qos.has_value())
                {
                    payloadObject.WithString("qos", m_qos.value());
                }
            }

            void SubscribeToIoTCoreRequest::s_loadFromJsonView(
                SubscribeToIoTCoreRequest &subscribeToIoTCoreRequest,
                const Crt::JsonView &jsonView) noexcept
            {
                if (jsonView.ValueExists("topicName"))
                {
                    subscribeToIoTCoreRequest.m_topicName = Crt::Optional<Crt::String>(jsonView.GetString("topicName"));
                }
                if (jsonView.ValueExists("qos"))
                {
                    subscribeToIoTCoreRequest.m_qos = Crt::Optional<Crt::String>(jsonView.GetString("qos"));
                }
            }

            void SubscribeToIoTCoreRequest::SetQos(Crt::Optional<QOS> qos) noexcept
            {
                switch (qos.value())
                {
                    case QOS_AT_MOST_ONCE:
                        m_qos = Crt::String("0");
                        break;
                    case QOS_AT_LEAST_ONCE:
                        m_qos = Crt::String("1");
                        break;
                    default:
                        break;
                }
            }

            Crt::Optional<QOS> SubscribeToIoTCoreRequest::GetQos() noexcept
            {
                if (!m_qos.has_value())
                    return Crt::Optional<QOS>();
                if (m_qos.value() == Crt::String("0"))
                {
                    return Crt::Optional<QOS>(QOS_AT_MOST_ONCE);
                }
                if (m_qos.value() == Crt::String("1"))
                {
                    return Crt::Optional<QOS>(QOS_AT_LEAST_ONCE);
                }

                return Crt::Optional<QOS>();
            }

            Crt::String SubscribeToIoTCoreRequest::GetModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToIoTCoreRequest");
            }

            Crt::ScopedResource<OperationRequest> SubscribeToIoTCoreRequest::s_allocateFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) noexcept
            {
                Crt::String payload = {stringView.begin(), stringView.end()};
                Crt::JsonObject jsonObject(payload);
                Crt::JsonView jsonView(jsonObject);
                Crt::ScopedResource<SubscribeToIoTCoreRequest> derivedResponse(
                    Crt::New<SubscribeToIoTCoreRequest>(allocator), SubscribeToIoTCoreRequest::s_customDeleter);
                SubscribeToIoTCoreRequest::s_loadFromJsonView(*derivedResponse, jsonView);
                auto operationResponse = static_cast<OperationRequest *>(derivedResponse.release());
                return Crt::ScopedResource<OperationRequest>(operationResponse, OperationRequest::s_customDeleter);
            }

            void SubscribeToIoTCoreRequest::s_customDeleter(SubscribeToIoTCoreRequest *shape) noexcept
            {
                OperationRequest::s_customDeleter(static_cast<OperationRequest *>(shape));
            }

            void SubscribeToIoTCoreStreamHandler::OnStreamEvent(Crt::ScopedResource<OperationResponse> response)
            {
                OnStreamEvent(static_cast<IoTCoreMessage *>(response.get()));
            }

            bool SubscribeToIoTCoreStreamHandler::OnStreamError(
                Crt::ScopedResource<OperationError> operationError,
                RpcError rpcError)
            {
                if (operationError->GetModelName() == Crt::String("aws.greengrass#ServiceError"))
                {
                    return OnStreamError(static_cast<ServiceError *>(operationError.get()), rpcError);
                }
                if (operationError->GetModelName() == Crt::String("aws.greengrass#UnauthorizedError"))
                {
                    return OnStreamError(static_cast<UnauthorizedError *>(operationError.get()), rpcError);
                }
                return true;
            }

            SubscribeToIoTCoreOperationContext::SubscribeToIoTCoreOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> SubscribeToIoTCoreOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return SubscribeToIoTCoreResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> SubscribeToIoTCoreOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return IoTCoreMessage::s_allocateFromPayload(stringView, allocator);
            }

            Crt::String SubscribeToIoTCoreOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToIoTCoreRequest");
            }

            Crt::String SubscribeToIoTCoreOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToIoTCoreResponse");
            }

            Crt::Optional<Crt::String> SubscribeToIoTCoreOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::String("aws.greengrass#IoTCoreMessage");
            }

            Crt::String SubscribeToIoTCoreOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToIoTCore");
            }

            SubscribeToIoTCoreOperation::SubscribeToIoTCoreOperation(
                ClientConnection &connection,
                SubscribeToIoTCoreStreamHandler *streamHandler,
                const SubscribeToIoTCoreOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, streamHandler, operationContext, allocator)
            {
            }

            std::future<RpcError> SubscribeToIoTCoreOperation::Activate(
                const SubscribeToIoTCoreRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String SubscribeToIoTCoreOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            ResumeComponentOperationContext::ResumeComponentOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> ResumeComponentOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return ResumeComponentResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> ResumeComponentOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String ResumeComponentOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ResumeComponentRequest");
            }

            Crt::String ResumeComponentOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ResumeComponentResponse");
            }

            Crt::Optional<Crt::String> ResumeComponentOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String ResumeComponentOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#ResumeComponent");
            }

            ResumeComponentOperation::ResumeComponentOperation(
                ClientConnection &connection,
                const ResumeComponentOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> ResumeComponentOperation::Activate(
                const ResumeComponentRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String ResumeComponentOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            PublishToIoTCoreOperationContext::PublishToIoTCoreOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> PublishToIoTCoreOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return PublishToIoTCoreResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> PublishToIoTCoreOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String PublishToIoTCoreOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToIoTCoreRequest");
            }

            Crt::String PublishToIoTCoreOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToIoTCoreResponse");
            }

            Crt::Optional<Crt::String> PublishToIoTCoreOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String PublishToIoTCoreOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToIoTCore");
            }

            PublishToIoTCoreOperation::PublishToIoTCoreOperation(
                ClientConnection &connection,
                const PublishToIoTCoreOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> PublishToIoTCoreOperation::Activate(
                const PublishToIoTCoreRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String PublishToIoTCoreOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            void SubscribeToConfigurationUpdateStreamHandler::OnStreamEvent(
                Crt::ScopedResource<OperationResponse> response)
            {
                OnStreamEvent(static_cast<ConfigurationUpdateEvents *>(response.get()));
            }

            bool SubscribeToConfigurationUpdateStreamHandler::OnStreamError(
                Crt::ScopedResource<OperationError> operationError,
                RpcError rpcError)
            {
                if (operationError->GetModelName() == Crt::String("aws.greengrass#ServiceError"))
                {
                    return OnStreamError(static_cast<ServiceError *>(operationError.get()), rpcError);
                }
                if (operationError->GetModelName() == Crt::String("aws.greengrass#ResourceNotFoundError"))
                {
                    return OnStreamError(static_cast<ResourceNotFoundError *>(operationError.get()), rpcError);
                }
                return true;
            }

            SubscribeToConfigurationUpdateOperationContext::SubscribeToConfigurationUpdateOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> SubscribeToConfigurationUpdateOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return SubscribeToConfigurationUpdateResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> SubscribeToConfigurationUpdateOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return ConfigurationUpdateEvents::s_allocateFromPayload(stringView, allocator);
            }

            Crt::String SubscribeToConfigurationUpdateOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToConfigurationUpdateRequest");
            }

            Crt::String SubscribeToConfigurationUpdateOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToConfigurationUpdateResponse");
            }

            Crt::Optional<Crt::String> SubscribeToConfigurationUpdateOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::String("aws.greengrass#ConfigurationUpdateEvents");
            }

            Crt::String SubscribeToConfigurationUpdateOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToConfigurationUpdate");
            }

            SubscribeToConfigurationUpdateOperation::SubscribeToConfigurationUpdateOperation(
                ClientConnection &connection,
                SubscribeToConfigurationUpdateStreamHandler *streamHandler,
                const SubscribeToConfigurationUpdateOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, streamHandler, operationContext, allocator)
            {
            }

            std::future<RpcError> SubscribeToConfigurationUpdateOperation::Activate(
                const SubscribeToConfigurationUpdateRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String SubscribeToConfigurationUpdateOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            DeleteThingShadowOperationContext::DeleteThingShadowOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> DeleteThingShadowOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return DeleteThingShadowResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> DeleteThingShadowOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String DeleteThingShadowOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeleteThingShadowRequest");
            }

            Crt::String DeleteThingShadowOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeleteThingShadowResponse");
            }

            Crt::Optional<Crt::String> DeleteThingShadowOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String DeleteThingShadowOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#DeleteThingShadow");
            }

            DeleteThingShadowOperation::DeleteThingShadowOperation(
                ClientConnection &connection,
                const DeleteThingShadowOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> DeleteThingShadowOperation::Activate(
                const DeleteThingShadowRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String DeleteThingShadowOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            DeferComponentUpdateOperationContext::DeferComponentUpdateOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> DeferComponentUpdateOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return DeferComponentUpdateResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> DeferComponentUpdateOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String DeferComponentUpdateOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeferComponentUpdateRequest");
            }

            Crt::String DeferComponentUpdateOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#DeferComponentUpdateResponse");
            }

            Crt::Optional<Crt::String> DeferComponentUpdateOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String DeferComponentUpdateOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#DeferComponentUpdate");
            }

            DeferComponentUpdateOperation::DeferComponentUpdateOperation(
                ClientConnection &connection,
                const DeferComponentUpdateOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> DeferComponentUpdateOperation::Activate(
                const DeferComponentUpdateRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String DeferComponentUpdateOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            void SubscribeToValidateConfigurationUpdatesStreamHandler::OnStreamEvent(
                Crt::ScopedResource<OperationResponse> response)
            {
                OnStreamEvent(static_cast<ValidateConfigurationUpdateEvents *>(response.get()));
            }

            bool SubscribeToValidateConfigurationUpdatesStreamHandler::OnStreamError(
                Crt::ScopedResource<OperationError> operationError,
                RpcError rpcError)
            {
                if (operationError->GetModelName() == Crt::String("aws.greengrass#ServiceError"))
                {
                    return OnStreamError(static_cast<ServiceError *>(operationError.get()), rpcError);
                }
                return true;
            }

            SubscribeToValidateConfigurationUpdatesOperationContext::
                SubscribeToValidateConfigurationUpdatesOperationContext(
                    const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> SubscribeToValidateConfigurationUpdatesOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return SubscribeToValidateConfigurationUpdatesResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> SubscribeToValidateConfigurationUpdatesOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return ValidateConfigurationUpdateEvents::s_allocateFromPayload(stringView, allocator);
            }

            Crt::String SubscribeToValidateConfigurationUpdatesOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToValidateConfigurationUpdatesRequest");
            }

            Crt::String SubscribeToValidateConfigurationUpdatesOperationContext::GetInitialResponseModelName()
                const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToValidateConfigurationUpdatesResponse");
            }

            Crt::Optional<Crt::String> SubscribeToValidateConfigurationUpdatesOperationContext::
                GetStreamingResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateConfigurationUpdateEvents");
            }

            Crt::String SubscribeToValidateConfigurationUpdatesOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToValidateConfigurationUpdates");
            }

            SubscribeToValidateConfigurationUpdatesOperation::SubscribeToValidateConfigurationUpdatesOperation(
                ClientConnection &connection,
                SubscribeToValidateConfigurationUpdatesStreamHandler *streamHandler,
                const SubscribeToValidateConfigurationUpdatesOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, streamHandler, operationContext, allocator)
            {
            }

            std::future<RpcError> SubscribeToValidateConfigurationUpdatesOperation::Activate(
                const SubscribeToValidateConfigurationUpdatesRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String SubscribeToValidateConfigurationUpdatesOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            GetConfigurationOperationContext::GetConfigurationOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> GetConfigurationOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return GetConfigurationResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> GetConfigurationOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String GetConfigurationOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetConfigurationRequest");
            }

            Crt::String GetConfigurationOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetConfigurationResponse");
            }

            Crt::Optional<Crt::String> GetConfigurationOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String GetConfigurationOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#GetConfiguration");
            }

            GetConfigurationOperation::GetConfigurationOperation(
                ClientConnection &connection,
                const GetConfigurationOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> GetConfigurationOperation::Activate(
                const GetConfigurationRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String GetConfigurationOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            void SubscribeToTopicStreamHandler::OnStreamEvent(Crt::ScopedResource<OperationResponse> response)
            {
                OnStreamEvent(static_cast<SubscriptionResponseMessage *>(response.get()));
            }

            bool SubscribeToTopicStreamHandler::OnStreamError(
                Crt::ScopedResource<OperationError> operationError,
                RpcError rpcError)
            {
                if (operationError->GetModelName() == Crt::String("aws.greengrass#InvalidArgumentsError"))
                {
                    return OnStreamError(static_cast<InvalidArgumentsError *>(operationError.get()), rpcError);
                }
                if (operationError->GetModelName() == Crt::String("aws.greengrass#ServiceError"))
                {
                    return OnStreamError(static_cast<ServiceError *>(operationError.get()), rpcError);
                }
                if (operationError->GetModelName() == Crt::String("aws.greengrass#UnauthorizedError"))
                {
                    return OnStreamError(static_cast<UnauthorizedError *>(operationError.get()), rpcError);
                }
                return true;
            }

            SubscribeToTopicOperationContext::SubscribeToTopicOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> SubscribeToTopicOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return SubscribeToTopicResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> SubscribeToTopicOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return SubscriptionResponseMessage::s_allocateFromPayload(stringView, allocator);
            }

            Crt::String SubscribeToTopicOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopicRequest");
            }

            Crt::String SubscribeToTopicOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopicResponse");
            }

            Crt::Optional<Crt::String> SubscribeToTopicOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscriptionResponseMessage");
            }

            Crt::String SubscribeToTopicOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToTopic");
            }

            SubscribeToTopicOperation::SubscribeToTopicOperation(
                ClientConnection &connection,
                SubscribeToTopicStreamHandler *streamHandler,
                const SubscribeToTopicOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, streamHandler, operationContext, allocator)
            {
            }

            std::future<RpcError> SubscribeToTopicOperation::Activate(
                const SubscribeToTopicRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String SubscribeToTopicOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            GetComponentDetailsOperationContext::GetComponentDetailsOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> GetComponentDetailsOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return GetComponentDetailsResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> GetComponentDetailsOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String GetComponentDetailsOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetComponentDetailsRequest");
            }

            Crt::String GetComponentDetailsOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetComponentDetailsResponse");
            }

            Crt::Optional<Crt::String> GetComponentDetailsOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String GetComponentDetailsOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#GetComponentDetails");
            }

            GetComponentDetailsOperation::GetComponentDetailsOperation(
                ClientConnection &connection,
                const GetComponentDetailsOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> GetComponentDetailsOperation::Activate(
                const GetComponentDetailsRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String GetComponentDetailsOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            PublishToTopicOperationContext::PublishToTopicOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> PublishToTopicOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return PublishToTopicResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> PublishToTopicOperationContext::AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return nullptr;
            }

            Crt::String PublishToTopicOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopicRequest");
            }

            Crt::String PublishToTopicOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopicResponse");
            }

            Crt::Optional<Crt::String> PublishToTopicOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String PublishToTopicOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#PublishToTopic");
            }

            PublishToTopicOperation::PublishToTopicOperation(
                ClientConnection &connection,
                const PublishToTopicOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> PublishToTopicOperation::Activate(
                const PublishToTopicRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String PublishToTopicOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            ListComponentsOperationContext::ListComponentsOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> ListComponentsOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return ListComponentsResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> ListComponentsOperationContext::AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return nullptr;
            }

            Crt::String ListComponentsOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListComponentsRequest");
            }

            Crt::String ListComponentsOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListComponentsResponse");
            }

            Crt::Optional<Crt::String> ListComponentsOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String ListComponentsOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#ListComponents");
            }

            ListComponentsOperation::ListComponentsOperation(
                ClientConnection &connection,
                const ListComponentsOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> ListComponentsOperation::Activate(
                const ListComponentsRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String ListComponentsOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            CreateDebugPasswordOperationContext::CreateDebugPasswordOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> CreateDebugPasswordOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return CreateDebugPasswordResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> CreateDebugPasswordOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String CreateDebugPasswordOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateDebugPasswordRequest");
            }

            Crt::String CreateDebugPasswordOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateDebugPasswordResponse");
            }

            Crt::Optional<Crt::String> CreateDebugPasswordOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String CreateDebugPasswordOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateDebugPassword");
            }

            CreateDebugPasswordOperation::CreateDebugPasswordOperation(
                ClientConnection &connection,
                const CreateDebugPasswordOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> CreateDebugPasswordOperation::Activate(
                const CreateDebugPasswordRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String CreateDebugPasswordOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            GetThingShadowOperationContext::GetThingShadowOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> GetThingShadowOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return GetThingShadowResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> GetThingShadowOperationContext::AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return nullptr;
            }

            Crt::String GetThingShadowOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetThingShadowRequest");
            }

            Crt::String GetThingShadowOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetThingShadowResponse");
            }

            Crt::Optional<Crt::String> GetThingShadowOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String GetThingShadowOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#GetThingShadow");
            }

            GetThingShadowOperation::GetThingShadowOperation(
                ClientConnection &connection,
                const GetThingShadowOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> GetThingShadowOperation::Activate(
                const GetThingShadowRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String GetThingShadowOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            SendConfigurationValidityReportOperationContext::SendConfigurationValidityReportOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> SendConfigurationValidityReportOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return SendConfigurationValidityReportResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> SendConfigurationValidityReportOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String SendConfigurationValidityReportOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SendConfigurationValidityReportRequest");
            }

            Crt::String SendConfigurationValidityReportOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SendConfigurationValidityReportResponse");
            }

            Crt::Optional<Crt::String> SendConfigurationValidityReportOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String SendConfigurationValidityReportOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#SendConfigurationValidityReport");
            }

            SendConfigurationValidityReportOperation::SendConfigurationValidityReportOperation(
                ClientConnection &connection,
                const SendConfigurationValidityReportOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> SendConfigurationValidityReportOperation::Activate(
                const SendConfigurationValidityReportRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String SendConfigurationValidityReportOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            UpdateThingShadowOperationContext::UpdateThingShadowOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> UpdateThingShadowOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return UpdateThingShadowResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> UpdateThingShadowOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String UpdateThingShadowOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateThingShadowRequest");
            }

            Crt::String UpdateThingShadowOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateThingShadowResponse");
            }

            Crt::Optional<Crt::String> UpdateThingShadowOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String UpdateThingShadowOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateThingShadow");
            }

            UpdateThingShadowOperation::UpdateThingShadowOperation(
                ClientConnection &connection,
                const UpdateThingShadowOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> UpdateThingShadowOperation::Activate(
                const UpdateThingShadowRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String UpdateThingShadowOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            UpdateConfigurationOperationContext::UpdateConfigurationOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> UpdateConfigurationOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return UpdateConfigurationResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> UpdateConfigurationOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String UpdateConfigurationOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateConfigurationRequest");
            }

            Crt::String UpdateConfigurationOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateConfigurationResponse");
            }

            Crt::Optional<Crt::String> UpdateConfigurationOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String UpdateConfigurationOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateConfiguration");
            }

            UpdateConfigurationOperation::UpdateConfigurationOperation(
                ClientConnection &connection,
                const UpdateConfigurationOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> UpdateConfigurationOperation::Activate(
                const UpdateConfigurationRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String UpdateConfigurationOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            ValidateAuthorizationTokenOperationContext::ValidateAuthorizationTokenOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> ValidateAuthorizationTokenOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return ValidateAuthorizationTokenResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> ValidateAuthorizationTokenOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String ValidateAuthorizationTokenOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateAuthorizationTokenRequest");
            }

            Crt::String ValidateAuthorizationTokenOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateAuthorizationTokenResponse");
            }

            Crt::Optional<Crt::String> ValidateAuthorizationTokenOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String ValidateAuthorizationTokenOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#ValidateAuthorizationToken");
            }

            ValidateAuthorizationTokenOperation::ValidateAuthorizationTokenOperation(
                ClientConnection &connection,
                const ValidateAuthorizationTokenOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> ValidateAuthorizationTokenOperation::Activate(
                const ValidateAuthorizationTokenRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String ValidateAuthorizationTokenOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            RestartComponentOperationContext::RestartComponentOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> RestartComponentOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return RestartComponentResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> RestartComponentOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String RestartComponentOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#RestartComponentRequest");
            }

            Crt::String RestartComponentOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#RestartComponentResponse");
            }

            Crt::Optional<Crt::String> RestartComponentOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String RestartComponentOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#RestartComponent");
            }

            RestartComponentOperation::RestartComponentOperation(
                ClientConnection &connection,
                const RestartComponentOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> RestartComponentOperation::Activate(
                const RestartComponentRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String RestartComponentOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            GetLocalDeploymentStatusOperationContext::GetLocalDeploymentStatusOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> GetLocalDeploymentStatusOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return GetLocalDeploymentStatusResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> GetLocalDeploymentStatusOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String GetLocalDeploymentStatusOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetLocalDeploymentStatusRequest");
            }

            Crt::String GetLocalDeploymentStatusOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetLocalDeploymentStatusResponse");
            }

            Crt::Optional<Crt::String> GetLocalDeploymentStatusOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String GetLocalDeploymentStatusOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#GetLocalDeploymentStatus");
            }

            GetLocalDeploymentStatusOperation::GetLocalDeploymentStatusOperation(
                ClientConnection &connection,
                const GetLocalDeploymentStatusOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> GetLocalDeploymentStatusOperation::Activate(
                const GetLocalDeploymentStatusRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String GetLocalDeploymentStatusOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            GetSecretValueOperationContext::GetSecretValueOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> GetSecretValueOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return GetSecretValueResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> GetSecretValueOperationContext::AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return nullptr;
            }

            Crt::String GetSecretValueOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetSecretValueRequest");
            }

            Crt::String GetSecretValueOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#GetSecretValueResponse");
            }

            Crt::Optional<Crt::String> GetSecretValueOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String GetSecretValueOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#GetSecretValue");
            }

            GetSecretValueOperation::GetSecretValueOperation(
                ClientConnection &connection,
                const GetSecretValueOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> GetSecretValueOperation::Activate(
                const GetSecretValueRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String GetSecretValueOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            UpdateStateOperationContext::UpdateStateOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> UpdateStateOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return UpdateStateResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> UpdateStateOperationContext::AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return nullptr;
            }

            Crt::String UpdateStateOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateStateRequest");
            }

            Crt::String UpdateStateOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateStateResponse");
            }

            Crt::Optional<Crt::String> UpdateStateOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String UpdateStateOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#UpdateState");
            }

            UpdateStateOperation::UpdateStateOperation(
                ClientConnection &connection,
                const UpdateStateOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> UpdateStateOperation::Activate(
                const UpdateStateRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String UpdateStateOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            ListNamedShadowsForThingOperationContext::ListNamedShadowsForThingOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> ListNamedShadowsForThingOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return ListNamedShadowsForThingResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> ListNamedShadowsForThingOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String ListNamedShadowsForThingOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListNamedShadowsForThingRequest");
            }

            Crt::String ListNamedShadowsForThingOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListNamedShadowsForThingResponse");
            }

            Crt::Optional<Crt::String> ListNamedShadowsForThingOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String ListNamedShadowsForThingOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#ListNamedShadowsForThing");
            }

            ListNamedShadowsForThingOperation::ListNamedShadowsForThingOperation(
                ClientConnection &connection,
                const ListNamedShadowsForThingOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> ListNamedShadowsForThingOperation::Activate(
                const ListNamedShadowsForThingRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String ListNamedShadowsForThingOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            void SubscribeToComponentUpdatesStreamHandler::OnStreamEvent(
                Crt::ScopedResource<OperationResponse> response)
            {
                OnStreamEvent(static_cast<ComponentUpdatePolicyEvents *>(response.get()));
            }

            bool SubscribeToComponentUpdatesStreamHandler::OnStreamError(
                Crt::ScopedResource<OperationError> operationError,
                RpcError rpcError)
            {
                if (operationError->GetModelName() == Crt::String("aws.greengrass#ServiceError"))
                {
                    return OnStreamError(static_cast<ServiceError *>(operationError.get()), rpcError);
                }
                if (operationError->GetModelName() == Crt::String("aws.greengrass#ResourceNotFoundError"))
                {
                    return OnStreamError(static_cast<ResourceNotFoundError *>(operationError.get()), rpcError);
                }
                return true;
            }

            SubscribeToComponentUpdatesOperationContext::SubscribeToComponentUpdatesOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> SubscribeToComponentUpdatesOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return SubscribeToComponentUpdatesResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> SubscribeToComponentUpdatesOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return ComponentUpdatePolicyEvents::s_allocateFromPayload(stringView, allocator);
            }

            Crt::String SubscribeToComponentUpdatesOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToComponentUpdatesRequest");
            }

            Crt::String SubscribeToComponentUpdatesOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToComponentUpdatesResponse");
            }

            Crt::Optional<Crt::String> SubscribeToComponentUpdatesOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::String("aws.greengrass#ComponentUpdatePolicyEvents");
            }

            Crt::String SubscribeToComponentUpdatesOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#SubscribeToComponentUpdates");
            }

            SubscribeToComponentUpdatesOperation::SubscribeToComponentUpdatesOperation(
                ClientConnection &connection,
                SubscribeToComponentUpdatesStreamHandler *streamHandler,
                const SubscribeToComponentUpdatesOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, streamHandler, operationContext, allocator)
            {
            }

            std::future<RpcError> SubscribeToComponentUpdatesOperation::Activate(
                const SubscribeToComponentUpdatesRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String SubscribeToComponentUpdatesOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            ListLocalDeploymentsOperationContext::ListLocalDeploymentsOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> ListLocalDeploymentsOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return ListLocalDeploymentsResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> ListLocalDeploymentsOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String ListLocalDeploymentsOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListLocalDeploymentsRequest");
            }

            Crt::String ListLocalDeploymentsOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#ListLocalDeploymentsResponse");
            }

            Crt::Optional<Crt::String> ListLocalDeploymentsOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String ListLocalDeploymentsOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#ListLocalDeployments");
            }

            ListLocalDeploymentsOperation::ListLocalDeploymentsOperation(
                ClientConnection &connection,
                const ListLocalDeploymentsOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> ListLocalDeploymentsOperation::Activate(
                const ListLocalDeploymentsRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String ListLocalDeploymentsOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            StopComponentOperationContext::StopComponentOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> StopComponentOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return StopComponentResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> StopComponentOperationContext::AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return nullptr;
            }

            Crt::String StopComponentOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#StopComponentRequest");
            }

            Crt::String StopComponentOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#StopComponentResponse");
            }

            Crt::Optional<Crt::String> StopComponentOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String StopComponentOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#StopComponent");
            }

            StopComponentOperation::StopComponentOperation(
                ClientConnection &connection,
                const StopComponentOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> StopComponentOperation::Activate(
                const StopComponentRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String StopComponentOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            PauseComponentOperationContext::PauseComponentOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> PauseComponentOperationContext::AllocateInitialResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return PauseComponentResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> PauseComponentOperationContext::AllocateStreamingResponseFromPayload(
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept
            {
                return nullptr;
            }

            Crt::String PauseComponentOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PauseComponentRequest");
            }

            Crt::String PauseComponentOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#PauseComponentResponse");
            }

            Crt::Optional<Crt::String> PauseComponentOperationContext::GetStreamingResponseModelName() const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String PauseComponentOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#PauseComponent");
            }

            PauseComponentOperation::PauseComponentOperation(
                ClientConnection &connection,
                const PauseComponentOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> PauseComponentOperation::Activate(
                const PauseComponentRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String PauseComponentOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            CreateLocalDeploymentOperationContext::CreateLocalDeploymentOperationContext(
                const GreengrassServiceModel &serviceModel) noexcept
                : OperationModelContext(serviceModel)
            {
            }

            Crt::ScopedResource<OperationResponse> CreateLocalDeploymentOperationContext::
                AllocateInitialResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator) const noexcept
            {
                return CreateLocalDeploymentResponse::s_allocateFromPayload(stringView, allocator);
            }

            Crt::ScopedResource<OperationResponse> CreateLocalDeploymentOperationContext::
                AllocateStreamingResponseFromPayload(Crt::StringView stringView, Crt::Allocator *allocator)
                    const noexcept
            {
                return nullptr;
            }

            Crt::String CreateLocalDeploymentOperationContext::GetRequestModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateLocalDeploymentRequest");
            }

            Crt::String CreateLocalDeploymentOperationContext::GetInitialResponseModelName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateLocalDeploymentResponse");
            }

            Crt::Optional<Crt::String> CreateLocalDeploymentOperationContext::GetStreamingResponseModelName()
                const noexcept
            {
                return Crt::Optional<Crt::String>();
            }

            Crt::String CreateLocalDeploymentOperationContext::GetOperationName() const noexcept
            {
                return Crt::String("aws.greengrass#CreateLocalDeployment");
            }

            CreateLocalDeploymentOperation::CreateLocalDeploymentOperation(
                ClientConnection &connection,
                const CreateLocalDeploymentOperationContext &operationContext,
                Crt::Allocator *allocator) noexcept
                : ClientOperation(connection, nullptr, operationContext, allocator)
            {
            }

            std::future<RpcError> CreateLocalDeploymentOperation::Activate(
                const CreateLocalDeploymentRequest &request,
                OnMessageFlushCallback onMessageFlushCallback) noexcept
            {
                return ClientOperation::Activate(
                    static_cast<const OperationRequest *>(&request), onMessageFlushCallback);
            }

            Crt::String CreateLocalDeploymentOperation::GetModelName() const noexcept
            {
                return m_operationModelContext.GetOperationName();
            }

            GreengrassServiceModel::GreengrassServiceModel() noexcept
                : m_subscribeToIoTCoreOperationContext(*this), m_resumeComponentOperationContext(*this),
                  m_publishToIoTCoreOperationContext(*this), m_subscribeToConfigurationUpdateOperationContext(*this),
                  m_deleteThingShadowOperationContext(*this), m_deferComponentUpdateOperationContext(*this),
                  m_subscribeToValidateConfigurationUpdatesOperationContext(*this),
                  m_getConfigurationOperationContext(*this), m_subscribeToTopicOperationContext(*this),
                  m_getComponentDetailsOperationContext(*this), m_publishToTopicOperationContext(*this),
                  m_listComponentsOperationContext(*this), m_createDebugPasswordOperationContext(*this),
                  m_getThingShadowOperationContext(*this), m_sendConfigurationValidityReportOperationContext(*this),
                  m_updateThingShadowOperationContext(*this), m_updateConfigurationOperationContext(*this),
                  m_validateAuthorizationTokenOperationContext(*this), m_restartComponentOperationContext(*this),
                  m_getLocalDeploymentStatusOperationContext(*this), m_getSecretValueOperationContext(*this),
                  m_updateStateOperationContext(*this), m_listNamedShadowsForThingOperationContext(*this),
                  m_subscribeToComponentUpdatesOperationContext(*this), m_listLocalDeploymentsOperationContext(*this),
                  m_stopComponentOperationContext(*this), m_pauseComponentOperationContext(*this),
                  m_createLocalDeploymentOperationContext(*this)
            {
            }

            Crt::ScopedResource<OperationError> GreengrassServiceModel::AllocateOperationErrorFromPayload(
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

            void GreengrassServiceModel::AssignModelNameToErrorResponse(
                Crt::String modelName,
                ErrorResponseFactory factory) noexcept
            {
                m_modelNameToErrorResponse[modelName] = factory;
            }
        } // namespace Ipc
    }     // namespace Eventstreamrpc
} // namespace Aws
