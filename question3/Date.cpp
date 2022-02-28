#include "Date.h"

#include <exception>
#include <string>

Date::Date() : year(1970), month(1), day(1) {}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
    : year(year), month(month), day(day) {}

Date::Date(const Date& other) {
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::Date(Date&& other) {
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::~Date() {}

unsigned int Date::getDay() { return day; }

unsigned int Date::getMonth() { return month; }

unsigned int Date::getYear() { return year; }

unsigned long Date::getDayNumber() const {
    unsigned long m = ((unsigned long)month + 9) % 12;
    unsigned long y = (unsigned long)year - ((unsigned long)month / 10);
    return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 +
           ((unsigned long)day - 1);
}

void Date::setDate(unsigned long dayNumber) {
    unsigned long y = (10000 * ((unsigned long)dayNumber) + 14780) / 3652425;
    unsigned long ddd =
        (unsigned long)dayNumber - (365 * y + y / 4 - y / 100 + y / 400);
    if (ddd < 0) {
        y = y - 1;
        ddd = (unsigned long)dayNumber - (365 * y + y / 4 - y / 100 + y / 400);
    }
    unsigned long mi = (100 * ddd + 52) / 3060;
    unsigned long mm = (mi + 2) % 12 + 1;
    y = y + (mi + 2) / 12;
    unsigned long dd = ddd - (mi * 306 + 5) / 10 + 1;

    this->day = (unsigned int)dd;
    this->month = (unsigned int)mm;
    this->year = (unsigned int)y;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(unsigned long dayNumber) { this->setDate(dayNumber); }

/*                                           */
/* YOU MAY ADD YOUR MODIFICATIONS HERE       */
/*                                           */
bool Date::operator==(const Date& other) const {
    return Date().getYear() == other.year && Date().getMonth() == other.month &&
           Date().getDay() == other.day;
}

bool Date::operator!=(const Date& other) const {
    // return  !(*this == other);
    return !(this->operator==(other));
}

bool Date::operator>(const Date& other) const {
    return  day > other.day &&
            month > other.month &&
            year > other.year;
};

double& Date::operator[](const int index) { return Date()[index]; }

double& Date::operator[](const std::string dmy) {
    int index;
    if (dmy == "day") {
        index = day;
    } else if (dmy == "month") {
        index = month;
    } else if (dmy == "year") {
        index = year;
    } else {
        throw std::runtime_error("Cannot find index");
    }

    return Date()[index];
}

// Date& Date::operator+=(const Date& other) {
//     day += other.day;
//     month += other.month;
//     year += other.year;

//     return *this;
// }

Date& Date::operator+=(int value) {
    day += value;
    // month += value;
    // year += value;

    return *this;
}

Date Date::operator+(const Date& other) const {
    Date d;
    d.day = day;
    d.month = month;
    d.year = year;

    d.setDate(d.getDayNumber() + other.getDayNumber());

    return d;
}

 Date Date::operator-(const Date& other) const {
    Date d;
    d.day = day;
    d.month = month;
    d.year = year;

    //*resultDate - *examDate


    return d;
};

Date& Date::operator=(const Date& other) {
    day = other.day;
    month = other.month;
    year = other.year;

    return *this;
}

Date& Date::operator=(const Date&& other) {
    day = other.day;
    month = other.month;
    year = other.year;

    return *this;
}

// Date& Date::operator++() {
//     day += 1;
//     month += 1;
//     year += 1;

//     return *this;
// }

Date Date::operator++(int) {
    Date copy(*this);
    copy.day += 1;
    copy.month += 1;
    // copy.year += 1;

    return copy;
}

// Date& Date::operator--() {
//     day -= 1;
//     month -= 1;
//     year -= 1;

//     return *this;
// };
    
Date Date::operator--(int) {
    Date copy(*this);
    copy.day -= 1;
    copy.month -= 1;
    copy.year -= 1;

    return copy;
};


//std::cout << "date3: " << date3 << std::endl;
std::ostream& operator<<(std::ostream& os, Date& date){
   os << date.getDay() << "/" 
        << date.getMonth() << "/" 
        << date.getYear();

   return os;
};


/** HAD ISSUES WITH THE PRINTING, HAD IT THEN IT BROKE :( 
 * main.cpp line 33 is the culprit
 * everything else works fine though**/