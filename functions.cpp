#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<conio.h>
#include<stdio.h>
#include<sqlite3.h>

using namespace std;
#include"Functions.h"
#include"Footballer1.h"
#include"Gameplay.h"
#include"leauge.h"
#include"testingsqlData.h"

Gameplay play = (1);

int minute = 0;
int second = 0;
int resume = 0;

int choice();
int printTime();
void selection();
int match(vector<Footballer>&, vector<Footballer>&);

vector<Footballer> liverpoolFC;
vector<Footballer> chelseaFC;
vector<Footballer> evertonFC;


void transferPlayer(vector<Footballer>& team1);

///SCORES FOR EACH MATCH////
int match1_userscore[1] = {0};
int match1_oppscore[1] = {0};

int match2_userscore[1] = { 0 };
int match2_oppscore[1] = { 0 };

int f = 0;
int team_select_count = 0;
int counter = 0;
int matchNum = 0;

const char* dir = "c:\\myDir\\LIVERPOOL.db";

int chelsea_start_pass[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_speed[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_dribble[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_shoot[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_defend[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int chelsea_start_goalkeeper[11] = { 0,0,0,0,0,0,0,0,0,0,0 };

int everton_start_pass[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int everton_start_speed[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int everton_start_dribble[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int everton_start_shoot[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int everton_start_defend[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int everton_start_goalkeeper[11] = { 0,0,0,0,0,0,0,0,0,0,0 };


string gkChosen[1];
string defChosen[5] = {" ", " ", " ", ""};
string midChosen[4] = { " ", " ", " " };
string attChosen[4] = {" ", " ", " "};

int r_start_pass[11] = { 0,0,0,0,0,0,0,0,0,0 };
int r_start_shoot[11] = { 0,0,0,0,0,0,0,0,0,0};
int r_start_dribble[11] = { 0,0,0,0,0,0,0,0,0,0 };
int r_start_speed[11] = { 0,0,0,0,0,0,0,0,0,0};
int r_start_defend[11] = { 0,0,0,0,0,0,0,0,0,0};
int r_start_goalkeeper[11] = { 0,0,0,0,0,0,0,0,0,0 };
string startingTeam[13] = {"","","",""};
string startingTeamChelsea[11];
string startingTeamEverton[11];
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
	fillVectorOpp(chelseaFC, evertonFC);
	oppTeam(chelseaFC, evertonFC);
	
	cout << chancesMade(teamOverall(liverpoolFC)) << endl;

	//createDB(dir);
	//createTable(dir);
	//insertData(dir);
	selectData(dir);
	
	//match1.shotAnim();
	
	cout << "-----Main Menu-----\n";
	cout << "[0] Quit\n";
	cout << "[1] Play Next Match\n";
	cout << "[2] View Leauge Table\n";
	cout << "[3] Transfer Market\n";
	

	switch (getChoice())
	{
	case 0:
	{
		cout << "------Quitting Game------";
		exit(0);

		break;

	}

	case 1:
	{
		
		system("cls");
		cout << "------Play Match------" << endl;
		do {

			cout << "                                                                  ----------------------TEAM LINE-UP --------------" << endl;
			cout << "                                                                          GOAL KEEPER:  " << gkChosen[0] << endl;
			cout << "                                                                          DEFENSE: " << defChosen[1] << " " << defChosen[2] << " " << defChosen[3] << " " << defChosen[4] << endl;
			cout << "                                                                          Midfield: " << midChosen[0] << " " << midChosen[1] << " " << midChosen[2] << endl;
			cout << "                                                                          Attack: " << attChosen[0] << " " << attChosen[1] << " " << attChosen[2] << endl;
			selectTeam(liverpoolFC);
			if (team_select_count > 11)
			{
				break;
			}

		} while (team_select_count < 11);


		system("cls");

		cout << "-----Starting Line Up-----";
		for (int f = 0; f < 12; f++)
			cout << startingTeam[f] << "\n";

		cout << "Input any key to continue: ";
		string playOn;
		cin >> playOn;
		system("cls");

		playMatch(matchNum);

		break;
	}
		
	

	case 2:
	{
		system("cls");
		sortTeams();
		displayTable();
		cout << "Enter any input to Continue: ";
		string input;
		cin >> input;
		break;
	}

	case 3:
	{
		system("cls");
		transferPlayer(liverpoolFC);
	}
		

	}

}

int defCount = 1;
int midCount = 0;
int attCount = 0;

void selectTeam(vector<Footballer>& liverpoolFC) {
	cout << "\nPress the number to select players for your team" << endl;
	for (unsigned int i = 1; i < 12; i++) {
		cout << i << "-" << liverpoolFC[i].getName() << "\n";
	}
	int f = 0;
	cin >> f;
	
	if (f <= 11) {
		r_start_pass[f] = (liverpoolFC[f].getPassing());
		r_start_speed[f] = (liverpoolFC[f].getSpeed());
		r_start_dribble[f] = (liverpoolFC[f].getDribbling());
		r_start_shoot[f] = (liverpoolFC[f].getShooting());
		r_start_defend[f] = (liverpoolFC[f].getDefending());
		r_start_goalkeeper[f] = (liverpoolFC[f].getGoalkeeping());
		startingTeam[f] = (liverpoolFC[f].getName());
		if (liverpoolFC[f].playerPicked() == 1) {
			system("cls");
			cout << liverpoolFC[f].getName() << " is already Selected, pick someone else" << endl;
			selectTeam(liverpoolFC);
			
		}
		system("cls");
		if (liverpoolFC[f].getPosition() == "GK" && liverpoolFC[f].playerPicked() == 0) {
			gkChosen[0] = liverpoolFC[f].getName();
			team_select_count = team_select_count + 1;
		}
		else if (liverpoolFC[f].getPosition() == "DEF" && liverpoolFC[f].playerPicked() == 0) {
			defChosen[defCount] = liverpoolFC[f].getName();
			defCount = defCount + 1;
			team_select_count = team_select_count + 1;
		}

		else if (liverpoolFC[f].getPosition() == "MID" && liverpoolFC[f].playerPicked() == 0) {
			midChosen[midCount] = liverpoolFC[f].getName();
			midCount = midCount + 1;
			team_select_count = team_select_count + 1;
		}

		else if (liverpoolFC[f].getPosition() == "ATT" && liverpoolFC[f].playerPicked() == 0) {
			attChosen[attCount] = liverpoolFC[f].getName();
			attCount = attCount + 1;
			team_select_count = team_select_count + 1;
		}
		liverpoolFC[f].selected();

		
		
	}
	system("cls");


}


void oppTeam(vector<Footballer>& chelseaFC, vector<Footballer>& evertonFC) {
	for (unsigned int i = 1; i < 11; i++) {
		chelsea_start_pass[i] = (chelseaFC[i].getPassing());
		chelsea_start_speed[i] = (chelseaFC[i].getSpeed());
		chelsea_start_dribble[i] = (chelseaFC[i].getDribbling());
		chelsea_start_shoot[i] = (chelseaFC[i].getShooting());
		chelsea_start_defend[i] = (chelseaFC[i].getDefending());
		chelsea_start_goalkeeper[i] = (chelseaFC[i].getGoalkeeping());
		startingTeamChelsea[i] = (chelseaFC[i].getName());

		everton_start_pass[i] = (evertonFC[i].getPassing());
		everton_start_speed[i] = (evertonFC[i].getSpeed());
		everton_start_dribble[i] = (evertonFC[i].getDribbling());
		everton_start_shoot[i] = (evertonFC[i].getShooting());
		everton_start_defend[i] = (evertonFC[i].getDefending());
		everton_start_goalkeeper[i] = (evertonFC[i].getGoalkeeping());
		startingTeamEverton[i] = (evertonFC[i].getName());
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

	Footballer trent("Trent", "DEF", 18, 14, 14, 13, 12, 10, 0);
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
	for (int i = 1; i < 11; i++) {
		if (team1[i].getPosition() == "ATT") {
			shootList[watch] = i;
			watch = watch + 1;
			
		}

	}

	srand(time(0));
	int awayScore1 = 0;

	for (int i = 0; i < shotsTarget; i++) {
		random_shuffle(shootList, shootList + 2);
		int randomAtt = shootList[0];
		int shoot = rand() % (team1[randomAtt].getShooting());
		int save = rand() % (goalKeeper);
		if (shoot > save) {
			awayScore1 = awayScore1 + 1;
			cout << team1[randomAtt].getName() << " Scored\n";

			

		}


	}
	
	awayScore[0] = awayScore1;
}

void goalScored(int shotsTarget, int goalKeeper, vector<Footballer>& RealMadrid, int homeScore[]) {
	
	
	for (int f = 1; f < 11; f++) {
		if ((RealMadrid[f].playerPicked()) == 1) {
			if (RealMadrid[f].getPosition() == "ATT") {
				attArray[counter] = f;
				counter = counter + 1;


		}
	

	}


	}
	int homeScore1 = 0;
	srand(time(0));
	for (int i = 0; i < shotsTarget; i++) {
		int score = rand() % 10;
		if (score <= 10) {
			random_shuffle(attArray, attArray + 3);
			int randomAtt = attArray[0];
			int shoot = rand() % (RealMadrid[randomAtt].getShooting());
			int save = rand() % (goalKeeper);
			if (shoot > save) {
				homeScore1 = homeScore1 + 1;
				cout << RealMadrid[randomAtt].getName() << " Scored\n";
				

			}

		}
		
	}
	
	homeScore[0] = homeScore1;
}



void playMatch(int count) {

	
	if (count == 0) {

		
		match(liverpoolFC, evertonFC);
		

	}


	else if (count == 1) {
		match(liverpoolFC, chelseaFC);
		string go;
		cin >> go;

	}


}



void printNames(vector<Footballer>& RealMadrid, int i) {

	cout << i << "-" << RealMadrid[i].getName() << "\n";

	


}

//create chelsea
void fillVectorOpp(vector<Footballer>& chelseaFC, vector<Footballer>& evertonFC) {

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

	Footballer pulisic("Pulisic", "ATT", 13, 16, 14, 5, 13,0, 0);
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

	///////EVERTON//////////////

	Footballer empty1("empty", "empty", 0, 0, 0, 0, 0, 0, 0);
	evertonFC.push_back(empty1);

	Footballer pickford("Pickford", "GK", 0, 0, 0, 0, 0, 13, 0);
	evertonFC.push_back(pickford);

	Footballer keane("Keane", "DEF", 10, 11, 10, 1, 3, 0, 0);
	evertonFC.push_back(keane);

	Footballer mina("mina", "DEF", 8, 13, 8, 1, 3, 0, 0);
	evertonFC.push_back(mina);

	Footballer coleman("Coleman", "DEF", 12, 11, 12, 1, 3, 0, 0);
	evertonFC.push_back(coleman);

	Footballer digne("Digne", "DEF", 12, 14, 13, 1, 5, 0, 0);
	evertonFC.push_back(digne);

	Footballer gomes("Gomes", "MID", 13, 9, 12, 10, 11, 0, 0);
	evertonFC.push_back(gomes);

	Footballer sigurosson("Sigurosson", "MID", 13, 7, 11, 7, 15, 0, 0);
	evertonFC.push_back(sigurosson);

	Footballer delph("Delph", "MID", 12, 11, 12, 14, 7, 0, 0);
	evertonFC.push_back(delph);

	Footballer calvert("Calvert-Lewin", "ATT", 6, 13, 12, 3, 13, 0, 0);
	evertonFC.push_back(calvert);

	Footballer kean("Kean", "ATT", 8, 15, 13, 3, 14, 0, 0);
	evertonFC.push_back(kean);

	Footballer richarlson("Richarlson", "ATT", 10, 15, 14, 5, 13, 0, 0);
	evertonFC.push_back(richarlson);



}

int chancesMade(int teamValue) {
	int chances = teamValue / 10;
	return chances;
}

int teamOverall(vector<Footballer> team) {
	int teamValue = 0;
	for (int i = 0; i < 11; i++) {
		teamValue = teamValue + team[i].getOverall();
	}
	return teamValue;
}

void delay(int ms) {
	clock_t timeDelay = ms + clock();
	while (timeDelay > clock());
}

int match(vector<Footballer>& team1, vector<Footballer>& team2) {
	while (!_kbhit() && resume == 0) {
		if (second > 59) {
			second = 0;
			//++minute;
			minute = minute + 90;

		}
		printTime();
		delay(10);
		second = second + 5;
		int chanceCreated1 = rand()% 5000;
		if (chanceCreated1 <= chancesMade(teamOverall(team1))) {
			srand(time(0));
			int chooseEvent = rand() % 100;
			cout << chooseEvent << endl;
			if (chooseEvent <= 5) {
				resume = 1;
				penalty(team1, team2);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 30 && chooseEvent > 5)  {
				resume = 1;
				outside_box_shot(team1, team2);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 55 && 30 < chooseEvent) {
				resume = 1;
				shot_at_goal(team1, team2, throughBall(team1, team2));
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 75 && 55 < chooseEvent) {
				resume = 1;
				cross_into_box(team1, team2);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 90 && 75 < chooseEvent) {
				resume = 1;
				cornerKick(team1, team2);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 100 && 90 < chooseEvent) {
				resume = 1;
				freeKick(team1, team2);
				string go;
				cin >> go;
				resume = 0;
			}
			
			

		}

		int chanceCreated2 = rand() % 5000;
		cout << "team2 chances : "  <<  chanceCreated2 << endl;
		if (chanceCreated2 <= chancesMade(teamOverall(team2))) {
			srand(time(0));
			int chooseEvent = rand() % 100;
			cout << chooseEvent << endl;
			if (chooseEvent <= 5) {
				resume = 1;
				penalty(team2, team1);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 30 && chooseEvent > 5) {
				resume = 1;
				outside_box_shot(team2, team1);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 55 && 30 < chooseEvent) {
				resume = 1;
				shot_at_goal(team2, team1, throughBall(team2, team1));
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 75 && 55 < chooseEvent) {
				resume = 1;
				cross_into_box(team2, team1);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 90 && 75 < chooseEvent) {
				resume = 1;
				cornerKick(team2, team1);
				string go;
				cin >> go;
				resume = 0;
			}
			else if (chooseEvent <= 100 && 90 < chooseEvent) {
				resume = 1;
				freeKick(team2, team1);
				string go;
				cin >> go;
				resume = 0;
			}



		}

		

		if (minute >= 90) {
			resume = 1;
			cout << "\nMatch finished" << endl;
			fill_n(startingTeam, 13, 0);
			fill_n(gkChosen, 1, 0);
			fill_n(defChosen, 5, 0);
			fill_n(midChosen, 3, 0);
			fill_n(attChosen, 3, 0);
			fill_n(attArray, 3, 0);
			matchNum = matchNum + 1;
			string go;
			cout << "\nPress any key to continue: " << endl;
			cin >> go;
			mainMenu();
		}

	}
	selection();
	return 0;
}


int choice() {
	int x = 0;
	cin >> x;
	cout << x;
	return x;

}


void selection() {
	switch (choice())
	{
	case 0:
		resume = 0;
		break;

	case 1:
		resume = 1;
		break;
	}

}



int printTime() {
	system("cls");
	cout << "Enter 1 to pause the match" << endl;
	printf("Time:   %d:%d\n", minute, second);
	cout << "Enter choice here: ";
	return 0;
}


void transferPlayer(vector<Footballer>& team1) {
	for (int i = 1; i < 11; i++) {
		cout << team1[i].getName();
	}
}

int penalty(vector<Footballer>& team1, vector<Footballer>& team2) {
	int pos = 0;
	int attList[3];
	int gkPos = 0;
	int gkList[1];

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "ATT") {
			attList[pos] = i;
			pos++;
		}
	}

	for (int i = 0; i <= 11; i++) {
		if (team2[i].getPosition() == "GK") {
			gkList[gkPos] = i;
		}
	}
	
	int randomAtt = rand() % 2;
	int randomDir = rand() % 5;
	int randomDirGk = rand() % 5;

	if (rand() % team1[attList[randomAtt]].getShooting() > rand() % team2[gkList[gkPos]].getGoalkeeping()) {
		cout << team1[attList[randomAtt]].getName() << " Powers the penalty past " << team2[gkList[gkPos]].getName() << " Goal" << endl;
	}

	else if (randomDir != randomDirGk) {
		cout << team1[attList[randomAtt]].getName() << " sends " << team2[gkList[gkPos]].getName() << " the wrong way, Goal" << endl;
	}
	return 0;

}

int freeKick(vector<Footballer>& team1, vector<Footballer>& team2) {
	int pos = 0;
	int teamList[6];
	int gkPos = 0;
	int gkList[1];

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "ATT") {
			teamList[pos] = i;
			pos++;
		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "MID") {
			teamList[pos] = i;
			pos++;
		}
	}

	for (int i = 0; i <= 11; i++) {
		if (team2[i].getPosition() == "GK") {
			gkList[gkPos] = i;
		}
	}

	int kickTaker = rand() % 5;

	if ((rand() % team1[teamList[kickTaker]].getShooting()) / 2 > rand() % team2[gkList[gkPos]].getGoalkeeping()) {
		cout << team1[teamList[kickTaker]].getName() << " Scores a beautiful free kick" << endl;
	}


	return 0;
}

int cross_into_box(vector<Footballer>& team1, vector<Footballer>& team2) {
	int pos = 0;
	int midList[3];
	int pos1 = 0;
	int defList[4];
	int pos2 = 0;
	int attList[3];
	int gkPos = 0;
	int gkList[1];

	for (int i = 1; i <= 11; i++) {
		if (team2[i].getPosition() == "GK") {
			gkList[gkPos] = i;
		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "ATT") {
			attList[pos2] = i;
			pos2++;
		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "MID") {
			midList[pos] = i;
			pos++;
		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team2[i].getPosition() == "DEF") {
			defList[pos1] = i;
			pos1++;
		}
	}

	int randomAtt = rand() % 2;
	int randomMid = rand() % 2;
	int randomDef = rand() % 3;

	if (rand() % team1[midList[randomMid]].getDribbling() > rand() % team2[defList[randomDef]].getDefending()) {
		cout << team1[midList[randomMid]].getName() << " Dribbles past " << team2[defList[randomDef]].getName();
		if (rand() % team1[midList[randomMid]].getPassing() > rand() % team2[defList[randomDef]].getDefending()) {
			if (rand() % team1[attList[randomAtt]].getShooting() > rand() % team2[gkList[gkPos]].getGoalkeeping()) {
				cout << team1[midList[randomMid]].getName() << " Dribbles past " << team2[defList[randomDef]].getName() << " and delivers a cross into " << team1[attList[randomAtt]].getName() << " who tucks it away, GOALL" << endl;
			}
		}
	}

	return 0;
}


int cornerKick(vector<Footballer>& team1, vector<Footballer>& team2) {
	int pos = 0;
	int teamList1[10];
	int pos1 = 0;
	int teamList2[10];
	int pos2 = 0;
	int gkList[1];

	for (int i = 1; i <= 11; i++) {
		if (team2[i].getPosition() == "GK") {
			gkList[pos2] = i;

		}
	}


	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "DEF") {
			teamList1[pos] = i;
			pos++;

		}
		if (team1[i].getPosition() == "MID") {
			teamList1[pos] = i;
			pos++;

		}
		if (team1[i].getPosition() == "ATT") {
			teamList1[pos] = i;
			pos++;

		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team2[i].getPosition() == "DEF") {
			teamList2[pos1] = i;
			pos1++;

		}
		if (team2[i].getPosition() == "MID") {
			teamList2[pos1] = i;
			pos1++;

		}
		if (team2[i].getPosition() == "ATT") {
			teamList2[pos1] = i;
			pos1++;

		}
	}

	int randomPlayer1 = rand() % 10;
	int randomPlayer2 = rand() % 10;
	
	if (rand() % team1[teamList1[randomPlayer1]].getShooting() > rand() % team2[teamList2[randomPlayer2]].getDefending() && rand() % team1[teamList1[randomPlayer1]].getShooting() > rand()% team2[gkList[pos2]].getGoalkeeping()) {
		cout << team1[teamList1[randomPlayer1]].getName() << " Scores a wonderful Header from the corner" << endl;
		
	}

	return 0;

}

int outside_box_shot(vector<Footballer>& team1, vector<Footballer>& team2) {
	int pos = 0;
	int pos1 = 0;
	int pos2 = 0;
	int midList[3];
	int attList[3];
	int gkList[1];

	for (int i = 1; i <= 11; i++) {
		if (team2[i].getPosition() == "GK") {
			gkList[pos] = i;

		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "MID") {
			midList[pos1] = i;
			pos1++;
		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "ATT") {
			attList[pos2] = i;
			pos2++;
		}
	}

	srand(time(0));
	int randomMid = rand() % 2;
	int randomAtt = rand() % 2;


	if (rand() % team1[midList[randomMid]].getPassing() > rand() % team2[gkList[pos]].getGoalkeeping()) {
		cout << team1[midList[randomMid]].getName() << " GOAL " << endl;
		

	}
	else {
		cout << team1[midList[randomMid]].getName() << " with a longshot and " << team2[gkList[pos]].getName() << " makes a great save!" << endl;
	}
	return 0;
}


int throughBall(vector<Footballer>& team1, vector<Footballer>& team2) {
	int pos1 = 0;
	int pos2 = 0;
	int midList[3];
	int defList[4];
	int madePass = 0;

	for (int i = 1; i <= 11; i++) {
		if (team1[i].getPosition() == "MID") {
			midList[pos1] = i;
			pos1++;
		}
	}

	for (int i = 1; i <= 11; i++) {
		if (team2[i].getPosition() == "DEF") {
			defList[pos2] = i;
			pos2++;
		}
	}

	srand(time(0));
	int randomMid = rand() % 2;
	int randomDef = rand() % 3;
	

	if (rand() % team1[midList[randomMid]].getPassing() > rand() % team2[defList[randomDef]].getDefending()) {
		cout << team1[midList[randomMid]].getName() << " Makes a fantastic through ball " << endl;
		madePass = 1;

	}
	else {
		cout << team2[defList[randomDef]].getName() << " makes a great tackle" << endl;
	}

	return madePass;
	
}

int shot_at_goal(vector<Footballer>& team1, vector<Footballer>& team2, int passMade) {
	if (passMade == 1) {
		int pos = 0;
		int pos1 = 0;
		int pos2 = 0;
		int attList[3];
		int gkList[1];
		int defList[4];

		for (int i = 1; i <= 11; i++) {
			if (team1[i].getPosition() == "ATT") {
				attList[pos] = i;
				pos++;
			}
		}

		for (int i = 1; i <= 11; i++) {
			if (team2[i].getPosition() == "DEF") {
				defList[pos2] = i;
				pos2++;
			}
		}

		for (int i = 1; i <= 11; i++) {
			if (team2[i].getPosition() == "GK") {
				gkList[pos1] = i;
				
			}
		}

		int randomDef = rand() % 3;
		int randomAtt = rand() % 2;
		if (rand() % team1[attList[randomAtt]].getShooting() > rand() % team2[gkList[pos1]].getGoalkeeping() && rand() % team1[attList[randomAtt]].getSpeed() > rand() % team2[defList[randomDef]].getSpeed()) {
			cout << team1[attList[randomAtt]].getName() << " gets to the ball first and Scores";
			play.shotAnim();
			updateGoal(dir, team1[attList[randomAtt]].getName());
		}

	}
	return 0;
}




static int createDB(const char* s) {
	sqlite3* DB;
	int exit = 0;

	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}



static int createTable(const char* s) {
	sqlite3* DB;

	string sql = "CREATE TABLE IF NOT EXISTS LIVERPOOL("
		"ID INTEGER PRIMARY KEY, "
		"NAME       TEXT NOT NULL, "
		"GOALS        INT NOT NULL,"
		"ASSISTS        INT NOT NULL);";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			cerr << "Error Create Table" << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}
	return 0;
}

static int deleteData(const char* s) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	string sql = "DELETE FROM LIVERPOOL;";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;

}


static int insertData(const char* s) {
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);
	string sql("INSERT INTO LIVERPOOL(NAME, GOALS, ASSISTS) VALUES('Salah', 0, 0);"
		"INSERT INTO LIVERPOOL(NAME, GOALS, ASSISTS) VALUES('Firmino',  0, 0);"
		"INSERT INTO LIVERPOOL(NAME, GOALS, ASSISTS) VALUES('Mane',  0, 0);"
		"INSERT INTO LIVERPOOL(NAME, GOALS, ASSISTS) VALUES('Wijnaldum',  0, 0);"
	);

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error Insert data" << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records created successfully" << endl;

	return 0;

}

static int updateGoal(const char* s, string name) {
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);
	string sql("UPDATE LIVERPOOL SET GOALS = GOALS + 1 WHERE NAME = '" + name + "'");


	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error insert" << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records created successfully" << endl;

	return 0;

}

static int selectData(const char* s) {
	sqlite3* DB;
	int exit = sqlite3_open(s, &DB);

	string sql = "SELECT * FROM LIVERPOOL;";

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;

}


static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << argv[i] << endl;
	}
	cout << endl;

	return 0;
}
