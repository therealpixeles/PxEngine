#include "Window.h"

#include <stdexcept>

namespace px::platform {

Window::Window(const WindowConfig &config) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        throw std::runtime_error(std::string("Failed to initialize SDL: ") + SDL_GetError());
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    window_ = SDL_CreateWindow(config.title.c_str(), config.width, config.height,
                               SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
    if (!window_) {
        throw std::runtime_error(std::string("Failed to create window: ") + SDL_GetError());
    }

    gl_context_ = SDL_GL_CreateContext(window_);
    if (!gl_context_) {
        throw std::runtime_error(std::string("Failed to create GL context: ") + SDL_GetError());
    }

    if (SDL_GL_MakeCurrent(window_, gl_context_) != 0) {
        throw std::runtime_error(std::string("Failed to make GL context current: ") + SDL_GetError());
    }

    if (SDL_GL_SetSwapInterval(config.vsync ? 1 : 0) != 0) {
        SDL_LogWarn(SDL_LOG_CATEGORY_SYSTEM, "Unable to set swap interval: %s", SDL_GetError());
    }
}

Window::~Window() {
    if (gl_context_) {
        SDL_GL_DestroyContext(gl_context_);
        gl_context_ = nullptr;
    }
    if (window_) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    SDL_Quit();
}

void Window::swap_buffers() { SDL_GL_SwapWindow(window_); }

bool Window::poll_event(SDL_Event &event) { return SDL_PollEvent(&event) == 1; }

void Window::set_title(const std::string &title) { SDL_SetWindowTitle(window_, title.c_str()); }

std::pair<int, int> Window::drawable_size() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowSizeInPixels(window_, &w, &h);
    return {w, h};
}

} // namespace px::platform
