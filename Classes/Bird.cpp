#include "Bird.h"
#include "Definitions.h"

USING_NS_CC;

Bird::Bird( cocos2d::Layer *layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    flappyBird = Sprite::create( "res/bat.png",Rect(0,0,28,28));

    Vector<SpriteFrame*> animFrames(4);

     for(int i = 0; i < 4; i++)
     {
         auto frame = SpriteFrame::create("res/bat.png",Rect(28*i,0,28,28)); //we assume that the sprites' dimentions are 40*40 rectangles.
         animFrames.pushBack(frame);
     }
      auto animation = Animation::createWithSpriteFrames(animFrames,0.2f);
      auto animate = Animate::create(animation);
      flappyBird->runAction(RepeatForever::create(animate));


      flappyBird->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );


    
    auto flappyBody = PhysicsBody::createCircle( flappyBird->getContentSize( ).width / 2 );
    flappyBody->setCollisionBitmask( BIRD_COLLISION_BITMASK );
    flappyBody->setContactTestBitmask( true );
    
    flappyBird->setPhysicsBody( flappyBody );








    
    layer->addChild( flappyBird, 100 );



    isFalling = true;







}

void Bird::Fall( )
{
    if ( true == isFalling )
    {
        flappyBird->setPositionX( visibleSize.width / 2 + origin.x );
        flappyBird->setPositionY( flappyBird->getPositionY() - ( BIRD_FALLING_SPEED * visibleSize.height ) );




    }
    else
    {
        flappyBird->setPositionX( visibleSize.width / 2 + origin.x );
        flappyBird->setPositionY( flappyBird->getPositionY() + ( BIRD_FALLING_SPEED * visibleSize.height ) );

    }
}




