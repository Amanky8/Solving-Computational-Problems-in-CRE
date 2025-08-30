#include <iostream>
using namespace std;
long double Fa,Fb,Fc;
long double f1(long double v0, long double Fa, long double Fb, long double Fc ){
    return (-1)*204.0814508*Fa/(386-Fa);
}
long double f2(long double V, long double Fa, long double Fb, long double Fc){
    return 204.0814508*Fa/(386-Fa);
}
long double f3(long double V, long double Fa, long double Fb, long double Fc){
    return 204.0814508*Fa/(386-Fa);
}

int main(){
    // Fa0 is taken as 0.018 mol/s, T as 1100 K and P as 6 atm.
    long double Fbf=154.4,Fa0=193,Fb0=0,Fc0=0;
    long double K=3.07; 
    float h=0.01;

    long double V0=0; //initial value
    while(Fb0<Fbf){
        long double K1=h*f1(V0,Fa0,Fb0,Fc0);
        long double L1=h*f2(V0,Fa0,Fb0,Fc0);
        long double M1=h*f3(V0,Fa0,Fb0,Fc0);

        long double K2=h*f1(V0+h/2, Fa0+K1/2, Fb0+L1/2, Fc0+M1/2);
        long double L2=h*f2(V0+h/2, Fa0+K1/2, Fb0+L1/2, Fc0+M1/2);
        long double M2=h*f2(V0+h/2, Fa0+K1/2, Fb0+L1/2, Fc0+M1/2);

        long double K3=h*f1(V0+h/2, Fa0+K2/2, Fb0+L2/2, Fc0+M2/2);
        long double L3=h*f2(V0+h/2, Fa0+K2/2, Fb0+L2/2, Fc0+M2/2);
        long double M3=h*f2(V0+h/2, Fa0+K2/2, Fb0+L2/2, Fc0+M2/2);

        long double K4=h*f1(V0+h, Fa0+K3, Fb0+L3, Fc0+M3);
        long double L4=h*f2(V0+h, Fa0+K3, Fb0+L3, Fc0+M3);
        long double M4=h*f2(V0+h, Fa0+K3, Fb0+L3, Fc0+M3);

        long double Fa=Fa0+1.0/6.0*(K1+2*K2+2*K3+K4);
        long double Fb=Fb0+1.0/6.0*(L1+2*L2+2*L3+L4);
        long double Fc=Fc0+1.0/6.0*(M1+2*M2+2*M3+M4);
        V0=V0+h;
        Fa0=Fa; 
        Fb0=Fb;
        Fc0=Fc;

    }
    
    cout<<"Fa = "<<Fa0<<"\n"<<"Fb = "<<Fb0<<"\n"<<"Fc = "<<Fc0<<endl;
    cout<<"Volume : "<<V0;
    return 0;

}