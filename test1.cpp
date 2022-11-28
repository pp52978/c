#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <assert.h>
using namespace std;
int * getPolynomial (int num);
void setPolyCoef(int *pt, int maxval);
void releaseMem(int *pt);
void printPolynomial (int *pt );
double polynomialVal (int *pt, double x);
int *polynomialAdd (int *pt1, int *pt2);
int main()
{
int *p1, *p2, *p3, num1=7, num2=5;
int maxval =50;
p1= getPolynomial(num1);
setPolyCoef(p1, maxval);
for(int i=0;i<=7;i++)
cout<<*(p1+i);
/*printPolynomial (p1);
int x=1.2;
cout << "the polynomial p1’s value when x = " << x << " is: " << polynomialVal (p1, x) << endl;
p2= getPolynomial(num2);
setPolyCoef(p2, maxval);
printPolynomial (p2);
p3 = polynomialAdd (p1, p2);
printPolynomial (p2);
cout << "the polynomial p3’s value when x = " << x << " is: " << polynomialVal (p3, x) <<endl;
releaseMem(p1);
releaseMem(p2);*/
return 0;
}
int * getPolynomial (int num)
{
 int *p;
 p=new int[num+2];
 *p=num;
 return p;
}
void setPolyCoef(int *pt, int maxval)
{
   for(int i=1;i<=*pt+2;i++)

        *(pt+i)=rand()%(maxval-1);

}
/*void releaseMem(int *pt)
{
   delete pt;
}
void printPolynomial (int *pt )
{
  if(*pt==0)
    cout<< *(pt+1);
  else if(*pt==1)
  cout<<*(pt+*pt+1)<<"x^"<<*pt<<"+"<<*(pt+1);
  else
    printPolynomial(*pt)+printPolynomial(*pt-1);

}
double polynomialVal (int *pt, double x)
{

}
int *polynomialAdd (int *pt1, int *pt2)
{

}
