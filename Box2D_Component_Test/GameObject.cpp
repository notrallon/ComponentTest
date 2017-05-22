#include "TransformComponent.h"
#include "GameObject.h"

GameObject::GameObject(SharedContext* context) : m_Context(context) {
	m_Transform = AddComponent<TransformComponent>();
}

GameObject::~GameObject() {
	for (auto component : m_Components) {
		delete component.second;
	}
	m_Components.clear();
}

void GameObject::Update(float dt) {
	for (auto component : m_Components) {
		component.second->Update(dt);
	}
}

void GameObject::Draw(sf::RenderWindow& window) {
	for (auto component : m_Components) {
		component.second->Draw(window);
	}
}

const TransformComponent& GameObject::GetTransform() const {
	return *m_Transform;
}

const SharedContext& GameObject::GetContext() const {
	return *m_Context;
}
