/*
 ID: ashilol1
 PROG: ride
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    char comet[8], group[8];
    
    fin >> comet >> group;
    fin.close();
    
    int c = 1, g = 1;
    for (int i = 0; i < 6; i++){
        if (isalpha(comet[i])){
            c *= comet[i] - 'A' + 1;
            c %= 47;
            //cout << c << " ";
        }
        if (isalpha(group[i])){
            g *= group[i] - 'A' + 1;
            g %= 47;
            //cout << g << "\n";
        }
    }
    
    if (g == c){
        fout << "GO\n";
    } else {
        fout << "STAY\n";
    }
    fout.close();
    return 0;
}
