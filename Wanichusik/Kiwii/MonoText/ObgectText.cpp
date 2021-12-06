#include "ObgectText.h"

kiwii::ObgectText::ObgectText()
{
}

void kiwii::ObgectText::Import(std::wstring dir)
{
	std::wifstream file;
	file.open(dir);

	if (file.is_open()) {

		std::wstring str;

		while (file) {
			std::getline(file, str);

			_pic.resize(_pic.size());
			_pic[_pic.size() - 1].resize(str.size());

			for (int i = 0;i < str.size();i++) 
				_pic[_pic.size() - 1][i] = str[i];
		}

	}


}

kiwii::ObgectText::~ObgectText()
{
}