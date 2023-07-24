#ifndef DOCTOR_H
#define DOCTOR_H

#include "Staff.h"

class Doctor : public Staff {
private:
    int working_days;
    int surgery_count;

public:
    Doctor();

    void importInfo();
    void displayInfo();
    void editInfo();
    int monthly_salary();
};

#endif // DOCTOR_H
