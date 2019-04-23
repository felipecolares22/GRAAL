#include "graal.h"
#include <iterator>
#include <array>

int main(){

	std::array<int, 8> test = {3, 18, 90, 37, -17, 78, 65, -2};
	const void * result;
	int * aux;
	
	result = graal::min(test.begin(), test.end(), sizeof(int), graal::cmp);
	aux = (int *)result;
	
	//1
	std::cout<<">>>TEST 1: min:\n" << "Array used in test 1: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	std::cout<<"]\n" << "Result: " << *aux << std::endl<<std::endl;
	
	//2	
	std::cout<<">>>TEST 2: reverse:\n" << "Array used in test 2: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	graal::reverse(test.begin(), test.end(), sizeof(int));
	std::cout<<"]\n" << "Result: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	std::cout<<"]"<<std::endl<<std::endl;

	//3
	std::cout<<">>>TEST 3: copy:\n" << "Array used in test 3: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	graal::copy(test.begin(), test.begin()+3, test.begin()+4, sizeof(int));
	std::cout<<"]\n" << "Result: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	std::cout<<"]"<<std::endl<<std::endl;
	
	//4
	std::cout<<">>>TEST 4: clone:\n" << "Array used in test 4: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	result = graal::clone(test.begin(), test.begin()+5, sizeof(int));
	aux = (int *)result;
	std::cout<<"]\n" << "Result: [ ";
	for(int i=0; i<5; i++){
		std::cout<<*aux<<" ";
		aux++;
	}
	std::cout<<"]"<<std::endl<<std::endl;
	
	//5
	result = graal::find_if(test.begin(), test.end(), sizeof(int), graal::p);
	aux = (int*)result; 

	std::cout<<">>>TEST 5: find_if:\n" << "Array used in test 5: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	std::cout<<"]\n" << "Result: " << *aux << std::endl<<std::endl;

/*	//6 
	result = graal::find(test.begin(), test.begin()+5, sizeof(int), 78, graal::eq);
	aux = (int *)result;

	std::cout<<">>>TEST 6: find:\n" << "Array used in test 6: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	std::cout<<"]\n" << "Result: " << *aux << std::endl<<std::endl;
*/
	//7
	std::cout<<">>>TEST 7: all_of | any_of | none_of:\n" << "Array used in test 7: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	std::cout<<"]\n" << "Result: " << "all_of: " << graal::all_of(test.begin(), test.end(), sizeof(int), graal::p) << std::endl
					 <<	"Result: " << "any_of: " << graal::any_of(test.begin(), test.end(), sizeof(int), graal::p) << std::endl
					 <<	"Result: " << "none_of: " << graal::none_of(test.begin(), test.end(), sizeof(int), graal::p) << std::endl << std::endl;

	//8
	std::cout<<">>>TEST 8: equal:\n" << "Array used in test 8: [ ";
	for(int i=0; i<8; i++){
		std::cout<<test[i]<<" ";
	}
	std::cout<<"]\n" << "Result: " << "equal (f1,l1,f2): " << graal::equal(test.begin(), test.begin()+3, test.begin()+4, sizeof(int)) << std::endl
					 << "Result: " << "equal (f1,l1,f2,l2): " << graal::equal(test.begin(), test.begin()+4, test.begin()+5, test.end(), sizeof(int)) << std::endl;

	return 0;
}
