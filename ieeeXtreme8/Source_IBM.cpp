#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAX_SIZE 2000

int mat[120][120];



int main() 
{
	vector<int> type1;
	vector<int> pair1,pair2;
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cin>>mat[i][j];
		}

	//rule 1:
	for(int i=0;i<N-1;i++)
	{
		int flag=1;
		for(int j=0;j<M;j++)
		{
			if(mat[i][j]!=mat[i+1][j] && mat[i+1][j]==mat[N-1][j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			//that is error!
			type1.push_back(i+1);
		}
	}


	for(int i1=0;i1<N-1;i1++)
	{
		for(int i2=i1+1;i2<N-1;i2++)
		{
			int flag=1;
			for(int j=0;j<M;j++)
			{
				if(mat[i1][j]!=mat[i1+1][j] && mat[i1+1][j]==mat[i2][j] && mat[i2][j]==mat[i2+1][j])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				//that is error!
				pair1.push_back(i1+1);
				pair2.push_back(i2+1);
			}
		}
	}

	cout<<type1.size()+pair1.size()<<endl;
	for(int i=0;i<type1.size();i++)
	{
		cout<<"i1="<<type1[i]<<endl;
	}
	for(int i=0;i<pair1.size();i++)
	{
		cout<<"i1="<<pair1[i]<<" i2="<<pair2[i]<<endl;
	}

    return 0;
}
