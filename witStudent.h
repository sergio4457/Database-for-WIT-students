// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#ifndef WITSTUDENT_H
#define WITSTUDENT_H
#include "witPerson.h"

class WITStudent : public WITPerson {
public:
	WITStudent(void); 
	WITStudent(string name, string add, string num);  
	WITStudent(string name, string add, string num, string rate, string hours); 
	virtual ~WITStudent(void); 
	virtual string payMe(void)override;
private:
	WITStudent(const WITStudent & Obj);
	WITStudent & operator = (const WITStudent & Obj);
};
#endif