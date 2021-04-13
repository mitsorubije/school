#include <iostream>
#include "shape.h"

//testování virtuální metody
void TestShapes(){
    cout << "Testovani virtualni metody: " << endl;
    Shape* s1 = new Square(3);
    double area = s1->GetObsah();
    cout << "Square obsah: " << area << endl;

    Shape* s2 = new Circle(3);
    double obvod = s2->GetObvod();
    cout << "Circle obvod: " << obvod << endl;
}

int main() {
    //testování běžným způsobem:

    Square * ctverec = new Square(3);
    ctverec->Print();
    cout << endl;

    Circle * kruznice = new Circle(3);
    kruznice->Print();
    cout << endl;

    Rectangle * obdelnik = new Rectangle(3, 4);
    obdelnik->Print();
    cout << endl;

    //testování virtuální metody:

    TestShapes();

    return 0;
}