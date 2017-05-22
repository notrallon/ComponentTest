#include "Component.h"
#include "GameObject.h"

Component::Component() : m_GameObject(nullptr), m_Context(nullptr) {
}

Component::Component(GameObject* gameObject) : m_GameObject(gameObject), m_Context(nullptr) {
    m_Context = m_GameObject->GetContext();
}

Component::~Component() {
}
