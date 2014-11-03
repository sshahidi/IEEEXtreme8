#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 1001

float trans[MAX_SIZE][MAX_SIZE];
float res[MAX_SIZE][MAX_SIZE];
float temp[MAX_SIZE][MAX_SIZE];
float pre[MAX_SIZE][MAX_SIZE];


void mcopy(float a[][MAX_SIZE], float b[][MAX_SIZE],int n)
{
	for(int i=0;i<n;i++)
		memcpy(a[i],b[i],sizeof(float)*n);
}

bool compare(float a[][MAX_SIZE],float b[][MAX_SIZE],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!=b[i][j])
				return false;
	return true;
}

void mult(res,res,n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(
}

int main()
{
	memset(trans,0,sizeof(trans));
	memset(res,0,sizeof(res));
	memset(temp,0,sizeof(temp));
	while(true)
	{
		int n;
		cin>>n;
		if( n==0)
			break;
		int p[MAX_SIZE];
		for(int i=0;i<n-1;i++)
		{
			cin>>p[i];
			trans[i][0]=1-p[i];
			trans[i][i+1]=p[i];
		}

		mcopy(res,trans,n);
		//mcopy(temp,trans,n);
		mcopy(pre,trans,n);
		int count=0;
		while(!compare(temp,res))
		{
			mcopy(pre,temp);
			mcopy(temp,res);
			mult(res,res,n);
			count*=2;
		}
		//tracing back
		count/=4;



		//reinitalizing
		for(int i=0;i<n;i++)
			for(int j=0; j<n;j++)
			{
				trans[i][j]=0;
			}
	}//tc
	return 0;
}