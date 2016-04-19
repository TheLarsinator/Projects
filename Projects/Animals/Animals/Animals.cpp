// Animals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <random>

using namespace std;

int randomWithLimits(int min, int max)
{
	int i;
	do
	{
		i = rand();
	} while (i < min || i > max);

	return i;
}

class Animal
{
protected:
	string name;
	int height;
	int legs;
public:
	virtual int speed() = 0;
	Animal()
	{}
	Animal(int height, int legs, string name)
	{
		this->height = height;
		this->legs = legs;
		this->name = name;
	}
	
	int getHeight()
	{
		return height;
	}
	string getName()
	{
		return name;
	}
	void setHeight(int heigth)
	{
		this->height = height;
	}
	int getLegs()
	{
		return legs;
	}
	void setLegs(int legs)
	{
		this->legs = legs;
	}
	friend ostream& operator << (ostream &out, Animal &animal)
	{
		out <<  animal.getName() << "'s height: " << animal.getHeight() << ", " << animal.getName()  << " has " << animal.getLegs() << "legs." << endl;
		return out;
	}
};

class Mouse : public Animal
{
private:
	int oster;
	
public:
	Mouse(){}
	Mouse(int heights, int legss, int ost, string names)
	{
		//Animal::Animal(height, legs);
		height = heights;
		legs = legss;
		name = names;
		oster = ost;
	}
	int getOster()
	{
		return oster;
	}
	void setOster(int ost)
	{
		this->oster = ost;
	}
	int speed()
	{
		return randomWithLimits(2, 5);
	}
	~Mouse()
	{
		cout << name << " just died!" << endl;
	}
};

class Cat : public Animal
{
private:
	bool hasPrey = false;
	Mouse prey;
public:
	Cat(int sheight, int slegs, string sname)
	{
		height = sheight;
		legs = slegs;
		name = sname;
	}
	void catchMouse(Mouse &prey)
	{
		if (prey.getOster() > 0)
		{
			cout << "Can't eat a mouse that has cheese!" << endl;
		}
		else if(prey.getOster() < 1 && !hasPrey)
		{
			if (speed() < prey.speed())
				cout << name << " was not fast enough, " << prey.getName() << " escaped!" << endl;
			else
			{
				cout << "RIP: " << prey.getName() << endl;
				hasPrey = true;
				prey = prey;
			}
		}
	}
	void eatMouse()
	{
		if (hasPrey)
		{
			cout << name << " has a mouse..." << endl;
			prey.~Mouse();
			cout << name << " isn't hungry anymore!" << endl;
			hasPrey = false;
		}
	}
	int speed()
	{
		return randomWithLimits(1, 3);
	}
};

int main()
{
	Cat katt(35, 4, "Moms");
	Mouse mus(5, 4, 0, "Jerry");
	while (true)
	{
		cout << mus.getName() << " found some cheese!" << endl;
		mus.setOster(1);
		katt.catchMouse(mus);

		cout << mus.getName() << " has eaten his cheese!" << endl;
		mus.setOster(0);

		katt.catchMouse(mus);
		katt.eatMouse();

		system("pause");
	}
    return 0;
}

