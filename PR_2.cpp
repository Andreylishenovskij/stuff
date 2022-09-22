#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
using namespace std;
bool comp(vector <int> a,vector <int> b)
{
    return a[0]<b[0];
}

int main()
{
    int strings,columns;
    cin>>strings>>columns;
    vector <vector < int > > Matrix;
    for(int i = 0; i < strings;i++)
    {
         vector <int> str;
        for(int j = 0; j < columns ;j++)
        {
            int integer;
            cin>>integer;
            str.push_back(integer);
        }
        Matrix.push_back(str);
    }
    for(int i = 0; i < strings;i++)
    {
        for(int j = 0; j < columns ;j++)
        {
            cout<<Matrix[i][j]<<' ';
        }
        cout<<'\n';
    }
    sort(Matrix.begin(),Matrix.end(),comp);
    for(int i = 0; i < strings;i++)
    {
        for(int j = 0; j < columns ;j++)
        {
            cout<<Matrix[i][j]<<' ';
        }
        cout<<'\n';
    }
    getch();
}