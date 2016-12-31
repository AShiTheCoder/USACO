/*
 ID: ashilol1
 PROG: preface
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int main() {
    int N;
    array<array<int, 7>, 3501> counts;
    //I = 0(1), V = 1(5), X = 2(10), L = 3(50), C = 4(100), D = 5(500), M = 6(1000)
    array<char, 7> letters = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    
//    ifstream in("/Users/AShi/Documents/Repos/USACO/Preface Numbering/preface.txt");
    ifstream in("preface.in");
    ofstream out("preface.out");
    in >> N;
    in.close();
    
    counts[0] = {0, 0, 0, 0, 0, 0, 0};
    counts[1] = {1, 0, 0, 0, 0, 0, 0};
    counts[2] = {2, 0, 0, 0, 0, 0, 0};
    counts[3] = {3, 0, 0, 0, 0, 0, 0};
    counts[4] = {1, 1, 0, 0, 0, 0, 0};
    counts[5] = {0, 1, 0, 0, 0, 0, 0};
    counts[6] = {1, 1, 0, 0, 0, 0, 0};
    counts[7] = {2, 1, 0, 0, 0, 0, 0};
    counts[8] = {3, 1, 0, 0, 0, 0, 0};
    counts[9] = {1, 0, 1, 0, 0, 0, 0};
    for (int i = 10; i <= N; i++){
        array<int, 7> x;
        if (i/1000 > 0){
            x = counts[i % 1000];
            x[6] += i/1000;
        } else if (i >= 900){
            x = counts[i - 900];
            x[4]++, x[6]++;
        } else if (i >= 500){
            x = counts[i - 500];
            x[5]++;
        } else if (i >= 400){
            x = counts[i - 400];
            x[4]++, x[5]++;
        } else if (i/100 > 0){
            x = counts[i % 100];
            x[4] += i/100;
        } else if (i >= 90){
            x = counts[i - 90];
            x[2]++, x[4]++;
        } else if (i >= 50){
            x = counts[i - 50];
            x[3]++;
        } else if (i >= 40){
            x = counts[i - 40];
            x[2]++, x[3]++;
        } else {
            x = counts[i % 10];
            x[2] += i/10;
        }
        counts[i] = x;
    }
    array<int, 7> totals = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 1; i <= N; i++){
        for (int j = 0; j < 7; j++){
            totals[j] += counts[i][j];
        }
    }
    for (int i = 0; i < 7; i++){
        if (totals[i] != 0){
            out << letters[i] << " " << totals[i] << "\n";
        }
    }
    
    return 0;
}
