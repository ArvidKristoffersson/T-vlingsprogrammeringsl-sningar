#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct Battery{
    double e;
    int w;
    int c;
};

vector<vector<double> > dp;
vector<Battery> batteries;

double rec(double k, int ind, double energy, int left){
    if (dp[ind][left] != linf){
        return dp[ind][left] + energy;
    }

    if (ind == batteries.size()){
        return energy;
    }

    //Hoppa över
    double best = max(energy, rec(k, ind+1, energy, left));
    if (left - batteries[ind].c > -1){
        best = max(best, rec(k, ind+1, energy + batteries[ind].e - k * batteries[ind].w, left - batteries[ind].c));
    }
    dp[ind][left] = best - energy;
    //cout << best << " " << energy << " " << batteries[ind].c << " " << batteries[ind].w << endl;
    return best;
}

int main(){
    scoobydoobydoo();
    ll N, B, W; cin >> N >> B >> W;
    for(int i = 0; i < N; i++){
        vector<double> temp;
        int x, y, z; cin >> x >> y >> z;
        Battery t;
        t.e = (double)x; t.w = y; t.c = z;
        batteries.push_back(t);

        for (int j = 0; j < B+1; j++){
            temp.push_back(linf);
        }
        dp.push_back(temp);
    }
    vector<double> temp;
    for (int j = 0; j < B+1; j++){
        temp.push_back(linf);
    }
    dp.push_back(temp);
    /*
    for (auto e : batteries){
        cout << e.c << " " << e.w << " " << e.e << endl;
    }
    */

    sort(all(batteries), [](const Battery& b1, const Battery& b2){
        return b1.c > b2.c;
    });

    double a = 0, b = linf;

    //cout << rec(1.77, 0, 0, B) << endl;
    
    
    while (abs(a-b) > 1e-6){
        double mid = (a+b)/2;

        //cout << mid << " " << rec(mid, 0, 0, B) << " " << mid * W << endl;

        if (rec(mid, 0, 0, B) - mid*W > 0){
            a = mid;
            //cout << 1 << endl;
        } else {
            b = mid;
            //cout << 2 << endl;
        }
        for(int i = 0; i < N+1; i++){
            for (int j = 0; j < B+1; j++){
                dp[i][j] = linf;
            }
        }
    }
    

    cout << fixed << setprecision(10);
    cout << a << endl;





    return 0;
}
