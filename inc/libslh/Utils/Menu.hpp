#pragma once

#include "libslh/Graphics/Font.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>

namespace libslh {
    class Menu : public sf::Drawable {
        int                   _idx = 0;
        std::vector<sf::Text> _items;
        Font                  _defaultFace;
        Font                  _selectedFace;
        sf::Vector2f          _position{0, 0};

        void updateIndex(int delta);
        void arrange();

    public:
        Menu(Font defaultFace, Font selectedFace);
        void addItem(const std::basic_string<char>& line);
        void addItem(sf::String& line);
        void setPosition(sf::Vector2f position);
        void draw(sf::RenderTarget& target,
                  sf::RenderStates  states) const override;
    };
}
