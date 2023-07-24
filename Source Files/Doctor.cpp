#include "../Header_Files/Doctor.h"
#include <iostream>
#include <limits>


// Define the constructor for the Doctor class
Doctor::Doctor() : Staff() {
    working_days = 0;
    surgery_count = 0;
}

// Implement the importInfo function for the Doctor class
void Doctor::importInfo() {
    std::cout << "\t===== IMPORT DOCTOR INFORMATION: =====" << std::endl;
    Staff::importInfo();
    std::cout << "\tNumber of working days: ";
    std::cin >> working_days;
    std::cout << "\tSurgery count: ";
    std::cin >> surgery_count;
}

// Implement the displayInfo function for the Doctor class
void Doctor::displayInfo() {
    Staff::displayInfo();
    std::cout << "\tPosition: < DOCTOR >" << std::endl;
    std::cout << "\tNumber of working days: " << working_days << std::endl;
    std::cout << "\tSurgery count: " << surgery_count << std::endl;
    std::cout << "\t ->> Monthly Salary: " << monthly_salary() << std::endl;
}

// Implement the editInfo function for the Doctor class
void Doctor::editInfo() {
    int edit_option;
    do {
        fflush(stdin);
        Staff::editInfo();
        std::cout << "\t 7. Press 5 for Number of working days. " << std::endl;
        std::cout << "\t 8. Press 6 for Surgery count. " << std::endl;
        std::cout << "\tYour choice, press: ";
        std::cin >> edit_option;
        switch (edit_option) {
            case 1:
                fflush(stdin);
                std::cout << "\tNew Staff name: ";
                std::getline(std::cin, staff_name);
                break;
            case 2:
                std::cout << "\tNew Staff ID: ";
                std::cin >> staff_id;
                break;
            case 3:
                std::cout << "\tNew Date of birth (dd/mm/yyyy): ";
                input_Date(date_of_birth);
                break;
            case 4:
                std::cout << "\tNew Time of starting work (dd/mm/yyyy): ";
                input_Date(time_starting);
                break;
            case 5:
                std::cout << "\tNew Phone number: ";
                std::cin >> phone_number;
                break;
            case 6:
                fflush(stdin);
                std::cout << "\tNew Department: ";
                std::getline(std::cin, department);
                break;
            case 7:
                std::cout << "\tNew Number of working days: ";
                std::cin >> working_days;
                break;
            case 8:
                std::cout << "\tNew Surgery count: ";
                std::cin >> surgery_count;
                break;
            case 0:
                std::cout << "\tExiting Edit program..." << std::endl;
                break;
            default:
                std::cout << "\nInvalid choice! Please try again.";
                system("pause");
        }
    } while (edit_option != 0);
}

// Implement the monthly_salary function for the Doctor class
int Doctor::monthly_salary() {
    int salary_of_doctor;
    salary_of_doctor = 200 * working_days + 500 * surgery_count;
    return salary_of_doctor;
}
