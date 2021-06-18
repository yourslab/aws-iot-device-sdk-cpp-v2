#pragma once
/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

/* This file is generated. */

#include <aws/eventstreamrpc/EventStreamClient.h>

#include <aws/crt/DateTime.h>
#include <aws/greengrass/Exports.h>

using namespace Aws::Eventstreamrpc;

namespace Aws
{
    namespace Greengrass
    {
        class GreengrassCoreIpcClient;
        class GreengrassCoreIpcServiceModel;
        class ValidateConfigurationUpdateEvent : public AbstractShapeBase
        {
          public:
            ValidateConfigurationUpdateEvent() noexcept {}
            ValidateConfigurationUpdateEvent(const ValidateConfigurationUpdateEvent &) = default;
            void SetConfiguration(const Crt::JsonObject &configuration) noexcept { m_configuration = configuration; }
            Crt::Optional<Crt::JsonObject> GetConfiguration() noexcept { return m_configuration; }
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
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

        class MQTTMessage : public AbstractShapeBase
        {
          public:
            MQTTMessage() noexcept {}
            MQTTMessage(const MQTTMessage &) = default;
            void SetTopicName(const Crt::String &topicName) noexcept { m_topicName = topicName; }
            Crt::Optional<Crt::String> GetTopicName() noexcept { return m_topicName; }
            void SetPayload(const Crt::Vector<uint8_t> &payload) noexcept { m_payload = payload; }
            Crt::Optional<Crt::Vector<uint8_t>> GetPayload() noexcept { return m_payload; }
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

        class ConfigurationUpdateEvent : public AbstractShapeBase
        {
          public:
            ConfigurationUpdateEvent() noexcept {}
            ConfigurationUpdateEvent(const ConfigurationUpdateEvent &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
            void SetKeyPath(const Crt::Vector<Crt::String> &keyPath) noexcept { m_keyPath = keyPath; }
            Crt::Optional<Crt::Vector<Crt::String>> GetKeyPath() noexcept { return m_keyPath; }
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

        class PostComponentUpdateEvent : public AbstractShapeBase
        {
          public:
            PostComponentUpdateEvent() noexcept {}
            PostComponentUpdateEvent(const PostComponentUpdateEvent &) = default;
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
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
            PreComponentUpdateEvent() noexcept {}
            PreComponentUpdateEvent(const PreComponentUpdateEvent &) = default;
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
            void SetIsGgcRestarting(const bool &isGgcRestarting) noexcept { m_isGgcRestarting = isGgcRestarting; }
            Crt::Optional<bool> GetIsGgcRestarting() noexcept { return m_isGgcRestarting; }
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

        enum ConfigurationValidityStatus
        {
            CONFIGURATION_VALIDITY_STATUS_ACCEPTED,
            CONFIGURATION_VALIDITY_STATUS_REJECTED
        };

        class BinaryMessage : public AbstractShapeBase
        {
          public:
            BinaryMessage() noexcept {}
            BinaryMessage(const BinaryMessage &) = default;
            void SetMessage(const Crt::Vector<uint8_t> &message) noexcept { m_message = message; }
            Crt::Optional<Crt::Vector<uint8_t>> GetMessage() noexcept { return m_message; }
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
            JsonMessage() noexcept {}
            JsonMessage(const JsonMessage &) = default;
            void SetMessage(const Crt::JsonObject &message) noexcept { m_message = message; }
            Crt::Optional<Crt::JsonObject> GetMessage() noexcept { return m_message; }
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

        enum DeploymentStatus
        {
            DEPLOYMENT_STATUS_QUEUED,
            DEPLOYMENT_STATUS_IN_PROGRESS,
            DEPLOYMENT_STATUS_SUCCEEDED,
            DEPLOYMENT_STATUS_FAILED
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

        class RunWithInfo : public AbstractShapeBase
        {
          public:
            RunWithInfo() noexcept {}
            RunWithInfo(const RunWithInfo &) = default;
            void SetPosixUser(const Crt::String &posixUser) noexcept { m_posixUser = posixUser; }
            Crt::Optional<Crt::String> GetPosixUser() noexcept { return m_posixUser; }
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
        };

        enum ReportedLifecycleState
        {
            REPORTED_LIFECYCLE_STATE_RUNNING,
            REPORTED_LIFECYCLE_STATE_ERRORED
        };

        class ValidateConfigurationUpdateEvents : public OperationResponse
        {
          public:
            ValidateConfigurationUpdateEvents() noexcept {}
            ValidateConfigurationUpdateEvents &operator=(const ValidateConfigurationUpdateEvents &) noexcept;
            ValidateConfigurationUpdateEvents(const ValidateConfigurationUpdateEvents &objectToCopy)
            {
                *this = objectToCopy;
            }
            void SetValidateConfigurationUpdateEvent(
                const ValidateConfigurationUpdateEvent &validateConfigurationUpdateEvent) noexcept
            {
                m_validateConfigurationUpdateEvent = validateConfigurationUpdateEvent;
                m_chosenMember = TAG_VALIDATE_CONFIGURATION_UPDATE_EVENT;
            }
            Crt::Optional<ValidateConfigurationUpdateEvent> GetValidateConfigurationUpdateEvent() noexcept
            {
                if (m_chosenMember == TAG_VALIDATE_CONFIGURATION_UPDATE_EVENT)
                {
                    return m_validateConfigurationUpdateEvent;
                }
                else
                {
                    return Crt::Optional<ValidateConfigurationUpdateEvent>();
                }
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
            enum ChosenMember
            {
                TAG_VALIDATE_CONFIGURATION_UPDATE_EVENT
            } m_chosenMember;
            Crt::Optional<ValidateConfigurationUpdateEvent> m_validateConfigurationUpdateEvent;
        };

        class SubscriptionResponseMessage : public OperationResponse
        {
          public:
            SubscriptionResponseMessage() noexcept {}
            SubscriptionResponseMessage &operator=(const SubscriptionResponseMessage &) noexcept;
            SubscriptionResponseMessage(const SubscriptionResponseMessage &objectToCopy) { *this = objectToCopy; }
            void SetJsonMessage(const JsonMessage &jsonMessage) noexcept
            {
                m_jsonMessage = jsonMessage;
                m_chosenMember = TAG_JSON_MESSAGE;
            }
            Crt::Optional<JsonMessage> GetJsonMessage() noexcept
            {
                if (m_chosenMember == TAG_JSON_MESSAGE)
                {
                    return m_jsonMessage;
                }
                else
                {
                    return Crt::Optional<JsonMessage>();
                }
            }
            void SetBinaryMessage(const BinaryMessage &binaryMessage) noexcept
            {
                m_binaryMessage = binaryMessage;
                m_chosenMember = TAG_BINARY_MESSAGE;
            }
            Crt::Optional<BinaryMessage> GetBinaryMessage() noexcept
            {
                if (m_chosenMember == TAG_BINARY_MESSAGE)
                {
                    return m_binaryMessage;
                }
                else
                {
                    return Crt::Optional<BinaryMessage>();
                }
            }
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
            enum ChosenMember
            {
                TAG_JSON_MESSAGE,
                TAG_BINARY_MESSAGE
            } m_chosenMember;
            Crt::Optional<JsonMessage> m_jsonMessage;
            Crt::Optional<BinaryMessage> m_binaryMessage;
        };

        class IoTCoreMessage : public OperationResponse
        {
          public:
            IoTCoreMessage() noexcept {}
            IoTCoreMessage &operator=(const IoTCoreMessage &) noexcept;
            IoTCoreMessage(const IoTCoreMessage &objectToCopy) { *this = objectToCopy; }
            void SetMessage(const MQTTMessage &message) noexcept
            {
                m_message = message;
                m_chosenMember = TAG_MESSAGE;
            }
            Crt::Optional<MQTTMessage> GetMessage() noexcept
            {
                if (m_chosenMember == TAG_MESSAGE)
                {
                    return m_message;
                }
                else
                {
                    return Crt::Optional<MQTTMessage>();
                }
            }
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
            enum ChosenMember
            {
                TAG_MESSAGE
            } m_chosenMember;
            Crt::Optional<MQTTMessage> m_message;
        };

        class ConfigurationUpdateEvents : public OperationResponse
        {
          public:
            ConfigurationUpdateEvents() noexcept {}
            ConfigurationUpdateEvents &operator=(const ConfigurationUpdateEvents &) noexcept;
            ConfigurationUpdateEvents(const ConfigurationUpdateEvents &objectToCopy) { *this = objectToCopy; }
            void SetConfigurationUpdateEvent(const ConfigurationUpdateEvent &configurationUpdateEvent) noexcept
            {
                m_configurationUpdateEvent = configurationUpdateEvent;
                m_chosenMember = TAG_CONFIGURATION_UPDATE_EVENT;
            }
            Crt::Optional<ConfigurationUpdateEvent> GetConfigurationUpdateEvent() noexcept
            {
                if (m_chosenMember == TAG_CONFIGURATION_UPDATE_EVENT)
                {
                    return m_configurationUpdateEvent;
                }
                else
                {
                    return Crt::Optional<ConfigurationUpdateEvent>();
                }
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
            enum ChosenMember
            {
                TAG_CONFIGURATION_UPDATE_EVENT
            } m_chosenMember;
            Crt::Optional<ConfigurationUpdateEvent> m_configurationUpdateEvent;
        };

        class ComponentUpdatePolicyEvents : public OperationResponse
        {
          public:
            ComponentUpdatePolicyEvents() noexcept {}
            ComponentUpdatePolicyEvents &operator=(const ComponentUpdatePolicyEvents &) noexcept;
            ComponentUpdatePolicyEvents(const ComponentUpdatePolicyEvents &objectToCopy) { *this = objectToCopy; }
            void SetPreUpdateEvent(const PreComponentUpdateEvent &preUpdateEvent) noexcept
            {
                m_preUpdateEvent = preUpdateEvent;
                m_chosenMember = TAG_PRE_UPDATE_EVENT;
            }
            Crt::Optional<PreComponentUpdateEvent> GetPreUpdateEvent() noexcept
            {
                if (m_chosenMember == TAG_PRE_UPDATE_EVENT)
                {
                    return m_preUpdateEvent;
                }
                else
                {
                    return Crt::Optional<PreComponentUpdateEvent>();
                }
            }
            void SetPostUpdateEvent(const PostComponentUpdateEvent &postUpdateEvent) noexcept
            {
                m_postUpdateEvent = postUpdateEvent;
                m_chosenMember = TAG_POST_UPDATE_EVENT;
            }
            Crt::Optional<PostComponentUpdateEvent> GetPostUpdateEvent() noexcept
            {
                if (m_chosenMember == TAG_POST_UPDATE_EVENT)
                {
                    return m_postUpdateEvent;
                }
                else
                {
                    return Crt::Optional<PostComponentUpdateEvent>();
                }
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
            enum ChosenMember
            {
                TAG_PRE_UPDATE_EVENT,
                TAG_POST_UPDATE_EVENT
            } m_chosenMember;
            Crt::Optional<PreComponentUpdateEvent> m_preUpdateEvent;
            Crt::Optional<PostComponentUpdateEvent> m_postUpdateEvent;
        };

        class ConfigurationValidityReport : public AbstractShapeBase
        {
          public:
            ConfigurationValidityReport() noexcept {}
            ConfigurationValidityReport(const ConfigurationValidityReport &) = default;
            void SetStatus(ConfigurationValidityStatus status) noexcept;
            Crt::Optional<ConfigurationValidityStatus> GetStatus() noexcept;
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept { return m_message; }
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

        enum RequestStatus
        {
            REQUEST_STATUS_SUCCEEDED,
            REQUEST_STATUS_FAILED
        };

        class PublishMessage : public AbstractShapeBase
        {
          public:
            PublishMessage() noexcept {}
            PublishMessage &operator=(const PublishMessage &) noexcept;
            PublishMessage(const PublishMessage &objectToCopy) { *this = objectToCopy; }
            void SetJsonMessage(const JsonMessage &jsonMessage) noexcept
            {
                m_jsonMessage = jsonMessage;
                m_chosenMember = TAG_JSON_MESSAGE;
            }
            Crt::Optional<JsonMessage> GetJsonMessage() noexcept
            {
                if (m_chosenMember == TAG_JSON_MESSAGE)
                {
                    return m_jsonMessage;
                }
                else
                {
                    return Crt::Optional<JsonMessage>();
                }
            }
            void SetBinaryMessage(const BinaryMessage &binaryMessage) noexcept
            {
                m_binaryMessage = binaryMessage;
                m_chosenMember = TAG_BINARY_MESSAGE;
            }
            Crt::Optional<BinaryMessage> GetBinaryMessage() noexcept
            {
                if (m_chosenMember == TAG_BINARY_MESSAGE)
                {
                    return m_binaryMessage;
                }
                else
                {
                    return Crt::Optional<BinaryMessage>();
                }
            }
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
            enum ChosenMember
            {
                TAG_JSON_MESSAGE,
                TAG_BINARY_MESSAGE
            } m_chosenMember;
            Crt::Optional<JsonMessage> m_jsonMessage;
            Crt::Optional<BinaryMessage> m_binaryMessage;
        };

        enum QOS
        {
            QOS_AT_MOST_ONCE,
            QOS_AT_LEAST_ONCE
        };

        class SecretValue : public AbstractShapeBase
        {
          public:
            SecretValue() noexcept {}
            SecretValue &operator=(const SecretValue &) noexcept;
            SecretValue(const SecretValue &objectToCopy) { *this = objectToCopy; }
            void SetSecretString(const Crt::String &secretString) noexcept
            {
                m_secretString = secretString;
                m_chosenMember = TAG_SECRET_STRING;
            }
            Crt::Optional<Crt::String> GetSecretString() noexcept
            {
                if (m_chosenMember == TAG_SECRET_STRING)
                {
                    return m_secretString;
                }
                else
                {
                    return Crt::Optional<Crt::String>();
                }
            }
            void SetSecretBinary(const Crt::Vector<uint8_t> &secretBinary) noexcept
            {
                m_secretBinary = secretBinary;
                m_chosenMember = TAG_SECRET_BINARY;
            }
            Crt::Optional<Crt::Vector<uint8_t>> GetSecretBinary() noexcept
            {
                if (m_chosenMember == TAG_SECRET_BINARY)
                {
                    return m_secretBinary;
                }
                else
                {
                    return Crt::Optional<Crt::Vector<uint8_t>>();
                }
            }
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
            enum ChosenMember
            {
                TAG_SECRET_STRING,
                TAG_SECRET_BINARY
            } m_chosenMember;
            Crt::Optional<Crt::String> m_secretString;
            Crt::Optional<Crt::Vector<uint8_t>> m_secretBinary;
        };

        class LocalDeployment : public AbstractShapeBase
        {
          public:
            LocalDeployment() noexcept {}
            LocalDeployment(const LocalDeployment &) = default;
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
            void SetStatus(DeploymentStatus status) noexcept;
            Crt::Optional<DeploymentStatus> GetStatus() noexcept;
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

        class ComponentDetails : public AbstractShapeBase
        {
          public:
            ComponentDetails() noexcept {}
            ComponentDetails(const ComponentDetails &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
            void SetVersion(const Crt::String &version) noexcept { m_version = version; }
            Crt::Optional<Crt::String> GetVersion() noexcept { return m_version; }
            void SetState(LifecycleState state) noexcept;
            Crt::Optional<LifecycleState> GetState() noexcept;
            void SetConfiguration(const Crt::JsonObject &configuration) noexcept { m_configuration = configuration; }
            Crt::Optional<Crt::JsonObject> GetConfiguration() noexcept { return m_configuration; }
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

        class InvalidTokenError : public OperationError
        {
          public:
            InvalidTokenError() noexcept {}
            InvalidTokenError(const InvalidTokenError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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
            ValidateAuthorizationTokenResponse() noexcept {}
            ValidateAuthorizationTokenResponse(const ValidateAuthorizationTokenResponse &) = default;
            void SetIsValid(const bool &isValid) noexcept { m_isValid = isValid; }
            Crt::Optional<bool> GetIsValid() noexcept { return m_isValid; }
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(ValidateAuthorizationTokenResponse &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(ValidateAuthorizationTokenResponse *) noexcept;
            /* This needs to be defined so that `ValidateAuthorizationTokenResponse` can be used as a key in maps. */
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
            ValidateAuthorizationTokenRequest() noexcept {}
            ValidateAuthorizationTokenRequest(const ValidateAuthorizationTokenRequest &) = default;
            void SetToken(const Crt::String &token) noexcept { m_token = token; }
            Crt::Optional<Crt::String> GetToken() noexcept { return m_token; }
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

        class UpdateThingShadowResponse : public OperationResponse
        {
          public:
            UpdateThingShadowResponse() noexcept {}
            UpdateThingShadowResponse(const UpdateThingShadowResponse &) = default;
            void SetPayload(const Crt::Vector<uint8_t> &payload) noexcept { m_payload = payload; }
            Crt::Optional<Crt::Vector<uint8_t>> GetPayload() noexcept { return m_payload; }
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
            UpdateThingShadowRequest() noexcept {}
            UpdateThingShadowRequest(const UpdateThingShadowRequest &) = default;
            void SetThingName(const Crt::String &thingName) noexcept { m_thingName = thingName; }
            Crt::Optional<Crt::String> GetThingName() noexcept { return m_thingName; }
            void SetShadowName(const Crt::String &shadowName) noexcept { m_shadowName = shadowName; }
            Crt::Optional<Crt::String> GetShadowName() noexcept { return m_shadowName; }
            void SetPayload(const Crt::Vector<uint8_t> &payload) noexcept { m_payload = payload; }
            Crt::Optional<Crt::Vector<uint8_t>> GetPayload() noexcept { return m_payload; }
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

        class UpdateStateResponse : public OperationResponse
        {
          public:
            UpdateStateResponse() noexcept {}
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
            UpdateStateRequest() noexcept {}
            UpdateStateRequest(const UpdateStateRequest &) = default;
            void SetState(ReportedLifecycleState state) noexcept;
            Crt::Optional<ReportedLifecycleState> GetState() noexcept;
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

        class FailedUpdateConditionCheckError : public OperationError
        {
          public:
            FailedUpdateConditionCheckError() noexcept {}
            FailedUpdateConditionCheckError(const FailedUpdateConditionCheckError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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

        class ConflictError : public OperationError
        {
          public:
            ConflictError() noexcept {}
            ConflictError(const ConflictError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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

        class UpdateConfigurationResponse : public OperationResponse
        {
          public:
            UpdateConfigurationResponse() noexcept {}
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
            UpdateConfigurationRequest() noexcept {}
            UpdateConfigurationRequest(const UpdateConfigurationRequest &) = default;
            void SetKeyPath(const Crt::Vector<Crt::String> &keyPath) noexcept { m_keyPath = keyPath; }
            Crt::Optional<Crt::Vector<Crt::String>> GetKeyPath() noexcept { return m_keyPath; }
            void SetTimestamp(const Crt::DateTime &timestamp) noexcept { m_timestamp = timestamp; }
            Crt::Optional<Crt::DateTime> GetTimestamp() noexcept { return m_timestamp; }
            void SetValueToMerge(const Crt::JsonObject &valueToMerge) noexcept { m_valueToMerge = valueToMerge; }
            Crt::Optional<Crt::JsonObject> GetValueToMerge() noexcept { return m_valueToMerge; }
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

        class SubscribeToValidateConfigurationUpdatesResponse : public OperationResponse
        {
          public:
            SubscribeToValidateConfigurationUpdatesResponse() noexcept {}
            SubscribeToValidateConfigurationUpdatesResponse(const SubscribeToValidateConfigurationUpdatesResponse &) =
                default;
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(
                SubscribeToValidateConfigurationUpdatesResponse &,
                const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(SubscribeToValidateConfigurationUpdatesResponse *) noexcept;
            /* This needs to be defined so that `SubscribeToValidateConfigurationUpdatesResponse` can be used as a key
             * in maps. */
            bool operator<(const SubscribeToValidateConfigurationUpdatesResponse &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
        };

        class SubscribeToValidateConfigurationUpdatesRequest : public OperationRequest
        {
          public:
            SubscribeToValidateConfigurationUpdatesRequest() noexcept {}
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
            /* This needs to be defined so that `SubscribeToValidateConfigurationUpdatesRequest` can be used as a key in
             * maps. */
            bool operator<(const SubscribeToValidateConfigurationUpdatesRequest &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
        };

        class SubscribeToTopicResponse : public OperationResponse
        {
          public:
            SubscribeToTopicResponse() noexcept {}
            SubscribeToTopicResponse(const SubscribeToTopicResponse &) = default;
            void SetTopicName(const Crt::String &topicName) noexcept { m_topicName = topicName; }
            Crt::Optional<Crt::String> GetTopicName() noexcept { return m_topicName; }
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
            SubscribeToTopicRequest() noexcept {}
            SubscribeToTopicRequest(const SubscribeToTopicRequest &) = default;
            void SetTopic(const Crt::String &topic) noexcept { m_topic = topic; }
            Crt::Optional<Crt::String> GetTopic() noexcept { return m_topic; }
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

        class SubscribeToIoTCoreResponse : public OperationResponse
        {
          public:
            SubscribeToIoTCoreResponse() noexcept {}
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
            SubscribeToIoTCoreRequest() noexcept {}
            SubscribeToIoTCoreRequest(const SubscribeToIoTCoreRequest &) = default;
            void SetTopicName(const Crt::String &topicName) noexcept { m_topicName = topicName; }
            Crt::Optional<Crt::String> GetTopicName() noexcept { return m_topicName; }
            void SetQos(QOS qos) noexcept;
            Crt::Optional<QOS> GetQos() noexcept;
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

        class SubscribeToConfigurationUpdateResponse : public OperationResponse
        {
          public:
            SubscribeToConfigurationUpdateResponse() noexcept {}
            SubscribeToConfigurationUpdateResponse(const SubscribeToConfigurationUpdateResponse &) = default;
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(SubscribeToConfigurationUpdateResponse &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(SubscribeToConfigurationUpdateResponse *) noexcept;
            /* This needs to be defined so that `SubscribeToConfigurationUpdateResponse` can be used as a key in maps.
             */
            bool operator<(const SubscribeToConfigurationUpdateResponse &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
        };

        class SubscribeToConfigurationUpdateRequest : public OperationRequest
        {
          public:
            SubscribeToConfigurationUpdateRequest() noexcept {}
            SubscribeToConfigurationUpdateRequest(const SubscribeToConfigurationUpdateRequest &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
            void SetKeyPath(const Crt::Vector<Crt::String> &keyPath) noexcept { m_keyPath = keyPath; }
            Crt::Optional<Crt::Vector<Crt::String>> GetKeyPath() noexcept { return m_keyPath; }
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(SubscribeToConfigurationUpdateRequest &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(SubscribeToConfigurationUpdateRequest *) noexcept;
            /* This needs to be defined so that `SubscribeToConfigurationUpdateRequest` can be used as a key in maps. */
            bool operator<(const SubscribeToConfigurationUpdateRequest &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
            Crt::Optional<Crt::String> m_componentName;
            Crt::Optional<Crt::Vector<Crt::String>> m_keyPath;
        };

        class SubscribeToComponentUpdatesResponse : public OperationResponse
        {
          public:
            SubscribeToComponentUpdatesResponse() noexcept {}
            SubscribeToComponentUpdatesResponse(const SubscribeToComponentUpdatesResponse &) = default;
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(SubscribeToComponentUpdatesResponse &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(SubscribeToComponentUpdatesResponse *) noexcept;
            /* This needs to be defined so that `SubscribeToComponentUpdatesResponse` can be used as a key in maps. */
            bool operator<(const SubscribeToComponentUpdatesResponse &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
        };

        class SubscribeToComponentUpdatesRequest : public OperationRequest
        {
          public:
            SubscribeToComponentUpdatesRequest() noexcept {}
            SubscribeToComponentUpdatesRequest(const SubscribeToComponentUpdatesRequest &) = default;
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(SubscribeToComponentUpdatesRequest &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(SubscribeToComponentUpdatesRequest *) noexcept;
            /* This needs to be defined so that `SubscribeToComponentUpdatesRequest` can be used as a key in maps. */
            bool operator<(const SubscribeToComponentUpdatesRequest &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
        };

        class StopComponentResponse : public OperationResponse
        {
          public:
            StopComponentResponse() noexcept {}
            StopComponentResponse(const StopComponentResponse &) = default;
            void SetStopStatus(RequestStatus stopStatus) noexcept;
            Crt::Optional<RequestStatus> GetStopStatus() noexcept;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept { return m_message; }
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
            StopComponentRequest() noexcept {}
            StopComponentRequest(const StopComponentRequest &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
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

        class SendConfigurationValidityReportResponse : public OperationResponse
        {
          public:
            SendConfigurationValidityReportResponse() noexcept {}
            SendConfigurationValidityReportResponse(const SendConfigurationValidityReportResponse &) = default;
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(SendConfigurationValidityReportResponse &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationResponse> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(SendConfigurationValidityReportResponse *) noexcept;
            /* This needs to be defined so that `SendConfigurationValidityReportResponse` can be used as a key in maps.
             */
            bool operator<(const SendConfigurationValidityReportResponse &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
        };

        class SendConfigurationValidityReportRequest : public OperationRequest
        {
          public:
            SendConfigurationValidityReportRequest() noexcept {}
            SendConfigurationValidityReportRequest(const SendConfigurationValidityReportRequest &) = default;
            void SetConfigurationValidityReport(const ConfigurationValidityReport &configurationValidityReport) noexcept
            {
                m_configurationValidityReport = configurationValidityReport;
            }
            Crt::Optional<ConfigurationValidityReport> GetConfigurationValidityReport() noexcept
            {
                return m_configurationValidityReport;
            }
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(SendConfigurationValidityReportRequest &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationRequest> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(SendConfigurationValidityReportRequest *) noexcept;
            /* This needs to be defined so that `SendConfigurationValidityReportRequest` can be used as a key in maps.
             */
            bool operator<(const SendConfigurationValidityReportRequest &) const noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;

          private:
            Crt::Allocator *m_allocator;
            Crt::Optional<ConfigurationValidityReport> m_configurationValidityReport;
        };

        class ComponentNotFoundError : public OperationError
        {
          public:
            ComponentNotFoundError() noexcept {}
            ComponentNotFoundError(const ComponentNotFoundError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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
            RestartComponentResponse() noexcept {}
            RestartComponentResponse(const RestartComponentResponse &) = default;
            void SetRestartStatus(RequestStatus restartStatus) noexcept;
            Crt::Optional<RequestStatus> GetRestartStatus() noexcept;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept { return m_message; }
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
            RestartComponentRequest() noexcept {}
            RestartComponentRequest(const RestartComponentRequest &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
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

        class PublishToTopicResponse : public OperationResponse
        {
          public:
            PublishToTopicResponse() noexcept {}
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
            PublishToTopicRequest() noexcept {}
            PublishToTopicRequest(const PublishToTopicRequest &) = default;
            void SetTopic(const Crt::String &topic) noexcept { m_topic = topic; }
            Crt::Optional<Crt::String> GetTopic() noexcept { return m_topic; }
            void SetPublishMessage(const PublishMessage &publishMessage) noexcept { m_publishMessage = publishMessage; }
            Crt::Optional<PublishMessage> GetPublishMessage() noexcept { return m_publishMessage; }
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

        class PublishToIoTCoreResponse : public OperationResponse
        {
          public:
            PublishToIoTCoreResponse() noexcept {}
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
            PublishToIoTCoreRequest() noexcept {}
            PublishToIoTCoreRequest(const PublishToIoTCoreRequest &) = default;
            void SetTopicName(const Crt::String &topicName) noexcept { m_topicName = topicName; }
            Crt::Optional<Crt::String> GetTopicName() noexcept { return m_topicName; }
            void SetQos(QOS qos) noexcept;
            Crt::Optional<QOS> GetQos() noexcept;
            void SetPayload(const Crt::Vector<uint8_t> &payload) noexcept { m_payload = payload; }
            Crt::Optional<Crt::Vector<uint8_t>> GetPayload() noexcept { return m_payload; }
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

        class ListNamedShadowsForThingResponse : public OperationResponse
        {
          public:
            ListNamedShadowsForThingResponse() noexcept {}
            ListNamedShadowsForThingResponse(const ListNamedShadowsForThingResponse &) = default;
            void SetResults(const Crt::Vector<Crt::String> &results) noexcept { m_results = results; }
            Crt::Optional<Crt::Vector<Crt::String>> GetResults() noexcept { return m_results; }
            void SetTimestamp(const Crt::DateTime &timestamp) noexcept { m_timestamp = timestamp; }
            Crt::Optional<Crt::DateTime> GetTimestamp() noexcept { return m_timestamp; }
            void SetNextToken(const Crt::String &nextToken) noexcept { m_nextToken = nextToken; }
            Crt::Optional<Crt::String> GetNextToken() noexcept { return m_nextToken; }
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
            ListNamedShadowsForThingRequest() noexcept {}
            ListNamedShadowsForThingRequest(const ListNamedShadowsForThingRequest &) = default;
            void SetThingName(const Crt::String &thingName) noexcept { m_thingName = thingName; }
            Crt::Optional<Crt::String> GetThingName() noexcept { return m_thingName; }
            void SetNextToken(const Crt::String &nextToken) noexcept { m_nextToken = nextToken; }
            Crt::Optional<Crt::String> GetNextToken() noexcept { return m_nextToken; }
            void SetPageSize(const int &pageSize) noexcept { m_pageSize = pageSize; }
            Crt::Optional<int> GetPageSize() noexcept { return m_pageSize; }
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

        class ListLocalDeploymentsResponse : public OperationResponse
        {
          public:
            ListLocalDeploymentsResponse() noexcept {}
            ListLocalDeploymentsResponse(const ListLocalDeploymentsResponse &) = default;
            void SetLocalDeployments(const Crt::Vector<LocalDeployment> &localDeployments) noexcept
            {
                m_localDeployments = localDeployments;
            }
            Crt::Optional<Crt::Vector<LocalDeployment>> GetLocalDeployments() noexcept { return m_localDeployments; }
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
            ListLocalDeploymentsRequest() noexcept {}
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

        class ListComponentsResponse : public OperationResponse
        {
          public:
            ListComponentsResponse() noexcept {}
            ListComponentsResponse(const ListComponentsResponse &) = default;
            void SetComponents(const Crt::Vector<ComponentDetails> &components) noexcept { m_components = components; }
            Crt::Optional<Crt::Vector<ComponentDetails>> GetComponents() noexcept { return m_components; }
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
            ListComponentsRequest() noexcept {}
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

        class GetThingShadowResponse : public OperationResponse
        {
          public:
            GetThingShadowResponse() noexcept {}
            GetThingShadowResponse(const GetThingShadowResponse &) = default;
            void SetPayload(const Crt::Vector<uint8_t> &payload) noexcept { m_payload = payload; }
            Crt::Optional<Crt::Vector<uint8_t>> GetPayload() noexcept { return m_payload; }
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
            GetThingShadowRequest() noexcept {}
            GetThingShadowRequest(const GetThingShadowRequest &) = default;
            void SetThingName(const Crt::String &thingName) noexcept { m_thingName = thingName; }
            Crt::Optional<Crt::String> GetThingName() noexcept { return m_thingName; }
            void SetShadowName(const Crt::String &shadowName) noexcept { m_shadowName = shadowName; }
            Crt::Optional<Crt::String> GetShadowName() noexcept { return m_shadowName; }
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

        class GetSecretValueResponse : public OperationResponse
        {
          public:
            GetSecretValueResponse() noexcept {}
            GetSecretValueResponse(const GetSecretValueResponse &) = default;
            void SetSecretId(const Crt::String &secretId) noexcept { m_secretId = secretId; }
            Crt::Optional<Crt::String> GetSecretId() noexcept { return m_secretId; }
            void SetVersionId(const Crt::String &versionId) noexcept { m_versionId = versionId; }
            Crt::Optional<Crt::String> GetVersionId() noexcept { return m_versionId; }
            void SetVersionStage(const Crt::Vector<Crt::String> &versionStage) noexcept
            {
                m_versionStage = versionStage;
            }
            Crt::Optional<Crt::Vector<Crt::String>> GetVersionStage() noexcept { return m_versionStage; }
            void SetSecretValue(const SecretValue &secretValue) noexcept { m_secretValue = secretValue; }
            Crt::Optional<SecretValue> GetSecretValue() noexcept { return m_secretValue; }
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
            GetSecretValueRequest() noexcept {}
            GetSecretValueRequest(const GetSecretValueRequest &) = default;
            void SetSecretId(const Crt::String &secretId) noexcept { m_secretId = secretId; }
            Crt::Optional<Crt::String> GetSecretId() noexcept { return m_secretId; }
            void SetVersionId(const Crt::String &versionId) noexcept { m_versionId = versionId; }
            Crt::Optional<Crt::String> GetVersionId() noexcept { return m_versionId; }
            void SetVersionStage(const Crt::String &versionStage) noexcept { m_versionStage = versionStage; }
            Crt::Optional<Crt::String> GetVersionStage() noexcept { return m_versionStage; }
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
            GetLocalDeploymentStatusResponse() noexcept {}
            GetLocalDeploymentStatusResponse(const GetLocalDeploymentStatusResponse &) = default;
            void SetDeployment(const LocalDeployment &deployment) noexcept { m_deployment = deployment; }
            Crt::Optional<LocalDeployment> GetDeployment() noexcept { return m_deployment; }
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
            GetLocalDeploymentStatusRequest() noexcept {}
            GetLocalDeploymentStatusRequest(const GetLocalDeploymentStatusRequest &) = default;
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
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

        class GetConfigurationResponse : public OperationResponse
        {
          public:
            GetConfigurationResponse() noexcept {}
            GetConfigurationResponse(const GetConfigurationResponse &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
            void SetValue(const Crt::JsonObject &value) noexcept { m_value = value; }
            Crt::Optional<Crt::JsonObject> GetValue() noexcept { return m_value; }
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
            GetConfigurationRequest() noexcept {}
            GetConfigurationRequest(const GetConfigurationRequest &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
            void SetKeyPath(const Crt::Vector<Crt::String> &keyPath) noexcept { m_keyPath = keyPath; }
            Crt::Optional<Crt::Vector<Crt::String>> GetKeyPath() noexcept { return m_keyPath; }
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

        class GetComponentDetailsResponse : public OperationResponse
        {
          public:
            GetComponentDetailsResponse() noexcept {}
            GetComponentDetailsResponse(const GetComponentDetailsResponse &) = default;
            void SetComponentDetails(const ComponentDetails &componentDetails) noexcept
            {
                m_componentDetails = componentDetails;
            }
            Crt::Optional<ComponentDetails> GetComponentDetails() noexcept { return m_componentDetails; }
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
            GetComponentDetailsRequest() noexcept {}
            GetComponentDetailsRequest(const GetComponentDetailsRequest &) = default;
            void SetComponentName(const Crt::String &componentName) noexcept { m_componentName = componentName; }
            Crt::Optional<Crt::String> GetComponentName() noexcept { return m_componentName; }
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

        class DeleteThingShadowResponse : public OperationResponse
        {
          public:
            DeleteThingShadowResponse() noexcept {}
            DeleteThingShadowResponse(const DeleteThingShadowResponse &) = default;
            void SetPayload(const Crt::Vector<uint8_t> &payload) noexcept { m_payload = payload; }
            Crt::Optional<Crt::Vector<uint8_t>> GetPayload() noexcept { return m_payload; }
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
            DeleteThingShadowRequest() noexcept {}
            DeleteThingShadowRequest(const DeleteThingShadowRequest &) = default;
            void SetThingName(const Crt::String &thingName) noexcept { m_thingName = thingName; }
            Crt::Optional<Crt::String> GetThingName() noexcept { return m_thingName; }
            void SetShadowName(const Crt::String &shadowName) noexcept { m_shadowName = shadowName; }
            Crt::Optional<Crt::String> GetShadowName() noexcept { return m_shadowName; }
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

        class ResourceNotFoundError : public OperationError
        {
          public:
            ResourceNotFoundError() noexcept {}
            ResourceNotFoundError(const ResourceNotFoundError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
            void SetResourceType(const Crt::String &resourceType) noexcept { m_resourceType = resourceType; }
            Crt::Optional<Crt::String> GetResourceType() noexcept { return m_resourceType; }
            void SetResourceName(const Crt::String &resourceName) noexcept { m_resourceName = resourceName; }
            Crt::Optional<Crt::String> GetResourceName() noexcept { return m_resourceName; }
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

        class DeferComponentUpdateResponse : public OperationResponse
        {
          public:
            DeferComponentUpdateResponse() noexcept {}
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
            DeferComponentUpdateRequest() noexcept {}
            DeferComponentUpdateRequest(const DeferComponentUpdateRequest &) = default;
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept { return m_message; }
            void SetRecheckAfterMs(const int64_t &recheckAfterMs) noexcept { m_recheckAfterMs = recheckAfterMs; }
            Crt::Optional<int64_t> GetRecheckAfterMs() noexcept { return m_recheckAfterMs; }
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
            Crt::Optional<int64_t> m_recheckAfterMs;
        };

        class InvalidArgumentsError : public OperationError
        {
          public:
            InvalidArgumentsError() noexcept {}
            InvalidArgumentsError(const InvalidArgumentsError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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

        class InvalidArtifactsDirectoryPathError : public OperationError
        {
          public:
            InvalidArtifactsDirectoryPathError() noexcept {}
            InvalidArtifactsDirectoryPathError(const InvalidArtifactsDirectoryPathError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
            void SerializeToJsonObject(Crt::JsonObject &payloadObject) const noexcept override;
            static void s_loadFromJsonView(InvalidArtifactsDirectoryPathError &, const Crt::JsonView &) noexcept;
            static Crt::ScopedResource<OperationError> s_allocateFromPayload(
                Crt::StringView,
                Crt::Allocator *) noexcept;
            static void s_customDeleter(InvalidArtifactsDirectoryPathError *) noexcept;
            /* This needs to be defined so that `InvalidArtifactsDirectoryPathError` can be used as a key in maps. */
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
            InvalidRecipeDirectoryPathError() noexcept {}
            InvalidRecipeDirectoryPathError(const InvalidRecipeDirectoryPathError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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
            CreateLocalDeploymentResponse() noexcept {}
            CreateLocalDeploymentResponse(const CreateLocalDeploymentResponse &) = default;
            void SetDeploymentId(const Crt::String &deploymentId) noexcept { m_deploymentId = deploymentId; }
            Crt::Optional<Crt::String> GetDeploymentId() noexcept { return m_deploymentId; }
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
            CreateLocalDeploymentRequest() noexcept {}
            CreateLocalDeploymentRequest(const CreateLocalDeploymentRequest &) = default;
            void SetGroupName(const Crt::String &groupName) noexcept { m_groupName = groupName; }
            Crt::Optional<Crt::String> GetGroupName() noexcept { return m_groupName; }
            void SetRootComponentVersionsToAdd(
                const Crt::Map<Crt::String, Crt::String> &rootComponentVersionsToAdd) noexcept
            {
                m_rootComponentVersionsToAdd = rootComponentVersionsToAdd;
            }
            Crt::Optional<Crt::Map<Crt::String, Crt::String>> GetRootComponentVersionsToAdd() noexcept
            {
                return m_rootComponentVersionsToAdd;
            }
            void SetRootComponentsToRemove(const Crt::Vector<Crt::String> &rootComponentsToRemove) noexcept
            {
                m_rootComponentsToRemove = rootComponentsToRemove;
            }
            Crt::Optional<Crt::Vector<Crt::String>> GetRootComponentsToRemove() noexcept
            {
                return m_rootComponentsToRemove;
            }
            void SetComponentToConfiguration(
                const Crt::Map<Crt::String, Crt::JsonObject> &componentToConfiguration) noexcept
            {
                m_componentToConfiguration = componentToConfiguration;
            }
            Crt::Optional<Crt::Map<Crt::String, Crt::JsonObject>> GetComponentToConfiguration() noexcept
            {
                return m_componentToConfiguration;
            }
            void SetComponentToRunWithInfo(const Crt::Map<Crt::String, RunWithInfo> &componentToRunWithInfo) noexcept
            {
                m_componentToRunWithInfo = componentToRunWithInfo;
            }
            Crt::Optional<Crt::Map<Crt::String, RunWithInfo>> GetComponentToRunWithInfo() noexcept
            {
                return m_componentToRunWithInfo;
            }
            void SetRecipeDirectoryPath(const Crt::String &recipeDirectoryPath) noexcept
            {
                m_recipeDirectoryPath = recipeDirectoryPath;
            }
            Crt::Optional<Crt::String> GetRecipeDirectoryPath() noexcept { return m_recipeDirectoryPath; }
            void SetArtifactsDirectoryPath(const Crt::String &artifactsDirectoryPath) noexcept
            {
                m_artifactsDirectoryPath = artifactsDirectoryPath;
            }
            Crt::Optional<Crt::String> GetArtifactsDirectoryPath() noexcept { return m_artifactsDirectoryPath; }
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

        class ServiceError : public OperationError
        {
          public:
            ServiceError() noexcept {}
            ServiceError(const ServiceError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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

        class UnauthorizedError : public OperationError
        {
          public:
            UnauthorizedError() noexcept {}
            UnauthorizedError(const UnauthorizedError &) = default;
            void SetMessage(const Crt::String &message) noexcept { m_message = message; }
            Crt::Optional<Crt::String> GetMessage() noexcept override { return m_message; }
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

        class CreateDebugPasswordResponse : public OperationResponse
        {
          public:
            CreateDebugPasswordResponse() noexcept {}
            CreateDebugPasswordResponse(const CreateDebugPasswordResponse &) = default;
            void SetPassword(const Crt::String &password) noexcept { m_password = password; }
            Crt::Optional<Crt::String> GetPassword() noexcept { return m_password; }
            void SetUsername(const Crt::String &username) noexcept { m_username = username; }
            Crt::Optional<Crt::String> GetUsername() noexcept { return m_username; }
            void SetPasswordExpiration(const Crt::DateTime &passwordExpiration) noexcept
            {
                m_passwordExpiration = passwordExpiration;
            }
            Crt::Optional<Crt::DateTime> GetPasswordExpiration() noexcept { return m_passwordExpiration; }
            void SetCertificateSHA256Hash(const Crt::String &certificateSHA256Hash) noexcept
            {
                m_certificateSHA256Hash = certificateSHA256Hash;
            }
            Crt::Optional<Crt::String> GetCertificateSHA256Hash() noexcept { return m_certificateSHA256Hash; }
            void SetCertificateSHA1Hash(const Crt::String &certificateSHA1Hash) noexcept
            {
                m_certificateSHA1Hash = certificateSHA1Hash;
            }
            Crt::Optional<Crt::String> GetCertificateSHA1Hash() noexcept { return m_certificateSHA1Hash; }
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
            CreateDebugPasswordRequest() noexcept {}
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
            SubscribeToIoTCoreOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class SubscribeToIoTCoreResult
        {
          public:
            SubscribeToIoTCoreResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            SubscribeToIoTCoreResponse *GetOperationResponse() const noexcept
            {
                return static_cast<SubscribeToIoTCoreResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<SubscribeToIoTCoreResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class PublishToIoTCoreOperationContext : public OperationModelContext
        {
          public:
            PublishToIoTCoreOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class PublishToIoTCoreResult
        {
          public:
            PublishToIoTCoreResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            PublishToIoTCoreResponse *GetOperationResponse() const noexcept
            {
                return static_cast<PublishToIoTCoreResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<PublishToIoTCoreResult> GetResult() noexcept;

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
            SubscribeToConfigurationUpdateOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class SubscribeToConfigurationUpdateResult
        {
          public:
            SubscribeToConfigurationUpdateResult(TaggedResult &&taggedResult) noexcept
                : m_taggedResult(std::move(taggedResult))
            {
            }
            SubscribeToConfigurationUpdateResponse *GetOperationResponse() const noexcept
            {
                return static_cast<SubscribeToConfigurationUpdateResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<SubscribeToConfigurationUpdateResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class DeleteThingShadowOperationContext : public OperationModelContext
        {
          public:
            DeleteThingShadowOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class DeleteThingShadowResult
        {
          public:
            DeleteThingShadowResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            DeleteThingShadowResponse *GetOperationResponse() const noexcept
            {
                return static_cast<DeleteThingShadowResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<DeleteThingShadowResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class DeferComponentUpdateOperationContext : public OperationModelContext
        {
          public:
            DeferComponentUpdateOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class DeferComponentUpdateResult
        {
          public:
            DeferComponentUpdateResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult))
            {
            }
            DeferComponentUpdateResponse *GetOperationResponse() const noexcept
            {
                return static_cast<DeferComponentUpdateResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<DeferComponentUpdateResult> GetResult() noexcept;

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
                const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class SubscribeToValidateConfigurationUpdatesResult
        {
          public:
            SubscribeToValidateConfigurationUpdatesResult(TaggedResult &&taggedResult) noexcept
                : m_taggedResult(std::move(taggedResult))
            {
            }
            SubscribeToValidateConfigurationUpdatesResponse *GetOperationResponse() const noexcept
            {
                return static_cast<SubscribeToValidateConfigurationUpdatesResponse *>(
                    m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<SubscribeToValidateConfigurationUpdatesResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class GetConfigurationOperationContext : public OperationModelContext
        {
          public:
            GetConfigurationOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class GetConfigurationResult
        {
          public:
            GetConfigurationResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            GetConfigurationResponse *GetOperationResponse() const noexcept
            {
                return static_cast<GetConfigurationResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<GetConfigurationResult> GetResult() noexcept;

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
            SubscribeToTopicOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class SubscribeToTopicResult
        {
          public:
            SubscribeToTopicResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            SubscribeToTopicResponse *GetOperationResponse() const noexcept
            {
                return static_cast<SubscribeToTopicResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<SubscribeToTopicResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class GetComponentDetailsOperationContext : public OperationModelContext
        {
          public:
            GetComponentDetailsOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class GetComponentDetailsResult
        {
          public:
            GetComponentDetailsResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            GetComponentDetailsResponse *GetOperationResponse() const noexcept
            {
                return static_cast<GetComponentDetailsResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<GetComponentDetailsResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class PublishToTopicOperationContext : public OperationModelContext
        {
          public:
            PublishToTopicOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class PublishToTopicResult
        {
          public:
            PublishToTopicResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            PublishToTopicResponse *GetOperationResponse() const noexcept
            {
                return static_cast<PublishToTopicResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<PublishToTopicResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class ListComponentsOperationContext : public OperationModelContext
        {
          public:
            ListComponentsOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class ListComponentsResult
        {
          public:
            ListComponentsResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            ListComponentsResponse *GetOperationResponse() const noexcept
            {
                return static_cast<ListComponentsResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<ListComponentsResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class CreateDebugPasswordOperationContext : public OperationModelContext
        {
          public:
            CreateDebugPasswordOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class CreateDebugPasswordResult
        {
          public:
            CreateDebugPasswordResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            CreateDebugPasswordResponse *GetOperationResponse() const noexcept
            {
                return static_cast<CreateDebugPasswordResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<CreateDebugPasswordResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class GetThingShadowOperationContext : public OperationModelContext
        {
          public:
            GetThingShadowOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class GetThingShadowResult
        {
          public:
            GetThingShadowResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            GetThingShadowResponse *GetOperationResponse() const noexcept
            {
                return static_cast<GetThingShadowResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<GetThingShadowResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class SendConfigurationValidityReportOperationContext : public OperationModelContext
        {
          public:
            SendConfigurationValidityReportOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class SendConfigurationValidityReportResult
        {
          public:
            SendConfigurationValidityReportResult(TaggedResult &&taggedResult) noexcept
                : m_taggedResult(std::move(taggedResult))
            {
            }
            SendConfigurationValidityReportResponse *GetOperationResponse() const noexcept
            {
                return static_cast<SendConfigurationValidityReportResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<SendConfigurationValidityReportResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class UpdateThingShadowOperationContext : public OperationModelContext
        {
          public:
            UpdateThingShadowOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class UpdateThingShadowResult
        {
          public:
            UpdateThingShadowResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            UpdateThingShadowResponse *GetOperationResponse() const noexcept
            {
                return static_cast<UpdateThingShadowResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<UpdateThingShadowResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class UpdateConfigurationOperationContext : public OperationModelContext
        {
          public:
            UpdateConfigurationOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class UpdateConfigurationResult
        {
          public:
            UpdateConfigurationResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            UpdateConfigurationResponse *GetOperationResponse() const noexcept
            {
                return static_cast<UpdateConfigurationResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<UpdateConfigurationResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class ValidateAuthorizationTokenOperationContext : public OperationModelContext
        {
          public:
            ValidateAuthorizationTokenOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class ValidateAuthorizationTokenResult
        {
          public:
            ValidateAuthorizationTokenResult(TaggedResult &&taggedResult) noexcept
                : m_taggedResult(std::move(taggedResult))
            {
            }
            ValidateAuthorizationTokenResponse *GetOperationResponse() const noexcept
            {
                return static_cast<ValidateAuthorizationTokenResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<ValidateAuthorizationTokenResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class RestartComponentOperationContext : public OperationModelContext
        {
          public:
            RestartComponentOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class RestartComponentResult
        {
          public:
            RestartComponentResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            RestartComponentResponse *GetOperationResponse() const noexcept
            {
                return static_cast<RestartComponentResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<RestartComponentResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class GetLocalDeploymentStatusOperationContext : public OperationModelContext
        {
          public:
            GetLocalDeploymentStatusOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class GetLocalDeploymentStatusResult
        {
          public:
            GetLocalDeploymentStatusResult(TaggedResult &&taggedResult) noexcept
                : m_taggedResult(std::move(taggedResult))
            {
            }
            GetLocalDeploymentStatusResponse *GetOperationResponse() const noexcept
            {
                return static_cast<GetLocalDeploymentStatusResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<GetLocalDeploymentStatusResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class GetSecretValueOperationContext : public OperationModelContext
        {
          public:
            GetSecretValueOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class GetSecretValueResult
        {
          public:
            GetSecretValueResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            GetSecretValueResponse *GetOperationResponse() const noexcept
            {
                return static_cast<GetSecretValueResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<GetSecretValueResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class UpdateStateOperationContext : public OperationModelContext
        {
          public:
            UpdateStateOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class UpdateStateResult
        {
          public:
            UpdateStateResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            UpdateStateResponse *GetOperationResponse() const noexcept
            {
                return static_cast<UpdateStateResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<UpdateStateResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class ListNamedShadowsForThingOperationContext : public OperationModelContext
        {
          public:
            ListNamedShadowsForThingOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class ListNamedShadowsForThingResult
        {
          public:
            ListNamedShadowsForThingResult(TaggedResult &&taggedResult) noexcept
                : m_taggedResult(std::move(taggedResult))
            {
            }
            ListNamedShadowsForThingResponse *GetOperationResponse() const noexcept
            {
                return static_cast<ListNamedShadowsForThingResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<ListNamedShadowsForThingResult> GetResult() noexcept;

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
            SubscribeToComponentUpdatesOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class SubscribeToComponentUpdatesResult
        {
          public:
            SubscribeToComponentUpdatesResult(TaggedResult &&taggedResult) noexcept
                : m_taggedResult(std::move(taggedResult))
            {
            }
            SubscribeToComponentUpdatesResponse *GetOperationResponse() const noexcept
            {
                return static_cast<SubscribeToComponentUpdatesResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<SubscribeToComponentUpdatesResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class ListLocalDeploymentsOperationContext : public OperationModelContext
        {
          public:
            ListLocalDeploymentsOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class ListLocalDeploymentsResult
        {
          public:
            ListLocalDeploymentsResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult))
            {
            }
            ListLocalDeploymentsResponse *GetOperationResponse() const noexcept
            {
                return static_cast<ListLocalDeploymentsResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<ListLocalDeploymentsResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class StopComponentOperationContext : public OperationModelContext
        {
          public:
            StopComponentOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class StopComponentResult
        {
          public:
            StopComponentResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult)) {}
            StopComponentResponse *GetOperationResponse() const noexcept
            {
                return static_cast<StopComponentResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<StopComponentResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class CreateLocalDeploymentOperationContext : public OperationModelContext
        {
          public:
            CreateLocalDeploymentOperationContext(const GreengrassCoreIpcServiceModel &serviceModel) noexcept;
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

        class CreateLocalDeploymentResult
        {
          public:
            CreateLocalDeploymentResult(TaggedResult &&taggedResult) noexcept : m_taggedResult(std::move(taggedResult))
            {
            }
            CreateLocalDeploymentResponse *GetOperationResponse() const noexcept
            {
                return static_cast<CreateLocalDeploymentResponse *>(m_taggedResult.GetOperationResponse());
            }
            OperationError *GetOperationError() const noexcept { return m_taggedResult.GetOperationError(); }
            RpcError GetRpcError() const noexcept { return m_taggedResult.GetRpcError(); }
            ResultType GetResultType() const noexcept { return m_taggedResult.GetResultType(); }

          private:
            TaggedResult m_taggedResult;
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
            std::future<CreateLocalDeploymentResult> GetResult() noexcept;

          protected:
            Crt::String GetModelName() const noexcept override;
        };

        class GreengrassCoreIpcServiceModel : public ServiceModel
        {
          public:
            GreengrassCoreIpcServiceModel() noexcept;
            Crt::ScopedResource<OperationError> AllocateOperationErrorFromPayload(
                const Crt::String &errorModelName,
                Crt::StringView stringView,
                Crt::Allocator *allocator) const noexcept override;
            void AssignModelNameToErrorResponse(Crt::String, ErrorResponseFactory) noexcept;

          private:
            friend class GreengrassCoreIpcClient;
            SubscribeToIoTCoreOperationContext m_subscribeToIoTCoreOperationContext;
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
            CreateLocalDeploymentOperationContext m_createLocalDeploymentOperationContext;
            Crt::Map<Crt::String, ErrorResponseFactory> m_modelNameToErrorResponse;
        };
    } // namespace Greengrass
} // namespace Aws
