/*
 ID: ashilol1
 PROG: milk3
 LANG: C++
 */
#include <fstream>
#include <iostream>
using std::cout;
using std::ifstream;
using std::ofstream;
int possible[21], milkNums[3], milkCaps[3], count = 0;
bool visited[21][21][21];
bool found = false;

void swap(int array[], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void sort(int array[], int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length - i - 1; j++){
            if (array[j] > array[j + 1]){
                swap(array, j, j + 1);
            }
        }
    }
}

int* pour(int from, int to, int milk[], int caps[]){
    int sum = milkNums[from] + milkNums[to];
    if (sum <= caps[to]){
        milk[to] = sum;
        milk[from] = 0;
    } else {
        sum -= caps[to], milk[to] = caps[to];
        milk[from] = sum;
    }
    //    cout << "Poured " << from << " into " << to << "\n";
    //    cout << milk[0] << " " << milk[1] << " " << milk[2] << "\n";
    return milk;
}

void milkSearch(int nums[], int caps[]){
    if (!visited[nums[0]][nums[1]][nums[2]]){
        int currState[3];
        visited[nums[0]][nums[1]][nums[2]] = true;
//        cout << nums[0] << " " << nums[1] << " " << nums[2] << " has been visited\n";
        if (nums[0] == 0){
            possible[count] = nums[2];
            count++;
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (i != j && nums[i] > 0 && nums[j] < caps[j]){
//                    cout << i << " into " << j << " works\n";
                    for (int k = 0; k < 3; k++){
                        currState[k] = nums[k];
                    }
                    milkSearch(pour(i, j, nums, caps), caps);
                    for (int k = 0; k < 3; k++){
                        nums[k] = currState[k];
                    }
                    
                } else {
//                    cout << i << " into " << j << " doesn't work\n";
                }
            }
        }
    } else {
//        cout << "Someone's been to " << nums[0] << " " << nums[1] << " " << nums[2] << "\n";
    }
}

int main(){
    
//    ifstream in ("/Users/AShi/Documents/Repos/USACO/Mother's Milk/milk3.txt");
            ifstream in ("milk3.in");
            ofstream out ("milk3.out");
    in >> milkCaps[0] >> milkCaps[1] >> milkCaps[2];
    in.close();
    milkNums[0] = 0, milkNums[1] = 0, milkNums[2] = milkCaps[2];
    milkSearch(milkNums, milkCaps);
    sort(possible, count);
    
    for (int i = 0; i < count; i++){
        out << possible[i];
        if (i == count - 1){
            out << "\n";
        } else out << " ";
    }
    
    return 0;
}