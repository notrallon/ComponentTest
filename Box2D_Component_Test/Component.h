#pragma once

#include "SharedContext.h"

#include <SFML\Graphics.hpp>
#include <iostream>

class GameObject;

class Component {
public:
	Component();
	Component(GameObject* gameObject);
	virtual ~Component();

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

protected:
    SharedContext* m_Context;
	GameObject* m_GameObject; // This is the gameobject that has the the component attached to it
};