// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#ifndef WITFACULTY_H
#define WITFACULTY_H
#include "witPerson.h"

class WITFaculty : public WITPerson {

public:
	WITFaculty(void);
	WITFaculty(string name, string add, string num); 
	WITFaculty(string name, string add, string num, string salary);
	virtual ~WITFaculty(void);  
	virtual string payMe(void);
private:
	WITFaculty(const WITFaculty & Obj);
	WITFaculty & operator = (const WITFaculty & Obj);
};
#endif