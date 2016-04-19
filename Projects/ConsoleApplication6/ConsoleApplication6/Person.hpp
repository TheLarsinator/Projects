#pragma once
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Person {
    
    string name;
    vector<Person*> roomies;
    
    
public:
    static vector<Person> people;
    Person(string name);
    void addRoomie(Person* roomie);
    vector<Person*> getRoomies() const;
    string getName() const;
};

bool compare(const Person* lhs, const Person* rhs);
Person* findPersonByName(string name);
vector<string> split(string input, char splitter);
ostream& operator<<(ostream& out, const Person p);