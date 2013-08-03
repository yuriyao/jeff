/*整数对象的实现*/
#include "jeobject.h"

namespace jeff_object
{
	/*整形对象的类型*/
	extern class JeType JeInt_type;
	/*整数系统的初始化*/
	extern void JeInt_init();

	/*整形对象*/
	class JeIntObject : public JeObject
	{
	public:
		JeIntObject();
		JeIntObject(long num);
		inline long get_value();
		inline void set_value(long value);

		/*序列化*/
		std::string serial();
		/*解析出来*/
		JeObject* dump(FILE *file);

	private:
		long value;
	};

	JeIntObject::JeIntObject()
	: JeObject(&JeInt_type), value(0)
	{

	}
	JeIntObject::JeIntObject(long num)
	: JeObject(&JeInt_type), value(num)
	{
		
	}

	long JeIntObject::get_value()
	{
		return this->value;
	}

	void JeIntObject::set_value(long value)
	{
		this->value = value;
	}

	/*整数对象类型*/
	class JeIntType : public JeType
	{
	public:
		JeIntType();
		JeIntType()
		

	};
}