#include <stdio.h>
#include <math.h>

int main()
{
	int a=0;
	int b=5;
	int i;
	double h=0.01;
	int n=(b-a)/h;
	
	double y1[n+1]={0};//x
	double y2[n+1]={0};//y
	y1[0]=-1;	y2[0]=(double)5/(double)4;
	//Predictor
	double y1p[n]={0};
	double y2p[n]={0};
	//Corrector
	double y1c[n]={0};
	double y2c[n]={0};
	double f1[n+1]={0};
	double f2[n+1]={0};
	f1[0]=exp(0)-3*y1[0]-4*y2[0];
	f2[0]=y1[0]+y2[0];
	for(i=1;i<=n;i++)
	{
		double t=a+h*i;
		y1p[i-1]=y1[i-1]+h*f1[i-1];
		y2p[i-1]=y2[i-1]+h*f2[i-1];
		f1[i]=exp(t)-3*y1p[i-1]-4*y2p[i-1];
		f2[i]=y1p[i-1]+y2p[i-1];
		y1c[i-1]=y1[i-1]+h/2*(f1[i-1]+f1[i]);
		y2c[i-1]=y2[i-1]+h/2*(f2[i-1]+f2[i]);
		y1[i]=y1c[i-1];
		y2[i]=y2c[i-1];
	}
	FILE*HW06_1 = fopen("HW06_1.csv","w+");
	fprintf(HW06_1,"t,x,y\n");
	for(i=0;i<=n;i++)
	{
		fprintf(HW06_1,"%lf,%lf,%lf\n",a+h*i,y1[i],y2[i]);
	}
	fclose(HW06_1);
}
