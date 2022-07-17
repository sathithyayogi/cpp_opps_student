#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Student
{
private:
    string student_name;
    long int student_mobile_number;
    int student_pin;

public:
    Student(
        string student_name_a,
        long int student_mobile_number_a,
        int student_pin_a)
    {
        student_name = student_name_a;
        student_mobile_number = student_mobile_number_a;
        student_pin = student_pin_a;
    }

    void changPin(int current_pin, int new_pin)
    {
        if (current_pin == new_pin)
        {
            student_pin = new_pin;

            cout << endl
                 << "Successfully updated your pin!";
            _getch();
        }
        else
        {
            cout << endl
                 << "Oops! Enter valid current pin";
            _getch();
        }
    }

 

    int getStudentPin()
    {
        return student_pin;
    }

    long int getStudentMobileNumber()
    {
        return student_mobile_number;
    }

    // we are having this below abstraction, because different department student has different scholarship eleigibility and college fee structure
    virtual int getStudentsCollegeFee() = 0;
    virtual void eligibleForScholarship() = 0;

};

// inheritance
class ComputerScienceStudent : public Student
{
private:
    int student_credits;
    double student_gpa;
    double tution_fee;
    string student_status;


public:
    ComputerScienceStudent(
        string student_name_a,
        long int student_mobile_number_a,
        int student_pin_a,
        int student_credits_a,
        double student_gpa_a,string student_status_a) : Student(student_name_a, student_mobile_number_a, student_pin_a)
    {
        student_credits = student_credits_a;
        student_gpa = student_gpa_a;
        student_status = student_status_a;
    }

    int getStudentsCollegeFee()
    {
        // need to implement the code
        return 500;
    }

    void eligibleForScholarship()
    {
        if(student_gpa > 3.8)
        {
            cout << "you are in dean's list and you are eligible to apply for scholarship ";
            return;
        }
        cout << "Sorry you are not in dean's list.";
    }

};

int main()
{
    srand(time(NULL));
    int defaultPinNumber;
    string name;
    long int mobileNumber;
    long int CheckmobileNumber;
    long int checkStudentPin;
    int credits;
    double gpa;
    string status;

    int choice;
    int stu_status_choice;


    defaultPinNumber = rand() % 10000;

    cout << "Enter Your Name : " << endl;
    cin >> name;
    cout << "Enter Your Mobile Number : " << endl;
    cin >> mobileNumber;
    cout << "Enter Your no credits that you are going to take  : " << endl;
    cin >> credits;
    cout << "Enter Your GPA  : " << endl;
    cin >> gpa;

    cout << "Select your Status " << endl;
    cout << "1) Wa-resident " << endl;
    cout << "2) Non-resident-intl " << endl;
    cout << "3) Non-WA-resident-eLearning " << endl;
    cout << "4) BAS-resident " << endl;
    cout << "5) BAS-Non-resident-intl " << endl;

    cin >> stu_status_choice;

    switch (stu_status_choice)
    {
    case 1:
        status = "Wa-resident";
        break;
    case 2:
        status = "Non-resident-intl";
        break;    
   case 3:
        status = "Non-WA-resident-eLearning";
        break;
     case 4:
        status = "BAS-resident";
        break;
      case 5:
        status = "BAS-Non-resident-intl";
        break;
           
    default:
        status = "Wa-resident";
        break;
    }


    // constructor

    ComputerScienceStudent studentOne = ComputerScienceStudent(name, mobileNumber, defaultPinNumber, credits, gpa,status);

    cout << "Your Account is created, your Student Pin is : ";
    cout << defaultPinNumber;

    // system("cls");


    cout << endl
         << "*** Welcome to Syracuse University ***";
    cout << endl
         << "Enter Your Mobile NO : ";
    cin >> CheckmobileNumber;
    cout << endl
         << "Enter Your Pin : ";
    cin >> checkStudentPin;

    if ((CheckmobileNumber == studentOne.getStudentMobileNumber()) && (checkStudentPin == studentOne.getStudentPin()))
    {
        cout << "Crendials Correct";

        system("cls");

        cout << "*** Welcome to Syracuse University ***"<< endl;
        cout << "*** 1) Check Your Profile ***" << endl;
        cout << "*** 2) Update your Pin ***" << endl;
        cout << "*** 3) Check College Fee ***" << endl;
        cout << "*** 4) Print College Fee ***" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Name : ";
            break;
            
        
        default:
            break;
        }


    }
    else
    {
        cout << "InCorrect Crendials";
    }
}
