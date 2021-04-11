#include <iostream>
#include "shape.h"

int main() {
    Shape * tvar = new Shape(9);
    tvar->Print();
    cout << endl;

    Square * ctverec = new Square(3);
    ctverec->Print();
    cout << endl;

    Circle * kruznice = new Circle(2);
    kruznice->Print();
    cout << endl;

    Rectangle * obdelnik = new Rectangle(3, 4);
    obdelnik->Print();
    cout << endl;

    return 0;
}