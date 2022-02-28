#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "LinkedList.h"

// struct tm
// {
//     int tm_mday; // day of month from 1 to 31
//     int tm_mon; // month of year from 0 to 11
//     int tm_year; // year since 1900
// };

class Patient {
public:
    // Patient constructor
    Patient(std::string name, std::string DOB, int regNo, std::vector<Patient*> adminHist);

    //Deconstructor
    ~Patient();

    std::string getName();
    std::string getDOB();
    int getRegNo(); 
    std::vector<Patient*> getAdminHist();
    void setAdminHist(std::vector<Patient*> adminHist);

private:
    std::string name;
    std::string DOB;
    int regNo; //unique but don't have to check
    // LinkedList* hist;   

    // the adminHistory
    std::vector<Patient*> hist;
  

};

// Write the string to standard output
std::ostream& operator<<(std::ostream& os, Patient& patient);

#endif //PATIENT_H