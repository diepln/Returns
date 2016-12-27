//
//  StartGameLayer.cpp
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#include "StartGameLayer.h"
#include "VisibleRect.h"
#include "Constants.h"
#include "MainGameScene.h"
#include "StartGameScene.h"
USING_NS_CC;

using namespace std;

static StartGameLayer *_functionAction = 0;

StartGameLayer* StartGameLayer::getInstance()
{
    return _functionAction;
}


StartGameLayer::StartGameLayer()
{
    _functionAction = this;
}
StartGameLayer::~StartGameLayer()
{
    
}
bool StartGameLayer::init()
{
    
    Label* lbStart = Label::create();
    lbStart->setString("Start Game");
    lbStart->setName("start");
    lbStart->setSystemFontSize(35);
    lbStart->setPosition(VisibleRect::center() + Vec2(0, 100));
    this->addChild(lbStart);
    
    Label* lbMenu = Label::create();
    lbMenu->setString("Menu Game");
    lbMenu->setName("menu");
    lbMenu->setSystemFontSize(35);
    lbMenu->setPosition(VisibleRect::center() + Vec2(0, 50));
    this->addChild(lbMenu);
    
    Label* lbOption = Label::create();
    lbOption->setString("Option");
    lbOption->setName("option");
    lbOption->setSystemFontSize(35);
    lbOption->setPosition(VisibleRect::center() + Vec2(0, 0));
    this->addChild(lbOption);
    
    Label* lbAbout = Label::create();
    lbAbout->setString("About");
    lbAbout->setName("about");
    lbAbout->setSystemFontSize(35);
    lbAbout->setPosition(VisibleRect::center() + Vec2(0, -50));
    this->addChild(lbAbout);
    
    Label* lbHelp = Label::create();
    lbHelp->setString("Help");
    lbHelp->setName("help");
    lbHelp->setSystemFontSize(35);
    lbHelp->setPosition(VisibleRect::center() + Vec2(0, -100));
    this->addChild(lbHelp);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
    
    return true;
}

bool StartGameLayer::onTouchBegan (cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto st =  event->getCurrentTarget()->getName();

    if(this->getChildByName("start")->getBoundingBox().containsPoint(touch->getLocation())){
        log("Start");
        auto scene = MainGameScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }
    return true;
}

void StartGameLayer::onClickItem(Ref* ref){
    
}



