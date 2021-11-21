#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
const int MAX = 510;
int ditu[MAX][MAX];
int cost[MAX][MAX];
int dis[MAX];
bool vis[MAX] = {false};
vector<int> pre[MAX];
int n,m,s,d;
void Dstra(){
    fill(dis,dis+MAX,INT_MAX);
    dis[s] = 0;
    while (1)
    {
        int u = -1,MIN = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if(vis[i] == false && dis[i] < MIN){
                u = i;
                MIN = dis[i];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int i=0;i<n;i++){
            if(vis[i] == false && ditu[u][i]!=INT_MAX){
                if(dis[u] + ditu[u][i] < dis[i]){
                    dis[i] = dis[u] + ditu[u][i];
                    pre[i].clear();
                    pre[i].push_back(u);
                }else if(dis[u] + ditu[u][i] == dis[i]){
                    pre[i].push_back(u);
                }
            }
        }
    }
}
vector<int> paths;
vector<int> ans;
int MIN_COST = INT_MAX;
void dfs(int index){
    if(index == s){
        paths.push_back(s);
        int sumc = 0;
        for(int i=paths.size()-1;i>0;i--){
            sumc += cost[paths[i]][paths[i-1]];
        }
        if(sumc < MIN_COST){
            MIN_COST = sumc;
            ans = paths;
        }
        paths.pop_back();
        return;
    }
    paths.push_back(index);
    for(int i=0;i<pre[index].size();i++){
        dfs(pre[index][i]);
    }
    paths.pop_back();
}
int main(){
    cin>>n>>m>>s>>d;
    fill(ditu[0],ditu[0]+MAX*MAX,INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int c1,c2,l,c;
        cin>>c1>>c2>>l>>c;
        ditu[c1][c2] = l;
        ditu[c2][c1] = l;
        cost[c1][c2] = c;
        cost[c2][c1] = c;
    }
    Dstra();
    dfs(d);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<ans.size()<<" "<<MIN_COST;
    return 0;
}