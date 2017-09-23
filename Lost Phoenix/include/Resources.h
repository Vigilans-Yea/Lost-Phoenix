#pragma once
#pragma warning(disable:4244) // disable double->int conversion warning
#include "Vector2D.hpp"

namespace ege
{
	class IMAGE;
	typedef IMAGE* PIMAGE;
};

/// <summary>
/// ����ͼ����ʵĽṹ�塣
/// </summary>
struct Texture
{
	ege::PIMAGE image; ///< �����ӦͼƬ��ͼ��ָ�롣
	Vector2D hitBox; ///< ����ͼƬ�����ľ���ʸ����
	
	/// <summary>
	/// ��֤����Ĭ�Ϲ��죬����Ϊ=default�Ĺ��캯����
	/// </summary>
	Texture() = default;
	
	/// <summary>
	/// ��֤Texture�ṹ���ܼ���ʹ��Aggregate Initialization�Ĺ��캯����
	/// </summary>
	Texture(ege::PIMAGE image, Vector2D hitBox) : image(image), hitBox(hitBox) { }
	
	/// <summary>
	/// �Ӳ���ID�����ҵ���Ӧ���ʵ���ʽת�����캯����
	/// </summary>
	/// <param name="id"> ���ʵ�Ψһ��ʶID�� </param>
	explicit Texture(int id);
};

/// <summary>
/// ����ID��ȡ���ʡ�����Lazy Load���ơ�
/// </summary>
/// <param name="id"> ���ʵ�Ψһ��ʶID�� </param>
/// <returns>
/// Ψһ��ʶID��Ӧ�Ĳ��ʡ�
/// </returns>
Texture getTexture(int id);

/// <summary>
/// �и���ʡ�
/// </summary>
/// <remarks>
/// �Ӳ������и�һ������Ӳ��ʡ�
/// 
/// ��׼��Ϊ�����Բ������Ͻ����ꡣ
/// </remarks>
/// <param name="texture"> ���и�Ĳ��ʡ� </param>
/// <param name="x">	 ���и���ʻ�׼��x���ꡣ </param>
/// <param name="y"> ���и���ʻ�׼��y���ꡣ </param>
/// <param name="w">	 ���и������Ŀ�ȡ� </param>
/// <param name="h">	 ���и������ĸ߶ȡ� </param>
/// <returns>
/// �и��Ĳ��ʡ�
/// </returns>
Texture splitTexture(Texture texture, int x, int y, int w, int h);

/// <summary>
/// �и���ʡ���װ��һ����������Vector2D�����ĸ����õĽӿڡ�
/// </summary>
/// <param name="texture"> ���и�Ĳ��ʡ� </param>
/// <param name="refPos">  ���и���ʻ�׼�㣨�������Ͻǣ����ꡣ </param>
/// <param name="hitBox">  ���и���εĳ���ʸ���� </param>
/// <returns>
/// �и��Ĳ��ʡ�
/// </returns>
inline Texture splitTexture(Texture texture, Vector2D refPos, Vector2D hitBox) { return splitTexture(texture, refPos.x, refPos.y, hitBox.x, hitBox.y); }

/// <summary>
/// ��װ����Ϸȫ��������ʵ�����õ����ռ䡣 ���л�ȡĬ�����õķ������� *Lazy Load����ʱ���أ�* ���ơ� **�Ƽ��ο���ϸ��������ȡ������Ϣ** ��
/// </summary>
/// <remarks>
/// ������ռ佫��Ϸ�����������ü���struct���б�ʾ������߿ɶ�������չ�ԡ�
/// 
/// ����Ĭ�����ñ�����json�ļ��У�������/settings�ļ����¡�
/// �������һ����ͷ�ļ��������ã�ʹ��json�Ŀɶ�����ṹ�Ը�ǿ��ͬʱ���޸������������ʱ��Ҳ����Ҫ **ȫ�����±���һ��** ��
/// 
/// ������Ϸ�󣬻�½����json�ļ��ж�ȡ������ã��ڶ�����һ��ר�ŵ��ڴ汣�档�������Ϊ��
/// * ����ʼ����ʱ����ȡ���в��ʵ�������Ϣ��<see cref="TextureInfo"/>��std::map�У�Ϊ�˺����õ�Lazy Load��׼����
/// * Setting���ռ����ṩ������ȡ**Ĭ����������**�ĺ�������ʱ��δ�����κ����á�  
/// * ���ⲿ�������һSetting���ռ�ĺ�������δ���أ���������õ����ϵ�һ���ȶ��ڴ������У����������á���������Ч����
///   - �������ö���ȡ��Lazy Load���ƣ����������egeͼ�ο�δ��ʼ������ǰ��ȡ���ʶ����bug��ͬʱ��ʡ�ڴ档  
///   - Ĭ������ʼ�շ��ض���һ���ȶ��ڴ�����ã��ﵽһ������ദʹ�õ�Ч����ͬʱ���ٿ�����
/// 
/// 
/// ---------
/// 
/// ���ڷɻ����ӵ�������ʵ�壬���û�����һ�����ã���һ��ʵ�����캯����ʹ�á�
/// ʵ������кܶ�����ԣ���ȫ�����ڹ��캯�����Ե�ʮ��ӷ�ף�ͬʱ��Ҫ����һ�����ԣ���Ҫ�޸ĺܶ�ط������׳���
/// 
/// ��ˣ��ɻ����ӵ��Ĺ��캯�����Ϊֻ��Ҫ��һ�� `����` ������ `��������Ϣ` ��ȥ���ɡ�
/// �ڴ�������ǰ�����Զ����õ�ʵ�������޸ģ��ﵽ�޸ķɻ��ӵ�������ݵ�Ч����
/// </remarks>
namespace Settings
{
	/// <summary>
	/// ��Ϸȫ�����ã���Ҫ����UI�����ʱ�����á�
	/// </summary>
	struct General
	{
		struct
		{
			char* title; ///< ��Ϸ���⡣
			int fps; ///< ��Ϸ��FPS��
			Vector2D resolution; ///< ��Ϸ���ڵķֱ��ʡ�
			int fontHeight; ///< UI������߶ȡ�
		} UI;

		struct
		{
			int enemyInfoDuration; ///< ��׷�ٵл���׷��״̬����ʱ�䡣
			int enemyWaveCoolDown; ///< �л�ÿһ��ˢ�µĻ�����ȴʱ�䡣
			int bgShiftSpeed; ///< �������ƶ��ٶȡ�
		} times;
	};
	/// <summary>
	/// ������Ϸ�����������á�
	/// </summary>
	struct BgTextures
	{
		Texture menu; ///< ���˵��������ʡ�
		Texture gaming; ///< ��ʽ��Ϸ�ڼ䱳�����ʡ�
		Texture gameOver; ///< ��Ϸ�����������ʡ�
	};
	
	/// <summary>
	/// ���ж�����<see cref="Action"/>��ز������á�
	/// </summary>
	struct AnimeTextures
	{
		Texture explosion; ///< ��ը��ͼ���ʡ�
	}; 
	
	/// <summary>
	/// �ӵ������û��ࡣ
	/// </summary>
	struct Bullet
	{
		Texture texture; ///< �ӵ����ʡ�
		int attack; ///< �ӵ���������
		int speed; ///< �ӵ��ƶ����ʣ��ٶȵ�ģ����
		int coolDown; ///< �ɻ������ȴ��
	};
	
	/// <summary>
	/// �ɻ������û��ࡣ
	/// </summary>
	struct Plane
	{
		int camp; ///< �ɻ�������Ӫ����Campö��һһ��Ӧ��
		Texture texture; ///< �ɻ����ʡ�
		int health; ///< �ɻ�HP���ޡ�
		int speed; ///< �ɻ��ƶ����ʣ��ٶȵ�ģ����
		Bullet bulletSetting; ///< �ɻ�Ĭ���ӵ����á�
		int score; ///< �ɻ�׹�ٷ�����
	};

	const Settings::General& general(); ///< ��ȡĬ�ϵ�ȫ����Ϸ���á���ȡLazy Load���ơ�
	const Settings::BgTextures& bgTextures(); ///< ��ȡĬ�ϵı����������á���ȡLazy Load���ơ�
	const Settings::AnimeTextures& animeTextures(); ///< ��ȡĬ�ϵĶ����������á���ȡLazy Load���ơ�
	const Settings::Plane& player( ); ///< ��ȡĬ�ϵ���ҷɻ����á���ȡLazy Load���ơ�
	const Settings::Plane& enemy_junior( ); ///< ��ȡĬ�ϵ��±��л����á���ȡLazy Load���ơ�
	const Settings::Plane& enemy_autoTarget( ); ///< ��ȡĬ�ϵ��Ի��ѵл����á���ȡLazy Load���ơ�
};