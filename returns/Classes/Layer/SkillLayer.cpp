//
//  SkillLayer.cpp
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#include "SkillLayer.h"
#include "MainGameScene.h"
#include "TileMap.h"
#include "VisibleRect.h"
#include "Constants.h"

USING_NS_CC;

using namespace std;

static SkillLayer *_functionAction = 0;

SkillLayer* SkillLayer::getInstance()
{
    return _functionAction;
}


SkillLayer::SkillLayer()
{
    _functionAction = this;

}
SkillLayer::~SkillLayer()
{
    
}
bool SkillLayer::init()
{
    
    Label* lbleft = Label::create();
    lbleft->setString(StringUtils::format("Left  %d",TileMap::getInstance()->getTotalLeft()));
    lbleft->setName("left");
    lbleft->setSystemFontSize(35);
    lbleft->setPosition(VisibleRect::rightBottom() + Vec2(-80, 20));
    this->addChild(lbleft);
    
    Label* lbright = Label::create();
    lbright->setString(StringUtils::format("Right  %d",TileMap::getInstance()->getTotalRight()));
    lbright->setName("right");
    lbright->setSystemFontSize(35);
    lbright->setPosition(VisibleRect::rightBottom() + Vec2(-80, 100));
    this->addChild(lbright);
    
    Label* lbtop = Label::create();
    lbtop->setString(StringUtils::format("Top  %d",TileMap::getInstance()->getTotalTop()));
    lbtop->setName("top");
    lbtop->setSystemFontSize(35);
    lbtop->setPosition(VisibleRect::rightBottom() + Vec2(-80, 200));
    this->addChild(lbtop);
    
    Label* lbbot = Label::create();
    lbbot->setString(StringUtils::format("Bot  %d",TileMap::getInstance()->getTotalBot()));
    lbbot->setName("bot");
    lbbot->setSystemFontSize(35);
    lbbot->setPosition(VisibleRect::rightBottom() + Vec2(-80, 300));
    this->addChild(lbbot);
    
    Label* lbSprings = Label::create();
    lbSprings->setString(StringUtils::format("Springs  %d",TileMap::getInstance()->getTotalSprings()));
    lbSprings->setName("springs");
    lbSprings->setSystemFontSize(35);
    lbSprings->setPosition(VisibleRect::rightBottom() + Vec2(-80, 380));
    this->addChild(lbSprings);
    
    Label* lbstart = Label::create();
    lbstart->setString("start");
    lbstart->setName("start");
    lbstart->setSystemFontSize(35);
    lbstart->setPosition(VisibleRect::rightBottom() + Vec2(-80, 460));
    this->addChild(lbstart);
    
    Label* lbremove = Label::create();
    lbremove->setString("remove");
    lbremove->setName("remove");
    lbremove->setSystemFontSize(35);
    lbremove->setPosition(VisibleRect::rightBottom() + Vec2(-80, 540));
    this->addChild(lbremove);
    
    Label* lbformatkey = Label::create();
    lbformatkey->setString(StringUtils::format("F_K %d - %d ",TileMap::getInstance()->getTotalStar(), TileMap::getInstance()->getTotalKey()));
    lbformatkey->setName("formatkey");
    lbformatkey->setSystemFontSize(35);
    lbformatkey->setPosition(VisibleRect::rightBottom() + Vec2(-80, 600));
    this->addChild(lbformatkey);
    
    // Enable touches
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
    return true;
}

bool SkillLayer::onTouchBegan (cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto st =  event->getCurrentTarget()->getName();
    
    if(this->getChildByName("left")->getBoundingBox().containsPoint(touch->getLocation())){
        log("left");
        onClickItem("left");
    }else if(this->getChildByName("right")->getBoundingBox().containsPoint(touch->getLocation())){
        log("right");
        onClickItem("right");
    }else if(this->getChildByName("top")->getBoundingBox().containsPoint(touch->getLocation())){
        log("top");
        onClickItem("top");
    }else if(this->getChildByName("bot")->getBoundingBox().containsPoint(touch->getLocation())){
        log("bot");
        onClickItem("bot");
    }else if(this->getChildByName("springs")->getBoundingBox().containsPoint(touch->getLocation())){
        log("springs");
        onClickItem("springs");
    }else if(this->getChildByName("remove")->getBoundingBox().containsPoint(touch->getLocation())){
        log("remove");
        onClickItem("remove");
    }else if(this->getChildByName("start")->getBoundingBox().containsPoint(touch->getLocation())){
        log("start");
        onClickItem("start");
    }
    
    return true;
}

void SkillLayer::updateFun(){
    Label* lbleft = (Label*)this->getChildByName("left");
    lbleft->setString(StringUtils::format("Left  %d",TileMap::getInstance()->getTotalLeft()));
    
    Label* lbright = (Label*)this->getChildByName("right");
    lbright->setString(StringUtils::format("Right  %d",TileMap::getInstance()->getTotalRight()));
    
    Label* lbtop = (Label*)this->getChildByName("top");
    lbtop->setString(StringUtils::format("Top  %d",TileMap::getInstance()->getTotalTop()));

    Label* lbbot = (Label*)this->getChildByName("bot");
    lbbot->setString(StringUtils::format("Bot  %d",TileMap::getInstance()->getTotalBot()));
    
    Label* lbsprings = (Label*)this->getChildByName("springs");
    lbsprings->setString(StringUtils::format("Springs  %d",TileMap::getInstance()->getTotalSprings()));
    
    Label* lbformatkey = (Label*)this->getChildByName("formatkey");
    lbformatkey->setString(StringUtils::format("F_K %d - %d ",TileMap::getInstance()->getTotalStar() - TileMap::getInstance()->getCurrenStar(), TileMap::getInstance()->getTotalKey() - TileMap::getInstance()->getCurrenKey()));
    
}

void SkillLayer::onClickItem(std::string key){

    auto st = key;
    _dir = -1;
    if(st == "left" && TileMap::getInstance()->getTotalLeft() > 0){
        _dir = IDTILE::TILE_LEFT;
    }else if(st == "right" && TileMap::getInstance()->getTotalRight() > 0){
        _dir = IDTILE::TILE_RIGHT;
    }else if (st == "top" && TileMap::getInstance()->getTotalTop() > 0){
        _dir = IDTILE::TILE_TOP;
    }else if(st == "bot" && TileMap::getInstance()->getTotalBot() > 0){
        _dir = IDTILE::TILE_BOT;
    }else if(st == "start"){
        _dir = IDTILE::TILE_START;
        MainGameScene::getInstance()->getMainChar()->setStateChar(stateRun);
    }else if(st == "remove"){
        _dir = IDTILE::TILE_REMOVE;
    }else if(st == "springs" && TileMap::getInstance()->getTotalSprings() > 0){
        _dir = IDTILE::TILE_SPRINGS;
    }
    updateFun();
}



