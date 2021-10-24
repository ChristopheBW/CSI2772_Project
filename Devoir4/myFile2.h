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

inline void SetInt::add(int element) {
  const int INCREASE_SIZE = 5;

  // check if the element is already in the list
  for (int i = 0; i < size; ++i) {
    if (elem[i] == element) {
      return;
    }
  }

  // check if the list need expansion
  if (size % INCREASE_SIZE == 0) {
    int *larger = new int[size + INCREASE_SIZE];

    // copy the old list to the larger list
    for (int i = 0; i < size; ++i) {
      larger[i] = elem[i];
    }

    delete[] elem; // free the memory of old elem
    elem = larger; // complete list expansion
  }

  elem[size++] = element;
  return;
}

inline void SetInt::remove(int element) {
  const int DECREASE_SIZE = 5;

  // try to find the element in the list
  for (int i = 0; i < size; ++i) {
    if (elem[i] == element) { // found
      for (int j = i; j < size - 1; ++j) {
        elem[j] = elem[j + 1];
      }
      --size;

      // check if the list can be reduction
      if (size % DECREASE_SIZE == 0) {
        if (size == 0) // if the list doesn't contains any element,
          elem = NULL; // then it should be null.
        else {         // otherwise start the list reduction
          int *smaller = new int[size];

          // copy the old list to the smaller list
          for (int i = 0; i < size; ++i) {
            smaller[i] = elem[i];
          }

          delete[] elem;  // free the memory of old elem
          elem = smaller; // complete list reduction
        }
      }
      return;
    }
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
