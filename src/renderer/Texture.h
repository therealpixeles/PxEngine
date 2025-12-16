#pragma once

#include <glad/gl.h>

#include <cstdint>

namespace px::renderer {

class Texture2D {
public:
    Texture2D() = default;
    Texture2D(int width, int height, int channels, const void *pixels);
    ~Texture2D();

    Texture2D(const Texture2D &) = delete;
    Texture2D &operator=(const Texture2D &) = delete;
    Texture2D(Texture2D &&other) noexcept;
    Texture2D &operator=(Texture2D &&other) noexcept;

    void bind(GLenum unit = GL_TEXTURE0) const;
    GLuint id() const { return texture_; }

private:
    GLuint texture_{0};
    int width_{0};
    int height_{0};
    int channels_{0};

    void destroy();
};

} // namespace px::renderer
