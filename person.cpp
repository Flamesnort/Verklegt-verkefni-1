#include "person.h"

//========CONSTRUCTORS==========
Person::Person()
{
    name = "";
    gender = "";
    date_of_birth = "";
    date_of_death = "";
}

//========PUBLIC FUNCTIONS==========
QString Person::getName()
{
    return QString::fromStdString(name);
}

QString Person::getGender()
{
    return QString::fromStdString(gender);
}

QString Person::getDoB()
{
    return QString::fromStdString(date_of_birth);
}

QString Person::getDoD()
{
    return QString::fromStdString(date_of_death);
}

void Person::setName(string _name)
{
    name = _name;
}

void Person::setGender(string _gender)
{
    gender = _gender;
}

void Person::setDoB(string dob)
{
    date_of_birth = dob;
}

void Person::setDoD(string dod)
{
    date_of_death = dod;
}

//========FRIEND FUNCTIONS==========
istream& operator >>(istream& ins, Person& person1)
{
    char temp;  //temporary variable to enter a character for the persons gender
    string tempGender;  //makes the interface easier to read

    cout << "Enter the name of a computer scientist: ";
    cin.ignore(1000, '\n'); //this might be needed because cin leaves stuff in the buffer
    getline(ins, person1.name);
    cout << "Enter that scientists gender (m for male, f for female): ";
    cin >> temp;
    if(temp == 'm')
    {
        person1.gender = "male";
        tempGender = "his ";
    }
    else if(temp == 'f')
    {
        person1.gender = "female";
        tempGender = "her ";
    }

    cout << "Enter " << tempGender << "date of birth: (DD/MM/YYYY)";
    ins >> person1.date_of_birth;

    cout << "Enter " << tempGender << "date of death (DD/MM/YYYY - enter 0 for still alive): ";
    ins >> person1.date_of_death;
    if(person1.date_of_death == "0")
    {
        person1.date_of_death = "Still alive";
    }

    return ins;
}

ostream& operator <<(ostream& os, Person person1)
{
    os << person1.name << endl;
    os << person1.gender << endl;
    os << person1.date_of_birth << endl;
    os << person1.date_of_death << endl;
    return os;
}
