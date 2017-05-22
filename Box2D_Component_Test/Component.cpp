#include "Component.h"
#include "GameObject.h"

Component::Component() : m_GameObject(nullptr) {
}

Component::Component(GameObject* gameObject) : m_GameObject(gameObject) {
	
}

Component::~Component() {
}
