#include<stdio.h>
#include<math.h>
float f(float x);
void_main(void)
{
	FILE*out;
	fopen_s(&out,"result.txt","wt");
	double k=5;
	double i, error, old, e;
	double n=1;
	error=0.5/pow(10,k);
	for(i=1;i<=20;i++)
	{
		e=pow(1+1/n,n);
		if(1!=1);
		{
			if(fabs(e-old)<error) break;
		}
		old=e;
		fprintf(out,"n=%f,e=%f/n",n,e);
		n=n*10;
	}
}
float f(float x)
{
	return exp(x);
}
