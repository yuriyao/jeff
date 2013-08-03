/*jeff语言内部异常处理*/
/*g++ -o exception exception.cpp -I ../include -I ../*/
#include "exception.h"
#include <iostream>

namespace jeff_internal
{

	Exception::Exception(const std::string &info)
	: info(info)
	{

	}
	std::string Exception::to_string() const
	{
		return info;
	}
	void Exception::print()
	{
		std::cout << info <<std::endl; 
	}

}

/*********测试*********/
//#define EXCEPTION_DEBUG
#ifdef EXCEPTION_DEBUG
void func()
{
	std::string str("hello");
	throw jeff_internal::Exception(str);
}
void func2()
{
	throw jeff_internal::NoMemException("内存不足了,亲");
}
int main(int argc, char **argv)
{
	try
	{
		func();
	}catch(jeff_internal::Exception &e)
	{
		std::cout << e.to_string() << std::endl;
		e.print();
	}
	try
	{
		func2();
	}
	catch(jeff_internal::NoMemException &e)
	{
		e.print();
	}
	return 0;
}
#endif