#define _USE_MATH_DEFINES
#include <math.h>
using namespace std; 

//hotovo TODO přidat tem shapům metody pro obvod a obsah, přidat getobvod a getobsah jako virtualni metodu pro shape, otestovat podle kodu z teamsů

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

    virtual double GetObvod() = 0;

    virtual double GetObsah() = 0;

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
    int _delkaStrany;

public:
    Square(int delkaStrany) : Shape(4){
        this->_delkaStrany = delkaStrany;
    }

    ~Square(){
    }

    double GetObvod(){
        return 4 * this->_delkaStrany;
    }

    double GetObsah(){
        return _delkaStrany * _delkaStrany;
    }

    void Print(){
        cout << "Pocet stran: " << this->GetStrany() << endl;
        cout << "Delka strany: " << this->_delkaStrany << endl;
        cout << "Obvod: " << this->GetObvod() << endl;
        cout << "Obsah: " << this->GetObsah() << endl;
    }


};


class Circle : public Shape
{

private:
    int _polomer;

public:
    Circle(int polomer) : Shape(0){
        this->_polomer = polomer;
    }

    ~Circle(){
    }

    double GetObvod(){
        return 2 * M_PI * this->_polomer;
    }

    double GetObsah(){
        return M_PI * pow(_polomer, 2);
    }

    void Print(){
        cout << "Polomer: " << this->_polomer << endl;
        cout << "Obvod: " << this->GetObvod() << endl;
        cout << "Obsah: " << this->GetObsah() << endl;
    }


};


class Rectangle : public Shape
{

private:
    int _delkaStrany1;
    int _delkaStrany2;

public:
    Rectangle(int delkaStrany1, int delkaStrany2) : Shape(4){
        this->_delkaStrany1 = delkaStrany1;
        this->_delkaStrany2 = delkaStrany2;
    }

    ~Rectangle(){
    }

    double GetObvod(){
        return 2 * (this->_delkaStrany1 + this->_delkaStrany2);
    }

    double GetObsah(){
        return _delkaStrany1 * _delkaStrany2;
    }

    void Print(){
        cout << "Pocet stran: " << this->GetStrany() << endl;
        cout << "Delka stran: " << this->_delkaStrany1 << "; " << this->_delkaStrany2 << endl;
        cout << "Obvod: " << this->GetObvod() << endl;
        cout << "Obsah: " << this->GetObsah() << endl;
    }


};