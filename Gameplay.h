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
	int passesMade(int array1[11]);
	int dribblesMade(int array1[11], int tackles);
	int chancesMade(int, int);
	int shots_on_target(int,int);
	int shootingAccuracy(int array1[11]);
	int tacklesMade(int array1[11]);
	int goalKeeping(int array1[11]);
	void shotAnim();



private:
	//member varibales
	int goal;


};