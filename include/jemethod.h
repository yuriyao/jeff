/*
 *	jeff语言的通用方法
 *  可以被c函数和JeFunctionObject使用
 */
#ifndef JEMETHOD_H
#define JEMETHOD_H
#include "jeobject.h"
#include "exception.h"
#include <string>

namespace jeff_object
{
	/*方法的类型*/
	enum METHOD_TYPES
	{
		NOT_INIT_OK,//还没有初始化好
		C_FUNCTION,//c函数
		JE_FUNCTION_OBJECT,//jeff内置的function对象
	};
 	class JeMethodObject : public JeObject
 	{
 	public:
 		JeMethodObject() 
 		: JeObject(), type(NOT_INIT_OK)
 		{

 		}
 		/*设置C函数*/
 		bool set_c_function(void *func)
 		{
 			type = C_FUNCTION;
 			this->func = func;
 			return true;
 		}
 		/*设置为JeffFunction对象*/
 		bool set_function_object(JeObject *func)
 		{
 			if(!JeCallable_check(func))
 				return false;
 			type = JE_FUNCTION_OBJECT;
 			this->func = func;
 			return true;
 		}
 		/*获得函数*/
 		void* get_func()
 		{
 			/*类本身还没有初始化好*/
 			if(type == NOT_INIT_OK)
 				throw jeff_internal::NotInitOKException("JeMethodObject还没有初始化好,,请先给函数赋值");
 			return this->func;
 		}
 		/*测试是否是C函数*/
 		bool is_c_function()
 		{
 			return type == C_FUNCTION;
 		}
 		/*测试是否是JeFunction对象*/
 		boool is_je_function_object()
 		{
 			return type == JE_FUNCTION_OBJECT;
 		}
 	private:
  		int type;
 		void *func;
 	};
}
#endif