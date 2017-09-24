/*! \mainpage Main Page
*
* \section intro_sec ���
*
* ����һ����EGEͼ�ο��д�ļ��׷ɻ���ս��Ϸ��
*
* \section build_sec ����
*
* ����ĿClone/Download�����غ���������restore_dependencies.ps1����ȡEGEͼ�ο���json�⵽������Ŀ�С�
* * EGEͼ�ο���������http://pan.seu.edu.cn��ΪVS2017�棬������ʹ��Visual Studio 2017�������ɡ�
*
* 
* --------
* ������Ŀ�ĸ���ϸ����ṹ���ܣ���μ�ʵ�����档
*/

#include <graphics.h>
#include <ege/fps.h>
#include "World.h"

World& world = *new World;

int main(int argc, const char* argv[ ])
{
	mainProcess:
	if (world.initialize())
	{
		world.renderMenu( );
		for (fps ui_fps; world.is_running( ); delay_fps(world.fps( )))
		{
			world.update( );
			world.updateCollision( );
			world.updateState( );
			world.render( );
		}
		world.clearWorld( );
		world.renderOverInterface( );
	}
	if(world.get_running( ))
		goto mainProcess;

	return 0;
}