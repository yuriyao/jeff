#include "jestrobject.h"
#include "jeintobject.h"
#include "jelongobject.h"
#include "jeexceptionobject.h"
#include <string.h>

namspace jeff_object
{
	JeStrObject::JeStrObject()
	: str(NULL), len(0)
	{

	}

	JeStrObject::JeStrObject(char *str)
	{
		set_str(str);
	}

	JeStrObject::JeStrObject(JeObject *obj)
	{
		JeStrObject *str_obj = obj->str();
		if(!str_obj->str)
		{
			this->str = NULL;
			this->len = 0;
		}
		else
		{
			this->str = 
		}
		/*减少引用计数*/
		str_obj->put();
	}

	void JeStrObject::set_str(char *str)
	{
		if(!str)
		{
			this->str = NULL;
			this->len = 0;
		}
		else 
		{
			this->len = strlen(str);
			if(len > STR_LEN_MAX)
			{
				this->len = 0;
				this->str = NULL;
				/*字符串太长,抛出异常*/
				JeExcept_StrTooLong->je_throw();
				return;
			}
			this->str = (char*)mm_malloc(len + 1);
			if(!this->str)
				throw jeff_internal::NoMemException;
   			memcpy(this->str, str, len + 1);
		}
	}

	JeStrObject::~JeStrObject()
	{
		mm_free(str);
	}



}