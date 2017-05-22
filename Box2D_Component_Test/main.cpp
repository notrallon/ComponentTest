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

	SharedContext sContext;
    b2World world = b2World(b2Vec2(0.0f, 0.0f));

    sContext.PhysicsWorld = &world;
    
    GameObject player(&sContext);
	sf::Texture* texture = new sf::Texture();

    player.AddComponent<BoxColliderComponent>();

	texture->loadFromFile("goku.png");
	SpriteComponent* sprite = player.AddComponent<SpriteComponent>();
	//SpriteComponent* sprite = new SpriteComponent();
	sprite->SetTexture(*texture);

	//player.AddComponent(sprite);

	player.GetComponent<SpriteComponent>();

	player.GetComponent<TransformComponent>()->Print();

    GameObject collisionBox(&sContext);
    collisionBox.AddComponent<BoxColliderComponent>();

	sf::Clock clock;
	sf::Time time;

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

	while (window.isOpen()) {
		sf::Event evnt;
		time = clock.restart();
		float dt = time.asSeconds();
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed: {
				window.close();
			}
			default:
				break;
			}
		}
        world.Step(timeStep, velocityIterations, positionIterations);
		player.Update(dt);

		window.clear(sf::Color::Magenta);
        player.Draw(window);
		window.display();
	}
}