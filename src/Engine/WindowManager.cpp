#include "libslh/Engine/WindowManager.hpp"

namespace libslh::Engine {
    void WindowManager::init(sf::VideoMode     mode,
                             const sf::String& title,
                             uint32_t          flags,
                             int               frameRate) {
        _title = title;
        _window.create(mode, _title, flags);
        _window.setFramerateLimit(frameRate);
        _window.setPosition({0, 0});
    }

    void WindowManager::render(const sf::Drawable& drawable) {
        _window.clear(_backgroundColor);
        _window.draw(drawable);
        _window.display();
    }

    void WindowManager::setBackgroundColor(sf::Color color) {
        _backgroundColor = color;
    }

    sf::Color WindowManager::getBackgroundColor() const {
        return _backgroundColor;
    }

    std::optional<sf::Event> WindowManager::pollEvent() {
        return _window.pollEvent();
    }

    void WindowManager::setSize(sf::Vector2u size) {
        _window.setSize(size);
    }

    sf::Vector2u WindowManager::getSize() const {
        return _window.getSize();
    }

    void WindowManager::setTitle(const sf::String& title) {
        _title = title;
        _window.setTitle(_title);
    }

    sf::String WindowManager::getTitle() const {
        return _title;
    }
} // namespace libslh::Engine
