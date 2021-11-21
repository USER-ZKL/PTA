#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> cards;
vector<string> buf(54);

void swapc(int i,int j)
{
    string b = cards[j];
    cards[j] = cards[i];
    cards[i] = b;
}
int main()
{
    cout << buf[1];
   
    for(int i = 1; i <=13;i++)
    {
        string s = "S" + to_string(i);
        cards.push_back(s);
    }
    for(int i = 1; i <=13;i++)
    {
        string s = "H" + to_string(i);
        cards.push_back(s);
    }
    for(int i = 1; i <=13;i++)
    {
        string s = "C" + to_string(i);
        cards.push_back(s);
    }
    for(int i = 1; i <=13;i++)
    {
        string s = "D" + to_string(i);
        cards.push_back(s);
    }
    for(int i = 1; i <=2;i++)
    {
        string s = "J" + to_string(i);
        cards.push_back(s);
    }
    
    int n;
    cin >> n;
    vector<int> sh;
    for(int i = 0; i <54;i++)
    {
        int d = 0;
        cin >> d;
        sh.push_back(d);
    }

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<sh.size();j++)
        {
            buf[sh[j]-1] = cards[j];
        }
        cards = buf;
    }

    for(int i =0 ; i < 54;i++)
    {
        cout << buf[i];
        if(i < 53) 
            cout << " ";
    }

}