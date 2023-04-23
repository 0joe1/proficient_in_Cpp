#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cout;
using std::endl;
int main(void)
{
    string ex = "yes,this is an ,you know ,an , example.";
    string ans;
    for (auto &a : ex)
        if (!ispunct(a))
            ans += a;
    cout<< ans << endl;

    return 0;
}
