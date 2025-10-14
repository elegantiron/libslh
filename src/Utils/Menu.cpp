#include "libslh/Utils/Menu.hpp"

namespace {
    constexpr float SPACING_FACTOR = 1.5F;
}

namespace libslh {
    Menu::Menu(Font defaultFace, Font selectedFace)
        : _defaultFace(std::move(defaultFace)),
          _selectedFace(std::move(selectedFace)) {}

    void Menu::addItem(sf::String& line) {
        _items.push_back(_defaultFace.createText(line));
    }

    void Menu::updateIndex(int delta) {
        _defaultFace.configureText(_items[_idx]);
        _idx += delta;
        auto numItems = static_cast<int>(_items.size());
        _idx %= numItems;
        if (_idx < 0) {
            _idx = numItems - 1;
        }
        _selectedFace.configureText(_items[_idx]);
    }

    void Menu::setPosition(sf::Vector2f position) {
        _position = position;
    }

    void Menu::arrange() {
        float totalHeight = 0.0;
        for (const auto& item : _items) {
            totalHeight += SPACING_FACTOR * item.getLineSpacing();
        }
        sf::Vector2f textPosition
            = {_position.x, _position.y - (totalHeight / 2)};
        for (auto& item : _items) {
            item.setPosition(textPosition);
            textPosition.y += item.getLineSpacing() * SPACING_FACTOR;
        }
    }
} // namespace libslh
