//
//  ControlsMenu.h
//  Pong
//
//  Created by Michael Caley on 2015-03-21.
//
//

#ifndef __Pong__ControlsMenu__
#define __Pong__ControlsMenu__

#include "cocos2d.h"


namespace Pong
{
    class ControlButton;
    
    class ControlsMenu : public cocos2d::LayerColor
    {
    public:
        static cocos2d::Scene* createScene();
        static ControlsMenu* getInstance();
        CREATE_FUNC(ControlsMenu);
        
        ~ControlsMenu();
        
        virtual bool init();
        
        void addEvents();
        void enableControlCapture(Pong::ControlButton *sender);
        void menuCancel(cocos2d::Ref *sender);
        void menuSave(cocos2d::Ref *sender);
        void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
        
    private:
        static ControlsMenu* _instance;
        
        bool _capture_control = false;
        Pong::ControlButton *_capture_sender;
        
        Pong::ControlButton *_p0_up;
        Pong::ControlButton *_p0_down;
        Pong::ControlButton *_p1_up;
        Pong::ControlButton *_p1_down;
    };
}

#endif /* defined(__Pong__ControlsMenu__) */
