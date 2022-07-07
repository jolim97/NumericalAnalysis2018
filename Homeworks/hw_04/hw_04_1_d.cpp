#include<stdio.h>
int main()
{
	int i,j;
	double x=0.7;
	double v[4]={0.0,0.3,0.6,1.0};//variable
	double value[4]={0.0000,0.5477,0.7746,1.0000};
	double L[4]={1,1,1,1};
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=i-1;j++)
		{
			L[i]=L[i]*(x-v[j])/(v[i]-v[j]);
		}
		for(j=i+1;j<=3;j++)
		{
			L[i]=L[i]*(x-v[j])/(v[i]-v[j]);
		}
	}
	double F=0;
	for(i=0;i<=3;i++)
	{
		F=F+L[i]*value[i];
	}
	printf("%lf",F);
	double a[4]={value[0],value[1],value[2],value[3]};//nominator
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=i-1;j++)
		{
			a[i]=a[i]/(v[i]-v[j]);
		}
		for(j=i+1;j<=3;j++)
		{
			a[i]=a[i]/(v[i]-v[j]);
		}
	}
	double b[4][4]={0};//ab,ac,ad,bc,bd,cd
	for(i=0;i<=2;i++)
	{
		for(j=i+1;j<=3;j++)
		{
			b[i][j]=v[i]*v[j];
		}
	}
	double c[4]={1,1,1,1};//abc,abd,acd,bcd
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=i-1;j++)
		{
			c[i]=c[i]*v[j];
		}
		for(j=i+1;j<=3;j++)
		{
			c[i]=c[i]*v[j];
		}
	}
	double A,B,C,D;//Coefficients of polynomial
	A=0;B=0; D=0;
	for(i=0;i<=3;i++)
	{
		A=A+a[i];
		B=B-(v[0]+v[1]+v[2]+v[3]-v[i])*a[i];
		D=D-c[i]*a[i];
	}
	C=a[0]*(b[1][2]+b[1][3]+b[2][3])+a[1]*(b[0][2]+b[0][3]+b[2][3])+a[2]*(b[0][1]+b[0][3]+b[1][3])+a[3]*(b[0][1]+b[0][2]+b[1][2]);
	printf("\n%lf\n%lf\n%lf\n%lf",A,B,C,D);
}
