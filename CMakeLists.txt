cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION True)
set(CXX_STANDARD 20)

project(
    ChangeMe
    DESCRIPTION "ChangeMe"
    HOMEPAGE_URL https://github.com/hugsy/ChangeMe
)

set(PROJECT_AUTHOR hugsy)
set(PROJECT_LICENSE MIT)
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

option(DEBUG                      ""        ON)
option(PWN_LOG_USE_COLOR          ""        OFF)
option(PWN_BUILD_TESTING          ""        OFF)
option(PWN_BUILD_TOOLKIT          ""        OFF)
option(PWN_BUILD_DOCS             ""        OFF)
option(PWN_ENABLE_LUA_BACKDOOR    ""        OFF)
option(PWN_DISASSEMBLE_X86        ""        OFF)
option(PWN_DISASSEMBLE_ARM64      ""        OFF)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/pwn++)
add_subdirectory(src)
