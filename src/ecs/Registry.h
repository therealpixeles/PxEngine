#pragma once

#include "Entity.h"

#include <unordered_map>
#include <vector>
#include <typeindex>
#include <memory>

namespace px::ecs {

class ComponentPoolBase {
public:
    virtual ~ComponentPoolBase() = default;
    virtual void remove(Entity entity) = 0;
};

template <typename T> class ComponentPool : public ComponentPoolBase {
public:
    template <typename... Args> T &emplace(Entity entity, Args &&...args) {
        if (entity >= components_.size()) {
            components_.resize(static_cast<size_t>(entity) + 1);
            present_.resize(static_cast<size_t>(entity) + 1, false);
        }
        components_[entity] = T{std::forward<Args>(args)...};
        present_[entity] = true;
        return components_[entity];
    }

    bool has(Entity entity) const { return entity < present_.size() && present_[entity]; }

    T &get(Entity entity) { return components_[entity]; }
    const T &get(Entity entity) const { return components_[entity]; }

    void remove(Entity entity) override {
        if (has(entity)) {
            present_[entity] = false;
        }
    }

private:
    std::vector<T> components_{};
    std::vector<bool> present_{};
};

class Registry {
public:
    Registry() = default;

    Entity create() { return ++last_entity_; }

    void destroy(Entity entity) {
        for (auto &pair : pools_) {
            pair.second->remove(entity);
        }
    }

    template <typename T, typename... Args> T &emplace(Entity entity, Args &&...args) {
        auto pool = get_pool<T>();
        return pool->emplace(entity, std::forward<Args>(args)...);
    }

    template <typename T> bool has(Entity entity) const {
        auto it = pools_.find(std::type_index(typeid(T)));
        if (it == pools_.end()) {
            return false;
        }
        return static_cast<ComponentPool<T> *>(it->second.get())->has(entity);
    }

    template <typename T> T &get(Entity entity) {
        return get_pool<T>()->get(entity);
    }

private:
    template <typename T> ComponentPool<T> *get_pool() const {
        auto key = std::type_index(typeid(T));
        auto it = pools_.find(key);
        if (it == pools_.end()) {
            return nullptr;
        }
        return static_cast<ComponentPool<T> *>(it->second.get());
    }

    template <typename T> ComponentPool<T> *get_pool() {
        auto key = std::type_index(typeid(T));
        auto it = pools_.find(key);
        if (it == pools_.end()) {
            auto pool = std::make_unique<ComponentPool<T>>();
            auto raw = pool.get();
            pools_.emplace(key, std::move(pool));
            return raw;
        }
        return static_cast<ComponentPool<T> *>(it->second.get());
    }

    Entity last_entity_{0};
    std::unordered_map<std::type_index, std::unique_ptr<ComponentPoolBase>> pools_{};
};

} // namespace px::ecs
