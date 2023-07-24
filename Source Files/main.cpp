#include "../Header_Files/Hospital_Management.h"
#include <iostream>

int main() {
    Hospital_Management manage;
    int option;
    std::cout << "\t\t\t===============================================================" << std::endl;
    std::cout << "\t\t\t=                 WELCOME TO HOSPITAL MANAGEMENT              =" << std::endl;
    std::cout << "\t\t\t===============================================================" << std::endl << std::endl;
    std::cout << "\tPress Enter key to continue!" << std::endl;
    system("pause");
    do {
        system("cls");
        std::cout << "\t\t\t===============================================================" << std::endl;
        std::cout << "\t\t\t=                    HOSPITAL MANAGEMENT MENU                =" << std::endl;
        std::cout << "\t\t\t===============================================================" << std::endl;
        std::cout << "\n\t 0. Press 0 for Exit." << std::endl;
        std::cout << "\t 1. Press 1 for Add Staff Information." << std::endl;
        std::cout << "\t 2. Press 2 for Print Staff List." << std::endl;
        std::cout << "\t 3. Press 3 for Edit Staff Information." << std::endl;
        std::cout << "\t 4. Press 4 for Search Staff Information." << std::endl;
        std::cout << "\t 5. Press 5 for Calculate Total Salary." << std::endl;
        std::cout << "\tYour choice, press: ";
        std::cin >> option;
        switch (option) {
            case 1:
                manage.import_staff();
                break;
            case 2:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    std::cout << "\t:( Ohh no! No data has been loaded yet!" << std::endl;
                    std::cout << "\tNeed more Staff information!" << std::endl << std::endl;
                } else {
                    manage.display_staff_list();
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    std::cout << "\t:( Ohh no! No data has been loaded yet!" << std::endl;
                    std::cout << "\tNeed more Staff information!" << std::endl << std::endl;
                } else {
                    manage.edit_staff_info();
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    std::cout << "\t:( Ohh no! No data has been loaded yet!" << std::endl;
                    std::cout << "\tNeed more Staff information!" << std::endl << std::endl;
                } else {
                    manage.search_staff();
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    std::cout << "\t:( Ohh no! No data has been loaded yet!" << std::endl;
                    std::cout << "\tNeed more Staff information!" << std::endl << std::endl;
                } else {
                    std::cout << "\tAlready have the salary of " << manage.staff_list_size() << " staff members!" << std::endl;
                    std::cout << "\t->> Total salary: " << manage.total_salary() << std::endl;
                }
                system("pause");
                break;
            case 0:
                std::cout << "\tExiting program..." << std::endl;
                break;
            default:
                std::cout << "\tInvalid choice! Please try again." << std::endl;
                break;
        }
    } while (option != 0);
    std::cout << "\n\n\t\t\t==== <3<3<3<3<3 THANKS FOR USING HOSPITAL MANAGEMENT PROGRAM <3<3<3<3<3 ====" << std::endl;
    system("pause");
    return 0;
}
