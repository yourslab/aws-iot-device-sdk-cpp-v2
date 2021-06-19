/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */
#include <aws/crt/Api.h>

#include <awstest/EchoTestRpcClient.h>

#include <aws/testing/aws_test_harness.h>

#include <iostream>
#include <sstream>

using namespace Aws::Eventstreamrpc;

static int s_connectToServer(struct aws_allocator *allocator, void *ctx);

static int s_connectToServer(struct aws_allocator *allocator, void *ctx)
{
    (void)ctx;
    {
        Aws::Crt::ApiHandle apiHandle(allocator);
        Aws::Crt::Io::TlsContextOptions tlsCtxOptions = Aws::Crt::Io::TlsContextOptions::InitDefaultClient();
        Aws::Crt::Io::TlsContext tlsContext(tlsCtxOptions, Aws::Crt::Io::TlsMode::CLIENT, allocator);
        ASSERT_TRUE(tlsContext);

        Aws::Crt::Io::TlsConnectionOptions tlsConnectionOptions = tlsContext.NewConnectionOptions();

        Aws::Crt::Io::EventLoopGroup eventLoopGroup(0, allocator);
        ASSERT_TRUE(eventLoopGroup);

        Aws::Crt::Io::DefaultHostResolver socketResolver(eventLoopGroup, 8, 30, allocator);
        ASSERT_TRUE(socketResolver);

        Aws::Crt::Io::ClientBootstrap clientBootstrap(eventLoopGroup, socketResolver, allocator);
        ASSERT_TRUE(clientBootstrap);
        clientBootstrap.EnableBlockingShutdown();
        MessageAmendment connectionAmendment;
        auto messageAmender = [&](void) -> MessageAmendment & { return connectionAmendment; };

        ConnectionLifecycleHandler lifecycleHandler;
        Awstest::EchoTestRpcClient client(clientBootstrap);
        // auto connectedStatus = client.Connect(lifecycleHandler);
        // ASSERT_TRUE(connectedStatus.get().baseStatus == EVENT_STREAM_RPC_SUCCESS);

        client.Close();
    }

    return AWS_OP_SUCCESS;
}

AWS_TEST_CASE(EventStreamConnect, s_connectToServer)
