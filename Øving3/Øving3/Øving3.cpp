// Øving3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cannonball.h"
#include "utilities.h"
#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>

using namespace std;

int main()
{

	setlocale(LC_ALL, "Norwegian");
	//double initVelY = 25;
	//double initVelX = 50;
	//double time = 0;
	//while (time < 6)
	//{
	//	cout << acclY() << endl;
	//	cout << acclX() << endl;
	//	cout << velY(initVelY, time) << endl;
	//	cout << posY(initVelY, time) << endl;
	//	cout << posX(initVelX, time) << endl;
	//	time += 2.5;
	//}
	//cin >> time;

	//Oppgave 4
	//double theta;
	//double absVel;

	//double velX;
	//double velY;

	//double distTarget = 5.0;
	//getUserInput(&theta, &absVel);
	//getVelocityVector(theta, absVel, &velX, &velY);
	//double distance = targetPractice(distTarget, velX, velY);
	//cout << distance << endl;
	const int GO = 1000000000;
	srand(time(NULL));
	int MIN = 100;
	int MAX = 1000;
	//playTargetPractice(MIN, MAX);
	int turnsUsed; 
	double total = 0;
	for (int i = 0; i < GO; i++)
	{
		letPCPlayTargetPractice(MIN, MAX, &turnsUsed);
		total += turnsUsed;
		if (i % 1000000 == 0)
			cout << i << endl;
	}
	cout << total << endl;
	cout << total / GO << endl;


	system("pause");
    return 0;
}

