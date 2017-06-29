#include "vertex.h"
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

int main()
{
    int vertex_num, edge_num;
    cin>>vertex_num;
    cin>>edge_num;
    vertex *V;
    vector<vertex *> city;
    vector<int> dijkstras;
    vector<bool> complete;
    vector<int> temp_src;
    for(int i=0;i<vertex_num;i++)
    {
        V=new vertex;
        city.push_back(V);
        dijkstras.push_back(INT_MAX);
        complete.push_back(0);
        temp_src.push_back(INT_MAX);
    }
    int city1, city2, distance;
    for(int i=0;i<edge_num;i++)
    {

        cin>>city1>>city2>>distance;
        city[city1]->connected.push_back(city2);
        city[city1]->distance.push_back(distance);
        city[city2]->connected.push_back(city1);
        city[city2]->distance.push_back(distance);

    }

    int range, speed, src, dest;
    cin>>range>>speed>>src>>dest;
    dijkstras[src]=0;
    int ns=src, flag=0;

    while(1)
    {
        	for(int i=0;i<city[ns]->connected.size();i++)
		{
			if(city[ns]->distance[i]<range)
            {
			    if(dijkstras[city[ns]->connected[i]]>city[ns]->distance[i]+dijkstras[ns])
                    {
                        dijkstras[city[ns]->connected[i]]=city[ns]->distance[i]+dijkstras[ns];
                        temp_src[city[ns]->connected[i]]=ns;
                        //cout<<ns<<endl;
                    }

            }
		}

		complete[ns]=1;
		int small=INT_MAX;
		for(int i=0;i<dijkstras.size();i++)
		{
			if(complete[i]==0&&dijkstras[i]<small)
			{
				small=dijkstras[i];
				ns=i;

			}
           // cout<<i<<" "<<dijkstras[i]<<endl;
		}
     if(ns==dest) break;
    }
    stack<int> route;
    int temp=dest, r=0;
    while(temp!=src)
    {
        route.push(temp_src[temp]);
        //cout<<"temp"<<temp_src[temp]<<endl;
        temp=temp_src[temp];
        r++;
    }
    cout<<"\nRoute:";
    for(int i=0;i<r;i++)
    {
        cout<<route.top()<<" ";
        route.pop();
    }
    cout<<dest<<endl;
    cout<<"Total distance: "<<dijkstras[dest]<<endl;
    cout<<"Estimation time: "<<(double)dijkstras[dest]/(double)speed;


    return 0;
}
