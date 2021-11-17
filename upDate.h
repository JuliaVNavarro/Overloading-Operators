//  Navarro, Julia
//  Class (CECS 282-02)
//  Prog 3 – upDate OverLoading Operators
//  Due 9/27/21
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.

#ifndef upDate_h
#define upDate_h
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class upDate{
  private:
    int *mdy;
    static int count;
  public:
    upDate();
    upDate(int M, int D, int Y);
    upDate(int J);
    upDate(const upDate&); //copy constructor
    ~upDate();
    void setDate(int M, int D, int Y);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    string getMonthName();
    upDate operator=(upDate d);
    upDate operator+=(int x);
    upDate operator-=(int x);
    friend upDate operator+(const upDate &d, int x);
    friend upDate operator-(const upDate &d, int x);
    friend upDate operator+(int x, const upDate &d);
    friend int operator-(const upDate &d1, const upDate &d2);
    friend ostream & operator<<(ostream & out, upDate d);
    int julian()const;
    static int GetDateCount();
    upDate operator++(int);
    upDate operator++();
    upDate operator--(int);
    upDate operator--();
    bool operator==(const upDate &d);
    bool operator>(const upDate &d);
    bool operator<(const upDate &d);
};

#endif