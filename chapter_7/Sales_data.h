#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

class Sales_data{
    friend Sales_data add(const Sales_data &lhs,const Sales_data &rhs);
    friend std::istream &read(std::istream &is,Sales_data &item);
    friend std::ostream &print(std::ostream &os,const Sales_data &item);
public:
    Sales_data()=default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(std::istream &is);

    std::string isbn() const {return this->bookNo;}
    Sales_data &combine(const Sales_data& item);

private:
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
    double avg_price()const{return units_sold?revenue/units_sold:0;}
};

Sales_data add(const Sales_data &lhs,const Sales_data &rhs);
std::istream &read(std::istream &is,Sales_data &item);
std::ostream &print(std::ostream &os,const Sales_data&item);


#endif
