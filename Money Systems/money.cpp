/*
 ID: ashilol1
 PROG: money
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
long long ways[10001];

int main() {
    int numCoins, amt;
    vector<int> coins;
    coins.reserve(25);
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Money Systems/money.txt");
    ifstream in ("money.in");
    ofstream out ("money.out");
    in >> numCoins >> amt;
    int next;
    for (int i = 0; i < numCoins; i++){
        in >> next;
        coins.push_back(next);
    }
    sort(coins.begin(), coins.end());
    ways[0] = 1;
    for (int i = 0; i < numCoins; i++){
        for (int j = coins[i]; j <= amt; j++){
            ways[j] += ways[j - coins[i]];
        }
    }
    out << ways[amt] << "\n";
    
    return 0;
}
