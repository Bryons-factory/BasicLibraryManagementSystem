#ifndef FACULTY_H
#define FACULTY_H
#include "User.h"

#include <string>
#include <iostream>
class Faculty : public User{
public:
	int facultyID() {
		return 	getInstitutionalID();
	}
};

#endif