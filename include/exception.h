/*用于错误或者异常处理处理*/
#include <string>
#ifndef EXCEPTION_H
#define EXCEPTION_H


namespace jeff_internal
{
	/*jeff语言所有异常类的基类*/
	class Exception
	{
	public:
		Exception(const std::string &info);
		std::string to_string() const;
		void print();
	private:
		std::string info;
	};
	/*内存不足*/
	class NoMemException : public Exception
	{
	public:
		NoMemException()
		: Exception("内存不足")
		{}
		NoMemException(const std::string &info)
		: Exception(info)
		{}
	};
	/*类还没有初始化好,可能是因为内部的一些成员变量没有赋值*/
	class NotInitOKException : public Exception
	{
	public:
		NotInitOKException()
		: Exception("对象还没有初始化好")
		{

		}
		NotInitOKException(const std::string &info)
		: Exception(info)
		{
			
		}
	};
}
#endif
