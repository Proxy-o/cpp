#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	void setData(void);
	void displaySingle(void) const;
	void setIndex(int index);
	int getIndex(void) const;
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
	int _index;
	std::string _getSinglInput(std::string str) const;
};

#endif