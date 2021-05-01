#define _USE_MATH_DEFINES
#include <math.h>
using namespace std; 

//hotovo TODO přidat tem shapům metody pro obvod a obsah, přidat getobvod a getobsah jako virtualni metodu pro shape, otestovat podle kodu z teamsů

//hotovo TODO: vyuzit polymorfismus - pole 5-10 objektů a seřadit je

//hotovo TODO: logger interface

class HistoryItem
{
    public:
        virtual void Print() = 0;
};

class HistoryLogger
{
    private:
        static HistoryItem* _items[5];
        static int _counter;
    public:    
        static void log(HistoryItem* item){
            if(HistoryLogger::_counter < 5){
                HistoryLogger::_items[HistoryLogger::_counter] = item;
                HistoryLogger::_counter++;
            }
            else{
                HistoryLogger::remove(HistoryLogger::_items[0]);
                HistoryLogger::log(item);
            }
        }

        static void remove(HistoryItem* item){
            for(int x = 0; x < 5; x++){
                if(HistoryLogger::_items[x] == item){
                    HistoryLogger::_items[x] = NULL;
                    int subx = x;
                    for(int y = 1; y < HistoryLogger::_counter - x; y++){
                        HistoryLogger::_items[subx] = HistoryLogger::_items[subx + 1];
                        subx++;
                    }
                    HistoryLogger::_counter--;
                    x = 10;
                }
            }
        }

        static void removeLast(){
            int pos = HistoryLogger::_counter - 1;
            HistoryLogger::_items[pos] = NULL;
            HistoryLogger::_counter--;
        }

        static void PrintLog(){
            for(int x = 0; x < HistoryLogger::_counter; x++){
                HistoryLogger::_items[x]->Print();
                cout << endl;
            }
            if(HistoryLogger::_counter == 0){
                cout << "HistoryLogger nema zadny zaznam" << endl;
            }
        }

        static void ClearLogs(){
            for(int x = 0; x < HistoryLogger::_counter; x++){
                HistoryLogger::_items[x] = NULL;
            }
            HistoryLogger::_counter = 0;
        }
};
HistoryItem* HistoryLogger::_items[5] = {0};
int HistoryLogger::_counter = 0;

class Shape : public HistoryItem
{

private:
    int _pocetStran;

public:
    Shape(int pocetStran){
        this->_pocetStran = pocetStran;
        HistoryLogger::log(this);
    }

    ~Shape(){  
        HistoryLogger::remove(this);
    }

    virtual double GetObvod() = 0;

    virtual double GetObsah() = 0;

    int GetStrany(){
        return this->_pocetStran;
    }

    virtual void Print(){
        cout << "Pocet stran: " << this->GetStrany() << endl;
    }

};


class Square : public Shape
{

private:
    int _delkaStrany;

protected:
    int GetA(){
        return _delkaStrany;
    }    

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

protected:
    int GetPolomer(){
        return _polomer;
    }

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

protected:
    int GetA(){
        return _delkaStrany1;
    }
    int GetB(){
        return _delkaStrany2;
    }

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

class ThirdDimensionObject
{

public:

    virtual double GetVolume() = 0;

};

class Cube : public Square, public ThirdDimensionObject
{

public:
    Cube(int delkaStrany) : Square(delkaStrany){
    }

    ~Cube(){
    }

    double GetVolume(){
        return GetA() * GetA() * GetA();
    }


};

class Sphere : public Circle, public ThirdDimensionObject
{

public:
    Sphere(int delkaStrany) : Circle(delkaStrany){
    }

    ~Sphere(){
    }

    double GetVolume(){
        return (4 / 3) * M_PI * pow(GetPolomer(), 3);
    }


};

class Block : public Rectangle, public ThirdDimensionObject
{
private:
    int _delkaStrany3;

public:
    Block(int delkaStrany1, int delkaStrany2, int delkaStrany3) : Rectangle(delkaStrany1, delkaStrany2){
        this->_delkaStrany3 = delkaStrany3;
    }

    ~Block(){
    }

    double GetVolume(){
        return GetA() * GetB() * this->_delkaStrany3;
    }


};