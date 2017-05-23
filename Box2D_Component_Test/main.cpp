#include "GameObject.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "BoxColliderComponent.h"
#include "SharedContext.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


int main() {
	sf::RenderWindow window;

	window.create({ 1280, 720, 32 }, "Title");
    sf::View view;
    view.zoom(1.0f / 32.0f);
    view.setCenter(sf::Vector2f(0, 0));
    window.setView(view);

	SharedContext sContext;
    b2World world = b2World(b2Vec2(0.0f, 0.0f));

    sContext.PhysicsWorld = &world;
    
    GameObject player(&sContext);
	sf::Texture* texture = new sf::Texture();
    player.SetPosition(view.getCenter().x, view.getCenter().y);
    player.AddComponent<BoxColliderComponent>();

	texture->loadFromFile("goku.png");
	SpriteComponent* sprite = player.AddComponent<SpriteComponent>();
	//SpriteComponent* sprite = new SpriteComponent();
	sprite->SetTexture(*texture);

	//player.AddComponent(sprite);

	player.GetComponent<SpriteComponent>();

	player.GetComponent<TransformComponent>()->Print();

    GameObject collisionBox(&sContext);
    collisionBox.SetPosition(500 / 32, 500 / 32);
    BoxColliderComponent* collider = collisionBox.AddComponent<BoxColliderComponent>();
    collider->SetStatic(true);

	sf::Clock clock;
	sf::Time time;

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    float currentDt = 0.0f;

	while (window.isOpen()) {
		sf::Event evnt;
		time = clock.restart();
		float dt = time.asSeconds();
        currentDt += dt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed: {
				window.close();
			}
			default:
				break;
			}
		}
        view.setCenter(player.GetComponent<TransformComponent>()->GetPosition());
        window.setView(view);
		player.Update(dt);

        if (currentDt > timeStep) {
            world.Step(timeStep, velocityIterations, positionIterations);
            currentDt -= timeStep;
        }

		window.clear(sf::Color::Magenta);
        player.Draw(window);
        collisionBox.Draw(window);
		window.display();
	}
}