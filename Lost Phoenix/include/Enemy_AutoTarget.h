/*! \file Enemy_AutoTarget.h
	\brief �����Ի��ѵл��ķɻ��༰�ӵ��ࡣ
*/

#pragma once
#include "Plane - Bullet.h"

/// <summary>
/// �Ի��ѵл����ص���Ѫ�񣬲���ɳ���Ļ���ӵ�׷����ҷɻ����˺��ߣ����ӵ��ٶȽ���������������
/// </summary>
/// <seealso cref="T:Plane"/>
class Plane_Enemy_AutoTarget : public Plane
{
public:
	Plane_Enemy_AutoTarget(Settings::Plane setting, Vector2D position, Vector2D velocity = Vector2D()); ///< �������캯����

	virtual void update() override; ///< ����״̬����ҪΪ�������������
	
	/// <summary>
	/// ����һ����������ı������ٶȡ��ߵȼ�ʱ�ɻ��ƶ��ٶȳ��ֱ仯��
	/// </summary>
	/// <remarks>
	/// �Ի��ѷɻ��������������ٶȻ�ı䡣�������Ϊ��
	/// * y�����ٶ���-2.4 ~ 2.4֮�����һ��ֵ, ȡ������  
	/// * ��y�����ٶȾ���ֵ����2����ɻ���x�����ٶȷ���  
	/// * ���ɻ�����Ļ�°�������ɻ�����������ˡ��ҿ��ܾ��зǳ���ĺ����ٶȡ�
	/// 
	/// ����<see cref="difficultyLevel"/>���ߣ���ʼ���ֳ���ͬ�����ԣ�
	/// * �Ѷȵȼ���3���Ϻ�ÿ�����ʱ��x�᷽���ٶȶ��������Ĭ���ٶȣ���һ����������Ѷ�Խ�ߣ�����Խ��
	/// </remarks>
	virtual void shoot() override;
	
	/// <summary>
	/// �����˺����ߵȼ�ʱ���ָ�����ơ�
	/// </summary>
	/// <param name="damage"> �ܵ����˺��� </param>
	/// <remarks>
	/// ����<see cref="difficultyLevel"/>���ߣ���ʼ���ֳ���ͬ�����ԣ�
	/// * �Ѷȵȼ���5���Ϻ����ܵ��˺���δ׹�٣�����������һ�θ���������ô������Ӱ��֮ǰ�������ȴ��
	/// </remarks>
	virtual void takeDamage(int damage) override;

};

/// <summary>
/// �Ի��ѵл���׷���ӵ���
/// </summary>
/// <seealso cref="T:Bullet"/>
class Bullet_Enemy_AutoTarget : public Bullet
{
public:
	/// <summary>
	/// ���캯����
	/// </summary>
	/// <param name="src"> ���Դ </param>
	/// <param name="des"> ��׷�ٵķɻ���һ��Ϊ��ҷɻ��� </param>
	/// <param name="setting"> �ӵ����á� </param>
	Bullet_Enemy_AutoTarget(Entity* src, Plane* des, Settings::Bullet setting);
};