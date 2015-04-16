//
//  Ball.cpp
//  Pong-cocos2d
//
//  Created by Michael Caley on 2014-12-25.
//
//


#include "Ball.h"

#include <random>

#include "cocos2d.h"

#include "Game.h"
#include "Pong.h"

USING_NS_CC;
using namespace Pong;


Ball::Ball()
{
    this->_speed = 300.0f;
    this->_ball_state = BallState::Ready;
}

Ball::~Ball()
{
    _eventDispatcher->removeEventListenersForTarget(this);
    removeFromPhysicsWorld();
}

Ball* Ball::create(const std::string &filename)
{
    Ball *ball = new (std::nothrow) Ball();
    if (ball && ball->initWithFile(filename)) {
        ball->setPhysics();
        ball->autorelease();
        return ball;
    }
    
    CC_SAFE_DELETE(ball);
    return nullptr;
}

Ball* Ball::create(const std::string &filename, const Rect rect)
{
    Ball *ball = new (std::nothrow) Ball();
    if (ball && ball->initWithFile(filename, rect)) {
        ball->setPhysics();
        ball->autorelease();
        return ball;
    }
    
    CC_SAFE_DELETE(ball);
    return nullptr;
}

Vec2 Ball::randomDirection()
{
    // TODO: Random number generator needed
    float x, y;
    if (std::rand() % 2 == 0)
    {
        x = -1;
    }
    else
    {
        x = 1;
    }
    
    y = -1 + static_cast<float> (rand()) /( static_cast <float> (RAND_MAX/(1 - -1)));
    
    CCLOG("Random direction: %f, %f", x, y);
    return Vec2(x, y);
}

void Ball::setPhysics()
{
    this->_physicsBody = PhysicsBody::createCircle(getContentSize().width/2);
    this->_physicsBody->setGravityEnable(false);
    setPhysicsBody(this->_physicsBody);
    //_physicsBody->setCategoryBitmask(0xFFFFFFFF);
    //_physicsBody->setCollisionBitmask(0xFFFFFFFF);
    this->_physicsBody->setContactTestBitmask(0x01);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Ball::onContactBegin, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool Ball::onContactBegin(const PhysicsContact& contact)
{
    // Shape A: ball       Shape B: whatever
    if (this->_physicsBody->getContactTestBitmask() & contact.getShapeA()->getContactTestBitmask())
    {
        auto node = contact.getShapeB()->getBody()->getNode();
        auto name = node->getName();
        if (name == "Paddle")
        {
            auto paddle_point = node->getPosition();
            auto paddle_height = node->getContentSize().height;
            auto contact_point = contact.getContactData()->points[0];
            
            float x, y;
            // Reverse direction; x always at constant speed
            x = this->_direction.x * -1;
            // (percentage of paddle height) * angle limit
            y = (contact_point.y - paddle_point.y) / (paddle_height / 2) * this->_angle_limit;
            this->_direction = Vec2(x, y);
        }
        else if (name == "Goal")
        {
            this->reset();
        }
        else
        {
            this->_direction = Vec2(this->_direction.x, this->_direction.y * -1);
        }
    }
    return false;
}

void Ball::reset()
{
    Size winSize = Director::getInstance()->getWinSizeInPixels();
    setPosition(winSize.width/2, winSize.height/2);
    this->_ball_state = BallState::Ready;
}

float Ball::getSpeed()
{
    return this->_speed;
}

void Ball::setSpeed(float speed)
{
    this->_speed = speed;
}


Pong::BallState Ball::getState()
{
    return this->_ball_state;
}

void Ball::update(float dt)
{
    if(Game::getGameState() == GameState::Pause || Game::getGameState() == GameState::Reset)
    {
        return;
    }
    
    if (this->_ball_state == BallState::Ready)
    {
        this->_ball_state = BallState::Launch;
    }
    else if (this->_ball_state == BallState::Launch)
    {
        this->_direction = this->randomDirection();
        this->_ball_state = BallState::Moving;
    }
    else if (this->_ball_state == BallState::Moving)
    {
        setPosition(getPosition() + Vec2(this->_direction * _speed * dt));
    }
}