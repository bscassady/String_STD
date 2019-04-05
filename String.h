#include<cstddef>

#ifndef STRING_ 
#define STRING_

class String{
  public :
  //Constructors
  String(size_t Arbitrary_value_of_capacity);// Trivial Constructor with Arbitrary_value_of_capacity as parameter because we don't know how to get it yet
  String(const char* s);

  //Destructor
  ~String();//Destroys the string object. This deallocates all the storage capacity allocated by the string using its allocator.

  //Operator
  String& operator= (const char* s);//Assigns a new value to the string, replacing its current contents with a pointer to a null-terminated sequence of characters passed as  parameter. The sequence is copied as the new value for the string.
  
  //getters
  size_t capacity();//Returns the size of the storage space currently allocated for the string, expressed in terms of bytes. This capacity is not necessarily equal to the string length. It can be equal or greater, with the extra space allowing the object to optimize its operations when new characters are added to the string.

  size_t size() const;//Returns the length of the string, in terms of bytes.

  size_t length() const;
  
  size_t max_size() const;//Returns the maximum length of the string, in terms of bytes. Arbitrarily equals 100.
  //setters
  
  //methods
  bool empty() const;//Returns whether the string is empty (i.e. whether its length is 0).

  
  void reserve (size_t n);//Requests that the string capacity be adapted to a planned change in size to a length of up to n characters. If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters (or greater). In all other cases, it is taken as a non-binding request to shrink the string capacity: the container implementation is free to optimize otherwise and leave the string with a capacity greater than n.

  
  protected : 
  //attributes
  static size_t MAX_SIZE_;
  size_t size_;
  size_t capacity_;
  char* str_;
  
  
    
    


};
#endif //STRING_
