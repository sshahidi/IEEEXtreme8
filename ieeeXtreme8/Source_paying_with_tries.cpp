#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 100001

//long long nums[MAX_SIZE];
long long tavans[26][MAX_SIZE];
long long acc[26][MAX_SIZE];

void precalc()
{
	for (int i=0;i<26;i++)
	{
		tavans[i][0]=1;
		acc[i][0]=1;
		for(int j=1;j<MAX_SIZE;j++)
		{
			tavans[i][j]=tavans[i][j-1]*(i+1);
			acc[i][j]=acc[i][j-1]+tavans[i][j];
		}
	}
}

int main()
{
	precalc();
	int TC;
	cin>>TC;
	for(int tc=0;tc<TC;tc++)
	{
		int A;
		long long L,N;
		cin>>A>>L>>N;
		long long sum=1;
		long long mult=1;

		/*if(A!=1)
		{
			long double cap= logl((long double)N)/logl((long double)A);
			long long icap=(long long)cap;
			sum=(long double)(powl(A,icap+1)-1)/(long double)(A-1);
			sum+=(L-icap)*N;
		}
		else
		{
			sum=L;*/
			int cnt=0;
			while(tavans[A-1][cnt]<N)
				cnt++;
			sum= acc[A-1][cnt-1] + (L-cnt+1)*N;
			/*for(int i=0;i<L;i++)
			{
				//mult*=A;
				mult=tavans[A-1][i];
				if(mult<N)
					sum+=mult;
				else
				{
					sum+=(L-i)*N;
					break;
				}
				//sum+= (mult < N ? mult : N );
			}*/

		//}
		sum*=(A*4);
		cout<<sum<<endl;
	}//tc
		

	return 0;
}