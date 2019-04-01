#include"String.h"
#include<cstddef>

size_t String::MAX_SIZE_=100;

String::String(size_t Arbitrary_value_of_capacity){
  capacity_=Arbitrary_value_of_capacity;
  size_ = 4;
  char array[5]={'T','o','t','o','\0'};
  str_=array;
}

