#include "TextureLoader.h"

#include <SDL3/SDL.h>
#include <stdexcept>

namespace px::assets {

px::renderer::Texture2D TextureLoader::load_bmp(const std::string &path) {
    SDL_Surface *surface = SDL_LoadBMP(path.c_str());
    if (!surface) {
        throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
    }

    SDL_Surface *converted = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32);
    SDL_DestroySurface(surface);
    if (!converted) {
        throw std::runtime_error(std::string("Failed to convert texture: ") + SDL_GetError());
    }

    auto texture = px::renderer::Texture2D(converted->w, converted->h, SDL_BYTESPERPIXEL(converted->format), converted->pixels);
    SDL_DestroySurface(converted);
    return texture;
}

} // namespace px::assets
