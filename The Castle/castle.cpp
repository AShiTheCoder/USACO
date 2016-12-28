/*
ID: ashilol1
PROG: castle
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int HOUSE[50][50];
int ROOMS[50][50];

void setNeighbors(int i, int j, int r, int N, int M, int &size){
    ROOMS[i][j] = r;
    size++;
    //bottom neighbor
    if (i + 1 < N && ROOMS[i + 1][j] == 0 && !(HOUSE[i][j] & 0b1000)){
        setNeighbors(i + 1, j, r, N, M, size);
    }
    //top neighbor
    if (i - 1 >= 0 && ROOMS[i - 1][j] == 0 && !(HOUSE[i][j] & 0b10)){
        setNeighbors(i - 1, j, r, N, M, size);
    }
    //right neighbor
    if (j + 1 < M && ROOMS[i][j + 1] == 0 && !(HOUSE[i][j] & 0b100)){
        setNeighbors(i, j + 1, r, N, M, size);
    }
    //left neighbor
    if (j - 1 >= 0 && ROOMS[i][j - 1] == 0 && !(HOUSE[i][j] & 0b1)){
        setNeighbors(i, j - 1, r, N, M, size);
    }
//    cout << i << ", " << j << " is part of room " << r << "\n";
}

//returns largest room size
int calcRooms(int N, int M){
    int room = 0, i = 0, j = 0, size = 0, maxSize = 0;
    memset(ROOMS, 0, sizeof(ROOMS));
    while (i < N){
        if (ROOMS[i][j] == 0){
            room++;
            size = 0;
            setNeighbors(i, j, room, N, M, size);
        }
        if (size > maxSize){
            maxSize = size;
        }
        j++;
        if (j == M){
            j = 0;
            i++;
        }
    }
    return maxSize;
}

int main(){
    int M, N, room = 0;
    memset(ROOMS, 0, sizeof(ROOMS));
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/The Castle/castle.txt");
    ifstream in ("castle.in");
    ofstream out ("castle.out");
    in >> M >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            in >> HOUSE[i][j];
//            cout << HOUSE[i][j] << "\n";
        }
    }
    int i = 0, j = 0, size = 0, maxSize = 0;
    while (i < N){
        if (ROOMS[i][j] == 0){
            room++;
            size = 0;
            setNeighbors(i, j, room, N, M, size);
        }
        if (size > maxSize){
            maxSize = size;
        }
        j++;
        if (j == M){
            j = 0;
            i++;
        }
    }
    out << room << "\n";
    out << maxSize << "\n";
    
    int newMax = maxSize, current, maxI = 0, maxJ = 0;
    string maxDir = "X";
    for (int j = 0; j < M; j++){
        for (int i = N - 1; i >= 0; i--){
            //north wall
            if (i - 1 >= 0 && HOUSE[i][j] & 0b10){
                HOUSE[i][j] ^= 0b10;
                HOUSE[i - 1][j] ^= 0b1000;
                current = calcRooms(N, M);
                HOUSE[i][j] ^= 0b10;
                HOUSE[i - 1][j] ^= 0b1000;
                
                if (current > newMax){
                    newMax = current;
                    maxI = i;
                    maxJ = j;
                    maxDir = "N";
                }
            }
            
            //east wall
            if (j + 1 < M && HOUSE[i][j] & 0b100){
                HOUSE[i][j] ^= 0b100;
                HOUSE[i][j + 1] ^= 0b1;
                current = calcRooms(N, M);
                HOUSE[i][j] ^= 0b100;
                HOUSE[i][j + 1] ^= 0b1;
                
                if (current > newMax){
                    newMax = current;
                    maxI = i;
                    maxJ = j;
                    maxDir = "E";
                }
            }
        }
    }
    out << newMax << "\n";
    out << maxI + 1 << " " << maxJ + 1 << " " << maxDir << "\n";
    return 0;
}

