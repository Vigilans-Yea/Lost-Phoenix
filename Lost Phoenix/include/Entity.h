/*! \file Entity.h
	\brief ��������ʵ��Ļ��࣬�Լ�һ����Ӫ��ö�١�
*/

#pragma once
#include "Resources.h"

/// <summary>
/// ʵ�����Ӫö�١����������ɻ����ӵ��ĵ��ѹ�ϵ��
/// </summary>
enum class Camp
{
	Friend, /// �Ѿ���ֻ���Ի���������ӵ���
	Enemy /// �о�
};

/// <summary>
/// ��Ϸ������ʵ����ܻ��ࡣ
/// </summary>
class Entity
{
public:
	/// <summary>
	/// �ж�����ʵ���Ƿ�����ײ��
	/// </summary>
	/// <remarks>
	/// �������ô����ж����������Ƿ���ײ��һ�����鷳���¡���������һ����Ŀд�˺ܳ��Ĵ��뵫���������⡭����
	/// ���Ǻ����ҵ���һ���������ϸ����ѧ��������**�Ƚ������������ĵľ���ֵ��������γ���Ĺ�ϵ**��
	/// <seealso cref="http://blog.csdn.net/u011483306/article/details/45368367"/>
	/// </remarks>
	/// <param name="e1"> һ��ʵ���ָ�루�ǿգ���</param>
	/// <param name="e2"> ��һ��ʵ���ָ�루�ǿգ��� </param>
	/// <returns>
	/// * ���������ײ���򷵻�true��  
	/// * ���δ������ײ����һ����Ϊ�գ��򷵻�false��
	/// </returns>
	static bool judgeCollision(const Entity * e1, const Entity * e2);

	/// <summary>
	/// Ψһ���캯����
	/// </summary>
	/// <param name="texture">  ʵ��Ĳ��ʡ� </param>
	/// <param name="camp">	    ʵ���<see cref="Camp"/>����Ӫ���� </param>
	/// <param name="position"> ʵ���ڵ�ͼ�ϵ����ꡣ </param>
	/// <param name="velocity"> (��ѡ) ʵ����ٶ�ʸ����Ĭ��Ϊ0�� </param>
	Entity(Texture texture, Camp camp, Vector2D position, Vector2D velocity = Vector2D()) :
		model(texture), camp(camp), curPos(position), velocity(velocity) { }
	
	/// <summary>
	/// ������������������֤����������������
	/// </summary>
	virtual ~Entity() { }
	
	/// <summary>
	/// ����ʵ��״̬����Ϊ�����麯�����˷���ֻͨ���ٶȸ��µ�ǰλ�á�
	/// </summary>
	virtual void update();
	
	/// <summary>
	/// �ڵ�ͼ�ϻ���ʵ�塣ʹ����͸��ͨ������˿�����Ⱦ��͸�����ʡ�
	/// </summary>
	virtual void draw();

	/* -------------- get & set --------------*/
	int getXPos() const { return curPos.x; }
	int getYPos() const { return curPos.y; }
	void setXPos(int x) { curPos.x = x; }
	void setYPos(int y) { curPos.y = y; }

	int getXVel() const { return velocity.x; }
	int getYVel() const { return velocity.y; }
	void setXVel(int x) { velocity.x = x; }
	void setYVel(int y) { velocity.y = y; }

	int getXHitBox() const { return model.hitBox.x; }
	int getYHitBox() const { return model.hitBox.y; }

	Vector2D getPosition() const { return curPos; }
	Vector2D getVelocity() const { return velocity; }
	Vector2D getHitBox() const { return model.hitBox; }

	void setPosition(const Vector2D& pos) { curPos = pos; }
	void setVelocity(const Vector2D& vel) { velocity = vel; }

	Camp getCamp() const { return camp; }

protected:
	/// <summary>
	/// ʵ��Ĳ���ģ�͡�ͨ������ȡʵ���HitBox���ԡ�<seealso cref="Texture"/>
	/// </summary>
	Texture model;
	
	/// <summary>
	/// ʵ�嵱ǰ�ڵ�ͼ�ϵ�λ�á�
	/// </summary>
	Vector2D curPos;
	
	/// <summary>
	/// ʵ�嵱ǰ���ٶ�ʸ����
	/// </summary>
	Vector2D velocity;

	/// <summary>
	/// ʵ�嵱ǰ��<see cref="Camp"/>����Ӫ����
	/// </summary>
	Camp camp;
};

