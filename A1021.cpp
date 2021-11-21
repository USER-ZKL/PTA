#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> map[10010];
bool finded[10010] = {false};
int n;
int maxdep = 0;
int maxd = 0;
vector<int> nums;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;
}
void dfs(int c,int dep){
    finded[c] = true;
    maxdep = (dep > maxdep) ? dep : maxdep;
    for(int i=0;i<map[c].size();i++){
        if(finded[map[c][i]]== false)
            dfs(map[c][i],dep+1);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int c1,c2;
        cin>>c1>>c2;
        map[c1].push_back(c2);
        map[c2].push_back(c1);
    }
    if(n==0) {
        cout<<"Error: 0 components";
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(finded[i]==false) {
            ans++;
            dfs(i,1);
        }
    }
    if(ans > 1) {
        cout<<"Error:"<<ans<<" components";
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(finded,false,sizeof(finded));
        maxdep = 0;
        dfs(i,1);
        if(maxdep > maxd) {
            nums.clear();
            nums.push_back(i);
            maxd = maxdep;
        }
        else if(maxdep = maxd){
            nums.push_back(i);
        }
        
    }
    int num = 0;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
        if(num < n) cout<<"\n";
    }
}