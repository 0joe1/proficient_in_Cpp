#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void lookLook(vector<int>& vec)
{
    vector<int> v=*vec;
    for (auto it=v.begin();it != v.end();it++)
        cout << *it <<endl;
}


int main(void)
{
    vector<int> v1;  //0
    vector<int> v2(10);  //1 10
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};

    return 0;
}

