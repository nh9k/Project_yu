#pragma once
#include "random.h" //�����Լ� �����ϴ� �������

class imagerandom :
	public random
{
public:
	imagerandom(int c) :random(c)
	{};
	int random1(int);
	~imagerandom();
};
