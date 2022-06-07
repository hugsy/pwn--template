project(xp LANGUAGES CXX VERSION 0.1.0)

set(PROJECT_LIB_SRC_DIR ${PROJECT_ROOT_DIR}/src CACHE INTERNAL "PROJECT_LIB_SRC_DIR")

set(
    SOURCE_FILES
    main.cc
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(DEBUG)
    target_compile_options(${PROJECT_NAME} PRIVATE /MTd)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE /MT)
endif(DEBUG)

target_include_directories(${PROJECT_NAME}    PUBLIC pwn++)
target_compile_definitions(${PROJECT_NAME}    PUBLIC _UNICODE UNICODE)
target_compile_options(${PROJECT_NAME}    PUBLIC        /sdl /WX /Gy /Gm- /permissive-)
target_link_options(${PROJECT_NAME}  PUBLIC        /CETCOMPAT /profile /DEBUGTYPE:cv,fixup)
target_link_libraries(${PROJECT_NAME} PUBLIC pwn++)
