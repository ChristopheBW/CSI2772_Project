/*Ex2 - Devoir 3 CSI2772A*/

#include "myLinkedList.h"

int main() {
  Evaluation *first = NULL; // Pointer on the first element of the list
                            // the list is empty, so initialization to NULL
  int number = 0;           // number of elements in the linked  list
  int choice;               // choice for the menu

  do {
    cout << endl << endl << "1) Display  of the complete linked list.\n";
    cout << "2) Insert an element\n";
    cout << "3) Remove an element.\n";
    cout << "4) Calculation of the class average.\n";
    cout << "5) Exit the program.\n" << endl << endl;
    cout << "Your choice ??:";
    cin >> choice;

    switch (choice) {
    case 1:
      display(first);
      break;
    case 2:
      first = add(first, number);
      break;
    case 3:
      first = remove(first, number);
      break;
    case 4:
      average(first, number);
      break;
    case 5:
      exit(0);
    default:
      break;
    }
  } while (1);
  return 0;
}

/*
 *add() Function*
 **/
Evaluation *add(Evaluation *p, int &number) {
  int insert_index, grade;
  char name[capacity]; // name: a string to store the name of the student

  // let user to give a valid position for the insertion
  do {
    cout << "After which element you want to insert ? (0 for start): ";
    cin >> insert_index;
  } while (insert_index > number || insert_index < 0); // validation check

  cout << "\n\tEntering the item from the chained list.\n" << endl;
  cout << "Enter the student: ";
  cin.ignore(256, '\n');
  cin.getline(name, capacity);
  cout << "Enter the grade: ";
  cin >> grade;

  // create a pointer point to a Evaluation structure with init the mem space
  struct Evaluation *nEva =
      (struct Evaluation *)malloc(sizeof(struct Evaluation));

  // init the student name
  for (int i = 0; i < capacity; i++) {
    nEva->student[i] = name[i];
  }

  // init the student grade
  nEva->grade = grade;

  // if insert to the first, we don't need to change the p->next but replace p
  if (insert_index == 0) {
    if (number != 0) { // if it is not the only node, there has node next (p)
      nEva->next = p;  // link the head (p) to be the next node
    }
    p = nEva;                    // as the first node, it will be the head (p)
  } else {                       // general condition: insert after some node
    struct Evaluation *pEva = p; // find the previous node
    for (int i = 1; i < insert_index; i++) {
      pEva = pEva->next;
    }

    // link the new node to the list
    nEva->next = pEva->next;
    pEva->next = nEva;
  }

  // after insertion, number of node in the list increaced by 1
  number++;

  // the head node may changed, return to the head p
  return p;
}

/**
 *remove() Function*
 **/

Evaluation *remove(Evaluation *p, int &number) {
  // should never do remove if there has no single node
  if (number == 0) {
    cout << endl << "There are no elements in the list!" << endl;
    return p;
  }

  int remove_index;

  // let user to give a valid position for the deletion
  do {
    cout << "What is the number of the element to delete ?: ";
    cin >> remove_index;
  } while (remove_index > number || remove_index < 1); // validation check

  // if delete the first node, we don't need to change the p->next
  if (remove_index == 1) {
    if (number == 1) { // if the head is the only node
      p = NULL;
    } else {       // if there has node after the head
      p = p->next; // let the next node be the head
    }
  } else {                       // general condition: delete a non-head node
    struct Evaluation *pEva = p; // find the node previous to the node delete
    for (int i = 2; i < remove_index; i++) {
      pEva = pEva->next;
    }

    // delete the node by re-assign the pEva->next to the next next node
    pEva->next = pEva->next->next;
  }

  number--;
  return p;
}

/**
 *display() Function *
 **/
void display(Evaluation *p) {
  Evaluation *c = p;  // copy the pointer to c avoid change the head
  while (c != NULL) { // only print if c exist
    cout << endl << "Student: " << c->student << endl;
    cout << "The grade is: " << c->grade << endl;
    c = c->next; // move to the next node
  }
}

/**
 *average() Function *
 **/
int average(Evaluation *p, int const &nbre) {
  Evaluation *c = p; // copy the pointer to c avoid change the head
  int sum = 0, avg;  // init the sum with 0, avg: average of the grade

  while (c != NULL) { // only calculate if c exist
    sum += c->grade;
    c = c->next; // move to the next node
  }

  avg = sum / nbre; // calculate the average of the grade

  cout << "The average of the class is: " << avg << endl;

  return avg;
}
