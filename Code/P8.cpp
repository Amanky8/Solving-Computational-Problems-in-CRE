#include<bits/stdc++.h>
#include <cmath>
using namespace std;

long double K1=0.0001385; 
long double K2=0.00007576; 

// f1 = (-K1CaCb^0.5)
long double f1(long double V, long double Fa, long double Fb, long double Fc, long double Fd, long double Fe){
    long double FT = Fa + Fb + Fc + Fd + Fe;
    return (-1)*K1*(512.03277*Fa/FT)*pow(512.03277*Fb/FT,0.5);
}
// f2 = (-K1CaCb^0.5) - (K2CcCb^0.5)
long double f2(long double V, long double Fa, long double Fb, long double Fc, long double Fd, long double Fe){
    long double FT = Fa + Fb + Fc + Fd + Fe;
    return (-1)*K1*(512.03277*Fa/FT)*pow(512.03277*Fb/FT,0.5) - K2*(512.03277*Fc/FT)*pow(512.03277*Fb/FT,0.5);
}
// f3 = (K1CaCb^0.5) - (K2CcCb^0.5)
long double f3(long double V, long double Fa, long double Fb, long double Fc, long double Fd, long double Fe){
    long double FT = Fa + Fb + Fc + Fd + Fe;
    return K1*(512.03277*Fa/FT)*pow(512.03277*Fb/FT,0.5) - K2*(512.03277*Fc/FT)*pow(512.03277*Fb/FT,0.5);
}
// f4 = (K1CaCb^0.5) + (K2CcCb^0.5)
long double f4(long double V, long double Fa, long double Fb, long double Fc, long double Fd, long double Fe){
    long double FT = Fa + Fb + Fc + Fd + Fe;
    return K1*(512.03277*Fa/FT)*pow(512.03277*Fb/FT,0.5) + K2*(512.03277*Fc/FT)*pow(512.03277*Fb/FT,0.5);
}
// f5 = (K2CcCb^0.5)
long double f5(long double V, long double Fa, long double Fb, long double Fc, long double Fd, long double Fe){
    long double FT = Fa + Fb + Fc + Fd + Fe;
    return K2*(512.03277*Fc/FT)*pow(512.03277*Fb/FT,0.5);
}
int main(){
    // ya0 is taken as 0.333, yb0 as 0.667, T as 833.15 K and P as 35 atm.
    // Inlet volumetric flow rate,v0 = 4.9e-3 m3/s and volume of the reactor is 3.53.
    // Assuming the gas is  ideal, we can calculate the molar volume, v = RT/P = 1.953e-3 m3/mol
    // Hence, FT0 = v0/v = 2.51 mol/s
    // Fa0 = ya0*FT0 = 0.83583 mol/s and Fb0 = yb0*FT0 = 1.67417 mol/s
    // Ca = (Fa/FT)*(P/RT)
    // Cb = (Fb/FT)*(P/RT)
    // Cc = (Fc/FT)*(P/RT)
    // P/RT = 512.03277

    cout << "\nThe reactions are: "<<endl<<"A + B ----> C + D (K1) \nB + C ----> D + E (K2)\n";
    long double V=3.53,Fa0=0.83583,Fb0=1.67417,Fc0=0,Fd0=0,Fe0=0;
    float h=0.01;
    long double v = 0.0049; // Volumetric flow rate
    long double k1,k2,k3,k4,l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4,o1,o2,o3,o4;
    long double V0=0.0; // Volume at entry 
    int n = (V-V0)/h; // Number of loops
    while(V0<V){
    k1 = h * f1(V0,Fa0,Fb0,Fc0,Fd0,Fe0);
    l1 = h * f2(V0,Fa0,Fb0,Fc0,Fd0,Fe0);
    m1 = h * f3(V0,Fa0,Fb0,Fc0,Fd0,Fe0);
    n1 = h * f4(V0,Fa0,Fb0,Fc0,Fd0,Fe0);
    o1 = h * f5(V0,Fa0,Fb0,Fc0,Fd0,Fe0);

    k2 = h * f1(V0+0.5*h,Fa0+0.5*k1,Fb0+0.5*l1,Fc0+0.5*m1,Fd0+0.5*n1,Fe0+0.5*o1);
    l2 = h * f2(V0+0.5*h,Fa0+0.5*k1,Fb0+0.5*l1,Fc0+0.5*m1,Fd0+0.5*n1,Fe0+0.5*o1);
    m2 = h * f3(V0+0.5*h,Fa0+0.5*k1,Fb0+0.5*l1,Fc0+0.5*m1,Fd0+0.5*n1,Fe0+0.5*o1);
    n2 = h * f4(V0+0.5*h,Fa0+0.5*k1,Fb0+0.5*l1,Fc0+0.5*m1,Fd0+0.5*n1,Fe0+0.5*o1);
    o2 = h * f5(V0+0.5*h,Fa0+0.5*k1,Fb0+0.5*l1,Fc0+0.5*m1,Fd0+0.5*n1,Fe0+0.5*o1);

    k3 = h * f1(V0+0.5*h,Fa0+0.5*k2,Fb0+0.5*l2,Fc0+0.5*m2,Fd0+0.5*n2,Fe0+0.5*o2);
    l3 = h * f2(V0+0.5*h,Fa0+0.5*k2,Fb0+0.5*l2,Fc0+0.5*m2,Fd0+0.5*n2,Fe0+0.5*o2);
    m3 = h * f3(V0+0.5*h,Fa0+0.5*k2,Fb0+0.5*l2,Fc0+0.5*m2,Fd0+0.5*n2,Fe0+0.5*o2);
    n3 = h * f4(V0+0.5*h,Fa0+0.5*k2,Fb0+0.5*l2,Fc0+0.5*m2,Fd0+0.5*n2,Fe0+0.5*o2);
    o3 = h * f5(V0+0.5*h,Fa0+0.5*k2,Fb0+0.5*l2,Fc0+0.5*m2,Fd0+0.5*n2,Fe0+0.5*o2);

    k4 = h * f1(V0+h,Fa0+k3,Fb0+l3,Fc0+m3,Fd0+n3,Fe0+o3);
    l4 = h * f2(V0+h,Fa0+k3,Fb0+l3,Fc0+m3,Fd0+n3,Fe0+o3);
    m4 = h * f3(V0+h,Fa0+k3,Fb0+l3,Fc0+m3,Fd0+n3,Fe0+o3);
    n4 = h * f4(V0+h,Fa0+k3,Fb0+l3,Fc0+m3,Fd0+n3,Fe0+o3);
    o4 = h * f5(V0+h,Fa0+k3,Fb0+l3,Fc0+m3,Fd0+n3,Fe0+o3);

    // Updating the feed rates
    Fa0 = Fa0 + ((k1 + 2.0*k2 + 2.0*k3 + k4)/6.0);
    Fb0 = Fb0 + ((l1 + 2.0*l2 + 2.0*l3 + l4)/6.0);
    Fc0 = Fc0 + ((m1 + 2.0*m2 + 2.0*m3 + m4)/6.0);
    Fd0 = Fd0 + ((n1 + 2.0*n2 + 2.0*n3 + n4)/6.0);
    Fe0 = Fe0 + ((o1 + 2.0*o2 + 2.0*o3 + o4)/6.0);

    // Updating the volume 
    V0=V0+h;
    }
    cout << "\nFeed rates(in mol/s) of different components at the exit are: \n";
    cout<<"Fa = "<<Fa0<<"\n"<<"Fb = "<<Fb0<<"\n"<<"Fc = "<<Fc0<<"\n"<<"Fd = "<<Fd0<<"\n"<<"Fe = "<<Fe0<<"\n";
    cout << "\nConcentration(in m3/s) of different components at the exit are: \n";
    cout<<"Ca = "<<Fa0/v<<"\n"<<"Cb = "<<Fb0/v<<"\n"<<"Cc = "<<Fc0/v<<"\n"<<"Cd = "<<Fd0/v<<"\n"<<"Ce = "<<Fe0/v<<"\n";
    return 0;
}