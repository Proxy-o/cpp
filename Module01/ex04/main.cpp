#include "my_sed.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./my_sed filename s1 s2" << std::endl;
        return 1;
    }
    else
    {
        MySed my_sed(argv[1], argv[2], argv[3]);
        my_sed.replace();
        my_sed.write();
        my_sed.read();
        my_sed.print();
    }
    return 0;
}
