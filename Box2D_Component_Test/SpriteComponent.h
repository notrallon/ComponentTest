#pragma once

#include "Component.h"

class SpriteComponent : public Component {
public:
	SpriteComponent();
	SpriteComponent(GameObject* gameObject);
	virtual ~SpriteComponent();

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetTexture(sf::Texture& texture);

private:
	sf::Sprite* m_Sprite;
};