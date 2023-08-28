#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class NoDefault{
public:
    NoDefault(const std::string);
    std::string member;
};
struct A{
    NoDefault my_mem;
};
struct B{
    //B(){};
    NoDefault b_member;

};


int main(void)
{
    class C{
    public:
         int a;
    };

    C c;
    printf("%d",c.a);
    //A a;
    return 0;
}

