#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <iostream>
#include <cstring>



using byte = unsigned char;
using Compare = bool (*)(const void*, const void* );
using Predicate = bool (*)(const void*);
using Equal = bool (*)(const void *, const void *);

namespace graal{
	
	//1
	const void * min(const void * first, const void * last, std::size_t size, Compare cmp);
	bool cmp(const void* var1, const void * var2);
	
	//2
	void reverse(void * first, void * last, size_t size);

	//3
	void * copy(const void * first, const void * last, const void * d_first, size_t size);
	
	//4
	void * clone(const void * first, const void * last, size_t size);

	//5
	const void * find_if(const void * first, const void * last, size_t size, Predicate p);
	bool p(const void *);
	
	//6
	const void * find(const void * first, const void * last, size_t size, const void * value, Equal eq);
	bool eq(const void*, const void *);
	
	//7
	bool all_of(const void * first, const void * last, size_t size, Predicate p);
	bool any_of(const void * first, const void * last, size_t size, Predicate p);
	bool none_of(const void * first, const void * last, size_t size, Predicate p);
	
	//8
	bool equal(const void * first1, const void * last1, const void * first2);
	bool equal(const void * first1, const void * last1, const void * first2, const void * last2);

	//9
	void * unique(void * first, void * last, size_t size, Equal eq);
	
	//10
	void * partition(void * first, void * last, size_t size, Predicate p);
	
}	
	
#endif
