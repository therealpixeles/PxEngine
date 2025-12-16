#include "Engine.h"

#include <SDL3/SDL.h>
#include <glad/gl.h>

#include <chrono>
#include <stdexcept>

namespace px::core {

Engine::Engine(const EngineConfig &config)
    : window_({config.title, config.width, config.height, config.vsync}), renderer_(window_, logger_) {
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress))) {
        throw std::runtime_error("Failed to load OpenGL functions via GLAD");
    }

    auto [w, h] = window_.drawable_size();
    glViewport(0, 0, w, h);
    renderer_.initialize_defaults();

    const auto *vendor = reinterpret_cast<const char *>(glGetString(GL_VENDOR));
    const auto *renderer = reinterpret_cast<const char *>(glGetString(GL_RENDERER));
    const auto *version = reinterpret_cast<const char *>(glGetString(GL_VERSION));
    logger_.info(std::string("OpenGL Vendor: ") + (vendor ? vendor : ""));
    logger_.info(std::string("OpenGL Renderer: ") + (renderer ? renderer : ""));
    logger_.info(std::string("OpenGL Version: ") + (version ? version : ""));
}

Engine::~Engine() { running_ = false; }

void Engine::run(const std::function<void(float)> &update, const std::function<void()> &render) {
    running_ = true;
    auto last = std::chrono::high_resolution_clock::now();

    while (running_) {
        SDL_Event event;
        while (window_.poll_event(event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                running_ = false;
                break;
            case SDL_EVENT_WINDOW_RESIZED:
                glViewport(0, 0, event.window.data1, event.window.data2);
                break;
            case SDL_EVENT_KEY_DOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running_ = false;
                }
                break;
            default:
                break;
            }
        }

        auto now = std::chrono::high_resolution_clock::now();
        float delta = std::chrono::duration<float>(now - last).count();
        last = now;

        update(delta);
        renderer_.begin_frame();
        render();
        renderer_.end_frame(window_);
    }
}

void Engine::stop() { running_ = false; }

} // namespace px::core
