#pragma once
#include "libslh/Engine/Clock.hpp"
#include "libslh/Engine/RNG.hpp"
#include "libslh/Engine/SceneManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <boost/locale.hpp>
#include <optional>

namespace libslh::Engine {
    class Core {
        static Core*             _instance;
        sf::RenderWindow         _window;
        SceneManager             _sceneMan;
        Clock                    _clock;
        sf::Color                _backgroundColor = sf::Color::Black;
        RNG                      _rng;
        boost::locale::generator _gen;
        std::basic_string<char>  _locale;

        Core(std::random_device& dev) : _rng(dev) {
            _locale = _gen("").name();
        }

        void handleEvent();
        void iterate(const GameTime& gameTime,
                     bool&           successful,
                     bool&           keepRunning);
        void handleEvent(std::optional<sf::Event> event,
                         bool&                    successful,
                         bool&                    keepRunning);

    public:
        static Core&            getInstance();
        const sf::RenderWindow& getWindow() const;
        void                    init(sf::VideoMode     mode,
                                     const sf::String& title,
                                     bool&             successful);
        void                    setNextScene(ScenePtr pScene);
        void                    run();
        void                    quit(bool successful);
        void setLocalization(sf::String& folder, sf::String& domain);
        [[nodiscard]]
        ScenePtr getCurrentScene() const;
        [[nodiscard]]
        std::basic_string<char> localize(
            const boost::locale::basic_message<char>& string);

        template <typename T>
            requires std::integral<T> || std::floating_point<T>
        T next() {
            return next(std::numeric_limits<T>::min(),
                        std::numeric_limits<T>::max());
        }

        template <typename T>
            requires std::integral<T> || std::floating_point<T>
        T next(T max) {
            return next(0, max);
        }

        template <typename T>
            requires std::integral<T> || std::floating_point<T>
        T next(T min, T max) {
            return _rng.next(min, max);
        }
    };
} // namespace libslh::Engine
