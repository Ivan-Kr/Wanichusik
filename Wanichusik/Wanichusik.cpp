#include "./Kiwii/DatoBased/Spritech/Spritech.h"
#include "./Kiwii/DatoBased/Mathem/Mathem.h"
#include <iostream>
#include <sstream>
#include <array>
#include <windows.h>
//⠀⠁⠂⠃⠄⠅⠆⠇⠈⠉⠊⠋⠌⠍⠎
//⠏⠐⠑⠒⠓⠔⠕⠖⠗⠘⠙⠚⠛⠜⠝
//⠞⠟⠠⠡⠢⠣⠤⠥⠦⠧⠨⠩⠪⠫⠬
//⠭⠮⠯⠰⠱⠲⠳⠴⠵⠶⠷⠸⠹⠺⠻
//⠼⠽⠾⠿⡀⡁⡂⡃⡄⡅⡆⡇⡈⡉⡊
//⡋⡌⡍⡎⡏⡐⡑⡒⡓⡔⡕⡖⡗⡘⡙
//⡚⡛⡜⡝⡞⡟⡠⡡⡢⡣⡤⡥⡦⡧⡨
//⡩⡪⡫⡬⡭⡮⡯⡰⡱⡲⡳⡴⡵⡶⡷
//⡸⡹⡺⡻⡼⡽⡾⡿⢀⢁⢂⢃⢄⢅⢆
//⢇⢈⢉⢊⢋⢌⢍⢎⢏⢐⢑⢒⢓⢔⢕
//⢖⢗⢘⢙⢚⢛⢜⢝⢞⢟⢠⢡⢢⢣⢤
//⢥⢦⢧⢨⢩⢪⢫⢬⢭⢮⢯⢰⢱⢲⢳
//⢴⢵⢶⢷⢸⢹⢺⢻⢼⢽⢾⢿⣀⣁⣂
//⣃⣄⣅⣆⣇⣈⣉⣊⣋⣌⣍⣎⣏⣐⣑
//⣒⣓⣔⣕⣖⣗⣘⣙⣚⣛⣜⣝⣞⣟⣠
//⣡⣢⣣⣤⣥⣦⣧⣨⣩⣪⣫⣬⣭⣮⣯
//⣰⣱⣲⣳⣴⣵⣶⣷⣸⣹⣺⣻⣼⣽⣾⣿

enum Dir {
	North,
	West,
	South,
	East
};

int main() {

	uint32_t score = 0;

	const Kiwii::Dot size(10,20);

	std::vector<Kiwii::Dot>blocks;

	blocks.push_back(Kiwii::Dot(1,5));

	while (true) {
		bool is_lose = false;
		system("cls");
		//////////////////////////

		//input
		{
			if (GetAsyncKeyState(VK_LEFT)&& blocks[0].X-1<0) blocks[0].X--;
			else if (GetAsyncKeyState(VK_RIGHT) && (size.Y > blocks[0].Y && blocks[0].Y >= 0)
				&& (size.X > blocks[0].X && blocks[0].X >= 0)) blocks[0].X++;
			else if (GetAsyncKeyState(VK_DOWN) && (size.Y > blocks[0].Y && blocks[0].Y >= 0)
				&& (size.X > blocks[0].X && blocks[0].X >= 0)) blocks[0].Y++;
			else{}
		}

		//output
		{
			std::vector<std::vector<char>> map;
			map.resize(size.X);
			for (int i = 0;i < size.X;i++) {
				map[i].resize(size.Y);
			}
			for (int i = 0;i < size.X;i++)
				for (int j = 0;j < size.Y;j++) 
					map[i][j] = '.';

			for (int i = 0;i < blocks.size();i++) 
				if ((size.Y > blocks[i].Y && blocks[i].Y >= 0) 
					&& (size.X > blocks[i].X && blocks[i].X >= 0))
					map[blocks[i].X][blocks[i].Y] = '#';

			std::string str="";
			for (int i = 0;i < size.Y;i++) { 
				for (int j = 0;j < size.X;j++) 
					str += map[j][i];
				str += '\n';
			}

			std::cout << str;
		}

		//////////////////////////
		if (is_lose) break;
	}

	std::cout << "Score = " << score<<'\n';

	return 0;
}
