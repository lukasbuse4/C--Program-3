#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>  // for manipulators

using namespace std;

//tolower prototype
string toLower(string);
void takeFile(string, vector<string>&, vector<string>&, vector<int>&, vector<int>&);
void displayTeam(string, vector<string>, vector<string>, vector<int>, vector<int>);
void battingReport(int,vector<string>, vector<string>, vector<int>, vector<int> );
void sluggingReport (int,vector<string>, vector<string>, vector<int>, vector<int>);

int main() {
    //do while userInput
    cout<< "Welcome to the baseball stats analyzer"<< endl;
    string userInput;
    do {
        //commands
        cout << "Please select one of the options below"<< endl;

        cout<< "INPUT filename"<< endl;
        cout << "TEAM identifier" << endl;
        cout << "REPORT n BATTING" << endl;
        cout << "REPORT n SLUGGING" << endl;
        cout << "QUIT"<< endl;

        cout << "Please provide input:" << endl;

        //recongize lower and cap letters
        userInput = "\0";
        //REPORT
        getline(cin, userInput);
        cout << userInput << endl;
        //toLower function call
        userInput = toLower(userInput);

        vector<string> playerNames; // declaring vectors
        vector<string> teamNames;

        vector <int> battingAverage ;
        vector <int> sluggingAverage ;


        if(userInput == "input"){
            cin >> userInput;// gets input stops at first space, gets secon whole input endline
            userInput = toLower(userInput);

            //getting filename

            //call function, data setup
            takeFile(userInput, playerNames, teamNames, battingAverage, sluggingAverage);
        }
        else if ( userInput == "team"){

            cin >> userInput;
            userInput = toLower(userInput);

        }
        else if (userInput == "report"){
            cin >> userInput; //n
            cin >> userInput; //BATTING or SLUGGING
            userInput = toLower(userInput);
            if(userInput == "batting"){

                //call respective function
            }
            else if(userInput == "slugging"){

            }
        }
        else if (userInput == "quit"){
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout<< "wrong input, please provide correct input" << endl;
        }

    }
    while (userInput != "quit");

  return 0;
}

//toLower function
string toLower(string inputString){
    int i=0;
    for(i=0; i < inputString.length(); i++)
    {
        if(isalpha(inputString.at(i))) {
            inputString[i] = tolower(inputString[i]);
        }
    }

    return inputString;
}
void takeFile(string takeFile, vector<string>& playerNames , vector<string>& teamNames, vector<int>& battingAverage, vector<int>& sluggingAverage){
 ifstream file;
 string fileName = takeFile; //be file name later . string varibale

 file.open(fileName);
 if(!file.is_open()){
     cout<< "File Not Found"<< endl;
     return;

 }

 string x; //dummy variable

 //take in data
 string playersName;
 string teamName;
 int gamesPlayed;
 int bats;
 int runsScored;
 int hits;
 int doubles;
 int triples;
 int homeruns;


 //ask how to delcare arrays when dont know how big file is
int singles;
int totalBases;
int battingAvg;
int sluggingAvg;

 istringstream ss;
 while (!file.eof()) {
     getline(ss, playersName, ';');
     playerNames.push_back(playersName);

     getline(ss, teamName, ';');
     teamNames.push_back(teamName);

     getline(ss, x , ';');
     gamesPlayed= stoi (x);

     getline(ss, x, ';');
     bats = stoi (x);

     getline(ss, x, ';');
     runsScored = stoi(x);

     getline(ss,x, ';');
     hits = stoi (x);

     getline(ss, x, ';');
     doubles = stoi (x);

     getline(ss, x, ';');
     triples = stoi (x);

     getline(ss, x);
     homeruns = stoi(x);

     //fomrulas
     singles = hits - (doubles + triples + runsScored);
     totalBases = singles + 2*doubles + 3*triples + 4*runsScored;

     if (bats == 0){
         battingAvg = 0;
         sluggingAvg = 0;
     }
     else {
         battingAvg = (hits) / (bats);
         sluggingAvg = ( totalBases) /  (bats);
     }
     //information stored
     battingAverage.push_back(battingAvg);
     sluggingAverage.push_back(sluggingAvg);

 }//end of while


}
void displayTeam(string team, vector<string> playerNames , vector<string>teamNames, vector<int>battingAverage, vector<int> sluggingAverage){
    //tabular form
    //loop check ever name == matches display team given, if matches grabs index (parallel)

    vector <string> dummyNames;
    vector <int> dummyBatting;
    vector <int> dummySlugging;

    int index= -1;

    for(int i = 0; i < teamNames.size(); i++){
        if (teamNames.at(i) == team){
            index= i;
            dummyNames.push_back(playerNames.at(i)); // been determined at i= matches (parallel) dummy has team and players together (holding container)
            dummyBatting.push_back(battingAverage.at(i));
            dummySlugging.push_back(sluggingAverage.at(i));
        }
    }

    vector<string> alphaNames;
    vector<int> alphaBatting;
    vector<int> alphaSlugging;

    for(int j = 0; j < dummyNames.size(); j++){
        string alphaName = dummyNames.at(j);
        int alphaIndex = j;
        for(int k = j+1; k < dummyNames.size(); k++) {
            if (dummyNames.at(k) < alphaName) {
                alphaName = dummyNames.at(k);
                alphaIndex = k;
            }
        }

        alphaNames.push_back(dummyNames.at(alphaIndex));
        alphaBatting.push_back(dummyBatting.at(alphaIndex));
        alphaSlugging.push_back(dummySlugging.at(alphaIndex));
    }



   // cout << "Name"<< right << setw(22) << "Team " << right << setw(15)<< "Batting %"  << right << setw(12) << "Slugging %"<< endl;

}
void battingReport(int bat,  vector<string> playerNames , vector<string>teamNames, vector<int>battingAverage, vector<int> sluggingAverage){
//passes in integer, displays top


}
void sluggingReport (int slugging,  vector<string> playerNames , vector<string>teamNames, vector<int>battingAverage, vector<int> sluggingAverage){


}



// 2 paralell