#include <iostream>
#include <ctime>

using namespace std; 


class Person
{

private:
    string _name;
    string _secondName;
    int _year;
    
    Person* _father;
    Person* _mother;

public:
    Person(string name, string secondName, int year){
        this->_name = name;
        this->_secondName = secondName;
        this->_year = year;
        this->_father = NULL;
        this->_mother = NULL;

    }

    ~Person(){

    }

    string GetName(){
        return this->_name;
    }

    string GetFullName(){
        return this->_name + " " + this->_secondName;
    }

    void Print(){
        std::time_t t = std::time(nullptr);
        std::tm *const pTInfo = std::localtime(&t);
        int rok = 1900 + pTInfo->tm_year;
        int vek = rok - this->_year;
        
        cout << this->GetFullName() << " [Age: " << vek << "]";
        // TODO Misto YEAR vypiste vek. staci aktualni rok - rok narozeni
        // hotovo
    }

    void SetFather(Person* father){
        this->_father = father;
    }
    void SetMother(Person* mother){
        this->_mother = mother;
    }

    void PrintFather(){
        if(this->_father == NULL){
            cout << "Father not set";
        }
        else{
            this->_father->Print();
        }
    }

    void PrintTree(){
        this->Print();
        cout << "\n";
        if(this->_father != NULL && this->_mother != NULL){
            this->_father->PrintTree();
            this->_mother->PrintTree();
        }
    }

};


class School
{

private:
    string _name;
    Person** _students;
    int _capacity;
    int _initialCapacity;
    int _count;


public:
    School(string name, int capacity){
        this->_name = name;
        this->_capacity = capacity;
        this->_initialCapacity = capacity;
        this->_count = 0;
        this->_students = new Person * [capacity];

    }

    ~School(){
        delete [] _students;
    }

    int AddStudent(Person* student){
        this->_students[this->_count] = student;
        int id = this->_count;
        this->_count++;

        //TODO vyresit prevrseni kapacity
        if(this->_count == this->_capacity){
            Person** temp = this->_students;
            //cout << "\nDochazi k navyseni kapacity\n";
            this->_capacity = this->_capacity + this->_initialCapacity;
            this->_students = new Person * [this->_capacity];
            for(int i = 0; i < this->_count; i++){
                this->_students[i] = temp[i];
            }
        }

        return id;
    }

    void PrintStudents(){
        for(int i = 0; i < this->_count; i++){
            if(this->_students[i] != NULL){
                this->_students[i]->Print();
                cout << "\n";
            }
        }
    }

    void PrintCapacity(){
        cout << this->_capacity;
    }

    void PrintStudentCount(){
        cout << this->_count;
    }

    Person* FindStudent(string name2){
        Person* result = NULL;
        for(int i = 0; i < this->_count; i++){
            if(this->_students[i]->GetFullName() == name2){
                result = this->_students[i];
                return result;
            }  
        }

        return result;
    }

    //FindStudents:
    //TODO vyresit vraceni vice osob (vice studentu se stejnym jmenem)
    //tenhle domaci ukol se prozatim zrusil, misto toho RemoveStudent jako TODO
    /*
    Person** FindStudents(string name2){
        Person** result = new Person * [50];
        int x = 0;
        for(int i = 0; i < this->_count; i++){
            if(this->_students[i]->GetFullName() == name2){
                result[x] = this->_students[i];
                x++;
            }  
        }

        return result;
    }*/

    //TODO:
    void RemoveStudent(Person* remove){
        int removing = 0;
        for(int i = 0; i < this->_count; i++){
            if(removing == 1){
                this->_students[i-1] = this->_students[i];
            }
            if(this->_students[i] == remove){
                this->_students[i] = NULL;
                removing = 1;
            }
        }
        if(removing == 1){
            this->_count--;
        }
    }
    

};


int main() {
    Person * me = new Person("Lukas", "Krocek", 2000);
    Person * father = new Person("Martin", "Krocek", 1970);
    Person * mother = new Person("Alena", "Krockova", 1975);
    Person * grandfather = new Person("Karel", "Krocek", 1940);
    Person * grandmother = new Person("Alzbeta", "Krockova", 1930);
    Person * grandfather2 = new Person("Tomas", "Krocek", 1940);
    Person * grandmother2 = new Person("Agata", "Krockova", 1930);
    Person * student1 = new Person("Kamil", "Lichnovsky", 1988);
    Person * student2 = new Person("Petr", "Dalny", 1999);
    Person * student3 = new Person("Katerina", "Dobrovska", 2003);
    Person * student4 = new Person("Petra", "Skalna", 1997);
    Person * student5 = new Person("Karel", "Dobrovsky", 2000);
    me->SetFather(father);
    me->SetMother(mother);
    father->SetFather(grandfather);
    father->SetMother(grandmother);
    mother->SetFather(grandfather2);
    mother->SetMother(grandmother2);
    //cout << person1->GetFullName();
    //me->Print();
    //me->PrintTree();

    School * skola = new School("VSB", 3);
    skola->AddStudent(me);
    skola->AddStudent(father);
    skola->AddStudent(grandfather2);

    skola->PrintStudents();
    cout << "Kapacita: ";
    skola->PrintCapacity();
    cout << "\nPocet studentu: ";
    skola->PrintStudentCount();
    cout << "\n";

    Person * found = skola->FindStudent("Tomas Krocek");
    found->Print();

    cout << "\n\nPo odstraneni prvniho studenta:\n";
    skola->RemoveStudent(me);
    skola->PrintStudents();
    cout << "Pocet studentu po odstraneni jednoho: ";
    skola->PrintStudentCount();
    cout << "\n\n";

    skola->AddStudent(student1);
    skola->AddStudent(student2);
    skola->AddStudent(student3);
    skola->AddStudent(student4);

    skola->PrintStudents();
    cout << "Kapacita: ";
    skola->PrintCapacity();
    cout << "\nPocet studentu: ";
    skola->PrintStudentCount();




    return 0;
}