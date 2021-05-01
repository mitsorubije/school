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

void TestShapeSort(){
    Shape* s1 = new Square(3);
    Shape* s2 = new Circle(3);
    Shape* s3 = new Rectangle(3, 4);
    Shape* s4 = new Square(6);
    Shape* s5 = new Circle(9);
    Shape* s6 = new Rectangle(1, 4);

    Shape* pole[6] = {s1,s2,s3,s4,s5,s6};

    cout << "Poradi pred serazenim: " << endl;
    for(int x = 0; x < 6; x++){
        cout << pole[x]->GetObvod() << endl;
    }
    cout << endl;


    for(int i = 0; i < 5; i++){    
        for(int x = 0; x < 5-i; x++){ 
            if(pole[x]->GetObvod() > pole[x+1]->GetObvod()){
                Shape* temp = pole[x];
                pole[x] = pole[x+1];
                pole[x+1] = temp;
            }
        }
    }

    cout << "Poradi po serazeni: " << endl;
    for(int x = 0; x < 6; x++){
        cout << pole[x]->GetObvod() << endl;
    }
    cout << endl;

}

void Test3DShapes(){
    cout << "Testovani virtualni metody u 3D shapes: " << endl;
    ThirdDimensionObject* s1 = new Cube(3);
    double volume1 = s1->GetVolume();
    cout << "Cube objem: " << volume1 << endl;

    ThirdDimensionObject* s2 = new Sphere(3);
    double volume2 = s2->GetVolume();
    cout << "Ball objem: " << volume2 << endl;

    ThirdDimensionObject* s3 = new Block(3,3,4);
    double volume3 = s3->GetVolume();
    cout << "Block objem: " << volume3 << endl;
}

void Test3DShapeSort(){
    ThirdDimensionObject* s1 = new Cube(3);
    ThirdDimensionObject* s2 = new Sphere(3);
    ThirdDimensionObject* s3 = new Block(3, 4, 3);
    ThirdDimensionObject* s4 = new Cube(6);
    ThirdDimensionObject* s5 = new Sphere(9);
    ThirdDimensionObject* s6 = new Block(1, 4, 2);

    ThirdDimensionObject* pole[6] = {s1,s2,s3,s4,s5,s6};

    cout << "Poradi pred serazenim: " << endl;
    for(int x = 0; x < 6; x++){
        cout << pole[x]->GetVolume() << endl;
    }
    cout << endl;


    for(int i = 0; i < 5; i++){    
        for(int x = 0; x < 5-i; x++){ 
            if(pole[x]->GetVolume() > pole[x+1]->GetVolume()){
                ThirdDimensionObject* temp = pole[x];
                pole[x] = pole[x+1];
                pole[x+1] = temp;
            }
        }
    }

    cout << "Poradi po serazeni: " << endl;
    for(int x = 0; x < 6; x++){
        cout << pole[x]->GetVolume() << endl;
    }
    cout << endl;

}

void TestLogger(){
    HistoryLogger::ClearLogs();

    HistoryLogger::PrintLog(); //nic
    cout << endl;

    Shape* s1 = new Square(3);
    Shape* s2 = new Circle(3);
    Shape* s3 = new Rectangle(3, 4);
    Shape* s4 = new Square(6);

    //HistoryLogger::PrintLog(); //tady to vypíše ty 4 shapes
    //cout << endl;

    Shape* s5 = new Circle(5);
    Shape* s6 = new Circle(4);
    Shape* s7 = new Circle(1);

    HistoryLogger::PrintLog(); //tady to vypíše s3 až a7 (posledních 5)

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
    cout << endl;

    //serazeni:

    //TestShapeSort();

    Cube* cube1 = new Cube(4);
    cout << cube1->GetVolume() << endl;

    Sphere* sphere1 = new Sphere(3);
    cout << sphere1->GetVolume() << endl;

    Test3DShapes();

    //sort 3d itemu:
    Test3DShapeSort();

    //logger test:
    TestLogger();

    return 0;
}