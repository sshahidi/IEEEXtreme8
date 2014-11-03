#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
#define MAX_SIZE 2000



char values[128];
char seq1[MAX_SIZE],seq2[MAX_SIZE];
char temp[MAX_SIZE];
int N;


//lower bound inclusive, upper bound exclusive
int solve(int from1,int to1,int from2,int to2)
{
	if(from1 >= to1 || from2 >= to2)
		return 0;
	int best=0;
	for(int i=from1;i<to1;i++)
	{
		//picking the ith element
		char* loc;
		int score=0;
		//strncpy(temp,seq2+from2,to2-from2);
		loc=strchr(seq2,seq1[i]);
		while(loc!=NULL && loc-seq2<from2)
			loc=strchr(loc+1,seq1[i]);
		if(loc !=NULL)
		{
			//take care of joker later.
			score+=values[seq1[i]];
			score+=solve(from1,i,from2,loc-seq2);
			score+=solve(i+1,to1,loc-seq2+1,to2);
			if(score>best)
				best=score;
		}
		if(seq1[i]=='R' && loc==NULL)
		{
			int tmp=0;
			for(int j=from2;j<to2;j++)
				if(values[seq2[j]]>tmp)
				{
					tmp=values[seq2[j]];
					loc=seq2+j;
				}
			//take care of joker later.
			score+=values[seq1[i]];
			score+=solve(from1,i,from2,loc-seq2);
			score+=solve(i+1,to1,loc-seq2+1,to2);
			if(score>best)
				best=score;
		}
	}
	return best;
}



int main() 
{
	for(int i=2;i<=9;i++)
		values['0'+i]=i;
	values['T']=10;
	values['A']=20;
	values['J']=15;
	values['Q']=15;
	values['K']=15;
	values['R']=50; //careful about joker they are excpetional case.

	while(true)
	{
		memset(seq1,0,sizeof(seq1));
		memset(seq2,0,sizeof(seq2));
		//int N;
		cin>>N;
		if(N==0)
			break;
		for(int i=0;i<N;i++)
		{
			cin>>seq1[i];
		}
		for(int i=0;i<N;i++)
		{
			cin>>seq2[i];
		}

		int best=0;
		for(int i=0;i<N;i++)
		{
			//picking the ith element
			char* loc;
			int score=0;
			if((loc=strchr(seq2,seq1[i])) !=NULL)
			{
				//take care of joker later.
				score+=values[seq1[i]];
				score+=solve(0,i,0,loc-seq2);
				score+=solve(i+1,N,loc-seq2+1,N);
				if(score>best)
					best=score;
			}
		}

		cout<<best<<endl;;
	}//tc

    return 0;
}
