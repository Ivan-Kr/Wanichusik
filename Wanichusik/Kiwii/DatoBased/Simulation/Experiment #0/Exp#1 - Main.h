#pragma once
#include "../_Template/_temp.h"
#include <vector>

//� ����, � ����� ������ ��������
//���� ����� �������, ����� ��������
//��� ����� ���� ������������ �������� (��-�� ������� ����)(������)
//��� ���� � ������� �������� (�����)

//� 4 ����� ����� ��������, "�������", "�������", "�'�����" � "������"
//���� �������� 1,2,3 � 0 ��������� ������� �������� ���� �����
//� ������� ������� � 64 ���� ���'��
//"��������� ������� ����㳿"(0-3), "�����������"(8), "��������"(4-7) � "���������"(9)
// ��� �� � � ��������� �� ������, �� �������������� ������� �� ��������� ������ - 10 (10-73)
// ������� ���� ����������� �� ������ ����, �� ��, ����������� ����� ������, � �� ���� �����
// ����� +1, ������ +2,...
// ���� �� ���� ������ "�������", �� +1, "��������", +2,...
// �� ��������� ���� ������� 1
//�� ��� ����������, ������ ������� � ����� � ������ 1/5 � ����� ���� ���������� �������
//(���������� ��� �'�������) ���� ������ ������ �����, � ���� � ��� �� ������� ����� � ����� ������� �� 3 ������ � ���� ���� ���� ���������, �� ���� ���� ������
//(���������� ��� ���������) ���� ������ ��������� �� �� �������, ���� �� ���, �� ���� �� ����
//� ������� ���� �� � ������� ����㳿, ���� ���� ���� < 1, �� ���� ���� ����������
//�������� ������ ��������� �� ������ � �������� �� �� ������, � ���� ������ ������� �� �� ���� �������, �� ����������� �����������

namespace Kiwii_Experiment {

	class Experiment {
	
		enum creatures {
			Plants,
			Herbivors,
			Carnivorous,
			Bacteries,
		};

		struct LiveDot {
			Kiwii::Point_Exp point;
			creatures type;
		};

		std::vector<Kiwii::Point_Exp> Dots;
	public:
		Kiwii::Map_Exp<uint8_t> Map = Kiwii::Map_Exp<uint8_t>(120,90);
		Kiwii::Map_Exp<uint8_t> MapSun = Kiwii::Map_Exp<uint8_t>(120, 90);
		Kiwii::Map_Exp<uint8_t> MapMineral = Kiwii::Map_Exp<uint8_t>(120, 90);

		void GenerateLight() {
			int k = 30;
			int sk = k;
			int min = 128;
			double z = 2;
			double zz = 1;
			for (int i = 0;i < MapSun.x;i+=k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();

					for (int ii = i;ii < i+k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] = NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 15;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM- min) ;
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k,z) / pow( sk,zz));

				}
			}
			k = 10;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 5;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 2;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 1;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					MapSun.map[i][j] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
		}

	};

}