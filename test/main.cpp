#include "graal.h"
#include <iterator>
#include <array>

int main(){

	std::array<int, 8> test11 = {3, 18, 90, 37, -17, 78, 65, -2};
	const void * first;
	const void * last;
	const void * result;
	int * test;
	std::size_t size = 4;
	first = test11.begin();
	last = test11.end();
	
	result = graal::min(first, last, size, graal::cmp);
	test = (int *)result;
	
	//1
	std::cout<<">>>TEST 1: min:\n" << "Array used in test 1: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test11[i]<<" ";
	}
	std::cout<<"]\n" << "Result: " << *test << std::endl<<std::endl;
	
	//2
	void *first2 = (void*)first;
	void *last2 = (void*)last;
	
	std::cout<<">>>TEST 2: reverse:\n" << "Array used in test 2: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test11[i]<<" ";
	}
	graal::reverse(first2, last2, size);
	std::cout<<"]\n" << "Result: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test11[i]<<" ";
	}
	std::cout<<"]"<<std::endl<<std::endl;

	//3
	std::cout<<">>>TEST 3: copy:\n" << "Array used in test 3: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test11[i]<<" ";
	}
	graal::copy(first, test11.begin()+3, test11.begin()+4, size);
	std::cout<<"]\n" << "Result: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test11[i]<<" ";
	}
	std::cout<<"]"<<std::endl;

	
	return 0;
}
