#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void)
{
    string str;
    vector<string> vec;
    while (cin >> str)
        vec.push_back(str);
    for (auto &t:vec)
    {
        for (auto &ch:t)
            ch = toupper(ch);
        cout << t << endl;
    }
    return 0;
}
