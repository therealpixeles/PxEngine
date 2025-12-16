#pragma once

#include <glad/gl.h>

#include <string>

namespace px::renderer {

class Shader {
public:
    Shader() = default;
    Shader(const std::string &vertex_src, const std::string &fragment_src);
    ~Shader();

    Shader(const Shader &) = delete;
    Shader &operator=(const Shader &) = delete;
    Shader(Shader &&other) noexcept;
    Shader &operator=(Shader &&other) noexcept;

    void bind() const;
    GLuint id() const { return program_; }

private:
    GLuint program_{0};

    void destroy();
    GLuint compile(GLenum type, const std::string &source);
};

} // namespace px::renderer
