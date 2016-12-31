/*
 ID: ashilol1
 PROG: subset
 LANG: C++11
 */
#include <iostream>
#include <fstream>
using namespace std;
long ways[391][40];

unsigned long numWays(long sum, long k){
    if (sum < 0 || k < 0) return 0;
    if (ways[sum][k] != -1) return ways[sum][k];
    else{
        ways[sum][k] = numWays(sum, k - 1) + numWays(sum - k, k - 1);
        return ways[sum][k];
    }
}

int main() {
    long N, sum;
    for (long i = 0; i < 391; i++){
        for (long j = 0; j < 40; j++){
            ways[i][j] = -1;
        }
    }
    ways[0][0] = 1;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Subset Sums/subset.txt");
    ifstream in ("subset.in");
    ofstream out ("subset.out");
    in >> N;
    in.close();
    
    if (((N + 1) * N) % 4 != 0){
        out << 0 << "\n";
        return 0;
    }
    
    sum = (N + 1) * N / 4;
    out << numWays(sum, N)/2 << "\n";
    
    return 0;
}
