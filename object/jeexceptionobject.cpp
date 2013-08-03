#include "jeexceptionobject.h"

namespace jeff_object
{
	
	/*jeff语言用来抛出异常*/
	void je_throw(JeExceptionObject &obj)
	{
		obj.print();
		abort();
	}
	void je_throw(JeExceptionObject *obj)
	{
		je_throw(*obj);
	}
}