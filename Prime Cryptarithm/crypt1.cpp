/*
 ID: ashilol1
 PROG: crypt1
 LANG: C++
 */

#include <fstream>
#include <iostream>

using namespace std;

int numDigits(int num){
    int N = 0;
    while (num > 0) {
        num /= 10;
        N++;
    }
    return N;
}

bool fits(int num, int digits[], int N){
    while (num > 0) {
        bool good = false;
        for (int i = 0; i < N; i++){
            if (num % 10 == digits[i]){
                good = true;
                i = N;
            }
        }
        if (!good){
            return false;
        }
        num /= 10;
    }
    return true;
}

int main(){
    int N, first, second, solutions = 0;
    int digits[10];
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/crypt1/crypt1.txt");
        ifstream in ("crypt1.in");
        ofstream out ("crypt1.out");
    
    in >> N;
    in.ignore();
    for (int i = 0; i < N; i++){
        in >> digits[i];
    }
    in.close();
    
    for (int i = 0; i < N; i++){
        if (digits[i] != 0){
            for (int j = 0; j < N; j++){
                for (int k = 0; k < N; k++){
                    for (int l = 0; l < N; l++){
                        if (digits[l] != 0){
                            for (int m = 0; m < N; m++){
                                first = 100 * digits[i] + 10 * digits[j] + digits[k];
                                second = 10 * digits[l] + digits[m];
                                if (numDigits(first * second) != 4 ||
                                    !fits(first * second, digits, N) ||
                                    numDigits(digits[l] * first) != 3 ||
                                    numDigits(digits[m] * first) != 3 ||
                                    !fits(digits[l] * first, digits, N) ||
                                    !fits(digits[m] * first, digits, N)){
                                    continue;
                                } else {
                                    solutions++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    out << solutions << "\n";
    out.close();
    return 0;
}