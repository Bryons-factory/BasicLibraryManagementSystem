#ifndef STAFF_H
#define STAFF_H
#include "Faculty.h"

#include <string>
#include <iostream>
class Staff : public Faculty {
public:
	int StaffID() {
		return 	facultyID();
	}
};

#endif