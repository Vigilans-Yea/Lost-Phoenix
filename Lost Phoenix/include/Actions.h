#pragma once
#include <graphics.h>
#include "Resources.h"

// ǰ������
class Plane;
class Bullet;
class Action;

void updateNewAction(Action* newAction);

/// <summary>
/// ��ege������̳�����Action���࣬����ege�Դ���fps��д�ɡ����ڱ���һЩ�����Ķ�����ͬʱͨ������ + �ص�����ʵ���¼���������
/// </summary>
/// <seealso cref="T:egeControlBase"/>
class Action : public egeControlBase
{
public:
	CTL_PREINIT(Action, egeControlBase)
	{
		// do sth. before sub objects' construct function call
	} CTL_PREINITEND;
	
	/// <summary>
	/// ���๹�캯����
	/// </summary>
	/// <param name="endCallbackFunc"> ����ѡ����һ����������������ʱ���õĻص�����ָ�롣������ָ���򲻵��á�</param>
	/// <param name="parameter2"> ege����������д���Ĳ��������ÿգ���Ӱ��ʹ�á� </param>
	Action(void(*endCallbackFunc)() = nullptr, CTL_DEFPARAM) : CTL_INITBASE(egeControlBase), end(false), callback(endCallbackFunc)
	{
		CTL_INIT; // must be the first line
		directdraw(true);
		enable(false);
		updateNewAction(this);
	}
	
	/// <summary>
	/// �����������ڻص�����ָ�벻Ϊ��ʱ�����ûص�������
	/// </summary>
	virtual ~Action ( ) 
	{
		if (callback)
			callback( );
	}

	bool end; ///< ���������Ƿ��ѵ������״̬������<see cref="World::actions"/>�б���Ⲣ����
	void(*callback)(); ///< �ص�����ָ�롣
};

/// <summary>
/// Action֮�ɻ���ը�����ڵл�������׹��ʱ���֣������Ի��������ܵ��˺���׹��ʱ���֡�
/// </summary>
/// <seealso cref="T:Action"/>
class Action_Plane_Explode : public Action
{
public:
	/// <summary>
	/// ��ʼ�����ֱ�ը�����Ĳ����顣��ȡLazy Load���ơ�
	/// </summary>
	static void initializeModels( );
	
	/// <summary>
	/// ���캯����
	/// </summary>
	/// <param name="src"> ��ըԴ�ɻ��� </param>
	/// <param name="doDestroy">	 (��ѡ) �Ƿ�����Դ�ɻ���Ĭ��Ϊtrue�� </param>
	/// <param name="boomSpeed">	 ��ը����ÿһ֡չ��ʱ�䡣 </param>
	/// <param name="endCallbackFunc"> �ص�����ָ�롣 </param>
	Action_Plane_Explode(Plane* src, bool doDestroy = true, int boomSpeed = 5, void(*endCallbackFunc)() = NULL);
	virtual ~Action_Plane_Explode( ); ///< ������������<see cref="toDestroy"/>Ϊtrue��������Դ�ɻ���

	virtual int onUpdate( ); ///< ���±�ը״̬����Ҫ�Ǹ��±�ը֡���Լ�ȷ�������Ƿ��ѽ�����
	virtual void onDraw(PIMAGE pimg) const; ///< ���Ʊ�ը֡�������ñ�ը��ͼ��������ɻ���ͼ�������غϡ�

public:
	static Texture models[4]; ///< ���ڱ��ֱ�ը�����Ĳ����顣
	int boomTime; ///< ��ը����ÿһ֡չ��ʱ�䡣
	int curIndex; ///< Ŀǰ�����ı�ը������������������
	Plane* srcPlane; ///< ��ըԴ�ɻ���
	bool toDestroy; ///< ��ʾ�Ƿ�Ҫ���ٱ�ըԴ�ɻ���
};

