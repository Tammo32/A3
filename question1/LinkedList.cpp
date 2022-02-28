#include "LinkedList.h"
#include <iostream>
#include <limits>

//constructor
LinkedList::LinkedList() {
   head = nullptr;
   tail = nullptr;
   length = 0;
}

//destructor
LinkedList::~LinkedList() {
   delete head;
   delete tail;
}

//Returns length of list
int LinkedList::getLength() {
   return length;
}

//places a tile at the end of the list
void LinkedList::addPatientEnd(Patient* p) {
   Node* temp = new Node(p, nullptr); // on the heap (to be deleted)
   temp->patient = p;
   temp->next = nullptr;

   if (head == nullptr) {
      head = temp;
      tail = temp;
   }
   else {
      tail->next = temp;
      tail = temp;
   }
   length++;
}

//returns tile at index
Patient* LinkedList::getPatientAtIndex(int index) {
   int count = 0;
   Node* current = head;
   // int returnValue = 0;
   Patient* returnValue = nullptr;
   if(index >= 0 && index < getLength()) {
      while(count < index) {
         ++count;
         current = current->next;
      }
      returnValue = current->patient;
   }
   return returnValue;
}

//returns a patient object and deletes from the list
// Patient* LinkedList::placePatient(Patient* patient){ //removes tile from list to go onto board
//    int i = 0;
//    Patient* placedPatient = nullptr;
//    Patient* temp = getPatientAtIndex(0);

//    //loop until tile is found or searched through the entire hand
//    bool breakLoop = false;
//    while(breakLoop == false){

//       //if the the tile has the same colour and shape as temp
//       if(patient->colour == temp->colour && tile->shape == temp->shape){
//          //set placedTile object to the searched for tile
//          placedPatient = new Patient(getPatientAtIndex(i)->colour, getPatientAtIndex(i)->shape);

//          if(i != 5){
//             removePatientAtIndex(i);
//          } else{
//             remove_back();
//          }
//          breakLoop = true;
//       }
//       i++;
//       temp = getPatientAtIndex(i);
      
//       //break the loop if tile cant be found
//       if (i > this->getLength()){
//          breakLoop = true;
//       }
//    }

//    if (placedPatient == nullptr){
//       return nullptr;
//    }
//    return placedPatient;
// }

//removes a tile from the front of the list
Patient* LinkedList::remove_front(){
   if(head != nullptr){
      Node* toRemove = head;
      head = head->next;
      length--;
      return toRemove->patient;
      // delete toRemove;
   }else{
      throw std::runtime_error("Nothing to remove");
   }
}

//removes a tile from the back of the list
void LinkedList::remove_back(){
   if(head != nullptr){
      Node* current = head;
      //pre should point to node before current;
      Node* prev = nullptr;

      while(current->next != nullptr){
         prev = current;
         current = current->next;
      }

      if(prev == nullptr){
         head = nullptr;
      }else{
         prev->next = nullptr;
         tail = prev;
      }
      length--;
      delete current->patient;
      delete current;
   }
}


//removes a tile from the list at index
void LinkedList::removePatientAtIndex(int index){
   if(index >= 0 && index < getLength()){
      if(head != nullptr){
         int counter = 0;
         Node* current = head;
         //pre should point to node before current;
         Node* prev = nullptr;
         while(counter != index){
               ++counter;
               prev = current;
               current = current->next;
         }
         if(prev == nullptr){
               head = current->next;
         }else{
               prev->next = current->next;
         }
         length--;
         delete current->patient;
         delete current;
      }
   }
}