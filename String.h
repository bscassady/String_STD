#include<cstddef>

#ifndef STRING_ 
#define STRING_

class String{
  public :
  //Constructors
  String(size_t Arbitrary_value_of_capacity);// Trivial Constructor with Arbitrary_value_of_capacity as parameter because we don't know how to get it yet


  //Destructor
  //~String();

  //getters
  
  //setters
  
  //methods
  void reserve (size_t);
  
  protected : 
  //attributes
  static size_t MAX_SIZE_;
  size_t size_;
  size_t capacity_;
  char* str_;
  
  
    
    


};
#endif //STRING_
