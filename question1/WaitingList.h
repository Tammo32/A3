#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include "Patient.h"

class WaitingList : public Patient {
public:   
    // Constructor
    WaitingList();

    // Deconstructor
    ~WaitingList();

    int getLength();
    void addPatientEnd(Patient* p);
    

private:
    
};

#endif //WAITING_LIST_H