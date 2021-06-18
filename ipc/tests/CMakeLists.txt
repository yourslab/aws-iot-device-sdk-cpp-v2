include(AwsTestHarness)
enable_testing()
include(CTest)

file(GLOB AWS_ECHOTESTRPC_HEADERS
        "include/awstest/*.h"
)

file(GLOB AWS_ECHOTESTRPC_SRC
        "EchoTestRpcClient.cpp"
        "EchoTestRpcModel.cpp"
)

if (WIN32)
    if (MSVC)
        source_group("Header Files\\awstest\\" FILES ${AWS_ECHOTESTRPC_HEADERS})
        source_group("Source Files" FILES ${AWS_ECHOTESTRPC_SRC})
    endif ()
endif()

install(FILES ${AWS_ECHOTESTRPC_HEADERS} DESTINATION "include/awstest/" COMPONENT Development)

file(GLOB TEST_SRC "*.cpp")
file(GLOB TEST_HDRS "*.h")
file(GLOB TESTS ${TEST_HDRS} ${TEST_SRC})

set(TEST_BINARY_NAME ${PROJECT_NAME}-tests)

aws_use_package(aws-crt-cpp)
aws_use_package(GreengrassIpc-cpp)

if (UNIX AND NOT APPLE)
    generate_cpp_test_driver(${TEST_BINARY_NAME})
endif()
