#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,p;
    vector<int> data;
    vector<int> data2;
    cin >> n >> p;
    for(int i = 0; i<n ; i++)
    {
        int d = 0;
        cin >> d;
        data.push_back(d);
    }
    for(int i = n - p; i < n ; i++)
    {
        // if(i == 0)
        // {
        //     cout << data[i];
        //     if(i < n-1)
        //         cout << " ";
        // }
        // cout << data[i] << " ";
        data2.push_back(data[i]);
    }
    for(int i = 0 ; i < n-p ; i ++){
        // cout << data[i];
        // if(i < n-p-1) 
        //     cout << " ";
        data2.push_back(data[i]);
    }
    for(int i = 0; i < data2.size(); i++)
    {
        cout << data2[i];
        if(i < data2.size())
            cout << " ";
    }
}