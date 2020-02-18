#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
#include"Functions.h"
#include"Footballer1.h"
#include"Gameplay.h"


///SCORES FOR EACH MATCH////
int match1_userscore[1] = {0};
int match1_oppscore[1] = {0};

int f = 0;

int counter = 0;
int matchNum = 0;
vector<Footballer> chelseaFC;

vector<int> myvector;
vector<Footballer> realMadrid;

int chelsea_start_pass[7] = { 0,0,0,0,0,0,0 };
int chelsea_start_speed[7] = { 0,0,0,0,0,0,0 };
int chelsea_start_dribble[7] = { 0,0,0,0,0,0,0 };
int chelsea_start_shoot[7] = { 0,0,0,0,0,0,0 };
int chelsea_start_defend[7] = {0,0,0,0,0,0,0};
int chelsea_start_goalkeeper[7] = { 0,0,0,0,0,0,0};





int r_start_pass[7] = { 0,0,0,0,0,0,0 };
int r_start_shoot[7] = { 0,0,0,0,0,0,0 };
int r_start_dribble[7] = { 0,0,0,0,0,0,0 };
int r_start_speed[7] = { 0,0,0,0,0,0,0 };
int r_start_defend[7] = { 0,0,0,0,0,0,0 };
int r_start_goalkeeper[7] = { 0,0,0,0,0,0,0 };
string startingTeam[7] = {"","","",""};
string startingTeamOpp[7];
string startATT[11] = { "","","" };


Gameplay match1(2);



int getChoice() {
	int choice = 0;
	cout << "Enter choice:";
	cin >> choice;
	return choice;
	system("cls");

}


void mainMenu() {
	//fills in player info
	fillVector(realMadrid);
	fillVectorOpp(chelseaFC);
	chelseaTeam(chelseaFC);


	cout << "-----Main Menu-----\n";
	cout << "[0] Quit\n";
	cout << "[1] Play Match\n";


	switch (getChoice())
	{
	case 0:
		cout << "------Quitting Game------";
		exit(0);
		
		break;

	case 1:
		cout << "------Play Match------";
		int x = 0;
		do {

			selectTeam(realMadrid);
			x = x + 1;
			if (x > 5)
			{
				break;
			}

		} while (x < 5);

		system("cls");

		cout << "-----Starting Line Up-----";
		for (int f = 0; f < 6; f++)
			cout << startingTeam[f] << "\n";

		playMatch(matchNum);

		break;

	}
}



void selectTeam(vector<Footballer>& RealMadrid) {
	cout << "\nPress the number to select players for your team\n";
	for (unsigned int i = 0; i < 6; i++) {
		cout << i << "-" << RealMadrid[i].getName() << "\n";
	}
	int f = 0;
	cin >> f;
	if (f) {
		r_start_pass[f] = (RealMadrid[f].getPassing());
		r_start_speed[f] = (RealMadrid[f].getSpeed());
		r_start_dribble[f] = (RealMadrid[f].getDribbling());
		r_start_shoot[f] = (RealMadrid[f].getShooting());
		r_start_defend[f] = (RealMadrid[f].getDefending());
		startingTeam[f] = (RealMadrid[f].getName());
		RealMadrid[f].selected();
		


		
	}


}


void chelseaTeam(vector<Footballer>& chelseaFC) {
	for (unsigned int i = 1; i < 7; i++) {
		chelsea_start_pass[i] = (chelseaFC[i].getPassing());
		chelsea_start_speed[i] = (chelseaFC[i].getSpeed());
		chelsea_start_dribble[i] = (chelseaFC[i].getDribbling());
		chelsea_start_shoot[i] = (chelseaFC[i].getShooting());
		chelsea_start_defend[i] = (chelseaFC[i].getDefending());
		chelsea_start_goalkeeper[i] = (chelseaFC[i].getGoalkeeping());
		startingTeamOpp[i] = (chelseaFC[i].getName());

	}

}



void fillVector(vector<Footballer>& RealMadrid) {

	Footballer empty("empty", "empty", 0, 0, 0, 0, 0,0, 0);
	RealMadrid.push_back(empty);

	Footballer ronaldo("Ronaldo", "ATT", 10, 10, 10, 10, 18,0,0);
	RealMadrid.push_back(ronaldo);

	Footballer kroos("Kroos", "MID", 10, 10, 10, 10, 10,0,0);
	RealMadrid.push_back(kroos);

	Footballer ramos("Ramos", "DEF", 10, 15, 10, 10, 10,0,0);
	RealMadrid.push_back(ramos);

	Footballer benzema("Benzema", "ATT", 10, 10, 10, 10, 12,0,0);
	RealMadrid.push_back(benzema);

	Footballer bale("Bale", "ATT", 10, 10, 10, 10, 13,0,0);
	RealMadrid.push_back(bale);

	Footballer court("Court", "GK", 0, 0, 0, 0, 0, 16, 0);
	RealMadrid.push_back(court);
	
}


int i = 0;

void printVector(vector<Footballer>& RealMadrid, int i) {
	cout << "Name =  " << RealMadrid[i].getName() << "\n";
	cout << "Passing: " << RealMadrid[i].getPassing() << "\n";
	cout << "Speed: " << RealMadrid[i].getSpeed() << "\n";
	cout << "Dribbling: " << RealMadrid[i].getDribbling() << "\n";
	cout << "Defending: " << RealMadrid[i].getDefending() << "\n";
	cout << "Shooting: " << RealMadrid[i].getShooting() << "\n";
	cout << "\n";


}


int attArray[3];


void goalConcede(int shotsTarget, int goalKeeper, vector<Footballer>& RealMadrid, int awayScore[]) {
	for (int i = 0; i <5; i++) {
		awayScore[0] = 5;


	}
	

}

void goalScored(int shotsTarget, int goalKeeper, vector<Footballer>& RealMadrid, int homeScore[]) {
	
	
	for (int f = 1; f < 6; f++) {
		if ((RealMadrid[f].playerPicked()) == 1) {
			if (RealMadrid[f].getPosition() == "ATT") {
				attArray[counter] = f;
				//cout << realMadrid[f].getName();
				counter = counter + 1;


		}
	

	}


	}
	//cout << attArray[0];
	//cout << attArray[1];
	//cout << attArray[2];
	int homeScore1 = 0;

	for (int i = 0; i < shotsTarget; i++) {
		srand(time(0));
		int score = rand() % 10;
		//cout << score;
		if (score <= 10) {
			random_shuffle(attArray, attArray + 3);
			int randomAtt = attArray[0];
			int shoot = rand() % (RealMadrid[randomAtt].getShooting());
			int save = rand() % (goalKeeper);
			if (shoot > save) {
				homeScore1 = homeScore1 + 1;
				cout << RealMadrid[randomAtt].getName() << " Scores";
				cout << homeScore1;
				//cout << "Real Madrid - " << homeScore << " 0 - Barcelona\n";

			}

		}
		
	}
	
	homeScore[0] = homeScore1;
}



void playMatch(int count) {


	if (count == 0) {
		
		goalConcede(match1.shots_on_target(match1.chancesMade(match1.passesMade(chelsea_start_pass), match1.dribblesMade(chelsea_start_dribble, match1.tacklesMade(r_start_defend))), match1.shootingAccuracy(chelsea_start_shoot)), match1.goalKeeping(r_start_goalkeeper), chelseaFC, match1_oppscore);
		goalScored(match1.shots_on_target(match1.chancesMade(match1.passesMade(r_start_pass), match1.dribblesMade(r_start_dribble, match1.tacklesMade(chelsea_start_defend))), match1.shootingAccuracy(r_start_shoot)), match1.goalKeeping(chelsea_start_goalkeeper), realMadrid, match1_userscore);
		cout <<"real madrid:  " << match1_userscore[0] <<"Chelsea - "  << match1_oppscore[0];
		matchNum = matchNum + 1;
		mainMenu();
		

	}


	else if (count == 1) {
		cout << "\nMatch2";
		string oi = "";
		cin >> oi;

	}


}



void printNames(vector<Footballer>& RealMadrid, int i) {

	cout << i << "-" << RealMadrid[i].getName() << "\n";

	


}

//create chelsea
void fillVectorOpp(vector<Footballer>& chelseaFC) {

	Footballer empty("empty", "empty", 0, 0, 0, 0, 0,0, 0);
	chelseaFC.push_back(empty);

	Footballer kepa("Kepa", "GK", 0, 0, 0, 0, 0, 5, 0);
	chelseaFC.push_back(kepa);

	Footballer abraham("Abraham", "ATT", 10, 10, 10, 5, 18,0, 0);
	chelseaFC.push_back(abraham);

	Footballer kovacic("Kovacic", "MID", 10, 10, 10, 8, 10,0, 0);
	chelseaFC.push_back(kovacic);

	Footballer tomori("Tomori", "DEF", 10, 15, 10, 14, 14,0, 0);
	chelseaFC.push_back(tomori);

	Footballer pulisic("Pulisic", "ATT", 10, 10, 10, 5, 12,0, 0);
	chelseaFC.push_back(pulisic);

	Footballer willian("Willian", "ATT", 10, 10, 10, 5, 13,0, 0);
	chelseaFC.push_back(willian);


}