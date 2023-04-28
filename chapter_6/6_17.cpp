#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool find_upper(const string& s)
{
    for (auto ch:s)
        if (isupper(ch))
            return 1;
    return 0;
}
void allToLower(string& s)
{
    for (auto &ch:s)
        ch=tolower(ch);
}

int main(void)
{
    string s("Hello,World");
    if (find_upper(s))
        printf("find\n");
    else
        cout << "not found" << endl;
    allToLower(s);
    cout << s << endl;
    return 0;
}
