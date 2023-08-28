#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;


class Screen;

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    std::vector<Screen> screens;
};

class Screen{
friend void Window_mgr::clear(ScreenIndex);
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

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s=screens[i];
    s.contents = std::string(s.height*s.width,' ');
}

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
    Window_mgr window;
    window.screens.push_back(myScreen);
    window.screens[0].display(cout);
    window.clear(0);
    window.screens[0].display(cout);


    return 0;
}

