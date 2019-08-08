// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "witPerson.h"

ostream & operator << (ostream& out, const WITPerson& Obj) { 
	out << "Name: "		<< Obj.name << endl;                     
	out << "Address: "  << Obj.address << endl;
	out << "W-Number: " << Obj.wNum << endl;
	out << "Role: "		<< Obj.role << endl;
	return out;
};
istream & operator >> (istream& in, WITPerson& Obj) { 
	in.ignore();
	cout << "" << endl;
	getline(in, Obj.name);
	cout << "" << endl;
	getline(in, Obj.address);
	cout << "" << endl;
	getline(in, Obj.wNum);
	return in;
};
ostream & operator << (ofstream& out, WITPerson& Obj) 
{ 
	out << Obj.name << endl;
	out << Obj.address << endl;
	out << Obj.wNum << endl;
	out << Obj.role << endl;
	out << Obj.pay << endl;
	out << Obj.hours_worked << endl;
	return out;
};

WITPerson::WITPerson(void) 
{
	WITPerson::name = "";
	WITPerson::address = "";
	WITPerson::wNum = "";
	WITPerson::role = "";
}

WITPerson::WITPerson(string name, string add, string num, string role) 
{
	WITPerson::name = name;
	WITPerson::address = add;
	WITPerson::wNum = num;
	WITPerson::role = role;
}

WITPerson::WITPerson(const WITPerson & Obj) 
{
	name = Obj.name;
	address = Obj.address;
	wNum = Obj.wNum;
	role = Obj.role;
}

WITPerson::~WITPerson(void) 
{   cout << "Destructor\n ";   }

WITPerson & WITPerson::operator=(const WITPerson & Obj) 
{
	name	= Obj.name;
	address = Obj.address;
	wNum	= Obj.wNum;
	role	= Obj.role;
	return *this;
}