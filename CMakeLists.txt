cmake_minimum_required(VERSION 3.25)
project(warframe)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_ROOT_DIR})
include_directories(${OPEN_SSL_HEADER_ROOT_DIR})

# Dependency websocketpp required for websockets
find_package(websocketpp CONFIG REQUIRED)

# RapidJSON library to quickly parse json
find_package(RapidJSON CONFIG REQUIRED)

# Add the 'include' directory to the include file search path
include_directories(${CMAKE_SOURCE_DIR}/include)

# Retrieve include directories for websocketpp and add them to our include directories
get_target_property(websocketpp_INCLUDE_DIRS websocketpp::websocketpp INTERFACE_INCLUDE_DIRECTORIES)
include_directories(${websocketpp_INCLUDE_DIRS})

add_library(warframe SHARED src/library.cpp example/main.cpp include/socket.h src/socket.cpp include/heartbeat.h include/payload.h include/gatewayevents/hello_gateway_event.h include/gateway_event_processor.h include/event-emitter/eventemitter.h include/event-emitter/eventdata.h include/event-emitter/hello-event.h include/eventbus.h include/event-emitter/eventmessage.h include/event-emitter/messagetype.h)
#target_include_directories(warframe PRIVATE ${websocketpp_INCLUDE_DIRS})
target_link_libraries(warframe
        PRIVATE ${OPENSSL_CRYPTO_LIBRARY}
        PRIVATE ${OPENSSL_SSL_LIBRARY}
        PRIVATE websocketpp::websocketpp
        PRIVATE rapidjson
        )

add_subdirectory(example)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

