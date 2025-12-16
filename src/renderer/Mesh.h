#pragma once

#include <glad/gl.h>

#include <vector>

namespace px::renderer {

class Mesh {
public:
    Mesh();
    Mesh(const std::vector<float> &vertices, GLsizei stride);
    ~Mesh();

    Mesh(const Mesh &) = delete;
    Mesh &operator=(const Mesh &) = delete;
    Mesh(Mesh &&other) noexcept;
    Mesh &operator=(Mesh &&other) noexcept;

    void bind() const;
    void draw() const;

private:
    GLuint vao_{0};
    GLuint vbo_{0};
    GLsizei vertex_count_{0};
    GLsizei stride_{0};

    void destroy();
};

} // namespace px::renderer
