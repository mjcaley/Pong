//
//  Goal.h
//  Pong
//
//  Created by Mike Caley on 2015-02-24.
//
//

#ifndef __Pong__Goal__
#define __Pong__Goal__

#include "cocos2d.h"


namespace Pong
{
    class Game;
    
    class Goal : public cocos2d::Node
    {
    public:
        ~Goal();
        static Goal* create(int player, cocos2d::Size size, Pong::Game *game);
        void setPhysics();
        bool onContactBegin(const cocos2d::PhysicsContact& contact);
        
    private:
        int _player;
        Pong::Game *_game;
        cocos2d::PhysicsBody* _physicsBody;
    };
}

#endif /* defined(__Pong__Goal__) */
