#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
void cmplx(double Re,double Im,double* fi,double* r,double* kreistg,double n)
{
   if((Re>0)&&(Im>0))//1.Quadrant
   {
      *fi=atan(Im/Re)*(180/M_PI);
   }
   if((Re<0)&&(Im>0))//2.Quadrant
   {
      *fi=(atan(Im/Re)*(180/M_PI))+180;
   }
   if((Re<0)&&(Im<0))//3.Quadrant
   {
      *fi=(atan(Im/Re)*(180/M_PI))+180;
   }
   if((Re>0)&&(Im<0))//4.Quadrant
   {
      *fi=(atan(Im/Re)*(180/M_PI))+360;
   }
   *r=sqrt(pow(Re,2)+pow(Im,2));
   *r=pow(*r,(1/n));
   *kreistg=360/n;

}
int main()
{
   double Re,Im,n,r,fi,kreistg,wkl,ergcos,ergsin;
   int k=0,x=1,i;

   printf("\t\t\tKomplexes Wurzelziehen\n");
   printf("\t\t\t**********************\n\n");

   printf("Exponent: ");
   scanf("%lf",&n);
   printf("Realteil: ");
   scanf("%lf",&Re);
   printf("Imaginärteil: ");
   scanf("%lf",&Im);

   cmplx(Re,Im,&fi,&r,&kreistg,n);

   printf("\t\t%.0lffi=%.2lf",n,fi);
   fi=fi/n;

   printf("\nr=%.3lf ",r);
   printf("\tfi=%.2lf ",fi);
   printf("\tKreisteilung=%.2lf \n\n\n",kreistg);
   wkl=fi;

   for(i=0;i<=n;i++)
   {
      ergsin=r*sin(wkl*(M_PI/180));
      ergcos=r*cos(wkl*(M_PI/180));
      printf("k=%d x%d=  %.3lf*(cos%.3lf + jsin%.3lf)= %.3lf  %.3lfj\n",k++,x++,r,wkl,wkl,ergcos,ergsin);
      wkl=fi+(k*(360/n));
      Sleep(200);
   }
   system("\n\nPAUSE");
   return 0;
}


