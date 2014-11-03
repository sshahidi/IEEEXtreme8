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
#define MAX_LINES 101

int num[MAX_LINES][MAX_LINES];

void is_optimal(int income[][MAX_LINES],int H,int W, double forush[][MAX_LINES]);

int main()
{
	int W,H;
	cin>>W>>H;
	memset(num,0,sizeof(num));

	for (int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='L')
			{
				num[i][j]=1;
				//j++;
			}
			else if (ch=='-')
			{
				num[i][j]=0;
				//j++;
			}
			else if (ch=='M')
			{
				num[i][j]=2;
				//j++;
			}
			else if (ch=='H')
			{
				num[i][j]=3;
				//j++;
			}
			else if (ch==' ' || ch=='*')
			{
				//do nothing!
				j--;
			}
		}
	}

	double corner[MAX_LINES][MAX_LINES];
    for(int i=0;i<MAX_LINES;i++)
        for(int j=0;j<MAX_LINES;j++)
            corner[i][j]=0;
	//memset(corner,0,sizeof(corner));

	//all days.
	for(int i=0;i<7;i++)
	{
		int income[MAX_LINES][MAX_LINES];
		char day[100];
		if(cin.eof())
			break;
		cin>>day; //we dont need the day

		for(int j=0;j<H;j++)
		{
			for(int k=0;k<W-1;k++)
			{
				scanf("%d*",&income[j][k]);
			}
			scanf("%d*",&income[j][W-1]);
		}

		double temp[MAX_LINES][MAX_LINES];
		is_optimal(income,H,W,temp);
		for (int j=0;j<H;j++)
		{
			for(int k=0;k<W;k++)
				corner[j][k]+=temp[j][k];
		}
	}
	double max=0;
	int max_i=-2,max_j=-2;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
			if(corner[i][j]>max)
			{
				max=corner[i][j];
				max_i=i;
				max_j=j;
			}
	}
	cout<<max_j+1<<" "<<max_i+1;
	//cout<<"hello"<<endl;

	return 0;
}

void is_optimal(int sold[][MAX_LINES],int h,int w, double forush[][MAX_LINES])
{
	int max = 0;
	double profit;
	//double[][] forush = new double[h][w];

	for(int i = 0; i < h; i += 1)
	{
		for(int j = 0; j < w; j += 1)
		{
			profit = sold[i][j];
			if(num[i][j]==3)
				profit=-1000;

			if(i + 1 < h)
			{
				if(sold[i+1][j] > 5 && num[i+1][j] == 3)
				{
					profit += 1;
				}
			}

			if(i - 1 > 0)
			{
				if(sold[i-1][j] > 5 && num[i-1][j] == 3)
				{
					profit += 1;
				}
			}

			if(j + 1 < w)
			{
				if(sold[i][j+1] > 5 && num[i][j+1] == 3)
				{
					profit += 1;
				}
			}

			if(j - 1 > 0)
			{
				if(sold[i][j-1] > 5 && num[i][j-1] == 3)
				{
					profit += 1;
				}
			}

			profit/= (double)(num[i][j]+1);
			
			if(profit > 20)
			{
				forush[i][j] = profit - 20;
			}

			else
			{
				forush[i][j] = 0;
			}
		}
	}

}

