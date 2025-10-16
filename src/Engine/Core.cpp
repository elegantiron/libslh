#include "libslh/Engine/Core.hpp"

namespace {
    constexpr int FRAME_LIMIT = 60;
}

namespace libslh::Engine {

    void Core::init(sf::VideoMode mode, const sf::String& title,
                    bool& successful) {
        _window.create(mode, title, sf::Style::Titlebar | sf::Style::Close);
        _window.setKeyRepeatEnabled(false);
        _window.setFramerateLimit(FRAME_LIMIT);
        _window.setPosition(sf::Vector2i(0, 0));

        successful = true;
    }

    Core& Core::getInstance() {
        if (_instance == nullptr) {
            std::random_device dev;
            _instance = new Core(dev);
        }
        return *_instance;
    }

    Core* Core::_instance{nullptr};

    void Core::iterate(const GameTime& gameTime, bool& successful,
                       bool& keepRunning) {
        keepRunning = false;
        successful  = false;
        _sceneMan.iterate(gameTime, successful, keepRunning);
    }

    void Core::handleEvent(std::optional<sf::Event> event, bool& successful,
                           bool& keepRunning) {
        if (event->is<sf::Event::Closed>()) {
            keepRunning = false;
            return;
        }

        _sceneMan.handleEvent(event, successful, keepRunning);
    }

    void Core::run() {
        bool keepRunning = true;
        bool successful  = true;
        while (successful && keepRunning) {
            iterate(_clock.newFrame(), successful, keepRunning);
            if (!successful || !keepRunning) {
                quit(successful);
                return;
            }
            while (std::optional event = _window.pollEvent()) {
                handleEvent(event, successful, keepRunning);
                if (!successful || !keepRunning) {
                    quit(successful);
                    return;
                }
            }
            _window.clear(_backgroundColor);
            _window.draw(_sceneMan);
            _window.display();
        }
    }

    void Core::quit(bool /*successful*/) {}

    const sf::RenderWindow& Core::getWindow() const {
        return _window;
    }

    void Core::setNextScene(ScenePtr pScene) {
        _sceneMan.setNextScene(std::move(pScene));
    }

    ScenePtr Core::getCurrentScene() const {
        return _sceneMan.getCurrentScene();
    }

    std::basic_string<char> Core::localize(
        const boost::locale::basic_message<char>& string) {
        return string.str(_gen(_locale));
    }
} // namespace libslh::Engine
