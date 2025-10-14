#pragma once

#include "libslh/Types/Font.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>

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
        void addItem(sf::String& line);
        void setPosition(sf::Vector2f position);
    };
}
