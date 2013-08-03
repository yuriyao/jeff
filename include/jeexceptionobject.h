/**
  *  jeff语言的异常
  **/
#include "jeobject.h"

namespace jeff_object
{
	class JeExceptionObject : public JeObject
	{
	public:
		JeExceptionObject();
		JeExceptionObject(std::string &info);
		
	};

	class JeExceptionType : public JeType 
	{

	};

	/*jeff语言用来抛出异常*/
	void je_throw(JeExceptionObject &obj);
	void je_throwe(JeExceptionObject *obj);
}

