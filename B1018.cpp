#include<iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int p = 0;
    int js = 0,jb = 0;
    int ys = 0,yb = 0;
    int mj[3] = {0};
    int my[3] = {0};
    for(int i = 0; i < n ; i ++)
    {
        char jia,yi;
        cin >> jia >> yi;
        if(jia == 'C'){
            if(yi == 'C')
                p++;
            else if(yi == 'J')
            {
                js++;
                yb++;
                mj[1]++;
            }else if(yi == 'B')
            {
                jb++;
                ys++;
                my[0]++;
            }
        }

        if(jia == 'J')
        {
            if(yi == 'J')
                p++;
            else if(yi == 'B')
            {
                js++;
                yb++;
                mj[2]++;
            }else if(yi == 'C')
            {
                jb++;
                ys++;
                my[1]++;
            }
        }

        if(jia == 'B')
        {
            if(yi == 'B')
                p++;
            else if(yi == 'C')
            {
                js++;
                yb++;
                mj[0]++;
            }else if(yi == 'J')
            {
                jb++;
                ys++;
                my[2]++;
            }
        }
    }
    int jms = mj[0];
    int jmm = 0;
    for(int i = 0; i<3; i++)
    {
        if(mj[i] > jms)
        {
            jms = mj[i];
            jmm = i;
        }
    }

    int yms = my[0];
    int ymm = 0;
    for(int i = 0; i<3; i++)
    {
        if(my[i] > yms)
        {
            yms = my[i];
            ymm = i;
        }
    }

    cout << js << " " << p << " " << jb << endl;
    cout << ys << " " << p << " " << yb << endl;
    if(jmm == 0)
        cout << "B ";
    else if(jmm == 1)
        cout << "C ";
    else
        cout << "J ";

    if(ymm == 0)
        cout << "B";
    else if(ymm == 1)
        cout << "C";
    else
        cout << "J";
}