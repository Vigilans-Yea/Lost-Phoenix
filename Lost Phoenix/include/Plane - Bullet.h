/*! \file "Plane - Bullet.h"
	\brief ����ɻ����ӵ��Ļ��࣬�Լ�����"dealDamage"���ӵ�->�ɻ����Ի�->�л���ȫ�ֺ�����
*/

#pragma once
#include "Entity.h"

/// <summary>
/// �ɻ��Ļ��ࡣ
/// </summary>
/// <seealso cref="T:Entity"/>
class Plane : public Entity
{
public:
	enum class State
	{
		Alive,
		Dead,
		Vanished,
		Invincible
	};

	Plane(Settings::Plane setting, Vector2D position, Vector2D velocity);
	~Plane( );

	virtual void update( );
	virtual void draw( );
	virtual void shoot( ) = 0;
	virtual void takeDamage(int damage);

	Plane::State getState( ) { return state; }
	void setState(Plane::State new_state) { state = new_state; }

	int getHealth( ) { return curHealth; }
	void setHealth(int hp) { curHealth = hp; }

	int speed;
	int maxHealth;
	int curHealth;
	time_t shootCoolDown;

protected:
	bool checkShootCoolDown( );

	time_t shootCheckPoint;
	Plane::State state;
};

/// <summary>
/// �ӵ��Ļ��ࡣ
/// </summary>
/// <seealso cref="T:Entity"/>
class Bullet : public Entity
{
public:
	/// <summary>
	/// Ψһ���캯����
	/// </summary>
	/// <param name="src">	    �ӵ��Ĳ���Դ�������Ƿɻ����������Ҳ�������ӵ�������������֮�ࣩ </param>
	/// <param name="setting">  �ӵ����������á� </param>
	/// <param name="velocity"> (��ѡ)�ӵ����ٶȡ��������Ƿ�����Ҫ�ڱ𴦳�ʼ��������� </param>
	Bullet(Entity* src, Settings::Bullet setting, Vector2D velocity = Vector2D( ));

	virtual void update( ); ///< �����ӵ�״̬��
	
	int speed; ///< �ӵ����ƶ����ʡ�
	int attack; ///< �ӵ����˺���
	bool end; ///< �����ӵ��Ƿ��Ѵﵽ����״̬�� TODO: ��Bullet::Stateȡ��bool����������Not Hit, Hit��Vanished״̬��

private:
	Vector2D initPosBySource(Entity* p); ///< ���ӵ���λ������ΪԴ�ɻ����Ϸ���
};

class Plane_Player;

void dealDamage(Plane* plane, Bullet* bullet); ///< �ӵ���ɻ�����ʱ���˺�����
void dealDamage(Plane_Player* player, Plane* enemy); ///< �Ի���л�����ʱ���˺�����
