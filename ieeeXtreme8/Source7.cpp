#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_LINES 1001

short table[MAX_LINES][MAX_LINES];

int main()
{
    int N,M;
	cin>>N>>M;

	for(int i=0;i<M;i++)
	{
		int a,b;
		cin>>a>>b;
		table[a][b]=1;
		table[b][a]=-1;
	}
	

	return 0;
}