
// header file for user login class
// thall
/*****************************************
* class description:
* this class allows users to log in to the system. Users must enter
* valid login credentials before gaining access
*
* functional requirements:
* a) login credentials are provided during registration through
* the Register New Users class
* b) the system must allow access only to users with valid
* login credentials
* c) a member function of this class, PrintUserSumary, displays the user's
* complete borrowing history, currently borrowed books, and user information
* (first name, last name, address, phone number, email, password, and
* institutional ID (staffID, employeeID, studentID))
* d) users must be able to log out after completing their session
*
*
* what to expect:
* 1. there will be a prompt for the user to enter their username and password
* 2. the login will be successful if the username and password match
* 3. this class will access the storage class that manages the user credentials file
* 4. the user will be able to log out after completing their session
*
*****************************************/
#ifndef USERLOGIN_H
#define USERLOGIN_H
#include "User.h"
#include <string>
#include <iostream>

class UserLogin {
	// Add a public section to define the class members and methods
public:
	// Constructor
	UserLogin();

	// Destructor
	~UserLogin();

	// Copy constructor
	UserLogin(const UserLogin& other);

	// Member function to log in a user
	bool Login();

	// Member function to log out a user
	void Logout();

	// Member function to print user summary
	void PrintUserSummary() const;
};
#endif // USERLOGIN_H
