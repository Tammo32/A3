#ifndef NODE_H
#define NODE_H

#include "Patient.h"

class Node {
public:

   Node(Patient* patient, Node* next);
   Node(Node& other);

   Patient* patient;
   Node* next;
};

#endif // NODE_H
