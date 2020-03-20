#pragma once
#include"Footballer1.h"


int getChoice();
void mainMenu();
void selectTeam(vector<Footballer>&);
void oppTeam(vector<Footballer>&, vector<Footballer>&);
void fillVector(vector<Footballer>&);
void fillVectorOpp(vector<Footballer>&, vector<Footballer>&);
void playMatch(int count);
void printNames(vector<Footballer>& RealMadrid, int i);
void printVector(vector<Footballer>& RealMadrid, int i);
void goalScored(int, int, vector<Footballer>& RealMadrid, int);
void goalConcede(int, int, vector<Footballer>& RealMadrid, int);
int throughBall(vector<Footballer>&, vector<Footballer>&);
int shot_at_goal(vector<Footballer>&, vector<Footballer>&, int);
int teamOverall(vector<Footballer> team);
int chancesMade(int);
int outside_box_shot(vector<Footballer>&, vector<Footballer>&);
int cornerKick(vector<Footballer>&, vector<Footballer>&);
int cross_into_box(vector<Footballer>&, vector<Footballer>&);
int freeKick(vector<Footballer>& team1, vector<Footballer>& team2);
int penalty(vector<Footballer>& team1, vector<Footballer>& team2);

static int createDB(const char* s);
static int createTable(const char* s);
static int deleteData(const char* s);
static int insertData(const char* s);
static int selectData(const char* s);
static int updateGoal(const char* s, string name);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);