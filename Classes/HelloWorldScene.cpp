#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "WorldMap.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (Map[i][j] == '#')
			{
			auto sprite = Sprite::create("IndestructibleWall.png");
			sprite->setAnchorPoint(Vec2(0, 0));
			sprite->setScale(1.6);
			sprite->setPosition(Vec2(j * 10, i * 10));
			this->addChild(sprite);
			}
			else if (Map[i][j] == '1')
			{
			auto sprite = Sprite::create("Wall.png");
			sprite->setAnchorPoint(Vec2(0, 0));
			sprite->setScale(1.6);
			sprite->setPosition(Vec2(j * 10, i * 10));
			this->addChild(sprite);
			}
			else if (Map[i][j] == '2')
			{
			auto sprite = Sprite::create("Water.png");
			sprite->setAnchorPoint(Vec2(0, 0));
			sprite->setScale(1.6);
			sprite->setPosition(Vec2(j * 10, i * 10));
			this->addChild(sprite);
			}
			else if (Map[i][j] == '3')
			{
			auto sprite = Sprite::create("Bridge.png");
			sprite->setAnchorPoint(Vec2(0, 0));
			sprite->setScale(1.6);
			sprite->setPosition(Vec2(j * 10, i * 10));
			this->addChild(sprite);
			}
			else if (i < 50 && j < 50 && Map[i][j] == '*'&&Map[i + 1][j + 1] != '*'&&Map[i][j + 1] != '*'&&Map[i + 1][j] != '*')
			{
			auto sprite = Sprite::create("InvadersBase.png");
			sprite->setAnchorPoint(Vec2(0, 0));
			sprite->setScale(1.6);
			sprite->setPosition(Vec2((j - 1) * 10, (i - 1) * 10));
			this->addChild(sprite);
			}
			else if (i < 50 && j < 50 && Map[i][j] == '*'&&Map[i + 1][j + 1] != '*'&&Map[i][j + 1] != '*'&&Map[i + 1][j] != '*')
			{
			auto sprite = Sprite::create("InvadersBase.png");
			sprite->setAnchorPoint(Vec2(0, 0));
			sprite->setScale(1.6);
			sprite->setPosition(Vec2((j-1) * 10, (i-1) * 10));
			this->addChild(sprite);
			}
		}
	}

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
