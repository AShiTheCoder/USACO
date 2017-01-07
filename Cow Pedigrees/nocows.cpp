/*
 ID: ashilol1
 PROG: nocows
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int data[100][99]; //data[n][k] for tree of n reduced nodes and depth <= k + 1

int numTrees(int n, int k){
    if (n < 0 || k < 0) return 0;
    if (data[n][k] != -1) return data[n][k];
    else {
        int sum = 0;
        for (int i = 0; i <= n; i++){
            sum += numTrees(i, k - 1) * numTrees(n - i - 1, k - 1);
        }
        data[n][k] = sum % 9901;
        return data[n][k];
    }
}

int main() {
    int size, depth;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (i == 0) data[i][j] = 1;
            else data[i][j] = -1;
        }
    }
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Cow Pedigrees/nocows.txt");
    ifstream in ("nocows.in");
    ofstream out ("nocows.out");
    in >> size >> depth;
    depth--;
    in.close();
    
    if (size % 2 == 0) out << 0 << "\n";
    else {
        size /= 2;
        int x = numTrees(size, depth) - numTrees(size, depth - 1);
        if (x < 0) x += 9901;
        out << x << "\n";
    }
    
    return 0;
}
