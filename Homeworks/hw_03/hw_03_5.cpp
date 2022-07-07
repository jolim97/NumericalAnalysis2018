#include<stdio.h>
#include<math.h>
int main()
{
	double a[4][4]={{15,2,1,1},{2,10,1,0},{1,1,5,1},{3,1,1,1}};
	double b[4]={27,27,31,13};
	double w=0.99; //or 1
	double x[4]={0,0,0,0};
	double X[4]={0,};
	double error=0.5/pow(10,5);
	int i,j,k;
	for(i=1;i<=200;i++)
	{
		printf("%2d x1=%.4lf  x2=%.4lf  x3=%.4lf  x4=%.4lf\n",i-1,x[0],x[1],x[2],x[3]);
		for(j=0;j<=3;j++)
		{
			X[j]=x[j]+w*b[j]/a[j][j];
			for(k=0;k<=j-1;k++)
			{
				X[j]=X[j]-w*a[j][k]*x[k]/a[j][j];
			}
			for(k=j;k<=3;k++)
			{
				X[j]=X[j]-w*a[j][k]*x[k]/a[j][j];
			}
		}
		double e1,e2,e3,e4;
		e1=fabs((X[0]-x[0])/X[0]);
		e2=fabs((X[1]-x[1])/X[1]);
		e3=fabs((X[2]-x[2])/X[2]);
		e4=fabs((X[3]-x[3])/X[3]);
		if(i!=1)
		{
			if(e1<error&&e2<error&&e3<error&&e4<error) break;
		}
		x[0]=X[0]; x[1]=X[1]; x[2]=X[2]; x[3]=X[3];
	}
}
