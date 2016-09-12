/*
 ID: ashilol1
 PROG: gift1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Gifter{
    Gifter(){}
    int balance = 0;
    string name;
    void gift(Gifter&, int);
    void setName(string n){
        name = n;
    }
};

void Gifter::gift(Gifter& g, int n){
    g.balance += n;
    balance -= n;
}

int main() {
    Gifter gifters[10];
    int numG, amt, div, portion = 0, current = 0;
    string curName;
    
    ifstream in ("gift1.in");
    ofstream out ("gift1.out");
    
    in >> numG;
    in.ignore();
    
    for (int i = 0; i < numG; i++){
        getline(in, curName);
        gifters[i].setName(curName);
    }
    
    while (!in.eof()){
        getline(in, curName);
        for (int i = 0; i < numG; i++){
            if (gifters[i].name == curName){
                current = i;
            }
        }
        in >> amt >> div;
        in.ignore();
        if (div > 0){
            portion = amt / div;
            amt -= portion * div;
        }
        for (int i = 0; i < div; i++){
            getline(in, curName);
            for (int j = 0; j < numG; j++){
                if (gifters[j].name == curName){
                    gifters[current].gift(gifters[j], portion);
                }
            }
        }
    }
    in.close();
    
    for (int i = 0; i < numG; i++){
        cout << gifters[i].name << " " << gifters[i].balance << "\n";
        out << gifters[i].name << " " << gifters[i].balance << "\n";
    }
    out.close();
    return 0;
}
