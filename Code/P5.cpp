#include <iostream>
using namespace std;
long double Fa,Fb,Fc;
long double f1(long double v0, long double Fa, long double Fb, long double Fc ){
    return (-1)*1.54*Fa/(0.036-Fa);
}
long double f2(long double V, long double Fa, long double Fb, long double Fc){
    return 1.54*Fa/(0.036-Fa);
}
long double f3(long double V, long double Fa, long double Fb, long double Fc){
    return 1.54*Fa/(0.036-Fa);
}

int main(){
    // Fa0 is taken as 0.018 mol/s, T as 518 Celcius and P as 2 atm.
    long double Faf=0.0117,Fa0=0.018,Fb0=0,Fc0=0;
    long double K=0.05; 
    float h=0.000001;

    long double V0=0; //initial value
    while(Fa0>Faf){
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