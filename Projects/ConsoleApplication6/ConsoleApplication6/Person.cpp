#include <iostream>
#include "Person.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include "stdafx.h"

using namespace std;

vector<Person> Person::people;


/* Returnerer listen over roomies */
vector<Person*> Person::getRoomies() const {
	return roomies;
}

/* Returnerer navnet til personen */
string Person::getName() const {
	return name;
}

/* Konstruktøren til Person */
Person::Person(string name) {
	// DIN KODE HER
	this->name = name;

	/* LA STÅ: Legger til alle nye Person-instanser i en global liste */
	people.push_back(*this);
}

/* Metode for å legge til en roomie */
void Person::addRoomie(Person* roomie) {
	/* LA STÅ: For å unngå evig loop */
	for (int i = 0; i < roomies.size(); i++) {
		if (roomies[i] == roomie || roomie == this) return;
	}

	// DIN KODE HER
	//Legger inn den nye roomien
	roomies.push_back(roomie);
	bool alreadyRoomie = false;
	//Skal legge inn alle de andre roomiene til roomie
	for (int j = 0; j < roomie->getRoomies().size(); j++)
	{	
		//Sjekk om noen av dem allerede er en roomie
		for (int k = 0; k < roomies.size(); k++)
		{
			if (roomies.at(k) == roomie)
				alreadyRoomie == true; break;
		}
		if (!alreadyRoomie)
			roomies.push_back(roomie->getRoomies().at(j));
		else
			alreadyRoomie = false;
	}
}

/* Returnerer Personen i Person::people som har navnet name */
Person* findPersonByName(string name) {
	// DIN KODE HER
	for (int i = 0; i < Person::people.size(); i++)
	{
		if (Person::people.at(i).getName() == name)
		{
			return &Person::people.at(i);
		}
	}
}

/* Skal returnere en vector med substringene */
vector<string> split(string input, char splitter) {
    // LIM INN KODE FRA OPPGAVE a)
	vector<string> vec;
	int tempVal = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == splitter)
		{
			vec.push_back(input.substr(tempVal, (i - 1) - tempVal));
			tempVal = i + 1;
		}
	}
	//if setningen vil ikke få tak i det siste ordet
	vec.push_back(input.substr(tempVal, input.length() - tempVal));
}



/* LA STÅ */
bool compare(const Person* lhs, const Person* rhs) {
    return lhs->getName() < rhs->getName();
}

ostream & operator<<(ostream& out, const Person p) {
    
    vector<Person*> sorted = p.getRoomies();
    sort(sorted.begin(), sorted.end(), compare);
    
    out << p.getName() << ":";
    for (int i = 0; i < sorted.size(); i++) {
        cout << " " << sorted.at(i)->getName();
    }
    return out;
}