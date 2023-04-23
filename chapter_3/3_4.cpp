#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::endl;


int main(void)
{
    string s1,s2;
    
    getline(cin,s1);
    getline(cin,s2);
    if (s1 == s2)
        cout << "these two string are equal" << endl;
    else
        cout << "the larger one is " << ((s1>s2)?s1:s2) <<endl; 

    if (s1.size() == s2.size())
        cout << "these two string have same length" <<endl;
    else
        cout << "the longer one is " << ((s1.size()>s2.size())?s1:s2) <<endl;
    return 0;
}
