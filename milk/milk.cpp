/*
ID: ashilol1
PROG: milk
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

struct Farmer{
    int price;
    int milk;
    void setMilk(int m){
        milk = m;
    }
    void setPrice(int p){
        price = p;
    }
    bool hasMilk(){
        return milk > 0;
    }
    Farmer(){}
};

void buyFrom(Farmer& f, int& price, int& milk){
    f.milk -= 1;
    milk -= 1;
    price += f.price;
}

void swap(Farmer* f, int i, int j){
    Farmer temp = f[i];
    f[i] = f[j];
    f[j] = temp;
}

int partition(Farmer a[], int left, int right) {
    int splitPos = left;
    for (int i = left; i < right; i++) {
        if (a[i].price < a[right].price) {
            swap(a, i, splitPos);
            splitPos++;
        }
    }
    swap(a,splitPos,right);
    return splitPos;
}

void quick(Farmer* a, int left, int right) {
    if (right > left) {
        int pivotPos = partition(a, left, right);
        quick(a, left, pivotPos-1);
        quick(a, pivotPos+1, right);
    }
}

void quicksort(Farmer* a, int length) {
    quick(a, 0, length - 1);
}

int main(){
    int milk, numFarmers, currMilk, currPrice, cost = 0, currFarmer = 0;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/milk/milk.in.txt");
    ifstream in ("milk.in");
    ofstream out ("milk.out");
    
    in >> milk >> numFarmers;
    in.ignore();
    Farmer* farmers = new Farmer[numFarmers];
    for (int i = 0; i < numFarmers; i++){
        in >> currPrice >> currMilk;
        in.ignore();
        farmers[i].setMilk(currMilk);
        farmers[i].setPrice(currPrice);
    }
    in.close();
    
    quicksort(farmers, numFarmers);
    
    while (milk > 0){
        if (!farmers[currFarmer].hasMilk()){
            currFarmer++;
        } else {
            buyFrom(farmers[currFarmer], cost, milk);
        }
    }
    
    out << cost << "\n";
    out.close();
    return 0;
}