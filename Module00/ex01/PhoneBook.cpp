#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to Your Awesome PhoneBook" << std::endl;
	return ;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "Goodbye!" << std::endl;
	return ;
}

void PhoneBook::addContact(void)
{
	static int	index;

	this->contacts[index % 8].setData();
	this->contacts[index % 8].setIndex(index % 8);
	index++;
	return ;
}

void PhoneBook::search(void) const
{
	int index;
	index = -1;
	while (index < 0 || index > 7 || this->contacts[index].getFirstName() == "")
	{
		std::cout << "Please enter the index of the contact you want to see" << std::endl;
		std::cin >> index;
	}
	this->contacts[index].displaySingle();
	return ;
}

std::string PhoneBook::getTenChars(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}
void PhoneBook::printContacts(void) const
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].getFirstName() == "")
			break ;
		std::cout << "         " << this->contacts[i].getIndex() << "|" << std::flush;
		std::cout << std::setw(10) << PhoneBook::getTenChars(this->getTenChars(this->contacts[i].getFirstName())) << "|" << std::flush;
		std::cout << std::setw(10) << PhoneBook::getTenChars(this->getTenChars(this->contacts[i].getLastName())) << "|" << std::flush;
		std::cout << std::setw(10) << PhoneBook::getTenChars(this->getTenChars(this->contacts[i].getNickname())) << std::endl;
	}
	return ;
}