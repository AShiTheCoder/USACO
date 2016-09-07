/*
 ID: ashilol1
 PROG: milk2
 LANG: C++
 */

#include <fstream>
#include <iostream>

using namespace std;

int main(){
    int no = 0, yes = 0, maxNo = 0, maxYes = 0, endMax = 0, startMax = 1000000, num, start, end, past;
    int time[1000000];
//    int x = 0;
//    bool fail = false;
    
    ifstream in ("milk2.in");
    ofstream out ("milk2.out");
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/milk2/milk2.in.txt");
//    ofstream out ("/Users/AShi/Documents/Repos/USACO/milk2/milk2.out.txt");

    
    in >> num;
    //int starts[num], ends[num];
    in.ignore();
    for (int i = 0; i < 1000000; i++){
        time[i] = 0;
    }
    for (int i = 0; i < num; i++){
        in >> start >> end;
        if (end > endMax) {
            endMax = end;
        }
        if (start < startMax) {
            startMax = start;
        }
        in.ignore();
        for (int j = start; j < end; j++){
            time[j] = 1;
        }
    }
    in.close();
    
    past = time[startMax];
    yes = 0;
    no = 0;
    for (int i = startMax; i < endMax; i++){
        if (i == endMax - 1){
            if (no + 1 > maxNo && time[i] == 0){
                maxNo = no + 1;
            }
            if (yes + 1 > maxYes && time[i] == 1){
                maxYes = yes + 1;
            }
        } else if (time[i] == past){
            if (time[i] == 0){
                no++;
            } else yes++;
        } else if (past == 0){
            if (no > maxNo){
                maxNo = no;
            }
            no = 0;
            yes = 1;
        } else {
            if (yes > maxYes){
                maxYes = yes;
            }
            yes = 0;
            no = 1;
        }
        past = time[i];
    }
//    for (int i = startMax; i < endMax; i++){
//        cout << i << " " << time[i] << "\n";
//    }
//    cout << "\n";
    out << maxYes << " " << maxNo << "\n";
    out.close();
    return 0;
}