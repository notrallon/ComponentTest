#pragma once

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
	GameObject* m_GameObject; // This is the gameobject that has the the component attached to it
};