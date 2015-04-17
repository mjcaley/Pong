//
//  Menu.cpp
//  Pong
//
//  Created by Michael Caley on 2015-02-25.
//
//

#include "MainMenu.h"

#include "cocos2d.h"

#include "ControlsMenu.h"
#include "Game.h"
#include "Pong.h"

using namespace Pong;
USING_NS_CC;


Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool MainMenu::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 255)))
    {
        return false;
    }
    
    this->addEvents();
    
    auto title = Label::createWithTTF("Pong", "fonts/Cave-Story.ttf", 100);
    title->setAlignment(TextHAlignment::CENTER);
    title->setPosition(visibleSize.width/2, visibleSize.height-50);
    addChild(title);
    
    auto menu_font = TTFConfig();
    menu_font.fontFilePath = "fonts/Cave-Story.ttf";
    menu_font.fontSize = 50;
    
    Label *label0;
    MenuItemLabel *item0;
    if (Game::getGameInstance())
    {
        label0 = Label::createWithTTF(menu_font, "Resume", TextHAlignment::CENTER);
        label0->setColor(Color3B::WHITE);
        item0 = MenuItemLabel::create(label0, CC_CALLBACK_1(MainMenu::menuResume, this));
    }
    else
    {
        label0 = Label::createWithTTF(menu_font, "Play", TextHAlignment::CENTER);
        label0->setColor(Color3B::WHITE);
        item0 = MenuItemLabel::create(label0, CC_CALLBACK_1(MainMenu::menuPlay, this));
    }
    
    auto label1 = Label::createWithTTF(menu_font, "Controls", TextHAlignment::CENTER);
    label1->setColor(Color3B::WHITE);
    auto item1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MainMenu::menuControls, this));
    
    auto label2 = Label::createWithTTF(menu_font, "Exit", TextHAlignment::CENTER);
    auto item2 = MenuItemLabel::create(label2, CC_CALLBACK_1(MainMenu::menuExit, this));
    
    auto menu = Menu::create(item0, item1, item2, NULL);
    menu->alignItemsVerticallyWithPadding(30);
    this->addChild(menu);
    
    return true;
}

void MainMenu::addEvents()
{
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(MainMenu::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void MainMenu::menuControls(Ref *sender)
{
    Director::getInstance()->pushScene(ControlsMenu::createScene());
}

void MainMenu::menuExit(Ref *sender)
{
    Director::getInstance()->end();
    exit(0);
}

void MainMenu::menuPlay(Ref *sender)
{
    Game::setGameState(GameState::Play);
    Director::getInstance()->replaceScene(Game::createScene());
}

void MainMenu::menuResume(Ref *sender)
{
    Director::getInstance()->popScene();
}

void MainMenu::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        Director::getInstance()->popScene();
        if (Game::getGameState() == GameState::Reset)
        {
            return;
        }
        Game::setGameState(GameState::Play);
    }
}