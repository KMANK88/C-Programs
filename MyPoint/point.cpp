//
//  point.cpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/21/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class MyPoint{
public:
    MyPoint(){
        x = 0;
        y = 0;
        
    };
    
    MyPoint(double X , double Y){
        x = X;
        y = Y;
    };
    
    void setX(double X){
        x = X;
    };
    void setY(double Y){
        y = Y;
    };
    
    double getX(){
        return x;
        
    };
    
    double getY(){
        return y;
    };
    
    double distance(MyPoint point){
        return  sqrt((pow((point.getX() - this->getX()),2)+ pow((point.getY() - this->getY()),2)));
    };
    
protected:
    double x;
    double y;
};

class ThreeDPoint : public MyPoint {
public:
    ThreeDPoint () {
        x =0;
        y =0;
        z =0;
    };
    
    ThreeDPoint (double X, double Y, double Z){
        x = X;
        y = Y;
        z = Z;
    };
    
    void setZ(double Z){
        z = Z;
    };
    
    double getZ(){
        return z;
    };
    
    double distance(ThreeDPoint point){
        
        //cout << "Regular andd this" << point.getX() << point.getY() << point.getZ() <<endl;
       // cout << this->getX() <<  this->getY() << this->getZ() << endl;
        return sqrt((pow((point.getX() - this->getX()),2)+ pow((point.getY() - this->getY()),2))+ (pow((point.getZ() - this->getZ()),2)));
    };
    
private:
    double z;
};
