#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

int main()
{
    int length, n, *point, **cost_table;
    cin>>length;
    cin>>n;

    point = new int[n+2];
    point[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>point[i+1];
    }
    point[n+1] = length;

    cost_table = new int*[n+2];
    for(int i=0;i<n+2;i++)
    {
        cost_table[i] = new int[n+1];
    }
    for(int i=1;i<n+2;i++)
    {
        for(int j=i-1;j<=n;j++)
        {
            cost_table[i][j]=0;
        }
    }
    for(int i=1;i<n+2;i++)
    {
        for(int j=i-2;j>=0;j--)
        {
            int min_cost=INT_MAX;
            for(int k=i-1;k>=j+1;k--)
            {
                int temp = cost_table[i][k] + cost_table[k][j] + point[i]-point[j];
                //cout<<"compute:"<<i<<k<<j<<" "<<cost_table[i][k]<<" "<<cost_table[k][j]<<" "<<point[i]<<" "<<point[j]<<endl;
                if(min_cost>temp)min_cost = temp;
            }
            cost_table[i][j] = min_cost;
            //cout<<i<<" "<<j<<" "<<min_cost<<endl;
        }
    }
    cout<<"min_cost:"<<cost_table[n+1][0];
    return 0;
}
