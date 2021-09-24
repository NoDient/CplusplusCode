#include <iostream>
using namespace std;

// Tìm các số nhị phân gồm có n bit
int a[100];
int n = 4;

void inradaynhiphan (int a[], int n)
{
    for (int i = 1 ; i <= n ;i++) cout<<a[i] << " ";
    cout<< endl;
}

void khoitaotohop (int i)
{
    for(int j=0;j<=1;j++)
    {
        a[i] = j;
        if(i == n) inradaynhiphan(a,n);
        else khoitaotohop (i+1);
    }
}
int main ()
{
    khoitaotohop (1);
}
