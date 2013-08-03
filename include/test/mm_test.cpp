/**
 *  g++ -o mm_test mm_test.cpp ../../lib//exception.cpp -I ../ -I ../../
 **/
#include "mm.h"
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A init..." << std::endl;		
		this->a = 10;
	}
	A(int a)
	: a(a)
	{
		std::cout << "A init with one " <<std::endl;

	}
	void print()
	{
		std::cout << this->a << std::endl;
	}
private:
	int a;
};

int main(int argc, char **argv)
{
	A *a = NEW0(A);
	A *a2 = NEW1(A, 4);
	a->print();
	a2->print();
	return 0;
}