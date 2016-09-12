/*
 ID: ashilol1
 TASK: beads
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string beads, noWhite;
    int n, j, i = 0, count = 0, max = 0, switches = 0, next = 0, x;
    char currColor;
    
    ifstream in ("beads.in");
    ofstream out ("beads.out");
    
    in >> n;
    in.ignore();
    getline(in, beads);
    in.close();
    
    while (i < n){
        count = 0;
        switches = 0;
        while (beads[(i + count) % n] == 'w' && count < n){
            count++;
        }
        currColor = beads[(i + count) % n];
        j = (i + count) % n;
        while (switches < 2 && count < n){
            if (beads[j] == currColor || beads[j] == 'w') {
                count++;
                j++;
                j %= n;
            } else {
                switches++;
                if (switches == 1){
                    x = 0;
                    while (beads[(j - (x + 1) + n) % n] == 'w' && count < n){
                        x++;
                    }
                    next = j - x;
                }
                currColor = beads[j];
            }
        }
        if (count > max){
            max = count;
        }
        if (next > i){
            i = next;
        } else break;
    }
    out << max << "\n";
    return 0;
}