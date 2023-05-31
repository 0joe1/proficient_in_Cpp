#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

class Screen{
public:
    typedef std::string::size_type pos;
    Screen()=default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
private:
    pos height=0,width=0;
    pos cursor = 0;
    std::string contents;

};



int main(void)
{
    return 0;
}
