/*
 ID: ashilol1
 PROG: namenum
 LANG: C++
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int numDigits = 0;
    char** pad = new char*[10];
    for (int i = 0; i < 10; i++){
        pad[i] = new char[3];
    }
    pad[2][0] = 'A';
    pad[2][1] = 'B';
    pad[2][2] = 'C';
    pad[3][0] = 'D';
    pad[3][1] = 'E';
    pad[3][2] = 'F';
    pad[4][0] = 'G';
    pad[4][1] = 'H';
    pad[4][2] = 'I';
    pad[5][0] = 'J';
    pad[5][1] = 'K';
    pad[5][2] = 'L';
    pad[6][0] = 'M';
    pad[6][1] = 'N';
    pad[6][2] = 'O';
    pad[7][0] = 'P';
    pad[7][1] = 'R';
    pad[7][2] = 'S';
    pad[8][0] = 'T';
    pad[8][1] = 'U';
    pad[8][2] = 'V';
    pad[9][0] = 'W';
    pad[9][1] = 'X';
    pad[9][2] = 'Y';
    
//    ifstream dict ("/Users/AShi/Documents/Repos/USACO/namenum/dict.txt");
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/namenum/namenum.in.txt");
//    ofstream out ("/Users/AShi/Documents/Repos/USACO/namenum/namenum.out.txt");
            ifstream in ("namenum.in");
            ofstream out ("namenum.out");
            ifstream dict ("dict.txt");
    string d;
    getline(in, d);
    in.close();
    
    numDigits = d.length();
    int digits[numDigits];
    for (int i = 0; i < numDigits; i++){
        digits[i] = d[i] - '0';
    }
    
    string names[5000], name;
    int count = 0;
    while (!dict.eof()){
        getline(dict, name);
        if (name.length() == numDigits){
            names[count] = name;
            count++;
        }
    }
    dict.close();
    
    bool good, found = false;
    for (int i = 0; i < count; i++){
        good = true;
        for (int j = 0; j < numDigits; j++){
            if (!(names[i][j] == pad[digits[j]][0] ||
                  names[i][j] == pad[digits[j]][1] ||
                  names[i][j] == pad[digits[j]][2])){
                good = false;
                j = numDigits;
            }
        }
        if (good){
            out << names[i] << "\n";
            found = true;
        }
    }
    if (!found){
        out << "NONE\n";
    }
    
    return 0;
}