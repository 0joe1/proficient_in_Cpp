#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(void)
{
    vector<int> ivec(10,3);
    for (decltype(ivec.size()) i=0;i<10;i++) 
        ivec[i]=666;
    for (decltype(ivec.size())i=0;i<10;i++)
        cout<<ivec[i]<<endl;
    return 0;
}
