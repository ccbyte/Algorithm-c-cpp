/*最大子序列和-穷举法-O(n3)*/
#include "stdio.h"
#include "clock.h"

void subSequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, i, j, k;
	MaxSum = 0;
	for( i=0; i < N; i++)
		for( j=i;j < N; j++)
		{
			ThisSum = 0;
			for(k=i; k<=j; k++)
				ThisSum += A[ k ];

			if(ThisSum > maxSum)
				MaxSum = ThisSum;
		}
	return MaxSum;
}

int main()
{
	int A[99];
	int x;
	clock_t a,b;
	a = clock();
	while(scanf("%d",&x) != EOF)
	{
		
	}
	subSequenceSum(A[],)
	{
	}
	b = clock();
}