#include <iostream>
#include <ctime>
#include "skolaupdated.h"
#include <cstdbool>

int main() {
    FamilyTreePerson * me = new FamilyTreePerson("Lukas", "Krocek", 2000);
    FamilyTreePerson * father = new FamilyTreePerson("Martin", "Krocek", 1970);
    FamilyTreePerson * mother = new FamilyTreePerson("Alena", "Krockova", 1975);
    FamilyTreePerson * grandfather = new FamilyTreePerson("Karel", "Krocek", 1940);
    FamilyTreePerson * grandmother = new FamilyTreePerson("Alzbeta", "Krockova", 1930);
    FamilyTreePerson * grandfather2 = new FamilyTreePerson("Tomas", "Krocek", 1940);
    FamilyTreePerson * grandmother2 = new FamilyTreePerson("Agata", "Krockova", 1930);
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
    //konstruktor přímo s rodiči:
    FamilyTreePerson * sister = new FamilyTreePerson("Michaela", "Krockova", 2006, father, mother);

     School * skola = new School("VSB", 3);
    skola->AddStudent(me);
    skola->AddStudent(father);
    skola->AddStudent(grandfather2);
    skola->AddStudent(student4);
    skola->AddStudent(student2);
    skola->AddStudent(student3);

    skola->PrintStudents();
    cout << "Kapacita: ";
    skola->PrintCapacity();
    cout << "\nPocet studentu: ";
    skola->PrintStudentCount();
    cout << "\n\n";

    /*skola->FindStudent("Lukas Krocek")->AddCredits(40);
    skola->NextSemester();
    skola->FindStudent("Lukas Krocek")->Print();

    skola->FindStudent("Lukas Krocek")->AddCredits(30);
    skola->NextSemester();
    skola->FindStudent("Lukas Krocek")->Print();

    skola->FindStudent("Lukas Krocek")->AddCredits(30);
    skola->NextSemester();
    skola->FindStudent("Lukas Krocek")->Print();

    skola->FindStudent("Lukas Krocek")->AddCredits(30);
    skola->NextSemester();
    skola->FindStudent("Lukas Krocek")->Print();

    skola->FindStudent("Lukas Krocek")->AddCredits(20);
    skola->NextSemester();
    skola->FindStudent("Lukas Krocek")->Print();

    skola->FindStudent("Lukas Krocek")->AddCredits(30);
    skola->NextSemester();
    */

    cout << "Pocet osob po je " << Person::GetPocet() << endl;

    /*char c = 'A';
    int a = c;
    cout << a << endl;*/

    cout << endl;
    me->PrintTree();
    cout << endl;
    sister->PrintTree();

    return 0;
}