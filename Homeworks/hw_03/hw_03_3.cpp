#include<stdio.h>
int main()
{
	double a=-1,b=3,c=-1;
	double d[6]={100,150,150,150,150,100};
	double p[6]={0}, q[6]={0};
	p[0]=-c/b; q[0]=d[0]/b;
	int i;
	for(i=1;i<=5;i++)
	{
		q[i]=(d[i]-a*q[i-1])/(a*p[i-1]+b);
		if(i==5) break;
		p[i]=-c/(a*p[i-1]+b);
	}
	double x[6];
	x[5]=q[5];
	for(i=4;i>=0;i--)
	{
		x[i]=p[i]*x[i+1]+q[i];
	}
	printf("x= ");
	for(i=0;i<=5;i++)
	{
		printf("%lf	",x[i]);
	}
	printf("\np= ");
	for(i=0;i<=5;i++)
	{
		printf("%lf	",p[i]);
	}
	printf("\nq= ");
	for(i=0;i<=5;i++)
	{
		printf("%lf	",q[i]);
	}
}
