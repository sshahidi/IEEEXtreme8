#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 50001

int calc(int N,int F,int T, int L, int D[], int C[],int last_station_index,int from,int to)
{
	if(D[to] - D[from] < T)
		if(last_station_index==-1)
			return 0;
		else
			return (D[to] - D[from] - T)*C[last_station_index];
	
	int cost=0;
	int min=1000000001;
	int min_D=-1,min_i=-1;
	for(int i=from+1;i<to;i++)
	{
		if(D[i]-D[from]>T)
			break;
		if(C[i]<min)
		{
			min=C[i];
			min_D=D[i];
			min_i=i;
		}
	}
	
	if(min_i==-1) //can't make it with that initial fuel
		return -1;
	cost+=F-(D[min_i]-D[from])*min;
	/*int temp=calc();
	if(temp<0)
		return -1;
	cost+=temp;
	
	/int temp=calc();
	if(temp<0)
		return -1;
	cost+=temp;
	*/
	return cost;
}


class STN
{
public:
	int C,D;
};


int comp(const void* a,const void* b)
{
	STN * c= (STN*) a;
	STN* d = (STN*) b;
	return c->D - d->D;
}

STN stn[MAX_SIZE];

int main()
{
	int N,F,T,L;
	int D[MAX_SIZE];
	int C[MAX_SIZE];
	int TC;
	cin>>TC;
	
	for(int tc=0;tc<TC;tc++)
	{
		//rading
		cin>>N>>F>>T>>L;
		for (int i=0;i<N;i++)
		{
			cin>>stn[i].D>>stn[i].C;
		}
		qsort(stn,N,sizeof(STN),comp);

		long long cost=0;
		int walked_d=0;
		int current_station=-1;
		while(walked_d<L)
		{

			int min=1000000001;
			int min_D=-1,min_i=-1;
			for(int i=current_station+1; i<N ;i++)
			{
				if(current_station==-1 && stn[i].D>T)
					break;
				if(current_station!=-1 && stn[i].D-stn[current_station].D>T)
					break;
				if(stn[i].C<min)
				{
					min=stn[i].C;
					min_D=stn[i].D;
					min_i=i;
					if(current_station!=-1 && min<stn[current_station].C)
						break;
				}
			}
			
			if(min_i==-1 && current_station+1<N) //no answer
			{
				cost=-1;
				break;
			}
			if(min_i==-1 && current_station+1>=N && L-stn[current_station].D > T)
			{
				cost=-1;
				break;
			}
			if(current_station==-1 && L< T)
			{
				cost=0;
				break;
			}
			if(current_station!=-1 && L - stn[current_station].D <= T && stn[current_station].C<min) //end of line is reached, no cheaper station is on the way till the end.
			{
				cost+=(L - stn[current_station].D - T)*stn[current_station].C; //returning the gass!
				break;
			}

			if(current_station!=-1 && min<stn[current_station].C)
			{
				//returning the excess gass and filling up the thank with new price:
				cost+=(min_D-stn[current_station].D - T)*stn[current_station].C;
				cost+=F*min;
			}
			else
			{
				//just filling up the thank
				if(current_station==-1)
					cost+= (F-T+ min_D)*min;
				else
					cost+= (F-T+ min_D-stn[current_station].D)*min;
				
			}
			T=F;
			walked_d=min_D;
			current_station=min_i;
		}

		//processing.
		//from va to add she baraye avalin run.
		//int res=calc();
		//res-=extra;
		cout<<cost<<endl;
	}//for tc
	return 0;
}