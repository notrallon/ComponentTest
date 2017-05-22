#include "GameObject.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "SharedContext.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


int main() {
	sf::RenderWindow window;

	window.create({ 1280, 720, 32 }, "Title");

	GameObject player;
	sf::Texture* texture = new sf::Texture();

	SharedContext sContext;
	b2World world = b2World(b2Vec2(0.0f, 10.0f));
	sContext.world = &world;

	texture->loadFromFile("goku.png");
	SpriteComponent* sprite = player.AddComponent<SpriteComponent>();
	//SpriteComponent* sprite = new SpriteComponent();
	sprite->SetTexture(*texture);

	player.AddComponent(sprite);

	player.GetComponent<SpriteComponent>();

	player.GetComponent<TransformComponent>()->Print();

	sf::Clock clock;
	sf::Time time;

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
		player.Update(dt);

		window.clear(sf::Color::Magenta);
		sprite->Draw(window);
		window.display();
	}
}