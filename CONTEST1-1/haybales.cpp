#include <fstream>
#include <iostream>

using namespace std;
int BALES[100000], N, Q;

void quicksort(int *a, int begin, int end){
    int pivot = (begin + end)/2;
    int I = begin, J = end, temp;
    while (I <= J){
        while (a[I] < a[pivot]) I++;
        while (a[J] > a[pivot]) J--;
        if (I <= J){
            temp = a[I];
            a[I] = a[J];
            a[J] = temp;
            J--;
            I++;
        }
    }
    if (begin < J){
        quicksort(a, begin, J);
    }
    if (I < end){
        quicksort(a, I, end);
    }
}

int search(int x, int *a, int begin, int end, int findEnd){
    if (end < begin) {
        return begin - findEnd;
    } else {
        int p = (begin + end)/2;
        if (x == a[p]){
            return p;
        } else if (x < a[p]){
            return search(x, a, begin, p - 1, findEnd);
        } else return search(x, a, p + 1, end, findEnd);
    }
}

int main() {
    int begin, end, x, y;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/CONTEST1-1/haybales.txt");
    ifstream in ("haybales.in");
    ofstream out ("haybales.out");
    in >> N >> Q;
    for (int i = 0; i < N; i++){
        in >> BALES[i];
    }
    quicksort(BALES, 0, N - 1);
//    for (int i = 0; i < N; i++){
//        cout << BALES[i] << "\n";
//    }
    for (int i = 0; i < Q; i++){
        in >> begin >> end;
        y = search(end, BALES, 0, N - 1, 1);
        x = search(begin, BALES, 0, N - 1, 0);
        out << y - x + 1<< "\n";
    }
    
    return 0;
}
