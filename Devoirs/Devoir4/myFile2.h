#include <cstdlib>
using namespace std;

class SetInt {
public:
  SetInt() : elem(NULL), size(0){};
  SetInt(int[], int);
  ~SetInt();
  SetInt(const SetInt &); // copy constructor
  void add(int);
  void remove(int);
  bool contains(int);
  int nbElem();
  int *tabElem();

private:
  int *elem;
  int size;
  bool containsIn(int n, int &);
};

inline SetInt::SetInt(int *elem, int size) {
  this->elem = elem;
  this->size = size;
}

inline SetInt::~SetInt() { delete[] elem; }

inline SetInt::SetInt(const SetInt &other) {
  elem = other.elem;
  size = other.size;
}

inline void SetInt::add(int item)
{
  // check if item is already in the list
	if (!contains(item))
	{
    // create a new array to store our new (larger) array
		int* tmp = new int[this->size + 1];
    // copy all elements from the old to the new array
		for (int i = 0; i < this->size; ++i)
		{
			tmp[i] = this->elem[i];
		}
    // finish the list expansion
		this->elem = tmp;
    // add the new item to the list
		this->elem[this->size] = item;
    // increase size after adding
		this->size++;
	}
}

inline void SetInt::remove(int item){
  // check if only only has one element
	if (this->size == 1) {
    // check if this element match item
		if (this->elem[0] == item) {
      // then we have a empty list (which should be NULL)
			this->elem = NULL;
      // and then decrease size
			this->size--;
		} else {
      // otherwise the element doesn't match item
			return;
		}
	} else {
    // create a new array to store our new (smaller) array
		int* temp = new int[this->size - 1];
    // copy all elements from the old to the new array
		for (int i = 0, j = 0; i < this->size; ++i) {
      // if found the item, then skip it
			if (this->elem[i] != item) {
				temp[j++] = this->elem[i];
			}
		}
    // finish decrease the list size
    // and re-assign it to the elem
		this->elem = temp;
    // decrease size after removing
		--(this->size);
	}
}

inline bool SetInt::contains(int element) {
  // check if the list contains element
  for (int i = 0; i < size; ++i) {
    if (elem[i] == element) // found
      return true;
  }

  return false; // not found
}

inline int SetInt::nbElem() { return size; }

inline int *SetInt::tabElem() { return elem; }

inline bool SetInt::containsIn(int n, int& index)
{
	return this->elem[index] == n;
}