#include <iostream>

using namespace std;

int main(){
    int apples, pears;
    cin >> apples >> pears;
    int pearCost = pears * 13, appleCost = apples * 7;
    if (appleCost == pearCost){
        cout << "lika";
        return 0;
    }
    if (appleCost > pearCost){
        cout << "Axel";
        return 0;
    }
    if (appleCost < pearCost){
        cout << "Petra";
    }
    
    return 0;
}
