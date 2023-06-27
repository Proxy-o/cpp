#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	std::string getTenChars(std::string str) const;

  public:
	PhoneBook(void);
	~PhoneBook(void);
	void addContact(void);
	void printContacts(void) const;
	void search(void) const;

	Contact contacts[8];
};
#endif