#pragma once

#include <SDL3/SDL.h>
#include <string>
#include <utility>

namespace px::platform {

struct WindowConfig {
    std::string title;
    int width{1280};
    int height{720};
    bool vsync{true};
};

class Window {
public:
    explicit Window(const WindowConfig &config);
    ~Window();

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    SDL_Window *handle() const { return window_; }
    SDL_GLContext context() const { return gl_context_; }

    void swap_buffers();
    bool poll_event(SDL_Event &event);
    void set_title(const std::string &title);
    std::pair<int, int> drawable_size() const;

private:
    SDL_Window *window_{nullptr};
    SDL_GLContext gl_context_{nullptr};
};

} // namespace px::platform
