#include "libslh/Engine/WindowManager.hpp"

namespace libslh::Engine {
    void WindowManager::init(sf::VideoMode mode, const sf::String& title,
                             uint32_t flags, int frameRate) {
        _window.create(mode, title, flags);
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

    std::optional<sf::Event> WindowManager::pollEvent() {
        return _window.pollEvent();
    }

    void WindowManager::pollEvent(std::optional<sf::Event>& event) {
        event = _window.pollEvent();
    }
}
