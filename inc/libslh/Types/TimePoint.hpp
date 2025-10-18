#pragma once

#include "libslh/Types/Duration.hpp"

#include <chrono>

namespace libslh {
    using TimePoint
        = std::chrono::time_point<std::chrono::steady_clock, Duration>;
}
