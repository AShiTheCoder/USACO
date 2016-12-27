#include <fstream>
#include <iostream>
using namespace std;
int COWS[200][3], N;

int main() {
    ifstream in ("/Users/AShi/Documents/Repos/USACO/CONTEST1-3/moocast.txt");
//    ifstream in ("moocast.in");
    ofstream out ("moocast.out");
    in >> N;
    
    for (int i = 0; i < N; i++){
        in >> COWS[i][0] >> COWS[i][1] >> COWS[i][2];
    }
    
    return 0;
}
