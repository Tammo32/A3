#ifndef COSC1076_A3_DATE_H
#define COSC1076_A3_DATE_H

#include <iostream>

class Date{
public:    
    
    // Constructors/DeConstructors
    Date();

    //dayNumber is the number of days since 1/3/0000 
    Date(unsigned long dayNumber);
    Date(const Date& other);
    Date(Date&& other);
    ~Date();

    //Contract: Year, Month, Day should be valid
    //          Year should be a positive number, 
    //          month should be a number in range [1,12], 
    //          date should be a numbers in range [1,31] and valid. 
    Date(unsigned int year, unsigned int month, unsigned int day);

    
    //Getters and setters
    unsigned int getDay();
    unsigned int getMonth();
    unsigned int getYear();
    unsigned long getDayNumber() const;

    void setDate(unsigned long dayNumber);

    //Contract: Year, Month, Day should be valid
    //          Year should be a positive number, 
    //          month should be a number in range [1,12], 
    //          date should be a numbers in range [1,31] and valid. 
    void setDate(unsigned int year, unsigned int month, unsigned int day);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */


    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator>(const Date& other) const; 
    
    double& operator[](const int index);
    double& operator[](const std::string dmy);

    // Date& operator+=(const Date& other);
    Date& operator+=(int value);
    Date operator+(const Date& other) const;
    Date operator-(const Date& other) const;

    Date& operator=(const Date& other);
    Date& operator=(const Date&& other);

    // Increment operator
    // Date& operator++();
    Date operator++(int);

    // Decrement operator    
    // Date& operator--();
    Date operator--(int);
    
private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

std::ostream& operator<<(std::ostream& os, Date& date);
// std::ostream& operator<<(std::ostream& os, Date& date, Date& other);

#endif //COSC1076_A3_DATE_H