#include <iostream>
#include <cstdio>

using namespace std;

long long int fib_recursive(int n);

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<fib_recursive(n)<<endl;
        FILE* fd = fopen("output.txt", "w");
        fprintf(fd,"%lli", fib_recursive(n) );
        fclose(fd);
    }
    return 0;
}

long long int fib_recursive(int n)
{
    if(n==0)return 0;
    else if(n==1)return 1;
    else
    {
        return fib_recursive(n-1)+fib_recursive(n-2);
    }
}
