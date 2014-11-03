#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <hash_map>
using namespace std;
#define MAX_SIZE 200001


int num[MAX_SIZE];
int K,M;
hash_map<int,int> table;


void updateMap(int in,int out)
{
	//if (in > table[K] && out> table[K])
	//	return;
	//TODO...

}

int comp(const void* a,const void* b)
{
	return *(int*) a - *(int*)b;
}

int main()
{
    int N;
	cin>>N>>M>>K;

	for (int i=0;i<N;i++)
		cin>>num[i];
	//adding
	for (int i=0;i<M;i++)
		num[N+i]=num[i];
	
	
	int subseq[100001];
	memcpy(subseq,num,sizeof(int)*(M));

	qsort(subseq,M,sizeof(int),comp);
	//filling up the table
	for(int i=0;i<M;i++)
		table[i]=subseq[i];

	int min=table[K];
	//int min=2147483647;
	//int temp=min;
	for(int i=1;i<N;i++)
	{
		updateMap(num[i+M],num[i]);
		
		if(table[K]<min)
			min=table[K];
	}

   
	cout<<min<<endl;
	return 0;
}