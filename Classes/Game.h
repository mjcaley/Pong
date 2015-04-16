//
//  Game.h
//  Pong
//
//  Created by Michael Caley on 2014-12-29.
//
//

#ifndef __Pong__Game__
#define __Pong__Game__

#include "cocos2d.h"


namespace Pong {
    class Ball;
    struct Controls;
    enum class GameState;
    class MainMenu;
    class Paddle;
    
    class Game : public cocos2d::Layer
    {
        friend class Pong::MainMenu;
    public:
        Game();
        ~Game();
        
        // there's no 'id' in cpp, so we recommend returning the class instance pointer
        static cocos2d::Scene* createScene();
        
        static Game* getGameInstance();
        static Pong::GameState getGameState() { return _game_state; };
        
        static Pong::Controls getControls(int player);
        static void setControls(int player, Pong::Controls controls);
        
        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual bool init();
        
        // implement the "static create()" method manually
        CREATE_FUNC(Game);
        
        void addEvents();
        void onKeyReleased(cocos2d::EventKeyboard::KeyCode key, const cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        
        void increaseScore(int player);
        
        void update(float dt);
        
    private:
        static Game *_instance;
        static Pong::GameState _game_state;
        
        float _reset_timer;
        
        int _p0_score = 0;
        int _p1_score = 0;
        int winning_score = 10;
        
        Pong::Ball *_ball;
        
        cocos2d::Label *_p0_score_label;
        cocos2d::Label *_p1_score_label;
        cocos2d::Label *_player_won_label;
        cocos2d::Label *_new_game_button;
        
        Pong::Paddle *_p0_paddle;
        Pong::Paddle *_p1_paddle;
        
        static Pong::Controls _p0_controls;
        static Pong::Controls _p1_controls;
        
        void newGame();
        void resetBall();
        void resetPaddles();
        void resetScore();
        void resetTimer();
        void wonGame(int player);
        
    protected:
        static void setGameState(Pong::GameState state) { _game_state = state; };
    };
}


#endif /* defined(__Pong__Game__) */
