#pragma once
#include <graphics.h>
#include "Resources.h"

// ǰ������
class Plane;
class Bullet;
class Action;

void updateNewAction(Action* newAction);

// Action���࣬����ege�Դ���fps��д�ɣ����ڽ���һЩ׼������
class Action : public egeControlBase
{
public:
	CTL_PREINIT(Action, egeControlBase)
	{
		// do sth. before sub objects' construct function call
	} CTL_PREINITEND;

	Action(void(*endCallbackFunc)() = NULL, CTL_DEFPARAM) : CTL_INITBASE(egeControlBase), end(false), callback(endCallbackFunc)
	{
		CTL_INIT; // must be the first line
		directdraw(true);
		enable(false);
		updateNewAction(this);
	}

	virtual ~Action ( ) 
	{
		if (callback)
			callback( );
	}

	bool end;
	void(*callback)();
};



class Action_Plane_Explode : public Action
{
public:
	static void initializeModels( );

	Action_Plane_Explode(Plane* src, bool doDestroy = true, int boomSpeed = 5, void(*endCallbackFunc)() = NULL);
	virtual ~Action_Plane_Explode( );

	virtual int onUpdate( );
	virtual void onDraw(PIMAGE pimg) const;

public:
	static Texture models[4];
	int boomTime;
	int curIndex;
	Plane* srcPlane;
	bool toDestroy;
};

