#include "BoxColliderComponent.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "GameObject.h"

#include <Box2D\Box2D.h>

BoxColliderComponent::BoxColliderComponent() : Component(), m_Body(nullptr) {

}

BoxColliderComponent::BoxColliderComponent(GameObject* gameObject) : Component(gameObject) {
    float32 pixelScaler = 1.0f / 32.0f;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(m_GameObject->GetTransform().GetPosition().x, 
                         m_GameObject->GetTransform().GetPosition().y);

    m_Body = m_Context->PhysicsWorld->CreateBody(&bodyDef);

    b2PolygonShape groundBox;

    groundBox.SetAsBox((m_GameObject->GetTransform().GetSize().x / 2.0f) * pixelScaler, 
                       (m_GameObject->GetTransform().GetSize().y / 2.0f) * pixelScaler);

    m_Body->CreateFixture(&groundBox, 10.0f);
}

BoxColliderComponent::~BoxColliderComponent() {
    
}

void BoxColliderComponent::Update(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        m_Body->ApplyForceToCenter(b2Vec2(-100, 0), true);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        m_Body->ApplyForceToCenter(b2Vec2(100, 0), true);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        m_Body->ApplyForceToCenter(b2Vec2(0, -100), true);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        m_Body->ApplyForceToCenter(b2Vec2(0, 100), true);
    }
}

void BoxColliderComponent::Draw(sf::RenderWindow & window) {
    sf::RectangleShape shape;
    float32 pixelScaler = 1.0f / 32.0f;

    sf::Vector2f size = m_GameObject->GetTransform().GetSize();
    b2Vec2 pos = m_Body->GetPosition();

    shape.setSize(size);
    std::cout << shape.getSize().x << shape.getSize().y << std::endl;
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(pos.x * pixelScaler, pos.y * pixelScaler);
    window.draw(shape);
}

const sf::Vector2f & BoxColliderComponent::GetPosition() const {
    float32 pixelScaler = 1.0f / 32.0f;
    sf::Vector2f pos(m_Body->GetPosition().x * pixelScaler, m_Body->GetPosition().y * pixelScaler);
    //std::cout << pos.x << pos.y << std::endl;
    return pos;
}
