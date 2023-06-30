#include "my_sed.hpp"

MySed::MySed(std::string filename, std::string s1, std::string s2)
{
    this->_filename = filename;
    this->_s1 = s1;
    this->_s2 = s2;
    this->_output = std::string(this->_filename + ".replace");
}

MySed::~MySed()
{
}

void MySed::replace()
{
    std::ifstream ifs(this->_filename);
    if (ifs.is_open())
    {
        std::string content;
        if (std::getline(ifs, content, '\0'))
        {
            size_t pos = content.find(this->_s1);
            while (pos != std::string::npos)
            {
                content.erase(pos, this->_s1.length());
                content.insert(pos, this->_s2);
                pos = content.find(this->_s1);
            }
            this->_buffer = content;
        }
        else
        {
            std::cerr << "Empty file found." << std::endl;
        }
        ifs.close();
    }
    else
    {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
}

void MySed::write()
{
    std::ofstream ofs(this->_output);
    if (ofs.is_open())
    {
        ofs << this->_buffer;
        ofs.close();
    }
    else
    {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
}

void MySed::read()
{
    std::ifstream ifs(this->_output);
    if (ifs.is_open())
    {
        std::string content;
        if (std::getline(ifs, content, '\0'))
        {
            this->_buffer = content;
        }
        else
        {
            std::cerr << "Empty file found." << std::endl;
        }
        ifs.close();
    }
    else
    {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
}

void MySed::print()
{
    std::cout << this->_buffer << std::endl;
}