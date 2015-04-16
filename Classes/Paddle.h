//
//  Paddle.h
//  Pong
//
//  Created by Michael Caley on 2014-12-25.
//
//

#ifndef __Pong__Paddle__
#define __Pong__Paddle__

#include "cocos2d.h"


namespace Pong
{
    struct Controls;
    
    class Paddle : public cocos2d::Sprite
    {
    public:
        static Paddle* create(const std::string &filename);
        static Paddle* create(const std::string &filename, const cocos2d::Rect rect);
        Paddle();
        ~Paddle();
        void addEvents();
        void setPhysics();
        void initOptions(int player);
        void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, const cocos2d::Event* event);
        void onKeyReleased(cocos2d::EventKeyboard::KeyCode key, const cocos2d::Event* event);
        void reset();
        void setControls(Pong::Controls &controls);
        void setControls(cocos2d::EventKeyboard::KeyCode up, cocos2d::EventKeyboard::KeyCode down);
        void update(float dt);
        
    private:
        Pong::Controls *_controls;
        bool _buttonUp;
        bool _buttonDown;
        bool _moveUp;
        bool _moveDown;
        cocos2d::PhysicsBody *_physicsBody;
        int _player;
    };
}

#endif /* defined(__Pong__Paddle__) */
