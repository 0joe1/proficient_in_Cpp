#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(void)
{
    vector<int> ivec;
    for (int i=0;i<10;i++)
    {
        int t;
        cin >> t;
        ivec.push_back(t);
    }
    /*for (int i=0;i<ivec.size()-1;i++)
        cout << ivec[i]+ivec[i+1] << endl;
     */
    for (decltype(ivec.size()) i=0;i<ivec.size()/2;i++)
        cout << ivec[i]+ivec[ivec.size()-i-1] << endl;

    return 0;
}
