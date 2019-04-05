#include <iostream>
#include"String.h"
int main(){


String* test1= new String(20);
const char* s="Character sequence test";
String* test2 = new String(s);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(10);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(30);
std::cout << (test1->capacity()==30) << std::endl;
std::cout << not test1->empty()<< std::endl;


//Test size()
std::cout << (test1->size()==4)<< std::endl;
//Test length()
std::cout<<(test1->length()==4)<<std::endl;
//Test operator=(char*)
*test1 = "bou";
std::cout<<(test1->length()==3)<<std::endl;
*test1= "baracuda";
std::cout<<(test1->length()==8)<<std::endl;


//Test operator+(String)
String test3="baudruche";

String test4=test3+*test1;
std::cout<<(test4.length()==17)<< (test4.capacity()==17) <<std::endl;

//Test max_size()
std::cout<<(test1->max_size()==100)<<std::endl;
std::cout<<(test2->max_size()==100)<<std::endl;

//Test limitation size
char c[]       ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
test3=c;
std::cout<<(test3.size()==100)<<std::endl;
test3.reserve(10000);
std::cout<<(test3.size()==100)<<std::endl;
String* test5=new String(c);
std::cout<<(test5->size()==100)<<std::endl;
String test6 = test3+*test5;
std::cout<<(test6.size()==100)<<std::endl;



delete test1;
delete test2;
delete test5;
return 0;
}
