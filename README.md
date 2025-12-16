# PixelesEngine (PxEngine)

A modular C++20 game engine targeting Windows (MinGW-w64 UCRT) with SDL3 windowing/input and OpenGL 4.6 core rendering. The repository also includes a sandbox application that renders a triangle and demonstrates input handling.

## Features

- SDL3 window creation with OpenGL 4.6 core profile context
- GLAD-based OpenGL function loading
- Modern OpenGL renderer (VAO/VBO, shaders, core profile only)
- Basic ECS registry (entities, components)
- Asset loading for shaders and BMP textures
- RAII-driven architecture with clear namespaces (px::core, px::platform, px::renderer, px::ecs, px::assets)
- Sandbox app showing a triangle and ESC-to-exit input handling

## Building

```bash
cmake -S . -B build
cmake --build build
./build/bin/PxSandbox
```

Assets are copied to the build output directory automatically.
