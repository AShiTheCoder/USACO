/*
 ID: ashilol1
 PROG: hamming
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool hamming(int a, int b, int len, int D){
    int x = a ^ b, count = 0;
    for (int i = 0; i < len; i++){
        if (x & int(pow(2, i))){
            count++;
        }
    }
    return count >= D;
}

int main() {
    int N, B, D;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Hamming Codes/hamming.txt");
    ifstream in ("hamming.in");
    ofstream out ("hamming.out");
    in >> N >> B >> D;
    in.close();
//    cout << hamming(0x554, 0x234, 12);
    
    int count = 1, codes[256];
    bool works;
    codes[0] = 0;
    for (int i = 1; i < pow(2, B); i++){
        if (count < N){
            works = true;
            for (int j = 0; j < count; j++){
                if (!hamming(i, codes[j], B, D)){
                    works = false;
                    j = count;
                }
            }
            if (works){
                codes[count] = i;
                count++;
            }
        } else i = pow(2, B);
    }
    
    out << codes[0];
    for (int i = 1; i < N; i++){
        if (i % 10 == 0){
            out << "\n" << codes[i];
        } else out << " " << codes[i];
    }
    out << "\n";
    
    return 0;
}
