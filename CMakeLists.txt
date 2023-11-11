cmake_minimum_required(VERSION 3.16)
project(AncientTimes LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(SFML)


file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(
    AncientTimes 
    ${SOURCE_FILES}
)


target_precompile_headers(AncientTimes PRIVATE src/stdafx.hpp)
target_link_libraries(AncientTimes PRIVATE sfml-system)
target_link_libraries(AncientTimes PRIVATE sfml-audio)
target_link_libraries(AncientTimes PRIVATE sfml-network)
target_link_libraries(AncientTimes PRIVATE sfml-window)
target_link_libraries(AncientTimes PRIVATE sfml-graphics)
target_compile_features(AncientTimes PRIVATE cxx_std_20)


if(WIN32)
    add_custom_command(
        TARGET AncientTimes
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:AncientTimes>
        VERBATIM)
endif()

install(TARGETS AncientTimes)




