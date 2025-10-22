#include "libslh/System/Timer.hpp"

namespace libslh {
    Timer::Timer(TimerCallback callback)
        : _callback(callback), _running(false) {}

    void Timer::update(const GameTime& gameTime) {
        update(gameTime.getLastFrame());
    }

    void Timer::update(const Duration& elapsedTime) {
        if (!_running
            || _callback == nullptr
            || _interval == Duration::zero()) {
            return;
        }
        _runningClock += elapsedTime;
        if (_runningClock >= _interval) {
            _runningClock = Duration::zero();
            _callback(_running, _interval);
        }
    }

    void Timer::setInterval(Duration interval) {
        _interval = interval;
    }

    void Timer::restart() {
        _running      = true;
        _runningClock = Duration::zero();
    }
}
