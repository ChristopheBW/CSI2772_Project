/*myFile1b.h, Ex1 devoir4 CSI2772A*/

#ifndef MYFILE1B
#define MYFILE1B

#include "myFile1a.h"
#include <iostream>

using namespace std;

class Student {
  int numID;
  int nbCourses;
  int maxCourses;
  int *List_grades;
  Course **List_courses;

public:
  Student(int, int); // constructor

  ~Student(); // destructor

  double average();

  int totalHours();

  bool addCourse(Course *, int);
};

inline Student::Student(int numID, int maxCourses) {
  this->numID = numID;
  this->maxCourses = maxCourses;
  nbCourses = 0;
  List_grades = new int[maxCourses];
  List_courses = new Course *[maxCourses];
}

inline Student::~Student() {
  delete[] List_grades;
  delete[] List_courses;
}

inline double Student::average() {
  double sum = 0;

  for (int i = 0; i < nbCourses; ++i) {
    sum += List_grades[i];
  }

  return sum / nbCourses;
}

inline int Student::totalHours() {
  int sum = 0;

  for (int i = 0; i < nbCourses; ++i) {
    sum += List_courses[i]->getHours();
  }

  return sum;
}

inline bool Student::addCourse(Course *course, int grade) {
  if (nbCourses >= maxCourses)
    return false;

  List_courses[nbCourses] = course;
  List_grades[nbCourses] = grade;
  ++nbCourses;

  return true;
}

#endif
