// �����Լ� ������ ���� �������, �θ�Ŭ���� 

#pragma once
class random
{
protected:
	int con;

public:
	random(int c);
	virtual int random1(int); // virtual�� �������̵� ���
	~random();
};

