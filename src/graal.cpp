#include <iostream>
#include <iterator>
#include <cstring>
#include "graal.h"

using byte = unsigned char;
using Compare = bool (*)(const void*, const void *);
using Predicate = bool (*)(const void*);

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

	//3
	void * copy(const void * first, const void * last, const void * d_first, size_t size){
		
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;
		byte *pd_first = (byte *)d_first;

		void *result;

		while(pfirst <= plast){
			std::memcpy(pd_first, pfirst, size);
			pfirst += size;
			pd_first += size;
		}

		result = (void *)pd_first;
		return result;
	}
			
	//4
	void * clone(const void * first, const void * last, size_t size){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;
		int aux_arr_size = (plast-pfirst);
		byte *aux_arr = new byte[aux_arr_size];

		void *result = &aux_arr[0];

		while(pfirst < plast){
			std::memcpy(aux_arr, pfirst, size);
			pfirst += size;
			aux_arr += size;
		}
		return result;
	}


	//5
	bool p(const void * pnum){
		int* aux = (int *) pnum;
		return *aux > 1; 	
	}
	
	const void * find_if(const void * first, const void * last, size_t size, Predicate p){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;

		while(pfirst < plast){
			if(p(pfirst)){
				return pfirst;
			}
			pfirst += size;
		}
		pfirst -=size;
		return pfirst;
	}

/*	
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

