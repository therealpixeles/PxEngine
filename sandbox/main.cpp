#include "../src/core/Engine.h"
#include "../src/assets/ShaderLoader.h"
#include "../src/renderer/Mesh.h"
#include "../src/renderer/Shader.h"

#include <filesystem>
#include <vector>

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    px::core::EngineConfig config{};
    config.title = "PxEngine Sandbox";
    config.width = 1280;
    config.height = 720;
    config.vsync = true;

    px::core::Engine engine{config};
    engine.logger().info("Engine initialized");

    std::filesystem::path asset_root = std::filesystem::current_path() / "assets";
    auto vertex_source = px::assets::ShaderLoader::load_source((asset_root / "shaders" / "triangle.vert").string());
    auto fragment_source = px::assets::ShaderLoader::load_source((asset_root / "shaders" / "triangle.frag").string());

    px::renderer::Shader shader{vertex_source, fragment_source};

    std::vector<float> vertices = {
        // positions        // colors
        -0.5f, -0.5f, 0.0f, 1.0f, 0.2f, 0.2f,
        0.5f,  -0.5f, 0.0f, 0.2f, 1.0f, 0.2f,
        0.0f,  0.5f,  0.0f, 0.2f, 0.2f, 1.0f,
    };

    px::renderer::Mesh mesh{vertices, static_cast<GLsizei>(6 * sizeof(float))};

    engine.renderer().set_clear_color({0.05f, 0.05f, 0.08f, 1.0f});

    engine.run([
    ](float delta_time) {
        (void)delta_time;
    },
                [&]() {
                    engine.renderer().draw(mesh, shader);
                });

    return 0;
}
