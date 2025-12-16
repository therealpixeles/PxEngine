#pragma once

#include <string>

namespace px::assets {

class ShaderLoader {
public:
    static std::string load_source(const std::string &path);
};

} // namespace px::assets
