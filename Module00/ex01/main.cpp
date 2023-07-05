#include <iostream>
#include "PhoneBook.hpp"

int main()
{

    PhoneBook phoneBook;
    std::string command;

    while (1)
    {
        std::cout << "Please enter a command ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            if (phoneBook.printContacts())
                phoneBook.search();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else if (std::cin.eof())
        {
            break;
        }
        else
        {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}
