#pragma once

#include<iostream>
#include<string>
using namespace std;



class Footballer {

public:
	//default constructor
	Footballer();

	//overload constructor
	Footballer(string, string, int, int, int, int, int,int,int);

	//Destructor
	~Footballer();


	//accessor functions
	string getName();
	string getPosition();
	int getPassing();
	int getSpeed();
	int getDribbling();
	int getDefending();
	int getShooting();
	int getGoalkeeping();
	int getOverall();
	void selected();
	int playerPicked();


private:
	//member varibales
	string name;
	string position;
	int passing;
	int speed;
	int dribbling;
	int defending;
	int shooting;
	int goalKeeping;
	int picked;


};