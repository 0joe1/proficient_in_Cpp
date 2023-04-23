#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(void)
{
    vector<unsigned> scores(11,0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            auto iter = scores.begin()+grade/10;
            (*iter)++;
        }
    }
    for (auto s:scores)
        cout << s << endl;
    return 0;
}

