#include <iostream>
using namespace std;
long double k,v;
long double f1(long double x0,long double A0){
    return (-1)*k*A0/v;
}

int main(){
    long double A0, l, x0;
    cout<<"Enter the initial/starting length of PFR : ";
    cin>>x0;
    cout<<"Enter initial concentration of A : ";
    cin>>A0;
    cout<<"Enter the lenght of the plug flow reactor : ";
    cin>>l;
    cout<<"Enter the value of Mean Axial Velocity : ";
    cin>>v;
    cout<<"Enter the value of rate constant k : ";
    cin>>k;

    float h=0.01;
     while(x0<l){
        long double k1=h*f1(x0,A0);
        long double k2= h*f1(x0+h/2,A0+k1/2);
        long double k3= h*f1(x0+h/2,A0+k2/2);
        long double k4= h*f1(x0+h,A0+k3);
        long double A1=A0+1.0/6.0*(k1+2*k2+2*k3+k4);
        x0+=h;
        A0=A1;
        //cout<<"A ="<<A0<<" "<<"at Length = "<<x0<<" metre"<<endl;
    }
    cout<<"A="<<A0<<" "<<"at Length="<<l<<"metre";
}