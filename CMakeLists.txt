cmake_minimum_required(VERSION 3.25)
project(PixelesEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    SDL3
    URL https://github.com/libsdl-org/SDL/releases/download/release-3.0.0/SDL3-3.0.0.zip
)
FetchContent_Declare(
    glm
    URL https://github.com/g-truc/glm/releases/download/1.0.1/glm-1.0.1.zip
)

FetchContent_MakeAvailable(SDL3 glm)

find_package(OpenGL REQUIRED)

add_library(glad STATIC external/glad/src/gl.c)
target_include_directories(glad PUBLIC external/glad/include)

add_library(PxEngine
    src/core/Engine.cpp
    src/core/Logger.cpp
    src/platform/Window.cpp
    src/renderer/Renderer.cpp
    src/renderer/Shader.cpp
    src/renderer/Texture.cpp
    src/renderer/Mesh.cpp
    src/assets/ShaderLoader.cpp
    src/assets/TextureLoader.cpp
)

target_include_directories(PxEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include
)

target_link_libraries(PxEngine
    PUBLIC
        SDL3::SDL3
        glm::glm
        OpenGL::GL
        glad
)

target_compile_definitions(PxEngine PRIVATE SDL_MAIN_HANDLED)

add_executable(PxSandbox sandbox/main.cpp)

target_link_libraries(PxSandbox PRIVATE PxEngine)

target_include_directories(PxSandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/bin)

set_target_properties(PxSandbox PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(PxEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
