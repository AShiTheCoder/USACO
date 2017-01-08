/*
 ID: ashilol1
 PROG: maze1
 LANG: C++11
 */
#include <iostream>
#include <fstream>
using namespace std;
char maze[201][77];
int dist[100][38];
//   0 1 2 3 4 5 6 7 8 9 10
// 0 + - + - + - + - + - +
// 1 |0,0 0,1 0,2 0,3 0,4|
// 2 + - +   + - +   +   +
// 3 |1,0 1,1 1,2|1,3|1,4|
// 4 +   + - + - +   +   +
// 5 |2,0|2,1 2,2 2,3|2,4
// 6 + - +   + - + - + - +

void fill(int x, int y, int d){
    if (dist[x][y] == -1 || dist[x][y] > d) {
        dist[x][y] = d;
        if (maze[2 * x + 1][2 * y] == ' '){
            fill(x, y - 1, d + 1);
        }
        if (maze[2 * x + 1][2 * (y + 1)] == ' '){
            fill(x, y + 1, d + 1);
        }
        if (maze[2 * x][2 * y + 1] == ' '){
            fill(x - 1, y, d + 1);
        }
        if (maze[2 * (x + 1)][2 * y + 1] == ' '){
            fill(x + 1, y, d + 1);
        }
    }
}

int main() {
    int H, W, x = -1, y = -1;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 38; j++){
            dist[i][j] = -1;
        }
    }
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Overfencing/maze1.txt");
    ifstream in ("maze1.in");
    ofstream out ("maze1.out");
    in >> W >> H;
    in.ignore();
//    in >> noskipws;
    char c = ' ';
    for (int i = 0; i < 2 * H + 1; i++){
        for (int j = 0; j < 2 * W + 1; j++){
            in.get(c);
            if (c != '\n') {
                maze[i][j] = c;
            } else {
                maze[i][j] = ' ';
                in.unget();
            }
            cout << maze[i][j];
        }
//        in.get(c);
//        while (c != '\n') in.get(c);
        in.ignore();
        cout << "\n";
    }
    
//    for (int i = 0; i < 2 * H + 1; i++){
//        for (int j = 0; j < 2 * W + 1; j++){
//            cout << maze[i][j];
//        }
//        cout << "\n";
//    }
    
    for (int i = 0; i < 2 * H + 1; i++){
        for (int j = 0; j < 2 * W + 1; j++){
//            cout << maze[i][j];
            x = -1;
            if (i == 0 && maze[i][j] == ' '){
                x = i, y = j/2;
            } else if (i == 2 * H && maze[i][j] == ' '){
                x = (i - 1)/2, y = j/2;
            } else if (j == 0 && maze[i][j] == ' '){
                x = i/2, y = j;
            } else if (j == 2 * W && maze[i][j] == ' '){
                x = i/2, y = (j - 1)/2;
            }
            if (x != -1){
//                cout << x << ", " << y << " is an exit\n";
                fill(x, y, 1);
            }
        }
//        cout << "\n";
    }
    int max = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (dist[i][j] > max) max = dist[i][j];
        }
    }
    out << max << "\n";
    
    return 0;
}
