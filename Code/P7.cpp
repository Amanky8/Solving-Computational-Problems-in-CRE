#include <bits/stdc++.h>
using namespace std;
long double k1=0.01,k2=0.005;
long double Ft;
long double f1(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    Ft=Fa+Fb+Fc+Fd;
    return (-1)*k1*(1607.4499)*Fa*Fb/(Ft*Ft);
}
long double f2(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    Ft=Fa+Fb+Fc+Fd;
    return (-1)*k1*1607.4499*Fa*Fb/(Ft*Ft) - k2*1607.4499*Fb*Fc/(Ft*Ft);
}
long double f3(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    Ft=Fa+Fb+Fc+Fd;
     return k1*1607.4499*Fa*Fb/(Ft*Ft)-k2*1607.4499*Fb*Fc/(Ft*Ft);
}
long double f4(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    Ft=Fa+Fb+Fc+Fd;
    return k2*1607.4499*Fb*Fc/(Ft*Ft);
}

int main(){
    //For Parallel reaction.
    cout<<"The reactions are:"<<endl<<"A + B ----> C (K1) \nB + C ----> D (K2)\n";
    
    
    
    long double Fa,Fb,Fc,Fd,V;
    Fa=4; Fb=4; Fc=0; Fd=0; 
    V=0;
    

    

    float h=0.01;
    // long double V=0;

    while(V<9.99){
        //=Fa+Fb+Fc+Fd;

        long double k1=h*f1(V,Fa,Fb,Fc,Fd);
        long double l1=h*f2(V,Fa,Fb,Fc,Fd);
        long double m1=h*f3(V,Fa,Fb,Fc,Fd);
        long double n1=h*f4(V,Fa,Fb,Fc,Fd);

        // Ft=Fa+k1/2 + Fb +l1/2 + Fc+m1/2 + Fd+n1/2;

        long double k2= h*f1(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);
        long double l2= h*f2(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);
        long double m2= h*f3(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);
        long double n2= h*f4(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);

        // Ft=Fa+k2/2 + Fb +l2/2 + Fc+m2/2 + Fd+n2/2;

        long double k3= h*f1(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);
        long double l3= h*f2(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);
        long double m3= h*f3(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);
        long double n3= h*f4(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);

        // Ft=Fa+Fb+Fc+Fd + k3+l3+m3+n3;

        long double k4=h*f1(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);
        long double l4=h*f2(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);
        long double m4=h*f3(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);
        long double n4=h*f4(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);

        long double A1=Fa+1.0/6.0*(k1+2*k2+2*k3+k4);
        long double B1=Fb+1.0/6.0*(l1+2*l2+2*l3+l4);
        long double C1=Fc+1.0/6.0*(m1+2*m2+2*m3+m4);
        long double D1=Fd+1.0/6.0*(n1+2*n2+2*n3+n4);

      

        V+=h;
        Fa=A1;
        Fb=B1;
        Fc=C1;
        Fd=D1;
    }
    cout<<"Fa="<<Fa<<endl<<"Fb="<<Fb<<endl<<"Fc="<<Fc<<endl<<"Fd="<<Fd<<" "<<"at V="<<V<<"cubic metres.";

    return 0;

}