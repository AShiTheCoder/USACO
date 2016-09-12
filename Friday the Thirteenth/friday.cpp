/*
 ID: ashilol1
 PROG: friday
 LANG: C++
 */

#include <fstream>
#include <iostream>

using namespace std;

int main(){
    int years, day = 0, monthCap;
    int months[12] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
    int days[7] = {0, 0, 0, 0, 0, 0, 0};
    
    ifstream in ("friday.in");
    ofstream out ("friday.out");
    
    in >> years;
    monthCap = years * 12;
    in.close();
    
    for (int i = 0; i < monthCap; i++){
        if (i % 12 == 0){
            if ((i/12 + 1900) % 400 == 0 || ((i/12 + 1900) % 4 == 0 && (i/12 + 1900) % 100 != 0)){
                months[1] = 1;
            } else {
                months[1] = 0;
            }
        }
        days[day]++;
        day = (day + months[i % 12]) % 7;
    }
    
    for (int i = 0; i < 6; i++){
        out << days[i] << " ";
    }
    out << days[6] << "\n";
    out.close();
    return 0;
}