/*
 ID: ashilol1
 PROG: cowtour
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define CODE_WORKS true
using namespace std;
ifstream in("cowtour.in");
ofstream out("cowtour.out");

int N;

struct Node{
    int x, y;
};
typedef vector<int> Vb;
typedef vector<vector<double> > Dg;
vector<Node> past;

double distan(int a, int b){
    return sqrt((past[b].x - past[a].x) * (past[b].x - past[a].x) + (past[b].y - past[a].y) * (past[b].y - past[a].y));
}

void path(vector<Vb> a, double (&dist)[150][150]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) dist[i][j] = 0;
            else if(a[i][j]) dist[i][j] = distan(i, j);
            else dist[i][j] = INFINITY;
        }
    }
    for(int k = 0; k < N; k++){
        for(int j = 0; j < N; j++){
            for(int i = 0; i < N; i++){
                if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

double longest(double (&paths)[150]){
    double big = 0;
    for(int i = 0; i < N; i++){
        if(paths[i] != INFINITY && paths[i] > big) big = paths[i];
    }
    return big;
}

int main(){
    int i, j, k, l, x, y;
    string row;
    in >> N;
    past.resize(N);
    for(i = 0; i < N; i++) in >> past[i].x >> past[i].y;
    vector<Vb> a(N, Vb(N)); //Adjacency matrix
    Vb v(N); //Visited matrix for flood fill
    for(i = 0; i < N; i++){
        in >> row;
        for(j = 0; j < N; j++){
            if(row[j] == '0') a[i][j] = 0;
            else a[i][j] = 1;
        }
        v[i] = 0; //Setting all pastures as unvisited
    }
    double dists[150][150];
    path(a, dists);
    double smallest = INFINITY;
    for(k = 0; k < N; k++){
        for(l = 0; l < N; l++){
            if(k == l || dists[k][l] != INFINITY) continue;
            smallest = min(smallest, longest(dists[k]) + distan(k, l) + longest(dists[l]));
        }
    }
    for(k = 0; k < N; k++){
        smallest = max(smallest, longest(dists[k]));
    }
    FILE * output;
    output = fopen("cowtour.out", "w");
    fprintf(output, "%.6lf\n", smallest);
    return 0;
}
//#include <iostream>
//#include <fstream>
//#include <queue>
//#include <vector>
//#include <cmath>
//#include <cassert>
//#include <iomanip>
//#define NDEBUG
//using namespace std;
//int coord[150][2];
//int connections[150][150];
//long double distances[150][150];
//
//long double dist(int a, int b){
////    cout << sqrt(pow(coord[a][0] - coord[b][0], 2) + pow(coord[a][1] - coord[b][1], 2)) << "\n";
//    return sqrt(pow(coord[a][0] - coord[b][0], 2) + pow(coord[a][1] - coord[b][1], 2));
//}
//
//long double diam(vector<int> field){
//    for (int i = 0; i < field.size(); i++){
//        for (int j = 0; j < field.size(); j++){
//            if (connections[field[i]][field[j]]) {
//                distances[i][j] = dist(field[i], field[j]);
////                cout << distances[i][j] << "\n";
//            }
//            else distances[i][j] = 100000000;
//        }
//    }
//    for (int k = 0; k < field.size(); k++){
//        for (int j = 0; j < field.size(); j++){
//            for (int i = 0; i < field.size(); i++){
//                if (field[i] != field[j] && distances[field[i]][field[k]] + distances[field[k]][field[j]] < distances[field[i]][field[j]]){
//                    distances[field[i]][field[j]] = distances[field[i]][field[k]] + distances[field[k]][field[j]];
//                    
//                }
////                cout << "distance from " << field[i] << " to " << field[j] << " is now " << distances[field[i]][field[j]] << "\n";
//            }
//        }
//    }
//    long double longest = 0;
//    for (int i = 0; i < field.size(); i++){
//        for (int j = 0; j < field.size(); j++){
//            if (distances[field[i]][field[j]] != 100000000 && distances[field[i]][field[j]] > longest){
//                longest = distances[field[i]][field[j]];
//            }
//        }
//    }
////    cout << longest << "\n";
//    return longest;
//}
//
//int main() {
//    vector<vector<int>> fields;
//    bool visited[150];
//    int N;
//    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Cow Tours/cowtour.txt");
////    ifstream in ("cowtour.in");
//    ofstream out ("cowtour.out");
//    in >> N;
//    for (int i = 0; i < N; i++){
//        in >> coord[i][0] >> coord[i][1];
//        visited[i] = false;
////        cout << coord[i][0] << ", " << coord[i][1] << "\n";
//    }
//    in.ignore();
//    char c;
//    for (int i = 0; i < N; i++){
//        for (int j = 0; j < N; j++){
//            in.get(c);
//            connections[i][j] = c - '0';
////            cout << connections[i][j];
//        }
//        in.ignore();
////        cout << "\n";
//    }
//    
//    //find fields
//    int x, numFields = 0;
//    for (int i = 0; i < N; i++){
//        if (!visited[i]){
//            visited[i] = true;
//            queue<int> found, assigned;
//            vector<int> result;
//            found.push(i);
//            while (!found.empty()){
//                x = found.front();
//                assigned.push(x);
//                found.pop();
//                for (int j = 0; j < N; j++){
//                    if (connections[x][j] && !visited[j]){
//                        visited[j] = true;
//                        found.push(j);
//                    }
//                }
//            }
//            while (!assigned.empty()){
//                result.push_back(assigned.front());
//                assigned.pop();
//            }
//            fields.push_back(result);
//            numFields++;
//        }
//    }
//    
////    for (int i = 0; i < numFields; i++){
////        for (int j = 0; j < fields[i].size(); j++){
////            cout << fields[i][j] << " ";
////        }
////        cout << "\n";
////    }
////    
//    vector<int> newField;
//    //for each field pair, try placing all connections
//    long double shortest = 100000000;
//    for (int i = 0; i < numFields; i++){
//        for (int j = i + 1; j < numFields; j++){
//            for (int k = 0; k < fields[i].size(); k++){
//                newField.push_back(fields[i][k]);
//            }
//            for (int k = 0; k < fields[j].size(); k++){
//                newField.push_back(fields[j][k]);
//            }
//            for (int k = 0; k < fields[i].size(); k++){
//                for (int m = 0; m < fields[j].size(); m++){
//                    //try placing a connection between the kth pasture of the ith field and the mth pasture of the jth field
//                    assert(connections[fields[i][k]][fields[j][m]] == 0);
//                    connections[fields[i][k]][fields[j][m]] = 1;
//                    connections[fields[j][m]][fields[i][k]] = 1;
////                    cout << fields[i][k] << " and " << fields[j][m] << " are now connected\n";
//                    long double d = diam(newField);
//                    if (d < shortest){
//                        shortest = d;
////                        cout << "The distance between " << fields[i][k] << " and " << fields[j][m] << " is the shortest so far\n";
//                    }
//                    connections[fields[i][k]][fields[j][m]] = 0;
//                    connections[fields[j][m]][fields[i][k]] = 0;
//                }
//            }
//        }
//    }
//    int y = 0;
//    while (shortest >= 1){
//        shortest--;
//        y++;
//    }
//    string Y = to_string(shortest);
//    cout << y << Y.substr(1) << "\n";
//    return 0;
//}
