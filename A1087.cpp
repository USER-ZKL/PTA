#include<iostream>
#include<map>
#include<vector>
#include<limits.h>
using namespace std;
int n,k;
string start;
map<string,int> s_i;
map<int,string> i_s;
int happiness[210];
int ditu[210][210];
int dis[210] = {0};
vector<int> pre[210];
bool vis[210] = {false};
void s2i(const string& s,int nu){
        s_i[s] = nu;
        i_s[nu] = s;
}
void Dijistra(){
    fill(dis,dis+210,INT_MAX);
    dis[0] = 0;
    while (1)
    {
        int u = -1,MIN = INT_MAX;
        for(int i = 0;i<n;i++){
            if(vis[i]==false && dis[i] < MIN){
                u = i;
                MIN = dis[i];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for (int i = 0; i < n; i++)
        {
            if(vis[i]==false && ditu[u][i] != INT_MAX){
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
vector<int> path;
vector<int> ans;
int difpath = 0;
int maxhapy = -1;
int maxavg = -1;
void dfs(int index){
    if(index == 0){
        path.push_back(0);
        difpath++;
        int sumhapy = 0;
        int avghapy = 0;
        for(int i=0;i<path.size();i++){
            sumhapy += happiness[path[i]];
        }
        avghapy = sumhapy/(path.size()-1);
        if(sumhapy > maxhapy){
            maxhapy = sumhapy;
            ans = path;
            maxavg = avghapy;
        }else if(sumhapy == maxhapy){
            if(avghapy > maxhapy){
                maxavg = avghapy;
                ans = path;
            }
        }
        path.pop_back();
        return;
    }
    path.push_back(index);
    for(int i=0;i<pre[index].size();i++){
        dfs(pre[index][i]);
    }
    path.pop_back();

}
int main(){
    fill(ditu[0],ditu[0]+210*210,INT_MAX);
    cin>>n>>k>>start;
    s_i[start] = 0;
    i_s[0] = start;
    for (int i = 1; i < n; i++)
    {
        string c;
        int h;
        cin>>c>>h;
        s2i(c,i);
        happiness[s_i[c]] = h; 
    }
    for(int i=0;i<k;i++){
        string c1,c2;
        int l;
        cin>>c1>>c2>>l;
        ditu[s_i[c1]][s_i[c2]] = l;
        ditu[s_i[c2]][s_i[c1]] = l;
    }

    Dijistra();
    dfs(s_i["ROM"]);
    int cost = 0;
    for(int i = ans.size()-1;i>0;i--){
        cost += ditu[ans[i]][ans[i-1]];
    }
    cout<<difpath<<" "<<cost<<" "<<maxhapy<<" "<<maxavg<<endl;
    for(int i=ans.size()-1;i>=0;i--){
        cout<<i_s[ans[i]];
        if(i>0) cout<<"->"; 
    }
    return 0;
}

