#include "libslh/Engine/Clock.hpp"

namespace libslh::Engine {
    const GameTime& Clock::getTime() const {
        return _gameTime;
    }

    const GameTime& Clock::newFrame() {
        _gameTime.update();
        return _gameTime;
    }
}
