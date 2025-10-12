#pragma once

#include "libslh/Types.hpp"

#include <chrono>

namespace libslh::Engine {

    class Clock {
        GameTime  _gameTime;
        TimePoint _frameStart{std::chrono::steady_clock::now()};

    public:
        const GameTime& newFrame();
        [[nodiscard]]
        const GameTime& getTime() const;
    };
}
