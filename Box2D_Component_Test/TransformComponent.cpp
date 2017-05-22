#include "TransformComponent.h"
#include "GameObject.h"

TransformComponent::TransformComponent() : m_Transform() {
}

TransformComponent::TransformComponent(GameObject * gameObject) : Component(gameObject) {
}

TransformComponent::~TransformComponent() {
}

void TransformComponent::Update(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_Transform.move(-100.0f * dt, 0.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		m_Transform.move(100.0f * dt, 0.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		m_Transform.move(0.0f, -100.0f * dt);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		m_Transform.move(0.0f, 100.0f * dt);
	}
}

void TransformComponent::Draw(sf::RenderWindow & window) {
	return;
}

const sf::Vector2f & TransformComponent::GetPosition() const {
	return m_Transform.getPosition();
}

void TransformComponent::Print() {
	std::cout << "TransformPrint" << std::endl;
}
