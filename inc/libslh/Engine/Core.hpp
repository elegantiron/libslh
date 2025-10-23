#pragma once
#include "libslh/Engine/Clock.hpp"
#include "libslh/Engine/RNG.hpp"
#include "libslh/Engine/SceneManager.hpp"
#include "libslh/Engine/WindowManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <boost/locale.hpp>
#include <optional>

namespace libslh::Engine {
    /**
     * @brief Control center for running a game.
     *
     */
    class Core {
        static Core* _instance;
        Clock        _clock;

        std::basic_string<char> _locale;

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
        Core& operator=(Core&)  = delete;
        Core& operator=(Core&&) = delete;
        Core(Core&)             = delete;
        Core(Core&&)            = delete;
        ~Core()                 = default;
        static Core& getInstance();
        void         init(sf::VideoMode     mode,
                          const sf::String& title,
                          bool&             successful);
        void         run();
        void         quit(bool successful);

#pragma region Window
    private:
        WindowManager _winMan;

    public:
        sf::Vector2u getWindowSize() const;
        void         setWindowTitle(const sf::String&);
        void         setWindowSize(sf::Vector2u);
#pragma endregion
#pragma region Scenes
    private:
        SceneManager _sceneMan;

    public:
        void setNextScene(ScenePtr pScene);
        [[nodiscard]]
        ScenePtr getCurrentScene() const;
#pragma endregion
#pragma region RNG
    private:
        RNG _rng;

    public:
        template <typename T>
        T getRandom();
        template <typename T>
        T getRandom(T);
        template <typename T>
        T getRandom(T, T);

#pragma endregion
#pragma region Localization
    private:
        boost::locale::generator _gen;

    public:
        void setLocalization(sf::String& folder, sf::String& domain);
        [[nodiscard]]
        std::basic_string<char> localize(
            const boost::locale::basic_message<char>& string);
#pragma endregion
    };

} // namespace libslh::Engine
