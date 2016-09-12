/*
 ID: ashilol1
 PROG: ariprog
 LANG: C++
 */
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string result = "";
bool biSquares[125001];

void init(int bound, bool data[]){
    for (int i = 0; i <= bound; i++){
        for (int j = i; j <= bound; j++){
            data[i * i + j * j] = true;
        }
    }
    cout << "done\n";
}

int main(){
    int length, biBound;
    bool found = false, good = false;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/ariprog/ariprog.txt");
        ifstream in ("ariprog.in");
        ofstream out ("ariprog.out");
    in >> length >> biBound;
    in.close();
    init(biBound, biSquares);
    
    for (int i = 1; i <= 2 * biBound * biBound/(length - 1); i++){
        for (int j = 0; j <= 2 * biBound * biBound - length; j++){
            if (!biSquares[j] || j + (length - 1) * i > 2 * biBound * biBound){ continue; }
            else {
                for (int k = 0; k < length; k++){
                    good = true;
                    if (!biSquares[j + k * i]){
                        k = length;
                        good = false;
                    }
                }
                if (good){
                    out << j << " " << i << "\n";
                    found = true;
                }
            }
        }
    }
    
    if (!found){
        out << "NONE\n";
    }
    
    return 0;
}