#include <iostream>

int main(void)
{
    const int a=10,&b=a;
    int c=b;
    constexpr int null=0;
    int *p=null;
    /*const.cpp: 在函数‘int main()’中:
const.cpp:8:12: 错误：invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
    8 |     int *p=null;
      |            ^~~~
      |            |
      |            int
*/
}
