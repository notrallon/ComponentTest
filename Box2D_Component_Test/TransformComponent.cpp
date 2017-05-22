#include "TransformComponent.h"
#include "BoxColliderComponent.h"
#include "GameObject.h"

TransformComponent::TransformComponent() : m_Transform() {
}

TransformComponent::TransformComponent(GameObject * gameObject) : Component(gameObject) {
}

TransformComponent::~TransformComponent() {
}

void TransformComponent::Update(float dt) {
    if (m_GameObject->GetComponent<BoxColliderComponent>() != nullptr) {
        m_Transform.setPosition(m_GameObject->GetComponent<BoxColliderComponent>()->GetPosition());
    } else {
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
}

void TransformComponent::Draw(sf::RenderWindow& window) {
	return;
}

const sf::Vector2f& TransformComponent::GetPosition() const {
	return m_Transform.getPosition();
}

const sf::Vector2f& TransformComponent::GetSize() const {
    return sf::Vector2f(111, 128);
}

void TransformComponent::SetPosition(float x, float y) {
    m_Transform.setPosition(x, y);
}

void TransformComponent::Print() {
	std::cout << "TransformPrint" << std::endl;
}
