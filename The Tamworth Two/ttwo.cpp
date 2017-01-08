/*
 ID: ashilol1
 PROG: ttwo
 LANG: C++11
 */
#include <iostream>
#include <fstream>
using namespace std;
int grid[10][10]; //0: blank, 1: obstacle

void turn(int* state){
    if (state[2] == 1){
        state[2] = 0;
        state[3] = -1;
    } else if (state[2] == -1){
        state[2] = 0;
        state[3] = 1;
    } else if (state[3] == 1){
        state[3] = 0;
        state[2] = 1;
    } else if (state[3] == -1){
        state[3] = 0;
        state[2] = -1;
    }
}

bool match(int* cstate, int* fstate, int* state){
    for (int i = 0; i < 4; i++){
        if (cstate[i] != state[i] || fstate[i] != state[i + 4]) return false;
    }
    return true;
}

void travel(int *cstate, int *fstate, int *initial, int steps, ostream &out){
//    out << steps << ":\n";
//    for (int i = 9; i >= 0; i--){
//        for (int j = 0; j < 10; j++){
//            if (grid[j][i] == 1) out << '*';
//            else if (cstate[0] == j && cstate[1] == i) out << 'C';
//            else if (fstate[0] == j && fstate[1] == i) out << 'F';
//            else out << '.';
//        }
//        out << "\n";
//    }
//    out << "\n";
    
    if (match(cstate, fstate, initial) || steps > 1000) out << 0 << "\n";
    else if (cstate[0] == fstate[0] && cstate[1] == fstate[1]) out << steps << "\n";
    else {
        int cx = cstate[0] + cstate[2], cy = cstate[1] + cstate[3];
        int fx = fstate[0] + fstate[2], fy = fstate[1] + fstate[3];
        if (cx >= 0 && cx < 10 && cy >= 0 && cy < 10 && grid[cx][cy] == 0){
            cstate[0] += cstate[2], cstate[1] += cstate[3];
        } else turn(cstate);
        if (fx >= 0 && fx < 10 && fy >= 0 && fy < 10 && grid[fx][fy] == 0){
            fstate[0] += fstate[2], fstate[1] += fstate[3];
        } else turn(fstate);
        
        travel(cstate, fstate, initial, steps + 1, out);
    }
}

int main() {
    int fx, fy, cx, cy, fxdir = 0, fydir = 1, cxdir = 0, cydir = 1;

//    ifstream in ("/Users/AShi/Documents/Repos/USACO/The Tamworth Two/ttwo.txt");
    ifstream in ("ttwo.in");
    ofstream out ("ttwo.out");
    char x;
    for (int i = 9; i >= 0; i--){
        for (int j = 0; j < 10; j++){
            in >> x;
            if (x != '*') grid[j][i] = 0;
            if (x == 'F') fx = j, fy = i;
            else if (x == 'C') cx = j, cy = i;
            else if (x == '*') grid[j][i] = 1;
        }
    }
    
    int fstate[4] = {fx, fy, fxdir, fydir}, cstate[4] = {cx, cy, cxdir, cydir};
    int initial[8] = {cx, cy, cxdir, cydir, fx, fy, fxdir, fydir};
    cx = cstate[0] + cstate[2], cy = cstate[1] + cstate[3];
    fx = fstate[0] + fstate[2], fy = fstate[1] + fstate[3];
    if (cx >= 0 && cx < 10 && cy >= 0 && cy < 10 && grid[cx][cy] == 0){
        cstate[0] += cstate[2], cstate[1] += cstate[3];
    } else turn(cstate);
    if (fx >= 0 && fx < 10 && fy >= 0 && fy < 10 && grid[fx][fy] == 0){
        fstate[0] += fstate[2], fstate[1] += fstate[3];
    } else turn(fstate);
    
    travel(cstate, fstate, initial, 1, out);
    
    return 0;
}
