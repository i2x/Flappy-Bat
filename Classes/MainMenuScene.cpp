#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "fmod.hpp"




USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();




    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create( "res/Background.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y) );



    auto playItem = MenuItemImage::create("res/Play Button.png","res/Play Button Clicked.png",CC_CALLBACK_1(
         MainMenuScene::GoToGameScence,this));

    playItem->setPosition(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y);

    auto menu = Menu::create(playItem,NULL);
    menu->setPosition(Point::ZERO);



    this->addChild( backgroundSprite );
    this->addChild(menu);



    FMOD::System *system;
         FMOD::Sound *sound;
         FMOD::Channel *channel;
         FMOD_RESULT result;



    
    return true;
}

void MainMenuScene::GoToGameScence(cocos2d::Ref *sender)
{
    auto scene = GameScene::createScene();

    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );

}

