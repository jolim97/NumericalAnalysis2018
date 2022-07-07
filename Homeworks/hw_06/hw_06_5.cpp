#include <stdio.h>
#include <math.h>
int main()
{
	int i;
	int a=0;
	int b=10;
	double h=0.05;
	int n=(b-a)/h;
	double y1[n+1];
	double y2[n+1];
	double c=38.916;
	y1[0]=M_PI/4;
	y2[0]=0;
	double t[n+1]={0};
	t[0]=a;
	double k11,k21,k31,k41,k12,k22,k32,k42;
	for(i=1;i<=n;i++)
	{
		t[i]=a+i*h;
		
		k11=y2[i-1];
		k12=-c*y1[i-1];
		
		k21=y2[i-1]+h/2*k12;
		k22=-c*(y1[i-1]+h/2*k11);
		
		k31=y2[i-1]+h/2*k22;
		k32=-c*(y1[i-1]+h/2*k21);
		
		k41=y2[i-1]+h*k32;
		k42=-c*(y1[i-1]+h*k31);
		
		y1[i]=y1[i-1]+h/6*(k11+2*(k21+k31)+k41);
		y2[i]=y2[i-1]+h/6*(k12+2*(k22+k32)+k42);
		printf("%lf	%lf\n",t[i],y1[i]);
	}
	FILE* data=fopen("HW06_5.csv","w+");
	fprintf(data,"t,theta\n");
	for(i=0;i<=n;i++)
	{
		fprintf(data,"%lf,%lf\n",t[i],y1[i]);
	}
	fclose(data);
}
