#pragma once
#include "libslh/System/Duration.hpp"
#include "libslh/System/TimePoint.hpp"

#ifdef LIBSLH_USE_BOOST
#include <boost/serialization/access.hpp>
#endif
namespace libslh {
    class GameTime {
        Duration  _totalElapsedTime{0};
        Duration  _lastFrame{0};
        TimePoint _lastUpdate;
#ifdef LIBSLH_USE_BOOST
        friend class boost::serialization::access;

        template <class Archive>
        void serialize(Archive& archive, const unsigned int  /*version*/) {
            archive << _totalElapsedTime;
            archive << _lastFrame;
        }
#endif
    public:
        GameTime(Duration totalElapsedTime, Duration lastFrame);
        GameTime() = default;

        [[nodiscard]]
        const Duration& getLastFrame() const;
        [[nodiscard]]
        const Duration& getTotalElapsedTime() const;
        void            update();
    };
} // namespace libslh
