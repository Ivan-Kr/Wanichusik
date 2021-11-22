#include "ShaderText.h"

void kiwii::ShaderText::Connect(ScreenText screentext)
{
	ConnectedScreen = screentext;
	is_connected = 1;
	action.push_back("Connect to "+(long long)&ConnectedScreen);
}

void kiwii::ShaderText::Disconnect()
{
	is_connected = 0;
	action.push_back("Disconnect from " + (long long)&ConnectedScreen);
}

void kiwii::ShaderText::Noise()
{
	for (int i = 0;i < ConnectedScreen.Height() * ConnectedScreen.Width();i++)
		ConnectedScreen.Screen(i, rand() % sizeof(wchar_t));
	action.push_back("Noise for " + (long long)&ConnectedScreen);
}

std::string kiwii::ShaderText::ShowList(int index)
{
	auto i = action.begin();

	while (i != action.end() || index != 0) {
		i++;
		index--;
	}

	if (index == 0 && i != action.end()) {
		return *i;
	}
}
