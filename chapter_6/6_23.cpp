#include <iostream>

using namespace std;

void print(const int (&j)[2])
{
    for (int i=0;i<2;++i)
        printf("%d",i);
}

int main(void)
{
    int j[2]={0,1};
    print(j);
    return 0;
}
