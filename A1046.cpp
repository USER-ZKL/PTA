#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> dis;
    dis.push_back(0);
    dis.push_back(0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int d = 0;
        cin >> d;
        sum += d;
        dis.push_back(sum);
    }

    int m = 0;
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int dist1 = 0;
        int dist2 = 0;
        int d1,d2;
        cin >> d1 >> d2;
        if(d1 == d2){
            cout << 0 << endl;
            continue;
        }
           
        if(d1 > d2){
            int d = 0;
            d = d1;
            d1 = d2;
            d2 = d;
        }
        if(d1 < d2)
        {
            // for (int j = d1; j < d2; j++)
            // {
            //     dist1 += dis[j];
            // }
            dist1 = dis[d2] - dis[d1];
            dist2 = sum - dist1;
            // for(int j = d2; j < dis.size(); j++)
            // {
            //     dist2 += dis[j];
            // }
            // for(int j = 1; j < d1; j++)
            // {
            //     dist2 += dis[j];
            // }
            if(dist1 < dist2)
                cout << dist1;
            else
                cout << dist2;
            cout << endl;
        }  
    } 
}