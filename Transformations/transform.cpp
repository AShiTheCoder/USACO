/*
ID: ashilol1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool transform(int t, int N, char** first, char** last){
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, beforeX, beforeY, afterX, afterY;
    bool works = true;
    switch (t) {
        case 1:
            x1 = 0, y1 = 1;
            x2 = -1, y2 = 0;
            break;
        case 2:
            x1 = -1, y1 = 0;
            x2 = 0, y2 = -1;
            break;
        case 3:
            x1 = 0, y1 = -1;
            x2 = 1, y2 = 0;
            break;
        case 4:
            x1 = -1, y1 = 0;
            x2 = 0, y2 = 1;
            break;
        case 51:
            x1 = 0, y1 = 1;
            x2 = 1, y2 = 0;
            break;
        case 52:
            x1 = 1, y1 = 0;
            x2 = 0, y2 = -1;
            break;
        case 53:
            x1 = 0, y1 = -1;
            x2 = -1, y2 = 0;
            break;
        case 6:
            x1 = 1, y1 = 0;
            x2 = 0, y2 = 1;
            break;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (N % 2 == 1){
                beforeX = j - N/2;
                beforeY = -1 * i + N/2;
                afterX = x1 * beforeX + y1 * beforeY + N/2;
                afterY = -1 * (x2 * beforeX + y2 * beforeY) + N/2;
                
                if (first[-1 * beforeY + N/2][beforeX + N/2] != last[afterY][afterX]){
                    works = false;
                    j = N;
                    i = N;
                }
            } else {
                if (j < N/2) {
                    beforeX = j - N/2;
                } else {
                    beforeX = j - N/2 + 1;
                }
                if (i < N/2){
                    beforeY = -1 * i + N/2;
                } else {
                    beforeY = -1 * i + N/2 - 1;
                }
                
                afterX = x1 * beforeX + y1 * beforeY;
                afterY = x2 * beforeX + y2 * beforeY;
                
                if (afterX < 0) {
                    afterX = afterX + N/2;
                } else {
                    afterX = afterX + N/2 - 1;
                }
                if (afterY < 0){
                    afterY = -1 * afterY + N/2 - 1;
                } else {
                    afterY = -1 * afterY + N/2;
                }
                if (j < N/2) {
                    beforeX += N/2;
                } else {
                    beforeX += N/2 - 1;
                }
                if (i < N/2){
                    beforeY = -1 * (beforeY - N/2);
                } else {
                    beforeY = -1 * (beforeY - N/2 + 1);
                }
                
                if (first[beforeY][beforeX] != last[afterY][afterX]){
                    works = false;
                    cout << "Case " << t << " fails because (" << -1 * beforeY + N/2 << ", " << beforeX + N/2 << ") != (" << afterY << ", " << afterX << ")!\n";
                    j = N;
                    i = N;
                }
            }
        }
    }
    return works;
}

int main(){
    int N, solution = 0;
    string s;
    bool good = false;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Transformations/transform.in.txt");
//    ofstream out ("/Users/AShi/Documents/Repos/USACO/Transformations/transform.out.txt");
    ifstream in ("transform.in");
    ofstream out ("transform.out");
    in >> N;
    char** before = new char*[N];
    char** after = new char*[N];
    in.ignore();
    
    for (int i = 0; i < N; i++){
        before[i] = new char[N];
        after[i] = new char[N];
    }
    for (int i = 0; i < N; i++){
        getline(in, s);
        for (int j = 0; j < N; j++){
            before[i][j] = s[j];
        }
    }
    for (int i = 0; i < N; i++){
        getline(in, s);
        for (int j = 0; j < N; j++){
            after[i][j] = s[j];
        }
    }
    in.close();
    
    if (transform(6, N, before, after)){
        solution = 6;
        good = true;
    }
    for (int i = 0; i < 3; i++){
        if (transform(i + 51, N, before, after)){
            solution = 5;
            good = true;
        }
    }
    for (int i = 4; i > 0; i--){
        if (transform(i, N, before, after)){
            solution = i;
            good = true;
        }
    }
    if (!good){
        solution = 7;
    }
    out << solution << "\n";
    out.close();
    return 0;
}