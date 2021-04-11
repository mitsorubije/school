#define _USE_MATH_DEFINES
#include <math.h>
using namespace std; 

class Shape
{

private:
    int _pocetStran;

public:
    Shape(int pocetStran){
        this->_pocetStran = pocetStran;
    }

    ~Shape(){  
    }

    int GetStrany(){
        return this->_pocetStran;
    }

    void Print(){
        cout << "Pocet stran: " << this->GetStrany() << endl;
    }

};


class Square : public Shape
{

private:
    int _obvod;
    int _delkaStrany;

public:
    Square(int delkaStrany) : Shape(4){
        this->_delkaStrany = delkaStrany;
        this->_obvod = 4 * this->_delkaStrany;
    }

    ~Square(){
    }

    void Print(){
        cout << "Pocet stran: " << this->GetStrany() << endl;
        cout << "Delka strany: " << this->_delkaStrany << endl;
        cout << "Obvod: " << this->_obvod << endl;
    }


};


class Circle : public Shape
{

private:
    float _obvod;
    int _polomer;

public:
    Circle(int polomer) : Shape(0){
        this->_polomer = polomer;
        this->_obvod = 2 * M_PI * this->_polomer;
    }

    ~Circle(){
    }

    void Print(){
        cout << "Polomer: " << this->_polomer << endl;
        cout << "Obvod: " << this->_obvod << endl;
    }


};


class Rectangle : public Shape
{

private:
    int _obvod;
    int _delkaStrany1;
    int _delkaStrany2;

public:
    Rectangle(int delkaStrany1, int delkaStrany2) : Shape(4){
        this->_delkaStrany1 = delkaStrany1;
        this->_delkaStrany2 = delkaStrany2;
        this->_obvod = 2 * (this->_delkaStrany1 + this->_delkaStrany2);
    }

    ~Rectangle(){
    }

    void Print(){
        cout << "Pocet stran: " << this->GetStrany() << endl;
        cout << "Delka stran: " << this->_delkaStrany1 << "; " << this->_delkaStrany2 << endl;
        cout << "Obvod: " << this->_obvod << endl;
    }


};