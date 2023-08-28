#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int a[9]={1,2,3};


void func(void)
{
    int b[9]={1,2,3};
    cout << a[3] <<endl;
    cout << b[3]<<endl;
}

int main(void)
{
    func();
    return 0;
}

