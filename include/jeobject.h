/**
 *  jeff语言的所有类的父类
 **/
#ifndef JEOBJECT_H
#define JEOBJECT_H

#include <string>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include "mm.h"
#include <map>

namespace jeff_object
{

/*类的限定符类型*/
enum class_limit
{
	cl_auto = 0x01, 
	cl_static = 0x02,
	cl_const = 0x04,
};

/*还未进行hash的标志*/
const int UNHASHED = -1;

class JeType;

/*jeff语言的基本类,所有其他的东西继承自这个类*/
class JeObject
{
public:
	JeObject()
	: ref(1), cl(cl_auto), type(NULL)
	{

	}

	JeObject(JeType *type)
	: ref(1), cl(cl_auto), type(type)
	{

	}

	//增加引用计数
	void get()
	{
		assert(ref > 0);
		ref ++;
	}

	//减少引用计数
	void put()
	{
		assert(ref > 0);
		if((-- ref) == 0)
		{
			release(this);
		}
	}

	/*释放内存*/
	void release()
	{
		DELETE(this);
	}

	/*获得类型*/
	JeType* get_type()
	{
		return this->type;
	}
	/*设置类型*/
	void set_type(JeType *type)
	{
		this->type = type;
	}
	/*转变为常量,不予许往回转*/
	void set_const()
	{
		cl |= cl_const;
	}
	/*转换为static,不允许回转*/
	void set_static()
	{
		cl |= cl_static;
	}
	/*测试是否是常量*/
	bool is_const()
	{
		return (cl & cl_const) != 0;
	}
	/*测试是否是静态变量*/
	bool is_static()
	{
		return (cl & cl_static) != 0;
	}

	inline JeStrObject* str()
	{
		char buffer[30];
		sprintf(buffer, "object at %p\n", this);
		return NEW1(JeStrObject, buffer);
	}

	inline JeStrObject* repr()
	{
		char buffer[30];
		sprintf(buffer, "object at %p\n", this);
		return NEW1(JeStrObject, buffer);
	}

	inline JeObject* print(FILE *file)
	{
		if(!file)
		{
			printf("object at %p", this);
			
		}
		else
		{
			fprintf(file, "object at %p", this);
		}
		return NEW0(JeNullObject);
	}
	/**
	  *  jeff语言的函数,copy自身,与=不同
	  *  = 是使用相同的指针,copy则生成一个新的拷贝
	  *  这个新的拷贝与原象在引用计数和cl可能不一样,其他的数据域由相应的类型系统完成
	  */
	JeObject* copy()
	{
		JeObject *ret = NEW0(JeObject);
		return ret;
	}

protected:
	/*序列化*/
	std::string serial(JeObject *object);
	/*解析出来*/
	JeObject* dump(FILE *file);

private:
	//引用计数
	int ref;
	/*类的限定符*/
	int cl;
	/*类型*/
	JeType *type;

};

typedef JeObject * (*unaryfunc)(JeObject *);
typedef JeObject * (*binaryfunc)(JeObject *, JeObject *);
typedef JeObject * (*ternaryfunc)(JeObject *, JeObject *, JeObject *);
typedef int (*inquiry)(JeObject *);
typedef Py_ssize_t (*lenfunc)(JeObject *);
typedef int (*coercion)(JeObject **, JeObject **);
typedef JeObject *(*intargfunc)(JeObject *, int) Py_DEPRECATED(2.5);
typedef JeObject *(*intintargfunc)(JeObject *, int, int) Py_DEPRECATED(2.5);
typedef JeObject *(*ssizeargfunc)(JeObject *, Py_ssize_t);
typedef JeObject *(*ssizessizeargfunc)(JeObject *, Py_ssize_t, Py_ssize_t);
typedef int(*intobjargproc)(JeObject *, int, JeObject *);
typedef int(*intintobjargproc)(JeObject *, int, int, JeObject *);
typedef int(*ssizeobjargproc)(JeObject *, Py_ssize_t, JeObject *);
typedef int(*ssizessizeobjargproc)(JeObject *, Py_ssize_t, Py_ssize_t, JeObject *);
typedef int(*objobjargproc)(JeObject *, JeObject *, JeObject *);


typedef int (*getreadbufferproc)(JeObject *, int, void **);
typedef int (*getwritebufferproc)(JeObject *, int, void **);
typedef int (*getsegcountproc)(JeObject *, int *);
typedef int (*getcharbufferproc)(JeObject *, int, char **);
/* ssize_t-based buffer interface */
typedef Py_ssize_t (*readbufferproc)(JeObject *, Py_ssize_t, void **);
typedef Py_ssize_t (*writebufferproc)(JeObject *, Py_ssize_t, void **);
typedef Py_ssize_t (*segcountproc)(JeObject *, Py_ssize_t *);
typedef Py_ssize_t (*charbufferproc)(JeObject *, Py_ssize_t, char **);

typedef struct {

	binaryfunc nb_add;
	binaryfunc nb_subtract;
	binaryfunc nb_multiply;
	binaryfunc nb_divide;
	binaryfunc nb_remainder;
	binaryfunc nb_divmod;
	ternaryfunc nb_power;
	unaryfunc nb_negative;
	unaryfunc nb_positive;
	unaryfunc nb_absolute;
	inquiry nb_nonzero;
	unaryfunc nb_invert;
	binaryfunc nb_lshift;
	binaryfunc nb_rshift;
	binaryfunc nb_and;
	binaryfunc nb_xor;
	binaryfunc nb_or;
	coercion nb_coerce;
	unaryfunc nb_int;
	unaryfunc nb_long;
	unaryfunc nb_float;
	unaryfunc nb_oct;
	unaryfunc nb_hex;
	
	binaryfunc nb_inplace_add;
	binaryfunc nb_inplace_subtract;
	binaryfunc nb_inplace_multiply;
	binaryfunc nb_inplace_divide;
	binaryfunc nb_inplace_remainder;
	ternaryfunc nb_inplace_power;
	binaryfunc nb_inplace_lshift;
	binaryfunc nb_inplace_rshift;
	binaryfunc nb_inplace_and;
	binaryfunc nb_inplace_xor;
	binaryfunc nb_inplace_or;

	binaryfunc nb_floor_divide;
	binaryfunc nb_true_divide;
	binaryfunc nb_inplace_floor_divide;
	binaryfunc nb_inplace_true_divide;

	unaryfunc nb_index;
} JeNbMethods;

class JeStrObject;

class JeType : public JeObject
{
public:
	JeType()
	: JeObject(NULL), hash(UNHASHED), nbm(NULL)
	{
	}
	/*设置类型名称*/
	void set_name(const std::string &str)
	{
		name = str;
	}
	/*设置文档*/
	void set_doc(const std::string &doc)
	{
		this->doc = doc;
	}
	/*获得名称*/
	const string& get_name() const 
	{
		return name;
	}
	/*获得文档*/
	const string& get_doc() const
	{
		return doc;
	}
	/*获得父亲*/
	const std::vector<JeObject> get_parents() const
	{
		return parents;
	}
	/*添加一个父亲*/
	bool add_parent(JeObject *parent) 
	{
		if(!parent)
			return false;
		parents.push(parent);
		return true;
	}
	/*设置数值运算方法*/
	void set_nbm(JeNbMethods *nbm)
	{
		this->nbm = nbm;
	}
	/*获得数值运算方法*/
	JeNbMethods* get_nbm()
	{
		return this->nbm;
	}
	/*默认的计算hash值的方法*/
	long hash_func()
	{
		if(hash != UNHASHED)
			return hash;
		hash = (long)this;
		if(hash == UNHASHED)
			hash += 1;
		return hash;
	}

	
private:
	/*类型的名称*/
	string name;
	/*文档*/
	string doc;
	/*预保留的hash值*/
	long hash;
	/*对象的父类表*/
	std::vector<JeObject*> parents;
	/*数值运算方法*/
	JeNbMethods *nbm;
};

}

#endif