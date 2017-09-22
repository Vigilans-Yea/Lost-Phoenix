#pragma once

/// <summary>
/// �����������Ŀ������ࡣ
/// </summary>
class InputController
{
public:
	/// <summary>
	/// ������洢��λ������һһ��Ӧ��ö�١�
	/// </summary>
	enum class Key
	{
		W, A, S, D, Space,
		Size /// ����ö�ٵ����һλ����������ö��ӵ�е�Ԫ�ظ���������Size��
	};

	/// <summary>
	/// Ĭ�Ϲ��캯�������Գ�ʼ������״̬���飨ȫ�����㣩��
	/// </summary>
	InputController( );
	
	/// <summary>
	/// �Ӽ��̸������롣�ú����ᱻ<see cref="World::update"/>���á�
	/// </summary>
	/// <remarks>
	/// �˷������������̰�����Ϣ���У���״̬�����н���Ӧ����״̬��Ϊtrue��ͬʱ��δ������������״̬��Ϊfalse��
	/// 
	/// ʱ�临�Ӷ����Ϊk*n, kΪ������Ϣ����size��nΪ����ö�ٵ�size��
	/// </remarks>
	void updateInput( );
	
	/// <summary>
	/// �жϵ�ǰ�Ƿ���ĳ������
	/// </summary>
	/// <param name="key"> Ҫ���ļ�λö��ֵ�� </param>
	/// <returns>
	/// �������򷵻��档
	/// </returns>
	bool isKeyDown(Key key);

private:
	/// <summary>
	/// �洢ĳ��������Ӧ��Virtual Key�����顣ÿ��Ԫ�ص���������<see cref="Key"/>ö�ٵĶ�Ӧö��ֵһһ��Ӧ��
	/// </summary>
	static int KeysEnum[(int)Key::Size];
	
	/// <summary>
	/// �洢����״̬�����顣Keyö��ֵ��ӦԪ��Ϊ<see cref="Key"/>��ʾ��Ӧ�����������¡�
	/// </summary>
	bool m_KeyState[(int)Key::Size];
};