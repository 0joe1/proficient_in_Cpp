#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

int main(void)
{
    string example("this is a test");
    for (char &a:example)
        a='X';
    cout << example << endl;
    return 0;
}
