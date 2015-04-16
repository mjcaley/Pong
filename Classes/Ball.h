//
//  Ball.h
//  Pong
//
//  Created by Michael Caley on 2014-12-25.
//
//

#ifndef __Pong__Ball__
#define __Pong__Ball__

#include "cocos2d.h"


namespace Pong
{
    enum class BallState;
    
    class Ball : public cocos2d::Sprite
    {
    public:
        Ball();
        ~Ball();
        static Ball* create(const std::string &filename);
        static Ball* create(const std::string &filename, const cocos2d::Rect rect);
        void setPhysics();
        bool onContactBegin(const cocos2d::PhysicsContact& contact);
        float getSpeed();
        void setSpeed(float speed);
        Pong::BallState getState();
        void reset();
        void update(float dt);
        
    private:
        cocos2d::PhysicsBody *_physicsBody;
        cocos2d::Vec2 _direction;
        float _angle_limit = 0.7;
        float _speed;
        Pong::BallState _ball_state;
        
        cocos2d::Vec2 randomDirection();
    };
}

#endif /* defined(__Pong__Ball__) */
