#pragma once

#include "../renderer/Texture.h"

#include <string>

namespace px::assets {

class TextureLoader {
public:
    static px::renderer::Texture2D load_bmp(const std::string &path);
};

} // namespace px::assets
