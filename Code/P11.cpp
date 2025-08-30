#include<bits/stdc++.h>
using namespace std;
long double k1,k2,v; 
long double f1(long double x0,long double A0,long double B0, long double C0){
    return (-1)*k1*A0/v;
}
long double f2(long double x0,long double A0,long double B0, long double C0){
    return (k1*A0 - k2*B0)/v;
}
long double f3(long double x0,long double A0,long double B0, long double C0){
     return k2*B0/v;
}
int main()
{   //For Series reaction.
    long double A0,B0,C0,x0,x;
    cout<<"Enter initial Ca0:";
    cin>>A0;
    cout<<"Enter intial Cb0:";
    cin>>B0;
    cout<<"Enter initial Cc0:";
    cin>>C0;
    cout<<"Enter Starting Length of PFR :";
    cin>>x0;
    cout<<"Enter Length of PFR :";
    cin>>x;
    cout<<"Enter the Mean Axial Velocity : ";
    cin>>v;

    cout<<"Enter k1 and k2:";
    cin>>k1>>k2;

 
    float h=0.01;

    while(x0<x){
        long double k1=h*f1(x0,A0,B0,C0);
        long double l1=h*f2(x0,A0,B0,C0);
        long double m1=h*f3(x0,A0,B0,C0);

        long double k2= h*f1(x0+h/2,A0+k1/2,B0+l1/2,C0+m1/2);
        long double l2= h*f2(x0+h/2,A0+k1/2,B0+l1/2,C0+m1/2);
        long double m2= h*f3(x0+h/2,A0+k1/2,B0+l1/2,C0+m1/2);

        long double k3= h*f1(x0+h/2,A0+k2/2,B0+l2/2,C0+m2/2);
        long double l3= h*f2(x0+h/2,A0+k2/2,B0+l2/2,C0+m2/2);
        long double m3= h*f3(x0+h/2,A0+k2/2,B0+l2/2,C0+m2/2);

        long double k4=h*f1(x0+h,A0+k3,B0+l3,C0+m3);
        long double l4=h*f2(x0+h,A0+k3,B0+l3,C0+m3);
        long double m4=h*f3(x0+h,A0+k3,B0+l3,C0+m3);

        long double A1=A0+1.0/6.0*(k1+2*k2+2*k3+k4);
        long double B1=B0+1.0/6.0*(l1+2*l2+2*l3+l4);
        long double C1=C0+1.0/6.0*(m1+2*m2+2*m3+m4);

        //x0+=h;
        A0=A1;
        B0=B1;
        C0=C1;
        cout<<"A="<<A0<<"  "<<"B="<<B0<<"  "<<"C="<<C0<<"  "<<"at length = "<<x0<<"meter"<<endl;
        x0+=h;
        
    }
    cout<<"A="<<A0<<endl<<"B="<<B0<<endl<<"C="<<C0<<endl<<"at length = "<<x<<"meter";

    return 0;
}