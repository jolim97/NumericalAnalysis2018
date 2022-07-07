#include<stdio.h>
#include<math.h>
double func(double t)
{
	return pow(2-t,2)+(2-t)*sin(pow(t,1.5));
}
int main()
{
	double a=0,b=20;
	int i,j,k;
	double Integral[30]={0};
	for(i=1;i<=30;i++)
	{
		int n=pow(2,i)+1;
		double h=(b-a)/pow(2,i);
		double t[n]={0};
		double I[n]={0};
		double R[n]={0};
		double V[n]={0};
		for(j=0;j<=pow(2,i);j++)
		{
			t[j]=a+h*j;
			I[j]=func(t[j]);
			R[j]=I[j]+5;
			V[j]=I[j]*R[j];
		}
		for(k=0;k<=pow(2,i-1)-1;k++)
		{
			Integral[i-1]=Integral[i-1]+h/3*(V[2*k]+4*V[2*k+1]+V[2*(k+1)]);
		}
		printf("%d %lf\n",i,Integral[i-1]);
		if(i!=1)
		{
			if(fabs((Integral[i-1]-Integral[i-2])/Integral[i-1])<0.0005) break;
		}
		
	}
	printf("Average Voltage = %lf",Integral[i-1]/20);
}
