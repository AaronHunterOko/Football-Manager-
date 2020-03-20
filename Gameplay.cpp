#include"Gameplay.h"
#include"Footballer1.h"
#include<cstdlib>
#include<ctime>
#include<algorithm>



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
	int onTarget = chances * 3;
	return onTarget;

}



//enter in passesMade() and dribblesMade()
int Gameplay::chancesMade(int passes, int dribbles) {
	int chances = passes / dribbles;
	return chances;

}


int Gameplay::dribblesMade(int array1[11], int tackles) {
	int dribbleValue = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7] + array1[8] + array1[9] + array1[10] + array1[11];
	int dribblesMade = dribbleValue / 2;
	int dribbles = dribblesMade + tackles;
	return dribbles;
}

int Gameplay::passesMade(int array1[11]) {

	int passes1 = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7] + array1[8] + array1[9] + array1[10] + array1[11];
	int passes =  passes1* 3;
	return passes;

}


int Gameplay::shootingAccuracy(int array1[11]) {
	int shootingA = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7] + array1[8] + array1[9] + array1[10] + array1[11];
	int accuracy = shootingA * 0.05;
	return accuracy;
}

int Gameplay::tacklesMade(int array1[11]) {
	int tackle1 = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7] + array1[8] + array1[9] + array1[10] + array1[11];
	int tackles = tackle1 / 1.5;
	return tackles;

}

int Gameplay::goalKeeping(int array1[11]) {
	int goalkeeper = array1[1] + array1[2] + array1[3] + array1[4] + array1[5] + array1[6] + array1[7] + array1[8] + array1[9] + array1[10] + array1[11];
	return goalkeeper;

}


void Gameplay::shotAnim() {
	int x = 0;
	while(x == 0){
		for (int i = 0; i <= 5; i++) {
			system("cls");
			cout << "	   _____     " << endl;
			cout << "          |     |     " << endl;
			cout << "             g    " << endl;
			cout << "                 " << endl;
			cout << "   po           " << endl;
		}
		for (int i = 0; i <= 2; i++) {
			system("cls");
			cout << "	   _____     " << endl;
			cout << "          |     |     " << endl;
			cout << "             g    " << endl;
			cout << "                 " << endl;
			cout << "    po           " << endl;
		}
		for (int i = 0; i <= 2; i++) {
			system("cls");
			cout << "	   _____     " << endl;
			cout << "          |     |     " << endl;
			cout << "             g  " << endl;
			cout << "                 " << endl;
			cout << "     po           " << endl;
		}
		for (int i = 0; i <= 2; i++) {
			system("cls");
			cout << "	   _____     " << endl;
			cout << "          |     |     " << endl;
			cout << "             g  " << endl;
			cout << "       o          " << endl;
			cout << "      p           " << endl;
		}
		for (int i = 0; i <= 2; i++) {
			system("cls");
			cout << "	   _____     " << endl;
			cout << "          |     |     " << endl;
			cout << "         o   g    " << endl;
			cout << "                 " << endl;
			cout << "      p           " << endl;
		}
		for (int i = 0; i <= 2; i++) {
			system("cls");
			cout << "	   _____     " << endl;
			cout << "          |o    |     " << endl;
			cout << "            g     " << endl;
			cout << "                 " << endl;
			cout << "      p           " << endl;
		}
		for (int i = 0; i <= 10; i++) {
			system("cls");
			cout << "	   _____     " << endl;
			cout << "          |  o  |     G" << endl;
			cout << "          g           O" << endl;
			cout << "                      A" << endl;
			cout << "      p               L" << endl;

		}
		x = 1;
	}


}