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
}
