#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* argv[])
{
    string ret;
    for (int i=1;i<argc;i++)
        ret += argv[i];
    cout << ret << endl;
    return 0;
}
