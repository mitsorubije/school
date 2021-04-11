using namespace std; 
//vse az po fakturu + updated skola + staticke promene a mozna i dalsi veci

class Person
{

private:
    string _name;
    string _secondName;
    int _year;
    
    //father a mother veci presunuty do FamilyTreePerson
    //Person* _father;
    //Person* _mother;
    string _address;

    static int _pocet; //staticky counter kolik mame objektu tridy person, muzem k nemu pristupovat pomocí Person::_pocet tkze nepotrebujeme zadnou konkretni osobu k pristupu atak

public:
    Person(string name, string secondName, int year){
        this->_name = name;
        this->_secondName = secondName;
        this->_year = year;
        //this->_father = NULL;
        //this->_mother = NULL;
        this->_address = "";
        Person::IncPocet(); //staticke promene muzem bud takhle pomoci funkcí upravovat
    }

    ~Person(){
        Person::_pocet--; //nebo takto normalne pomocí -- atd
    }

    static void IncPocet(){  //ty statické funkce znamenaji ze k nim muzem pristupovat pomoci tridy, nemusime pomoci objektu. tkze napr JmenoTridy::Get() misto JmenoObjektu->Get()
        Person::_pocet += 1;
    }

    static int GetPocet(){
        return Person::_pocet; 
    }

    string GetName(){
        return this->_name;
    }

    string GetFullName(){
        return this->_name + " " + this->_secondName;
    }

    string GetSurname(){
        return this->_secondName;
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

    void SetAddress(string adresa){
        this->_address = adresa;
    }

    string GetAddress(){
        return this->_address;
    }

};

int Person::_pocet = 0;


//TODO: napsat si nejaky vlastni příklad dedičnosti, např trida shape a potomky square circle atd, nebo bytost zvire savec atak. alespon 3 tridy, alespon 1 vlastnost a 1 metodu
//TODO2: + poslat aji kod tohohle FamilyTreePerson
class FamilyTreePerson : public Person
{

private:
    FamilyTreePerson* _father;
    FamilyTreePerson* _mother;

public:
    FamilyTreePerson(string name, string secondName, int year) : Person(name, secondName, year){
        this->_father = NULL;
        this->_mother = NULL;
    }

    FamilyTreePerson(string name, string secondName, int year, FamilyTreePerson* father, FamilyTreePerson* mother) : Person(name, secondName, year){
        this->_father = father;
        this->_mother = mother;
    }

    ~FamilyTreePerson(){
    }

    void SetFather(FamilyTreePerson* father){
        this->_father = father;
    }
    void SetMother(FamilyTreePerson* mother){
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



class LoginGeneratorService
{
private:
    Person* _udaje;
    string _login;

    static int _pismena[26];

public:
    LoginGeneratorService(Person* udaje){
        this->_udaje = udaje;
        this->_login = LoginGeneratorService::GetLogin(udaje);
    }

    ~LoginGeneratorService(){

    }

    static string GetLogin(Person* udaje){
        string prijmeni = udaje->GetSurname();
        char prvni = prijmeni[0];
        int a = prvni - 65;

        int cislo = LoginGeneratorService::_pismena[a];
        string login = prvni + to_string(cislo);

        LoginGeneratorService::_pismena[a]++;

        return login;
    }


};

int LoginGeneratorService::_pismena[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


class Student
{
private:
    Person* _udaje;
    int _kredity;
    int _semestr;
    string _login;

    static int _pismena[26];

public:
    Student(Person* udaje){
        this->_udaje = udaje;
        this->_kredity = 0;
        this->_semestr = 1;
        //this->_login = Student::CreateLogin(udaje);
        this->_login = LoginGeneratorService::GetLogin(udaje);
    }

    ~Student(){

    }

    //DU: dodelat to create login a vytvorit tridu LoginGeneratorService tridu ktera dela to samé ale samostatne abychom pak mohli tady v konstruktoru pouzit treba LoginGeneratorService::GetLogin(udaje)
    static string CreateLogin(Person* udaje){
        string prijmeni = udaje->GetSurname();
        char prvni = prijmeni[0];
        int a = prvni - 65;

        int cislo = Student::_pismena[a];
        string login = prvni + to_string(cislo);

        Student::_pismena[a]++;

        return login;
    }

    string GetLogin(){
        return this->_login;
    }

    int GetCredits(){
        return this->_kredity;
    }

    int GetSemestr(){
        return this->_semestr;
    }

    void AddCredits(int num){
        this->_kredity = this->_kredity + num; 
    }

    void AddSemestr(){
        this->_semestr++; 
    }

    void Print(){
        this->_udaje->Print();
        cout << " Kredity: " << this->_kredity << "; Semestr: " << this->_semestr << "; Login: " << this->_login << endl;
    }

    Person* GetPerson(){
        return this->_udaje;
    }


};

int Student::_pismena[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

class School
{

private:
    string _name;
    Student** _students;
    int _capacity;
    int _initialCapacity;
    int _count;


public:
    School(string name, int capacity){
        this->_name = name;
        this->_capacity = capacity;
        this->_initialCapacity = capacity;
        this->_count = 0;
        this->_students = new Student * [capacity];

    }

    ~School(){
        delete [] _students;
    }

    int AddStudent(Person* student){
        Student* newStudent = new Student(student);
        this->_students[this->_count] = newStudent;
        int id = this->_count;
        this->_count++;

        //TODO vyresit prevrseni kapacity - hotovo
        if(this->_count == this->_capacity){
            Student** temp = this->_students;
            //cout << "\nDochazi k navyseni kapacity\n";
            this->_capacity = this->_capacity + this->_initialCapacity;
            this->_students = new Student * [this->_capacity];
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

    Student* FindStudent(string name2){
        Student* result = NULL;
        for(int i = 0; i < this->_count; i++){
            if(this->_students[i]->GetPerson()->GetFullName() == name2){
                result = this->_students[i];
                return result;
            }  
        }

        return result;
    }

    void RemoveStudent(Student* remove){
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
    
    void NextSemester(){
        for(int i = 0; i < this->_count; i++){
            int semestr = this->_students[i]->GetSemestr();
            int kredity = this->_students[i]->GetCredits();
            if(semestr < 6 && kredity >= 30 * semestr){
                this->_students[i]->AddSemestr();
            }
            else if(semestr == 6){
                if(StatniceCheck(this->_students[i]) == true){
                    cout << "Student muze ke statnicim" << endl;
                }
                else{
                    cout << "Student nemuze ke statnicim" << endl;
                }
            }
        }
    }

    //TODO: dve moznosti
    // jestli muzou ke statnicim, udelat nejak statnice ze jestli je udelaji ty statnice a pokud ano tak je odebrat z té školy a ty veci nejak zahrnout do printu
    // a nebo udelat ty ukoly z tech slidů tu banku
    bool StatniceCheck(Student* check){
        if(check->GetCredits() >= 180 && check->GetSemestr() == 6){
            return true;
        }
        else{
            return false;
        }
    }

};

class InvoiceItem{

private:
    string _name;
    int _price;

public:
    InvoiceItem(string name, int price){
        this->_name = name;
        this->_price = price;

    }

    ~InvoiceItem(){
    }

    int GetPrice(){
        return this->_price;
    }

    void Print(){
        cout << this->_name << " " << this->_price << endl;
    }

};

class Invoice
{

private:
    Person* _osoba;
    int _id;
    InvoiceItem** _items;
    int _count;

public:
    Invoice(int id, Person* osoba){
        this->_osoba = osoba;
        this->_id = id;
        this->_items = new InvoiceItem * [30];
        this->_count = 0;

    }

    ~Invoice(){
        //nejprve znicime all polozky
        for(int i = 0; i < this->_count; i++){
            delete _items[i];
        }
        //pak nicime pole
        delete [] _items;
    }

    void AddItem(string nazev, int cena){
        this->_items[this->_count] = new InvoiceItem(nazev, cena);

        this->_count++;
    }

    int GetSum(){
        int sum = 0;
        for(int i = 0; i < this->_count; i++){
            sum = sum + this->_items[i]->GetPrice();
        }
        return sum;
    }

    void Print(){
        cout << "Invoice ID: " << this->_id << endl;
        for(int i = 0; i < this->_count; i++){
             this->_items[i]->Print();
        }
        cout << "Celkova cena: " << this->GetSum() << endl; 
    }

};

void TestInvoicing(){
    Person* me2 = new Person("Lukas", "Krocek", 2000);
    me2->SetAddress("Ulice 13, Mesto");
    Invoice* i1 = new Invoice(0, me2);
    i1->AddItem("Nazev", 10);
    i1->AddItem("Druha", 20);

    int sum = i1->GetSum();
    cout << "Celkova cena: " << sum << endl;

    i1->Print();
}