#pragma once
#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace {
    constexpr int DEFAULT_FPS = 60;
}

namespace libslh::Engine {
    class WindowManager {
        sfg::SFGUI       _sfgui;
        sf::RenderWindow _window;
        sf::Color        _backgroundColor;

    public:
        WindowManager() = default;
        void init(sf::VideoMode mode, const sf::String& title,
                  uint32_t flags     = sf::Style::Titlebar | sf::Style::Close,
                  int      frameRate = DEFAULT_FPS);
        void render(const sf::Drawable& drawable);
        void setBackgroundColor(sf::Color color);
        std::optional<sf::Event> pollEvent();
        void                     pollEvent(std::optional<sf::Event>& event);
    };
}
