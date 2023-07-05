#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string Contact::_getSinglInput(std::string str) const
{
	std::string input;

	std::cout << "Please enter " << str << std::endl;
	std::cin.clear();
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);

	return (input);
}

void Contact::setData(void)
{
	this->_firstName = this->_getSinglInput("your first name");
	this->_lastName = this->_getSinglInput("your last name");
	this->_nickname = this->_getSinglInput("your nickname");
	this->_phoneNumber = this->_getSinglInput("your phone number");
	this->_darkestSecret = this->_getSinglInput("your darkest secret");
}

void Contact::setIndex(int index)
{
	this->_index = index;
}
int Contact::getIndex(void) const
{
	return (this->_index);
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void Contact::displaySingle(void) const
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
}