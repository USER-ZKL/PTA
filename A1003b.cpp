#include<iostream>
#include<limits.h>
using namespace std;
const int Max_city = 550;
int n,m,start,dest;
int teams_city[Max_city];
int ditu[Max_city][Max_city];
int dis[Max_city];
bool vis[Max_city] = {false};
int w[Max_city] = {0};
int num[Max_city] = {0};
void Distra(){
    fill(dis,dis+n,INT_MAX);
    dis[start] = 0;
    w[start] = teams_city[start];
    num[start] = 1;
    while (1)
    {
        int u = -1,MIN = INT_MAX;
        for(int i=0;i<n;i++){
            if(dis[i] < MIN && vis[i]==false){
                u = i;
                MIN = dis[i];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int i=0;i<n;i++){
            if(ditu[u][i]!=INT_MAX && vis[i]==false){
                if(dis[u] + ditu[u][i] < dis[i]){
                    dis[i] = dis[u] + ditu[u][i];
                    w[i] = w[u] + teams_city[i];
                    num[i] = num[u];
                }else if(dis[u] + ditu[u][i] == dis[i]){
                    if(w[u] + teams_city[i] > w[i]){
                        w[i] = w[u] + teams_city[i];
                    }
                    num[i] += num[u];
                }
            }
        }
    }
    

}
int main(){
    cin>>n>>m>>start>>dest;
    for(int i=0;i<n;i++){
        cin>>teams_city[i];
    }
    fill(ditu[0],ditu[0]+Max_city*Max_city,INT_MAX);
    for(int i=0;i<m;i++){
        int c1,c2,l;
        cin>>c1>>c2>>l;
        ditu[c1][c2] = l;
        ditu[c2][c1] = l;
    }
    Distra();
    cout<<num[dest]<<" "<<w[dest]<<endl;
}