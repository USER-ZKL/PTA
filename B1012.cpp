#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    float a4 = 0;
    int a5 = 0;
    int a4n = 0;
    int a4sum = 0;
    int a2n = 0;
    cin >> n;
    for(int i=0; i<n ; i++)
    {
        int d = 0;
        cin >> d;

        if((d%5==0)&&(d%2==0))
            a1 += d;

        
        if(d%5 == 1)
        {
            a2n++;
            if(a2n%2==1)
                a2 += d;
            else    
                a2 += -1*d;
        }

        if(d%5 == 2)       
            a3++;
        
        
        if(d%5 == 3)
        {
            a4n++;
            a4sum += d;
        }

        if(d%5 == 4){
            a5 = a5 > d ? a5 : d;
        }
    }
    a4 = (float)a4sum/a4n;
    // printf("%d %d %d %.1f %d",a1,a2,a3,a4,a5);
    if(a1 == 0)
        cout << "N ";
    else
        cout << a1 << " ";
    
    if(a2n == 0)
        cout << "N ";
    else
        cout << a2 << " ";
    
    if(a3 == 0)
        cout << "N ";
    else
        cout << a3 << " ";
    
    if(a4n == 0)
        cout << "N ";
    else
        printf("%.1f",a4);

    if(a5 == 0)
        cout << "N ";
    else
        cout << a5;
}