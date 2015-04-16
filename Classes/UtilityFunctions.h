//
//  UtilityFunctions.h
//  Pong
//
//  Created by Michael Caley on 2015-03-25.
//
//

#ifndef __Pong__UtilityFunctions__
#define __Pong__UtilityFunctions__

#include "cocos2d.h"


std::string KeyCodeToString(cocos2d::EventKeyboard::KeyCode keyCode);
bool ClickedMe(const cocos2d::EventMouse* event, const cocos2d::Node* node);

#endif /* defined(__Pong__UtilityFunctions__) */
