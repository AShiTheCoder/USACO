/*
 ID: ashilol1
 PROG: sort3
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int numbers[1000], N, n1 = 0, n2 = 0, n3 = 0;
    
    ifstream in ("/Users/AShi/Documents/Repos/USACO/Sorting A Three-Valued Sequence/sort3.txt");
//    ifstream in ("sort3.in");
    ofstream out ("sort3.out");
    in >> N;
    for (int i = 0; i < N; i++){
        in >> numbers[i];
        if (numbers[i] == 1){
            n1++;
        } else if (numbers[i] == 2){
            n2++;
        } else n3++;
    }
    
    //moving 1s in place
    int temp;
    int p1 = 0, p2 = n1, p3 = n1 + n2, swaps = 0;
    while (numbers[p2] != 1){
        p2++;
    }
    while (numbers[p3] != 1){
        p3++;
    }
    while (p1 < n1){
        if (numbers[p1] == 2){
            swaps++;
            if (p2 < n1 + n2){
                temp = numbers[p1];
                numbers[p1] = numbers[p2];
                numbers[p2] = temp;
                p2++;
                while (numbers[p2] != 1 && p2 < n1 + n2){
                    p2++;
                }
            } else {
                temp = numbers[p1];
                numbers[p1] = numbers[p3];
                numbers[p3] = temp;
                p3++;
                while (numbers[p3] != 1 && p3 < N){
                    p3++;
                }
            }
        } else if (numbers[p1] == 3){
            swaps++;
            if (p3 < N){
                temp = numbers[p1];
                numbers[p1] = numbers[p3];
                numbers[p3] = temp;
                p3++;
                while (numbers[p3] != 1 && p3 < N){
                    p3++;
                }
            } else {
                temp = numbers[p1];
                numbers[p1] = numbers[p2];
                numbers[p2] = temp;
                p2++;
                while (numbers[p2] != 1 && p2 < n1 + n2){
                    p2++;
                }
            }
        }
        p1++;
    }
    
    //moving 2s in place
    p2 = n1;
    p3 = n1 + n2;
    while (numbers[p2] == 2){
        p2++;
    }
    while (numbers[p3] == 3){
        p3++;
    }
    
    while (p2 < n1 + n2){
        if (numbers[p2] == 3){
            swaps++;
            temp = numbers[p2];
            numbers[p2] = numbers[p3];
            numbers[p3] = temp;
            p3++;
            while (numbers[p3] == 3 && p3 < N){
                p3++;
            }
        }
        p2++;
    }
    
    for (int i = 0; i < N; i++){
        cout << numbers[i];
    }
    out << swaps << "\n";
    
    return 0;
}
