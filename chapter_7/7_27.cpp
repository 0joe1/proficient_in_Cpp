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

    Screen& move(pos ht,pos wd);
    Screen& set(char c);
    void display(std::ostream&) const;
private:
    pos height=0,width=0;
    pos cursor = 0;
    std::string contents;

};

inline Screen& Screen::move(pos ht,pos wd)
{
    cursor = ht*width + wd;
    return *this;
}
Screen& Screen::set(char c)
{
    contents[cursor]=c;
    return *this;
}
void Screen::display(std::ostream& out) const
{
    out << contents<<endl;
}


int main(void)
{
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    return 0;
}

