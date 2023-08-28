#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class NoDefault{
public:
    int a;
    NoDefault(int x){a=x;}
};

class C{
public:
    C(int x):d(x){}
    NoDefault d;
};

int main(void)
{
    return 0;
}

