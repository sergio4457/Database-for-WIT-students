// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
#include "witStaff.h"

WITStaff::WITStaff(void) 
{
	name	= "";
	address = "";
	wNum	= "";
	role = "Staff";
}

WITStaff::WITStaff(string name, string add, string num) 
{
	WITPerson::name = name;
	WITPerson::address = add;
	WITPerson::wNum = num;
	WITPerson::role = "Staff";
	cout << "Please Enter the Staff hourly pay: " << endl;
	cin >> pay;
	cout << "Please enter the worked hours: " << endl;
	cin >> hours_worked;
}
WITStaff::WITStaff(string name, string add, string num, string rate, string hours) {  
	WITStaff::name = name;
	WITStaff::address = add;
	WITStaff::wNum = num;
	WITStaff::role = "Staff";
	WITStaff::pay = rate;
	WITStaff::hours_worked = hours;
}
WITStaff::~WITStaff(void) 
{	cout << "Destructor\n ";   }

string WITStaff::payMe(void)
{
	double Income;
	if ((stof(hours_worked)) <= 40) {
		Income = (stof(hours_worked)) * (stof(pay));
	}
	else 
	{
		double worked_time = (stof(hours_worked)) - 40; 
		Income = ((stof(pay)) * 40) + (worked_time*1.5*(stof(pay)));
	}
	return ("Name: " + this->name + " Income: $" + to_string(Income));
}
WITStaff & WITStaff::operator=(const WITStaff & Obj) 
{
	name = Obj.name;
	address = Obj.address;
	wNum = Obj.wNum;
	role = Obj.role;
	return *this;
}