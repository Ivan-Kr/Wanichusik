#include "Kiwii/Screen.h"
#include "Kiwii/Music.h"

int main(int args,char* argv[])
{
	printf("%s\n",argv[0]);
	is_sound(L".\\Pocket\\Introduce.wav");

	scene a;
	a.obj.resize(1);
	a.obj[0].set_size(8, 8);
	a.obj[0].import(".\\Pocket\\Pic.ppm");
	a.obj[0]._positioo(5, 5);
	a.write_comment("Hey, its apple!");
	a.write_scene(30, 30,true);
	 
	std::cin.get();
}