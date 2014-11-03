#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAX_SIZE 2000

int mat[MAX_SIZE][MAX_SIZE];



int main() 
{
	vector<int> res;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}

	//diag
	long long dsum=0;
	for(int i=0;i<n;i++)
		dsum+=mat[i][i];

	//columns:
	for(int i=n-1;i>=0;i--)
	{
		long long  sum=0;
		for (int j=0;j<n;j++)
		{
			sum+=mat[j][i];
		}
		if(sum!=dsum)
			res.push_back(-i-1);
	}

	//anti diag:
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=mat[i][n-i-1];
	if(sum!=dsum)
		res.push_back(0);

	//rows:
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
			sum+=mat[i][j];
		if(sum!=dsum)
			res.push_back(i+1);
	}

	//printing
	cout<<res.size()<<endl;

	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;

    return 0;
}
