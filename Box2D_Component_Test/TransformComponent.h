#pragma once

#include "Component.h"

class TransformComponent : public Component {
public:
	TransformComponent();
	TransformComponent(GameObject* gameObject);
	virtual ~TransformComponent();

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	const sf::Vector2f& GetPosition() const;
    const sf::Vector2f& GetSize() const;

    void SetPosition(float x, float y);

	void Print();

private:
	sf::Transformable m_Transform;
};