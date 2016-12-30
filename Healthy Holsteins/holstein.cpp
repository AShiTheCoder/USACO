/*
 ID: ashilol1
 PROG: holstein
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <queue>
#include <array>

using namespace std;

int main() {
    queue<array<int, 15>> data;
    int feedData[15][25], v[25], V, G;
    
//    ifstream in("/Users/AShi/Documents/Repos/USACO/Healthy Holsteins/holstein.txt");
        ifstream in("holstein.in");
    ofstream out("holstein.out");
    in >> V;
    for (int i = 0; i < V; i++){
        in >> v[i];
    }
    in >> G;
    for (int i = 0; i < G; i++){
        for (int j = 0; j < V; j++){
            in >> feedData[i][j];
        }
    }
    
    array<int, 15> a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, best;
    bool works = true, found = false;
    int total = 0;
    data.push(a);
    while (!data.empty() && !found){
        works = true;
        array<int, 15> x = data.front();
        data.pop();
        
        for (int i = 0; i < V; i++){
            if (works){
                total = 0;
                for (int j = 0; j < G; j++){
                    total += (feedData[j][i] * x[j]);
                }
                
                //                cout << "Total of " << total << " compared to " << v[i] << " needed of vitamin " << i + 1 << "\n";
                
                if (total < v[i]){
                    works = false;
                    
                    //                    for (int i = 0; i < G; i++){
                    //                        cout << x[i] << " ";
                    //                    }
                    //                    cout << "doesnt work\n";
                }
            }
        }
        
        if (works){
            found = true;
            best = x;
        } else {
            int c = G - 1;
            while (c >= 0 && x[c] == 0) c--;
            for (int i = c + 1; i < G; i++){
                x[i] = 1;
                data.push(x);
                x[i] = 0;
            }
        }
    }
    
    int count = 0;
    
    for (int i = 0; i < G; i++){
        count += best[i];
    }
    out << count;
    for (int i = 0; i < G; i++){
        if (best[i] != 0){
            out << " " << i + 1;
        }
    }
    out << "\n";
    
    return 0;
}
