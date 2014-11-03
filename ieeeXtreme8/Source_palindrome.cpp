#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

#define MAX_SIZE 2010

char input[MAX_SIZE];
int L[MAX_SIZE][MAX_SIZE];
char X[MAX_SIZE],Y[MAX_SIZE];
//int LCSLength(string X,int m,string Y, int n)
int LCSLength(char* X,int m,char* Y, int n)
{
    //int m = X.size();
    //int n = Y.size();
    //int L[m+1][n+1];
    
	for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(X[i-1]==Y[j-1])
                L[i][j] = L[i-1][j-1]+1;
            else
                L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[m][n];
}

void myrev(char* str)
{
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char tmp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=tmp;
	}
}

int main() 
{
	int max=-1;
	cin>>input;
	strcpy(X,input);
	strcpy(Y,input);
	myrev(Y);

	int len=strlen(input);
	
	int index=0;
	int step_size=20;
	for(int i=len/2, j=len/2-1;i<len && j>=0;i+=step_size,j-=step_size)
	{
		int res=LCSLength(X,i,Y,len-i+1);
		if(res>max)
		{
			//cout<<"i:"<<i<<" max: "<<max<<endl;
			max=res;
			index=i;
		}

		res=LCSLength(X,j,Y,len-j+1);
		if(res>max)
		{
			//cout<<"j:"<<j<<" max: "<<max<<endl;
			max=res;
			index=j;
		}
		if(j<=max)
			break;
	}
	
	//////////////
	for(int i=index, j=index-1;i<len-1 && j>=0 && i<=index+step_size && j>=index-step_size;i++,j--)
	{
		int res=LCSLength(X,i,Y,len-i+1);
		if(res>max)
		{
			//cout<<"i:"<<i<<" max: "<<max<<endl;
			max=res;
			index=i;
		}

		res=LCSLength(X,j,Y,len-j+1);
		if(res>max)
		{
			//cout<<"j:"<<j<<" max: "<<max<<endl;
			max=res;
			index=j;
		}
		if(j<=max)
			break;
	}


	
	//char tmp2[MAX_SIZE];
	//strcpy(tmp2,input+index);
	//myrev(tmp2);
	int res  = LCSLength(X,index,Y,len-index);
	if(max==res)
		cout<<2*max<<endl;
	else
		cout<<2*max-1<<endl;

    return 0;
}
