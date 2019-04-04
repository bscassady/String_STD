#include <iostream>
#include"String.h"
int main(){


String* test1= new String(20);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(10);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(30);
std::cout << (test1->capacity()==30) << std::endl;
std::cout << not test1->empty()<< std::endl;


//Test size()
std::cout << test1->size()<< std::endl;



delete test1;

return 0;
}
