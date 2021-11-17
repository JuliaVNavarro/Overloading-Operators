//  Navarro, Julia
//  Class (CECS 282-02)
//  Prog 3 – upDate OverLoading Operators
//  Due 10/1/21
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.

#include "upDate.h"
#include <iostream>
#include <string>
using namespace std;

//converts a Gregorian date t oa Julian date
int Greg2Julian2(int month, int day, int year){
  int J = month;
  int K = day;
  int I = year;

  int JD = K - 32075 + 1461 * (I + 4800 + (J - 14)/12)/4 + 367 * (J - 2 - (J - 14)/12 * 12)/12 - 3 * ((I + 4900 + (J - 14)/12)/100)/4;

  return JD;
}

//converts a Julian date to a Gregorian date
void Julian2Greg2(int JD, int & month, int & day, int & year){
  
  int L = JD + 68569;
  int N = 4 * L/146097;
  L = L - (146097 * N + 3)/4;
  int I = 4000 * (L + 1)/1461001;
  L = L - 1461 * I/4 + 31;
  int J = 80 * L/2447;
  int K = L - 2447 * J/80;
  L = J / 11;
  J = J + 2 - 12 * L;
  I = 100 * (N - 49) + I + L;

  year = I;
  month = J;
  day = K;


}

int upDate::count = 0;

ostream & operator<<(ostream & out, upDate d){
  return out << d.getMonthName() << d.getDay() << ", " << d.getYear();
}

upDate::upDate(){
  mdy = new int[3];
  mdy[0] = 5;
  mdy[1] = 11;
  mdy[2] = 1959;
  count++;
}

upDate::upDate(int M, int D, int Y){
  mdy = new int[3];
  mdy[0] = M;
  mdy[1] = D;
  mdy[2] = Y;

  if(M > 12 || M < 1){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  else if(D > 31 || D < 1){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in February is invalid, the date will be the default date: May 11, 1959
  else if(D > 29 && M == 2){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in February is invalid, the date will be the default date: May 11, 1959
  else if(D > 28 && M == 2){
    if(Y%100 > 0 && Y%4 > 0){
      mdy[0]= 5;
      mdy[1]= 11;
      mdy[2]= 1959;
      
    }
    else if(Y%100 == 0 && Y%400 > 0){
      mdy[0]= 5;
      mdy[1]= 11;
      mdy[2]= 1959;
    }
  }
  //if the day in April is invalid, the date will be the default date: May 11, 1959
  else if( D > 30 && M == 4){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in June is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 6){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in September is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 9){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in November is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 11){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //otherwise, date will be constructed depending on user input
  else{
    mdy[0]= M;
    mdy[1]= D;
    mdy[2]= Y;
  }
  count++;
}

upDate::upDate(int J){
  int month = 1;
  int day = 1;
  int year = 2000;

  Julian2Greg2(J, month, day, year); 
  mdy = new int[3];
  mdy[0] = month;
  mdy[1] = day;
  mdy[2] = year;
  count++;
}

void upDate::setDate(int M, int D, int Y){

  if(M > 12 || M < 1){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  else if(D > 31 || D < 1){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in February is invalid, the date will be the default date: May 11, 1959
  else if(D > 29 && M == 2){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in February is invalid, the date will be the default date: May 11, 1959
  else if(D > 28 && M == 2){
    if(Y%100 > 0 && Y%4 > 0){
      mdy[0]= 5;
      mdy[1]= 11;
      mdy[2]= 1959;
      
    }
    else if(Y%100 == 0 && Y%400 > 0){
      mdy[0]= 5;
      mdy[1]= 11;
      mdy[2]= 1959;
    }
  }
  //if the day in April is invalid, the date will be the default date: May 11, 1959
  else if( D > 30 && M == 4){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in June is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 6){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in September is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 9){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //if the day in November is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 11){
    mdy[0]= 5;
    mdy[1]= 11;
    mdy[2]= 1959;
  }
  //otherwise, date will be constructed depending on user input
  else{
    mdy[0]= M;
    mdy[1]= D;
    mdy[2]= Y;
  }
}

int upDate::getMonth() const{
  int m = mdy[0];
  return m;
}

int upDate::getDay() const{
  int d = mdy[1];
  return d;
}

int upDate::getYear() const{
  int y = mdy[2];
  return y;
}

string upDate::getMonthName(){
  string monthArr[12] = {"January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};
  return monthArr[this->getMonth() - 1];
}

upDate::upDate(const upDate &d){ // copy constructor
  mdy = new int[3];
  mdy[0] = d.getMonth();
  mdy[1] = d.getDay();
  mdy[2] = d.getYear();

  *mdy = *(d.mdy);
  count++;
}

upDate::~upDate(){
  count--;
  delete [] mdy;

}

upDate upDate::operator=(upDate d){
  this->mdy[0] = d.mdy[0];
  this->mdy[1] = d.mdy[1];
  this->mdy[2] = d.mdy[2];
  *(this->mdy) = *(d.mdy);
  return *this;  
}

upDate upDate::operator+=(int x){
  int month = this->mdy[0];
  int day = this->mdy[1];
  int year = this->mdy[2];
  int J = Greg2Julian2(month, day, year);
  J += x;
  Julian2Greg2(J, month, day, year); 
  
  this->mdy[0] = month;
  this->mdy[1] = day;
  this->mdy[2] = year;
  
  
  return *this; 
}

upDate upDate::operator-=(int x){
  int month = this->mdy[0];
  int day = this->mdy[1];
  int year = this->mdy[2];
  int J = Greg2Julian2(month, day, year);
  J -= x;
  Julian2Greg2(J, month, day, year); 
  
  this->mdy[0] = month;
  this->mdy[1] = day;
  this->mdy[2] = year;
  
  
  return *this; 
}

upDate operator+(const upDate &d, int x){
  upDate d2;
  int month = d.mdy[0];
  int day = d.mdy[1];
  int year = d.mdy[2];

  int J = Greg2Julian2(month, day, year);
  J += x;
  Julian2Greg2(J, month, day, year);
  d2.mdy[0] = month;
  d2.mdy[1] = day;
  d2.mdy[2] = year;
  return d2;
}

upDate operator-(const upDate &d, int x){
  upDate d2;
  int month = d.mdy[0];
  int day = d.mdy[1];
  int year = d.mdy[2];

  int J = Greg2Julian2(month, day, year);
  J -= x;
  Julian2Greg2(J, month, day, year);
  d2.mdy[0] = month;
  d2.mdy[1] = day;
  d2.mdy[2] = year;
  return d2;
}

upDate operator+(int x, const upDate &d){
  upDate d2;
  int month = d.mdy[0];
  int day = d.mdy[1];
  int year = d.mdy[2];

  int J = Greg2Julian2(month, day, year);
  x += J;
  Julian2Greg2(x, month, day, year);
  d2.mdy[0] = month;
  d2.mdy[1] = day;
  d2.mdy[2] = year;
  return d2;
}

int operator-(const upDate &d1, const upDate &d2){
  int x;
  int month = d1.mdy[0];
  int day = d1.mdy[1];
  int year = d1.mdy[2];

  int j1 = Greg2Julian2(month, day, year);

  month = d2.mdy[0];
  day = d2.mdy[1];
  year = d2.mdy[2];

  int j2 = Greg2Julian2(month, day, year);

  x = j1 - j2;
  return x;
}

int upDate::julian() const{

  int month = this->mdy[0];
  int day = this->mdy[1];
  int year = this->mdy[2];

  int j = Greg2Julian2(month, day, year);
  return j;
}

int upDate::GetDateCount(){
  return count;
}

upDate upDate::operator++(){ //pre-increment
  int month = this->mdy[0];
  int day = this->mdy[1];
  int year = this->mdy[2];

  int j = Greg2Julian2(month, day, year);
  j++;
  Julian2Greg2(j, month, day, year);
  
  this->mdy[0] = month;
  this->mdy[1] = day;
  this->mdy[2] = year;

  return *this;
}

upDate upDate::operator++(int){ //post-increment
  upDate copy = *this;
  int month = this->mdy[0];
  int day = this->mdy[1];
  int year = this->mdy[2];

  int j = Greg2Julian2(month, day, year);
  j++;
  Julian2Greg2(j, month, day, year);
  
  this->mdy[0] = month;
  this->mdy[1] = day;
  this->mdy[2] = year;

  return copy;
}

upDate upDate::operator--(){ //pre-decrement
  int month = this->mdy[0];
  int day = this->mdy[1];
  int year = this->mdy[2];

  int j = Greg2Julian2(month, day, year);
  j--;
  Julian2Greg2(j, month, day, year);
  
  this->mdy[0] = month;
  this->mdy[1] = day;
  this->mdy[2] = year;

  return *this;
}

upDate upDate::operator--(int){ //post-decrement
  upDate copy = *this;
  int month = this->mdy[0];
  int day = this->mdy[1];
  int year = this->mdy[2];

  int j = Greg2Julian2(month, day, year);
  j--;
  Julian2Greg2(j, month, day, year);
  
  this->mdy[0] = month;
  this->mdy[1] = day;
  this->mdy[2] = year;

  return copy;
}

bool upDate::operator==(const upDate&d){
  if(this->julian() == d.julian()){
    return true;
  } else {
    return false;
  }
}

bool upDate::operator>(const upDate &d){
  if(this->julian() > d.julian()){
    return true;
  } else {
    return false;
  }
}

bool upDate::operator<(const upDate &d){
  if(this->julian() < d.julian()){
    return true;
  } else {
    return false;
  }
}