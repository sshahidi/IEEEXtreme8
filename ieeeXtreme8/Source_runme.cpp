#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;
#define MAX_SIZE 1001
int flag=0;

char mget(char ch)
{
	char res=-1;
	switch(ch)
		{
			case '0':
				res=0; 
			break;
			case '1':
				res=1; 
			break;
			case '2':
				res=2; 
			break;
			case '3':
				res=3; 
			break;
			case '4':
				res=4; 
			break;
			case '5':
				res=5; 
			break;
			case '6':
				res=6; 
			break;
			case '7':
				res=7; 
			break;
			case '8':
				res=8; 
			break;
			case '9':
				res=9; 
			break;
			case 'A':
				res=10; 
			break;
			case 'B':
				res=11; 
			break;
			case 'C':
				res=12; 
			break;
			case 'D':
				res=13; 
			break;
			case 'E':
				res=14; 
			break;
			case 'F':
				res=15; 
			break;
		}
	if(res==-1)
		flag=1;
	return res;
}


int main()
{

	 char str[101];
    cin>>str;
    int len=strlen(str)-1;
    cout<<(len/10)%10<<len%10<<endl;

///////////////////////////////////////////////////////////
	/*char ch1,ch2;
	int cnt=0;
	char res[10000];
	while(!cin.eof())
	{
		cin>>ch1>>ch2;
		char a=mget(ch1);
		char b=mget(ch2);
		if(flag==1)
			break;
		res[cnt]= mget(ch1)<<4 | mget(ch2);
		cout<<(int)res[cnt]<<" ";
		cnt++;
	}
	cout<<"\ndone. writing to file:"<<cnt<<endl;
	 ofstream fout;
	fout.open ("res.txt");
	//fout.open("res.txt","w");
	for(int i=0;i<cnt;i++)
	{
		fout<<res[i];
	}
	fout.close();*/
	return 0;
}