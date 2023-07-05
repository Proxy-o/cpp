
#include <iostream>

int main(int argc, char const *argv[])
{

    std::string result;

    if (argc == 1)
        result = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {

        for (int i = 1; i < argc; ++i)
        {
            std::string arg(argv[i]);

            for (size_t j = 0; j < arg.length(); ++j)
            {
                char c = arg[j];
                if (std::islower(c))
                {
                    c = std::toupper(c);
                }
                result += c;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}
