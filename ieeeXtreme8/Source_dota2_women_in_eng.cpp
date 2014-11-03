#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;
#define MAX_SIZE 50001

class Hero
{
public:
	char name[30];
	char type;
	int win;
	int loss;
	double rate;
	double score;
};

int comp(const void* a,const void* b)
{
	Hero* c= (Hero*)a;
	Hero* d= (Hero*)b;
	return (int)(-c->score + d->score);
}

Hero heros[MAX_SIZE];

int main()
{
	int N,M;
	cin>>N>>M;

	char alaki[5];
	cin.getline(alaki,2);
	for(int i=0;i<N;i++)
	{
		char type[20];
		char str[120];
		memset(str,0,sizeof(str));
		//scanf("%s,%s,%d:%d",heros[i].name,type,&heros[i].win,&heros[i].loss);
		cin.getline(str,120);
		char temp[120];
		strcpy(temp,str);
		strtok(str,",");
		strcpy(heros[i].name,str);
		
		char temp2[120];
		strcpy(temp2,temp+strlen(str)+1);
		strtok(temp2,",");
		//strcpy(type,temp,temp-temp2);
		heros[i].type=temp2[0];//type[0];

		//temp=temp2;
		//char* temp2= strtok(temp," ,:\r\n\t");
		strcpy(temp,temp+strlen(str)+strlen(temp2)+2);
		sscanf(temp,"%d:%d",&heros[i].win,&heros[i].loss);
		 
		heros[i].rate=(int)((100*(double)heros[i].win)/((double)(heros[i].win+heros[i].loss)));
		heros[i].score=heros[i].rate*(i+1);
	}

	qsort(heros,N,sizeof(Hero),comp);
	int types[26];
	types['I'-'A']=types['A'-'A']=types['S'-'A']=0;
	for(int i=0;i<M;i++)
	{
		cout<<heros[i].name<<endl;
		types[heros[i].type-'A']++;
	}
	cout<<endl;
	printf("This set of heroes:\n");
	printf("Contains %.2f percentage of Intelligence\n",100*((double)types['I'-'A']/(double)M));
	printf("Contains %.2f percentage of Strength\n",100*((double)types['S'-'A']/(double)M));
	printf("Contains %.2f percentage of Agility\n",100*((double)types['A'-'A']/(double)M));
	return 0;
}