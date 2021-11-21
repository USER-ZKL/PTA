#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
    int number;
    int dep;
};

vector<int> weibo[1010];
bool vis[1010] = {false};
int n,l;
int maxfollows = -1;
void bfs(int user,int dep){
    vis[user] = true;
    queue<node> q;
    node nd = {user,dep};
    int depth = 0;
    q.push(nd);
    while (!q.empty() )
    {
        auto now = q.front();
        depth = now.dep+1;
        if(depth>l) break;
        q.pop();
        for(int i=0;i<weibo[now.number].size();i++){
            if(vis[weibo[now.number][i]]==false){
                node fols = {weibo[now.number][i],depth};
                q.push(fols);
                maxfollows++;
                vis[weibo[now.number][i]] = true;
            }
            
        }
        
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
        maxfollows = 0;
        bfs(chk,0);
        cout<<maxfollows<<endl;
    }
    return 0;
}
