#pragma once
#include "Component.h"

#include <Box2D/Box2D.h>

class BoxColliderComponent : public Component {
public:
	BoxColliderComponent();
	virtual ~BoxColliderComponent();

private:
	b2Body* m_Body;
};