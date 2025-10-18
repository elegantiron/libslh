#pragma once
#include <chrono>

namespace libslh {
    using Duration
        = std::chrono::duration<double, std::chrono::milliseconds::period>;
}
