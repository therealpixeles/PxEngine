#include "Renderer.h"

#include "../core/Logger.h"
#include "../platform/Window.h"

#include <glad/gl.h>
#include <SDL3/SDL.h>

namespace px::renderer {

Renderer::Renderer(px::platform::Window &window, px::core::Logger &logger) : logger_(logger) {
    (void)window;
}

void Renderer::initialize_defaults() { glEnable(GL_DEPTH_TEST); }

void Renderer::set_clear_color(const glm::vec4 &color) { clear_color_ = color; }

void Renderer::begin_frame() {
    glClearColor(clear_color_.r, clear_color_.g, clear_color_.b, clear_color_.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::end_frame(px::platform::Window &window) { window.swap_buffers(); }

void Renderer::draw(const Mesh &mesh, const Shader &shader) const {
    shader.bind();
    mesh.bind();
    mesh.draw();
}

} // namespace px::renderer
