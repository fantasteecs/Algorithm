#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long int fib_memorize(int n, vector<long long int> &table);

int main()
{
    int n;
    while(cin>>n)
    {
        vector<long long int> table;
        table.resize(n+1);
        table[1]=1;
        cout<<fib_memorize(n, table)<<endl;
        FILE* fd = fopen("output.txt", "w");
        fprintf(fd,"%lli", fib_memorize(n, table) );
        fclose(fd);
    }
    return 0;
}

long long int fib_memorize(int n, vector<long long int> &table)
{
    if(n==0)return 0;
    else if(n==1)return 1;
    else
    {
        if(table[n]==0)
        {
            table[n] = fib_memorize(n-1, table) + fib_memorize(n-2, table);
        }
    }
    return table[n];
}

