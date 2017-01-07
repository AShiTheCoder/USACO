/*
 ID: ashilol1
 PROG: prefix
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> primitives, a;
    string sequence;
    sequence.reserve(200000);
    primitives.reserve(200);
    a.reserve(200);
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Longest Prefix/prefix.txt");
    ifstream in ("prefix.in");
    ofstream out ("prefix.out");
    
    string next;
    in >> next;
    while (next != "."){
        primitives.push_back(next);
        in >> next;
    }
    in >> next;
    while (!in.eof()){
        sequence += next;
        in >> next;
    }
    in.close();
    
    vector<bool> visited(sequence.size() + 1);
    visited[0] = true;
    int farthest = 0;
    for (int i = 1; i < visited.size(); i++) visited[i] = false;
    for (int i = 0; i < visited.size(); i++){
        if (!visited[i]) continue;
        for (int j = 0; j < primitives.size(); j++){
            string cur = primitives[j], x = sequence.substr(i, cur.length());
            if (i + cur.length() <= sequence.length() && x == cur){
                visited[i + cur.length()] = true;
                if (i + cur.length() > farthest) farthest = i + int(cur.length());
            }
        }
    }
    out << farthest << "\n";
    
    return 0;
}
