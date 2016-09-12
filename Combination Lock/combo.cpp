/*
ID: ashilol1
PROG: combo
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

struct Combo{
    Combo(){}
    int code1, code2, code3, lock;
    void set(int a, int b, int c, int l){
        code1 = a;
        code2 = b;
        code3 = c;
        lock = l;
    }
    bool within(int a, int b, int c){
        return ((abs(code1 - a) <= 2 || lock - abs(code1 - a) <= 2) &&
                (abs(code2 - b) <= 2 || lock - abs(code2 - b) <= 2) &&
                (abs(code3 - c) <= 2 || lock - abs(code3 - c) <= 2));
    }
};

int main(){
    int lockSize, combo1[3], combo2[3], numCombos = 0, width, total = 0;
    Combo combos[125];
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/combo/combo.txt");
    ifstream in ("combo.in");
    ofstream out ("combo.out");
    
    in >> lockSize;
    in.ignore();
    for (int i = 0; i < 3; i++){
        in >> combo1[i];
    }
    in.ignore();
    for (int i = 0; i < 3; i++){
        in >> combo2[i];
    }
    in.close();
    
    if (lockSize < 5){
        width = lockSize;
    } else {
        width = 5;
    }
    
    for (int i = 0; i < width; i++){
        for (int j = 0; j < width; j++){
            for (int k = 0; k < width; k++){
                combos[numCombos].set((combo1[0] + i - 2 + lockSize) % lockSize,
                                  (combo1[1] + j - 2 + lockSize) % lockSize,
                                  (combo1[2] + k - 2 + lockSize) % lockSize,lockSize);
                numCombos++;
            }
        }
    }
    total = numCombos;
    
    for (int i = 0; i < numCombos; i++){
        if (!combos[i].within(combo2[0], combo2[1], combo2[2])){
            total++;
        }
    }
    
    out << total << "\n";
    
    return 0;
}