//
//  Pong.h
//  Pong
//
//  Created by Mike Caley on 2014-12-23.
//
//

#ifndef __Pong__Pong__
#define __Pong__Pong__

#include "cocos2d.h"


namespace Pong
{
    enum class BallState
    {
        Reset,
        Ready,
        Launch,
        Moving
    };
    
    struct Controls
    {
        cocos2d::EventKeyboard::KeyCode up;
        cocos2d::EventKeyboard::KeyCode down;
    };
    
    enum class GameState
    {
        Play,
        Pause,
        Reset
    };
}

#endif /* defined(__Pong__Pong__) */