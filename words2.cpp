/// Nick Wang 2/2/2020

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab04_2
{
  /**
   * construct an object with initial_capacity
   *
   * @param initial_capacity the max number of string the user wish to store in
   * data array before resizing
   */
	Words::Words(unsigned int initial_capacity) {
		used = 0;
		capacity = initial_capacity;
    data = new string[capacity];
	}


  /**
   * construct an object by deep copying the source object
   *
   * @param source the source object this will copy from
   */
  Words::Words(const Words &source){
    this->used = source.used;
    this->capacity = source.capacity;
    data = new string[capacity];
    ///copy over strings
    for(int i = 0; i < used; i++)
      data[i] = source.data[i];
  }

  /**
   * destructor
   */
  Words::~Words(){
      delete [] data;
  }

  /**
   * append a new string to the data array.
   *
   * @param word the string to be appended
   */
	void Words::append(string word) {
    ///checks if array is full
    if(used >= capacity){
      ///new array with double capacity
      string* temp = new string[capacity*2];
      capacity *= 2;
      ///point pointer in temp to memory address stored in data array
      for(int i = 0; i < used; i++)
        temp[i] = data[i];
      data = temp;
    }
    ///append word
    data[used] = word;
    ++used;
	}

  /**
   * return a mutable reference to string stored at index
   *
   * @param index the zero indexed address in the data array
   * @returns a mutable reference to the string stored at index
   */
	string& Words::operator[] (unsigned int index) {
		assert(index < used);
		return data[index];
	}


  /**
   * overrides the default assignment operator. Performs a deep copy of source.
   *
   * @param source the reference to source object to be assigned
   * @returns the reference to this, which is a deep copy of source
   */
  Words& Words::operator=(const Words &source){
    ///if self assignment, return this
    if(this == &source)
      return *this;
    ///updates members of this
    this->used = source.used;
    ///if this has different capacity from source, allocate a new array with
    ///capacity of source and copies over the elements
    if(this->capacity != source.capacity){
      string* temp = new string[source.capacity];
      data = temp;
    }
    this->capacity = source.capacity;
    ///copy over each elements in source.data array
    for(int i = 0; i < source.used; i++)
      data[i] = source.data[i];
    return *this;
  }

  /**
   * @returns the number of strings stored in data
   */
	unsigned int Words::size() const {
		return used;
	}

  /**
   * @returns the max number of strings can be stored in data array before resizing
   */
	unsigned int Words::get_capacity() const {
		return capacity;
	}

  /**
   * returns an immutable copy of the string that is stored at index
   *
   * @param index the zero based address of data array
   * @returns a copy of the string that is stored at index
   */
	string Words::operator[] (unsigned int index) const {
		assert(index < used);
		return data[index];
	}

}
