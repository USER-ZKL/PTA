#include<iostream>
using namespace std;
int main()
{
    int jh,js,yh,ys,m;
    int jj = 0, yj = 0;
    cin >> m;
    while (m--)
    {
        cin >> jh >> js >> yh >> ys;
        if(js == (jh + yh) && ys != (jh + yh))
            yj++;
        if(ys == (jh + yh) && js != (jh + yh))
            jj++;
    }
    cout << jj << " " << yj;
}