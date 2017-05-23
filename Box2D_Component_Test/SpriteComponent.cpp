#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"

SpriteComponent::SpriteComponent() : Component() {
	m_Sprite = new sf::Sprite();
}

SpriteComponent::SpriteComponent(GameObject* gameObject) : Component(gameObject) {
	m_Sprite = new sf::Sprite();
}

SpriteComponent::~SpriteComponent() {
	delete m_Sprite;
}

void SpriteComponent::Update(float dt) {
	m_Sprite->setPosition(m_GameObject->GetTransform().GetPosition());
}

void SpriteComponent::Draw(sf::RenderWindow& window) {
	window.draw(*m_Sprite);
}

void SpriteComponent::SetTexture(sf::Texture& texture) {
    sf::Image image = texture.copyToImage();
	m_Sprite->setTexture(texture);
    m_Sprite->setScale(sf::Vector2f(1.0f / 32.0f, 1.0f / 32.0f));
}
