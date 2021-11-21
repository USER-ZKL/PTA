#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int n = 0;
int ditu[110][110];
int dis[110];
bool vis[110] = {false};
int nm = 0;
int Prim(int ans){
    fill(dis,dis+110,INT_MAX);
    dis[1] = 0;
    while (1)
    {
        int u = -1,MIN = INT_MAX;
        
        for(int i=1;i<=n;i++){
            if(vis[i]==false && dis[i]<MIN){
                u = i;
                MIN = dis[i];
            }
        }
        if(u == -1) break;
        vis[u] = true;
        ans+=dis[u];
        nm++;
        for(int i = 1;i<=n;i++){
            if(vis[i]==false && ditu[u][i]!=INT_MAX){
                if(ditu[u][i] < dis[i] ){
                    dis[i] = ditu[u][i];
                }
            }
        }

    }
    
    if(nm != n) return -1;
    else return ans;
}
int main(){
    fill(ditu[0],ditu[0]+110*110,INT_MAX);
    cin>>n;
    for(int i=0;i<(n*(n-1)/2);i++){
        int c1 = 0,c2 = 0,l=0;
        cin>>c1>>c2>>l;
        ditu[c1][c2] = l;
        ditu[c2][c1] = l;
    }
    int end;
    cin>>end;
    int ans = Prim(0);
    if(ans == -1) cout<<"Error";
    else cout<<ans;
    return 0;
}