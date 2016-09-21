/*
 ID: ashilol1
 PROG: pprime
 LANG: C++
 */
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool isPrime(long num){
    int mx = sqrt(num) + 1;
    if (num % 2 == 0) return false;
    for(int i = 3; i < mx; i += 2){
        if(num % i == 0) return false;
    }
    return true;
}

int numDigits(int n){
    int d = 0;
    while (n > 0){
        d++;
        n /= 10;
    }
    return d;
}

void iterate(int level, int indices[], int LEVEL, bool odd, int lower, int upper, ofstream &out){
    if (level == 0){
        long x = 0;
        for (int i = 0; i < LEVEL; i++){
            if (odd){
                if (i == LEVEL - 1){
                    x += pow(10, i) * indices[1];
                } else {
                    x += (pow(10, i) + pow(10, 2 * (LEVEL - 1) - i)) * indices[LEVEL - i];
                }
            } else {
                x += (pow(10, i) + pow(10, 2 * LEVEL - 1 - i)) * indices[LEVEL - i];
            }
        }
        if (isPrime(x) && x >= lower && x <= upper){
            out << x << "\n";
        }
    } else {
        if (level == LEVEL){
            for (indices[level] = 1; indices[level] < 10; indices[level]++){
                iterate(level - 1, indices, LEVEL, odd, lower, upper, out);
            }
        } else {
            for (indices[level] = 0; indices[level] < 10; indices[level]++){
                iterate(level - 1, indices, LEVEL, odd, lower, upper, out);
            }
        }
    }
}

int main(){
    int a, b, c, d;
    
//        ifstream in ("/Users/AShi/Documents/Repos/USACO/Prime Palindromes/pprime.txt");
    ifstream in ("pprime.in");
    ofstream out ("pprime.out");
    in >> a >> b;
    in.close();
    c = numDigits(a);
    d = numDigits(b);
    int indices[10];
    
    for (int i = (c + 1)/2; i <= (d + 1)/2; i++){
        for (int j = 1; j <= 2; j++){
            memset(indices, 0, sizeof indices);
            iterate(i, indices, i, j % 2 == 1, a, b, out);
        }
    }
    out.close();
    
    return 0;
}
