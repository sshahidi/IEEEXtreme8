#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 10001


int main()
{
	
	while(true)
	{
		int n;
		cin>>n;
		if( n==0)
			break;
		double p[MAX_SIZE];
		for(int i=1;i<n;i++)
		{
			cin>>p[i];
		}
		double sum=1;
		for(int i=1;i<n;i++)
		{
			sum=sum*(double)1/(double)p[i]+1;
		}
		//sum=sum*(1/p[n-1])+1;
		int res= sum-floor(sum) >=.5 ? (int)(sum+1) : (int)sum;
		cout<<res<<endl;
		//if(sum-res>1e-100)
		//	res=(int)sum+1;
		//cout<<(int)(ceil(res-1e-100)+1e-100)<<endl;
		
	}//tc
	return 0;
}