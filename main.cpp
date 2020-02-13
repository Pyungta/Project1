#include "resistorBands.h"
#include <iostream>
#include <cmath>
#include <iomanip>


using std::cin;
using std::cout;
using std::endl;

//Tolerance function
double toler(char c)
{
    //define variable with double type
    double tol = 0.0; //tolerance
    //tolerance can be defined by char c variable
    //each Letter has tolerance value
    if(c == 'n')
    {
        tol = 0.01;
    }
    else if(c == 'r')
    {
        tol = 0.02;
    }
    else if(c == 'w')
    {
        tol = 0.05;
    }
    else if(c == 'g')
    {
        tol = 0.005;
    }
    else if(c == 'b')
    {
        tol = 0.0025;
    }
    else if (c == 'v')
    {
        tol = 0.001;
    }
    else if(c == 'y')
    {
        tol = 0.0005;
    }
    else if(c == 'd')
    {
        tol = 0.05;
    }
    else if(c == 's')
    {
        tol = 0.1;
    }
    return tol;
}
//Figure function
int figure(char c1)
{
    // int variable i
    int i = 0;
    //each Letter's figure value
    if (c1 == 'k')
    {
        i = 0;
    }
    else if(c1 == 'n')
    {
        i = 1;
    }
    else if(c1 == 'r')
    {
        i = 2;
    }
    else if(c1 == 'o')
    {
        i = 3;
    }
    else if(c1 == 'w')
    {
        i = 4;
    }
    else if(c1 == 'g')
    {
        i = 5;
    }
    else if(c1 == 'b')
    {
        i = 6;
    }
    else if (c1 == 'v')
    {
        i = 7;
    }
    else if(c1 == 'y')
    {
        i = 8;    }
    else if(c1 == 'e')
    {
        i = 9;
    }
    return i;
        
}

void resistorBands(istream& in, ostream& out)
{
    // define string variable input
    string input;
    //type in input variable
    in >> input;
    // put input to myString variable
    string myString = input;
    //get the length of myString
    int length = myString.length();// string length
    // divide string to char array
    char c1 = myString[0];
    char c2 = myString[1];
    char c3 = myString[2];
    char c4 = myString[3];
    char c5 = myString[4];
    double p, q, r, s, m;
    double tolerance;
    double resistance; //resistor
    int lower, upper; //tolerance lower and upper bounds
    
    
    
    if(length == 3)
    {
        p = 10 * figure(c1);
        q = figure(c2);
        r = figure(c3);
        tolerance = 0.2;  //20%
        m = pow(10, r); //multiplier
        resistance = (p + q) * m; //resistance
        upper = resistance * (1+tolerance); //upper
        lower = resistance * (1-tolerance); //lower
        out << "Resistance: "<<std::setprecision(0)<< std::fixed<< resistance<<endl; //fixed with setprecision 0 (print resistance)
        out << "Lower: " <<lower << endl; //print lower
        out << "Upper: " <<upper << endl; //print upper
    }
    else if (length == 4)
    {
        p = 10 * figure(c1);
        q = figure(c2);
        r = figure(c3);
        m = pow(10, r);
        tolerance = toler(c4); //tolerance
        resistance = (p + q) * m; //resistance
        upper = resistance * (1+tolerance); //upper
        lower = resistance * (1-tolerance); //lower
        out << "Resistance: "<< std::setprecision(0) << std::fixed << resistance<< endl; // fixed with setprecision 0(print resistance)
        out << "Lower: " <<lower << endl; //print lower
        out << "Upper: " <<upper << endl; //print upper
    }
    else if (length == 5)
    {
        p = 100 * figure(c1);
        q = 10 *figure(c2);
        r = figure(c3);
        s = figure(c4);
        m = pow(10, s); //multiplier
        tolerance = toler(c5); //tolerance
        resistance = (p+q+r) * m; //resistance
        upper = resistance * (1+tolerance); //upper
        lower = resistance * (1-tolerance); //lower
        out << "Resistance: "<< std::setprecision(0)<< std::fixed << resistance<< endl; //fixed with setprecision 0(print resistance)
        out << "Lower: " <<lower << endl; //print lower
        out << "Upper: " <<upper << endl; //print upper
    }
    
}


int main()
{
    // resistorBands function
    resistorBands(cin, cout);
    
    return 0;
}
