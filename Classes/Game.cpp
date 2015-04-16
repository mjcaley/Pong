//
//  Game.cpp
//  Pong
//
//  Created by Michael Caley on 2014-12-29.
//
//

#include "Game.h"

#include "cocos2d.h"

#include "Ball.h"
#include "Goal.h"
#include "MainMenu.h"
#include "Paddle.h"
#include "Pong.h"
#include "UtilityFunctions.h"


USING_NS_CC;
using namespace Pong;


GameState Game::_game_state = GameState::Pause;
Game* Game::_instance = nullptr;
Controls Game::_p0_controls = Pong::Controls{cocos2d::EventKeyboard::KeyCode::KEY_A, cocos2d::EventKeyboard::KeyCode::KEY_Z};
Controls Game::_p1_controls = Pong::Controls{cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW, cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW};

Game::Game()
{
    Game::_instance = this;
}

Game::~Game()
{
    Game::_instance = nullptr;
}

Scene* Game::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = Game::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

Game* Game::getGameInstance()
{
    return _instance;
}

bool Game::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    this->addEvents();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // Player 0 paddle
    _p0_paddle = Paddle::create("Sprites/PongSpriteSheet.png", Rect(24, 2, 20, 64));
    _p0_paddle->setScale(1.5);
    _p0_paddle->setPosition(60, visibleSize.height/2);
    _p0_paddle->initOptions(1);
    _p0_paddle->setControls(_p0_controls);
    _p0_paddle->setName("Paddle");
    _p0_paddle->setTag(1);
    _p0_paddle->scheduleUpdate();
    this->addChild(_p0_paddle);
    
    // Player 1 paddle
    _p1_paddle = Paddle::create("Sprites/PongSpriteSheet.png", Rect(24, 2, 20, 64));
    _p1_paddle->setScale(1.5);
    _p1_paddle->setPosition(visibleSize.width-60, visibleSize.height/2);
    _p1_paddle->initOptions(2);
    _p1_paddle->setControls(_p1_controls);
    _p1_paddle->setName("Paddle");
    _p1_paddle->setTag(2);
    _p1_paddle->scheduleUpdate();
    this->addChild(_p1_paddle);
    
    _ball = Ball::create("Sprites/PongSpriteSheet.png", Rect(2, 2, 20, 20));
    _ball->setScale(1.5);
    _ball->setPosition(visibleSize.width/2, visibleSize.height/2);
    _ball->setName("Ball");
    _ball->setTag(0);
    _ball->scheduleUpdate();
    this->addChild(_ball);
    
    auto top_wall = Sprite::create("Sprites/PongSpriteSheet.png", Rect(46, 2, 960, 10));
    top_wall->setContentSize(Size(visibleSize.width, 10));
    top_wall->setPosition(Vec2(visibleSize.width/2, visibleSize.height-110));
    auto topWallPhysicsBody = PhysicsBody::createBox(top_wall->getContentSize());
    topWallPhysicsBody->setGravityEnable(false);
    topWallPhysicsBody->setContactTestBitmask(0x02);
    top_wall->setPhysicsBody(topWallPhysicsBody);
    top_wall->setName("Wall");
    this->addChild(top_wall);
    
    auto bottom_wall = Sprite::create("Sprites/PongSpriteSheet.png", Rect(46, 2, 960, 10));
    bottom_wall->setContentSize(Size(visibleSize.width, 10));
    bottom_wall->setPosition(Vec2(visibleSize.width/2, 5));
    auto bottomWallPhysicsBody = PhysicsBody::createBox(bottom_wall->getContentSize());
    bottomWallPhysicsBody->setGravityEnable(false);
    bottomWallPhysicsBody->setContactTestBitmask(0x02);
    bottom_wall->setPhysicsBody(bottomWallPhysicsBody);
    bottom_wall->setName("Wall");
    this->addChild(bottom_wall);
    
    // Goals
    auto goal0 = Goal::create(0, Size(20, visibleSize.height), this);
    goal0->setPosition(-10, visibleSize.height/2);
    goal0->setTag(1);
    goal0->setName("Goal");
    this->addChild(goal0);
    
    auto goal1 = Goal::create(1, Size(20, visibleSize.height), this);
    goal1->setPosition(visibleSize.width+10, visibleSize.height/2);
    goal1->setTag(0);
    goal1->setName("Goal");
    this->addChild(goal1);
    
    // Score labels
    auto font = TTFConfig();
    font.fontFilePath = "fonts/Cave-Story.ttf";
    font.fontSize = 150;
    
    _p0_score_label = Label::createWithTTF(font, "0", TextHAlignment::RIGHT);
    _p0_score_label->setAnchorPoint(Vec2(1, 1));
    _p0_score_label->setPosition(visibleSize.width/2-50, visibleSize.height-10);
    this->addChild(_p0_score_label);
    
    auto dash_label = Label::createWithTTF(font, "-");
    dash_label->setAnchorPoint(Vec2(0.5, 1));
    dash_label->setPosition(visibleSize.width/2, visibleSize.height-10);
    this->addChild(dash_label);
    
    _p1_score_label = Label::createWithTTF(font, "0", TextHAlignment::LEFT);
    _p1_score_label->setAnchorPoint(Vec2(0, 1));
    _p1_score_label->setPosition(visibleSize.width/2+50, visibleSize.height-10);
    this->addChild(_p1_score_label);
    
    // Game won items
    auto winning_font = TTFConfig();
    winning_font.fontFilePath = "fonts/Cave-Story.ttf";
    winning_font.fontSize = 100;
    _player_won_label = Label::createWithTTF(winning_font, "One of you wins!", TextHAlignment::CENTER);
    _player_won_label->setPosition(visibleSize.width/2, visibleSize.height/2+140);
    this->addChild(_player_won_label);
    auto new_game_font = TTFConfig();
    new_game_font.fontFilePath = "fonts/Cave-Story.ttf";
    new_game_font.fontSize = 75;
    _new_game_button = Label::createWithTTF(new_game_font, "New Game", TextHAlignment::CENTER);
    _new_game_button->setPosition(visibleSize.width/2, visibleSize.height/2+80);
    this->addChild(_new_game_button);
    auto click_listener = EventListenerMouse::create();
    click_listener->onMouseUp = CC_CALLBACK_1(Game::onMouseUp, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(click_listener, this);
    
    setControls(0, _p0_controls);
    setControls(1, _p1_controls);
    
    this->scheduleUpdate();
    newGame();
    
    return true;
}

void Game::addEvents()
{
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(Game::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Game::onKeyReleased(EventKeyboard::KeyCode key, const Event *event)
{
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        Game::setGameState(GameState::Pause);
        Director::getInstance()->pushScene(Pong::MainMenu::createScene());
    }
}

void Game::onMouseUp(Event *event)
{
    auto e = dynamic_cast<EventMouse*>(event);
    if (ClickedMe(e, dynamic_cast<Node*>(_new_game_button)) && _new_game_button->isVisible())
    {
        this->newGame();
    }
}

void Game::increaseScore(int player)
{
    if (player == 0)
    {
        _p0_score++;
        _p0_score_label->setString(std::to_string(_p0_score));
    }
    else if (player == 1)
    {
        _p1_score++;
        _p1_score_label->setString(std::to_string(_p1_score));
    }
    
    resetTimer();
    resetBall();
    Game::_game_state = GameState::Reset;
    
    if (_p0_score == this->winning_score)
    {
        this->wonGame(0);
    }
    else if (_p1_score == this->winning_score)
    {
        this->wonGame(1);
    }
}

void Game::newGame()
{
    _player_won_label->setVisible(false);
    _new_game_button->setVisible(false);
    resetTimer();
    resetScore();
    resetBall();
    Game::_game_state = GameState::Reset;
}

void Game::resetBall()
{
    _ball->reset();
}

void Game::resetPaddles()
{
    _p0_paddle->reset();
    _p1_paddle->reset();
}

void Game::resetScore()
{
    _p0_score = 0;
    _p1_score = 0;
    _p0_score_label->setString("0");
    _p1_score_label->setString("0");
}

void Game::resetTimer()
{
    this->_reset_timer = 3;
}

void Game::wonGame(int player)
{
    Game::_game_state = GameState::Pause;
    _player_won_label->setString("Player " + std::to_string(player+1) + " won!");
    _player_won_label->setVisible(true);
    _new_game_button->setVisible(true);
}

Controls Game::getControls(int player)
{
    if (player == 0)
    {
        return Game::_p0_controls;
    }
    else
    {
        return Game::_p1_controls;
    }
}

void Game::setControls(int player, Controls controls)
{
    if (player == 0)
    {
        Game::_p0_controls = controls;
        if (Game::_instance)
        {
            Game::_instance->_p0_paddle->setControls(controls.up, controls.down);
        }
    }
    else
    {
        Game::_p1_controls = controls;
        if (Game::_instance)
        {
            Game::_instance->_p1_paddle->setControls(controls.up, controls.down);
        }
    }
}

void Game::update(float dt)
{
    if (Game::_game_state == GameState::Reset)
    {
        if (_reset_timer > 0)
        {
            _reset_timer -= dt;
        }
        else
        {
            Game::_game_state = GameState::Play;
        }
    }
}