#include <iostream>

struct Book{
    unsigned int ino;
    std::string title;
    double revenue;
};

void getbook(struct Book* book)
{
    std::cin >> book->ino >> book->title >> book->revenue;
}
int main(void)
{
    struct Book tbook,sumbook;
    getbook(&sumbook);
    getbook(&tbook);
    while (tbook.ino == sumbook.ino)
    {
        sumbook.revenue = tbook.revenue+sumbook.revenue;
        getbook(&tbook);
    }
    std::cout<<sumbook.revenue<< std::endl;
            


    //std::cout<<book1.revenue<< std::endl;

    return 0;
}
