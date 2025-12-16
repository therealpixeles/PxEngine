#include "Shader.h"

#include <stdexcept>
#include <vector>

namespace px::renderer {

Shader::Shader(const std::string &vertex_src, const std::string &fragment_src) {
    GLuint vertex = compile(GL_VERTEX_SHADER, vertex_src);
    GLuint fragment = compile(GL_FRAGMENT_SHADER, fragment_src);

    program_ = glCreateProgram();
    glAttachShader(program_, vertex);
    glAttachShader(program_, fragment);
    glLinkProgram(program_);

    GLint success = 0;
    glGetProgramiv(program_, GL_LINK_STATUS, &success);
    if (success != GL_TRUE) {
        GLint length = 0;
        glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &length);
        std::vector<GLchar> log(static_cast<size_t>(length));
        glGetProgramInfoLog(program_, length, nullptr, log.data());
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        throw std::runtime_error(std::string("Shader program link failed: ") + log.data());
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() { destroy(); }

Shader::Shader(Shader &&other) noexcept { std::swap(program_, other.program_); }

Shader &Shader::operator=(Shader &&other) noexcept {
    if (this != &other) {
        destroy();
        std::swap(program_, other.program_);
    }
    return *this;
}

void Shader::bind() const { glUseProgram(program_); }

GLuint Shader::compile(GLenum type, const std::string &source) {
    GLuint shader = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success != GL_TRUE) {
        GLint length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        std::vector<GLchar> log(static_cast<size_t>(length));
        glGetShaderInfoLog(shader, length, nullptr, log.data());
        glDeleteShader(shader);
        throw std::runtime_error(std::string("Shader compilation failed: ") + log.data());
    }

    return shader;
}

void Shader::destroy() {
    if (program_ != 0) {
        glDeleteProgram(program_);
        program_ = 0;
    }
}

} // namespace px::renderer
