/*
 ID: ashilol1
 PROG: concom
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 100
using namespace std;

int main() {
    int controls[100][100]; //company i controls [i][j] of company j
    int percents[100];
    int comp1, comp2, perc;
    for (int i = 0; i < N; i++){
        percents[i] = 0;
        for (int j = 0; j < N; j++){
            if (i == j) controls[i][j] = 50;
            else controls[i][j] = 0;
        }
    }
    vector<int> owners;
    owners.reserve(100);
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Controlling Companies/concom.txt");
    ifstream in ("concom.in");
    ofstream out ("concom.out");
    in >> comp1;
    in >> comp1 >> comp2 >> perc;
    while (!in.eof()){
        controls[comp1 - 1][comp2 - 1] = perc;
        if (find(owners.begin(), owners.end(), comp1 - 1) == owners.end()){
            owners.push_back(comp1 - 1);
        }
        in >> comp1 >> comp2 >> perc;
    }
    sort(owners.begin(), owners.end());
    int n = int(owners.size());
    queue<int> found;
    vector<int> owned;
    owned.reserve(100);
    for (int i = 0; i < n; i++){
        owned.clear();
        for (int j = 0; j < N; j++){
            percents[j] = controls[owners[i]][j];
        }
        for (int j = 0; j < N; j++){
            if (owners[i] != j && percents[j] >= 50){
                found.push(j);
            }
        }
        
        while (!found.empty()){
            for (int j = 0; j < N; j++){
                if (percents[j] >= 50) percents[j] = 0;
            }
            int s = int(found.size());
            for (int j = 0; j < s; j++){
                int x = found.front();
                for (int k = 0; k < N; k++){
                    if (x != k) percents[k] += controls[x][k];
                }
                found.pop();
                owned.push_back(x);
            }
            for (int j = 0; j < N; j++){
                if (owners[i] != j && percents[j] >= 50){
                    found.push(j);
                }
            }
        }
        sort(owned.begin(), owned.end());
        for (int j = 0; j < owned.size(); j++){
            out << owners[i] + 1 << " " << owned[j] + 1 << "\n";
        }
    }
    
    return 0;
}
