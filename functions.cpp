#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
#include"Functions.h"
#include"Footballer1.h"
#include"Gameplay.h"
#include"Leaugetable.h"


///SCORES FOR EACH MATCH////
int match1_userscore[1] = {0};
int match1_oppscore[1] = {0};

int f = 0;

int counter = 0;
int matchNum = 0;
vector<Footballer> chelseaFC;

vector<int> myvector;
vector<Footballer> liverpoolFC;

int chelsea_start_pass[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_speed[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_dribble[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_shoot[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_defend[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_goalkeeper[11] = { 0,0,0,0,0,0,0,0,0,0,0 };





int r_start_pass[11] = { 0,0,0,0,0,0,0,0,0,0 };
int r_start_shoot[11] = { 0,0,0,0,0,0,0,0,0,0};
int r_start_dribble[11] = { 0,0,0,0,0,0,0,0,0,0 };
int r_start_speed[11] = { 0,0,0,0,0,0,0,0,0,0};
int r_start_defend[11] = { 0,0,0,0,0,0,0,0,0,0};
int r_start_goalkeeper[11] = { 0,0,0,0,0,0,0,0,0,0 };
string startingTeam[12] = {"","","",""};
string startingTeamOpp[11];
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
	fillVector(liverpoolFC);
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

			selectTeam(liverpoolFC);
			x = x + 1;
			if (x > 11)
			{
				break;
			}

		} while (x < 11);

		cout << "success";
		system("cls");

		cout << "-----Starting Line Up-----";
		for (int f = 0; f < 12; f++)
			cout << startingTeam[f] << "\n";

		playMatch(matchNum);

		break;

	}
}



void selectTeam(vector<Footballer>& liverpoolFC) {
	cout << "\nPress the number to select players for your team\n";
	for (unsigned int i = 0; i < 12; i++) {
		cout << i << "-" << liverpoolFC[i].getName() << "\n";
	}
	int f = 0;
	cin >> f;
	if (f) {
		r_start_pass[f] = (liverpoolFC[f].getPassing());
		r_start_speed[f] = (liverpoolFC[f].getSpeed());
		r_start_dribble[f] = (liverpoolFC[f].getDribbling());
		r_start_shoot[f] = (liverpoolFC[f].getShooting());
		r_start_defend[f] = (liverpoolFC[f].getDefending());
		r_start_goalkeeper[f] = (liverpoolFC[f].getGoalkeeping());
		startingTeam[f] = (liverpoolFC[f].getName());
		liverpoolFC[f].selected();
		system("cls");
		
		


		
	}


}


void chelseaTeam(vector<Footballer>& chelseaFC) {
	for (unsigned int i = 1; i < 11; i++) {
		chelsea_start_pass[i] = (chelseaFC[i].getPassing());
		chelsea_start_speed[i] = (chelseaFC[i].getSpeed());
		chelsea_start_dribble[i] = (chelseaFC[i].getDribbling());
		chelsea_start_shoot[i] = (chelseaFC[i].getShooting());
		chelsea_start_defend[i] = (chelseaFC[i].getDefending());
		chelsea_start_goalkeeper[i] = (chelseaFC[i].getGoalkeeping());
		startingTeamOpp[i] = (chelseaFC[i].getName());

	}

}


//pass, speed, dribbbling, def, shoot

void fillVector(vector<Footballer>& liverpoolFC) {

	Footballer empty("empty", "empty", 0, 0, 0, 0, 0,0, 0);
	liverpoolFC.push_back(empty);

	Footballer firmino("Firmino", "ATT", 15, 14, 17, 6, 17,0,0);
	liverpoolFC.push_back(firmino);

	Footballer wijnaldum("Wijnaldum", "MID", 15, 14, 15, 10, 14,0,0);
	liverpoolFC.push_back(wijnaldum);

	Footballer robertson("Robertson", "DEF", 14, 15, 14, 15, 7,0,0);
	liverpoolFC.push_back(robertson);

	Footballer salah("Salah", "ATT", 13, 18, 18, 2, 18,0,0);
	liverpoolFC.push_back(salah);

	Footballer mane("Mane", "ATT", 12, 17, 16, 10, 17,0,0);
	liverpoolFC.push_back(mane);

	Footballer allison("Allsion", "GK", 0, 0, 0, 0, 0, 18, 0);
	liverpoolFC.push_back(allison);

	Footballer henderson("Henderson", "MID", 16, 10, 13, 14, 13, 0, 0);
	liverpoolFC.push_back(henderson);

	Footballer fabinho("Fabinho", "MID", 15, 13, 14, 16, 14, 0, 0);
	liverpoolFC.push_back(fabinho);

	Footballer gomez("Gomez", "DEF", 13, 17, 13, 15, 4, 0, 0);
	liverpoolFC.push_back(gomez);

	Footballer vanDijk("Van Dijk", "DEF", 14, 14, 13, 19, 7, 0, 0);
	liverpoolFC.push_back(vanDijk);

	Footballer trent("Trent", "DEF", 18, 14, 14, 13, 12, 10, 10);
	liverpoolFC.push_back(trent);

	
}


int i = 0;

void printVector(vector<Footballer>& liverpoolFC, int i) {
	cout << "Name =  " << liverpoolFC[i].getName() << "\n";
	cout << "Passing: " << liverpoolFC[i].getPassing() << "\n";
	cout << "Speed: " << liverpoolFC[i].getSpeed() << "\n";
	cout << "Dribbling: " << liverpoolFC[i].getDribbling() << "\n";
	cout << "Defending: " << liverpoolFC[i].getDefending() << "\n";
	cout << "Shooting: " << liverpoolFC[i].getShooting() << "\n";
	cout << "\n";


}


int attArray[3];
int watch = 0;

void goalConcede(int shotsTarget, int goalKeeper, vector<Footballer>& team1, int awayScore[]) {
	int shootList[3];
	for (i = 1; i < 11; i++) {
		if (team1[i].getPosition() == "ATT") {
			shootList[watch] = i;
			watch = watch + 1;
			
		}

	}

	srand(time(0));
	int awayScore1 = 0;

	for (int i = 0; i < shotsTarget; i++) {
		random_shuffle(shootList, shootList + 3);
		int randomAtt = shootList[0];
		int shoot = rand() % (team1[randomAtt].getShooting());
		int save = rand() % (goalKeeper);
		if (shoot > save) {
			awayScore1 = awayScore1 + 1;
			cout << team1[randomAtt].getName() << " Scores\n";

			

		}


	}
	
	awayScore[0] = awayScore1;
}

void goalScored(int shotsTarget, int goalKeeper, vector<Footballer>& RealMadrid, int homeScore[]) {
	
	
	for (int f = 1; f < 11; f++) {
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
	srand(time(0));
	for (int i = 0; i < shotsTarget; i++) {
		int score = rand() % 10;
		//cout << "shots on target= " shotsTarget;
		if (score <= 10) {
			random_shuffle(attArray, attArray + 3);
			int randomAtt = attArray[0];
			int shoot = rand() % (RealMadrid[randomAtt].getShooting());
			int save = rand() % (goalKeeper);
			if (shoot > save) {
				homeScore1 = homeScore1 + 1;
				cout << RealMadrid[randomAtt].getName() << " Scores\n";
				

			}

		}
		
	}
	
	homeScore[0] = homeScore1;
}



void playMatch(int count) {


	if (count == 0) {
		
		goalConcede(match1.shots_on_target(match1.chancesMade(match1.passesMade(chelsea_start_pass), match1.dribblesMade(chelsea_start_dribble, match1.tacklesMade(r_start_defend))), match1.shootingAccuracy(chelsea_start_shoot)), match1.goalKeeping(r_start_goalkeeper), chelseaFC, match1_oppscore);
		goalScored(match1.shots_on_target(match1.chancesMade(match1.passesMade(r_start_pass), match1.dribblesMade(r_start_dribble, match1.tacklesMade(chelsea_start_defend))), match1.shootingAccuracy(r_start_shoot)), match1.goalKeeping(chelsea_start_goalkeeper), liverpoolFC, match1_userscore);
		cout <<"\nLiverpool:  " << match1_userscore[0] <<"Chelsea - "  << match1_oppscore[0];
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

	Footballer kepa("Kepa", "GK", 0, 0, 0, 0, 0, 14, 0);
	chelseaFC.push_back(kepa);

	Footballer abraham("Abraham", "ATT", 10, 15, 13, 2, 14,0, 0);
	chelseaFC.push_back(abraham);

	Footballer kovacic("Kovacic", "MID", 14, 13, 15, 12, 10,0, 0);
	chelseaFC.push_back(kovacic);

	Footballer tomori("Tomori", "DEF", 12, 14, 12, 13, 3,0, 0);
	chelseaFC.push_back(tomori);

	Footballer pulisic("Pulisic", "ATT", 13, 16, 14, 5, 11,0, 0);
	chelseaFC.push_back(pulisic);

	Footballer willian("Willian", "ATT", 13, 14, 16, 8, 14,0, 0);
	chelseaFC.push_back(willian);

	Footballer mount("Mount", "MID", 13, 11, 13, 10, 13, 0, 0);
	chelseaFC.push_back(mount);

	Footballer barkley("barkley", "MID", 14, 12, 13, 8, 12, 0, 0);
	chelseaFC.push_back(barkley);

	Footballer zouma("Zouma", "DEF", 11, 16, 12, 13, 3, 0, 0);
	chelseaFC.push_back(zouma);

	Footballer reece("reece", "DEF", 12, 14, 13, 12, 5, 0, 0);
	chelseaFC.push_back(reece);

	Footballer azpilaqueta("azpilaqueta", "DEF", 14, 10, 12, 15, 6, 0, 0);
	chelseaFC.push_back(azpilaqueta);



}