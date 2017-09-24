/*! \file Player.h
	\brief ������ҵķɻ����ӵ��ࡣ
*/

#pragma once
#include "Plane - Bullet.h"

/// <summary>
/// ��ҷɻ���
/// </summary>
/// <seealso cref="T:Plane"/>
class Plane_Player : public Plane
{
public:
	/// <summary>
	/// Ψһ���캯����
	/// </summary>
	/// <param name="setting"> �ɻ������á��Ժ�ɸĳ�`Settings::Player`�� </param>
	Plane_Player(Settings::Plane setting);
	
	virtual void update( ); ///< ����״̬����Ҫ�Ǹ��¼������롣���ɻ��Ѳ����ڴ��״̬�������κζ�����
	//virtual void draw( );
	virtual void shoot( ); ///< ���������һ��<see cref="Bullet_Player"/>��
	virtual void takeDamage(int damage); ///< �е��˺������ɻ��Դ������һ��<see cref="Action_Plane_Explode"/>��

private:
	void handleInput( ); ///< ����������룬���·ɻ�״̬��
};

/// <summary>
/// ��ҷɻ������ӵ���
/// </summary>
/// <seealso cref="T:Bullet"/>
class Bullet_Player : public Bullet
{
public:
	/// <summary>
	/// Ψһ���캯����
	/// </summary>
	/// <param name="src"> ���Դ��һ��Ϊ��ҷɻ��� </param>
	/// <param name="setting">  �ӵ����á� </param>
	/// <param name="velocity"> �ӵ��ٶȡ� </param>
	Bullet_Player(Entity* src, Settings::Bullet setting, Vector2D velocity = Vector2D());
};