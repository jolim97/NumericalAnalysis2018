#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
	int i,j,k;
	j=4+2;  //order+2
	double A[5]={1,-10,35,-50,24}; //coefficient
	double r=-A[1]/A[0] , s=-A[2]/A[0]; //Larger root
	double B[7], C[7];
	B[0]=0,B[1]=0,C[0]=0,C[1]=0;
	double error=0.5/pow(10,4);
	clock_t start,end;
	start=clock();
	for(i=1;i<=50;i++)
	{
		for(k=2;k<=7;k++)
		{
			B[k]=A[k-2]+r*B[k-1]+s*B[k-2];
			C[k]=B[k]+r*C[k-1]+s*C[k-2];
			//printf("b%d=%lf	c%d=%lf\n",k-1,B[k],k-1,C[k]);
		}
		double dr,ds;
		dr=(B[j]*C[j-1]-B[j+1]*C[j-2])/(C[j]*C[j-2]-C[j-1]*C[j-1]);
		ds=(B[j+1]*C[j-1]-B[j]*C[j])/(C[j]*C[j-2]-C[j-1]*C[j-1]);
		printf("r=%lf	s=%lf	error(r)=%lf	error(s)=%lf\n",r,s,fabs(dr/r),fabs(ds/s));
		if(fabs(dr/r)<error&&fabs(ds/s)<error) break;
		r=r+dr;	s=s+ds;
	}
	double x1,x2,x3,x4;
	x1=(r+pow(r*r+4*s,0.5))/2;
	x2=(r-pow(r*r+4*s,0.5))/2;
	x3=(-B[3]+pow(B[3]*B[3]-4*B[2]*B[4],0.5))/(2*B[2]);
	x4=(-B[3]-pow(B[3]*B[3]-4*B[2]*B[4],0.5))/(2*B[2]);
	printf("x1=%.4lf	x2=%.4lf	x3=%.4lf	x4=%.4lf\n",x1,x2,x3,x4);
	end=clock();
	printf("%lfseconds",(double)(end-start)/CLOCKS_PER_SEC);
}
