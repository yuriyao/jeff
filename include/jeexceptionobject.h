/**
  *  jeff语言的异常
  **/
#include "jeobject.h"

namespace jeff_object
{
	/**
	 *  异常系统的基类
	 **/
	class JeExceptionObject : public JeObject
	{
	public:
		JeExceptionObject();
		JeExceptionObject(char *info);
		/*jeff语言用来抛出异常*/
		void je_throw();
		JeObject* print(FILE *file);
		JeStrObject* repr();
		JeStrObject* str();
		

	private:
		PyStrObject *info;
		
	};

	/**
	 *  内存不足的异常
	 **/
	class JeNoMemExceptionObject : public JeExceptionObject
	{
	public:
		JeNoMemExceptionObject()
		: JeExceptionObject("No memery exception")
		{

		}
	};

	/**
	 *  字符串太长的异常
	 **/
	class JeStrTooLongExceptionObject : public JeExceptionObject
	{
	public:
		JeStrTooLongExceptionObject()
		: JeExceptionObject("Str too long exception")
		{

		}
	};

	/**
	 *  方法还没有实现的异常
	 **/
	class JeNoImplementExceptionObject : public JeExceptionObject
	{
	public:
		JeNoImplementExceptionObject()
		: JeExceptionObject("Method not implement exception")
		{

		}
	};

	class JeExceptionType : public JeType 
	{
	public:

	};

	/**
	 *  异常系统初始化
	 **/
	extern void je_exception_init();

	/*异常实例*/
	extern JeExceptionObject *JeExcept;
	extern JeNoMemExceptionObject *JeExcept_NoMem;
	extern JeStrTooLongExceptionObject *JeExcept_StrTooLong;
	extern JeNoImplementExceptionObject *JeExcept_NoImplement;

}

