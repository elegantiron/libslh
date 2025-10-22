#include "libslh/System/GameTime.hpp"

namespace libslh {
    GameTime::GameTime(Duration totalElapsedTime, Duration lastFrame)
        : _totalElapsedTime(totalElapsedTime),
          _lastFrame(lastFrame),
          _lastUpdate(std::chrono::steady_clock::now()) {}

    void GameTime::update() {
        auto now   = std::chrono::steady_clock::now();
        _lastFrame = now - _lastUpdate;
        _totalElapsedTime += _lastFrame;
        _lastUpdate = now;
    }

    const Duration& GameTime::getLastFrame() const {
        return _lastFrame;
    }

    const Duration& GameTime::getTotalElapsedTime() const {
        return _totalElapsedTime;
    }
}
