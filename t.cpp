#include<iostream>
#include<string>
using namespace std;
const int maxn = 1020;  //最多占用1000+10+1=1011个结点（0号位置不用），这里开到1020稍大一点
const int INF = 1000000000;
int Graph[maxn][maxn];
int d[maxn];
bool visit[maxn];
int n, m, k, dis;
void Dijkstra(int s);
int main()
{
	fill(Graph[0], Graph[0] + maxn * maxn, INF);
	scanf("%d%d%d%d", &n, &m, &k, &dis);
	for (int i = 0; i < k; i++){
		string s1, s2;
		int c1, c2;
		int len;
		cin >> s1 >> s2 >> len;
//对于加油站1~m，我把它们拼在1~n之后，这样共有n+m个结点要进入Dijkstra算法
		if (s1[0] == 'G'){  //使用stoi灵活转化，注意M为10（两位数）的情况
            s1=s1.substr(1);
            c1=n+stoi(s1);
        }
		else c1=stoi(s1);
		if (s2[0] == 'G'){
            s2=s2.substr(1);
            c2=n+stoi(s2);
        }
		else c2=stoi(s2);
		Graph[c1][c2] = Graph[c2][c1] = len;
	}
	int maxL = -1, maxx = -1;
	int min_len = -1;
	for (int i = n + 1; i <= n + m; i++) {  
		Dijkstra(i);            //对于每个加油站，使用Dijkstra算法
		bool ok = true;         //判断当前案例是否合法
		int sum = 0, min_dist = INF;  //记录路径总和，房屋中到加油站最近的房屋距离
		for (int j = 1; j <= n; j++) {
			sum += d[j];
			if (d[j] > dis) { //如果某房子得不到供给，退出，并标记不合法
				ok = false;
				break;
			}
			if (d[j] < min_dist) min_dist = d[j];
		}
		if (ok) {  //如果合法
			if (min_dist > min_len) {  //最近的房屋到加油站的距离比原先最短的要长（更不容易发生危险）
				maxL = sum;
				maxx = i - n;
				min_len = min_dist;
			}
			else if (min_dist == min_len && sum < maxL) { //一样长的情况，sum
				maxL = sum;
				maxx = i - n;
			}
		}
	}
	if (maxx != -1) {
		printf("G%d\n", maxx);
		printf("%.1f %.1f", min_len*1., maxL*1. / n);
	}
	else printf("No Solution");
	return 0;
}
void Dijkstra(int s) {  //Dijkstra算法，这里不再赘述
	fill(d, d + maxn, INF);
	fill(visit, visit + maxn, 0);
	d[s] = 0;
	for (int i = 0; i < m + n; i++) {
		int u = -1, min = INF;
		for (int j = 1; j <= m + n; j++) {
			if (visit[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		visit[u] = true;
		for (int v = 1; v <= m + n; v++) {
			if (visit[v] == false && Graph[u][v] != INF) {
				if (Graph[u][v] + d[u] < d[v]) {
					d[v] = Graph[u][v] + d[u];
				}
			}
		}
	}
}
