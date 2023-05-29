cmake_minimum_required(VERSION 3.25)
project(warframe)

set(CMAKE_CXX_STANDARD 23)

# MacOS OpenSSL specific
set(OPEN_SSL_HEADER_ROOT_DIR "/nix/store/6zyv2ff4f4bsa5vbn4ylimnzzisak8ga-openssl-3.0.7-dev/include/")
set(OPENSSL_ROOT_DIR "/nix/store/in8nxwr1sjnncxzrqnprxlaxvfpvd5aq-openssl-3.0.7")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/lib/libcrypto.dylib")
set(OPENSSL_SSL_LIBRARY "${OPENSSL_ROOT_DIR}/lib/libssl.dylib")

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_ROOT_DIR})
include_directories(${OPEN_SSL_HEADER_ROOT_DIR})

# Dependency websocketpp required for websockets
find_package(websocketpp CONFIG REQUIRED)

# Add the 'include' directory to the include file search path
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(warframe SHARED src/library.cpp example/main.cpp)
target_link_libraries(warframe PRIVATE websocketpp::websocketpp)

add_subdirectory(example)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

