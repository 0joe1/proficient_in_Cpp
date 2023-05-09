#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

inline string make_plural(size_t ctr,const string &word,const string &ending="s")
{
    return (ctr>1)?word+ending:word;
}

int main(void)
{
    cout << make_plural(2,"success","es") <<endl;
    cout << make_plural(2,"failure") <<endl;
    return 0;
}

