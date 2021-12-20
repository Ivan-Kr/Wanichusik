#pragma once
//independent class
class KiwiI
{
	unsigned __int64 size;
	__int64 seed=0;
public:

	KiwiI();

	unsigned __int64 __size();
	unsigned __int8 _cunt_dig(__int64 num);
	__int64 _random(__int64 seed);
	__int64 _random();

	~KiwiI();

	

protected:
	void _setsize(unsigned __int64 size);
};

