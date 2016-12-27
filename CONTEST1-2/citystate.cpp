#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int N;
vector<string*> data(200000);

bool match(int i, string *s){
    string a1 = data.at(i)[0], a2 = data.at(i)[1], b1 = s[0], b2 = s[1];
//    cout << a1.substr(0,2);
    return a1.substr(0, 2) == b2 && b1.substr(0, 2) == a2;
}

int main() {
    int x = 0;
    bool found = false;
    string temp[2];
    
    ifstream in ("/Users/AShi/Documents/Repos/USACO/CONTEST1-2/citystate.txt");
//    ifstream in ("citystate.in");
    ofstream out ("citystate.out");
    in >> N;
    for (int i = 0; i < N; i++){
        in >> temp[0] >> temp[1];
        found = false;
        for (int j = 0; j < data.size(); j++){
            if (match(j, temp)){
                x++;
                data.erase(data.begin() + j);
                found = true;
                break;
            }
        }
        if (!found){
            data.push_back(temp);
        }
    }
    cout << x;
    
    return 0;
}
