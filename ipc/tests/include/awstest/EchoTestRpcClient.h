#pragma once
/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

/* This file is generated. */

#include <awstest/EchoTestRpcModel.h>

using namespace Aws::Eventstreamrpc;

namespace Awstest
{
    class DefaultConnectionConfig : public ConnectionConfig
    {
      public:
        DefaultConnectionConfig() noexcept;
    };

    class EchoTestRpcClient
    {
      public:
        EchoTestRpcClient(
            Crt::Io::ClientBootstrap &clientBootstrap,
            Crt::Allocator *allocator = Crt::g_allocator) noexcept;
        std::future<RpcError> Connect(
            ConnectionLifecycleHandler &lifecycleHandler,
            ConnectionConfig connectionConfig = DefaultConnectionConfig()) noexcept;
        void Close() noexcept;
        GetAllProductsOperation NewGetAllProducts() noexcept;
        CauseServiceErrorOperation NewCauseServiceError() noexcept;
        CauseStreamServiceToErrorOperation NewCauseStreamServiceToError(
            CauseStreamServiceToErrorStreamHandler &) noexcept;
        EchoStreamMessagesOperation NewEchoStreamMessages(EchoStreamMessagesStreamHandler &) noexcept;
        EchoMessageOperation NewEchoMessage() noexcept;
        GetAllCustomersOperation NewGetAllCustomers() noexcept;
        ~EchoTestRpcClient() noexcept;

      private:
        EchoTestRpcServiceModel m_echoTestRpcServiceModel;
        ClientConnection m_connection;
        Crt::Io::ClientBootstrap &m_clientBootstrap;
        Crt::Allocator *m_allocator;
        MessageAmendment m_connectAmendment;
    };
} // namespace Awstest
