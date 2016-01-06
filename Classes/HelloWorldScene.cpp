#include "HelloWorldScene.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/spritesheet.plist");
    auto offset = SpriteFrameCache::getInstance()->getSpriteFrameByName("font.png")->getRectInPixels().origin;

    // GL calls: 20 - could be 1?
    for (int i = 0; i < 10; ++i)
    {
        auto label = Label::createWithBMFont("res/spritesheet.fnt", "Cocos rules!", TextHAlignment::LEFT, 0, offset);
        label->setPosition(origin + Vec2(i*10, i*20));
        addChild(label);

        auto logo = Sprite::createWithSpriteFrameName("logo.png");
        logo->setPosition(origin + visibleSize/2 + Vec2(i*10, i*20));
        addChild(logo);
    }
    
    /* dumps:
     "/cc_2x2_white_image" rc=12 id=2 2 x 2 @ 32 bpp => 0 KB
     "/[...]/Resources/res/spritesheet.png" rc=14 id=1 252 x 452 @ 32 bpp => 444 KB
     TextureCache dumpDebugInfo: 2 textures, for 444 KB (0.43 MB)
    */
    log("%s", Director::getInstance()->getTextureCache()->getCachedTextureInfo().c_str());

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
