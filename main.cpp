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
                 << "Successfully updated your pin!" << endl;
            _getch();
        }
        else
        {
            cout << endl
                 << "Oops! Enter valid current pin" << endl;
            _getch();
        }
    }

    int getStudentPin()
    {
        return student_pin;
    }

    string getStudentName()
    {
        return student_name;
    }

    long int getStudentMobileNumber()
    {
        return student_mobile_number;
    }

    // we are having this below abstraction, because different department student has different scholarship eleigibility and college fee structure
    virtual string getStudentsCollegeFee() = 0;
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
    string fees;

public:
    ComputerScienceStudent(
        string student_name_a,
        long int student_mobile_number_a,
        int student_pin_a,
        int student_credits_a,
        double student_gpa_a, string student_status_a) : Student(student_name_a, student_mobile_number_a, student_pin_a)
    {
        student_credits = student_credits_a;
        student_gpa = student_gpa_a;
        student_status = student_status_a;
    }

    string getStudentStatus()
    {
        return student_status;
    }

    int getStudentsCredits()
    {
        return student_credits;
    }

    int getStudentGPA()
    {
        return student_gpa;
    }

    int getNumCredits()
    {
        return student_credits;
    }

    string getStudentsCollegeFee()
    {

        if (tution_fee < 0)
        {
            throw std::invalid_argument("not a valid tuition!");
        }
        else
        {
            if (getStudentStatus().compare("Wa-resident"))
            {
                if (getNumCredits() > 0 && getNumCredits() <= 10)
                {
                    tution_fee = getNumCredits() * 113.04;
                }
                else if (getNumCredits() > 10 && getNumCredits() <= 19)
                {
                    tution_fee = 1130.4 + ((getNumCredits() - 10) * 55.94);
                }
                else if (getNumCredits() > 19 && getNumCredits() <= 25)
                {
                    tution_fee = 1679.34 + ((getNumCredits() - 19) * 101.41);
                }
                else
                {
                    tution_fee = 0.0;
                }
            }
            else if (getStudentStatus().compare("Non-resident-intl"))
            {
                if (getNumCredits() > 0 && getNumCredits() <= 10)
                {
                    tution_fee = getNumCredits() * 291.28;
                }
                else if (getNumCredits() > 10 && getNumCredits() < 19)
                {
                    tution_fee = 2912.80 + ((getNumCredits() - 10) * 63.22);
                }
                else if (getNumCredits() > 18 && getNumCredits() <= 25)
                {
                    tution_fee = 3418.56 + ((getNumCredits() - 18) * 279.66);
                }
                else
                {
                    tution_fee = 0.0;
                }
            }
            else if (getStudentStatus().compare("Non-WA-resident-eLearning"))
            {
                if (getNumCredits() > 0 && getNumCredits() <= 10)
                {
                    tution_fee = getNumCredits() * 220.51;
                }
                else if (getNumCredits() > 10 && getNumCredits() < 19)
                {
                    tution_fee = 2205.10 + ((getNumCredits() - 10) * 11.04);
                }
                else if (getNumCredits() > 18 && getNumCredits() <= 25)
                {
                    tution_fee = 2293.42 + ((getNumCredits() - 18) * 208.89);
                }
                else
                {
                    tution_fee = 0.0;
                }
            }
            else if (getStudentStatus().compare("BAS-resident"))
            {
                if (getNumCredits() > 0 && getNumCredits() <= 10)
                {
                    tution_fee = getNumCredits() * 235.47;
                }
                else if (getNumCredits() > 10 && getNumCredits() < 19)
                {
                    tution_fee = 2354.70 + ((getNumCredits() - 10) * 11.84);
                }
                else if (getNumCredits() > 18 && getNumCredits() <= 25)
                {
                    tution_fee = 2449.42 + ((getNumCredits() - 18) * 208.89);
                }
                else
                {
                    tution_fee = 0.0;
                }
            }
            else if (getStudentStatus().compare("BAS-Non-resident-intl"))
            {
                if (getNumCredits() > 0 && getNumCredits() <= 10)
                {
                    tution_fee = getNumCredits() * 620.30;
                }
                else if (getNumCredits() > 10 && getNumCredits() < 19)
                {
                    tution_fee = 6203.00 + ((getNumCredits() - 10) * 11.84);
                }
                else if (getNumCredits() > 18 && getNumCredits() <= 25)
                {
                    tution_fee = 6297.72 + ((getNumCredits() - 18) * 608.68);
                }
                else
                {
                    tution_fee = 0.0;
                }
            }

            else
            {
                tution_fee = 0.0;
            }
            fees = to_string(tution_fee);
            return fees;
        }
    }

    void eligibleForScholarship()
    {
        if (student_gpa > 3.8)
        {
            cout << "you are in dean's list and you are eligible to apply for scholarship ";
            return;
        }
        cout << "Sorry you are not in dean's list.";
    }
};

class ScienceStudent : public Student
{
private:
    int student_credits;
    double student_gpa;
    double tution_fee;
    string student_status;

public:
    ScienceStudent(
        string student_name_a,
        long int student_mobile_number_a,
        int student_pin_a,
        int student_credits_a,
        double student_gpa_a, string student_status_a) : Student(student_name_a, student_mobile_number_a, student_pin_a)
    {
        student_credits = student_credits_a;
        student_gpa = student_gpa_a;
        student_status = student_status_a;
    }

    string getStudentsCollegeFee()
    {
        return "500";
    }

    void eligibleForScholarship()
    {
        if (student_gpa > 3.8)
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
    long int Ch_currentpin, Ch_new_pin;
    int collegeDept;

    int choice;
    int stu_status_choice;

    defaultPinNumber = rand() % 10000;

    cout << "Enter Your Name : ";
    cin >> name;
    cout << "Enter Your Mobile Number : ";
    cin >> mobileNumber;
    cout << "Enter Your no credits that you are going to take  : ";
    cin >> credits;
    cout << "Enter Your GPA  : ";
    cin >> gpa;
    cout << "Enter Your College Department  : " << endl;
    cout << "1) Computer Science " << endl;
    cout << "2) Science " << endl;
    cin >> collegeDept;

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

   

        ComputerScienceStudent studentOne = ComputerScienceStudent(name, mobileNumber, defaultPinNumber, credits, gpa, status);
   
        // ScienceStudent studentOne = ScienceStudent(name, mobileNumber, defaultPinNumber, credits, gpa, status);

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

        do
        {
            cout << "*** Welcome to Syracuse University ***" << endl;
            cout << "*** 1) Check Your Profile ***" << endl;
            cout << "*** 2) Update your Pin ***" << endl;
            cout << "*** 3) Check College Fee ***" << endl;

            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Name : " + studentOne.getStudentName() << endl;
                cout << "Mobile Number : " + studentOne.getStudentMobileNumber() << endl;
                cout << "Credits Taken : " + studentOne.getStudentsCredits() << endl;
                cout << "GPA : " + studentOne.getStudentGPA() << endl;
                break;
            case 2:
                cout << "Enter your Old Pin : ";
                cin >> Ch_currentpin;
                cout << "Enter your Current Pin : ";
                cin >> Ch_new_pin;
                studentOne.changPin(Ch_currentpin, Ch_new_pin);
                break;
            case 3:
                cout << " Your College Fee is " + studentOne.getStudentsCollegeFee() << endl;
                break;
            default:
                break;
            }
        } while (1);
    }
    else
    {
        cout << "InCorrect Crendials";
    }
}
