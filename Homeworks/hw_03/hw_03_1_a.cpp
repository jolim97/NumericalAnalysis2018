#include<stdio.h>
int main()
{
	double A[2][3]={{0.00005,2,1.33335},{3,18,13}};
	double B[2][3];
	int i;
for(i=0;i<=2;i++)
	{
		B[0][i]=A[0][i]*A[1][0]/A[0][0];
	}
	for(i=0;i<=2;i++)
	{
		B[1][i]=B[0][i]-A[1][i];
	}
	double x1,x2;
	x2=B[1][2]/B[1][1];
	x1=(B[0][2]-x2*B[0][1])/B[0][0];
	printf("x1=%lf x2=%lf",x1,x2);
}
