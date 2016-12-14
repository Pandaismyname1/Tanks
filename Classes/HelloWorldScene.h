#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	char Map[50][51] =
	{
		"##################################################",
		"##################################################",
		"##11111111111111111##111**111##11111111111111111##",
		"##11111111111111111##111**111##11111111111111111##",
		"##11001111111111100##11111111##00111111111110011##",
		"##11001111111111100##11111111##00111111111110011##",
		"##11001111111000000##11111111##00000011111110011##",
		"##11001111111000000##11111111##00000011111110011##",
		"##0000000000000000000000$$0000000000000000000000##",
		"##0000000000000000000000$$0000000000000000000000##",
		"##11001111111001100##00000000##00110011111110011##",
		"##11001111111001100##00000000##00110011111110011##",
		"##11001100000001100############00110000000110011##",
		"##11001100000001100############00110000000110011##",
		"##1111111111111110000000000000000111111111111111##",
		"##1111111111111110000000000000000111111111111111##",
		"##1100000000000110011111001111100110000000000011##",
		"##1100000000000110011111001111100110000000000011##",
		"##1100110000000110011000000001100110000000110011##",
		"##1100110000000110011000000001100110000000110011##",
		"##1100110000000000011110000111100000000000110011##",
		"##1100110000000000011110000111100000000000110011##",
		"##2233222222222222222223333222222222222222223322##",
		"##2233222222222222222223333222222222222222223322##",
		"##1100111111111110011110000111100111111111110011##",
		"##1100111111111110011110000111100111111111110011##",
		"##1100000000011110011000000001100111100000000011##",
		"##1100000000011110011000000001100111100000000011##",
		"##110011111001111001100####001100111100111110011##",
		"##110011111000000000000####000000000000111110011##",
		"##110011111000000000000####000000000000111110011##",
		"##110011111001111001100####001100111100111110011##",
		"##1100111110011110011000000001100111100111110011##",
		"##1100111110011110011000000001100111100111110011##",
		"##1100111110000000011111001111100000000111110011##",
		"##1100111110000000011111001111100000000111110011##",
		"##11001111100111111#####00#####11111100111110011##",
		"##11001111100111111#####00#####11111100111110011##",
		"##11000000000000000##00000000##00000000000000011##",
		"##11000000000000000##00000000##00000000000000011##",
		"##1100011111111110000000^^0000000111111111100011##",
		"##1100011111111110000000^^0000000111111111100011##",
		"##11000000000000000##11111111##00000000000000011##",
		"##11000000000000000##11111111##00000000000000011##",
		"##11111111100111100##11111111##00111100111111111##",
		"##11111111100111100##11111111##00111100111111111##",
		"##11111111100111111##111%%111##00111100111111111##",
		"##11111111100111111##111%%111##00111100111111111##",
		"##################################################",
		"##################################################",
	};
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
