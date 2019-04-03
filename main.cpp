#include <iostream>
#include"String.h"
int main(){


String* test1= new String(20);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(10);
std::cout << (test1->capacity()==10) << std::endl;
test1->reserve(20);
std::cout << (test1->capacity()==20) << std::endl;
std::cout << not test1->empty()<< std::endl;
return 0;
}
