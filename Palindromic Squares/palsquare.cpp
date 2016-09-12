/*
ID: ashilol1
PROG: palsquare
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string toString(int val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}
string baseN(int n, int base){
    string baseRep = "";
    int x = n;
    while (x > 0){
        if (x % base > 9){
            char z = x % base + 55;
            baseRep = z + baseRep;
        } else {
            baseRep = toString(x % base) + baseRep;
        }
        x /= base;
    }
    //cout << n << " is " << baseRep << "\n";
    return baseRep;
}
bool isPalindrome(int n, int base){
    string baseRep = baseN(n, base);
    //cout << baseRep << "\n";
    for (int i = 0; i < baseRep.length()/2; i++){
        if (baseRep[i] != baseRep[baseRep.length() - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int base, x;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Palindromic Squares/palsquare.in.txt");
    ifstream in ("palsquare.in");
    ofstream out ("palsquare.out");
    in >> base;
    in.close();
    
    for (int i = 1; i < 301; i++){
        x = i * i;
        if (isPalindrome(x, base)){
            out << baseN(i, base) << " " << baseN(i * i, base) << "\n";
        }
    }
    out.close();
    
    return 0;
}