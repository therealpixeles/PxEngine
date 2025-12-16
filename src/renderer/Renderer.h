#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

#include <glm/glm.hpp>

namespace px::platform {
class Window;
}

namespace px::core {
class Logger;
}

namespace px::renderer {

class Renderer {
public:
    Renderer(px::platform::Window &window, px::core::Logger &logger);
    void initialize_defaults();

    void set_clear_color(const glm::vec4 &color);
    void begin_frame();
    void end_frame(px::platform::Window &window);

    void draw(const Mesh &mesh, const Shader &shader) const;

private:
    glm::vec4 clear_color_{0.1f, 0.1f, 0.1f, 1.0f};
    px::core::Logger &logger_;
};

} // namespace px::renderer
