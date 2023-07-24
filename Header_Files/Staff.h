#ifndef STAFF_H
#define STAFF_H

#include <string>

struct Date {
    int Day, Month, Year;
};

void input_Date(Date& d);
void output_Date(Date d);

class Staff {
protected:
    std::string staff_name;
    std::string staff_id;
    Date date_of_birth;
    Date time_starting;
    std::string phone_number;
    std::string department;

public:
    Staff();

    std::string get_staff_name() const;
    std::string get_staff_id() const;
    std::string get_phone_number() const;
    std::string get_department() const;
    Date get_date_of_birth() const;
    Date get_time_starting() const;

    virtual void importInfo();
    virtual void displayInfo();
    virtual void editInfo();
    virtual int monthly_salary() = 0;
};

#endif // STAFF_H
