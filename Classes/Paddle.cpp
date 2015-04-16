//
//  Paddle.cpp
//  Pong-cocos2d
//
//  Created by Michael Caley on 2014-12-25.
//
//

#include "Paddle.h"

#include "Game.h"
#include "Pong.h"


USING_NS_CC;
using namespace Pong;

Paddle::Paddle()
{
    _buttonDown = false;
    _buttonUp = false;
}

Paddle::~Paddle()
{
    delete _controls;
    removeFromPhysicsWorld();
}

Paddle* Paddle::create(const std::string &filename)
{
    Paddle *paddle = new (std::nothrow) Paddle();
    if (paddle && paddle->initWithFile(filename)) {
        paddle->addEvents();
        paddle->setPhysics();
        paddle->autorelease();
        return paddle;
    }
    
    CC_SAFE_DELETE(paddle);
    return nullptr;
}

Paddle* Paddle::create(const std::string &filename, const Rect rect)
{
    Paddle *paddle = new Paddle();
    if (paddle->initWithFile(filename, rect)) {
        paddle->addEvents();
        paddle->setPhysics();
        paddle->autorelease();
        return paddle;
    }
    
    CC_SAFE_DELETE(paddle);
    return nullptr;
}

void Paddle::addEvents()
{
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Paddle::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Paddle::onKeyReleased, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Paddle::setPhysics()
{
    this->_physicsBody = PhysicsBody::createBox(getContentSize());
    //_physicsBody->setDynamic(false);
    this->_physicsBody->setGravityEnable(false);
    setPhysicsBody(this->_physicsBody);
    //_physicsBody->setCategoryBitmask(0xFFFFFFFF);
    //_physicsBody->setCollisionBitmask(0xFFFFFFFF);
    this->_physicsBody->setContactTestBitmask(0x02);
}

void Paddle::initOptions(int player)
{
    this->_player = player;
}

void Paddle::onKeyPressed(EventKeyboard::KeyCode key, const Event* event)
{
    if (key == this->_controls->up)
    {
        this->_buttonUp = true;
    }
    else if (key == this->_controls->down)
    {
        this->_buttonDown = true;
    }
}

void Paddle::onKeyReleased(EventKeyboard::KeyCode key, const Event* event)
{
    if (key == this->_controls->up)
    {
        this->_buttonUp = false;
    }
    else if (key == this->_controls->down)
    {
        this->_buttonDown = false;
    }
}

void Paddle::setControls(Controls &controls)
{
    this->_controls = &controls;
}

void Paddle::setControls(const EventKeyboard::KeyCode up, const EventKeyboard::KeyCode down)
{
    this->_controls = new Controls {up, down};
}

void Paddle::update(float dt)
{
    if (Game::getGameState() == GameState::Pause)
    {
        return;
    }
    if (this->_buttonUp && !this->_buttonDown)
    {
        if (getPositionY() <= Director::getInstance()->getWinSizeInPixels().height-125 - (this->getBoundingBox().size.height / 2))
        {
            auto move = MoveBy::create(0, Vec2(0, 5));
            this->runAction(move);
        }
    }
    else if (this->_buttonDown && !this->_buttonUp)
    {
        if (getPositionY() >= 20  + (this->getBoundingBox().size.height / 2))
        {
            auto move = MoveBy::create(0, Vec2(0, -5));
            this->runAction(move);
        }
    }
    
}

void Paddle::reset()
{
    this->setPosition(this->getPositionX(), Director::getInstance()->getVisibleSize().height/2);
}