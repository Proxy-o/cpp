#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    PhoneBook phoneBook;
    std::string command;


    while (1) {
        std::cout << "Please enter a command ADD, SEARCH or EXIT" << std::endl;
        std::cin >> command;
        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.printContacts();
            phoneBook.search();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
return 0;
}
