#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

int top_down(int i, int j, vector<int> &point);

int main()
{
    int length, n, **cost_table;
    vector<int> point;
    cin>>length;
    cin>>n;

    point.resize(n+2);
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


    cout<<"min_cost:"<<top_down(n+1, 0, point);
    return 0;
}

int top_down(int i, int j, vector<int> &point)
{
    if(i-j==1) return 0;
    int min_cost=INT_MAX;
    for(int k=i-1;k>=j+1;k--)
    {
        int temp = top_down(i, k, point) + top_down(k, j, point) + point[i]-point[j];
        //cout<<"compute:"<<i<<k<<j<<" "<<cost_table[i][k]<<" "<<cost_table[k][j]<<" "<<point[i]<<" "<<point[j]<<endl;
        if(min_cost>temp)min_cost = temp;
    }
    return min_cost;
    //cout<<i<<" "<<j<<" "<<min_cost<<endl;
}
