#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 2000002

int nums[20];
int seq[MAX_SIZE];

bool hasNums(int n,int N)
{
	char mainstr[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	sprintf(mainstr,"%d",n);
	int len=strlen(mainstr);
	for(int i=0;i<N;i++)
	{
		char str[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
		sprintf(str,"%d",nums[i]);
		if(strstr(mainstr,str)!=NULL)
		{
			return true;
		}
		
	}
	return false;
}


int main()
{
	int S,E,P,N;
	cin>>S>>E>>P>>N;
	for(int i=0;i<N;i++)
	{
		cin>>nums[i];
	}

	int count=1;
	for(int i=S;i<=E;i++)
	{
		if(hasNums(i,N))
		{
			seq[count]=i;
			count++;
		}
	}

	if(P>=count)
		cout<<"DOES NOT EXIST"<<endl;
	else
		cout<<seq[P]<<endl;
	return 0;
}