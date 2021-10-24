/*myFile1a, Ex1 devoir4 CSI2772A*/
#ifndef MYFILE1A
#define MYFILE1A

#include <iostream>
using namespace std;

class Course {
  int num;
  int hours;

public:
  Course(int, int); // constructor
  int getNum();
  int getHours();
};

inline Course::Course(int num, int hours) {
  this->num = num;
  this->hours = hours;
}

inline int Course::getNum() { return num; }

inline int Course::getHours() { return hours; };

#endif
