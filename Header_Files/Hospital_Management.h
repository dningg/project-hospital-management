#ifndef HOSPITAL_MANAGEMENT_H
#define HOSPITAL_MANAGEMENT_H

#include "Staff.h"
#include "Doctor.h"
#include "Nurse.h"
#include <vector>

class Hospital_Management {
private:
    std::vector<Staff*> staff_list;

public:
    void import_staff();
    void display_staff_list();
    void edit_staff_info();
    void search_staff();
    long total_salary();
    int staff_list_size();
};

#endif // HOSPITAL_MANAGEMENT_H
