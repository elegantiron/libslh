#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

namespace libslh {
    class Menu : public sf::Drawable {
        std::vector<sf::Text> _items;
        sf::Font              _font;
        unsigned int          _defaultCharacterSize;
        sf::Color             _defaultFillColor;
        float                 _defaultOutlineThickness;
        sf::Color             _defaultOutlineColor;
        unsigned int          _selectedCharacterSize;
        sf::Color             _selectedFillColor;
        float                 _selectedOutlineThickness;
        sf::Color             _selectedOutlineColor;

    public:
        Menu(sf::Font&    font,
             unsigned int characterSize,
             sf::Color    defaultFillColor,
             sf::Color    selectedFillColor);
        Menu(sf::Font&    font,
             unsigned int defaultCharacterSize,
             sf::Color    defaultFillColor,
             unsigned int selectedCharacterSize,
             sf::Color    selectedFillColor);
        Menu(sf::Font&    font,
             unsigned int defaultCharacterSize,
             sf::Color    defaultFillColor,
             float        defaultOutlineThickness,
             sf::Color    defaultOutlineColor,
             unsigned int selectedCharacterSize,
             sf::Color    selectedFillColor,
             float        selectedOutlineThickness,
             sf::Color    selectedOutlineColor);
        void addItem(const sf::String& line);
        void draw(sf::RenderTarget& target,
                  sf::RenderStates  states) const override;
    };
}
