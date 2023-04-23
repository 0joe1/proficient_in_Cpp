#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(void)
{
    vector<int> vec;    
    int t;
    for (int i=0;i<10;i++)
    {
        cin >> t;
        vec.push_back(t);
    }

    for (auto iter=vec.begin();iter!=vec.end();iter++)
        *iter *= 2;
    for (auto iter=vec.cbegin();iter!=vec.cend();iter++)
        cout << *iter <<endl;

    return 0;
}

