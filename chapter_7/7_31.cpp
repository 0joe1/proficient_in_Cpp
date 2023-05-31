#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Y;
class X{
    Y* point_y=nullptr;
};
class Y{
    X object_x;
};


int main(void)
{
    return 0;
}


