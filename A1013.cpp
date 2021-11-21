#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> map[1010];
bool finded[1010] = {false};
int n,m,k;
int check = 0;
void dfs(int c){
    if(c == check) return;
    finded[c] = true;
    for(int i=0;i<map[c].size();i++){
        if(finded[map[c][i]]==false)
            dfs(map[c][i]);
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int c1 = 0,c2 = 0;
        cin>>c1>>c2;
        map[c1].push_back(c2);
        map[c2].push_back(c1);
    }
    int num = 0;
    for(int i=0;i<k;i++){
        int ans = 0;
        memset(finded,false,sizeof(finded));
        cin>>check;
        for(int j =1;j<=n;j++){
            if(j==check) continue;
            if(!finded[j]) ans++;
            dfs(j);
        }
     cout<<ans-1;
     num++;
     if(num<k) cout<<"\n";   
    }
}