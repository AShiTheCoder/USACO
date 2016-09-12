/*
 ID: ashilol1
 PROG: barn1
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

struct Board{
    int start, end;
    Board(){}
    void set(int s, int e){
        start = s;
        end = e;
    }
    void split(int s, int e, Board& b){
        int temp = end;
        set(start, s);
        b.set(e, temp);
    }
    int length(){
        return end - start + 1;
    }
};

void swap(int* a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int split(int* a, int left, int right){
    int result = left;
    for (int i = left; i < right; i++){
        if (a[i] < a[right]){
            swap(a, i, result);
            result++;
        }
    }
    swap(a, result, right);
    return result;
}

void quick(int* a, int start, int end){
    if (start < end){
        int middle = split(a, start, end);
        quick(a, start, middle - 1);
        quick(a, middle + 1, end);
    }
}

void quicksort(int* a, int length){
    quick(a, 0, length - 1);
}

int main(){
    int numBoards, total, numStalls, temp, currBoards = 1, maxGap = 0, currStall = 0, bestBoard = 0, maxStart = 0, maxEnd = 0, length = 0;
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Barn Repair/barn1.txt");
        ifstream in ("barn1.in");
        ofstream out ("barn1.out");
    
    in >> numBoards >> total >> numStalls;
    in.ignore();
    int* stalls = new int[numStalls];
    for (int i = 0; i < numStalls; i++){
        in >> temp;
        in.ignore();
        stalls[i] = temp;
    }
    in.close();
    quicksort(stalls, numStalls);
    
    if (numBoards >= numStalls){
        out << numStalls << "\n";
    } else {
        Board* boards = new Board[numBoards];
        boards[0].set(stalls[0], stalls[numStalls - 1]);
        for (int i = 0; i < numBoards - 1; i++){
            currStall = 0, maxGap = 0, maxStart = 0, maxEnd = 0, bestBoard = 0;
            for (int j = 0; j < currBoards; j++){
                currStall = 0;
                while (stalls[currStall] < boards[j].start){
                    currStall++;
                }
                while (stalls[currStall + 1] <= boards[j].end && currStall + 1 < numStalls){
                    if (stalls[currStall + 1] - stalls[currStall] > maxGap){
                        maxGap = stalls[currStall + 1] - stalls[currStall];
                        maxStart = stalls[currStall];
                        maxEnd = stalls[currStall + 1];
                        bestBoard = j;
                    }
                    currStall++;
                }
            }
            //        cout << "Board " << bestBoard << " spanned from " << boards[bestBoard].start << " to " << boards[bestBoard].end << "\n";
            boards[bestBoard].split(maxStart, maxEnd, boards[currBoards]);
            //        cout << "Split into " << boards[bestBoard].start << "-" << boards[bestBoard].end << " and " << boards[currBoards].start << "-" << boards[currBoards].end << "\n";
            currBoards++;
        }
        
        for (int i = 0; i < numBoards; i++){
            length += boards[i].length();
        }
        
        out << length << "\n";
    }
        out.close();
    return 0;
}