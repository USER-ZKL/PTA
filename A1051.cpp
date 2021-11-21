#include<cstdio>
#include<stack>
using namespace std;

const int maxn = 1010;
int popchecks[maxn];
stack<int> st;
int main(){
	int M,N,K;
	scanf("%d%d%d",&M,&N,&K);
	while(K--){
		int pos = 0;
		bool flag = true;
		for(int i=0;i<N;i++){
			scanf("%d",&popchecks[i]);
		}
		while(!st.empty()){
			st.pop();
		}
		
		for(int i=1;i<=N;i++){
			st.push(i);
			if(st.size()>M){
				flag == false;
				break;
			}
			
			while(!st.empty() && st.top()== popchecks[pos] ){
					st.pop();
					pos++;
			}
			
		}
		
		if(!st.empty() || flag==false){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
		
		
	}
	return 0;

}
