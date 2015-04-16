//
//  Goal.cpp
//  Pong
//
//  Created by Mike Caley on 2015-02-24.
//
//


#include "Goal.h"

#include "cocos2d.h"

#include "Game.h"


USING_NS_CC;
using namespace Pong;


Goal::~Goal()
{
    _eventDispatcher->removeEventListenersForTarget(this);
    removeFromPhysicsWorld();
}

Goal* Goal::create(int player, Size size, Game *game)
{
    Goal *goal = new (std::nothrow) Goal();
    if (goal && goal->init()) {
        goal->setContentSize(size);
        goal->_player = player;
        goal->_game = game;
        goal->setPhysics();
        goal->autorelease();
        return goal;
    }
    
    CC_SAFE_DELETE(goal);
    return nullptr;
}

void Goal::setPhysics()
{
    _physicsBody = PhysicsBody::createBox(getContentSize());
    _physicsBody->setGravityEnable(false);
    setPhysicsBody(_physicsBody);
    _physicsBody->setContactTestBitmask(0x03);
    auto _contactListener = EventListenerPhysicsContact::create();
    _contactListener->onContactBegin = CC_CALLBACK_1(Goal::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_contactListener, this);
}

bool Goal::onContactBegin(const PhysicsContact& contact)
{
    auto shape_a_name = contact.getShapeA()->getBody()->getNode()->getName();
    auto shape_b_name = contact.getShapeB()->getBody()->getNode()->getName();
    auto shape_b_tag = contact.getShapeB()->getBody()->getNode()->getTag();
    
    if (shape_a_name == "Ball" && shape_b_name == "Goal")
    {
        if (shape_b_tag == _player)
        {
            _game->increaseScore(_player);
        }
    }
    return false;
}