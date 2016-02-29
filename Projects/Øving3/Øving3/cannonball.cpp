#include "stdafx.h"
#include "cannonball.h"
#include <iostream>
#include <cmath>
#include "utilities.h"


using namespace std;


double acclY()
{
	return -9.81;
}

double acclX()
{
	return 0;
}

double velY(double initVelocity, double time)
{
	return initVelocity + acclY() * time;
}

double posY(double initVelocityY, double time)
{
	const int STARTPOS = 0;
	return STARTPOS + initVelocityY * time + (acclY() * time * time) / 2;
}

double posX(double initVelocityX, double time)
{
	const int STARTPOS = 0;
	return STARTPOS + initVelocityX * time + (acclX() * time * time) / 2;
}

void printTime(double time)
{
	int tempTim = time;
	double decimals = time - tempTim;
	int timr = tempTim % 3600;
	int tim = (tempTim - timr) / 3600;
	int minr = timr % 60;
	int min = (timr - minr) / 60;

	cout << tim << "timer, " << min << "minutter, " << minr + decimals << "sekunder." << endl;
}

double flightTime(double initVelocityY)
{
	return -2 * (initVelocityY / acclY());
}

void getUserInput(double *theta, double *absVelocity)
{
	cout << "Skriv inn vinkelen: ";
	cin >> *theta;
	cout << "Skriv inn farta: ";
	cin >> *absVelocity;
}

double getVelocityX(double theta, double absVelocity)
{
	return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity)
{
	return absVelocity * sin(theta);
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY)
{
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY)
{
	return flightTime(velocityY) * velocityX;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void angleAndSpeedFromDistance(double *theta, double *absVel, double distance)
{
	const double PI = 3.1415926535;
	*theta = 45*PI/180;
	double velY;
	velY = sqrt((acclY() / -2)*distance);
	*absVel = velY / sin(*theta);
}


void letPCPlayTargetPractice(int MIN, int MAX, int *turnsUsed)
{
	const double PI = 3.1415926535;
	//Set distance to target. 
	double distTarget = randomWithLimits(MIN, MAX);
	//cout << distTarget << endl;//Debug

	double theta;
	double absVel;

	double velX;
	double velY;

	int min = MIN;
	int max = MAX;

	int turns = 1;
	double distance;

	double distanceGuess = MIN + ((MAX - MIN)/2) ;
	bool shotOver;

	while (turns < 11)
	{
		//cout << "Skriv inn vinkel og hastighet for skudd " << turns << endl;
		angleAndSpeedFromDistance(&theta, &absVel, distanceGuess);
		getVelocityVector(theta, absVel, &velX, &velY);
		double shot = getDistanceTraveled(velX, velY);
		//cout << "Du skøyt " << shot << "meter langt!" << endl;

		distance = targetPractice(distTarget, velX, velY);
		//Bytte fortegn hvis vi har skutt for langt unna. 
		if (shot > distTarget)
		{
			//cout << "The distance you missed with is: " << distance << endl;
			max = distanceGuess;
			distance *= -1;
			shotOver = true;
		}
		else if(shot < distTarget)
		{
			//cout << "The distance you missed with is: " << distance << endl;
			min = distanceGuess;
			shotOver = false;
		}
		if (distance < 5)
		{
			//cout << "Gratulerer, du traff!" << endl;
			//cout << "Blinken lå på " << distTarget << "meter!" << endl;
			*turnsUsed = turns;
			break;
		}
		else if (distance > 5 && turns < 10)
		{
			//cout << "Du bommet og ";
			//if (shotOver)
				//cout << "skøyt over";
			//else
				//cout << "skøyt for kort";
				//cout << ", prøv igjen!" << endl;
			turns++;
		}
		else if (turns == 10)
		{
			cout << "Du bommet, og har ikke flere turer igjen." << endl;
			cout << "Blinken lå på " << distTarget << "meter!" << endl;
			*turnsUsed = 1000000000;
			break;
		}

		if(!shotOver)
			distanceGuess = distanceGuess + ((max - distanceGuess) / 2);
		else
			distanceGuess = min + ((distanceGuess - min) / 2);
	}
}


void playTargetPractice(int MIN, int MAX)
{
	const double PI = 3.1415926535;
	//Set distance to target. 
	double distTarget = randomWithLimits(MIN, MAX);
	//cout << distTarget << endl;//Debug

	double theta;
	double thetar;
	double absVel;

	double velX;
	double velY;

	int turns = 1;
	double distance;

	double thetaSol;
	double absVelSol;

	while (turns < 11)
	{
		cout << "Skriv inn vinkel og hastighet for skudd " << turns << endl;
		getUserInput(&theta, &absVel);
		thetar = (theta / 180)*PI;
		getVelocityVector(thetar, absVel, &velX, &velY);
		double shot = getDistanceTraveled(velX, velY);
		cout << "Du skøyt " << shot << "meter langt!" << endl;
		//cout << "VelX" << velX << "velY" << velY << endl; //Debug
		distance = targetPractice(distTarget, velX, velY);

		//Bytte fortegn hvis vi har skutt for langt unna. 
		if (shot > distTarget)
		{
			distance *= -1;
		}

		if (distance < 5)
		{
			cout << "Gratulerer, du traff!" << endl;
			cout << "Blinken lå på " << distTarget << "meter!" << endl;
			break;
		}
		else if(distance > 5 && turns < 10)
		{
			cout << "Du bommet med " << distance << "meter, prøv igjen!" << endl;
			turns++;
		}
		else if(turns == 10)
		{
			cout << "Du bommet, og har ikke flere turer igjen." << endl;
			cout << "Blinken lå på " << distTarget << "meter!" << endl;
			break;
		}
	}	
}