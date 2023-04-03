#include <iostream>
#include "Sales_item.h"

int main(void)
{
    Sales_item tbook,sum;
    int num=0;
    int c=0;

    while (std::cin >> tbook && c<5)
    {
        sum += tbook;
        num++;
        c++;

        std::cout << tbook.isbn()<<sum.isbn()<<std::endl;
        if (tbook.isbn() != sum.isbn())
        {
            std::cout <<"有" <<num <<"条记录"<< std::endl;
            num = 1;
            sum=tbook;
        }
    }

    return 0;
}
