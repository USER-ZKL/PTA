#include<cstdio>
#include<queue>
using namespace std;
struct mice{
	int weight;
	int rank;
};
mice Mices[10010];

int main(){
	int nq,ng;
	scanf("%d%d",&nq,&ng);
	for(int i=0;i<nq;++i){
		scanf("%d",&Mices[i].weight);
	}
	queue<int> mices;
	for(int i=0;i<nq;++i){
		int number;
		scanf("%d",&number);
		mices.push(number);
	}
	while(mices.size()!=1){
		int temp = mices.size(); 
		int groups = ((temp%ng == 0) ? (temp/ng) : (temp/ng+1)); 
		for(int i = 0;i<groups;++i){	//遍历每个组 
			int max_weight = mices.front();	 
			for(int j=0;j<ng;++j){	//找到该组最大重量老鼠的标号 
				if(i*ng + j >= temp) break;	//防止最后一组个数不够	
				int front = mices.front();
				max_weight = ((Mices[front].weight > Mices[max_weight].weight)? front : max_weight);
				Mices[front].rank = groups + 1; //没有晋级的不加入队列进行下一次循环，则排名不变。
				mices.pop();					//加入下一轮循环的会对其进行重新排名 			
			}	
			mices.push(max_weight);//入队，进入下一轮 
		}	
	}
	int one = mices.front();
	Mices[one].rank = 1;
	for(int i = 0;i<nq;++i){
		printf("%d",Mices[i].rank);
		if(i!=nq-1) printf(" ");
		
	}
}
