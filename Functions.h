#pragma once
#include"Footballer1.h"


int getChoice();
void mainMenu();
void selectTeam(vector<Footballer>&);
void chelseaTeam(vector<Footballer>&);
void fillVector(vector<Footballer>&);
void fillVectorOpp(vector<Footballer>&);
void playMatch(int count);
void printNames(vector<Footballer>& RealMadrid, int i);
void printVector(vector<Footballer>& RealMadrid, int i);
void goalScored(int, int, vector<Footballer>& RealMadrid, int);
void goalConcede(int, int, vector<Footballer>& RealMadrid, int);