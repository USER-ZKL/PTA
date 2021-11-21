#include<iostream>
#include<limits.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX_MAP = 1200;
const int INF = 1000000000;
int ditu[MAX_MAP][MAX_MAP];
int dis[MAX_MAP];
bool vis[MAX_MAP] = {false};
int n,m,k,ds;
void Dijistra(int gas){
    fill(dis,dis+MAX_MAP,INT_MAX);
    memset(vis,false,sizeof(vis)); 
    dis[gas] = 0;
    while (1)
    {
        int u = -1,MIN = INT_MAX;
        for(int i=1;i<=n+m;i++){
            if(vis[i] == false && dis[i] < MIN){
                u = i;
                MIN = dis[u];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int i=1;i<=n+m;i++){
            if(vis[i]==false && ditu[u][i]!=INT_MAX){
                if(dis[u] + ditu[u][i] < dis[i]){
                    dis[i] = dis[u] + ditu[u][i];
                }
            }
        }
    }
    

}
int s2i(string &s){
    if(s[0] == 'G'){
        return stoi(s.substr(1))+n;
    }else{
        return stoi(s);
    }
}
int main(){
    cin>>n>>m>>k>>ds;
    fill(ditu[0],ditu[0]+MAX_MAP*MAX_MAP,INT_MAX);
    for(int i=0;i<k;i++){
        string s1,s2;
        int dist = 0;
        cin>>s1>>s2>>dist;
        int c1 = s2i(s1);
        int c2 = s2i(s2);
        ditu[c1][c2] = dist;
        ditu[c2][c1] = dist;
    }
    double max_house = -1;
    int ans = INT_MAX;
    bool overds = false;
    double average = INF;
    for(int i=n+1;i<=n+m;i++){
        overds = false;
        double min = INT_MAX,avg;
           
        Dijistra(i);
        for(int j=1;j<=n;j++){
            if(dis[j] > ds) {
                overds = true;
                break;
            }
            min = (dis[j] < min) ? dis[j] : min;
            avg += 1.0 * dis[j] / n;
        }
        if(overds) continue;
        if(min > max_house){
            max_house = min;
            ans = i-n;
            average = avg;
        }else if(min = max_house && avg < average){
            // if(avg < average){
                average = avg;
                ans = i-n;
            // }
            // else if(avg = average){
            //     average = avg;
            //     ans = ((i-n) < ans) ? (i-n) : ans;
            // }
        }
    }
    if(ans == INT_MAX) {
        cout<<"No Soultion";
        return 0;
    }
    cout<<"G"<<ans<<endl;
    // int t = (int)(average * 10 + 0.5);
    // double aver = (double)t/10;
    // printf("%.1f ",(double)max_house);
    // cout<<aver;
    printf("%.1f %.1f",max_house,average);
}