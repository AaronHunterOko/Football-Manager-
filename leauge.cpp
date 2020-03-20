
#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"leauge.h"
#include"Footballer.h"


using namespace std;
int n = 0;
int temp;
int y;



team arsenal =
{
    "Arsenal",
    2
};
team liverpool =
{
    "Liverpool",
    6
};
team chelsea =
{
    "Chelsea",
    9
};
team everton =
{
    "Everton",
    14
};

int teamList[4] = { arsenal.points,liverpool.points,everton.points,chelsea.points };


void sortTeams() {


    n = 0;
    int j;
    for (n = 0; n < 4; n++) {
        for (j = n + 1; j < 4; j++)
        {
            if (teamList[n] < teamList[j]) {
                temp = teamList[n];
                teamList[n] = teamList[j];
                teamList[j] = temp;

            }
        }

    }


}
int posCount = 1;

void displayTable() {
    cout << "---------Premier Leauge Table-------- " << endl;
    cout << " " << endl;
    cout << "Pos|  Team     |Points";
    cout << " " << endl;
    for (y = 0; y < 4; y++) {
        if (teamList[y] == arsenal.points) {
            cout << posCount << "  | " << arsenal.name << "   | " << teamList[y] << endl;
            posCount = posCount + 1;
        }
        else if (teamList[y] == liverpool.points) {
            cout << posCount << "  | "  << liverpool.name << " | " << teamList[y] << endl;
            posCount = posCount + 1;

        }
        else if (teamList[y] == chelsea.points) {
            cout << posCount << "  | "  << chelsea.name << "   | " << teamList[y] << endl;
            posCount = posCount + 1;
        }
        else if (teamList[y] == everton.points) {
            cout << posCount << "  | "  << everton.name << "   | " << teamList[y] << endl;
            posCount = posCount + 1;
        }

    }


}


