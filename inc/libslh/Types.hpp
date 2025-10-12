#pragma once
#include <chrono>

namespace libslh {
    using Duration
        = std::chrono::duration<long double, std::chrono::milliseconds::period>;
    using TimePoint
        = std::chrono::time_point<std::chrono::steady_clock, Duration>;
    template <typename T>
    using TimerCallback = void (T::*)(bool& runAgain, Duration& nextInterval);

    struct GameTime {
        Duration totalElapsedTime{0};
        Duration lastFrame{0};
    };
} // namespace libslh
