#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <sstream>
using namespace std;
#define MAX_LINES 1000

char str[MAX_LINES][20];

int main()
{
	map<char*,int> labels;
    int N,M,K;
	//cin>>N>>M>>K;

	int lines=0;
	cin.getline(str[i],20);
	while(!cin.eof())
	{
		lines++;
		cin.getline(str[i],20);
	}
	
	//cout<<"processing..."<<endl;
	int current_line=0;

	while(current_line<lines);
	{
		char command[10];
		sscanf(str[current_line],"%s",command);

		if(!strcmp(command,"PRINT"))
		{
			stringstream sin(str[current_line]);

		}
		else if(!strcmp(command,"MOVE"))
		{
		}
		else if(!strcmp(command,"ADD"))
		{
		}
		else if(!strcmp(command,"SUB"))
		{
		}
		else if(!strcmp(command,"AND"))
		{
		}
		else if(!strcmp(command,"OR"))
		{
		}
		else if(!strcmp(command,"XOR"))
		{
		}
		else if(!strcmp(command,"COMP"))
		{
		}
		else if(!strcmp(command,"BEQ"))
		{
		}
		else if(!strcmp(command,"BNE"))
		{
		}
		else if(!strcmp(command,"BGT"))
		{
		}
		else if(!strcmp(command,"BLT"))
		{
		}
		else if(!strcmp(command,"BGE"))
		{
		}
		else if(!strcmp(command,"BLE"))
		{
		}
		else
		{
			labels[command]=current_line;
			strcpy(str[current_line],str[current_line+strlen(command)+1]); //carfull, i throw away tye label here since I saved it in the map. this hopefully won't cause problem
		}

		//current_line++;
	}
	

	return 0;
}