#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class practice{
private:
    string h;
public:
    void getstr(std::istream& = cin);
    void display()
    {
        cout << h <<endl;
    }
};

int main(void)
{
    practice p;
    p.getstr();
    p.display();
    return 0;
}

void practice::getstr(std::istream& in)
{
    getline(in,h);
}
