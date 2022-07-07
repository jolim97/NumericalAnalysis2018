#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
	int i,j,k;
	j=5+1;  //order+1
	double A[6]={1,-17,124,-508,1035,-875}; //coefficient
	double r=-A[1]/A[0] , s=-A[2]/A[0]; //Larger root
	double B[8], C[8];
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
		}
		double dr,ds;
		dr=(B[j]*C[j-1]-B[j+1]*C[j-2])/(C[j]*C[j-2]-C[j-1]*C[j-1]);
		ds=(B[j+1]*C[j-1]-B[j]*C[j])/(C[j]*C[j-2]-C[j-1]*C[j-1]);
		printf("r=%lf	s=%lf	error(r)=%lf	error(s)=%lf\n",r,s,fabs(dr/r),fabs(ds/s));
		if(fabs(dr/r)<error&&fabs(ds/s)<error) break;
		r=r+dr;	s=s+ds;
	}
	double D[4]={B[2],B[3],B[4],B[5]};
	double E[6],F[6];
	E[0]=0, E[1]=0, F[0]=0, F[1]=0;
	double t=-D[2]/D[1] , u=-D[3]/D[1];//Smaller root
	for(i=1;i<=50;i++)
	{
		for(k=2;k<=5;k++)
		{
			E[k]=D[k-2]+t*E[k-1]+u*E[k-2];
			F[k]=E[k]+t*F[k-1]+u*F[k-2];
		}
		double dt,du;
		dt=(E[j-2]*F[j-3]-E[j-1]*F[j-4])/(F[j-2]*F[j-4]-F[j-3]*F[j-3]);
		du=(E[j-1]*F[j-3]-E[j-2]*F[j-2])/(F[j-2]*F[j-4]-F[j-3]*F[j-3]);
		printf("t=%lf	u=%lf	error(t)=%lf	error(u)=%lf\n",t,u,fabs(dt/t),fabs(du/u));
		if(fabs(dt/t)<error&&fabs(du/u)<error) break;
		t=t+dt; u=u+du;
	}
	double x1,x2,x3,x4,x5;
	x1=(r+pow(r*r+4*s,0.5))/2;
	x2=(r-pow(r*r+4*s,0.5))/2;
	x3=(t+pow(t*t+4*u,0.5))/2;
	x4=(t-pow(t*t+4*u,0.5))/2;
	x5=-E[3]/E[2];
	printf("x1=%lf	x2=%lf	x3=%lf	x4=%lf	x5=%lf\n",x1,x2,x3,x4,x5);
	end=clock();
	printf("%lfseconds",(double)(end-start)/CLOCKS_PER_SEC);
}
