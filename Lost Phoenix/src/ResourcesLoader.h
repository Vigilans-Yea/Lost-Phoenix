#pragma once
#include "Resources.h"
#include <map>
#include <memory>

namespace Settings
{
	/// <summary>
	/// ���ʵ�����Դ��������������һ�������Ĳ��ʡ�
	/// </summary>
	struct TextureInfo
	{
		std::wstring path; ///< ���ʵ�·��������Unicode�ַ�����Ϊ���·������Եĸ�·������F5��Ctrl+F5�仯��
		Vector2D hitbox; ///< ���ʵķֱ��ʡ�
		Vector2D expectHitBox = Vector2D(); ///< ���ʾ����ź�Ҫ�ﵽ�ķֱ��ʡ�Ϊ������ʱ��ʾ�����š�
	};
}

/// <summary>
/// ��Դ������������<see cref="Resources.cpp"/>��ʹ�á��ڶ���һ���ȶ��ڴ��й����в��ʼ�������Դ��
/// </summary>
class ResourcesLoader
{
public:	
	/// <summary>
	/// Ĭ�Ϲ��캯���������ڳ���ʼʱ�������в������õ�<see cref="TextureInfo"/>��
	/// </summary>
	ResourcesLoader();
	
	/// <summary>
	/// ��������������������в��ʼ����á�
	/// </summary>
	~ResourcesLoader();
	
	/// <summary>
	/// ͨ��Ԫ��Ϣ���ز��ʡ�
	/// </summary>
	/// <remarks>
	/// ��w_to��h_to��������һ��Ϊ0ʱ����ʾ�����š�
	/// </remarks>
	/// <param name="imagePath"> ���ʵ�·��������Unicode�� </param>
	/// <param name="w_raw">	 ���ʵ�ԭ�ֱ��ʿ�ȡ� </param>
	/// <param name="h_raw">	 ���ʵ�ԭ�ֱ��ʸ߶ȡ� </param>
	/// <param name="w_to">  (��ѡ) �������ŵ��ķֱ��ʿ�ȡ� </param>
	/// <param name="h_to">	 (��ѡ) �������ŵ��ķֱ��ʸ߶ȡ� </param>
	/// <returns>
	/// ���سɹ��󣬷��ؼ��ض��õĲ��ʡ�
	/// </returns>
	Texture loadTexture(const wchar_t* imagePath, int w_raw, int h_raw, int w_to = 0, int h_to = 0);
	
	/// <summary>
	/// ͨ��<see cref="TextureInfo"/>���ز��ʡ�
	/// </summary>
	/// <remarks>
	/// ��װ��һ�����ղ������õĸ����õĽӿڡ��������ж�����Ĭ��inline�ġ�
	/// 
	/// TODO: �ò���ת��(forwarding)ʵ��������ء�
	/// </remarks>
	/// <param name="setting"> ���ʵ�����Դ�� </param>
	/// <returns>
	/// ���سɹ��󣬷��ؼ��ض��õĲ��ʡ�
	/// </returns>
	Texture loadTexture(Settings::TextureInfo setting)
	{ 
		return loadTexture(setting.path.c_str(), setting.hitbox.x, setting.hitbox.y, setting.expectHitBox.x, setting.expectHitBox.y);
	}
	
	/// <summary>
	/// �������в������á��ڳ���ʼʱͨ��<see cref="constructor"/>���á�
	/// </summary>
	void loadTextureSettings();
	void loadGeneralSettings(); ///< ����ȫ�����á�ͨ��Lazy Load������ʱ���á�
	void loadBgTextures(); ///< �������б������ʡ�ͨ��Lazy Load������ʱ���á�
	void loadAnimeTextures(); ///< �������ж������ʡ�ͨ��Lazy Load������ʱ���á�
	void loadPlaneSettings(); ///< �������зɻ����á�ͨ��Lazy Load������ʱ���á�
	const std::map<int, Texture>& loadAllTextures(); ///< һ���Լ������в��ʡ���ΪDepreciated��

	// settings loaded
	struct
	{
		std::unique_ptr<Settings::General> pGeneral; ///< Ĭ��ȫ�����á�
		std::unique_ptr<Settings::BgTextures> pBgTextures; ///< ���б������ʡ�
		std::unique_ptr<Settings::AnimeTextures> pAnimeTextures; ///< ���ж������ʡ�
		std::unique_ptr<Settings::Plane> pPlayer; ///< Ĭ����ҷɻ����á�
		std::unique_ptr<Settings::Plane> pEnemyJunior; ///< Ĭ���±��л����á�
		std::unique_ptr<Settings::Plane> pEnemyAutoTarget; ///< Ĭ���Ի��ѵл����á�
		std::map<int, Settings::TextureInfo> mTextureInfos; ///< �������в����������á�
	} settings; ///< ��������Ĭ�����á������ⲿ��ͨ���˴���������õ���������ȡĬ�����á�
	
	std::map<int, Texture> textures; ///< �����������������صĲ��ʡ�ͨ�����ʵ�ID���м�����
};