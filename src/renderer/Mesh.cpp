#include "Mesh.h"

#include <utility>

namespace px::renderer {

Mesh::Mesh() = default;

Mesh::Mesh(const std::vector<float> &vertices, GLsizei stride) : stride_(stride) {
    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);

    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(float)), vertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride_, reinterpret_cast<void *>(0));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride_, reinterpret_cast<void *>(3 * sizeof(float)));

    vertex_count_ = static_cast<GLsizei>(vertices.size() / (stride / static_cast<GLsizei>(sizeof(float))));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh() { destroy(); }

Mesh::Mesh(Mesh &&other) noexcept {
    std::swap(vao_, other.vao_);
    std::swap(vbo_, other.vbo_);
    std::swap(vertex_count_, other.vertex_count_);
    std::swap(stride_, other.stride_);
}

Mesh &Mesh::operator=(Mesh &&other) noexcept {
    if (this != &other) {
        destroy();
        std::swap(vao_, other.vao_);
        std::swap(vbo_, other.vbo_);
        std::swap(vertex_count_, other.vertex_count_);
        std::swap(stride_, other.stride_);
    }
    return *this;
}

void Mesh::bind() const { glBindVertexArray(vao_); }

void Mesh::draw() const { glDrawArrays(GL_TRIANGLES, 0, vertex_count_); }

void Mesh::destroy() {
    if (vbo_ != 0) {
        glDeleteBuffers(1, &vbo_);
        vbo_ = 0;
    }
    if (vao_ != 0) {
        glDeleteVertexArrays(1, &vao_);
        vao_ = 0;
    }
}

} // namespace px::renderer
