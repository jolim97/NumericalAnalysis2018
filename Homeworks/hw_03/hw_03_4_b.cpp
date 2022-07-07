#include<stdio.h>
#include<math.h>
int main()
{
	double a[3][3]={{10,-3,6},{1,8,-2},{-2,4,-9}};
	double b[3]={24.5,-10,-50};
	double x[3]={0};
	double X[3]={0};
	double error=0.5/pow(10,5);
	int i;
	for(i=1;i<=20;i++)
	{
		X[0]=(b[0]-a[0][1]*x[1]-a[0][2]*x[2])/a[0][0];
		X[1]=(b[1]-a[1][0]*X[0]-a[1][2]*x[2])/a[1][1];
		X[2]=(b[2]-a[2][0]*X[0]-a[2][1]*X[1])/a[2][2];
		printf("%d x1=%lf	x2=%lf	x3=%lf\n",i,X[0],X[1],X[2]);
		double e1,e2,e3;
		e1=fabs((X[0]-x[0])/X[0]);
		e2=fabs((X[1]-x[1])/X[1]);
		e3=fabs((X[2]-x[2])/X[2]);
		printf("error1=%.5lf	error2=%.5lf	error3=%.5lf\n",e1,e2,e3);
		if(i!=1)
		{
			if(e1<error&&e2<error&&e3<error) break;
		}
		x[0]=X[0]; x[1]=X[1]; x[2]=X[2];
	}
}
