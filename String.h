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
  size_t capacity();
  //setters
  
  //methods

  // Capacity: change the capacity_ to n .If n is biger than the curent capacity_, change the storage space dedicated to the char array.
  void reserve (size_t n);

  
  protected : 
  //attributes
  static size_t MAX_SIZE_;
  size_t size_;
  size_t capacity_;
  char* str_;
  
  
    
    


};
#endif //STRING_
