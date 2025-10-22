#pragma once
#include "libslh/System/Duration.hpp"
#include "libslh/System/GameTime.hpp"

namespace libslh::Engine {
    using TimerCallback = void (*)(bool& runAgain, Duration& nextInterval);

    class Timer {
        TimerCallback _callback;
        Duration      _interval{0};
        Duration      _runningClock{0};
        bool          _running = true;

    public:
        Timer(TimerCallback callback);
        Timer(Timer&)                 = delete;
        Timer(Timer&&)                = delete;
        ~Timer()                      = default;
        void operator=(const Timer&)  = delete;
        void operator=(const Timer&&) = delete;

        void update(const GameTime& gameTime);

        void update(const Duration& elapsedTime);
        void restart();

        void setInterval(Duration interval);
    };
} // namespace libslh::Engine
