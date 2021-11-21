#include<cstdio>
#include<stdlib.h>
typedef struct Node *List;
struct Node{
	int xi;
	int zhi;
	Node* next;
};

void Attach(int x,int z,Node **Rear){
	Node *newnode = (Node*)malloc((sizeof(struct Node)));
	newnode->xi = x;
	newnode->zhi = z;
	newnode->next = NULL;
	(*Rear)->next = newnode;
	(*Rear) = (*Rear)->next;
}

List Readdata(){
	List P = (List)malloc(sizeof(struct Node));
	P->next = NULL;
	List F = P;
	int n;
	scanf("%d",&n);
	while(n--){
		int xi,zhi;
		scanf("%d%d",&xi,&zhi);
		Attach(xi,zhi,&P);
	}
	Node *tmp = F;
	F = F->next;
	free(tmp);
	return F;
} 
void Print_data(List L){
	int flag = 0;
	if(!L) printf("0 0\n");
	while(L){
		if(flag == 0) flag = 1;
		else printf(" ");
		printf("%d %d",L->xi,L->zhi);
		L = L->next;
	}	
}

List Add(List a,List b){
	List P = (List)malloc(sizeof(struct Node));
	P->next = NULL;
	List F = P;
	
	while(a && b){
		if(a->zhi > b->zhi){
			Attach(a->xi,a->zhi,&P);
			a = a->next;
		}else if(a->zhi < b->zhi){
			Attach(b->xi,b->zhi,&P);
			b = b->next;
		}else{
			if((a->xi + b->xi) == 0){
				a = a->next;
				b = b->next;
			}else{
				Attach((a->xi + b->xi),a->zhi,&P);
				a = a->next;
				b = b->next;
			}
		}
	}
	while(a){
		Attach(a->xi,a->zhi,&P);
		a = a->next;
	}
	while(b){
		Attach(b->xi,b->zhi,&P);
		b = b->next;
	}
	Node *tmp = F;
	F = F->next;
	free(tmp);
	return F;	
}
List Muti(List L1,List L2){
	if(!L1 || !L2 )return NULL;
	List P = (List)malloc(sizeof(struct Node));
	P->next = NULL;
	List F = P;
	List t1 = L1->next;
	List t2 = L2;
	while(t2){
		Attach(L1->xi*t2->xi,L1->zhi+t2->zhi,&P);
		t2 = t2->next;
	}
	while(t1){
		t2 = L2;
		P = F;
		while(t2){
			Node* nd = (Node*)malloc(sizeof(struct Node));
			nd->xi = t1->xi * t2->xi;
			nd->zhi = t1->zhi + t2->zhi;
			nd->next = NULL;
			
			
			while(P->next!=NULL && (P->next->zhi > nd->zhi) ){
				P = P->next;
			} 
			if(P->next == NULL){
				P->next = nd;
				P = P->next;
			}
			 else if(P->next->zhi < nd->zhi){
				nd->next = P->next;
				P->next = nd;
				P = P->next;
			}else{
				if(P->next->xi + nd->xi == 0){
					Node* t = P->next;
					P->next = P->next->next;
					free(t);
				}else{
					P->next->xi += nd->xi;
				}
			}
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	Node *tmp = F;
	F = F->next;
	free(tmp);
	return F;	
} 
int main(){
	List P1,P2,PS,PP;
	P1 = Readdata();
	P2 = Readdata();
	PS = Add(P1,P2);
	PP = Muti(P1,P2); 
	Print_data(PP);
	
	Print_data(PS);
} 
