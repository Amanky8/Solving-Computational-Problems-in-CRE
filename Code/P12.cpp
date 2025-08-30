#include <bits/stdc++.h>
using namespace std;
long double f1( long double V, long double Fa, long double Fb){
    return (-1)*1000*Fa/(2494.2*(8.02-Fa));
}
long double f2(long double V, long double Fa, long double Fb){
    return 2000*Fa/(2494.2*(8.02-Fa));
}

int main(){
    // Fa0 is taken as 4.01 mol/s, T as 300 K and P as 1 bar.
    // Reactor volume is 10 cubic metres.
    long double V=10,Fa0=4.01,Fb0=0;
    long double K=0.01; 
    float h=0.01;

    long double V0=0; //initial value
    while(V0<=V){
    long double K1=h*f1(V0,Fa0,Fb0);
    long double L1=h*f2(V0,Fa0,Fb0);

    long double K2=h*f1(V0+h/2, Fa0+K1/2, Fb0+L1/2);
    long double L2=h*f2(V0+h/2, Fa0+K1/2, Fb0+L1/2);

    long double K3=h*f1(V0+h/2, Fa0+K2/2, Fb0+L2/2 );
    long double L3=h*f2(V0+h/2, Fa0+K2/2, Fb0+L2/2 );

    long double K4=h*f1(V0+h, Fa0+K3, Fb0+L3);
    long double L4=h*f2(V0+h, Fa0+K3, Fb0+L3);

    long double Fa=Fa0+1.0/6.0*(K1+2*K2+2*K3+K4);
    long double Fb=Fb0+1.0/6.0*(L1+2*L2+2*L3+L4);

    V0=V0+h;
    Fa0=Fa; Fb0=Fb;

    }
    
    cout<<"Fa = "<<Fa0<<"\n"<<"Fb = "<<Fb0;
    return 0;
}