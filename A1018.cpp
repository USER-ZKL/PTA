#include<iostream>
#include<limits.h>
#include<vector>
#include<cmath>
using namespace std;
const int STATIONS = 510;
int cmax,n,dest,m;
int cur_cap[STATIONS] = {0};
int G[STATIONS][STATIONS];
bool vis[STATIONS] = {false};
int dis[STATIONS];
vector<int> pre[STATIONS];
void Distra(){
    fill(dis,dis+n+1,INT_MAX);
    dis[0] = 0;
    while (1)
    {
        int u = -1,MIN = INT_MAX;
        for(int i=0;i<=n;i++){
            if(vis[i]==false && dis[i]<MIN){
                u = i;
                MIN = dis[i];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int i=0;i<=n;i++){
            if(vis[i]==false && G[u][i]!=INT_MAX){
                if(dis[u] + G[u][i] < dis[i]){
                    dis[i] = dis[u] + G[u][i];
                    pre[i].clear();
                    pre[i].push_back(u);
                }else if(dis[u] + G[u][i] == dis[i]){
                    pre[i].push_back(u);
                }
            }
        }
    }
}
vector<int> paths;
vector<int> perfect;
int min_send = INT_MAX;
int min_back = INT_MAX;
void dfs(int index){
    if(index == 0){
        paths.push_back(0);
        int back = 0,send = 0;
        for(int i = paths.size()-2;i>=0;i--){
            int cbike = cur_cap[paths[i]];
            if(cbike > cmax) back += (cbike - cmax);
            else if(cbike < cmax){
                int sub = cmax - cbike;
                if(back >= sub) back-=sub;
                else{
                    send += (sub - back);
                    back = 0;
                }
            } 
        }
        if(send < min_send){
            min_send = send;
            min_back = back;
            perfect = paths;
        }else if(send == min_send){
            if(back < min_back){
                min_back = back;
                min_send = send;
                perfect = paths;
            }
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
    cin>>cmax>>n>>dest>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>cur_cap[i];
    }
    fill(G[0],G[0]+STATIONS*STATIONS,INT_MAX);
    for(int i=0;i<m;i++){
        int c1,c2,l;
        cin>>c1>>c2>>l;
        G[c1][c2] = l;
        G[c2][c1] = l;
    }
    cmax/=2;
    Distra();
    dfs(dest);
    cout<<min_send<<" ";
    for(int i = perfect.size()-1;i>=0;i--){
        cout<<perfect[i];
        if(i>0) cout<<"->";
    }
    cout<<" "<<min_back;
}