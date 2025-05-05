// thall
// header file for NewUser class
/***********************************
* feature description:
* there will be three types of users: students, faculty, and staff.
* All users can use this feature to register a new user by collecting
* demographic information to create an account.
*
* functional requirements:
* a) the system collects the user's first name, last name,
* address, phone number, email, password, and institutionalID
* (staffID, employeeID, studentID).
* b) the system must verify and accept only valid information
* c) the system must store user registration details in a text file
* d) the system should assign a library ID, which will server as the
* login ID for accessing library services.
*
*
*
*/
#ifndef NEWUSER_H
#define NEWUSER_H
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class NewUser {
public:
	// Constructor
	NewUser();
	// Destructor
	~NewUser();
	// Copy constructor
	NewUser(const NewUser& other);
	// Member function to register a new user
	User RegisterNewUser();
	
	
};
#endif // NEWUSER_H

