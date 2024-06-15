cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION True)
set(CXX_STANDARD 23)

project(
    ChangeMe
    DESCRIPTION "ChangeMe"
    HOMEPAGE_URL https://github.com/hugsy/ChangeMe
)

set(PROJECT_AUTHOR hugsy)
set(PROJECT_LICENSE MIT)
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(PROJECT_SRC_DIR ${PROJECT_ROOT_DIR}/src)

set(DEBUG OFF)
set(PWN_LOG_USE_COLOR ON)
set(PWN_BUILD_TESTING OFF)
set(PWN_BUILD_TOOLKIT OFF)
set(PWN_BUILD_DOCS OFF)
set(PWN_DISASSEMBLE_X86 OFF)
set(PWN_DISASSEMBLE_ARM64 OFF)

option(BUILD_AS_SHARED_LIBRARY "Build as a shared library" OFF)

include(FetchContent)
FetchContent_Declare(
    pwn++
    GIT_REPOSITORY https://github.com/hugsy/pwn--.git
    GIT_TAG main
)
FetchContent_MakeAvailable(pwn++)

file(GLOB_RECURSE FILES ${PROJECT_SRC_DIR}/*.cpp ${PROJECT_SRC_DIR}/*.cxx ${PROJECT_SRC_DIR}/*.asm)
if(BUILD_AS_SHARED_LIBRARY)
    add_library(${PROJECT_NAME} SHARED ${FILES})
else()
    add_executable(${PROJECT_NAME} ${FILES})
endif(BUILD_AS_SHARED_LIBRARY)
add_dependencies(${PROJECT_NAME} pwn++)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)
target_include_directories(${PROJECT_NAME} PUBLIC $<TARGET_PROPERTY:pwn++,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_definitions(${PROJECT_NAME} PRIVATE $<TARGET_PROPERTY:pwn++,INTERFACE_COMPILE_DEFINITIONS>)
target_compile_options(${PROJECT_NAME} PRIVATE $<TARGET_PROPERTY:pwn++,INTERFACE_COMPILE_OPTIONS>)
target_link_options(${PROJECT_NAME} PRIVATE $<TARGET_PROPERTY:pwn++,INTERFACE_LINK_OPTIONS> /SUBSYSTEM:Console)
target_link_libraries(${PROJECT_NAME} PRIVATE pwn++ $<TARGET_PROPERTY:pwn++,INTERFACE_LINK_LIBRARIES>)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
