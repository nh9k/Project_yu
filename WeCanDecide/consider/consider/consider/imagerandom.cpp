//�������� ���ڸ� �����ϴ� �ڽ� Ŭ����


#include "stdafx.h"
#include "imagerandom.h"

int imagerandom::random1(int con)
{
	srand((unsigned int)time(NULL));
	con = (rand() %13)+ 15; //(rand() % ���ѹ� - ���۳ѹ� + 1)+ ���۳ѹ� ;
	return con;
}
imagerandom::~imagerandom()
{
}
