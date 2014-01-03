#ifndef __GameScene_SCENE_H__
#define __GameScene_SCENE_H__

#include "cocos2d.h"
#include "CCMenuItemCard.h"
class GameScene : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	//�Ƿ�ѡ����
	static bool  cardIsChosed(CCObject* pcard);
	// implement the "static node()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __GameScene_SCENE_H__
