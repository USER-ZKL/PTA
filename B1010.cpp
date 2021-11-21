#include<cstdio>
int a[1010] = {0};
int main()
{
    int xi,zhi;
    while (scanf("%d %d",&xi,&zhi)!=EOF)
    {
        a[zhi] = xi;
    }

    a[0] = 0;
    int count = 0;
    for(int i = 1; i<=1000; i++)
    {
        a[i-1] = a[i] * i;
        a[i] = 0;
        if(a[i-1] != 0)
            count++;
    }
    if(count == 0)
        cout << "0 0";
    else{
        for(int i = 1000;i>=0;i--)
        {
            if(a[i]==0)
                continue;
            else{
                cout << a[i] << " " << i;
                count--;
                if(count > 0)
                    cout << " ";
            }
        }
    }
    
}