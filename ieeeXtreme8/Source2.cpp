#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 1001

int nums[MAX_SIZE][MAX_SIZE];
int pre[MAX_SIZE][MAX_SIZE];

/*
void zero_array(int* input, int number)
{
       int i;
       for (i=0;i<number;i++){
               input[i]=0;
       }
}

int calc(int inner, int count,int states)
{
	int res=0;
	int low=inner>states? states:inner;
	int high=inner>states? inner:states;
	res=nums[low][count]+(pre[high][count]-pre[low][count]);
	//for (int i=low;i<=high;i++)
	//{
	//	res+=nums[i][count];
	//}
	return res;
}
*/

int main()
{
	int a,b,n;
	char c[1000];
	
	cin>>n;
	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>nums[i][j];
		}

		//precalc
		for(int i=0;i<n;i++)
		{
			pre[0][i]=nums[0][i];
			for(int j=1;j<n;j++)
			{
				pre[j][i]=nums[j][i]+pre[j-1][i];
			}
		}

	/////////////////////
		int L=n;
		int numStates=n;

		// allocate space

		int v[MAX_SIZE];
		//zero_array(v,MAX_SIZE);
		for(int i=0;i<n;i++)
			v[i]=nums[i][0];

		int vOld[MAX_SIZE];
		for(int i=0;i<n;i++)
			vOld[i]=nums[i][0];

		//zero_array(vOld,MAX_SIZE);

		for (int count=1;count<L;count++) //columns
		{
			for (int  states=0;states<numStates ; states++) //rows
			{
				
				int bestVal = 1000000000;
				for (int inner = 0; inner<numStates;inner++) 
				{
					int low=inner>states? states:inner;
					int high=inner>states? inner:states;
					int res=nums[low][count]+(pre[high][count]-pre[low][count]);
					int val = vOld[inner] + res;//calc(inner,count,states);
					if (val < bestVal)
					{
						bestVal = val;
					}
				}
			v[states] = bestVal;
		}
		memcpy(vOld,v,sizeof(v));
		//for(int z=0;z<n;z++)
		//	vOld[z] = v[z];
	}

// decide which of the final states is post probable
		int min=100000000;
		for (int i=0;i<n;i++)
			if(v[i]<min)
				min=v[i];

	/////////////////////
	cout<<min<<endl;
	return 0;
}