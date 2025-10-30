#pragma once
#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace {
    constexpr int DEFAULT_FPS = 60;
}

namespace libslh::Engine {
    class WindowManager {
        // sfg::SFGUI       _sfgui;
        sf::RenderWindow _window;
        sf::Color        _backgroundColor;
        sf::String       _title;

    public:
        WindowManager() = default;
        void                     init(sf::VideoMode     mode,
                                      const sf::String& title,
                                      uint32_t flags = sf::Style::Titlebar | sf::Style::Close,
                                      int      frameRate = DEFAULT_FPS);
        void                     render(const sf::Drawable& drawable);
        sf::Color                getBackgroundColor() const;
        void                     setBackgroundColor(sf::Color color);
        std::optional<sf::Event> pollEvent();
        sf::String               getTitle() const;
        void                     setTitle(const sf::String&);
        sf::Vector2u             getSize() const;
        void                     setSize(sf::Vector2u);
    };
}
