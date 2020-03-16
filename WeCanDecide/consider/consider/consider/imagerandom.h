#pragma once
#include "random.h" //랜덤함수 생성하는 헤더파일

class imagerandom :
	public random
{
public:
	imagerandom(int c) :random(c)
	{};
	int random1(int);
	~imagerandom();
};
