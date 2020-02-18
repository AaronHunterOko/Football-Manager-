#include"Gameplay.h"
#include"Footballer.h"


Gameplay::Gameplay() {
	//null states
	goal = 0;
	
}

//overload constructor
Gameplay::Gameplay(int goal1) {
	
	goal = goal1;


}


Gameplay::~Gameplay() {

}


//functions

int Gameplay::testValue() {

	return goal;


}

//enter in chancesMade

int Gameplay::shots_on_target(int chances, int shootingAccuracy) {
	int onTarget = chances * shootingAccuracy;
	return onTarget;

}



//enter in passesMade() and dribblesMade()
int Gameplay::chancesMade(int passes, int dribbles) {
	int chances = passes / dribbles;
	return chances;

}


int Gameplay::dribblesMade(int array1[3], int tackles) {
	int dribbleValue = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7];
	int dribblesMade = dribbleValue / 2;
	int dribbles = dribblesMade + tackles;
	return dribbles;
}

int Gameplay::passesMade(int array1[3]) {

	int passes1 = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7];
	int passes =  passes1* 5;

	return passes;

}


int Gameplay::shootingAccuracy(int array1[3]) {
	int shootingA = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7];
	int accuracy = shootingA * 0.05;
	return accuracy;
}

int Gameplay::tacklesMade(int array1[7]) {
	int tackle1 = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7];
	int tackles = tackle1 / 1.5;
	return tackles;

}

int Gameplay::goalKeeping(int array1[7]) {
	int goalkeeper = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7];
	return goalkeeper;

}

