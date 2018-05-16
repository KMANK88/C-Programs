//
//  MYDATE.cpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/17/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include "mydate.h"
#include <iostream>


Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
    returnMonth(month);
    
}

void Date::setDate(int mm, int dd, int yy){
    month = mm;
    day = dd;
    year = yy;
    return;
}

 Date& Date::operator++(){
     if (endOfMonth(this->day) == true){
         
     }else{
     ++ this->day;
     }
    return *this;
}


Date Date::operator++(int){
    Date temp;
    temp.day = this->day;
    temp.monthName = this->returnMonth(month);
    temp.year = this->year;
    if(endOfMonth(this->day) == false){
    ++this->day;
    }
    return temp;
}


Date& Date::operator+=(int additionDays){
    
    this->day += additionDays;
    return *this;
}


bool Date::isLeapYear(int y){
    bool ans;
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 !=0)){
        cout << "Leap year" << endl;
        ans = true;
    }else {
        cout << "Not a leap Year" << endl;
        ans = false;
    }
    return ans;
}

bool Date::endOfMonth(int d){
    if(month ==2 && (&Date::isLeapYear) && d==29){
        this->day = 1;
        this->month = month +1;
        returnMonth(this->month);
        return true;
    }else if(month == 2  && d==28){
        this->day = 1;
        this->month = month +1;
        returnMonth(this->month);
        return true;
    }else if((month == 4 || month ==6 || month ==8 || month== 9)&& d == 30){
        this->day = 1;
        this->month = month +1;
        returnMonth(this->month);
        return true;
    }else if((month ==1 ||month ==3 || month ==5 || month ==7 || month ==8 || month ==10 || month ==12) && d == 31){
        this->day = 1;
        this->month = month +1;
        if(this->month == 13){
            this->month = 1;
            this->year = year+1;
        }
        returnMonth(this->month);
        return true;
    }else{
        return false;
    }
}

string Date::returnMonth(int month){
    
    if(month ==1){
        monthName = "January";
    }else if(month ==2){
        monthName = "February";
    }else if(month ==3){
        monthName = "March";
    }else if(month == 4){
        monthName = "April";
    }else if(month == 5){
        monthName = "May";
    }else if(month == 6){
        monthName = "June";
    }else if(month == 7){
        monthName = "July";
    }else if(month == 8){
        monthName = "August";
    }else if(month ==9){
        monthName = "September";
    }else if(month ==10){
        monthName = "October";
    }else if(month == 11){
        monthName = "November";
    }else if(month == 12){
        monthName = "December";
    }else{
        monthName = "Incorrect month selected";
    }
    return monthName;
}

ostream& operator<< (ostream &output, const Date &d){
    output << d.monthName << " " << d.day << ", " << d.year << endl;
    return output;
    }

