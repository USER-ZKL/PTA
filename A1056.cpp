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
		for(int i = 0;i<groups;++i){	//����ÿ���� 
			int max_weight = mices.front();	 
			for(int j=0;j<ng;++j){	//�ҵ����������������ı�� 
				if(i*ng + j >= temp) break;	//��ֹ���һ���������	
				int front = mices.front();
				max_weight = ((Mices[front].weight > Mices[max_weight].weight)? front : max_weight);
				Mices[front].rank = groups + 1; //û�н����Ĳ�������н�����һ��ѭ�������������䡣
				mices.pop();					//������һ��ѭ���Ļ��������������� 			
			}	
			mices.push(max_weight);//��ӣ�������һ�� 
		}	
	}
	int one = mices.front();
	Mices[one].rank = 1;
	for(int i = 0;i<nq;++i){
		printf("%d",Mices[i].rank);
		if(i!=nq-1) printf(" ");
		
	}
}
