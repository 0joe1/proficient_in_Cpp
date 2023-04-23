#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;


int main(void)
{
    vector<int> a;
    int t;
    while (cin >> t )
    {
        a.push_back(t);
    }
    for (auto t:a)
        cout << t << endl;
    return 0;
}
