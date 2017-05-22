#pragma once

#include "SharedContext.h"
#include "Component.h"

#include <typeindex>
#include <typeinfo>
#include <unordered_map>

class TransformComponent;

class GameObject {
private:
	std::unordered_map<std::type_index, Component*> m_Components;
public:
	GameObject(SharedContext* context);
	~GameObject();

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	template <typename T>
	T* GetComponent() const {
		auto component = m_Components.find(typeid(T));
		if (component != m_Components.end()) {
			return static_cast<T*>(component->second);
		}
		std::cout << "Could not find component type.. " << std::endl;
		return nullptr;
	}

	template <typename T>
	T* AddComponent() {
		if (m_Components.find(typeid(T)) == m_Components.end()) {
			T* component = new T(this);
			m_Components.emplace(typeid(T), component);
			return component;
		}
		std::cout << "Could not add because of duplicate component type" << std::endl;
		return nullptr;
	}

	template <typename T>
	void AddComponent(T* component) {
		if (m_Components.find(typeid(T)) == m_Components.end()) {
			m_Components.emplace(typeid(T), component);
		}
	}

	const TransformComponent& GetTransform() const;
	SharedContext* GetContext() const;

    void SetPosition(float x, float y);

private:
	TransformComponent* m_Transform;
	SharedContext* m_Context;
};
