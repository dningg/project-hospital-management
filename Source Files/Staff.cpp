#include "../Header_Files/Staff.h"
#include <iostream>
#include <limits>


// Define the constructor for the Staff class
Staff::Staff() {
    staff_name = "";
    staff_id = "";
    date_of_birth = {0, 0, 0};
    time_starting = {0, 0, 0};
    phone_number = "";
    department = "";
}

// Implement the getter functions
std::string Staff::get_staff_name() const {
    return staff_name;
}

std::string Staff::get_staff_id() const {
    return staff_id;
}

std::string Staff::get_phone_number() const {
    return phone_number;
}

std::string Staff::get_department() const {
    return department;
}

Date Staff::get_date_of_birth() const {
    return date_of_birth;
}

Date Staff::get_time_starting() const {
    return time_starting;
}

// Implement the importInfo function
void Staff::importInfo() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\tStaff name: ";
    std::getline(std::cin, staff_name);
    std::cout << "\tStaff ID: ";
    std::cin >> staff_id;
    std::cout << "\tDate of birth (dd/mm/yyyy): ";
    input_Date(date_of_birth);
    std::cout << "\tTime of starting work (dd/mm/yyyy): ";
    input_Date(time_starting);
    std::cout << "\tPhone number: ";
    std::cin >> phone_number;
    std::cin.ignore();
    std::cout << "\tDepartment: ";
    std::getline(std::cin, department);
}

// Implement the displayInfo function
void Staff::displayInfo() {
    std::cout << "\tStaff name: " << staff_name << std::endl;
    std::cout << "\tStaff ID: " << staff_id << std::endl;
    std::cout << "\tDate of birth: ";
    output_Date(date_of_birth);
    std::cout << "\n\tTime of starting work: ";
    output_Date(time_starting);
    std::cout << "\n\tPhone number: " << phone_number << std::endl;
    std::cout << "\tDepartment: " << department << std::endl;
}

// Implement the editInfo function
void Staff::editInfo() {
    system("cls");
    std::cout << "\t===== WHAT STAFF INFORMATION DO YOU WANT TO EDIT ? =====" << std::endl;
    std::cout << "\t 0. Press 0 for Exit. " << std::endl;
    std::cout << "\t 1. Press 1 for Staff name. " << std::endl;
    std::cout << "\t 2. Press 2 for Staff ID. " << std::endl;
    std::cout << "\t 3. Press 3 for Date of birth. " << std::endl;
    std::cout << "\t 4. Press 4 for Time of starting work. " << std::endl;
    std::cout << "\t 5. Press 5 for Phone number." << std::endl;
    std::cout << "\t 6. Press 6 for Department." << std::endl;
}


// Define the input_Date function
void input_Date(Date& d) {
    bool validInput = false;
    
    while (!validInput) {
        std::cout << "\n\t\tDay: ";
        std::cin >> d.Day;
        if (std::cin.fail()) {
            std::cout << "\t\tInvalid input. Please enter an integer value.\n";
            std::cin.clear();                      // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining characters in the input buffer
            continue;
        }
        std::cout << "\t\tMonth: ";
        std::cin >> d.Month;

        if (std::cin.fail()) {
            std::cout << "\t\tInvalid input. Please enter an integer value.\n";
            std::cin.clear();                      // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining characters in the input buffer
            continue;
        }
        std::cout << "\t\tYear: ";
        std::cin >> d.Year;

        if (std::cin.fail()) {
            std::cout << "\t\tInvalid input. Please enter an integer value.\n";
            std::cin.clear();                      // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining characters in the input buffer
            continue;
        }
        validInput = true;
    }
}

// Define the output_Date function
void output_Date(Date d) {
    std::cout << d.Day << "/" << d.Month << "/" << d.Year;
}
