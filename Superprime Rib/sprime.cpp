/*
ID: ashilol1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isPrime(int num){
    int mx = sqrt(num) + 1;
    if (num % 2 == 0) return false;
    for(int i = 3; i < mx; i += 2){
        if(num % i == 0) return false;
    }
    return true;
}

void iterate(int current, int count, int max, ofstream &o){
    if (count == max){
        o << current << "\n";
    } else {
        for (int i = 0; i < 10; i++){
            if (isPrime(current * 10 + i)){
                iterate(current * 10 + i, count + 1, max, o);
            }
        }
    }
}

int main(){
    int primes[4] = {2, 3, 5, 7}, len = 0;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Superprime Rib/sprime.txt");
    ifstream in ("sprime.in");
    ofstream out ("sprime.out");
    in >> len;
    in.close();
    
    for (int i = 0; i < 4; i++){
        iterate(primes[i], 1, len, out);
    }
    out.close();
    
    return 0;
}
