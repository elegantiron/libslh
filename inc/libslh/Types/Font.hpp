#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace libslh {
    class Font {
        sf::Font        _font;
        unsigned int    _characterSize;
        sf::Color       _fillColor;
        float           _outlineThickness;
        sf::Color       _outlineColor;
        sf::Text::Style _style;

    public:
        Font(sf::Font        font,
                 unsigned int    size,
                 sf::Color       fillColor,
                 float           outlineThickness,
                 sf::Color       outlineColor,
                 sf::Text::Style style);

        void     configureText(sf::Text& text) const;
                 operator sf::Font&();
        sf::Text createText(sf::String text);
    };
}
