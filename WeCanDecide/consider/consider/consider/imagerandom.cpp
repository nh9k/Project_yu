//랜덤으로 숫자를 리턴하는 자식 클래스


#include "stdafx.h"
#include "imagerandom.h"

int imagerandom::random1(int con)
{
	srand((unsigned int)time(NULL));
	con = (rand() %13)+ 15; //(rand() % 끝넘버 - 시작넘버 + 1)+ 시작넘버 ;
	return con;
}
imagerandom::~imagerandom()
{
}
