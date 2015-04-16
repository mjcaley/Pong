//
//  ControlsMenu.cpp
//  Pong
//
//  Created by Michael Caley on 2015-03-21.
//
//

#include "ControlsMenu.h"

#include "cocos2d.h"

#include "Game.h"
#include "ControlButton.h"
#include "Pong.h"

using namespace Pong;
USING_NS_CC;


ControlsMenu* ControlsMenu::_instance = nullptr;

Scene* ControlsMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ControlsMenu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

ControlsMenu* ControlsMenu::getInstance()
{
    return ControlsMenu::_instance;
}

ControlsMenu::~ControlsMenu()
{
    ControlsMenu::_instance = nullptr;
}

bool ControlsMenu::init()
{
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 255)))
    {
        return false;
    }
    
    ControlsMenu::_instance = this;
    
    this->addEvents();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto menu_font = TTFConfig();
    menu_font.fontFilePath = "fonts/Cave-Story.ttf";
    menu_font.fontSize = 50;
    
    // Titles
    auto p0 = Label::createWithTTF(menu_font, "Player 1", TextHAlignment::CENTER);
    p0->setColor(Color3B::WHITE);
    p0->setPosition(visibleSize.width/4, visibleSize.height/4*3);
    this->addChild(p0);
    
    auto p1 = Label::createWithTTF(menu_font, "Player 2", TextHAlignment::CENTER);
    p1->setColor(Color3B::WHITE);
    p1->setPosition(visibleSize.width/4*3, visibleSize.height/4*3);
    this->addChild(p1);
    
    // Controls
    _p0_up = ControlButton::createWithTTF(menu_font, "Up", TextHAlignment::CENTER);
    _p0_up->setColor(Color3B::WHITE);
    _p0_up->setPosition(visibleSize.width/4, visibleSize.height/4*2.5);
    _p0_up->setTag(1);
    _p0_up->setControl(Game::getControls(0).up);
    this->addChild(_p0_up);
    
    _p0_down = ControlButton::createWithTTF(menu_font, "Down", TextHAlignment::CENTER);
    _p0_down->setColor(Color3B::WHITE);
    _p0_down->setPosition(visibleSize.width/4, visibleSize.height/4*1.5);
    _p0_down->setTag(1);
    _p0_down->setControl(Game::getControls(0).down);
    this->addChild(_p0_down);
    
    _p1_up = ControlButton::createWithTTF(menu_font, "Up", TextHAlignment::CENTER);
    _p1_up->setColor(Color3B::WHITE);
    _p1_up->setPosition(visibleSize.width/4*3, visibleSize.height/4*2.5);
    _p1_up->setTag(1);
    _p1_up->setControl(Game::getControls(1).up);
    this->addChild(_p1_up);
    
    _p1_down = ControlButton::createWithTTF(menu_font, "Down", TextHAlignment::CENTER);
    _p1_down->setColor(Color3B::WHITE);
    _p1_down->setPosition(visibleSize.width/4*3, visibleSize.height/4*1.5);
    _p1_down->setTag(1);
    _p1_down->setControl(Game::getControls(1).down);
    this->addChild(_p1_down);
    
    // Save/Cancel
    auto save_label = Label::createWithTTF(menu_font, "Save", TextHAlignment::CENTER);
    auto save_menu = MenuItemLabel::create(save_label, CC_CALLBACK_1(ControlsMenu::menuSave, this));

    auto cancel_label = Label::createWithTTF(menu_font, "Cancel", TextHAlignment::CENTER);
    auto cancel_menu = MenuItemLabel::create(cancel_label, CC_CALLBACK_1(ControlsMenu::menuCancel, this));
    
    auto menu = Menu::create(save_menu, cancel_menu, NULL);
    menu->setPosition(visibleSize.width/2, 70);
    menu->alignItemsHorizontallyWithPadding(100);
    this->addChild(menu);
    
    return true;
}

void ControlsMenu::addEvents()
{
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(ControlsMenu::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void ControlsMenu::enableControlCapture(ControlButton *sender)
{
    this->_capture_sender = sender;
    this->_capture_control = true;
}

void ControlsMenu::menuCancel(cocos2d::Ref *sender)
{
    Director::getInstance()->popScene();
}

void ControlsMenu::menuSave(cocos2d::Ref *sender)
{
    Game::setControls(0, Pong::Controls{_p0_up->getControl(), _p0_down->getControl()});
    Game::setControls(1, Pong::Controls{_p1_up->getControl(), _p1_down->getControl()});
    Director::getInstance()->popScene();
}

void ControlsMenu::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
    if (this->_capture_control) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
        {
            return;
        }
        this->_capture_sender->setControl(keyCode);
        this->_capture_control = false;
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        Director::getInstance()->popScene();
    }
}