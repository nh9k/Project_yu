// 랜덤함수 생성을 위한 헤더파일, 부모클래스 

#pragma once
class random
{
protected:
	int con;

public:
	random(int c);
	virtual int random1(int); // virtual로 오버라이드 사용
	~random();
};

