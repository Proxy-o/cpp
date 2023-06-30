#include <iostream>
#include <fstream>

class MySed
{
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string _buffer;
    std::string _output;

public:
    MySed(std::string filename, std::string s1, std::string s2);
    ~MySed();
    void replace();
    void write();
    void read();
    void print();
};