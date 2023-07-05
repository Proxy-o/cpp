#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);
	void addContact(void);
	int printContacts(void) const;
	void search(void) const;

private:
	Contact _contacts[8];
	std::string _getTenChars(std::string str) const;
};
#endif