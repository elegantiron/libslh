#include "libslh/Utils/Menu.hpp"

namespace libslh {
    void Menu::addItem(const sf::String& line) {
        sf::Text newItem{_font};
        newItem.setString(line);
        newItem.setCharacterSize(_defaultCharacterSize);
        newItem.setFillColor(_defaultFillColor);
        newItem.setOutlineThickness(_defaultOutlineThickness);
    }

    Menu::Menu(sf::Font&    font,
               unsigned int characterSize,
               sf::Color    defaultFillColor,
               sf::Color    selectedFillColor)
        : Menu(font,
               characterSize,
               defaultFillColor,
               0,
               defaultFillColor,
               characterSize,
               selectedFillColor,
               0,
               selectedFillColor) {}

    Menu::Menu(sf::Font&    font,
               unsigned int defaultCharacterSize,
               sf::Color    defaultFillColor,
               unsigned int selectedCharacterSize,
               sf::Color    selectedFillColor)
        : Menu(font,
               defaultCharacterSize,
               defaultFillColor,
               0,
               defaultFillColor,
               selectedCharacterSize,
               selectedFillColor,
               0,
               selectedFillColor) {}

    Menu::Menu(sf::Font&    font,
               unsigned int defaultCharacterSize,
               sf::Color    defaultFillColor,
               float        defaultOutlineThickness,
               sf::Color    defaultOutlineColor,
               unsigned int selectedCharacterSize,
               sf::Color    selectedFillColor,
               float        selectedOutlineThickness,
               sf::Color    selectedOutlineColor)
        : _font(font),
          _defaultCharacterSize(defaultCharacterSize),
          _defaultFillColor(defaultFillColor),
          _defaultOutlineThickness(defaultOutlineThickness),
          _defaultOutlineColor(defaultOutlineColor),
          _selectedCharacterSize(selectedCharacterSize),
          _selectedFillColor(selectedFillColor),
          _selectedOutlineThickness(selectedOutlineThickness),
          _selectedOutlineColor(selectedOutlineColor) {}

    void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for (auto item : _items) {
            target.draw(item);
        }
    }
}
