// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#ifndef WITSTAFF_H
#define WITSTAFF_H
#include "witPerson.h"

class WITStaff : public WITPerson {
public:
	WITStaff(void);
	WITStaff(string name, string add, string num);
	WITStaff(string name, string add, string num, string rate, string hours);
	virtual ~WITStaff(void);
	virtual string payMe(void)override;
private:
	WITStaff(const WITStaff & srcFile);
	WITStaff & operator = (const WITStaff & srcFile);
};
#endif