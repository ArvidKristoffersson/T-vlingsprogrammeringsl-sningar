#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

const int MAXN = 1e5+1;
vector<int> child[MAXN];
vector<int> adj[MAXN];
queue<int> p;
int parent[MAXN], sum[MAXN];
bool nut[MAXN], isVisited[MAXN];

void pcAllo(int s){
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int c = q.front();
        //cout << 1 << endl; 
        isVisited[c] = true;
        q.pop();
        for (auto e : adj[c]){
            if (!isVisited[e]){
                parent[e] = c;
                child[c].push_back(e);
                q.push(e);
                isVisited[e] = true;
            }
            
        }
        if (child[c].empty())p.push(c);
    }
    return;
}

void dArvid(){
    while (!p.empty()){
        int c = p.front();
        p.pop();
        if(nut[c]){
            nut[parent[c]] = true;
            sum[parent[c]] += sum[c]+1;
        }
        child[parent[c]].pop_back();
        if (parent[c] != 1 && child[parent[c]].empty()){
            p.push(parent[c]);
        }
    }


    return;
}

int main(){
    int n, k, t; cin >> n >> k;

    for (int i = 0; i < k; i++){
        cin >> t;
        nut[t] = true;
    } 

    for (int i = 0; i < n-1; i++){
        cin >> t >> k;
        adj[t].push_back(k);
        adj[k].push_back(t);
    }
    //cout << 2 << endl;

    pcAllo(1);

    /*

    for (int i = 1; i <= 10; i++){
        cout << i << ": " << parent[i] << "      ";
        for (int j = 0; j < child[i].size(); j++){
            cout << child[i][j] << " ";
        }

        cout << endl;
    }
    */

    dArvid();


    cout << sum[1]* 2 << endl;






    return 0;
}
