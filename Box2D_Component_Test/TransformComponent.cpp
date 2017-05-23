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
    BoxColliderComponent* boxCollider = m_GameObject->GetComponent<BoxColliderComponent>();
    if (boxCollider != nullptr) {
        SetPosition(boxCollider->GetPosition().x, boxCollider->GetPosition().y);
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
    // TODO (richard): Fix a way to get/set the size of the transform.
    return sf::Vector2f(3.46875, 4);
}

void TransformComponent::SetPosition(float x, float y) {
    m_Transform.setPosition(x, y);
}

void TransformComponent::Print() {
	std::cout << "TransformPrint" << std::endl;
}
