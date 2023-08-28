#include <string>
#include <iostream>

using std::cout;
using std::endl;



class Sales_data{
     //friend Sales_data add(const Sales_data &lhs,const Sales_data &rhs);
     friend std::istream &read(std::istream &is,Sales_data &item);
     //friend std::ostream &print(std::ostream &os,const Sales_data &item);
public:
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){cout <<"normal construct"<<endl;}
    Sales_data():Sales_data("",0,0){cout << "nothing"<<endl;}
    Sales_data(const std::string &s):Sales_data(s,0,0){cout<<"string s construct"<<endl;}
    Sales_data(std::istream &is):Sales_data(){cout<<"read from istream"<< endl;read(is,*this);};

    std::string isbn() const {return this->bookNo;}
    Sales_data &combine(const Sales_data& item);

private:
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
    double avg_price()const{return units_sold?revenue/units_sold:0;}
};

 //Sales_data add(const Sales_data &lhs,const Sales_data &rhs);
std::istream &read(std::istream &is,Sales_data &item){
    double price=0;
    is >>item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold*price;
    return is;
}
 //std::ostream &print(std::ostream &os,const Sales_data&item);

int main(void)
{
    cout << "predict 1 :" <<endl;
    cout << "normal construct" <<endl;
    cout <<"nothing" <<endl;
    cout << "real: " <<endl;
    Sales_data data1;

    cout << "predict 2 :" <<endl;
    cout << "normal construct" <<endl;
    cout <<"string s construct" <<endl;
    cout << "real: " <<endl;
    Sales_data data2(std::string("hello"));

    cout << "predict 3 :" <<endl;
    cout << "normal construct" <<endl;
    cout << "nothing" <<endl;
    cout << "read from istream" <<endl;
    cout << "real: " <<endl;
    Sales_data data3(std::cin);
    return 0;
}
