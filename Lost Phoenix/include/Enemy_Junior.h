/*! \file Enemy_Junior.h	
	\brief �����±��л��ķɻ��༰�ӵ��ࡣ
*/

#pragma once
#include "Plane - Bullet.h"

/// <summary>
/// �±��л����ص�ΪѪ�٣��ӵ��˺��ͣ�·����һ���������Ļ�����ӵ��ٶȿ죬�������̡�
/// </summary>
/// <seealso cref="T:Plane"/>
class Plane_Enemy_Junior : public Plane
{
public:
	Plane_Enemy_Junior(Settings::Plane setting, Vector2D position, Vector2D velocity = Vector2D()); ///< �������캯����

	virtual void update() override; ///< ����״̬����ҪΪ�������������
	
	/// <summary>
	/// ����һ��������ߵȼ�ʱ�ӵ��ƶ��ٶȳ��ֱ仯��
	/// </summary>
	/// <remarks>
	/// ����<see cref="difficultyLevel"/>���ߣ���ʼ���ֳ���ͬ�����ԣ�
	/// * �Ѷȵȼ���2���Ϻ��ӵ����ٶȽ���һ������䶯����ʼΪ0.8~1.2��ԭ�ٶȡ������Ѷ�Խ��Խ�ߣ����佫���Խ��Խ��  
	/// * ��������ʹ��С�ɻ������һ���ӵ�����ʹ����ҷɻ�����ͨ�С�
	/// </remarks>
	virtual void shoot() override;

};

/// <summary>
/// �±��л��ӵ���
/// </summary>
/// <seealso cref="T:Bullet"/>
class Bullet_Enemy_Junior : public Bullet
{
public:
	Bullet_Enemy_Junior(Entity* src, Settings::Bullet setting, Vector2D velocity = Vector2D()); ///< �������캯����������ӵ����캯����ͬ��

};