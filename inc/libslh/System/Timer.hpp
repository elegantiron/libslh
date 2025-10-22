#pragma once
#include "libslh/System/Duration.hpp"
#include "libslh/System/GameTime.hpp"

namespace libslh {
    using TimerCallback = void (*)(bool& runAgain, Duration& nextInterval);

    class Timer {
        TimerCallback _callback     = nullptr;
        Duration      _interval     = Duration::zero();
        Duration      _runningClock = Duration::zero();
        bool          _running      = true;

    public:
        Timer(TimerCallback);
        Timer()                       = default;
        Timer(Timer&)                 = delete;
        Timer(Timer&&)                = delete;
        ~Timer()                      = default;
        void operator=(const Timer&)  = delete;
        void operator=(const Timer&&) = delete;

        void update(const GameTime&);
        void update(const Duration&);
        void setInterval(Duration);
        void restart();
    };
} // namespace libslh
