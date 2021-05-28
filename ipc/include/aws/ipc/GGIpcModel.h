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
        namespace Ipc
        {
            class GreengrassIpcClient;
            class GreengrassServiceModel;
            class LinuxSystemResourceLimits : public AbstractShapeBase
            {
              public:
                explicit LinuxSystemResourceLimits(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                LinuxSystemResourceLimits(const LinuxSystemResourceLimits &) = default;

                void SetMemory(const Crt::Optional<int> &memory) noexcept { m_memory = memory; }
                const Crt::Optional<int> &GetMemory() noexcept { return m_memory; }

                void SetCpu(const Crt::Optional<double> &cpu) noexcept { m_cpu = cpu; }
                const Crt::Optional<double> &GetCpu() noexcept { return m_cpu; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(LinuxSystemResourceLimits &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(LinuxSystemResourceLimits *) noexcept;
                /* This needs to be defined so that `LinuxSystemResourceLimits` can be used as a key in maps. */
                bool operator<(const LinuxSystemResourceLimits &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<int> m_memory;
                Crt::Optional<double> m_cpu;
            };

            class SystemResourceLimits : public AbstractShapeBase
            {
              public:
                explicit SystemResourceLimits(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SystemResourceLimits(const SystemResourceLimits &) = default;

                void SetLinuxSystemResourceLimits(
                    const Crt::Optional<LinuxSystemResourceLimits> &linuxSystemResourceLimits) noexcept
                {
                    m_linuxSystemResourceLimits = linuxSystemResourceLimits;
                }
                const Crt::Optional<LinuxSystemResourceLimits> &GetLinuxSystemResourceLimits() noexcept
                {
                    return m_linuxSystemResourceLimits;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SystemResourceLimits &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SystemResourceLimits *) noexcept;
                /* This needs to be defined so that `SystemResourceLimits` can be used as a key in maps. */
                bool operator<(const SystemResourceLimits &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<LinuxSystemResourceLimits> m_linuxSystemResourceLimits;
            };

            class RunWithInfo : public AbstractShapeBase
            {
              public:
                explicit RunWithInfo(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator) {}
                RunWithInfo(const RunWithInfo &) = default;

                void SetPosixUser(const Crt::Optional<Crt::String> &posixUser) noexcept { m_posixUser = posixUser; }
                const Crt::Optional<Crt::String> &GetPosixUser() noexcept { return m_posixUser; }

                void SetSystemResourceLimits(const Crt::Optional<SystemResourceLimits> &systemResourceLimits) noexcept
                {
                    m_systemResourceLimits = systemResourceLimits;
                }
                const Crt::Optional<SystemResourceLimits> &GetSystemResourceLimits() noexcept
                {
                    return m_systemResourceLimits;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(RunWithInfo &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(RunWithInfo *) noexcept;
                /* This needs to be defined so that `RunWithInfo` can be used as a key in maps. */
                bool operator<(const RunWithInfo &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_posixUser;
                Crt::Optional<SystemResourceLimits> m_systemResourceLimits;
            };

            class PostComponentUpdateEvent : public AbstractShapeBase
            {
              public:
                explicit PostComponentUpdateEvent(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PostComponentUpdateEvent(const PostComponentUpdateEvent &) = default;

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PostComponentUpdateEvent &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PostComponentUpdateEvent *) noexcept;
                /* This needs to be defined so that `PostComponentUpdateEvent` can be used as a key in maps. */
                bool operator<(const PostComponentUpdateEvent &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_deploymentId;
            };

            class PreComponentUpdateEvent : public AbstractShapeBase
            {
              public:
                explicit PreComponentUpdateEvent(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PreComponentUpdateEvent(const PreComponentUpdateEvent &) = default;

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SetIsGgcRestarting(const Crt::Optional<bool> &isGgcRestarting) noexcept
                {
                    m_isGgcRestarting = isGgcRestarting;
                }
                const Crt::Optional<bool> &GetIsGgcRestarting() noexcept { return m_isGgcRestarting; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PreComponentUpdateEvent &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PreComponentUpdateEvent *) noexcept;
                /* This needs to be defined so that `PreComponentUpdateEvent` can be used as a key in maps. */
                bool operator<(const PreComponentUpdateEvent &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_deploymentId;
                Crt::Optional<bool> m_isGgcRestarting;
            };

            enum DeploymentStatus
            {
                DEPLOYMENT_STATUS_QUEUED,
                DEPLOYMENT_STATUS_IN_PROGRESS,
                DEPLOYMENT_STATUS_SUCCEEDED,
                DEPLOYMENT_STATUS_FAILED
            };

            enum ConfigurationValidityStatus
            {
                CONFIGURATION_VALIDITY_STATUS_ACCEPTED,
                CONFIGURATION_VALIDITY_STATUS_REJECTED
            };

            enum LifecycleState
            {
                LIFECYCLE_STATE_RUNNING,
                LIFECYCLE_STATE_ERRORED,
                LIFECYCLE_STATE_NEW,
                LIFECYCLE_STATE_FINISHED,
                LIFECYCLE_STATE_INSTALLED,
                LIFECYCLE_STATE_BROKEN,
                LIFECYCLE_STATE_STARTING,
                LIFECYCLE_STATE_STOPPING
            };

            class BinaryMessage : public AbstractShapeBase
            {
              public:
                explicit BinaryMessage(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator)
                {
                }
                BinaryMessage(const BinaryMessage &) = default;

                void SetMessage(const Crt::Optional<Crt::Vector<uint8_t>> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(BinaryMessage &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(BinaryMessage *) noexcept;
                /* This needs to be defined so that `BinaryMessage` can be used as a key in maps. */
                bool operator<(const BinaryMessage &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<uint8_t>> m_message;
            };

            class JsonMessage : public AbstractShapeBase
            {
              public:
                explicit JsonMessage(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator) {}
                JsonMessage(const JsonMessage &) = default;

                void SetMessage(const Crt::Optional<Crt::JsonObject> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::JsonObject> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(JsonMessage &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(JsonMessage *) noexcept;
                /* This needs to be defined so that `JsonMessage` can be used as a key in maps. */
                bool operator<(const JsonMessage &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::JsonObject> m_message;
            };

            class ValidateConfigurationUpdateEvent : public AbstractShapeBase
            {
              public:
                explicit ValidateConfigurationUpdateEvent(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ValidateConfigurationUpdateEvent(const ValidateConfigurationUpdateEvent &) = default;

                void SetConfiguration(const Crt::Optional<Crt::JsonObject> &configuration) noexcept
                {
                    m_configuration = configuration;
                }
                const Crt::Optional<Crt::JsonObject> &GetConfiguration() noexcept { return m_configuration; }

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ValidateConfigurationUpdateEvent &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ValidateConfigurationUpdateEvent *) noexcept;
                /* This needs to be defined so that `ValidateConfigurationUpdateEvent` can be used as a key in maps. */
                bool operator<(const ValidateConfigurationUpdateEvent &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::JsonObject> m_configuration;
                Crt::Optional<Crt::String> m_deploymentId;
            };

            class ConfigurationUpdateEvent : public AbstractShapeBase
            {
              public:
                explicit ConfigurationUpdateEvent(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ConfigurationUpdateEvent(const ConfigurationUpdateEvent &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SetKeyPath(const Crt::Optional<Crt::Vector<Crt::String>> &keyPath) noexcept
                {
                    m_keyPath = keyPath;
                }
                const Crt::Optional<Crt::Vector<Crt::String>> &GetKeyPath() noexcept { return m_keyPath; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ConfigurationUpdateEvent &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ConfigurationUpdateEvent *) noexcept;
                /* This needs to be defined so that `ConfigurationUpdateEvent` can be used as a key in maps. */
                bool operator<(const ConfigurationUpdateEvent &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
                Crt::Optional<Crt::Vector<Crt::String>> m_keyPath;
            };

            class MQTTMessage : public AbstractShapeBase
            {
              public:
                explicit MQTTMessage(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator) {}
                MQTTMessage(const MQTTMessage &) = default;

                void SetTopicName(const Crt::Optional<Crt::String> &topicName) noexcept { m_topicName = topicName; }
                const Crt::Optional<Crt::String> &GetTopicName() noexcept { return m_topicName; }

                void SetPayload(const Crt::Optional<Crt::Vector<uint8_t>> &payload) noexcept { m_payload = payload; }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetPayload() noexcept { return m_payload; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(MQTTMessage &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(MQTTMessage *) noexcept;
                /* This needs to be defined so that `MQTTMessage` can be used as a key in maps. */
                bool operator<(const MQTTMessage &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_topicName;
                Crt::Optional<Crt::Vector<uint8_t>> m_payload;
            };

            class ComponentUpdatePolicyEvents : public OperationResponse
            {
              public:
                explicit ComponentUpdatePolicyEvents(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ComponentUpdatePolicyEvents(const ComponentUpdatePolicyEvents &) = default;

                void SetPreUpdateEvent(const Crt::Optional<PreComponentUpdateEvent> &preUpdateEvent) noexcept
                {
                    m_preUpdateEvent = preUpdateEvent;
                }
                const Crt::Optional<PreComponentUpdateEvent> &GetPreUpdateEvent() noexcept { return m_preUpdateEvent; }

                void SetPostUpdateEvent(const Crt::Optional<PostComponentUpdateEvent> &postUpdateEvent) noexcept
                {
                    m_postUpdateEvent = postUpdateEvent;
                }
                const Crt::Optional<PostComponentUpdateEvent> &GetPostUpdateEvent() noexcept
                {
                    return m_postUpdateEvent;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ComponentUpdatePolicyEvents &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ComponentUpdatePolicyEvents *) noexcept;
                /* This needs to be defined so that `ComponentUpdatePolicyEvents` can be used as a key in maps. */
                bool operator<(const ComponentUpdatePolicyEvents &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<PreComponentUpdateEvent> m_preUpdateEvent;
                Crt::Optional<PostComponentUpdateEvent> m_postUpdateEvent;
            };

            enum ReportedLifecycleState
            {
                REPORTED_LIFECYCLE_STATE_RUNNING,
                REPORTED_LIFECYCLE_STATE_ERRORED
            };

            class SecretValue : public AbstractShapeBase
            {
              public:
                explicit SecretValue(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator) {}
                SecretValue(const SecretValue &) = default;

                void SetSecretString(const Crt::Optional<Crt::String> &secretString) noexcept
                {
                    m_secretString = secretString;
                }
                const Crt::Optional<Crt::String> &GetSecretString() noexcept { return m_secretString; }

                void SetSecretBinary(const Crt::Optional<Crt::Vector<uint8_t>> &secretBinary) noexcept
                {
                    m_secretBinary = secretBinary;
                }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetSecretBinary() noexcept { return m_secretBinary; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SecretValue &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SecretValue *) noexcept;
                /* This needs to be defined so that `SecretValue` can be used as a key in maps. */
                bool operator<(const SecretValue &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_secretString;
                Crt::Optional<Crt::Vector<uint8_t>> m_secretBinary;
            };

            class LocalDeployment : public AbstractShapeBase
            {
              public:
                explicit LocalDeployment(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator)
                {
                }
                LocalDeployment(const LocalDeployment &) = default;

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SetStatus(const Crt::Optional<Crt::String> &status) noexcept { m_status = status; }
                const Crt::Optional<Crt::String> &GetStatus() noexcept { return m_status; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(LocalDeployment &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(LocalDeployment *) noexcept;
                /* This needs to be defined so that `LocalDeployment` can be used as a key in maps. */
                bool operator<(const LocalDeployment &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_deploymentId;
                Crt::Optional<Crt::String> m_status;
            };

            enum RequestStatus
            {
                REQUEST_STATUS_SUCCEEDED,
                REQUEST_STATUS_FAILED
            };

            class ConfigurationValidityReport : public AbstractShapeBase
            {
              public:
                explicit ConfigurationValidityReport(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ConfigurationValidityReport(const ConfigurationValidityReport &) = default;

                void SetStatus(const Crt::Optional<Crt::String> &status) noexcept { m_status = status; }
                const Crt::Optional<Crt::String> &GetStatus() noexcept { return m_status; }

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ConfigurationValidityReport &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ConfigurationValidityReport *) noexcept;
                /* This needs to be defined so that `ConfigurationValidityReport` can be used as a key in maps. */
                bool operator<(const ConfigurationValidityReport &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_status;
                Crt::Optional<Crt::String> m_deploymentId;
                Crt::Optional<Crt::String> m_message;
            };

            class PublishMessage : public AbstractShapeBase
            {
              public:
                explicit PublishMessage(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator)
                {
                }
                PublishMessage(const PublishMessage &) = default;

                void SetJsonMessage(const Crt::Optional<JsonMessage> &jsonMessage) noexcept
                {
                    m_jsonMessage = jsonMessage;
                }
                const Crt::Optional<JsonMessage> &GetJsonMessage() noexcept { return m_jsonMessage; }

                void SetBinaryMessage(const Crt::Optional<BinaryMessage> &binaryMessage) noexcept
                {
                    m_binaryMessage = binaryMessage;
                }
                const Crt::Optional<BinaryMessage> &GetBinaryMessage() noexcept { return m_binaryMessage; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PublishMessage &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PublishMessage *) noexcept;
                /* This needs to be defined so that `PublishMessage` can be used as a key in maps. */
                bool operator<(const PublishMessage &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<JsonMessage> m_jsonMessage;
                Crt::Optional<BinaryMessage> m_binaryMessage;
            };

            class ComponentDetails : public AbstractShapeBase
            {
              public:
                explicit ComponentDetails(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ComponentDetails(const ComponentDetails &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SetVersion(const Crt::Optional<Crt::String> &version) noexcept { m_version = version; }
                const Crt::Optional<Crt::String> &GetVersion() noexcept { return m_version; }

                void SetState(const Crt::Optional<Crt::String> &state) noexcept { m_state = state; }
                const Crt::Optional<Crt::String> &GetState() noexcept { return m_state; }

                void SetConfiguration(const Crt::Optional<Crt::JsonObject> &configuration) noexcept
                {
                    m_configuration = configuration;
                }
                const Crt::Optional<Crt::JsonObject> &GetConfiguration() noexcept { return m_configuration; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ComponentDetails &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<AbstractShapeBase> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ComponentDetails *) noexcept;
                /* This needs to be defined so that `ComponentDetails` can be used as a key in maps. */
                bool operator<(const ComponentDetails &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
                Crt::Optional<Crt::String> m_version;
                Crt::Optional<Crt::String> m_state;
                Crt::Optional<Crt::JsonObject> m_configuration;
            };

            class SubscriptionResponseMessage : public OperationResponse
            {
              public:
                explicit SubscriptionResponseMessage(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscriptionResponseMessage(const SubscriptionResponseMessage &) = default;

                void SetJsonMessage(const Crt::Optional<JsonMessage> &jsonMessage) noexcept
                {
                    m_jsonMessage = jsonMessage;
                }
                const Crt::Optional<JsonMessage> &GetJsonMessage() noexcept { return m_jsonMessage; }

                void SetBinaryMessage(const Crt::Optional<BinaryMessage> &binaryMessage) noexcept
                {
                    m_binaryMessage = binaryMessage;
                }
                const Crt::Optional<BinaryMessage> &GetBinaryMessage() noexcept { return m_binaryMessage; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscriptionResponseMessage &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscriptionResponseMessage *) noexcept;
                /* This needs to be defined so that `SubscriptionResponseMessage` can be used as a key in maps. */
                bool operator<(const SubscriptionResponseMessage &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<JsonMessage> m_jsonMessage;
                Crt::Optional<BinaryMessage> m_binaryMessage;
            };

            class ValidateConfigurationUpdateEvents : public OperationResponse
            {
              public:
                explicit ValidateConfigurationUpdateEvents(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ValidateConfigurationUpdateEvents(const ValidateConfigurationUpdateEvents &) = default;

                void SetValidateConfigurationUpdateEvent(
                    const Crt::Optional<ValidateConfigurationUpdateEvent> &validateConfigurationUpdateEvent) noexcept
                {
                    m_validateConfigurationUpdateEvent = validateConfigurationUpdateEvent;
                }
                const Crt::Optional<ValidateConfigurationUpdateEvent> &GetValidateConfigurationUpdateEvent() noexcept
                {
                    return m_validateConfigurationUpdateEvent;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ValidateConfigurationUpdateEvents &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ValidateConfigurationUpdateEvents *) noexcept;
                /* This needs to be defined so that `ValidateConfigurationUpdateEvents` can be used as a key in maps. */
                bool operator<(const ValidateConfigurationUpdateEvents &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<ValidateConfigurationUpdateEvent> m_validateConfigurationUpdateEvent;
            };

            class ConfigurationUpdateEvents : public OperationResponse
            {
              public:
                explicit ConfigurationUpdateEvents(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ConfigurationUpdateEvents(const ConfigurationUpdateEvents &) = default;

                void SetConfigurationUpdateEvent(
                    const Crt::Optional<ConfigurationUpdateEvent> &configurationUpdateEvent) noexcept
                {
                    m_configurationUpdateEvent = configurationUpdateEvent;
                }
                const Crt::Optional<ConfigurationUpdateEvent> &GetConfigurationUpdateEvent() noexcept
                {
                    return m_configurationUpdateEvent;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ConfigurationUpdateEvents &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ConfigurationUpdateEvents *) noexcept;
                /* This needs to be defined so that `ConfigurationUpdateEvents` can be used as a key in maps. */
                bool operator<(const ConfigurationUpdateEvents &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<ConfigurationUpdateEvent> m_configurationUpdateEvent;
            };

            class IoTCoreMessage : public OperationResponse
            {
              public:
                explicit IoTCoreMessage(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator)
                {
                }
                IoTCoreMessage(const IoTCoreMessage &) = default;

                void SetMessage(const Crt::Optional<MQTTMessage> &message) noexcept { m_message = message; }
                const Crt::Optional<MQTTMessage> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(IoTCoreMessage &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(IoTCoreMessage *) noexcept;
                /* This needs to be defined so that `IoTCoreMessage` can be used as a key in maps. */
                bool operator<(const IoTCoreMessage &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<MQTTMessage> m_message;
            };

            enum QOS
            {
                QOS_AT_MOST_ONCE,
                QOS_AT_LEAST_ONCE
            };

            class InvalidArtifactsDirectoryPathError : public OperationError
            {
              public:
                explicit InvalidArtifactsDirectoryPathError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                InvalidArtifactsDirectoryPathError(const InvalidArtifactsDirectoryPathError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(InvalidArtifactsDirectoryPathError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(InvalidArtifactsDirectoryPathError *) noexcept;
                /* This needs to be defined so that `InvalidArtifactsDirectoryPathError` can be used as a key in maps.
                 */
                bool operator<(const InvalidArtifactsDirectoryPathError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class InvalidRecipeDirectoryPathError : public OperationError
            {
              public:
                explicit InvalidRecipeDirectoryPathError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                InvalidRecipeDirectoryPathError(const InvalidRecipeDirectoryPathError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(InvalidRecipeDirectoryPathError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(InvalidRecipeDirectoryPathError *) noexcept;
                /* This needs to be defined so that `InvalidRecipeDirectoryPathError` can be used as a key in maps. */
                bool operator<(const InvalidRecipeDirectoryPathError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class CreateLocalDeploymentResponse : public OperationResponse
            {
              public:
                explicit CreateLocalDeploymentResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                CreateLocalDeploymentResponse(const CreateLocalDeploymentResponse &) = default;

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(CreateLocalDeploymentResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(CreateLocalDeploymentResponse *) noexcept;
                /* This needs to be defined so that `CreateLocalDeploymentResponse` can be used as a key in maps. */
                bool operator<(const CreateLocalDeploymentResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_deploymentId;
            };

            class CreateLocalDeploymentRequest : public OperationRequest
            {
              public:
                explicit CreateLocalDeploymentRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                CreateLocalDeploymentRequest(const CreateLocalDeploymentRequest &) = default;

                void SetGroupName(const Crt::Optional<Crt::String> &groupName) noexcept { m_groupName = groupName; }
                const Crt::Optional<Crt::String> &GetGroupName() noexcept { return m_groupName; }

                void SetRootComponentVersionsToAdd(
                    const Crt::Optional<Crt::Map<Crt::String, Crt::String>> &rootComponentVersionsToAdd) noexcept
                {
                    m_rootComponentVersionsToAdd = rootComponentVersionsToAdd;
                }
                const Crt::Optional<Crt::Map<Crt::String, Crt::String>> &GetRootComponentVersionsToAdd() noexcept
                {
                    return m_rootComponentVersionsToAdd;
                }

                void SetRootComponentsToRemove(
                    const Crt::Optional<Crt::Vector<Crt::String>> &rootComponentsToRemove) noexcept
                {
                    m_rootComponentsToRemove = rootComponentsToRemove;
                }
                const Crt::Optional<Crt::Vector<Crt::String>> &GetRootComponentsToRemove() noexcept
                {
                    return m_rootComponentsToRemove;
                }

                void SetComponentToConfiguration(
                    const Crt::Optional<Crt::Map<Crt::String, Crt::JsonObject>> &componentToConfiguration) noexcept
                {
                    m_componentToConfiguration = componentToConfiguration;
                }
                const Crt::Optional<Crt::Map<Crt::String, Crt::JsonObject>> &GetComponentToConfiguration() noexcept
                {
                    return m_componentToConfiguration;
                }

                void SetComponentToRunWithInfo(
                    const Crt::Optional<Crt::Map<Crt::String, RunWithInfo>> &componentToRunWithInfo) noexcept
                {
                    m_componentToRunWithInfo = componentToRunWithInfo;
                }
                const Crt::Optional<Crt::Map<Crt::String, RunWithInfo>> &GetComponentToRunWithInfo() noexcept
                {
                    return m_componentToRunWithInfo;
                }

                void SetRecipeDirectoryPath(const Crt::Optional<Crt::String> &recipeDirectoryPath) noexcept
                {
                    m_recipeDirectoryPath = recipeDirectoryPath;
                }
                const Crt::Optional<Crt::String> &GetRecipeDirectoryPath() noexcept { return m_recipeDirectoryPath; }

                void SetArtifactsDirectoryPath(const Crt::Optional<Crt::String> &artifactsDirectoryPath) noexcept
                {
                    m_artifactsDirectoryPath = artifactsDirectoryPath;
                }
                const Crt::Optional<Crt::String> &GetArtifactsDirectoryPath() noexcept
                {
                    return m_artifactsDirectoryPath;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(CreateLocalDeploymentRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(CreateLocalDeploymentRequest *) noexcept;
                /* This needs to be defined so that `CreateLocalDeploymentRequest` can be used as a key in maps. */
                bool operator<(const CreateLocalDeploymentRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_groupName;
                Crt::Optional<Crt::Map<Crt::String, Crt::String>> m_rootComponentVersionsToAdd;
                Crt::Optional<Crt::Vector<Crt::String>> m_rootComponentsToRemove;
                Crt::Optional<Crt::Map<Crt::String, Crt::JsonObject>> m_componentToConfiguration;
                Crt::Optional<Crt::Map<Crt::String, RunWithInfo>> m_componentToRunWithInfo;
                Crt::Optional<Crt::String> m_recipeDirectoryPath;
                Crt::Optional<Crt::String> m_artifactsDirectoryPath;
            };

            class PauseComponentResponse : public OperationResponse
            {
              public:
                explicit PauseComponentResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PauseComponentResponse(const PauseComponentResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PauseComponentResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PauseComponentResponse *) noexcept;
                /* This needs to be defined so that `PauseComponentResponse` can be used as a key in maps. */
                bool operator<(const PauseComponentResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class PauseComponentRequest : public OperationRequest
            {
              public:
                explicit PauseComponentRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PauseComponentRequest(const PauseComponentRequest &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PauseComponentRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PauseComponentRequest *) noexcept;
                /* This needs to be defined so that `PauseComponentRequest` can be used as a key in maps. */
                bool operator<(const PauseComponentRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
            };

            class StopComponentResponse : public OperationResponse
            {
              public:
                explicit StopComponentResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                StopComponentResponse(const StopComponentResponse &) = default;

                void SetStopStatus(const Crt::Optional<Crt::String> &stopStatus) noexcept { m_stopStatus = stopStatus; }
                const Crt::Optional<Crt::String> &GetStopStatus() noexcept { return m_stopStatus; }

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(StopComponentResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(StopComponentResponse *) noexcept;
                /* This needs to be defined so that `StopComponentResponse` can be used as a key in maps. */
                bool operator<(const StopComponentResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_stopStatus;
                Crt::Optional<Crt::String> m_message;
            };

            class StopComponentRequest : public OperationRequest
            {
              public:
                explicit StopComponentRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                StopComponentRequest(const StopComponentRequest &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(StopComponentRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(StopComponentRequest *) noexcept;
                /* This needs to be defined so that `StopComponentRequest` can be used as a key in maps. */
                bool operator<(const StopComponentRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
            };

            class ListLocalDeploymentsResponse : public OperationResponse
            {
              public:
                explicit ListLocalDeploymentsResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ListLocalDeploymentsResponse(const ListLocalDeploymentsResponse &) = default;

                void SetLocalDeployments(const Crt::Optional<Crt::Vector<LocalDeployment>> &localDeployments) noexcept
                {
                    m_localDeployments = localDeployments;
                }
                const Crt::Optional<Crt::Vector<LocalDeployment>> &GetLocalDeployments() noexcept
                {
                    return m_localDeployments;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ListLocalDeploymentsResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ListLocalDeploymentsResponse *) noexcept;
                /* This needs to be defined so that `ListLocalDeploymentsResponse` can be used as a key in maps. */
                bool operator<(const ListLocalDeploymentsResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<LocalDeployment>> m_localDeployments;
            };

            class ListLocalDeploymentsRequest : public OperationRequest
            {
              public:
                explicit ListLocalDeploymentsRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ListLocalDeploymentsRequest(const ListLocalDeploymentsRequest &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ListLocalDeploymentsRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ListLocalDeploymentsRequest *) noexcept;
                /* This needs to be defined so that `ListLocalDeploymentsRequest` can be used as a key in maps. */
                bool operator<(const ListLocalDeploymentsRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class SubscribeToComponentUpdatesResponse : public OperationResponse
            {
              public:
                explicit SubscribeToComponentUpdatesResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToComponentUpdatesResponse(const SubscribeToComponentUpdatesResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscribeToComponentUpdatesResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToComponentUpdatesResponse *) noexcept;
                /* This needs to be defined so that `SubscribeToComponentUpdatesResponse` can be used as a key in maps.
                 */
                bool operator<(const SubscribeToComponentUpdatesResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class SubscribeToComponentUpdatesRequest : public OperationRequest
            {
              public:
                explicit SubscribeToComponentUpdatesRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToComponentUpdatesRequest(const SubscribeToComponentUpdatesRequest &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscribeToComponentUpdatesRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToComponentUpdatesRequest *) noexcept;
                /* This needs to be defined so that `SubscribeToComponentUpdatesRequest` can be used as a key in maps.
                 */
                bool operator<(const SubscribeToComponentUpdatesRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class ListNamedShadowsForThingResponse : public OperationResponse
            {
              public:
                explicit ListNamedShadowsForThingResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ListNamedShadowsForThingResponse(const ListNamedShadowsForThingResponse &) = default;

                void SetResults(const Crt::Optional<Crt::Vector<Crt::String>> &results) noexcept
                {
                    m_results = results;
                }
                const Crt::Optional<Crt::Vector<Crt::String>> &GetResults() noexcept { return m_results; }

                void SetTimestamp(const Crt::Optional<Crt::DateTime> &timestamp) noexcept { m_timestamp = timestamp; }
                const Crt::Optional<Crt::DateTime> &GetTimestamp() noexcept { return m_timestamp; }

                void SetNextToken(const Crt::Optional<Crt::String> &nextToken) noexcept { m_nextToken = nextToken; }
                const Crt::Optional<Crt::String> &GetNextToken() noexcept { return m_nextToken; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ListNamedShadowsForThingResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ListNamedShadowsForThingResponse *) noexcept;
                /* This needs to be defined so that `ListNamedShadowsForThingResponse` can be used as a key in maps. */
                bool operator<(const ListNamedShadowsForThingResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<Crt::String>> m_results;
                Crt::Optional<Crt::DateTime> m_timestamp;
                Crt::Optional<Crt::String> m_nextToken;
            };

            class ListNamedShadowsForThingRequest : public OperationRequest
            {
              public:
                explicit ListNamedShadowsForThingRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ListNamedShadowsForThingRequest(const ListNamedShadowsForThingRequest &) = default;

                void SetThingName(const Crt::Optional<Crt::String> &thingName) noexcept { m_thingName = thingName; }
                const Crt::Optional<Crt::String> &GetThingName() noexcept { return m_thingName; }

                void SetNextToken(const Crt::Optional<Crt::String> &nextToken) noexcept { m_nextToken = nextToken; }
                const Crt::Optional<Crt::String> &GetNextToken() noexcept { return m_nextToken; }

                void SetPageSize(const Crt::Optional<int> &pageSize) noexcept { m_pageSize = pageSize; }
                const Crt::Optional<int> &GetPageSize() noexcept { return m_pageSize; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ListNamedShadowsForThingRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ListNamedShadowsForThingRequest *) noexcept;
                /* This needs to be defined so that `ListNamedShadowsForThingRequest` can be used as a key in maps. */
                bool operator<(const ListNamedShadowsForThingRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_thingName;
                Crt::Optional<Crt::String> m_nextToken;
                Crt::Optional<int> m_pageSize;
            };

            class UpdateStateResponse : public OperationResponse
            {
              public:
                explicit UpdateStateResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                UpdateStateResponse(const UpdateStateResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(UpdateStateResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(UpdateStateResponse *) noexcept;
                /* This needs to be defined so that `UpdateStateResponse` can be used as a key in maps. */
                bool operator<(const UpdateStateResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class UpdateStateRequest : public OperationRequest
            {
              public:
                explicit UpdateStateRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                UpdateStateRequest(const UpdateStateRequest &) = default;

                void SetState(const Crt::Optional<Crt::String> &state) noexcept { m_state = state; }
                const Crt::Optional<Crt::String> &GetState() noexcept { return m_state; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(UpdateStateRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(UpdateStateRequest *) noexcept;
                /* This needs to be defined so that `UpdateStateRequest` can be used as a key in maps. */
                bool operator<(const UpdateStateRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_state;
            };

            class GetSecretValueResponse : public OperationResponse
            {
              public:
                explicit GetSecretValueResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetSecretValueResponse(const GetSecretValueResponse &) = default;

                void SetSecretId(const Crt::Optional<Crt::String> &secretId) noexcept { m_secretId = secretId; }
                const Crt::Optional<Crt::String> &GetSecretId() noexcept { return m_secretId; }

                void SetVersionId(const Crt::Optional<Crt::String> &versionId) noexcept { m_versionId = versionId; }
                const Crt::Optional<Crt::String> &GetVersionId() noexcept { return m_versionId; }

                void SetVersionStage(const Crt::Optional<Crt::Vector<Crt::String>> &versionStage) noexcept
                {
                    m_versionStage = versionStage;
                }
                const Crt::Optional<Crt::Vector<Crt::String>> &GetVersionStage() noexcept { return m_versionStage; }

                void SetSecretValue(const Crt::Optional<SecretValue> &secretValue) noexcept
                {
                    m_secretValue = secretValue;
                }
                const Crt::Optional<SecretValue> &GetSecretValue() noexcept { return m_secretValue; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetSecretValueResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetSecretValueResponse *) noexcept;
                /* This needs to be defined so that `GetSecretValueResponse` can be used as a key in maps. */
                bool operator<(const GetSecretValueResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_secretId;
                Crt::Optional<Crt::String> m_versionId;
                Crt::Optional<Crt::Vector<Crt::String>> m_versionStage;
                Crt::Optional<SecretValue> m_secretValue;
            };

            class GetSecretValueRequest : public OperationRequest
            {
              public:
                explicit GetSecretValueRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetSecretValueRequest(const GetSecretValueRequest &) = default;

                void SetSecretId(const Crt::Optional<Crt::String> &secretId) noexcept { m_secretId = secretId; }
                const Crt::Optional<Crt::String> &GetSecretId() noexcept { return m_secretId; }

                void SetVersionId(const Crt::Optional<Crt::String> &versionId) noexcept { m_versionId = versionId; }
                const Crt::Optional<Crt::String> &GetVersionId() noexcept { return m_versionId; }

                void SetVersionStage(const Crt::Optional<Crt::String> &versionStage) noexcept
                {
                    m_versionStage = versionStage;
                }
                const Crt::Optional<Crt::String> &GetVersionStage() noexcept { return m_versionStage; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetSecretValueRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetSecretValueRequest *) noexcept;
                /* This needs to be defined so that `GetSecretValueRequest` can be used as a key in maps. */
                bool operator<(const GetSecretValueRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_secretId;
                Crt::Optional<Crt::String> m_versionId;
                Crt::Optional<Crt::String> m_versionStage;
            };

            class GetLocalDeploymentStatusResponse : public OperationResponse
            {
              public:
                explicit GetLocalDeploymentStatusResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetLocalDeploymentStatusResponse(const GetLocalDeploymentStatusResponse &) = default;

                void SetDeployment(const Crt::Optional<LocalDeployment> &deployment) noexcept
                {
                    m_deployment = deployment;
                }
                const Crt::Optional<LocalDeployment> &GetDeployment() noexcept { return m_deployment; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetLocalDeploymentStatusResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetLocalDeploymentStatusResponse *) noexcept;
                /* This needs to be defined so that `GetLocalDeploymentStatusResponse` can be used as a key in maps. */
                bool operator<(const GetLocalDeploymentStatusResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<LocalDeployment> m_deployment;
            };

            class GetLocalDeploymentStatusRequest : public OperationRequest
            {
              public:
                explicit GetLocalDeploymentStatusRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetLocalDeploymentStatusRequest(const GetLocalDeploymentStatusRequest &) = default;

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetLocalDeploymentStatusRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetLocalDeploymentStatusRequest *) noexcept;
                /* This needs to be defined so that `GetLocalDeploymentStatusRequest` can be used as a key in maps. */
                bool operator<(const GetLocalDeploymentStatusRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_deploymentId;
            };

            class ComponentNotFoundError : public OperationError
            {
              public:
                explicit ComponentNotFoundError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ComponentNotFoundError(const ComponentNotFoundError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ComponentNotFoundError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ComponentNotFoundError *) noexcept;
                /* This needs to be defined so that `ComponentNotFoundError` can be used as a key in maps. */
                bool operator<(const ComponentNotFoundError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class RestartComponentResponse : public OperationResponse
            {
              public:
                explicit RestartComponentResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                RestartComponentResponse(const RestartComponentResponse &) = default;

                void SetRestartStatus(const Crt::Optional<Crt::String> &restartStatus) noexcept
                {
                    m_restartStatus = restartStatus;
                }
                const Crt::Optional<Crt::String> &GetRestartStatus() noexcept { return m_restartStatus; }

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(RestartComponentResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(RestartComponentResponse *) noexcept;
                /* This needs to be defined so that `RestartComponentResponse` can be used as a key in maps. */
                bool operator<(const RestartComponentResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_restartStatus;
                Crt::Optional<Crt::String> m_message;
            };

            class RestartComponentRequest : public OperationRequest
            {
              public:
                explicit RestartComponentRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                RestartComponentRequest(const RestartComponentRequest &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(RestartComponentRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(RestartComponentRequest *) noexcept;
                /* This needs to be defined so that `RestartComponentRequest` can be used as a key in maps. */
                bool operator<(const RestartComponentRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
            };

            class InvalidTokenError : public OperationError
            {
              public:
                explicit InvalidTokenError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                InvalidTokenError(const InvalidTokenError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(InvalidTokenError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(InvalidTokenError *) noexcept;
                /* This needs to be defined so that `InvalidTokenError` can be used as a key in maps. */
                bool operator<(const InvalidTokenError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class ValidateAuthorizationTokenResponse : public OperationResponse
            {
              public:
                explicit ValidateAuthorizationTokenResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ValidateAuthorizationTokenResponse(const ValidateAuthorizationTokenResponse &) = default;

                void SetIsValid(const Crt::Optional<bool> &isValid) noexcept { m_isValid = isValid; }
                const Crt::Optional<bool> &GetIsValid() noexcept { return m_isValid; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ValidateAuthorizationTokenResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ValidateAuthorizationTokenResponse *) noexcept;
                /* This needs to be defined so that `ValidateAuthorizationTokenResponse` can be used as a key in maps.
                 */
                bool operator<(const ValidateAuthorizationTokenResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<bool> m_isValid;
            };

            class ValidateAuthorizationTokenRequest : public OperationRequest
            {
              public:
                explicit ValidateAuthorizationTokenRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ValidateAuthorizationTokenRequest(const ValidateAuthorizationTokenRequest &) = default;

                void SetToken(const Crt::Optional<Crt::String> &token) noexcept { m_token = token; }
                const Crt::Optional<Crt::String> &GetToken() noexcept { return m_token; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ValidateAuthorizationTokenRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ValidateAuthorizationTokenRequest *) noexcept;
                /* This needs to be defined so that `ValidateAuthorizationTokenRequest` can be used as a key in maps. */
                bool operator<(const ValidateAuthorizationTokenRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_token;
            };

            class FailedUpdateConditionCheckError : public OperationError
            {
              public:
                explicit FailedUpdateConditionCheckError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                FailedUpdateConditionCheckError(const FailedUpdateConditionCheckError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(FailedUpdateConditionCheckError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(FailedUpdateConditionCheckError *) noexcept;
                /* This needs to be defined so that `FailedUpdateConditionCheckError` can be used as a key in maps. */
                bool operator<(const FailedUpdateConditionCheckError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class UpdateConfigurationResponse : public OperationResponse
            {
              public:
                explicit UpdateConfigurationResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                UpdateConfigurationResponse(const UpdateConfigurationResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(UpdateConfigurationResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(UpdateConfigurationResponse *) noexcept;
                /* This needs to be defined so that `UpdateConfigurationResponse` can be used as a key in maps. */
                bool operator<(const UpdateConfigurationResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class UpdateConfigurationRequest : public OperationRequest
            {
              public:
                explicit UpdateConfigurationRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                UpdateConfigurationRequest(const UpdateConfigurationRequest &) = default;

                void SetKeyPath(const Crt::Optional<Crt::Vector<Crt::String>> &keyPath) noexcept
                {
                    m_keyPath = keyPath;
                }
                const Crt::Optional<Crt::Vector<Crt::String>> &GetKeyPath() noexcept { return m_keyPath; }

                void SetTimestamp(const Crt::Optional<Crt::DateTime> &timestamp) noexcept { m_timestamp = timestamp; }
                const Crt::Optional<Crt::DateTime> &GetTimestamp() noexcept { return m_timestamp; }

                void SetValueToMerge(const Crt::Optional<Crt::JsonObject> &valueToMerge) noexcept
                {
                    m_valueToMerge = valueToMerge;
                }
                const Crt::Optional<Crt::JsonObject> &GetValueToMerge() noexcept { return m_valueToMerge; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(UpdateConfigurationRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(UpdateConfigurationRequest *) noexcept;
                /* This needs to be defined so that `UpdateConfigurationRequest` can be used as a key in maps. */
                bool operator<(const UpdateConfigurationRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<Crt::String>> m_keyPath;
                Crt::Optional<Crt::DateTime> m_timestamp;
                Crt::Optional<Crt::JsonObject> m_valueToMerge;
            };

            class ConflictError : public OperationError
            {
              public:
                explicit ConflictError(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator)
                {
                }
                ConflictError(const ConflictError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ConflictError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ConflictError *) noexcept;
                /* This needs to be defined so that `ConflictError` can be used as a key in maps. */
                bool operator<(const ConflictError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class UpdateThingShadowResponse : public OperationResponse
            {
              public:
                explicit UpdateThingShadowResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                UpdateThingShadowResponse(const UpdateThingShadowResponse &) = default;

                void SetPayload(const Crt::Optional<Crt::Vector<uint8_t>> &payload) noexcept { m_payload = payload; }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetPayload() noexcept { return m_payload; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(UpdateThingShadowResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(UpdateThingShadowResponse *) noexcept;
                /* This needs to be defined so that `UpdateThingShadowResponse` can be used as a key in maps. */
                bool operator<(const UpdateThingShadowResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<uint8_t>> m_payload;
            };

            class UpdateThingShadowRequest : public OperationRequest
            {
              public:
                explicit UpdateThingShadowRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                UpdateThingShadowRequest(const UpdateThingShadowRequest &) = default;

                void SetThingName(const Crt::Optional<Crt::String> &thingName) noexcept { m_thingName = thingName; }
                const Crt::Optional<Crt::String> &GetThingName() noexcept { return m_thingName; }

                void SetShadowName(const Crt::Optional<Crt::String> &shadowName) noexcept { m_shadowName = shadowName; }
                const Crt::Optional<Crt::String> &GetShadowName() noexcept { return m_shadowName; }

                void SetPayload(const Crt::Optional<Crt::Vector<uint8_t>> &payload) noexcept { m_payload = payload; }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetPayload() noexcept { return m_payload; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(UpdateThingShadowRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(UpdateThingShadowRequest *) noexcept;
                /* This needs to be defined so that `UpdateThingShadowRequest` can be used as a key in maps. */
                bool operator<(const UpdateThingShadowRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_thingName;
                Crt::Optional<Crt::String> m_shadowName;
                Crt::Optional<Crt::Vector<uint8_t>> m_payload;
            };

            class SendConfigurationValidityReportResponse : public OperationResponse
            {
              public:
                explicit SendConfigurationValidityReportResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SendConfigurationValidityReportResponse(const SendConfigurationValidityReportResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(
                    SendConfigurationValidityReportResponse &,
                    const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SendConfigurationValidityReportResponse *) noexcept;
                /* This needs to be defined so that `SendConfigurationValidityReportResponse` can be used as a key in
                 * maps. */
                bool operator<(const SendConfigurationValidityReportResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class SendConfigurationValidityReportRequest : public OperationRequest
            {
              public:
                explicit SendConfigurationValidityReportRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SendConfigurationValidityReportRequest(const SendConfigurationValidityReportRequest &) = default;

                void SetConfigurationValidityReport(
                    const Crt::Optional<ConfigurationValidityReport> &configurationValidityReport) noexcept
                {
                    m_configurationValidityReport = configurationValidityReport;
                }
                const Crt::Optional<ConfigurationValidityReport> &GetConfigurationValidityReport() noexcept
                {
                    return m_configurationValidityReport;
                }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(
                    SendConfigurationValidityReportRequest &,
                    const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SendConfigurationValidityReportRequest *) noexcept;
                /* This needs to be defined so that `SendConfigurationValidityReportRequest` can be used as a key in
                 * maps. */
                bool operator<(const SendConfigurationValidityReportRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<ConfigurationValidityReport> m_configurationValidityReport;
            };

            class GetThingShadowResponse : public OperationResponse
            {
              public:
                explicit GetThingShadowResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetThingShadowResponse(const GetThingShadowResponse &) = default;

                void SetPayload(const Crt::Optional<Crt::Vector<uint8_t>> &payload) noexcept { m_payload = payload; }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetPayload() noexcept { return m_payload; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetThingShadowResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetThingShadowResponse *) noexcept;
                /* This needs to be defined so that `GetThingShadowResponse` can be used as a key in maps. */
                bool operator<(const GetThingShadowResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<uint8_t>> m_payload;
            };

            class GetThingShadowRequest : public OperationRequest
            {
              public:
                explicit GetThingShadowRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetThingShadowRequest(const GetThingShadowRequest &) = default;

                void SetThingName(const Crt::Optional<Crt::String> &thingName) noexcept { m_thingName = thingName; }
                const Crt::Optional<Crt::String> &GetThingName() noexcept { return m_thingName; }

                void SetShadowName(const Crt::Optional<Crt::String> &shadowName) noexcept { m_shadowName = shadowName; }
                const Crt::Optional<Crt::String> &GetShadowName() noexcept { return m_shadowName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetThingShadowRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetThingShadowRequest *) noexcept;
                /* This needs to be defined so that `GetThingShadowRequest` can be used as a key in maps. */
                bool operator<(const GetThingShadowRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_thingName;
                Crt::Optional<Crt::String> m_shadowName;
            };

            class CreateDebugPasswordResponse : public OperationResponse
            {
              public:
                explicit CreateDebugPasswordResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                CreateDebugPasswordResponse(const CreateDebugPasswordResponse &) = default;

                void SetPassword(const Crt::Optional<Crt::String> &password) noexcept { m_password = password; }
                const Crt::Optional<Crt::String> &GetPassword() noexcept { return m_password; }

                void SetUsername(const Crt::Optional<Crt::String> &username) noexcept { m_username = username; }
                const Crt::Optional<Crt::String> &GetUsername() noexcept { return m_username; }

                void SetPasswordExpiration(const Crt::Optional<Crt::DateTime> &passwordExpiration) noexcept
                {
                    m_passwordExpiration = passwordExpiration;
                }
                const Crt::Optional<Crt::DateTime> &GetPasswordExpiration() noexcept { return m_passwordExpiration; }

                void SetCertificateSHA256Hash(const Crt::Optional<Crt::String> &certificateSHA256Hash) noexcept
                {
                    m_certificateSHA256Hash = certificateSHA256Hash;
                }
                const Crt::Optional<Crt::String> &GetCertificateSHA256Hash() noexcept
                {
                    return m_certificateSHA256Hash;
                }

                void SetCertificateSHA1Hash(const Crt::Optional<Crt::String> &certificateSHA1Hash) noexcept
                {
                    m_certificateSHA1Hash = certificateSHA1Hash;
                }
                const Crt::Optional<Crt::String> &GetCertificateSHA1Hash() noexcept { return m_certificateSHA1Hash; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(CreateDebugPasswordResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(CreateDebugPasswordResponse *) noexcept;
                /* This needs to be defined so that `CreateDebugPasswordResponse` can be used as a key in maps. */
                bool operator<(const CreateDebugPasswordResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_password;
                Crt::Optional<Crt::String> m_username;
                Crt::Optional<Crt::DateTime> m_passwordExpiration;
                Crt::Optional<Crt::String> m_certificateSHA256Hash;
                Crt::Optional<Crt::String> m_certificateSHA1Hash;
            };

            class CreateDebugPasswordRequest : public OperationRequest
            {
              public:
                explicit CreateDebugPasswordRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                CreateDebugPasswordRequest(const CreateDebugPasswordRequest &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(CreateDebugPasswordRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(CreateDebugPasswordRequest *) noexcept;
                /* This needs to be defined so that `CreateDebugPasswordRequest` can be used as a key in maps. */
                bool operator<(const CreateDebugPasswordRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class ListComponentsResponse : public OperationResponse
            {
              public:
                explicit ListComponentsResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ListComponentsResponse(const ListComponentsResponse &) = default;

                void SetComponents(const Crt::Optional<Crt::Vector<ComponentDetails>> &components) noexcept
                {
                    m_components = components;
                }
                const Crt::Optional<Crt::Vector<ComponentDetails>> &GetComponents() noexcept { return m_components; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ListComponentsResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ListComponentsResponse *) noexcept;
                /* This needs to be defined so that `ListComponentsResponse` can be used as a key in maps. */
                bool operator<(const ListComponentsResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<ComponentDetails>> m_components;
            };

            class ListComponentsRequest : public OperationRequest
            {
              public:
                explicit ListComponentsRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ListComponentsRequest(const ListComponentsRequest &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ListComponentsRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ListComponentsRequest *) noexcept;
                /* This needs to be defined so that `ListComponentsRequest` can be used as a key in maps. */
                bool operator<(const ListComponentsRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class PublishToTopicResponse : public OperationResponse
            {
              public:
                explicit PublishToTopicResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PublishToTopicResponse(const PublishToTopicResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PublishToTopicResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PublishToTopicResponse *) noexcept;
                /* This needs to be defined so that `PublishToTopicResponse` can be used as a key in maps. */
                bool operator<(const PublishToTopicResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class PublishToTopicRequest : public OperationRequest
            {
              public:
                explicit PublishToTopicRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PublishToTopicRequest(const PublishToTopicRequest &) = default;

                void SetTopic(const Crt::Optional<Crt::String> &topic) noexcept { m_topic = topic; }
                const Crt::Optional<Crt::String> &GetTopic() noexcept { return m_topic; }

                void SetPublishMessage(const Crt::Optional<PublishMessage> &publishMessage) noexcept
                {
                    m_publishMessage = publishMessage;
                }
                const Crt::Optional<PublishMessage> &GetPublishMessage() noexcept { return m_publishMessage; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PublishToTopicRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PublishToTopicRequest *) noexcept;
                /* This needs to be defined so that `PublishToTopicRequest` can be used as a key in maps. */
                bool operator<(const PublishToTopicRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_topic;
                Crt::Optional<PublishMessage> m_publishMessage;
            };

            class GetComponentDetailsResponse : public OperationResponse
            {
              public:
                explicit GetComponentDetailsResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetComponentDetailsResponse(const GetComponentDetailsResponse &) = default;

                void SetComponentDetails(const Crt::Optional<ComponentDetails> &componentDetails) noexcept
                {
                    m_componentDetails = componentDetails;
                }
                const Crt::Optional<ComponentDetails> &GetComponentDetails() noexcept { return m_componentDetails; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetComponentDetailsResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetComponentDetailsResponse *) noexcept;
                /* This needs to be defined so that `GetComponentDetailsResponse` can be used as a key in maps. */
                bool operator<(const GetComponentDetailsResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<ComponentDetails> m_componentDetails;
            };

            class GetComponentDetailsRequest : public OperationRequest
            {
              public:
                explicit GetComponentDetailsRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetComponentDetailsRequest(const GetComponentDetailsRequest &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetComponentDetailsRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetComponentDetailsRequest *) noexcept;
                /* This needs to be defined so that `GetComponentDetailsRequest` can be used as a key in maps. */
                bool operator<(const GetComponentDetailsRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
            };

            class SubscribeToTopicResponse : public OperationResponse
            {
              public:
                explicit SubscribeToTopicResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToTopicResponse(const SubscribeToTopicResponse &) = default;

                void SetTopicName(const Crt::Optional<Crt::String> &topicName) noexcept { m_topicName = topicName; }
                const Crt::Optional<Crt::String> &GetTopicName() noexcept { return m_topicName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscribeToTopicResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToTopicResponse *) noexcept;
                /* This needs to be defined so that `SubscribeToTopicResponse` can be used as a key in maps. */
                bool operator<(const SubscribeToTopicResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_topicName;
            };

            class SubscribeToTopicRequest : public OperationRequest
            {
              public:
                explicit SubscribeToTopicRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToTopicRequest(const SubscribeToTopicRequest &) = default;

                void SetTopic(const Crt::Optional<Crt::String> &topic) noexcept { m_topic = topic; }
                const Crt::Optional<Crt::String> &GetTopic() noexcept { return m_topic; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscribeToTopicRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToTopicRequest *) noexcept;
                /* This needs to be defined so that `SubscribeToTopicRequest` can be used as a key in maps. */
                bool operator<(const SubscribeToTopicRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_topic;
            };

            class GetConfigurationResponse : public OperationResponse
            {
              public:
                explicit GetConfigurationResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetConfigurationResponse(const GetConfigurationResponse &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SetValue(const Crt::Optional<Crt::JsonObject> &value) noexcept { m_value = value; }
                const Crt::Optional<Crt::JsonObject> &GetValue() noexcept { return m_value; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetConfigurationResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetConfigurationResponse *) noexcept;
                /* This needs to be defined so that `GetConfigurationResponse` can be used as a key in maps. */
                bool operator<(const GetConfigurationResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
                Crt::Optional<Crt::JsonObject> m_value;
            };

            class GetConfigurationRequest : public OperationRequest
            {
              public:
                explicit GetConfigurationRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                GetConfigurationRequest(const GetConfigurationRequest &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SetKeyPath(const Crt::Optional<Crt::Vector<Crt::String>> &keyPath) noexcept
                {
                    m_keyPath = keyPath;
                }
                const Crt::Optional<Crt::Vector<Crt::String>> &GetKeyPath() noexcept { return m_keyPath; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(GetConfigurationRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(GetConfigurationRequest *) noexcept;
                /* This needs to be defined so that `GetConfigurationRequest` can be used as a key in maps. */
                bool operator<(const GetConfigurationRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
                Crt::Optional<Crt::Vector<Crt::String>> m_keyPath;
            };

            class SubscribeToValidateConfigurationUpdatesResponse : public OperationResponse
            {
              public:
                explicit SubscribeToValidateConfigurationUpdatesResponse(
                    Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToValidateConfigurationUpdatesResponse(
                    const SubscribeToValidateConfigurationUpdatesResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(
                    SubscribeToValidateConfigurationUpdatesResponse &,
                    const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToValidateConfigurationUpdatesResponse *) noexcept;
                /* This needs to be defined so that `SubscribeToValidateConfigurationUpdatesResponse` can be used as a
                 * key in maps. */
                bool operator<(const SubscribeToValidateConfigurationUpdatesResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class SubscribeToValidateConfigurationUpdatesRequest : public OperationRequest
            {
              public:
                explicit SubscribeToValidateConfigurationUpdatesRequest(
                    Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToValidateConfigurationUpdatesRequest(const SubscribeToValidateConfigurationUpdatesRequest &) =
                    default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(
                    SubscribeToValidateConfigurationUpdatesRequest &,
                    const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToValidateConfigurationUpdatesRequest *) noexcept;
                /* This needs to be defined so that `SubscribeToValidateConfigurationUpdatesRequest` can be used as a
                 * key in maps. */
                bool operator<(const SubscribeToValidateConfigurationUpdatesRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class DeferComponentUpdateResponse : public OperationResponse
            {
              public:
                explicit DeferComponentUpdateResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                DeferComponentUpdateResponse(const DeferComponentUpdateResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(DeferComponentUpdateResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(DeferComponentUpdateResponse *) noexcept;
                /* This needs to be defined so that `DeferComponentUpdateResponse` can be used as a key in maps. */
                bool operator<(const DeferComponentUpdateResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class DeferComponentUpdateRequest : public OperationRequest
            {
              public:
                explicit DeferComponentUpdateRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                DeferComponentUpdateRequest(const DeferComponentUpdateRequest &) = default;

                void SetDeploymentId(const Crt::Optional<Crt::String> &deploymentId) noexcept
                {
                    m_deploymentId = deploymentId;
                }
                const Crt::Optional<Crt::String> &GetDeploymentId() noexcept { return m_deploymentId; }

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SetRecheckAfterMs(const Crt::Optional<int> &recheckAfterMs) noexcept
                {
                    m_recheckAfterMs = recheckAfterMs;
                }
                const Crt::Optional<int> &GetRecheckAfterMs() noexcept { return m_recheckAfterMs; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(DeferComponentUpdateRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(DeferComponentUpdateRequest *) noexcept;
                /* This needs to be defined so that `DeferComponentUpdateRequest` can be used as a key in maps. */
                bool operator<(const DeferComponentUpdateRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_deploymentId;
                Crt::Optional<Crt::String> m_message;
                Crt::Optional<int> m_recheckAfterMs;
            };

            class InvalidArgumentsError : public OperationError
            {
              public:
                explicit InvalidArgumentsError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                InvalidArgumentsError(const InvalidArgumentsError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(InvalidArgumentsError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(InvalidArgumentsError *) noexcept;
                /* This needs to be defined so that `InvalidArgumentsError` can be used as a key in maps. */
                bool operator<(const InvalidArgumentsError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class DeleteThingShadowResponse : public OperationResponse
            {
              public:
                explicit DeleteThingShadowResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                DeleteThingShadowResponse(const DeleteThingShadowResponse &) = default;

                void SetPayload(const Crt::Optional<Crt::Vector<uint8_t>> &payload) noexcept { m_payload = payload; }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetPayload() noexcept { return m_payload; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(DeleteThingShadowResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(DeleteThingShadowResponse *) noexcept;
                /* This needs to be defined so that `DeleteThingShadowResponse` can be used as a key in maps. */
                bool operator<(const DeleteThingShadowResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::Vector<uint8_t>> m_payload;
            };

            class DeleteThingShadowRequest : public OperationRequest
            {
              public:
                explicit DeleteThingShadowRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                DeleteThingShadowRequest(const DeleteThingShadowRequest &) = default;

                void SetThingName(const Crt::Optional<Crt::String> &thingName) noexcept { m_thingName = thingName; }
                const Crt::Optional<Crt::String> &GetThingName() noexcept { return m_thingName; }

                void SetShadowName(const Crt::Optional<Crt::String> &shadowName) noexcept { m_shadowName = shadowName; }
                const Crt::Optional<Crt::String> &GetShadowName() noexcept { return m_shadowName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(DeleteThingShadowRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(DeleteThingShadowRequest *) noexcept;
                /* This needs to be defined so that `DeleteThingShadowRequest` can be used as a key in maps. */
                bool operator<(const DeleteThingShadowRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_thingName;
                Crt::Optional<Crt::String> m_shadowName;
            };

            class SubscribeToConfigurationUpdateResponse : public OperationResponse
            {
              public:
                explicit SubscribeToConfigurationUpdateResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToConfigurationUpdateResponse(const SubscribeToConfigurationUpdateResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(
                    SubscribeToConfigurationUpdateResponse &,
                    const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToConfigurationUpdateResponse *) noexcept;
                /* This needs to be defined so that `SubscribeToConfigurationUpdateResponse` can be used as a key in
                 * maps. */
                bool operator<(const SubscribeToConfigurationUpdateResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class SubscribeToConfigurationUpdateRequest : public OperationRequest
            {
              public:
                explicit SubscribeToConfigurationUpdateRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToConfigurationUpdateRequest(const SubscribeToConfigurationUpdateRequest &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SetKeyPath(const Crt::Optional<Crt::Vector<Crt::String>> &keyPath) noexcept
                {
                    m_keyPath = keyPath;
                }
                const Crt::Optional<Crt::Vector<Crt::String>> &GetKeyPath() noexcept { return m_keyPath; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscribeToConfigurationUpdateRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToConfigurationUpdateRequest *) noexcept;
                /* This needs to be defined so that `SubscribeToConfigurationUpdateRequest` can be used as a key in
                 * maps. */
                bool operator<(const SubscribeToConfigurationUpdateRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
                Crt::Optional<Crt::Vector<Crt::String>> m_keyPath;
            };

            class PublishToIoTCoreResponse : public OperationResponse
            {
              public:
                explicit PublishToIoTCoreResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PublishToIoTCoreResponse(const PublishToIoTCoreResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PublishToIoTCoreResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PublishToIoTCoreResponse *) noexcept;
                /* This needs to be defined so that `PublishToIoTCoreResponse` can be used as a key in maps. */
                bool operator<(const PublishToIoTCoreResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class PublishToIoTCoreRequest : public OperationRequest
            {
              public:
                explicit PublishToIoTCoreRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                PublishToIoTCoreRequest(const PublishToIoTCoreRequest &) = default;

                void SetTopicName(const Crt::Optional<Crt::String> &topicName) noexcept { m_topicName = topicName; }
                const Crt::Optional<Crt::String> &GetTopicName() noexcept { return m_topicName; }

                void SetQos(const Crt::Optional<Crt::String> &qos) noexcept { m_qos = qos; }
                const Crt::Optional<Crt::String> &GetQos() noexcept { return m_qos; }

                void SetPayload(const Crt::Optional<Crt::Vector<uint8_t>> &payload) noexcept { m_payload = payload; }
                const Crt::Optional<Crt::Vector<uint8_t>> &GetPayload() noexcept { return m_payload; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(PublishToIoTCoreRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(PublishToIoTCoreRequest *) noexcept;
                /* This needs to be defined so that `PublishToIoTCoreRequest` can be used as a key in maps. */
                bool operator<(const PublishToIoTCoreRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_topicName;
                Crt::Optional<Crt::String> m_qos;
                Crt::Optional<Crt::Vector<uint8_t>> m_payload;
            };

            class ResourceNotFoundError : public OperationError
            {
              public:
                explicit ResourceNotFoundError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ResourceNotFoundError(const ResourceNotFoundError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SetResourceType(const Crt::Optional<Crt::String> &resourceType) noexcept
                {
                    m_resourceType = resourceType;
                }
                const Crt::Optional<Crt::String> &GetResourceType() noexcept { return m_resourceType; }

                void SetResourceName(const Crt::Optional<Crt::String> &resourceName) noexcept
                {
                    m_resourceName = resourceName;
                }
                const Crt::Optional<Crt::String> &GetResourceName() noexcept { return m_resourceName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ResourceNotFoundError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ResourceNotFoundError *) noexcept;
                /* This needs to be defined so that `ResourceNotFoundError` can be used as a key in maps. */
                bool operator<(const ResourceNotFoundError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
                Crt::Optional<Crt::String> m_resourceType;
                Crt::Optional<Crt::String> m_resourceName;
            };

            class ResumeComponentResponse : public OperationResponse
            {
              public:
                explicit ResumeComponentResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ResumeComponentResponse(const ResumeComponentResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ResumeComponentResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ResumeComponentResponse *) noexcept;
                /* This needs to be defined so that `ResumeComponentResponse` can be used as a key in maps. */
                bool operator<(const ResumeComponentResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class ResumeComponentRequest : public OperationRequest
            {
              public:
                explicit ResumeComponentRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                ResumeComponentRequest(const ResumeComponentRequest &) = default;

                void SetComponentName(const Crt::Optional<Crt::String> &componentName) noexcept
                {
                    m_componentName = componentName;
                }
                const Crt::Optional<Crt::String> &GetComponentName() noexcept { return m_componentName; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(ResumeComponentRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(ResumeComponentRequest *) noexcept;
                /* This needs to be defined so that `ResumeComponentRequest` can be used as a key in maps. */
                bool operator<(const ResumeComponentRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_componentName;
            };

            class UnauthorizedError : public OperationError
            {
              public:
                explicit UnauthorizedError(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                UnauthorizedError(const UnauthorizedError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(UnauthorizedError &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(UnauthorizedError *) noexcept;
                /* This needs to be defined so that `UnauthorizedError` can be used as a key in maps. */
                bool operator<(const UnauthorizedError &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_message;
            };

            class ServiceError : public OperationError
            {
              public:
                explicit ServiceError(Crt::Allocator *allocator = Crt::g_allocator) noexcept : m_allocator(allocator) {}
                ServiceError(const ServiceError &) = default;

                void SetMessage(const Crt::Optional<Crt::String> &message) noexcept { m_message = message; }
                const Crt::Optional<Crt::String> &GetMessage() noexcept { return m_message; }

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
            };

            class SubscribeToIoTCoreResponse : public OperationResponse
            {
              public:
                explicit SubscribeToIoTCoreResponse(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToIoTCoreResponse(const SubscribeToIoTCoreResponse &) = default;

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscribeToIoTCoreResponse &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToIoTCoreResponse *) noexcept;
                /* This needs to be defined so that `SubscribeToIoTCoreResponse` can be used as a key in maps. */
                bool operator<(const SubscribeToIoTCoreResponse &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
            };

            class SubscribeToIoTCoreRequest : public OperationRequest
            {
              public:
                explicit SubscribeToIoTCoreRequest(Crt::Allocator *allocator = Crt::g_allocator) noexcept
                    : m_allocator(allocator)
                {
                }
                SubscribeToIoTCoreRequest(const SubscribeToIoTCoreRequest &) = default;

                void SetTopicName(const Crt::Optional<Crt::String> &topicName) noexcept { m_topicName = topicName; }
                const Crt::Optional<Crt::String> &GetTopicName() noexcept { return m_topicName; }

                void SetQos(const Crt::Optional<Crt::String> &qos) noexcept { m_qos = qos; }
                const Crt::Optional<Crt::String> &GetQos() noexcept { return m_qos; }

                void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
                static void s_loadFromJsonView(SubscribeToIoTCoreRequest &, const Crt::JsonView &) noexcept;
                static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                    Crt::StringView,
                    Crt::Allocator *) noexcept;
                static void s_customDeleter(SubscribeToIoTCoreRequest *) noexcept;
                /* This needs to be defined so that `SubscribeToIoTCoreRequest` can be used as a key in maps. */
                bool operator<(const SubscribeToIoTCoreRequest &) const noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;

              private:
                Crt::Allocator *m_allocator;
                Crt::Optional<Crt::String> m_topicName;
                Crt::Optional<Crt::String> m_qos;
            };

            class SubscribeToIoTCoreStreamHandler : public StreamResponseHandler
            {
              public:
                virtual void OnStreamEvent(IoTCoreMessage *response) { (void)response; }
                virtual bool OnStreamError(ServiceError *operationError, RpcError rpcError)
                {
                    (void)operationError;
                    (void)rpcError;
                    return true;
                }

                virtual bool OnStreamError(UnauthorizedError *operationError, RpcError rpcError)
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
            class SubscribeToIoTCoreOperationContext : public OperationModelContext
            {
              public:
                SubscribeToIoTCoreOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class SubscribeToIoTCoreOperation : public ClientOperation
            {
              public:
                SubscribeToIoTCoreOperation(
                    ClientConnection &connection,
                    SubscribeToIoTCoreStreamHandler *streamHandler,
                    const SubscribeToIoTCoreOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const SubscribeToIoTCoreRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class ResumeComponentOperationContext : public OperationModelContext
            {
              public:
                ResumeComponentOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class ResumeComponentOperation : public ClientOperation
            {
              public:
                ResumeComponentOperation(
                    ClientConnection &connection,
                    const ResumeComponentOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const ResumeComponentRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class PublishToIoTCoreOperationContext : public OperationModelContext
            {
              public:
                PublishToIoTCoreOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class PublishToIoTCoreOperation : public ClientOperation
            {
              public:
                PublishToIoTCoreOperation(
                    ClientConnection &connection,
                    const PublishToIoTCoreOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const PublishToIoTCoreRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class SubscribeToConfigurationUpdateStreamHandler : public StreamResponseHandler
            {
              public:
                virtual void OnStreamEvent(ConfigurationUpdateEvents *response) { (void)response; }
                virtual bool OnStreamError(ServiceError *operationError, RpcError rpcError)
                {
                    (void)operationError;
                    (void)rpcError;
                    return true;
                }

                virtual bool OnStreamError(ResourceNotFoundError *operationError, RpcError rpcError)
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
            class SubscribeToConfigurationUpdateOperationContext : public OperationModelContext
            {
              public:
                SubscribeToConfigurationUpdateOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class SubscribeToConfigurationUpdateOperation : public ClientOperation
            {
              public:
                SubscribeToConfigurationUpdateOperation(
                    ClientConnection &connection,
                    SubscribeToConfigurationUpdateStreamHandler *streamHandler,
                    const SubscribeToConfigurationUpdateOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const SubscribeToConfigurationUpdateRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class DeleteThingShadowOperationContext : public OperationModelContext
            {
              public:
                DeleteThingShadowOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class DeleteThingShadowOperation : public ClientOperation
            {
              public:
                DeleteThingShadowOperation(
                    ClientConnection &connection,
                    const DeleteThingShadowOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const DeleteThingShadowRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class DeferComponentUpdateOperationContext : public OperationModelContext
            {
              public:
                DeferComponentUpdateOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class DeferComponentUpdateOperation : public ClientOperation
            {
              public:
                DeferComponentUpdateOperation(
                    ClientConnection &connection,
                    const DeferComponentUpdateOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const DeferComponentUpdateRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class SubscribeToValidateConfigurationUpdatesStreamHandler : public StreamResponseHandler
            {
              public:
                virtual void OnStreamEvent(ValidateConfigurationUpdateEvents *response) { (void)response; }
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
            class SubscribeToValidateConfigurationUpdatesOperationContext : public OperationModelContext
            {
              public:
                SubscribeToValidateConfigurationUpdatesOperationContext(
                    const GreengrassServiceModel &serviceModel) noexcept;
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

            class SubscribeToValidateConfigurationUpdatesOperation : public ClientOperation
            {
              public:
                SubscribeToValidateConfigurationUpdatesOperation(
                    ClientConnection &connection,
                    SubscribeToValidateConfigurationUpdatesStreamHandler *streamHandler,
                    const SubscribeToValidateConfigurationUpdatesOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const SubscribeToValidateConfigurationUpdatesRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class GetConfigurationOperationContext : public OperationModelContext
            {
              public:
                GetConfigurationOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class GetConfigurationOperation : public ClientOperation
            {
              public:
                GetConfigurationOperation(
                    ClientConnection &connection,
                    const GetConfigurationOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const GetConfigurationRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class SubscribeToTopicStreamHandler : public StreamResponseHandler
            {
              public:
                virtual void OnStreamEvent(SubscriptionResponseMessage *response) { (void)response; }
                virtual bool OnStreamError(InvalidArgumentsError *operationError, RpcError rpcError)
                {
                    (void)operationError;
                    (void)rpcError;
                    return true;
                }

                virtual bool OnStreamError(ServiceError *operationError, RpcError rpcError)
                {
                    (void)operationError;
                    (void)rpcError;
                    return true;
                }

                virtual bool OnStreamError(UnauthorizedError *operationError, RpcError rpcError)
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
            class SubscribeToTopicOperationContext : public OperationModelContext
            {
              public:
                SubscribeToTopicOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class SubscribeToTopicOperation : public ClientOperation
            {
              public:
                SubscribeToTopicOperation(
                    ClientConnection &connection,
                    SubscribeToTopicStreamHandler *streamHandler,
                    const SubscribeToTopicOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const SubscribeToTopicRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class GetComponentDetailsOperationContext : public OperationModelContext
            {
              public:
                GetComponentDetailsOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class GetComponentDetailsOperation : public ClientOperation
            {
              public:
                GetComponentDetailsOperation(
                    ClientConnection &connection,
                    const GetComponentDetailsOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const GetComponentDetailsRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class PublishToTopicOperationContext : public OperationModelContext
            {
              public:
                PublishToTopicOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class PublishToTopicOperation : public ClientOperation
            {
              public:
                PublishToTopicOperation(
                    ClientConnection &connection,
                    const PublishToTopicOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const PublishToTopicRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class ListComponentsOperationContext : public OperationModelContext
            {
              public:
                ListComponentsOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class ListComponentsOperation : public ClientOperation
            {
              public:
                ListComponentsOperation(
                    ClientConnection &connection,
                    const ListComponentsOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const ListComponentsRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class CreateDebugPasswordOperationContext : public OperationModelContext
            {
              public:
                CreateDebugPasswordOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class CreateDebugPasswordOperation : public ClientOperation
            {
              public:
                CreateDebugPasswordOperation(
                    ClientConnection &connection,
                    const CreateDebugPasswordOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const CreateDebugPasswordRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class GetThingShadowOperationContext : public OperationModelContext
            {
              public:
                GetThingShadowOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class GetThingShadowOperation : public ClientOperation
            {
              public:
                GetThingShadowOperation(
                    ClientConnection &connection,
                    const GetThingShadowOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const GetThingShadowRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class SendConfigurationValidityReportOperationContext : public OperationModelContext
            {
              public:
                SendConfigurationValidityReportOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class SendConfigurationValidityReportOperation : public ClientOperation
            {
              public:
                SendConfigurationValidityReportOperation(
                    ClientConnection &connection,
                    const SendConfigurationValidityReportOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const SendConfigurationValidityReportRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class UpdateThingShadowOperationContext : public OperationModelContext
            {
              public:
                UpdateThingShadowOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class UpdateThingShadowOperation : public ClientOperation
            {
              public:
                UpdateThingShadowOperation(
                    ClientConnection &connection,
                    const UpdateThingShadowOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const UpdateThingShadowRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class UpdateConfigurationOperationContext : public OperationModelContext
            {
              public:
                UpdateConfigurationOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class UpdateConfigurationOperation : public ClientOperation
            {
              public:
                UpdateConfigurationOperation(
                    ClientConnection &connection,
                    const UpdateConfigurationOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const UpdateConfigurationRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class ValidateAuthorizationTokenOperationContext : public OperationModelContext
            {
              public:
                ValidateAuthorizationTokenOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class ValidateAuthorizationTokenOperation : public ClientOperation
            {
              public:
                ValidateAuthorizationTokenOperation(
                    ClientConnection &connection,
                    const ValidateAuthorizationTokenOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const ValidateAuthorizationTokenRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class RestartComponentOperationContext : public OperationModelContext
            {
              public:
                RestartComponentOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class RestartComponentOperation : public ClientOperation
            {
              public:
                RestartComponentOperation(
                    ClientConnection &connection,
                    const RestartComponentOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const RestartComponentRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class GetLocalDeploymentStatusOperationContext : public OperationModelContext
            {
              public:
                GetLocalDeploymentStatusOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class GetLocalDeploymentStatusOperation : public ClientOperation
            {
              public:
                GetLocalDeploymentStatusOperation(
                    ClientConnection &connection,
                    const GetLocalDeploymentStatusOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const GetLocalDeploymentStatusRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class GetSecretValueOperationContext : public OperationModelContext
            {
              public:
                GetSecretValueOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class GetSecretValueOperation : public ClientOperation
            {
              public:
                GetSecretValueOperation(
                    ClientConnection &connection,
                    const GetSecretValueOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const GetSecretValueRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class UpdateStateOperationContext : public OperationModelContext
            {
              public:
                UpdateStateOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class UpdateStateOperation : public ClientOperation
            {
              public:
                UpdateStateOperation(
                    ClientConnection &connection,
                    const UpdateStateOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const UpdateStateRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class ListNamedShadowsForThingOperationContext : public OperationModelContext
            {
              public:
                ListNamedShadowsForThingOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class ListNamedShadowsForThingOperation : public ClientOperation
            {
              public:
                ListNamedShadowsForThingOperation(
                    ClientConnection &connection,
                    const ListNamedShadowsForThingOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const ListNamedShadowsForThingRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class SubscribeToComponentUpdatesStreamHandler : public StreamResponseHandler
            {
              public:
                virtual void OnStreamEvent(ComponentUpdatePolicyEvents *response) { (void)response; }
                virtual bool OnStreamError(ServiceError *operationError, RpcError rpcError)
                {
                    (void)operationError;
                    (void)rpcError;
                    return true;
                }

                virtual bool OnStreamError(ResourceNotFoundError *operationError, RpcError rpcError)
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
            class SubscribeToComponentUpdatesOperationContext : public OperationModelContext
            {
              public:
                SubscribeToComponentUpdatesOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class SubscribeToComponentUpdatesOperation : public ClientOperation
            {
              public:
                SubscribeToComponentUpdatesOperation(
                    ClientConnection &connection,
                    SubscribeToComponentUpdatesStreamHandler *streamHandler,
                    const SubscribeToComponentUpdatesOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const SubscribeToComponentUpdatesRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class ListLocalDeploymentsOperationContext : public OperationModelContext
            {
              public:
                ListLocalDeploymentsOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class ListLocalDeploymentsOperation : public ClientOperation
            {
              public:
                ListLocalDeploymentsOperation(
                    ClientConnection &connection,
                    const ListLocalDeploymentsOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const ListLocalDeploymentsRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class StopComponentOperationContext : public OperationModelContext
            {
              public:
                StopComponentOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class StopComponentOperation : public ClientOperation
            {
              public:
                StopComponentOperation(
                    ClientConnection &connection,
                    const StopComponentOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const StopComponentRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class PauseComponentOperationContext : public OperationModelContext
            {
              public:
                PauseComponentOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class PauseComponentOperation : public ClientOperation
            {
              public:
                PauseComponentOperation(
                    ClientConnection &connection,
                    const PauseComponentOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const PauseComponentRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class CreateLocalDeploymentOperationContext : public OperationModelContext
            {
              public:
                CreateLocalDeploymentOperationContext(const GreengrassServiceModel &serviceModel) noexcept;
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

            class CreateLocalDeploymentOperation : public ClientOperation
            {
              public:
                CreateLocalDeploymentOperation(
                    ClientConnection &connection,
                    const CreateLocalDeploymentOperationContext &operationContext,
                    Crt::Allocator *allocator) noexcept;
                std::future<RpcError> Activate(
                    const CreateLocalDeploymentRequest &request,
                    OnMessageFlushCallback onMessageFlushCallback) noexcept;

              protected:
                Crt::String GetModelName() const noexcept override;
            };

            class GreengrassServiceModel : public ServiceModel
            {
              public:
                GreengrassServiceModel() noexcept;
                Crt::ScopedResource<OperationError> AllocateOperationErrorFromPayload(
                    const Crt::String &errorModelName,
                    Crt::StringView stringView,
                    Crt::Allocator *allocator) const noexcept override;
                void AssignModelNameToErrorResponse(Crt::String, ErrorResponseFactory) noexcept;

              private:
                friend class GreengrassIpcClient;
                SubscribeToIoTCoreOperationContext m_subscribeToIoTCoreOperationContext;
                ResumeComponentOperationContext m_resumeComponentOperationContext;
                PublishToIoTCoreOperationContext m_publishToIoTCoreOperationContext;
                SubscribeToConfigurationUpdateOperationContext m_subscribeToConfigurationUpdateOperationContext;
                DeleteThingShadowOperationContext m_deleteThingShadowOperationContext;
                DeferComponentUpdateOperationContext m_deferComponentUpdateOperationContext;
                SubscribeToValidateConfigurationUpdatesOperationContext
                    m_subscribeToValidateConfigurationUpdatesOperationContext;
                GetConfigurationOperationContext m_getConfigurationOperationContext;
                SubscribeToTopicOperationContext m_subscribeToTopicOperationContext;
                GetComponentDetailsOperationContext m_getComponentDetailsOperationContext;
                PublishToTopicOperationContext m_publishToTopicOperationContext;
                ListComponentsOperationContext m_listComponentsOperationContext;
                CreateDebugPasswordOperationContext m_createDebugPasswordOperationContext;
                GetThingShadowOperationContext m_getThingShadowOperationContext;
                SendConfigurationValidityReportOperationContext m_sendConfigurationValidityReportOperationContext;
                UpdateThingShadowOperationContext m_updateThingShadowOperationContext;
                UpdateConfigurationOperationContext m_updateConfigurationOperationContext;
                ValidateAuthorizationTokenOperationContext m_validateAuthorizationTokenOperationContext;
                RestartComponentOperationContext m_restartComponentOperationContext;
                GetLocalDeploymentStatusOperationContext m_getLocalDeploymentStatusOperationContext;
                GetSecretValueOperationContext m_getSecretValueOperationContext;
                UpdateStateOperationContext m_updateStateOperationContext;
                ListNamedShadowsForThingOperationContext m_listNamedShadowsForThingOperationContext;
                SubscribeToComponentUpdatesOperationContext m_subscribeToComponentUpdatesOperationContext;
                ListLocalDeploymentsOperationContext m_listLocalDeploymentsOperationContext;
                StopComponentOperationContext m_stopComponentOperationContext;
                PauseComponentOperationContext m_pauseComponentOperationContext;
                CreateLocalDeploymentOperationContext m_createLocalDeploymentOperationContext;
                Crt::Map<Crt::String, ErrorResponseFactory> m_modelNameToErrorResponse;
            };
        } // namespace Ipc
    }     // namespace Eventstreamrpc
} // namespace Aws
