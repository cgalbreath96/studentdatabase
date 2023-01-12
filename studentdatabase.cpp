
#include<iostream>
#include<string>
using namespace std;
void initialize_records(string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[]);
void print_menu();
float grade_input_validation(float _grade);
int record_input_validation(int _input);
void enter_student_rec (string& _fname, string& _lname, int& _student_id, float& _midterm_grade, float& _final_grade);
void delete_student_record(int _user_opt, string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[]);
void print_student_records(string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[]);
void print_student_record_by_id(int _user_opt, string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[]);
void edit_student_record(int _user_opt, string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[]);
const int SIZE = 20;
int main()
{
    int user_opt;
    string fname[SIZE];
    string lname[SIZE];
    int student_id[SIZE];
    float midterm_grade[SIZE];
    float final_grade[SIZE];
    initialize_records(fname, lname, student_id, midterm_grade, final_grade);

    do
    {
        print_menu();
        cin >> user_opt;
        switch (user_opt)
        {
            case 1:
                for (int i =0; i < SIZE; i++)
                {
                if (fname[i] != "")
                continue;
                else
                enter_student_rec(fname[i], lname[i], student_id[i], midterm_grade[i], final_grade[i]);
                break;
                }
                break;
            case 2:
                cout << "Select a student record to delete (1-20): ";
                cin >> user_opt;
                user_opt = record_input_validation(user_opt);
                delete_student_record(user_opt, fname, lname, student_id, midterm_grade, final_grade);
                break;
            case 3:
                print_student_records(fname, lname, student_id, midterm_grade, final_grade);
                break;
            case 4:
                cout << "Select a student record to print (1-20): ";
                cin >> user_opt;
                user_opt = record_input_validation(user_opt);
                print_student_record_by_id(user_opt, fname, lname, student_id, midterm_grade, final_grade);
                break;
            case 5:
                cout << "Select a student record to edit (1-20): ";
                cin >> user_opt;
                user_opt = record_input_validation(user_opt);
                edit_student_record(user_opt, fname, lname, student_id, midterm_grade, final_grade);
                break;
            case 6: cout << "Goodbye!" << endl;
                break;
            default: cout << "Invalid input" << endl;
        }
       
    } while (user_opt != 6);

    return 0;
}

void initialize_records(string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[])
{
    int i =0;
    for (i; i < SIZE; i ++)
    {
        fname[i] = "";
        lname[i] = "";
        student_id[i] = 0;
        midterm_grade[i] = 0;
        final_grade[i] = 0;
    }
}

void print_menu()
{
    cout << endl;
    cout << "Please select one of the following options:" << endl;
    cout << "[1]: Add a new student record." << endl;
    cout << "[2]: Delete a student record." << endl;
    cout << "[3]: Display all student records." << endl;
    cout << "[4]: Show a student record by ID." << endl;
    cout << "[5]: Edit a student record." << endl;
    cout << "[6]: Exit" << endl;
    cout << "Choose an option from 1 to 6:";
}

float grade_input_validation(float _grade)
{
    while (_grade <= -1  || _grade >= 101)
    {
        cout << "Invalid input" << endl;
        cout << "Enter student grade (0-100): ";
        cin >> _grade;

    }
        return _grade;
}

int record_input_validation(int _input)
{
    while (_input <= 0 || _input >= 21)
    {
        cout << "Invalid input." << endl;
        cout << "Enter a Student ID (1-20): ";
        cin >> _input;
    }
    return _input;
}

void enter_student_rec (string& _fname, string& _lname, int& _student_id, float& _midterm_grade, float& _final_grade)
{
    cout << "Please enter the following information to add a new student record." << endl;
    cout << "Enter a first name: ";
    cin >> _fname;
    cout << "Enter a last name: ";
    cin >> _lname;
    cout << "Enter Student ID: ";
    cin >> _student_id;
    cout << "Enter the midterm grade: ";
    cin >> _midterm_grade;
    _midterm_grade = grade_input_validation(_midterm_grade);
    cout << "Enter the final grade: ";
    cin >> _final_grade;
    _final_grade = grade_input_validation(_final_grade);

}

void delete_student_record(int _user_opt, string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[])
{
    fname[_user_opt - 1] = "";
    lname[_user_opt - 1] = "";
    student_id[_user_opt - 1] = 0;
    midterm_grade[_user_opt - 1] = 0;
    final_grade[_user_opt - 1] = 0;
    cout << "Student record sucessfully deleted!" << endl;
}

void print_student_records(string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[])
{
    cout << "ID"  << "\t" << "First Name" << "\t" << "Last Name" << "\t" << "Midterm Grade" << "\t" << "Final Grade" << endl;
    for (int i =0; i < SIZE; i++)
    {
        if (fname[i] == "")
        continue;
        else
        cout << student_id[i] << "\t" << fname[i] << "\t" << lname[i] << "\t" << midterm_grade[i] << "\t" << final_grade[i] << endl;
    }
}

void print_student_record_by_id(int _user_opt, string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[])
{
    cout << "ID"  << "\t" << "First Name" << "\t" << "Last Name" << "\t" << "Midterm Grade" << "\t" << "Final Grade" << endl;
    cout << student_id[_user_opt - 1] << "\t" << fname[_user_opt - 1] << "\t" << lname[_user_opt - 1] << "\t" << midterm_grade[_user_opt - 1] << "\t" << final_grade[_user_opt - 1] << endl;
}

void edit_student_record(int _user_opt, string fname[], string lname[], int student_id[], float midterm_grade[], float final_grade[])
{
    cout << "Student record found! Enter the following information to edit student record." << endl;
    cout << "Enter a first name: ";
    cin >> fname[_user_opt -1];
    cout << "Enter a last name: ";
    cin >> lname[_user_opt -1];
    cout << "Enter a Student ID: ";
    cin >> student_id[_user_opt -1];
    cout << "Enter a midterm grade: ";
    cin >> midterm_grade[_user_opt -1];
    midterm_grade[_user_opt -1] = grade_input_validation(midterm_grade[_user_opt -1]);
    cout << "Enter a final grade: ";
    cin >> final_grade[_user_opt -1];
    final_grade[_user_opt -1] = grade_input_validation(final_grade[_user_opt -1]);
    cout << "Student record successfully modified!" << endl;
}
