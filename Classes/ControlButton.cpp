//
//  ControlButton.cpp
//  Pong
//
//  Created by Michael Caley on 2015-03-23.
//
//

#include "ControlButton.h"

#include "cocos2d.h"

#include "ControlsMenu.h"
#include "UtilityFunctions.h"

using namespace Pong;
USING_NS_CC;


ControlButton* ControlButton::createWithTTF(const std::string& title, const std::string& fontFile, float fontSize, const Size& dimensions /* = Size::ZERO */, TextHAlignment hAlignment /* = TextHAlignment::LEFT */, TextVAlignment vAlignment /* = TextVAlignment::TOP */)
{
    auto ret = new (std::nothrow) ControlButton(nullptr,hAlignment,vAlignment);
    
    if (ret && FileUtils::getInstance()->isFileExist(fontFile))
    {
        TTFConfig ttfConfig(fontFile.c_str(),fontSize,GlyphCollection::DYNAMIC);
        if (ret->setTTFConfig(ttfConfig))
        {
            ret->setDimensions(dimensions.width,dimensions.height);
            ret->setString(title);
            ret->_text = title; // Set the title
            ret->addEvents();
            
            ret->autorelease();
            
            return ret;
        }
    }
    
    delete ret;
    return nullptr;
}

ControlButton* ControlButton::createWithTTF(const TTFConfig& ttfConfig, const std::string& title, TextHAlignment alignment /* = TextHAlignment::CENTER */, int maxLineWidth /* = 0 */)
{
    auto ret = new (std::nothrow) ControlButton(nullptr,alignment);
    
    if (ret && FileUtils::getInstance()->isFileExist(ttfConfig.fontFilePath) && ret->setTTFConfig(ttfConfig))
    {
        ret->setMaxLineWidth(maxLineWidth);
        ret->setString(title);
        ret->_text = title; // Set the static title
        ret->addEvents();
        
        ret->autorelease();
        
        return ret;
    }
    
    delete ret;
    return nullptr;
}

void ControlButton::addEvents()
{
    auto listener = EventListenerMouse::create();
    listener->onMouseUp = CC_CALLBACK_1(ControlButton::onMouseUp, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void ControlButton::onMouseUp(cocos2d::Event *event)
{
    auto e = dynamic_cast<EventMouse*>(event);
    if (ClickedMe(e, dynamic_cast<Node*>(this)))
    {
        auto parent = ControlsMenu::getInstance();
        parent->enableControlCapture(this);
    }
}

EventKeyboard::KeyCode ControlButton::getControl()
{
    return this->_key_code;
}

void ControlButton::setControl(cocos2d::EventKeyboard::KeyCode keyCode)
{
    this->_key_code = keyCode;
    this->setString(this->_text + ": " + KeyCodeToString(_key_code));
}