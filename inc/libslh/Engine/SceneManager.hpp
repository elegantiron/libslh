#pragma once

#include "libslh/Engine/Scene.hpp"
#include "libslh/Types.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>
#include <stack>

namespace libslh::Engine {
    class SceneManager : public sf::Drawable {
        ScenePtr             _nextScene{nullptr};
        std::stack<ScenePtr> _scenes;
        void                 transitionScene();
        void                 popScene(bool& nowEmpty);

    public:
        void iterate(const GameTime& gameTime,
                     bool&           successful,
                     bool&           keepRunning);
        void handleEvent(std::optional<sf::Event> event,
                         bool&                    successful,
                         bool&                    keepRunning);
        void setNextScene(ScenePtr pScene);
        void draw(sf::RenderTarget& target,
                  sf::RenderStates  states) const override;
        [[nodiscard]]
        ScenePtr getCurrentScene() const;
    };
}
