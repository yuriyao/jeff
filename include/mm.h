/**
 *  内存管理
 **/
#ifndef MM_H
#define MM_H
#include "config.h"
#include <stdlib.h>
#include "exception.h"

#if MM_METHOD == 1
static inline void* mm_malloc(int len)
{
	return malloc(len > 0 ? len : 1);
} 

/*释放并清0指针*/
#define mm_free(ptr)\
	(free(ptr); ptr = NULL;)
	
#endif

/*如果发生了内存不足的情况,就抛出异常,异常在全局捕获,所以在NEW时不用判断是否成功*/
/*new没有参数的构造器*/
#define NEW0(type) ({\
	type* __ret = (type*)mm_malloc(sizeof(type));\
	if(!__ret)\
		throw jeff_internal::NoMemException();\
	new(__ret) type;\
	__ret;\
})

/*new只有一个参数的构造器*/
#define NEW1(type, arg1) ({\
	type* __ret = (type*)mm_malloc(sizeof(type));\
	if(!__ret)\
		throw jeff_internal::NoMemException();\
	new(__ret) type(arg1);\
	__ret;\
})

/*new只有两个个参数的构造器*/
#define NEW2(type, arg1, arg2) ({\
	type* __ret = (type*)mm_malloc(sizeof(type));\
	if(!__ret)\
		throw jeff_internal::NoMemException();\
	new(__ret) type(arg1, arg2);\
	__ret;\
})

/*new只有三个个参数的构造器*/
#define NEW3(type, arg1, arg2, arg3) ({\
	type* __ret = (type*)mm_malloc(sizeof(type));\
	if(!__ret)\
		throw jeff_internal::NoMemException();\
	new(__ret) type(arg1, arg2, arg3);\
	__ret;\
})

/*多余三个就慢慢实现吧*/

#define DELETE(ptr) (mm_free(ptr))

#endif