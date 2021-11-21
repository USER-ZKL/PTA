#include<iostream>
#include<vector>
using namespace std;
class point
{
private:
    int a[5];
public:
    point(){}
    ~point(){}
    void set(vector<int> &data){
       for (int i = 0; i < data.size(); i++)
       {
           a[i] = data[i]; 
       }
       
    }
    void show(){
        for (int i = 0; i < 5; i++)
        {
            cout << a[i] << " ";
        }
        
    }
};
int main(){
    point p;
    vector<int> data;
    cout<<"请输入五个数：";
    for (int i = 0; i < 5; i++)
    {
        int d = 0;
        cin >> d;
        data.push_back(d);
    }
    p.set(data);
    p.show();
    
}