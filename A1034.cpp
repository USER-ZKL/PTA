#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int relas[2020][2020] = {0};
int tmprelas[2020][2020]={0};
bool vis[2020] = {false};
int myw[2020] = {0};
int n,k,people;
vector<pair<string,int>> ansg;
map<string,int> name;
void strtoint(const string &s){
    if(name.find(s)!=name.end()) return;
    else{
        name[s] = people;
        people++;
    }
}
int gnum = 0,gw = 0;
int head = -1,maxgw = 0;
void dfs(int g){
    //if(vis[g]==false){
        vis[g] = true;
        gnum++;
        if(myw[g]>maxgw){
            maxgw = myw[g];
            head = g;
        }
    //}
    for(int i=0;i<people;i++){
        if(relas[g][i]>0){
            gw += relas[g][i];
            relas[g][i] = 0;
            if(vis[i]==false)
            dfs(i);
        }
    }
}
void init(){
    for(int i=0;i<people;i++){
        for (int j = 0; j < people; j++)
        {
            relas[i][j] = tmprelas[i][j];
        }
    }
}
bool cmp(pair<string,int>a,pair<string,int>b){
    return a.first < b.first;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string n1,n2;
        int w = 0;
        cin>>n1>>n2>>w;
        strtoint(n1);
        strtoint(n2);
        relas[name[n1]][name[n2]]  = w;
        myw[name[n1]]+=w;
        myw[name[n2]]+=w;
    }
    /*
    for(int i=0;i<people;i++){
        for(int j=0;j<people;j++){
            tmprelas[i][j] = relas[i][j];
        }
    }*/
    int ans = 0;
    for(int i=0;i<people;i++){
        //memset(vis,false,sizeof(vis));
        if(vis[i]==false){
            gnum = 0;
            gw = 0;
            head = -1;
            maxgw = 0;
            
            dfs(i);
            //init();
            if(gnum>2 && gw>k){
                 ans++;
                 auto p = name.begin();
                 for(;p!=name.end();p++){
                     if((*p).second == head) break;
                 }
                 pair<string,int> np = {(*p).first,gnum};
                ansg.push_back(np);
            }
        }
    }
    if(ans == 0) {
        cout<<ans;
        return 0;
    }
    sort(ansg.begin(),ansg.end(),cmp);
    cout<<ans<<endl;
    for(auto p : ansg){
        cout<<p.first<<" "<<p.second<<endl;
    }
}