#pragma once
#include "Component.h"

#include <Box2D/Box2D.h>

class BoxColliderComponent : public Component {
public:
	            BoxColliderComponent();
                BoxColliderComponent(GameObject* gameObject);
	virtual     ~BoxColliderComponent();

    virtual void Update(float dt) override;
    virtual void Draw(sf::RenderWindow& window) override;

    const sf::Vector2f& GetPosition() const;

private:
	b2Body*      m_Body;
};