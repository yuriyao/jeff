/**
  *  字符串对象
  **/
#include "jeobject.h"

namspace jeff_object
{

	class JeIntObject;
	class JeLongObject;

	/*字符串的最长长度*/
	const long STR_LEN_MAX = (1UL << 30);

	class JeStrObject : public JeObject
	{
	public:
		JeStrObject();
		JeStrObject(char *str);
		JeStrObject(JeObject *obj);


		JeStrObject* copy();

		~JeStrObject();

	private:
		void set_str(char *str);
		char *str;
		int len;

	};

	class JeStrType : public JeType
	{

	};
}