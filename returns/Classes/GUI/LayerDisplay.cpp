//
//  LayerDisplay.cpp
//  gamebase
//
//  Created by NgocDiep on 5/12/15.
//
//

#include "LayerDisplay.h"
#include "VisibleRect.h"
USING_NS_CC;

/**
 * super
 */
LayerDisplay::LayerDisplay()
{
    touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(LayerDisplay::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(LayerDisplay::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(LayerDisplay::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(LayerDisplay::onTouchCancelled, this);

}

LayerDisplay::~LayerDisplay()
{
}

bool LayerDisplay::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    cocos2d::log("touch began");
    return true;
}

void LayerDisplay::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    cocos2d::log("touch ended");
}

void LayerDisplay::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    cocos2d::log("touch moved");
}

void LayerDisplay::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
    cocos2d::log("touch cancelled");
}

void LayerDisplay::setShow(bool show, int flag){
    this->setVisible(show);
}

void LayerDisplay::setPos(Vec2 pos, int flag){
    this->setPos(pos);
}
