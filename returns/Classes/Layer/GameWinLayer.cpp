//
//  StartGameLayer.cpp
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#include "GameWinLayer.h"
#include "VisibleRect.h"
#include "Constants.h"
#include "MainGameScene.h"
#include "StartGameScene.h"
#include "GameSingleton.h"

USING_NS_CC;
using namespace std;

static GameWinLayer *_functionAction = 0;

GameWinLayer* GameWinLayer::getInstance()
{
    return _functionAction;
}


GameWinLayer::GameWinLayer()
{
    _functionAction = this;
}
GameWinLayer::~GameWinLayer()
{
    
}
bool GameWinLayer::init()
{
    
    Label* lbReplay = Label::create();
    lbReplay->setString("Replay");
    lbReplay->setName("replay");
    lbReplay->setSystemFontSize(35);
    lbReplay->setPosition(VisibleRect::center() + Vec2(-100, 0));
    Label* lbNext = Label::create();
    lbNext->setString("Next Game");
    lbNext->setName("next");
    lbNext->setSystemFontSize(35);
    lbNext->setPosition(VisibleRect::center() + Vec2(100, 0));

    
    
    return true;
}

void GameWinLayer::onClickItem(Ref* ref){
    
    Label*lb = (Label*)ref;
    auto st = lb->getName();
    
    if(st == "replay"){//Start game
        auto scene = MainGameScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }else if(st == "next"){
        int lv =GameSingleton::getInstance()->getLevel() + 1;
        log("level " + lv);
        GameSingleton::getInstance()->setLevel(lv);
        auto scene = MainGameScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }
    
}



