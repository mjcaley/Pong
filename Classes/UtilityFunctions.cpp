//
//  UtilityFunctions.cpp
//  Pong
//
//  Created by Michael Caley on 2015-03-25.
//
//

#include "UtilityFunctions.h"

#include "cocos2d.h"

USING_NS_CC;


std::string KeyCodeToString(EventKeyboard::KeyCode keyCode)
{
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_PAUSE:
            return "Pause";
        case EventKeyboard::KeyCode::KEY_SCROLL_LOCK:
            return "Scroll Lock";
        case EventKeyboard::KeyCode::KEY_PRINT:
            return "Print Screen";
        case EventKeyboard::KeyCode::KEY_SYSREQ:
            return "SysRq";
        case EventKeyboard::KeyCode::KEY_BREAK:
            return "Break";
        case EventKeyboard::KeyCode::KEY_ESCAPE:
            return "Esc";
        case EventKeyboard::KeyCode::KEY_BACKSPACE:
            return "Backspace";
        case EventKeyboard::KeyCode::KEY_TAB:
            return "Tab";
        case EventKeyboard::KeyCode::KEY_BACK_TAB:
            return "Back Tab";
        case EventKeyboard::KeyCode::KEY_RETURN:
            return "Return";
        case EventKeyboard::KeyCode::KEY_CAPS_LOCK:
            return "Caps Lock";
        case EventKeyboard::KeyCode::KEY_LEFT_SHIFT:
            return "Left Shift";
        case EventKeyboard::KeyCode::KEY_RIGHT_SHIFT:
            return "Right Shift";
        case EventKeyboard::KeyCode::KEY_LEFT_CTRL:
            return "Left Ctrl";
        case EventKeyboard::KeyCode::KEY_RIGHT_CTRL:
            return "Right Ctrl";
        case EventKeyboard::KeyCode::KEY_LEFT_ALT:
            return "Left Alt";
        case EventKeyboard::KeyCode::KEY_RIGHT_ALT:
            return "Right Alt";
        case EventKeyboard::KeyCode::KEY_MENU:
            return "Menu";
        case EventKeyboard::KeyCode::KEY_HYPER:
            return "Hyper";
        case EventKeyboard::KeyCode::KEY_INSERT:
            return "Insert";
        case EventKeyboard::KeyCode::KEY_HOME:
            return "Home";
        case EventKeyboard::KeyCode::KEY_PG_UP:
            return "Page Up";
        case EventKeyboard::KeyCode::KEY_DELETE:
            return "Delete";
        case EventKeyboard::KeyCode::KEY_END:
            return "End";
        case EventKeyboard::KeyCode::KEY_PG_DOWN:
            return "Page Down";
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            return "Left Arrow";
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            return "Right Arrow";
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            return "Up Arrow";
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            return "Down Arrow";
        case EventKeyboard::KeyCode::KEY_NUM_LOCK:
            return "Num Lock";
        case EventKeyboard::KeyCode::KEY_KP_PLUS:
            return "Num Plus";
        case EventKeyboard::KeyCode::KEY_KP_MINUS:
            return "Num Minus";
        case EventKeyboard::KeyCode::KEY_KP_MULTIPLY:
            return "Num Mutiply";
        case EventKeyboard::KeyCode::KEY_KP_DIVIDE:
            return "Num Divide";
        case EventKeyboard::KeyCode::KEY_KP_ENTER:
            return "Num Enter";
        case EventKeyboard::KeyCode::KEY_KP_HOME:
            return "Num Home";
        case EventKeyboard::KeyCode::KEY_KP_UP:
            return "Num Up";
        case EventKeyboard::KeyCode::KEY_KP_PG_UP:
            return "Num Page Up";
        case EventKeyboard::KeyCode::KEY_KP_LEFT:
            return "Num Left";
        case EventKeyboard::KeyCode::KEY_KP_FIVE:
            return "Num Five";
        case EventKeyboard::KeyCode::KEY_KP_RIGHT:
            return "Num Right";
        case EventKeyboard::KeyCode::KEY_KP_END:
            return "Num End";
        case EventKeyboard::KeyCode::KEY_KP_DOWN:
            return "Num Down";
        case EventKeyboard::KeyCode::KEY_KP_PG_DOWN:
            return "Num Page Down";
        case EventKeyboard::KeyCode::KEY_KP_INSERT:
            return "Num Insert";
        case EventKeyboard::KeyCode::KEY_KP_DELETE:
            return "Num Delete";
        case EventKeyboard::KeyCode::KEY_F1:
            return "F1";
        case EventKeyboard::KeyCode::KEY_F2:
            return "F2";
        case EventKeyboard::KeyCode::KEY_F3:
            return "F3";
        case EventKeyboard::KeyCode::KEY_F4:
            return "F4";
        case EventKeyboard::KeyCode::KEY_F5:
            return "F5";
        case EventKeyboard::KeyCode::KEY_F6:
            return "F6";
        case EventKeyboard::KeyCode::KEY_F7:
            return "F7";
        case EventKeyboard::KeyCode::KEY_F8:
            return "F8";
        case EventKeyboard::KeyCode::KEY_F9:
            return "F9";
        case EventKeyboard::KeyCode::KEY_F10:
            return "F10";
        case EventKeyboard::KeyCode::KEY_F11:
            return "F11";
        case EventKeyboard::KeyCode::KEY_F12:
            return "F12";
        case EventKeyboard::KeyCode::KEY_SPACE:
            return "Space";
        case EventKeyboard::KeyCode::KEY_EXCLAM:
            return "!";
        case EventKeyboard::KeyCode::KEY_QUOTE:
            return "\"";
        case EventKeyboard::KeyCode::KEY_NUMBER:
            return "#";
        case EventKeyboard::KeyCode::KEY_DOLLAR:
            return "$";
        case EventKeyboard::KeyCode::KEY_PERCENT:
            return "%";
        case EventKeyboard::KeyCode::KEY_CIRCUMFLEX:
            return "^";
        case EventKeyboard::KeyCode::KEY_AMPERSAND:
            return "&";
        case EventKeyboard::KeyCode::KEY_APOSTROPHE:
            return "'";
        case EventKeyboard::KeyCode::KEY_LEFT_PARENTHESIS:
            return "(";
        case EventKeyboard::KeyCode::KEY_RIGHT_PARENTHESIS:
            return ")";
        case EventKeyboard::KeyCode::KEY_ASTERISK:
            return "*";
        case EventKeyboard::KeyCode::KEY_PLUS:
            return "+";
        case EventKeyboard::KeyCode::KEY_COMMA:
            return ",";
        case EventKeyboard::KeyCode::KEY_MINUS:
            return "-";
        case EventKeyboard::KeyCode::KEY_PERIOD:
            return ".";
        case EventKeyboard::KeyCode::KEY_SLASH:
            return "/";
        case EventKeyboard::KeyCode::KEY_0:
            return "0";
        case EventKeyboard::KeyCode::KEY_1:
            return "1";
        case EventKeyboard::KeyCode::KEY_2:
            return "2";
        case EventKeyboard::KeyCode::KEY_3:
            return "3";
        case EventKeyboard::KeyCode::KEY_4:
            return "4";
        case EventKeyboard::KeyCode::KEY_5:
            return "5";
        case EventKeyboard::KeyCode::KEY_6:
            return "6";
        case EventKeyboard::KeyCode::KEY_7:
            return "7";
        case EventKeyboard::KeyCode::KEY_8:
            return "8";
        case EventKeyboard::KeyCode::KEY_9:
            return "9";
        case EventKeyboard::KeyCode::KEY_COLON:
            return ":";
        case EventKeyboard::KeyCode::KEY_SEMICOLON:
            return ";";
        case EventKeyboard::KeyCode::KEY_LESS_THAN:
            return "<";
        case EventKeyboard::KeyCode::KEY_EQUAL:
            return "=";
        case EventKeyboard::KeyCode::KEY_GREATER_THAN:
            return ">";
        case EventKeyboard::KeyCode::KEY_QUESTION:
            return "?";
        case EventKeyboard::KeyCode::KEY_AT:
            return "@";
        case EventKeyboard::KeyCode::KEY_CAPITAL_A:
            return "A";
        case EventKeyboard::KeyCode::KEY_CAPITAL_B:
            return "B";
        case EventKeyboard::KeyCode::KEY_CAPITAL_C:
            return "C";
        case EventKeyboard::KeyCode::KEY_CAPITAL_D:
            return "D";
        case EventKeyboard::KeyCode::KEY_CAPITAL_E:
            return "E";
        case EventKeyboard::KeyCode::KEY_CAPITAL_F:
            return "F";
        case EventKeyboard::KeyCode::KEY_CAPITAL_G:
            return "G";
        case EventKeyboard::KeyCode::KEY_CAPITAL_H:
            return "H";
        case EventKeyboard::KeyCode::KEY_CAPITAL_I:
            return "I";
        case EventKeyboard::KeyCode::KEY_CAPITAL_J:
            return "J";
        case EventKeyboard::KeyCode::KEY_CAPITAL_K:
            return "K";
        case EventKeyboard::KeyCode::KEY_CAPITAL_L:
            return "L";
        case EventKeyboard::KeyCode::KEY_CAPITAL_M:
            return "M";
        case EventKeyboard::KeyCode::KEY_CAPITAL_N:
            return "N";
        case EventKeyboard::KeyCode::KEY_CAPITAL_O:
            return "O";
        case EventKeyboard::KeyCode::KEY_CAPITAL_P:
            return "P";
        case EventKeyboard::KeyCode::KEY_CAPITAL_Q:
            return "Q";
        case EventKeyboard::KeyCode::KEY_CAPITAL_R:
            return "R";
        case EventKeyboard::KeyCode::KEY_CAPITAL_S:
            return "S";
        case EventKeyboard::KeyCode::KEY_CAPITAL_T:
            return "T";
        case EventKeyboard::KeyCode::KEY_CAPITAL_U:
            return "U";
        case EventKeyboard::KeyCode::KEY_CAPITAL_V:
            return "V";
        case EventKeyboard::KeyCode::KEY_CAPITAL_W:
            return "W";
        case EventKeyboard::KeyCode::KEY_CAPITAL_X:
            return "X";
        case EventKeyboard::KeyCode::KEY_CAPITAL_Y:
            return "Y";
        case EventKeyboard::KeyCode::KEY_CAPITAL_Z:
            return "Z";
        case EventKeyboard::KeyCode::KEY_LEFT_BRACKET:
            return "[";
        case EventKeyboard::KeyCode::KEY_BACK_SLASH:
            return "\\";
        case EventKeyboard::KeyCode::KEY_RIGHT_BRACKET:
            return "]";
        case EventKeyboard::KeyCode::KEY_UNDERSCORE:
            return "_";
        case EventKeyboard::KeyCode::KEY_GRAVE:
            return "`";
        case EventKeyboard::KeyCode::KEY_A:
            return "a";
        case EventKeyboard::KeyCode::KEY_B:
            return "b";
        case EventKeyboard::KeyCode::KEY_C:
            return "c";
        case EventKeyboard::KeyCode::KEY_D:
            return "d";
        case EventKeyboard::KeyCode::KEY_E:
            return "e";
        case EventKeyboard::KeyCode::KEY_F:
            return "f";
        case EventKeyboard::KeyCode::KEY_G:
            return "g";
        case EventKeyboard::KeyCode::KEY_H:
            return "h";
        case EventKeyboard::KeyCode::KEY_I:
            return "i";
        case EventKeyboard::KeyCode::KEY_J:
            return "j";
        case EventKeyboard::KeyCode::KEY_K:
            return "k";
        case EventKeyboard::KeyCode::KEY_L:
            return "l";
        case EventKeyboard::KeyCode::KEY_M:
            return "m";
        case EventKeyboard::KeyCode::KEY_N:
            return "n";
        case EventKeyboard::KeyCode::KEY_O:
            return "o";
        case EventKeyboard::KeyCode::KEY_P:
            return "p";
        case EventKeyboard::KeyCode::KEY_Q:
            return "q";
        case EventKeyboard::KeyCode::KEY_R:
            return "r";
        case EventKeyboard::KeyCode::KEY_S:
            return "s";
        case EventKeyboard::KeyCode::KEY_T:
            return "t";
        case EventKeyboard::KeyCode::KEY_U:
            return "u";
        case EventKeyboard::KeyCode::KEY_V:
            return "v";
        case EventKeyboard::KeyCode::KEY_W:
            return "w";
        case EventKeyboard::KeyCode::KEY_X:
            return "x";
        case EventKeyboard::KeyCode::KEY_Y:
            return "y";
        case EventKeyboard::KeyCode::KEY_Z:
            return "z";
        case EventKeyboard::KeyCode::KEY_LEFT_BRACE:
            return "{";
        case EventKeyboard::KeyCode::KEY_BAR:
            return "|";
        case EventKeyboard::KeyCode::KEY_RIGHT_BRACE:
            return "}";
        case EventKeyboard::KeyCode::KEY_TILDE:
            return "~";
        case EventKeyboard::KeyCode::KEY_EURO:
            return "€";
        case EventKeyboard::KeyCode::KEY_POUND:
            return "£";
        case EventKeyboard::KeyCode::KEY_YEN:
            return "¥";
        case EventKeyboard::KeyCode::KEY_MIDDLE_DOT:
            return "·";
        case EventKeyboard::KeyCode::KEY_DPAD_LEFT:
            return "Left";
        case EventKeyboard::KeyCode::KEY_DPAD_RIGHT:
            return "Right";
        case EventKeyboard::KeyCode::KEY_DPAD_UP:
            return "Up";
        case EventKeyboard::KeyCode::KEY_DPAD_DOWN:
            return "Down";
        case EventKeyboard::KeyCode::KEY_DPAD_CENTER:
            return "Center";
        case EventKeyboard::KeyCode::KEY_ENTER:
            return "Enter";
        default:
            return "";
    }
}

bool ClickedMe(const EventMouse* event, const Node *node)
{
    auto rect = node->getBoundingBox();
    Vec2 click;
    if (std::string(cocos2dVersion()) == "cocos2d-x 3.5")
    {
        // Maybe a bug in cocos2d-x 3.4 - https://github.com/cocos2d/cocos2d-x/issues/8536
        auto dir = Director::getInstance();
        click = dir->convertToGL(Vec2(
                                      event->getLocation().x,
                                      event->getLocation().y - Director::getInstance()->getVisibleSize().height)
                                 );
    }
    else
    {
        click = event->getLocation();
    }
    
    return rect.containsPoint(click);
}