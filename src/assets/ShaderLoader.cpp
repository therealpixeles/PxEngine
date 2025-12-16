#include "ShaderLoader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace px::assets {

std::string ShaderLoader::load_source(const std::string &path) {
    std::ifstream file(path, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open shader file: " + path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

} // namespace px::assets
