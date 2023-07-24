#include <bits/stdc++.h>
#include <vector>
#include <Windows.h>
using namespace std;

void SetColor(int backgound_color, int text_color) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

struct Date{
    int Day,Month,Year;
};
void input_Date(Date& d) {
    bool validInput = false;
    
    while (!validInput) {
        cout << "\n\t\tDay: ";
        cin >> d.Day;
        if (cin.fail()) {
            cout << "\t\tInvalid input. Please enter an integer value.\n";
            cin.clear();                      // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining characters in the input buffer
            continue;
        }
        cout << "\t\tMonth: ";
        cin >> d.Month;

        if (cin.fail()) {
            cout << "\t\tInvalid input. Please enter an integer value.\n";
            cin.clear();                      // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining characters in the input buffer
            continue;
        }
        cout << "\t\tYear: ";
        cin >> d.Year;

        if (cin.fail()) {
            cout << "\t\tInvalid input. Please enter an integer value.\n";
            cin.clear();                      // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining characters in the input buffer
            continue;
        }
        validInput = true;
    }
}
void output_Date(Date d) {
    cout << d.Day << "/" << d.Month << "/" << d.Year;
}


class Staff{
    protected:
        string staff_name;
        string staff_id;
        Date date_of_birth;
        Date time_starting;
        string phone_number;
        string department;
    public:
        Staff(){
            staff_name = "";
            staff_id = "";
            date_of_birth;
            time_starting;
            phone_number = "";
            department = ""; 
        }
        string get_staff_name() const{
            return staff_name;
        }
        string get_staff_id() const{
            return staff_id;
        }
        string get_phone_number() const{
            return phone_number;
        }
        string get_department() const{
            return department;
        }
        Date get_date_of_birth() const{
            return date_of_birth;
        }
        Date get_time_starting() const{
            return time_starting;
        }
        virtual void importInfo();
        virtual void displayInfo();
        virtual void editInfo();
        virtual int monthly_salary() = 0;
};

    void Staff :: importInfo(){
        fflush(stdin);
        cout << "\tStaff name: ";
        getline(cin, staff_name);
        cout << "\tStaff ID: ";
        cin >> staff_id;
        cout << "\tDate of birth (dd/mm/yyyy): ";
        input_Date(date_of_birth);
        cout << "\tTime of starting work (dd/mm/yyyy): ";
        input_Date(time_starting);
        cout << "\tPhone number: ";
        cin >> phone_number;
        cin.ignore();
        cout << "\tDepartment: ";
        getline(cin, department);
    }

    void Staff ::displayInfo(){
        cout << "\tStaff name: " << staff_name << endl;
        cout << "\tStaff ID: " << staff_id << endl;
        cout << "\tDate of birth: ";
        output_Date(date_of_birth);
        cout << "\n\tTime of starting work: ";
        output_Date(time_starting);
        cout << "\n\tPhone number: " << phone_number << endl;
        cout << "\tDepartment: " << department << endl;
    }

    void Staff :: editInfo(){
        system("cls");
        cout << "\t===== WHAT STAFF INFORMATION DO YOU WANT TO EDIT ? =====" << endl;
        cout << "\t 0. Press 0 for Exit. " << endl;
        cout << "\t 1. Press 1 for Staff name. " << endl;
        cout << "\t 2. Press 2 for Staff ID. " << endl;
        cout << "\t 3. Press 3 for Date of birth. " << endl;
        cout << "\t 4. Press 4 for Time of starting work. " << endl;
        cout << "\t 5. Press 5 for Phone number." << endl;
        cout << "\t 6. Press 6 for Department." << endl;
    }


class Doctor : public Staff{
    private:
        int working_days;
        int surgery_count;
    public:
        Doctor(){
            working_days = 0;
            surgery_count = 0;
        }
        void importInfo();
        void displayInfo();
        void editInfo();
        int monthly_salary();
};

    void Doctor :: importInfo(){
        cout << "\t===== IMPORT DOCTOR INFORMATION: =====" << endl;
        Staff :: importInfo();
        cout << "\tNumber of working days: ";
        cin >> working_days;
        cout << "\tSurgery count: ";
        cin >> surgery_count;
    }

    void Doctor :: displayInfo(){
        Staff :: displayInfo();
        cout << "\tPosition: < DOCTOR >" << endl;
        cout << "\tNumber of working days: " << working_days << endl;
        cout << "\tSurgery count: " << surgery_count << endl;
        cout << "\t ->> Monthly Salary: " << monthly_salary() <<endl;
    }

    void Doctor :: editInfo(){
        int edit_option;
        do{
            fflush(stdin);
            Staff :: editInfo();
            cout << "\t 7. Press 5 for Number of working days. " << endl;
            cout << "\t 8. Press 6 for Surgery count. " << endl;
            cout << "\tYour choice, press: ";
            cin >> edit_option;
            switch (edit_option){
                case 1:
                    fflush(stdin);
                    cout << "\tNew Staff name: ";
                    getline(cin, staff_name);
                    break;
                case 2:
                    cout << "\tNew Staff ID: ";
                    cin >> staff_id;
                    break;
                case 3:
                    cout << "\tNew Date of birth (dd/mm/yyyy): ";
                    input_Date(date_of_birth);
                    break;
                case 4:
                    cout << "\tNew Time of starting work (dd/mm/yyyy): ";
                    input_Date(time_starting);
                    break;
                case 5:
                    cout << "\tNew Phone number: ";
                    cin >> phone_number;
                    break;
                case 6:
                    fflush(stdin);
                    cout << "\tNew Department: ";
                    getline(cin, department);
                    break;
                case 7:
                    cout << "\tNew Number of working days: ";
                    cin >> working_days;
                    break;
                case 8:
                    cout << "\tNew Surgery count: ";
                    cin >> surgery_count;
                    break;
                case 0:
                    cout << "\tExiting Edit program..." << endl;
                    break;
                default:
                    cout << "\nInvalid choice! Please try again.";
                    system("pause");
            }
        } while (edit_option != 0);
    }

    int Doctor :: monthly_salary(){
        int salary_of_doctor;
        salary_of_doctor = 200*working_days + 500*surgery_count;
        return salary_of_doctor;
    }


class Nurse : public Staff{
    private:
        int working_days;
        int night_shifts;
    public:
        Nurse(){
            working_days = 0;
            night_shifts = 0;
        }
        void importInfo();
        void displayInfo();
        void editInfo();
        int monthly_salary();
};

    void Nurse :: importInfo(){
        cout << "\t===== IMPORT NURSE INFORMATION: =====" << endl;
        Staff :: importInfo();
        cout << "\tNumber of working days: ";
        cin >> working_days;
        cout << "\tNumber of night shifts: ";
        cin >> night_shifts;
    }

    void Nurse :: displayInfo(){
        Staff :: displayInfo();
        cout << "\tPosition: << NURSE >>" << endl;
        cout << "\tNumber of working days: " << working_days << endl;
        cout << "\tNumber of night shifts: " << night_shifts << endl;
        cout << "\t ->> Monthly Salary: " << monthly_salary() <<endl;
    }

    void Nurse :: editInfo(){
        int edit_option;
        do{
            fflush(stdin);
            Staff :: editInfo();
            cout << "\t 7. Press 5 for Number of working days. " << endl;
            cout << "\t 8. Press 6 for Number of night shifts. " << endl;
            cout << "\tYour choice, press: ";
            cin >> edit_option;
            switch (edit_option){
                case 1:
                    fflush(stdin);
                    cout << "\tNew Staff name: ";
                    getline(cin, staff_name);
                    break;
                case 2:
                    cout << "\tNew Staff ID: ";
                    cin >> staff_id;
                    break;
                case 3:
                    cout << "\tNew Date of birth (dd/mm/yyyy): ";
                    input_Date(date_of_birth);
                    break;
                case 4:
                    cout << "\tNew Time of starting work (dd/mm/yyyy): ";
                    input_Date(time_starting);
                    break;
                case 5:
                    cout << "\tNew Phone number: ";
                    cin >> phone_number;
                    break;
                case 6:
                    fflush(stdin);
                    cout << "\tNew Department: ";
                    getline(cin, department);
                    break;
                case 7:
                    cout << "\tNew Number of working days: ";
                    cin >> working_days;
                    break;
                case 8:
                    cout << "\tNew Number of night shifts: ";
                    cin >> night_shifts;
                    break;
                case 0:
                    cout << "\tExiting Edit program..." << endl;
                    break;
                default:
                    cout << "\nInvalid choice! Please try again.";
                    system("pause");
            }
        } while (edit_option != 0);
    }

    int Nurse :: monthly_salary(){
        int salary_of_doctor;
        salary_of_doctor = 100*working_days + 250*night_shifts;
        return salary_of_doctor;
    }


class Hospital_Management{
    private:
        vector<Staff*> staff_list;
    public:
        void import_staff();
        void display_staff_list();
        void edit_staff_info();
        void search_staff();
        long total_salary();
        int staff_list_size() const{
            return staff_list.size();
        };
};
    
    void Hospital_Management :: import_staff(){
        Staff* new_staff;
        int option;
        do{
           system("cls");
            cout << "\t========== POSITION OF HOSPITAL: ==========" << endl;
            cout << "\t 0. Press 0 for Exit. " << endl;
            cout << "\t 1. Press 1 for NEW DOCTOR. " << endl;
            cout << "\t 2. Press 2 for NEW NURSE. " << endl;
            cout << "\tYour choice, press: ";
            cin >> option;
            switch (option)
            {
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
                    cout << "\tExiting Import program..." << endl;
                    break;
                default:
                    cout << "\nInvalid choice! Please try again.";
                    system("pause");
            }
        } while ((option != 0));
        system("cls");
        cout << "\t Information about " << staff_list.size() << " staffs is available !" << endl;
        cout << "\t Please check the staff information with the 'Display Staffs List' function in MENU !" << endl;
        system("pause");
    }

    void Hospital_Management::display_staff_list() {
        cout << "\t Information about " << staff_list.size() << " staffs is available !" << endl;
        int display_option;
        do {
            system("cls");
            cout << "\t========== TYPE OF EMPLOYEES YOU WANT TO SEARCH: ==========" << endl;
            cout << "\t 0. Press 0 to Exit." << endl;
            cout << "\t 1. Press 1 for Doctor List. " << endl;
            cout << "\t 2. Press 2 for Nurse List. " << endl;
            cout << "\t 3. Press 3 for All Staff List." << endl;
            cout << "\tYour choice: ";
            cin >> display_option;
            switch (display_option) {
                case 1: {
                    system("cls");
                    cout << "\t========== DOCTOR LIST ==========" << endl;
                    int count = 0;
                    for (int i = 0; i < staff_list.size(); i++) {
                        Doctor* doctor = dynamic_cast<Doctor*>(staff_list[i]);
                        if (doctor) {
                            cout << "\t-----[ Doctor no." << ++count << " ]-----" << endl;
                            doctor->displayInfo();
                        }
                    }
                    cout << "\n\t=====[ Total number of doctors: " << count << " ]=====" << endl;
                    system("pause");
                    break;
                }
                case 2: {
                    system("cls");
                    cout << "\t========== NURSE LIST ==========" << endl;
                    int count = 0;
                    for (int i = 0; i < staff_list.size(); i++) {
                         Nurse* nurse = dynamic_cast<Nurse*>(staff_list[i]);
                        if (nurse) {
                            cout << "\t-----[ Nurse no." << ++count << " ]-----" << endl;
                            nurse->displayInfo();
                        }
                    }
                    cout << "\n\t=====[ Total number of nurses: " << count << " ]=====" << endl;
                    system("pause");
                    break;
                }
                case 3: {
                    system("cls");
                    cout << "\t========== ALL STAFF LIST ==========" << endl;
                    for (int i = 0; i < staff_list.size(); i++) {
                        cout << "\t-----[ Staff no." << i + 1 << " / Total input: " << staff_list.size() << " ]-----" << endl;
                        staff_list[i]->displayInfo();
                    }
                    system("pause");
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "\n\tPlease press 0, 1, 2, or 3 only! \n\tTry again: ";
                    system("pause");
            }
        } while (display_option != 0);
    }

    void Hospital_Management::edit_staff_info() {
        int staff_edited;
        cout << "\t========== ALL STAFF LIST ==========" << endl;
        for (int i = 0; i < staff_list.size(); i++) {
            cout << "\t-----[ Staff no." << i + 1 << " / Total input: " << staff_list.size() << " ]-----" << endl;
            staff_list[i]->displayInfo();
        }
        cout << "\n\n\t===== WHICH STAFF MEMBER DO YOU WANT TO EDIT/DELETE FROM THE LIST? =====" << endl;
        cout << "\tChoose a staff member from 1 to " << staff_list.size() << ": ";
        cin >> staff_edited;
        while (staff_edited < 1 || staff_edited > staff_list.size()) {
            cout << "\tPlease re-enter a number from 1 to " << staff_list.size() << ": ";
            cin >> staff_edited;
        }
        Staff* staff = staff_list[staff_edited - 1];
        system("cls");
        cout << "\t-----[ STAFF EDITED ]-----" << endl;
        staff->displayInfo();
    
        int edit_option;
        cout << "\n\t===== SELECT ACTION =====" << endl;
        cout << "\t 1. Edit staff information." << endl;
        cout << "\t 2. Remove staff member." << endl;
        cout << "\tYour choice, press: ";
        cin >> edit_option;

        if (edit_option == 1) {
            staff->importInfo();
            cout << "\n\tPlease check the staff information you just edited using the 'Display Staff List' function in the MENU!" << endl;
        }
        else if (edit_option == 2) {
            system("cls");
            staff_list.erase(staff_list.begin() + staff_edited - 1);
            delete staff;
            cout << "\n\tThe staff member has been deleted." << endl;
            cout << "\n\tAfter deleting, information about " << staff_list.size() << " staff members is available!" << endl;
            cout << "\tPlease check the staff information using the 'Display Staff List' function in the MENU!" << endl;
        }
        else {
            cout << "\n\tInvalid option! Please try again." << endl;
        }
    }

void Hospital_Management::search_staff() {
    int search_option;
    do {
        system("cls");
        cout << "\t========== SEARCH STAFF ==========" << endl;
        cout << "\t 0. Press 0 to Exit" << endl;
        cout << "\t 1. Press 1 to Search by Staff name. " << endl;
        cout << "\t 2. Press 2 to Search by Staff ID. " << endl;
        cout << "\t 3. Press 3 to Search by Date of birth. " << endl;
        cout << "\t 4. Press 4 to Search by Time of starting work. " << endl;
        cout << "\t 5. Press 5 to Search by Phone number." << endl;
        cout << "\t 6. Press 6 to Search by Department." << endl;
        cout << "\tYour choice: ";
        cin >> search_option;

        switch (search_option) {
            case 1: {
                string search_name;
                cout << "\tEnter Staff name: ";
                cin.ignore();
                getline(cin, search_name);
                int count = 0;
                system("cls");
                cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_staff_name().find(search_name) != string::npos) {
                        cout << "\t-----[ Staff no." << ++count << " ]-----" << endl;
                        staff_list[i]->displayInfo();
                    }
                }
                cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << endl;
                system("pause");
                break;
            }
            case 2: {
                string search_id;
                cout << "\tEnter Staff ID: ";
                cin >> search_id;
                int count = 0;
                system("cls");
                cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_staff_id() == search_id) {
                        cout << "\t-----[ Staff no." << ++count << " ]-----" << endl;
                        staff_list[i]->displayInfo();
                    }
                }
                cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << endl;
                system("pause");
                break;
            }
            case 3: {
                Date search_birth;
                cout << "\tEnter Date of birth: ";
                input_Date(search_birth);
                int count = 0;
                system("cls");
                cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    Date birth = staff_list[i]->get_date_of_birth();
                    if (birth.Day == search_birth.Day && birth.Month == search_birth.Month && birth.Year == search_birth.Year) {
                        cout << "\t-----[ Staff no." << ++count << " ]-----" << endl;
                        staff_list[i]->displayInfo();
                    }
                }
                cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << endl;
                system("pause");
                break;
            }
            case 4: {
                Date search_start;
                cout << "\tEnter Time of starting work: ";
                input_Date(search_start);
                int count = 0;
                system("cls");
                cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    Date start = staff_list[i]->get_time_starting();
                    if (start.Day == search_start.Day && start.Month == search_start.Month && start.Year == search_start.Year) {
                        cout << "\t-----[ Staff no." << ++count << " ]-----" << endl;
                        staff_list[i]->displayInfo();
                    }
                }
                cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << endl;
                system("pause");
                break;
            }
            case 5: {
                string search_phone;
                cout << "\tEnter Phone number: ";
                cin >> search_phone;
                int count = 0;
                system("cls");
                cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_phone_number() == search_phone) {
                        cout << "\t-----[ Staff no." << ++count << " ]-----" << endl;
                        staff_list[i]->displayInfo();
                    }
                }
                cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << endl;
                system("pause");
                break;
            }
            case 6: {
                string search_department;
                cout << "\tEnter Department: ";
                cin.ignore();
                getline(cin, search_department);
                int count = 0;
                system("cls");
                cout << "\t========== STAFF MATCHED YOUR SEARCH ==========" << endl;
                for (int i = 0; i < staff_list.size(); i++) {
                    if (staff_list[i]->get_department().find(search_department) != string::npos) {
                        cout << "\t-----[ Staff no." << ++count << " ]-----" << endl;
                        staff_list[i]->displayInfo();
                    }
                }
                cout << "\n\t=====[" << " Total number of relevant search results: " << count << " ]=====" << endl;
                system("pause");
                break;
            }
            case 0:
                break;
            default:
                cout << "\n\tInvalid choice! Please try again.";
                system("pause");
        }
    } while (search_option != 0);
}

    long Hospital_Management :: total_salary(){
        long total_salary = 0;
        for (int i=0; i < staff_list.size(); i++) 
        {
            total_salary += staff_list[i]->monthly_salary();
        }
        return total_salary;
    }


int main() {
    SetConsoleTitle(TEXT("HOSPITAL MANAGEMENT PROGRAM"));
    SetConsoleOutputCP(65001);
    SetColor(7, 0);
    Hospital_Management manage;
    int option;
    cout << "\t\t\t===============================================================" << endl;
    cout << "\t\t\t=                 WELCOME TO HOSPITAL MANAGEMENT              =" << endl;
    cout << "\t\t\t===============================================================" << endl << endl;
    cout << "\tPress Enter key to continue!" << endl;
    system("pause");
    do {
        system("cls");
        cout << "\t\t\t===============================================================" << endl;
        cout << "\t\t\t=                    HOSPITAL MANAGEMENT MENU                =" << endl;
        cout << "\t\t\t===============================================================" << endl;
        cout << "\n\t 0. Press 0 for Exit." << endl;
        cout << "\t 1. Press 1 for Add Staff Information." << endl;
        cout << "\t 2. Press 2 for Print Staff List." << endl;
        cout << "\t 3. Press 3 for Edit Staff Information." << endl;
        cout << "\t 4. Press 4 for Search Staff Information." << endl;
        cout << "\t 5. Press 5 for Calculate Total Salary." << endl;
        cout << "\tYour choice, press: ";
        cin >> option;
        switch (option) {
            case 1:
                manage.import_staff();
                break;
            case 2:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    cout << "\t:( Ohh no! No data has been loaded yet!" << endl;
                    cout << "\tNeed more Staff information!" << endl << endl;
                } else {
                    manage.display_staff_list();
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    cout << "\t:( Ohh no! No data has been loaded yet!" << endl;
                    cout << "\tNeed more Staff information!" << endl << endl;
                } else {
                    manage.edit_staff_info();
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    cout << "\t:( Ohh no! No data has been loaded yet!" << endl;
                    cout << "\tNeed more Staff information!" << endl << endl;
                } else {
                    manage.search_staff();
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if (manage.staff_list_size() == 0) {
                    cout << "\t:( Ohh no! No data has been loaded yet!" << endl;
                    cout << "\tNeed more Staff information!" << endl << endl;
                } else {
                    cout << "\tAlready have the salary of " << manage.staff_list_size() << " staff members!" << endl;
                    cout << "\t->> Total salary: " << manage.total_salary() << endl;
                }
                system("pause");
                break;
            case 0:
                cout << "\tExiting program..." << endl;
                break;
            default:
                cout << "\tInvalid choice! Please try again." << endl;
                break;
        }
    } while (option != 0);
    cout << "\n\n\t\t\t==== <3<3<3<3<3 THANKS FOR USING HOSPITAL MANAGEMENT PROGRAM <3<3<3<3<3 ====" << endl;
    system("pause");
    return 0;
}