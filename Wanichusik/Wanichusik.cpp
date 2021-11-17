#include "Kiwii/Screen.h"

int main()
{
	scene a;
	a.obj.resize(1);
	a.obj[0].set_size(8, 8);
	a.obj[0].import("D:\\nand\\Pic.ppm");
	a.obj[0]._positioo(5, 5);
	a.write_scene(30, 30,false);
}