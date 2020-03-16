// 랜덤으로 숫자를 리턴하는 클래스, 부모 클래스

#include "stdafx.h"
#include "random.h"

random::random(int c)
{
	con = c;
}

int random::random1(int con)
{
	srand((unsigned int)time(NULL));
	con = rand() % 6; // 자식클래스보다 숫자가 대략적임
	return con;
}

random::~random()
{
}
