#pragma once

#include <Box2D/Box2D.h>

struct SharedContext {
	SharedContext() {}
	
	b2World* world;
};