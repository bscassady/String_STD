#include"String.h"
#include<cstddef>

size_t String::MAX_SIZE_=100;

String::String(size_t Arbitrary_value_of_capacity){
  capacity_=Arbitrary_value_of_capacity;
  size_ = 4;
  str_=new char[capacity_];
  str_[0]='T';
  str_[1]='o';
  str_[2]='t';
  str_[3]='o';
  str_[4]='\0';
}

String::~String(){
  delete[] str_; 
}


void String::reserve (size_t n){
  if (capacity_< n){
    char* strbis=str_;
    str_=new char[n+1];
    for (size_t i=0;i<=size_;++i){
      str_[i]=strbis[i];    
    }
    delete strbis;
    capacity_=n;    
  }
  
}

size_t String::capacity(){
  return capacity_;
}
bool String::empty() const{
  return size_==0;
}

size_t String::size() const{
  return size_;
}














