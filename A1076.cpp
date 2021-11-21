#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> weibo[1010];
bool vis[1010] = {false};
int n,l;
int maxfollows = -1;
void dfs(int user,int dep){
    if(dep>l) return;
    vis[user] = true;
    maxfollows++;
    for(int i=0;i<weibo[user].size();i++){
        if(vis[weibo[user][i]]==false)
            dfs(weibo[user][i],dep+1);
    }
}
int main(){
    cin>>n>>l;
    for(int i =1;i<=n;i++){
        int follows = 0;
        cin>>follows;
        for(int j=0;j<follows;j++){
            int fn = 0;
            cin>>fn;
            weibo[fn].push_back(i);
        }
    }
    int chks = 0;
    cin>>chks;
    for(int i=0;i<chks;i++){
        int chk = 0;
        cin>>chk;
        memset(vis,false,sizeof(vis));
        maxfollows = -1;
        dfs(chk,0);
        cout<<maxfollows<<endl;
    }
    return 0;
}