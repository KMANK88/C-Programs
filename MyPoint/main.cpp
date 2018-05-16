//
//  main.cpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/21/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>

#include "point.cpp"
int main()
{
    MyPoint p1(1, 2);
    MyPoint p2(4, 2.5);
    cout << p1.distance(p2) << endl;
    p1.setX(1);
    p1.setY(1);
    p2.setX(2);
    p2.setY(2);
    cout << p1.distance(p2) << endl;
    ThreeDPoint p3(2,3,1);
    ThreeDPoint p4(8,-5,0);
    cout << p3.distance(p4) << endl;
    return 0;
}
