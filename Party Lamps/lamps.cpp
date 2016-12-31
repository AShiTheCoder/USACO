/*
 ID: ashilol1
 PROG: lamps
 LANG: C++11
 */
//this solution is bad LOL
#include <iostream>
#include <fstream>
#include <array>
using namespace std;

bool match(int* master, int* state){
    for (int i = 0; i < 6; i++){
        if (master[i] == -1) continue;
        else if (master[i] != state[i]) return false;
    }
    return true;
}

void printState(int N, int *state, ostream &out){
    for (int i = 0; i < N; i++){
        out << state[(i + 1) % 6];
    }
    out << "\n";
}

int main() {
    int N, C, x, numOn = 0, numOff = 0;
    array<int, 100> on, off;
    array<int, 8> workingStates = {-1, -1, -1, -1, -1, -1, -1, -1};
    int state[6] = {-1, -1, -1, -1, -1, -1}; //states of each lamp (lamps mod 6)
    //0-3 are for 1 switch; 4-7 are for 3
    int oddStates[8][6] = {
        {0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 0, 1},
        {0, 1, 0, 0, 1, 0}, {1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1}
    };
    //0 is for 0 switches; 1-6 are for 2, 7 is for 4
    int evenStates[8][6] = {
        {1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}
    };
    int oddRankings[8] = {0, 6, 1, 3, 4, 2, 5, 7}; //order to print solutions
    int evenRankings[8] = {4, 6, 2, 7, 3, 1, 5, 0}; //order to print solutions
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Party Lamps/lamps.txt");
        ifstream in ("lamps.in");
    ofstream out ("lamps.out");
    in >> N >> C;
    in >> x;
    int c = 0;
    while (x != -1){
        on[c] = x;
        c++;
        numOn++;
        in >> x;
    }
    in >> x;
    c = 0;
    while (x != -1){
        off[c] = x;
        c++;
        numOff++;
        in >> x;
    }
    //create the desired state
    for (int i = 0; i < numOn; i++){
        state[on[i] % 6] = 1;
    }
    for (int i = 0; i < numOff; i++){
        state[off[i] % 6] = 0;
    }
    
    bool usingOdd = C % 2;
    c = 0;
    if (C > 4){
        if (C % 2){
            for (int i = 0; i < 8; i++){
                if (match(state, oddStates[i])){
                    workingStates[c] = i;
                    c++;
                }
            }
        } else {
            for (int i = 0; i < 8; i++){
                if (match(state, evenStates[i])){
                    workingStates[c] = i;
                    c++;
                }
            }
        }
    } else if (C == 0){
        if (match(state, evenStates[0])){
            workingStates[0] = 0;
            c++;
        }
    } else if (C == 1){
        for (int i = 0; i < 4; i++){
            if (match(state, oddStates[i])){
                workingStates[c] = i;
                c++;
            }
        }
    } else if (C == 2){
        for (int i = 0; i < 7; i++){
            if (match(state, evenStates[i])){
                workingStates[c] = i;
                c++;
            }
        }
    } else if (C == 3){
        for (int i = 0; i < 8; i++){
            if (match(state, oddStates[i])){
                workingStates[c] = i;
                c++;
            }
        }
    } else {
        for (int i = 0; i < 8; i++){
            if (match(state, evenStates[i])){
                workingStates[c] = i;
                c++;
            }
        }
    }
    
    if (workingStates[0] == -1){
        out << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < c; j++){
                if (usingOdd){
                    if (oddRankings[i] == workingStates[j]){
                        //print it
                        printState(N, oddStates[workingStates[j]], out);
                    }
                } else {
                    if (evenRankings[i] == workingStates[j]){
                        //print it
                        printState(N, evenStates[workingStates[j]], out);
                    }

                }
            }
        }
    }
    return 0;
}
