// �������� ���ڸ� �����ϴ� Ŭ����, �θ� Ŭ����

#include "stdafx.h"
#include "random.h"

random::random(int c)
{
	con = c;
}

int random::random1(int con)
{
	srand((unsigned int)time(NULL));
	con = rand() % 6; // �ڽ�Ŭ�������� ���ڰ� �뷫����
	return con;
}

random::~random()
{
}
