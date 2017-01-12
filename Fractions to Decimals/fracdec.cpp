/*
 ID: ashilol1
 PROG: fracdec
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ofstream out ("fracdec.out");

void output(string answer){
    if(answer.length() <= 76) out << answer << endl;
    else{
        for(int i = 0; i < answer.length(); i += 76){
            cout << answer.substr(i, 76) << endl;
        }
    }
}

int main() {
    int N, D;
    string result;
    bool toggle = true;
    
    ifstream in ("/Users/AShi/Documents/Repos/USACO/Fractions to Decimals/fracdec.txt");
//    ifstream in ("fracdec.in");
    
    in >> N >> D;
    int values[D];
    memset(values, -1, sizeof(values));
    values[N % D] = 0;
    
    int n = N % D;
    while (toggle){
        result += to_string(n * 10 / D);
        n = n * 10 % D;
        if(n == 0){
            output(to_string(N / D) + "." + result);
            return 0;
        }
        if(values[n] != -1) toggle = false;
        else values[n] = (int)result.length();
    }
    result = result.substr(0, values[n]) + "(" + result.substr(values[n], result.length()) + ")";
    if(result.substr(result.length() - 3, 3) == "(0)") result = result.substr(0, result.length() - 3);
    output(to_string(N / D) + "." + result);
    
    return 0;
}
