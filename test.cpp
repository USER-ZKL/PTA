#include<iostream>
using namespace std;
double FourCutFiveKeep(double num,int t)
{
    int pow10t=1;
    while(t!=0)
    {
        pow10t *= 10;
        t--;
    }
    return (int)(num * (double)pow10t + 0.5) / (double)pow10t;
}
int main(){
    double ans = FourCutFiveKeep(3.25,1);
    cout<<ans;
}