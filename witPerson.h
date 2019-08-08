// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#ifndef WITPERSON_H
#define WITPERSON_H

class WITPerson {
	friend ostream & operator << (ostream &, const WITPerson&);
	friend istream & operator >> (istream&, WITPerson&);
	friend ostream & operator << (ofstream&, WITPerson&); 

protected:
	string name;
	string address;
	string wNum;
	string role;
	string hours_worked; 
	string pay; 

public:
	WITPerson(void); 
	WITPerson(string name, string add, string num, string role);
	virtual ~WITPerson(void);
	string getRole(void) { return role; }
	string getName(void) { return name; }
	string getAddress(void) { return address; }
	string getwNum(void) { return wNum; }
	virtual string payMe(void) = 0;

private:
	WITPerson(const WITPerson & Obj);
	WITPerson & operator = (const WITPerson & Obj);

};
#endif