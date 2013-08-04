#include "jeexceptionobject.h"
#include <stdio.h>

namespace jeff_object
{

	JeExceptionObject::JeExceptionObject()
	:
	{

		set_type()
	}

	/*jeff语言用来抛出异常*/
	void JeExcetionObject::je_throw()
	{
		this->print(stderr);
		abort();
	}

	JeObject* JeExceptionObject::print(FILE *file)
	{
		return this->str()->print();
	}

	JeStrObject* JeExceptionObject::repr()
	{

	}

	JeStrObject* JeExceptionObject::str()
	{

	}

	/**************************************************/
	/*异常实例*/
	JeExceptionObject *JeExcept;
	JeNoMemExceptionObject *JeExcept_NoMem;
	JeStrTooLongExceptionObject *JeExcept_StrTooLong;
	JeNoImplementExceptionObject *JeExcept_NoImplement;

	/**
	 *  异常系统初始化
	 **/
	void je_exception_init()
	{
		JeExcept = NEW0(JeExceptionObject);
		JeExcept_NoMem = NEW0(JeNoMemExceptionObject);
		JeExcept_StrTooLong = NEW0(JeStrTooLongExceptionObject);
		JeExcept_NoImplement = NEW0(JeNoImplementExceptionObject);
	}

	

}