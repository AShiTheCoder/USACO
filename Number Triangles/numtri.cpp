/*
ID: ashilol1
PROG: numtri
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string.h>
#define MAX 1001
using namespace std;
int numbers[MAX][MAX], bestValues[MAX][MAX];

int max (int a, int b){
    return a > b ? a : b;
}

int search(int row, int pos, int end){
    if (bestValues[row][pos] != -1){
        return bestValues[row][pos];
    } else if (row <= end){
        return bestValues[row][pos] = numbers[row][pos] + max(search(row + 1, pos, end), search(row + 1, pos + 1, end));
    } else return 0;
}

int main(){
    int numRows;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Number Triangles/numtri.txt");
    ifstream in ("numtri.in");
    ofstream out ("numtri.out");
    in >> numRows;
    in.ignore();
    for (int i = 1; i <= numRows; i++){
        for (int j = 1; j <= i; j++){
            in >> numbers[i][j];
        }
        in.ignore();
    }
    
    memset(bestValues, -1, sizeof bestValues);
    out << search(1, 1, numRows) << "\n";
    in.close();
    out.close();
    return 0;
}
