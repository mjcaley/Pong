//
//  Menu.h
//  Pong
//
//  Created by Michael Caley on 2015-02-25.
//
//

#ifndef __Pong__Menu__
#define __Pong__Menu__

#include "cocos2d.h"


namespace Pong
{
    class MainMenu : public cocos2d::LayerColor
    {
    public:
        static cocos2d::Scene* createScene();
        CREATE_FUNC(MainMenu);
        
        virtual bool init();
        
        void addEvents();
        
        void menuControls(cocos2d::Ref *sender);
        void menuExit(cocos2d::Ref *sender);
        void menuPlay(cocos2d::Ref *sender);
        void menuResume(cocos2d::Ref *sender);
        
        void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    };
}

#endif /* defined(__Pong__Menu__) */
