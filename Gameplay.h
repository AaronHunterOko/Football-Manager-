#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Gameplay {

public:
	//default constructor
	Gameplay();
	 
	//overload constructor
	Gameplay(int);


	//Destructor
	~Gameplay();


	//functions
	
	int testValue();
	int passesMade(int array1[3]);
	int dribblesMade(int array1[3], int tackles);
	int chancesMade(int, int);
	int shots_on_target(int,int);
	int shootingAccuracy(int array1[3]);
	int tacklesMade(int array1[7]);
	int goalKeeping(int array1[7]);



private:
	//member varibales
	int goal;


};