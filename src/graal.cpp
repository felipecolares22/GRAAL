#include <iostream>
#include <iterator>
#include <cstring>
#include "graal.h"

using byte = unsigned char;
using Compare = bool (*)(const void*, const void *);


namespace graal{

	//1
	bool cmp(const void* var1, const void* var2){
		const int * pvar1 = static_cast<const int*>(var1);
		const int * pvar2 = static_cast<const int*>(var2);
		
		return (*pvar1<*pvar2);
	}

	const void * min (const void *first, const void *last, std::size_t size, Compare cmp){
	
		byte * pfirst = (byte*) first;
		byte * plast = (byte*) last;
		byte smallest[size];
		byte aux_arr[size];

		void * result = pfirst;
	
		std::memcpy(smallest, pfirst, size);
	
		while(pfirst < plast){
			std::memcpy(aux_arr, pfirst, size);
	
			if( cmp(aux_arr, smallest ) ){
				std::memcpy(smallest, pfirst, size);
				result = pfirst;
			}
	
			pfirst += size;
		}
	
		return result;
	}

	//2
	void reverse(void * first, void * last, size_t size){
	
		byte *pfirst = (byte *) first;
		byte *plast = (byte *) last;
		byte aux[size];
		
		while(pfirst != plast){
			std::memcpy(aux, plast-size, size);
			std::memcpy(plast-size, pfirst, size);
			std::memcpy(pfirst, aux, size);
			pfirst +=size;
			plast -=size;
		}
	}
/*
	//3
	void * copy(const void * first, const void * last, const void * d_first, size_t size){
	
	}
	
	//4
	void * clone(const void * first, const void * last, size_t size){
	
	}

	//5
	bool p(const void *){
	
	}
	
	const void * find_if(const void * first, const void * last, size_t size, Predicate p){
	
	}
	
	//6
	bool eq(const void*, const void *){
	
	}
	
	const void * find(const void * first, const void * last, size_t size, const void * value, Equal eq){
	
	}
	
	//7
	bool all_of(const void * first, const void * last, size_t size, Predicate p){
	
	}
	
	bool any_of(const void * first, const void * last, size_t size, Predicate p){
	
	}
	
	bool none_of(const void * first, const void * last, size_t size, Predicate p){
	
	}
	
	//8
	bool equal(const void * first1, const void * last1, const void * first2){
	
	}
	
	bool equal(const void * first1, const void * last1, const void * first2, const void * last2){
	
	}

	//9
	void * unique(void * first, void * last, size_t size, Equal eq){
	
	}
	
	//10
	void * partition(void * first, void * last, size_t size, Predicate p){
	
	}
*/	
	
}

