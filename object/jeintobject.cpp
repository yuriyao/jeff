/*整数类型对象的具体实现*/
#include "jeintobject.h"

namespace jeff_object
{
	/*整形对象的类型*/
	class JeIntType JeInt_type(NULL);
	/*将整数转换为整数对象*/
	JeIntObject* JeInt_fromLong(int value)
	{
		return NEW1(JeIntObject, value);
	}

	/*****************************数值操作函数********************************/
	/*整数相加*/
	JeIntObject* JeInt_add(JeIntObject *v1, JeIntObject *v2)
	{
		assert(v1);
		assert(v2);
		long a = v1->get_value();
		long b = v2->get_value();
		long x = a + b;
		/*未发生溢出*/
		if((x ^ a) >= 0 || (x ^ b) >= 0)
			return NEW1(JeIntObject, x);
		/*会发生溢出*/
		else
			/*应该转换为长整形*/
			return NEW1(JeIntObject, 0);
	}
	/*整数相减*/
	JeIntObject* JeInt_Sub(JeIntObject *v1, JeIntObject *v2)
	{
		long a = v1->get_value();
		long b = -(v2->get_value());
		long x = a + b;

		/*未发生溢出*/
		if((x ^ a) >= 0 || (x ^ b) >= 0)
			return NEW1(JeIntObject, x);
		/*会发生溢出*/
		else
			/*应该转换为长整形*/
			return NEW1(JeIntObject, 0);
	}

	JeNbMethod JeInt_nbMethod = 
	{
		JeInt_add,
		JeInt_Sub,

	};



	/******************整数的序列化操作**********************/
	std::string JeIntObject::serial()
	{
		return std::string(this->value);
	}

	JeObject* JeIntObject::dump(FILE *file)
	{
		long v;

		fscanf(file, "%ld", &v);

		return JeInt_fromLong(v);
	}

	/*整数系统的初始化*/
	void JeInt_init()
	{
		/*设置数值操作函数表*/
		JeInt_type.set_nbm(&JeInt_nbMethod);

	}
}
