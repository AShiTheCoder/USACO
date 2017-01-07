/*
 ID: ashilol1
 PROG: zerosum
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void compute(int current, int k, vector<string> values, ostream &out){
    if (current != k){
        vector<string> x = values;
        x.push_back(" ");
        compute(current + 1, k, x, out);
        x.erase(x.end() - 1);
        x.push_back("+");
        compute(current + 1, k, x, out);
        x.erase(x.end() - 1);
        x.push_back("-");
        compute(current + 1, k, x, out);
    } else {
//        for (int i = 0; i < k; i++){
//            cout << "/" << values[i];
//        }
//        cout << "/\n";
        int total = 0, curNum = 1;
        string op = "+", toPrint = "1";
        for (int i = 0; i < k; i++){
            toPrint += values[i] + to_string(i + 2);
            if (values[i] == " "){
                curNum *= 10;
                curNum += i + 2;
            } else {
                if (op == "+"){
                    total += curNum;
                } else {
                    total -= curNum;
                }
                op = values[i];
                curNum = i + 2;
            }
        }
        if (op == "+"){
            total += curNum;
        } else {
            total -= curNum;
        }
        if (total == 0) out << toPrint << "\n";
    }
}

int main() {
    int N;
    vector<string> blank;
    blank.reserve(8);
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Zero Sum/zerosum.txt");
    ifstream in ("zerosum.in");
    ofstream out ("zerosum.out");
    in >> N;
    in.close();
    
    compute(0, N - 1, blank, out);
    return 0;
}
