#include "Patient.h"

#include <iostream>

// Patient constructor
Patient::Patient(std::string name, std::string DOB, int regNo, std::vector<Patient*> adminHist): 
        name(name), DOB(DOB), regNo(regNo), hist(adminHist){}

Patient::~Patient() {

};

std::string Patient::getName() {
    return name;
};

std::string Patient::getDOB() {
    return DOB;
};

int Patient::getRegNo() {
    return regNo;
};

std::vector<Patient*> Patient::getAdminHist() {
    return hist;
};

void Patient::setAdminHist(std::vector<Patient*> adminHist){
    hist = adminHist;
}

// Enables patient data to be writtent to output stream
std::ostream& operator<<(std::ostream& os, Patient& patient){
   os << " ("<< patient.getName() << ", " 
             << patient.getDOB() << ", "
             << patient.getRegNo() << ", ";
            //  << patient.getAdminHist() << " ) ";

   return os;
};