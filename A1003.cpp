#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
struct node{
    
    int next,length;
};
int n,m,start,dest;
int teams_city[550] = {0};
int dis[550] = {0};
vector<node> ditu[550];
bool vis[550] = {false};
int weight[550] = {0};
int shorts[550] = {0};
void dijikstra(){
    fill(dis,dis+n,INT_MAX);
    dis[start] = 0;
    shorts[start] = 1;
    weight[start] = teams_city[start];
    for (int i = 0; i < n; i++)
    {
        int u = -1,min_length = INT_MAX;
        for(int j=0;j<n;j++){
            if(vis[j]==false && dis[j]<min_length){
                u = j;
                min_length = dis[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j=0;j<ditu[u].size();j++){
            int next = ditu[u][j].next;
            if(vis[next]==false){
                if( dis[u]+ditu[u][j].length < dis[next]){
                    dis[next] = ditu[u][j].length + dis[u];
                    shorts[next] = shorts[u];
                    weight[next] = weight[u] + teams_city[next];
                }else if(dis[u]+ditu[u][j].length == dis[next]){
                        if(weight[u]+weight[next] > weight[next])
                            weight[next] = weight[u] + teams_city[next];
                        shorts[next] += shorts[u];
                }
            }
            
        }
    }
    
}
int main(){
    cin>>n>>m>>start>>dest;
    for(int i=0;i<n;i++){
        int teams = 0;
        cin>>teams;
        teams_city[i] = teams;
    }
    for(int i=0;i<m;i++){
        int c1,c2,l;
        cin>>c1>>c2>>l;
        node n1(c1,l);
        node n2(c2,l);
        ditu[c1].push_back(n2);
        ditu[c2].push_back(n1);
    }
    dijikstra();
    cout<<shorts[dest]<<" "<<weight[dest]<<endl;
}