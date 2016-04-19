#include <iostream>
#include <vector>
#include "Person.hpp"
#include <string>
#include "stdafx.h"

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    
    int numberOfPeople;
    cin >> numberOfPeople;
    
    string input;
    for(int i = 0; i < numberOfPeople; i++) {
        cin >> input;
        Person newPerson = Person(input);
    }
    
    vector<string> roomies;
    while (cin >> input) {
        roomies = split(input, '_');
        Person* p = findPersonByName(roomies.at(0));
        for (int i = 1; i < roomies.size(); i++) {
            p->addRoomie(findPersonByName(roomies.at(i)));
        }
    }
    
    for (int i = 0; i < Person::people.size(); i++) {
        cout << Person::people.at(i) << endl;
    }
}