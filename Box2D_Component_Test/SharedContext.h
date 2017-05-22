#pragma once

#include <Box2D/Box2D.h>

struct SharedContext {
	SharedContext() : PhysicsWorld(nullptr) {}
	
	b2World* PhysicsWorld;
};