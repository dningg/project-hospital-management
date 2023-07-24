#include "../Header_Files/Hospital_Management.h"
#include <iostream>

void Hospital_Management::import_staff() {
    Staff* new_staff;
    int option;
    do {
        system("cls");
        std::cout << "\t========== POSITION OF HOSPITAL: ==========" << std::endl;
        std::cout << "\t 0. Press 0 for Exit. " << std::endl;
        std::cout << "\t 1. Press 1 for NEW DOCTOR. " << std::endl;
        std::cout << "\t 2. Press 2 for NEW NURSE. " << std::endl;
        std::cout << "\tYour choice, press: ";
        std::cin >> option;
        switch (option) {
            case 1:
                system("cls");
                new_staff = new Doctor();
                new_staff->importInfo();
                staff_list.push_back(new_staff);
                break;
            case 2:
                system("cls");
                new_staff = new Nurse();
                new_staff->importInfo();
                staff_list.push_back(new_staff);
                break;
            case 0:
                std::cout << "\tExiting Import program..." << std::endl;
                break;
            default:
                std::cout << "\nInvalid choice! Please try again.";
                system("pause");
        }
    } while ((option != 0));
    system("cls");
    std::cout << "\t Information about " << staff_list.size() << " staffs is available !" << std::endl;
    std::cout << "\t Please check the staff information with the 'Display Staffs List' function in MENU !" << std::endl;
    system("pause");
}

void Hospital_Management::display_staff_list() {
    std::cout << "\t Information about " << staff_list.size() << " staffs is available !" << std::endl;
    int display_option;
    do {
        system("cls");
        std::cout << "\t========== TYPE OF EMPLOYEES YOU WANT TO SEARCH: ==========" << std::endl;
        std::cout << "\t 0. Press 0 to Exit." << std::endl;
        std::cout << "\t 1. Press 1 for Doctor List. " << std::endl;
        std::cout << "\t 2. Press 2 for Nurse List. " << std::endl;
        std::cout << "\t 3. Press 3 for All Staff List." << std::endl;
        std::cout << "\tYour choice: ";
        std::cin >> display_option;
        switch (display_option) {
            case 1: {
                system("cls");
                std::cout << "\t========== DOCTOR LIST ==========" << std::endl;
                int count = 0;
                for (int i = 0; i < staff_list.size(); i++) {
                    Doctor* doctor = dynamic_cast<Doctor*>(staff_list[i]);
                    if (doctor) {
                        std::cout << "\t-----[ Doctor no." << ++count << " ]-----" << std::endl;
                        doctor->displayInfo();
                    }
                }
                std::cout << "\n\t=====[ Total number of doctors: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                std::cout << "\t========== NURSE LIST ==========" << std::endl;
                int count = 0;
                for (int i = 0; i < staff_list.size(); i++) {
                     Nurse* nurse = dynamic_cast<Nurse*>(staff_list[i]);
                    if (nurse) {
                        std::cout << "\t-----[ Nurse no." << ++count << " ]-----" << std::endl;
                        nurse->displayInfo();
                    }
                }
                std::cout << "\n\t=====[ Total number of nurses: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                std::cout << "\t========== ALL STAFF LIST ==========" << std::endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    std::cout << "\t-----[ Staff no." << i + 1 << " / Total input: " << staff_list.size() << " ]-----" << std::endl;
                    staff_list[i]->displayInfo();
                }
                system("pause");
                break;
            }
            case 0:
                break;
            default:
                std::cout << "\n\tPlease press 0, 1, 2, or 3 only! \n\tTry again: ";
                system("pause");
        }
    } while (display_option != 0);
}

void Hospital_Management::edit_staff_info() {
    int staff_edited;
    std::cout << "\t========== ALL STAFF LIST ==========" << std::endl;
    for (int i = 0; i < staff_list.size(); i++) {
        std::cout << "\t-----[ Staff no." << i + 1 << " / Total input: " << staff_list.size() << " ]-----" << std::endl;
        staff_list[i]->displayInfo();
    }
    std::cout << "\n\n\t===== WHICH STAFF MEMBER DO YOU WANT TO EDIT/DELETE FROM THE LIST? =====" << std::endl;
    std::cout << "\tChoose a staff member from 1 to " << staff_list.size() << ": ";
    std::cin >> staff_edited;
    while (staff_edited < 1 || staff_edited > staff_list.size()) {
        std::cout << "\tPlease re-enter a number from 1 to " << staff_list.size() << ": ";
        std::cin >> staff_edited;
    }
    Staff* staff = staff_list[staff_edited - 1];
    system("cls");
    std::cout << "\t-----[ STAFF EDITED ]-----" << std::endl;
    staff->displayInfo();

    int edit_option;
    std::cout << "\n\t===== SELECT ACTION =====" << std::endl;
    std::cout << "\t 1. Edit staff information." << std::endl;
    std::cout << "\t 2. Remove staff member." << std::endl;
    std::cout << "\tYour choice, press: ";
    std::cin >> edit_option;

    if (edit_option == 1) {
        staff->importInfo();
        std::cout << "\n\tPlease check the staff information you just edited using the 'Display Staff List' function in the MENU!" << std::endl;
    }
    else if (edit_option == 2) {
        system("cls");
        staff_list.erase(staff_list.begin() + staff_edited - 1);
        delete staff;
        std::cout << "\n\tThe staff member has been deleted." << std::endl;
        std::cout << "\n\tAfter deleting, information about " << staff_list.size() << " staff members is available!" << std::endl;
        std::cout << "\tPlease check the staff information using the 'Display Staff List' function in the MENU!" << std::endl;
    }
    else {
        std::cout << "\n\tInvalid option! Please try again." << std::endl;
    }
}

void Hospital_Management::search_staff() {
    int search_option;
    do {
        system("cls");
        std::cout << "\t========== SEARCH STAFF ==========" << std::endl;
        std::cout << "\t 0. Press 0 to Exit" << std::endl;
        std::cout << "\t 1. Press 1 to Search by Staff name. " << std::endl;
        std::cout << "\t 2. Press 2 to Search by Staff ID. " << std::endl;
        std::cout << "\t 3. Press 3 to Search by Date of birth. " << std::endl;
        std::cout << "\t 4. Press 4 to Search by Time of starting work. " << std::endl;
        std::cout << "\t 5. Press 5 to Search by Phone number." << std::endl;
        std::cout << "\t 6. Press 6 to Search by Department." << std::endl;
        std::cout << "\tYour choice: ";
        std::cin >> search_option;

        switch (search_option) {
            case 1: {
                std::string search_name;
                std::cout << "\tEnter Staff name: ";
                std::cin.ignore();
                getline(std::cin, search_name);
                int count = 0;
                system("cls");
                std::cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << std::endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_staff_name().find(search_name) != std::string::npos) {
                        std::cout << "\t-----[ Staff no." << ++count << " ]-----" << std::endl;
                        staff_list[i]->displayInfo();
                    }
                }
                std::cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                std::string search_id;
                std::cout << "\tEnter Staff ID: ";
                std::cin >> search_id;
                int count = 0;
                system("cls");
                std::cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << std::endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_staff_id() == search_id) {
                        std::cout << "\t-----[ Staff no." << ++count << " ]-----" << std::endl;
                        staff_list[i]->displayInfo();
                    }
                }
                std::cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                Date search_birth;
                std::cout << "\tEnter Date of birth: ";
                input_Date(search_birth);
                int count = 0;
                system("cls");
                std::cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << std::endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    Date birth = staff_list[i]->get_date_of_birth();
                    if (birth.Day == search_birth.Day && birth.Month == search_birth.Month && birth.Year == search_birth.Year) {
                        std::cout << "\t-----[ Staff no." << ++count << " ]-----" << std::endl;
                        staff_list[i]->displayInfo();
                    }
                }
                std::cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                Date search_start;
                std::cout << "\tEnter Time of starting work: ";
                input_Date(search_start);
                int count = 0;
                system("cls");
                std::cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << std::endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    Date start = staff_list[i]->get_time_starting();
                    if (start.Day == search_start.Day && start.Month == search_start.Month && start.Year == search_start.Year) {
                        std::cout << "\t-----[ Staff no." << ++count << " ]-----" << std::endl;
                        staff_list[i]->displayInfo();
                    }
                }
                std::cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 5: {
                std::string search_phone;
                std::cout << "\tEnter Phone number: ";
                std::cin >> search_phone;
                int count = 0;
                system("cls");
                std::cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << std::endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_phone_number() == search_phone) {
                        std::cout << "\t-----[ Staff no." << ++count << " ]-----" << std::endl;
                        staff_list[i]->displayInfo();
                    }
                }
                std::cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 6: {
                std::string search_department;
                std::cout << "\tEnter Department: ";
                std::cin.ignore();
                getline(std::cin, search_department);
                int count = 0;
                system("cls");
                std::cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << std::endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_department().find(search_department) != std::string::npos) {
                        std::cout << "\t-----[ Staff no." << ++count << " ]-----" << std::endl;
                        staff_list[i]->displayInfo();
                    }
                }
                std::cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << std::endl;
                system("pause");
                break;
            }
            case 0:
                break;
            default:
                std::cout << "\n\tInvalid choice! Please try again.";
                system("pause");
        }
    } while (search_option != 0);
}

long Hospital_Management::total_salary() {
    long total_salary = 0;
    for (int i = 0; i < staff_list.size(); i++) {
        total_salary += staff_list[i]->monthly_salary();
    }
    return total_salary;
}

int Hospital_Management::staff_list_size() {
    return staff_list.size();
}