//
//  ControlButton.h
//  Pong
//
//  Created by Michael Caley on 2015-03-23.
//
//

#ifndef __Pong__ControlButton__
#define __Pong__ControlButton__

#include "cocos2d.h"


namespace Pong
{
    class ControlButton : public cocos2d::Label
    {
    public:
#ifdef _WIN32
        // No support for inherited constructors yet
        ControlButton(cocos2d::FontAtlas *atlas = nullptr, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT,
                      cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP, bool useDistanceField = false, bool useA8Shader = false) :
        Label(atlas, hAlignment, vAlignment, useDistanceField, useA8Shader) { };
#else
        using cocos2d::Label::Label;
#endif
        static ControlButton* createWithTTF(const std::string& title, const std::string& fontFile, float fontSize, const cocos2d::Size& dimensions = cocos2d::Size::ZERO, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);
        static ControlButton* createWithTTF(const cocos2d::TTFConfig& ttfConfig, const std::string& title, cocos2d::TextHAlignment alignment = cocos2d::TextHAlignment::CENTER, int maxLineWidth = 0);
        
        void addEvents();
        void onMouseUp(cocos2d::Event *event);
        cocos2d::EventKeyboard::KeyCode getControl();
        void setControl(cocos2d::EventKeyboard::KeyCode keyCode);
        
    private:
        std::string _text;
        cocos2d::EventKeyboard::KeyCode _key_code;
    };
}

#endif /* defined(__Pong__ControlButton__) */
