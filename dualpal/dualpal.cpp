/*
 ID: ashilol1
 PROG: dualpal
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
    int numQueries, minX, counter = 0, goodCount = 0;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/dualpal/dualpal.in.txt");
        ifstream in ("dualpal.in");
        ofstream out ("dualpal.out");
    in >> numQueries >> minX;
    in.close();
    
    int i = minX + 1;
    while (counter < numQueries){
        goodCount = 0;
        for (int j = 2; j < 11; j++){
            if (isPalindrome(i, j)){
                goodCount++;
            }
        }
        if (goodCount > 1){
            out << i << "\n";
            counter++;
        }
        i++;
    }
    
    out.close();
    
    return 0;
}