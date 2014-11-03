#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 1001

// A simple print function
void print(int *input)
{
    for ( int i = 0; i < 5; i++ )
        cout << input[i] << " ";
    cout << endl;
}

int partition(int* input, int p, int r)
{
    int pivot = input[r];
    
    while ( p < r )
    {
        while ( input[p] < pivot )
            p++;
        
        while ( input[r] > pivot )
            r--;
        
        if ( input[p] == input[r] )
            p++;
        else if ( p < r ) {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    
    return r;
}

int quick_select(int* input, int p, int r, int k)
{
    if ( p == r ) return input[p];
    int j = partition(input, p, r);
    int length = j - p + 1;
    if ( length == k ) return input[j];
    else if ( k < length ) return quick_select(input, p, j - 1, k);
    else  return quick_select(input, j + 1, r, k - length);
}

int num[200001];

int main()
{
    int N,M,K;
	cin>>N>>M>>K;

	for (int i=0;i<N;i++)
		cin>>num[i];
	//adding
	for (int i=0;i<M;i++)
		num[N+i]=num[i];
	int min=2147483647;
	int subseq[100001];
	int temp;
	for(int i=0;i<N;i++)
	{
		if(num[i+M-1] > temp && i>0 && num[i-1]>temp)
			continue;
		memcpy(subseq,num+i,sizeof(int)*(M));
		temp=quick_select(subseq,0,M-1,K);
		if(temp<min)
			min=temp;
	}

    //int A5[] = { 100, 400, 300, 500, 200 };
    //cout << "5th order element " << quick_select(A5, 0, 4, 5) << endl;
	cout<<min<<endl;
	return 0;
}