#pragma once

#include "Resource.hpp"

// Zasób
class Resource {
public:
    double get() const {
        return 42.0;
    }
};

// Manager zasobu
class ResourceManager {
    Resource* resource; // wskaźnik na dynamiczny zasób

public:
    // Konstruktor
    ResourceManager() {
        resource = new Resource();
    }

    // Destruktor
    ~ResourceManager() {
        delete resource;
    }

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) {
        resource = new Resource(*other.resource);
    }

    // Operator przypisania kopiującego
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            delete resource;
            resource = new Resource(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept {
        resource = other.resource;
        other.resource = nullptr;
    }

    // Operator przypisania przenoszącego
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            delete resource;
            resource = other.resource;
            other.resource = nullptr;
        }
        return *this;
    }

    // Metoda dostępu do zasobu
    double get() const {
        return resource->get();
    }
};
