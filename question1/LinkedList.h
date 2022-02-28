#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int getLength();
   void addPatientEnd(Patient* p);
   Patient* getPatientAtIndex(int index);
   // Patient* placePatient(Patient* patient);
   Patient* remove_front();
   void remove_back();
   void removePatientAtIndex(int index);

private:
   Node* head;
   Node* tail;
   int length;
};

#endif //LINKEDLIST_H