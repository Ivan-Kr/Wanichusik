#include ".\Kiwii.h"

Kiwii::Kiwii()
{
	this->size = sizeof(Kiwii);
}

unsigned __int64 Kiwii::__size()
{
	return size;
}

unsigned __int8 Kiwii::_cunt_dig(__int64 num)
{
	unsigned __int8 iter = 0;
	while (num != 0) {
		num /= 10;
		iter++;
	}

	return iter;
}

__int64 Kiwii::_random(__int64 seed)
{
	//we have work with numbers, what isn't rise 1152921504606846975
	const __int64 m = 281474976710656;
	const __int64 a = 48271;
	const __int64 c = 161803398874989;
	//X(n+1)=(a*(X*X)+c)%m
	this->seed = ((a*(seed)+c)%m);

	return this->seed;
}
__int64 Kiwii::_random()
{
	return _random(this->seed);
}

Kiwii::~Kiwii()
{

}

void Kiwii::_setsize(unsigned __int64 size)
{
	this->size = size;
}
