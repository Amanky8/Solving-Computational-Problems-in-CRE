#include <iostream>
using namespace std;
long double Fa,Fb,Fc;
long double f1(long double v0, long double Fa, long double Fb, long double Fc, long double Fd ){
    return ((-0.62/1.996569)*((Fa*Fa)-(Fb*Fc/0.31)))-((0.111/1.996569)*((Fa*Fb)-(Fc*Fd/0.111)));
}
long double f2(long double V, long double Fa, long double Fb, long double Fc, long double Fd){
    return ((0.31/1.996569)*((Fa*Fa)-(Fb*Fc/0.31)))-((0.111/1.996569)*((Fa*Fb)-(Fc*Fd/0.111)));
}
long double f3(long double V, long double Fa, long double Fb, long double Fc, long double Fd){
    return ((0.31/1.996569)*((Fa*Fa)-(Fb*Fc/0.31)))+((0.111/1.996569)*((Fa*Fb)-(Fc*Fd/0.111)));
}
long double f4(long double V, long double Fa, long double Fb, long double Fc, long double Fd){
    return ((0.111/1.996569)*((Fa*Fb)-(Fc*Fd/0.111)));
}

int main(){
    // Fa0 is taken as 0.018 mol/s, T as 1033 K and P as 1 atm.
    long double Fa0=16.67,Faf=8.335,Fb0=0,Fc0=0,Fd0=0;
    long double K1=0.31, K2=0.111; 
    long double h=0.000001;

    long double V0=0; //initial value
    while(Fa0>Faf){
        long double K1=h*f1(V0,Fa0,Fb0,Fc0,Fd0);
        long double L1=h*f2(V0,Fa0,Fb0,Fc0,Fd0);
        long double M1=h*f3(V0,Fa0,Fb0,Fc0,Fd0);
        long double N1=h*f4(V0,Fa0,Fb0,Fc0,Fd0);

        long double K2=h*f1(V0+h/2, Fa0+K1/2, Fb0+L1/2, Fc0+M1/2,Fd0+N1/2);
        long double L2=h*f2(V0+h/2, Fa0+K1/2, Fb0+L1/2, Fc0+M1/2,Fd0+N1/2);
        long double M2=h*f3(V0+h/2, Fa0+K1/2, Fb0+L1/2, Fc0+M1/2,Fd0+N1/2);
        long double N2=h*f4(V0+h/2, Fa0+K1/2, Fb0+L1/2, Fc0+M1/2,Fd0+N1/2);

        long double K3=h*f1(V0+h/2, Fa0+K2/2, Fb0+L2/2, Fc0+M2/2,Fd0+N2/2);
        long double L3=h*f2(V0+h/2, Fa0+K2/2, Fb0+L2/2, Fc0+M2/2,Fd0+N2/2);
        long double M3=h*f3(V0+h/2, Fa0+K2/2, Fb0+L2/2, Fc0+M2/2,Fd0+N2/2);
        long double N3=h*f4(V0+h/2, Fa0+K2/2, Fb0+L2/2, Fc0+M2/2,Fd0+N2/2);

        long double K4=h*f1(V0+h, Fa0+K3, Fb0+L3, Fc0+M3,Fd0+N3);
        long double L4=h*f2(V0+h, Fa0+K3, Fb0+L3, Fc0+M3,Fd0+N3);
        long double M4=h*f3(V0+h, Fa0+K3, Fb0+L3, Fc0+M3,Fd0+N3);
        long double N4=h*f4(V0+h, Fa0+K3, Fb0+L3, Fc0+M3,Fd0+N3);

        long double Fa=Fa0+1.0/6.0*(K1+2*K2+2*K3+K4);
        long double Fb=Fb0+1.0/6.0*(L1+2*L2+2*L3+L4);
        long double Fc=Fc0+1.0/6.0*(M1+2*M2+2*M3+M4);
        long double Fd=Fd0+1.0/6.0*(N1+2*N2+2*N3+N4);
        V0=V0+h;
        Fa0=Fa; 
        Fb0=Fb;
        Fc0=Fc;
        Fd0=Fd;

    }
    
    cout<<"Fa = "<<Fa0<<"\n"<<"Fb = "<<Fb0<<"\n"<<"Fc = "<<Fc0<<endl;
    cout<<"Volume : "<<V0;
    return 0;

}