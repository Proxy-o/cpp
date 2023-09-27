#include <iostream>
class A
{
};
class B : public A
{
};
int main()
{
    // int a = 56;
    A *a;
    B *b;
    b = (B *)a;

    return 0;
}
