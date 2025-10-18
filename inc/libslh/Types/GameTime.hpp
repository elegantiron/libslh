#pragma once
#include "libslh/Types/Duration.hpp"
#ifdef LIBSLH_USE_BOOST
#include <boost/serialization/access.hpp>
#endif
namespace libslh::Engine {
    class GameTime {
        Duration _totalElapsedTime{0};
        Duration _lastFrame{0};
#ifdef LIBSLH_USE_BOOST
        friend class boost::serialization::access;

        template <class Archive>
        void serialize(Archive& archive, const unsigned int version) {
            archive << _totalElapsedTime;
            archive << _lastFrame;
        }
#endif
    public:
        GameTime(Duration totalElapsedTime, Duration lastFrame)
            : _totalElapsedTime(totalElapsedTime), _lastFrame(lastFrame) {}
    };
} // namespace libslh::Engine
