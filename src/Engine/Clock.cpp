#include "libslh/Engine/Clock.hpp"

namespace libslh::Engine {
    const GameTime& Clock::getTime() const {
        return _gameTime;
    }

    const GameTime& Clock::newFrame() {
        auto now            = std::chrono::steady_clock::now();
        _gameTime.lastFrame = now - _frameStart;
        _gameTime.totalElapsedTime += _gameTime.lastFrame;
        _frameStart = now;
        return _gameTime;
    }
}
