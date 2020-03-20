#include"Footballer1.h"
#include<vector>

Footballer::Footballer() {
	//null states
	int passing = 0;
	int speed = 0;
	int dribbling = 0;
	int defending = 0;
	int shooting = 0;
	int goalKeeping = 0;
	int picked = 0;

}

//overload constructor

Footballer::Footballer(string name1,string position1, int passing1, int speed1, int dribbling1, int defending1, int shooting1,int goalKeeping1, int picked1){
	name = name1;
	position = position1;
	passing = passing1;
	speed = speed1;
	dribbling = dribbling1;
	defending = defending1;
	shooting = shooting1;
	goalKeeping = goalKeeping1;
	picked = picked1;
	

}


//destructor
Footballer::~Footballer(){


}

int Footballer::playerPicked() {
	return picked;
}


//functions
string Footballer::getName(){
	return name;
}

string Footballer::getPosition() {
	return position;
}

int Footballer::getPassing(){
	return passing;
}

int Footballer::getSpeed() {
	return speed;
}

int Footballer::getDribbling()  {
	return dribbling;
}

int Footballer::getDefending() {
	return defending;
}

int Footballer::getShooting() {
	return shooting;
}


int Footballer::getGoalkeeping() {
	return goalKeeping;
}

int Footballer::getOverall() {
	int overall = passing + speed + dribbling + defending + shooting + goalKeeping;
	return overall;
}


void Footballer::selected() {
	picked = 1;

}

void Footballer::notSelected() {
	picked = 0;

}