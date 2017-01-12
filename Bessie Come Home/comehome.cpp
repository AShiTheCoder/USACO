/*
 ID: ashilol1
 PROG: comehome
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int convert(char c){
    if (c < 91) return c - 65;
    else return c - 71;
}
char convertback(int c){
    if (c < 26) return c + 65;
    else return c + 71;
}

int main() {
    int paths[52][52], dist[52][2];
    //dist[i][0]: if i has been visited, dist[i][1]: shortest dist
    int N;
    for (int i = 0; i < 52; i++){
        dist[i][0] = 0;
        dist[i][1] = INT_MAX;
        for (int j = 0; j < 52; j++){
            paths[i][j] = -1;
        }
    }
    dist[25][0] = 1;
    dist[25][1] = 0;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Bessie Come Home/comehome.txt");
    ifstream in ("comehome.in");
    ofstream out ("comehome.out");
    in >> N;
    char A, B;
    int a, b, x;
    for (int i = 0; i < N; i++){
        in >> A >> B >> x;
        a = convert(A); b = convert(B);
        if (paths[a][b] == -1 || x < paths[a][b]){
            paths[a][b] = x;
            paths[b][a] = x;
        }
    }
    int closest = INT_MAX, closestI = -1, currNode = 25;
    for (int i = 0; i < 52; i++){
        if (!dist[i][0]){
            if (paths[currNode][i] != -1 && dist[currNode][1] + paths[currNode][i] < dist[i][1]){
                dist[i][1] = dist[currNode][1] + paths[currNode][i];
            }
            if (dist[i][1] < closest){
                closestI = i, closest = dist[i][1];
            }
        }
    }
    while (closestI != -1){
        currNode = closestI;
        dist[currNode][0] = 1;
        
        closest = INT_MAX, closestI = -1;
        for (int i = 0; i < 52; i++){
            if (!dist[i][0]){
                //update shortest distances of adjacent nodes
                if (paths[currNode][i] != -1 && dist[currNode][1] + paths[currNode][i] < dist[i][1]){
                    dist[i][1] = dist[currNode][1] + paths[currNode][i];
//                    if (i == 17) cout << "R is now " << dist[i][1] << " away via " << convertback(currNode) << "\n";;
                }
                //find the unvisited node closest to source, whether adjacent or not
                if (dist[i][1] < closest){
                    closestI = i, closest = dist[i][1];
                }
            }
        }
    }
    closest = INT_MAX, closestI = -1;
    for (int i = 0; i < 25; i++){
        if (dist[i][1] < closest){
            closest = dist[i][1];
            closestI = i;
        }
//        cout << char(i + 65) << " " << dist[i][1] << "\n";
    }
    out << char(closestI + 65) << " " << closest << "\n";
    
    return 0;
}
