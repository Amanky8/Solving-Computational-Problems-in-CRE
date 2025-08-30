#include<bits/stdc++.h>
using namespace std;
long double k1,k2; 
long double f1(long double t0,long double A0,long double B0, long double C0){
    return (-1)*k1*A0;
}
long double f2(long double t0,long double A0,long double B0, long double C0){
    return k1*A0 - k2*B0;
}
long double f3(long double t0,long double A0,long double B0, long double C0){
     return k2*B0;
}
int main()
{   //For Series reaction.
    cout<<"Kindly enter the time(1 digit decimal precision):";
    long double t;
    cin>>t;
    cout<<"Enter initial conditions as well:";
    long double A0,B0,C0,t0;
    cout<<"Enter initial Ca0:";
    cin>>A0;
    cout<<"Enter intial Cb0:";
    cin>>B0;
    cout<<"Enter initial Cc0:";
    cin>>C0;
    cout<<"Enter initial time:";
    cin>>t0;

    // long double k1,k2; 
    cout<<"Enter k1 and k2:";
    cin>>k1>>k2;

 
    float h=0.1;
    // long double t0=0;

    while(t0<t){
        long double k1=h*f1(t0,A0,B0,C0);
        long double l1=h*f2(t0,A0,B0,C0);
        long double m1=h*f3(t0,A0,B0,C0);
        long double k2= h*f1(t0+h/2,A0+k1/2,B0+l1/2,C0+m1/2);
        long double l2= h*f2(t0+h/2,A0+k1/2,B0+l1/2,C0+m1/2);
        long double m2= h*f3(t0+h/2,A0+k1/2,B0+l1/2,C0+m1/2);
        long double k3= h*f1(t0+h/2,A0+k2/2,B0+l2/2,C0+m2/2);
        long double l3= h*f2(t0+h/2,A0+k2/2,B0+l2/2,C0+m2/2);
        long double m3= h*f3(t0+h/2,A0+k2/2,B0+l2/2,C0+m2/2);

        long double k4=h*f1(t0+h,A0+k3,B0+l3,C0+m3);
        long double l4=h*f2(t0+h,A0+k3,B0+l3,C0+m3);
        long double m4=h*f3(t0+h,A0+k3,B0+l3,C0+m3);

        long double A1=A0+1.0/6.0*(k1+2*k2+2*k3+k4);
        long double B1=B0+1.0/6.0*(l1+2*l2+2*l3+l4);
        long double C1=C0+1.0/6.0*(m1+2*m2+2*m3+m4);

        t0+=h;
        A0=A1;
        B0=B1;
        C0=C1;
        cout<<"A="<<A0<<"  "<<"B="<<B0<<"  "<<"C="<<C0<<"  "<<"at time="<<t<<"sec"<<endl;
        
    }
    cout<<"A="<<A0<<endl<<"B="<<B0<<endl<<"C="<<C0<<endl<<"at time="<<t<<"sec";

    return 0;
}