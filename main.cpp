#include <iostream>
#include"String.h"
int main(){


String* test1= new String(20);
String* test2 = new String("Character sequence test");
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(10);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(30);
std::cout << (test1->capacity()==30) << std::endl;
std::cout << not test1->empty()<< std::endl;


//Test size()
std::cout << (test1->size()==4)<< std::endl;



delete test1;
delete test2;
return 0;
}
