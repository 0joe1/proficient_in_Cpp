#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::endl;

int main(void)
{
    string sum,t;
    getline(cin,sum);
    for (int i=0;i<4;i++)
    {
        getline(cin,t);
        sum += " "+t; 
    }
    cout << sum << endl;
    return 0;
}
