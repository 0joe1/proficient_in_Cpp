#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(void)
{
    string line;
    getline(cin,line);
    cout << line << endl;

    char ch;
    cin >> ch;
    cout << ch <<endl;
    return 0;
}
