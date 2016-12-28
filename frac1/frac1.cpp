/*
 ID: ashilol1
 PROG: frac1
 LANG: C++
 */

//DOES NOT WORK. WTF. WHY.

#include <fstream>
#include <iostream>

using namespace std;

int GCD(int a, int b){
    if (a == 0){
        return b;
    } else return GCD(b % a, a);
}

class Fraction{
public:
    int n, d;
    int compare(Fraction f){
        if (n * f.d > d * f.n){
//            cout << n << "/" << d << " is greater than " << f.n << "/" << f.d << "\n";
            return 1;
        } else if (n * f.d < d * f.n){
//            cout << n << "/" << d << " is less than " << f.n << "/" << f.d << "\n";
            return -1;
        } else {
//            cout << n << "/" << d << " is equal to " << f.n << "/" << f.d << "\n";
            return 0;
        }
    }
    Fraction(){};
    Fraction(int num, int denom){
        n = num;
        d = denom;
        int x = GCD(n, d);
        n /= x;
        d /= x;
    }
};

void quicksort(int left, int right, Fraction *fractions){
    int pivot = (left + right) / 2, i = left, j = right;
    while (i <= j){
        while (fractions[i].compare(fractions[pivot]) == -1) i++;
        while (fractions[j].compare(fractions[pivot]) == 1) j--;
        if (i <= j){
            Fraction temp = fractions[i];
            fractions[i] = fractions[j];
            fractions[j] = temp;
            i++;
            j--;
        }
    }
    
    if (left < j){
        quicksort(left, j, fractions);
    }
    if (right > i){
        quicksort(i, right, fractions);
    }
    
}

int main() {
    Fraction fractions[1000];
    int N, count = 0;
    bool found;
    
    ifstream in ("/Users/AShi/Documents/Repos/USACO/frac1/frac1.txt");
//    ifstream in ("frac1.in");
    ofstream out ("frac1.out");
    in >> N;
    
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= i; j++){
            found = false;
            Fraction f (j, i);
            for (int k = 0; k < count; k++){
                if (fractions[k].compare(f) == 0){
                    found = true;
                }
            }
            if (!found){
                fractions[count] = f;
                count++;
            }
        }
    }
    quicksort(0, count - 1, fractions);
    for (int i = 0; i < count; i++){
        cout << fractions[i].n << "/" << fractions[i].d << "\n";
    }
    return 0;
}
