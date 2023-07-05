#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to Your Awesome PhoneBook" << std::endl;
	return;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "Goodbye!" << std::endl;
	return;
}

void PhoneBook::addContact(void)
{
	static int index;

	this->_contacts[index % 8].setData();
	this->_contacts[index % 8].setIndex(index % 8);
	index++;
	return;
}

void PhoneBook::search(void) const
{
	int index;
	std::string input;
	index = -1;

	while (index < 0 || index > 7 || this->_contacts[index].getFirstName() == "")
	{
		std::cout << "Please enter the index of the contact you want to see" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
			index = input[0] - '0';
		else
			std::cout << "Invalid index" << std::endl;
	}
	this->_contacts[index].displaySingle();
	return;
}

std::string PhoneBook::_getTenChars(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}
int PhoneBook::printContacts(void) const
{
	if (this->_contacts[0].getFirstName() == "")
	{
		std::cout << "No contacts to display" << std::endl;
		return 0;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].getFirstName() == "")
			break;
		std::cout << std::setw(10) << this->_contacts[i].getIndex() << "|" << std::flush;
		std::cout << std::setw(10) << this->_getTenChars(this->_contacts[i].getFirstName()) << "|" << std::flush;
		std::cout << std::setw(10) << this->_getTenChars(this->_contacts[i].getLastName()) << "|" << std::flush;
		std::cout << std::setw(10) << this->_getTenChars(this->_contacts[i].getNickname()) << std::endl;
	}
	return 1;
}