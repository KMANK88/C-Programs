//
//  Calendar.cpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/3/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//
#include <iostream>
#include <iomanip>
using namespace std;


bool isLeapYear(int year){
    return year % 400 == 0 || (year % 4 == 0 && year % 100 !=0);
    //given to us
}

int getStartDay(int year,int month){
    int d[12] = {0,3,2,5,0,3,5,1,4,6,2,4};  //Location of days on a calender
    int a = year - (month < 2);
    a=(a + a/4 - a/100 + a/400 + d[month]+1) % 7;

    return a;
    //Found the calculation on stack Overflow. Deals with putting date in correct spot for each month.
}

string getMonth(int num){
    //A string for months 0 is Jan, and 11 is Dec.
    string month[] = {"January", "Febuary", "March","April", "May", "June","July", "August", "September","October", "November", "December"};
    
    return (month[num]);
}
int getDaysinMonth (int year, int month){
    int LongMonth = 31;
    int shortMonth = 30;
    int leap = 29;
    int notLeap = 28;
    if (month == 0){            //Using getMonth we can loop through the string array and find which number corrispondsto the the right number of days for the month
        return (LongMonth);
    } else if (month == 1){
        if(isLeapYear(year)){
            return(leap);
        }else{
            return(notLeap);
        }
    } else if (month == 2){
        return (LongMonth);
    }else if (month == 3){
        return (shortMonth);
    } else if (month == 4){
        return (LongMonth);
    }else if (month == 5){
        return (shortMonth);
    }else if (month == 6){
        return (LongMonth);
    } else if (month == 7){
        return (LongMonth);
    }else if (month == 8){
        return (shortMonth);
    }else if (month == 9){
        return (LongMonth);
    }else if (month == 10){
        return (shortMonth);
    }else if (month == 11){
        return (LongMonth);
    }
    return 0;
}

// Function to print the calendar of the given year
void showData(int year, int month){
    int amountOfDays = 0;
    int start = 0;
    int space;
    
    start = getStartDay(year, month);
    amountOfDays = getDaysinMonth(year, month);
    
    cout<< "            " << getMonth(month) << " " << year << endl;  //where month is printed and year
    cout << "  -----------------------------------" << endl;    //nice line for profesonalisum
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat"<< endl;   //days

    //dealing with spacing in the calender output
    for ( space= 0; space < start; space++){
            printf("     ");
    }
        for (int x = 1; x <= amountOfDays; x++){
            cout << setw(5) << x;
            if (++space > 6){
                space = 0;
                cout << endl;
            }
        }
    cout << endl;
    return;
}
int main(){
    int year = 0;
    int month = 0;
    cout<< "Enter the Year" << endl;
    cin >> year;
    cout << "Enter the Month" << endl;
    cin >> month;
    showData(year,month-1);
    return 0;
}

