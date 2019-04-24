#include <iostream>
#include <iterator>
#include <cstring>
#include "graal.h"

using byte = unsigned char;
using Compare = bool (*)(const void*, const void *);
using Predicate = bool (*)(const void*);
using Equal = bool (*)(const void*, const void*);


namespace graal{

	//1
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
	void reverse(void * first, void * last, std::size_t size){
	
		byte *pfirst = (byte *) first;
		byte *plast = (byte *) last;
		byte aux[size];
		
		while(pfirst < plast){
			std::memcpy(aux, plast-size, size);
			std::memcpy(plast-size, pfirst, size);
			std::memcpy(pfirst, aux, size);
			pfirst +=size;
			plast -=size;
		}
	}

	//3
	void * copy(const void * first, const void * last, const void * d_first, std::size_t size){
		
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;
		byte *pd_first = (byte *)d_first;

		void *result;

		while(pfirst < plast){
			std::memcpy(pd_first, pfirst, size);
			pfirst += size;
			pd_first += size;
		}

		result = (void *)pd_first;
		return result;
	}
			
	//4
	void * clone(const void * first, const void * last, std::size_t size){
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
	const void * find_if(const void * first, const void * last, std::size_t size, Predicate p){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;

		while(pfirst < plast){
			if(p(pfirst)){
				return pfirst;
			}
			pfirst += size;
		}
		return plast;
	}


	//6
	const void * find(const void * first, const void * last, std::size_t size, const void * value, Equal eq){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;

		while(pfirst < plast){
			if(eq(pfirst, value)){
				return pfirst;
			}
			pfirst +=size;
		}
		return plast;
	}


	//7
	bool all_of(const void * first, const void * last, std::size_t size, Predicate p){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;

		while(pfirst < plast){
			if(p(pfirst) == false) return false;
			pfirst += size;
		}
		return true;
	}
	
	bool any_of(const void * first, const void * last, std::size_t size, Predicate p){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;

		while(pfirst < plast){
			if(p(pfirst)) return true;
			pfirst += size;
		}
		return false;
	}
	
	bool none_of(const void * first, const void * last, std::size_t size, Predicate p){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;

		while(pfirst < plast){
			if(p(pfirst)) return false;
			pfirst += size;
		}
		return true;
	}


	//8
	bool equal(const void * first1, const void * last1, const void * first2, std::size_t size, Equal eq){
		byte *pfirst = (byte *)first1;
		byte *plast = (byte *)last1;
		byte *pfirst2 = (byte *)first2;
		int aux = plast-pfirst;

		for(int i=0; i<aux; i+=size){
			if(eq(pfirst,pfirst2) == false) return false;
			else{
				pfirst += size;
				pfirst2 += size;
			}
		}
		return true;
	}
	
	bool equal(const void * first1, const void * last1, const void * first2, const void * last2, std::size_t size, Equal eq){
		byte *pfirst = (byte *)first1;
		byte *plast = (byte *)last1;
		byte *pfirst2 = (byte *)first2;
		byte *plast2 = (byte *)last2;

		while(pfirst < plast and pfirst2 < plast2){
			if(eq(pfirst,pfirst2) == false) return false;
			if(eq(pfirst,plast-size) and eq(pfirst2,plast2-size)){
				return true;
			}
			pfirst += size;
			pfirst2 += size;
		}
		return false;
	}

/*
	//9
	void * unique(void * first, void * last, std::size_t size, Equal eq){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;
		byte *aux = pfirst+size;

		while(pfirst < plast){
			
		
		}
		
	}
*/

	//10
	void * partition(void * first, void * last, std::size_t size, Predicate p){
		byte *pfirst = (byte *)first;
		byte *plast = (byte *)last;
		byte *fast = pfirst + size;
		byte aux[size];

		while(pfirst < plast){
			if(p(pfirst) == false){
				while(true){
					if(fast >= plast) return pfirst;
					if(p(fast) == true){
						std::memcpy( aux, fast, size );
             	  		std::memcpy( fast, pfirst, size );
               			std::memcpy( pfirst, aux, size );
               			
						break;
					}
					fast += size;
				}
			}
			pfirst += size;
		}
	}
	
/*
	//11
	void sort(void * first, std::size_t count, std::size_t size, Compare cmp){
		byte *pfirst = (byte *)first;
		byte * 
		byte aux[size];
	
	}
*/

}


