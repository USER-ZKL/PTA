#include<iostream>
using namespace std;
float datas[1010] = {0};
int main()
{
    int k1,k2;
    cin >> k1;
    for(int i = 0; i<k1 ; i++)
    {
        int p = 0;
        float v = 0;
        cin >> p >> v;
        datas[p] += v;
    }
    cin >> k2;
    int sum = k1 + k2;
    for(int i = 0; i< k2 ; i ++)
    {
        int p = 0;
        float v = 0;
        cin >> p >> v;
        if(datas[p] != 0){
            if(datas[p] + v == 0)
                sum -= 2;
            else
                sum--;
        }
        datas[p] += v;
    }
    cout << sum;
    // int d = 0;
    // for(int i = 1000; i>=0;i--)
    // {
    //     if(datas[i]!=0)    
    //         d++;
    // }
    // cout << d << " ";
    for(int i = 1000; i >= 0; i--)
    {
        if(datas[i]!=0){
            printf(" %d %.1f",i,datas[i]);
        }
    }
}