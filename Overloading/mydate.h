//
//  mydate.h
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/17/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#ifndef mydate_h
#define mydate_h

#include <iostream>

using namespace std;

class Date{
  
    
public:
    Date(int m=1, int d=1, int y=1900);//constructor
    void setDate(int mm, int dd, int yy); // set the date
    Date &operator++();// preincrement operator
    Date operator++(int);//post increment operator
    Date &operator+=(int additionalDays); // add days, modify object
    bool isLeapYear(int y); // is theis a leap year?
   bool endOfMonth(int d); // is this end of Month?
    string returnMonth(int m);
    friend ostream &operator<< (ostream &output, const Date &d);
    
private:
    int month;
    int day;
    int year;
    string monthName;
    
    static const int days[]; // array of days per month
    void helpIncrement(); // utility function
    
};



#endif
