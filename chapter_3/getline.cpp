#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::getline;

int main(void)
{
    string a;
    while(getline(cin,a))
        cout <<"something" << a << endl;

    return 0;
}
