#pragma once

#include "Logger.h"
#include "../platform/Window.h"
#include "../renderer/Renderer.h"

#include <functional>

namespace px::core {

struct EngineConfig {
    std::string title{"PxEngine Sandbox"};
    int width{1280};
    int height{720};
    bool vsync{true};
};

class Engine {
public:
    explicit Engine(const EngineConfig &config);
    ~Engine();

    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;

    void run(const std::function<void(float)> &update, const std::function<void()> &render);
    void stop();

    px::platform::Window &window() { return window_; }
    px::renderer::Renderer &renderer() { return renderer_; }
    Logger &logger() { return logger_; }

private:
    Logger logger_{};
    px::platform::Window window_;
    px::renderer::Renderer renderer_;
    bool running_{false};
};

} // namespace px::core
