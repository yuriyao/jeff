/**
  *  实现长整形
  **/
#ifndef JE_LONG_OBJECT_H
#define JE_LONG_OBJECT_H
#include "jeobject.h"

namespace jeff_object
{
	class JeLongType;

	class JeLongObject : public JeObject
	{
	public:
		JeLongObject();
		JeLongObject(long value);
		JeLongObject(char *value);

	private:
		/*转换为double*/
		double to_double();
		unsigned char *value; 
	};

	class JeLongType : public JeType
	{
	public:

	};
}

#endif