#include "libslh/Types/Font.hpp"

#include <utility>

namespace libslh {
    Font::Font(sf::Font        font,
               unsigned int    size,
               sf::Color       fillColor,
               float           outlineThickness,
               sf::Color       outlineColor,
               sf::Text::Style style)
        : _font(std::move(font)),
          _characterSize(size),
          _fillColor(fillColor),
          _outlineThickness(outlineThickness),
          _outlineColor(outlineColor),
          _style(style) {}

    void Font::configureText(sf::Text& text) const {
        text.setFont(_font);
        text.setCharacterSize(_characterSize);
        text.setFillColor(_fillColor);
        text.setOutlineThickness(_outlineThickness);
        text.setOutlineColor(_outlineColor);
        text.setStyle(_style);
    }

    Font::operator sf::Font&() {
        return _font;
    }

    sf::Text Font::createText(sf::String text) {
        sf::Text newItem{_font, std::move(text)};
        configureText(newItem);
        return newItem;
    }
}
