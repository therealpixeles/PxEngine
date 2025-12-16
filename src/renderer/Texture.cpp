#include "Texture.h"

#include <stdexcept>
#include <utility>

namespace px::renderer {

Texture2D::Texture2D(int width, int height, int channels, const void *pixels)
    : width_(width), height_(height), channels_(channels) {
    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    GLint internal_format = channels_ == 4 ? GL_RGBA : GL_SRGB8_ALPHA8;
    GLenum format = channels_ == 4 ? GL_RGBA : GL_RGBA;
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width_, height_, 0, format, GL_UNSIGNED_BYTE, pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D() { destroy(); }

Texture2D::Texture2D(Texture2D &&other) noexcept {
    std::swap(texture_, other.texture_);
    std::swap(width_, other.width_);
    std::swap(height_, other.height_);
    std::swap(channels_, other.channels_);
}

Texture2D &Texture2D::operator=(Texture2D &&other) noexcept {
    if (this != &other) {
        destroy();
        std::swap(texture_, other.texture_);
        std::swap(width_, other.width_);
        std::swap(height_, other.height_);
        std::swap(channels_, other.channels_);
    }
    return *this;
}

void Texture2D::bind(GLenum unit) const {
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, texture_);
}

void Texture2D::destroy() {
    if (texture_ != 0) {
        glDeleteTextures(1, &texture_);
        texture_ = 0;
    }
}

} // namespace px::renderer
