cmake_minimum_required(VERSION 3.26)
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
set(PROJECT_SRC_DIR ${PROJECT_ROOT_DIR}/src)

option(DEBUG "" ON)
option(PWN_LOG_USE_COLOR "" OFF)
option(PWN_BUILD_TESTING "" OFF)
option(PWN_BUILD_TOOLKIT "" OFF)
option(PWN_BUILD_DOCS "" OFF)
option(PWN_ENABLE_LUA_BACKDOOR "" OFF)
option(PWN_DISASSEMBLE_X86 "" OFF)
option(PWN_DISASSEMBLE_ARM64 "" OFF)

include(FetchContent)
FetchContent_Declare(
    pwn++
    GIT_REPOSITORY https://github.com/hugsy/pwn--.git
    GIT_TAG main
)
FetchContent_MakeAvailable(pwn++)

add_executable(${PROJECT_NAME}
    ${PROJECT_SRC_DIR}/main.cpp
)

add_dependencies(${PROJECT_NAME} pwn++)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_include_directories(${PROJECT_NAME} PUBLIC $<TARGET_PROPERTY:pwn++,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_definitions(${PROJECT_NAME} PRIVATE $<TARGET_PROPERTY:pwn++,INTERFACE_COMPILE_DEFINITIONS>)
target_compile_options(${PROJECT_NAME} PRIVATE $<TARGET_PROPERTY:pwn++,INTERFACE_COMPILE_OPTIONS>)
target_link_options(${PROJECT_NAME} PRIVATE $<TARGET_PROPERTY:pwn++,INTERFACE_LINK_OPTIONS> /SUBSYSTEM:Console)
target_link_libraries(${PROJECT_NAME} PRIVATE pwn++ $<TARGET_PROPERTY:pwn++,INTERFACE_LINK_LIBRARIES>)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
