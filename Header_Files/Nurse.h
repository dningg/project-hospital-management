#ifndef NURSE_H
#define NURSE_H

#include "Staff.h"

class Nurse : public Staff {
private:
    int working_days;
    int night_shifts;

public:
    Nurse();

    void importInfo();
    void displayInfo();
    void editInfo();
    int monthly_salary();
};

#endif // NURSE_H
