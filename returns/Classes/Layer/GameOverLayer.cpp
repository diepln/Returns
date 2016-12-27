//
//  StartGameLayer.cpp
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#include "GameOverLayer.h"
#include "VisibleRect.h"
#include "Constants.h"
#include "MainGameScene.h"
#include "StartGameScene.h"
USING_NS_CC;
using namespace std;

static GameOverLayer *_functionAction = 0;

GameOverLayer* GameOverLayer::getInstance()
{
    return _functionAction;
}


GameOverLayer::GameOverLayer()
{
    _functionAction = this;
}
GameOverLayer::~GameOverLayer()
{
    
}
bool GameOverLayer::init()
{
    
    Label* lbStart = Label::create();
    lbStart->setString("Start Game");
    lbStart->setName("start");
    lbStart->setSystemFontSize(35);
    lbStart->setPosition(VisibleRect::center() + Vec2(0, 100));
    
    return true;
}

void GameOverLayer::onClickItem(Ref* ref){
    
//    Label*lb = (Label*)ref;
//    auto st = lb->getName();
//    
//    
//    if(st == "start"){//Start game
//        auto scene = MainGameScene::createScene();
//        Director::getInstance()->replaceScene(scene);
//    }else if(st == "menu"){
//        
//    }else if (st == "option"){
//        
//    }else if(st == "about"){
//        
//    }else if(st == "help"){
//        
//    }
    
}



