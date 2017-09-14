#include "InputController.h"
#include <graphics.h>

int InputController::KeysEnum[(int)Key::Size] = {'W', 'A', 'S', 'D', VK_SPACE};

InputController::InputController( ) : m_KeyState( ) { }

void InputController::updateInput( )
{
	for(key_msg key; kbmsg( );)
	{ // ������k*n��
		key = getkey( );
		for (int i = 0; i < sizeof(KeysEnum); ++i) 
		{
			if (key.key == KeysEnum[i]) 
			{
				if (key.msg == key_msg_down) 
				{ // ���event�ǡ����¼���
					m_KeyState[i] = true;
				}
				else if (key.msg == key_msg_up) 
				{ // ���event�ǡ��ɿ�����
					m_KeyState[i] = false;
				}
				break;
			}
		}
	}
}

bool InputController::isKeyDown(Key key)
{
	return m_KeyState[static_cast<int>(key)]; 
}
