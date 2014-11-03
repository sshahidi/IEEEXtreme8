#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 1001

int rule_tab[8];

unsigned long long rev(unsigned long long num,int bits)
{
    if (num==0)
        return 0;
    unsigned long long res=0;
    int cnt=0;
    while(num>0)
    {
        cnt++;
        res=res*2 + num%2;
        num/=2;
    }
    res=res<<(bits-cnt);
    return res;
}

void printState(unsigned long long state,int bits)
{
	state=rev(state,bits);
	cout<<'-';
	for(int i=0;i<bits;i++)
	{
		if( (state>>i)%2 ==0)
		{
			cout<<' ';
		}
		else
			cout<<'*';
	}
	cout<<'-';
}





unsigned long long calcState(unsigned long long pre_state,int bits)
{
	unsigned long long res=0;
	res=res*2 + rule_tab[((pre_state<<1)%8)];
	//res=res*2 + rule_tab[((pre_state>>0)%8)];
	for(int i=0;i<bits-1;i++)
	{
		res = res*2 + rule_tab[((pre_state>>i)%8)];
	}
	return rev(res,bits);
}

int main()
{
	int rule,max_itr,len;
	unsigned long long init;
	cin>>rule>>max_itr>>len>>init;
	
	//true=1, false =0
	for(int i=0;i<7;i++)
	{
		rule_tab[i]= (rule>>i)%2;
	}

	
	unsigned long long pre_state=init;

	for(int itr=1; itr<=max_itr; itr++)
	{
		printf("%-4d",itr);
		printState(pre_state,len);
		cout<<endl;
		unsigned long long state=calcState(pre_state,len);
		if (pre_state==state)
			break;
		pre_state=state;
	}



	
	return 0;
}