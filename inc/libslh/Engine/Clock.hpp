#pragma once

#include "libslh/Types/GameTime.hpp"
#include "libslh/Types/TimePoint.hpp"

#include <chrono>

namespace libslh::Engine {

    class Clock {
        GameTime  _gameTime;
        TimePoint _frameStart{std::chrono::steady_clock::now()};

    public:
        /**
         * @brief Nark the start of a new frame and get the current elapsed GameTime
         *
         * @return const GameTime&
         */
        const GameTime& newFrame();
        /**
         * @brief Get the current elapsed GameTime
         *
         * @return const GameTime&
         */
        [[nodiscard]]
        const GameTime& getTime() const;
    };
}
