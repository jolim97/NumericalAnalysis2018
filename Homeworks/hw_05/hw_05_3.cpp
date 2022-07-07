#include <stdio.h>
#include <math.h>
double func(double x)
{
	return exp(-10*x*x);
}
int main()
{
	int i,j;
	int n=20;
	int p=pow(2,n);
	double a=0,b=2;
	double I[n][p]={0};
	for(i=1;i<=n;i++)
	{ 
		int N=pow(2,i);
		double h=(b-a)/N;
		double x[N+1]={0};
		double f[N+1]={0};
		for(j=0;j<=N;j++)
		{
			x[j]=a+h*j;
			f[j]=func(x[j]);
		}
		for(j=k;j<=N/2-1;j++)
		{
			I[i-1][j]=h/3*(f[2*j]+4*f[2*j+1]+f[2*(j+1)]);
		}
	}
	
}
