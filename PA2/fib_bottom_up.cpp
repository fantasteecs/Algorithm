#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long int fib_bottom_up(int n);

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<fib_bottom_up(n)<<endl;
        FILE* fd = fopen("output.txt", "w");
        fprintf(fd,"%lli", fib_bottom_up(n) );
        fclose(fd);
    }
    return 0;
}

long long int fib_bottom_up(int n)
{
    if(n==0)return 0;
    else if(n==1)return 1;
    else
    {
        vector<long long int> table(n+1);
        table[0]=0;table[1]=1;
        for(int i=2;i<n+1;i++)
        {
            table[i]=table[i-1]+table[i-2];
        }
        return table[n];
    }
}
