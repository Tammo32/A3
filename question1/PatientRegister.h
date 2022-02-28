#ifndef PATIENT_REGISTER_H
#define PATIENT_REGISTER_H

#include "Patient.h"

class PatientRegister : public Patient {
public:   
    // Empty PatientRegister constructor
    PatientRegister();

    // Deconstructor
    ~PatientRegister();

    void addPatient();
    void removePatient();
    bool checkPatient(); // check if in register (by regNo)
    int retrievePatient();

    // Allow to retrieve a patient by registration number
    // char& operator[](const int index);
    // unsigned int& operator[](const char channel);


private:
    
};

#endif //PATIENT_REGISTER_H