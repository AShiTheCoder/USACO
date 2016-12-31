/*
 ID: ashilol1
 PROG: runround
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <array>
#define type    unsigned long
using namespace std;

bool runsaround(type num){
    type a = num;
    int d = 0;
    array<int, 9> digits;
    while (a > 0){
        d++;
        a /= 10;
    }
    a = num;
    for (int i = 0; i < d; i++){
        digits[d - i - 1] = a % 10;
        a /= 10;
    }
    for (int i = 0; i < d; i++){
        for (int j = i + 1; j < d; j++){
            if (digits[i] == digits[j]) return false;
        }
    }
    
    array<int, 9> visited = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int x = digits[0] % d;
    visited[x]++;
    for (int i = 0; i < d - 1; i++){
        x += digits[x];
        x %= d;
        visited[x]++;
    }
    for (int i = 0; i < d; i++){
        if (visited[i] != 1) return false;
    }
    return true;
}

int main() {
    type N;
    
//        ifstream in ("/Users/AShi/Documents/Repos/USACO/Runaround Numbers/runround.txt");
    ifstream in ("runround.in");
    ofstream out ("runround.out");
    in >> N;
    N++;
    in.close();
    
    while (!runsaround(N)){
        N++;
    }
    out << N << "\n";
    
    return 0;
}
