#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main(void)
{
    vector<string> a;
    string t;
    while (cin >> t )
    {
        a.push_back(t);
    }
    for (auto t:a)
        cout << t << endl;
    return 0;
}

