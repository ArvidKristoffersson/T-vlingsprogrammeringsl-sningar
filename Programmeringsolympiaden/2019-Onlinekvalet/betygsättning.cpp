#include <iostream>
#include <vector>

using namespace std;

int main(){
    double kA, kC, kE, a, c, e; cin >> kA >> kC >> kE >> a >> c >> e;

    if(kA == a && kC == c && kE == e){
        cout << 'A' << endl;
    } else if (a >= kA/2 && kC == c && kE == e){
        cout << 'B' << endl;
    } else if (kC == c && kE == e){
        cout << 'C' << endl;
    } else if (c >= kC/2 && kE == e){
        cout << 'D' << endl;
    } else if (kE == e){
        cout <<  'E' << endl;
    } else {
        cout << 'F' << endl;
    }


    return 0;
}
