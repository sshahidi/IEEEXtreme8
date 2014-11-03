#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 100001

long long nums[MAX_SIZE];

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>nums[i];
	int Q;
	cin>>Q;
	int X;
	for(int i=0;i<Q;i++)
	{
		cin>>X;
	}

	long long sum=0;
	for(int i=0;i<N;i++)
		sum+=nums[i];

	for(int i=0;i<Q;i++)
	{
		sum*=2;
		sum= sum %(1000000007);
	}

	cout<<sum<<endl;

	return 0;
}