// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
#include "witStudent.h"

WITStudent::WITStudent(void)
{
	name	= "";
	address = "";
	wNum	= "";
	role	= "Student";
}

WITStudent::WITStudent(string name, string add, string num) 
{
	WITPerson::name    = name;
	WITPerson::address = add;
	WITPerson::wNum	   = num;
	WITPerson::role    = "Student";
	cout << "Please Enter the Student hourly pay: " << endl;
	cin >> pay;
	do {
		cout << "Please enter the # of worked hours less than 40 hours: " << endl;
		cin >> hours_worked;
	} while ((stof(hours_worked)) > 40);
}
WITStudent::WITStudent(string name, string add, string num,string rate, string hours){
	WITPerson::name    = name;
	WITPerson::address = add;
	WITPerson::wNum    = num;
	WITPerson::role    = "Student";
	WITPerson::pay     = rate;
	WITPerson::hours_worked = hours;	
}
WITStudent::~WITStudent(void)
{	cout << "Destructor\n ";	}

string WITStudent::payMe(void)
{
	double paycheck = (stof(hours_worked)) * (stof(pay));
	return ("Name: " + this->name + " Pay Check: $" + to_string(paycheck));
}
WITStudent & WITStudent::operator=(const WITStudent & Obj) 
{
	name	= Obj.name;
	address = Obj.address;
	wNum	= Obj.wNum;
	role	= Obj.role;
	return *this;
}


