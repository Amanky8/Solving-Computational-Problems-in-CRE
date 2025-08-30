#include <iostream>
#include <cmath>
using namespace std;

long double f_func(long double x, long double y){
    return (exp(x)+(x*y)-1);
}

long double g_func(long double x, long double y){
    return (sin(x*y)+x+y-1);
}

long double dfdx(long double x, long double y){
    return (exp(x)+y);
}

long double dfdy(long double x, long double y){
    return (x);
}

long double dgdx(long double x, long double y){
    return (y*cos(x*y)+1);
}

long double dgdy(long double x, long double y){
    return (x*cos(x*y)+1);
}

int main(){
    long double x, y, x_new, y_new, f, g, df_dx, df_dy, dg_dx, dg_dy;
    long double D, Delta_x, Delta_y;
    int n;
    x_new=0.1;
    y_new=0.5;
    n=0;
    const long double tolerance = 1e-6; // Tolerance for convergence

    f = f_func(x_new, y_new); 
    g = g_func(x_new, y_new); 


    while(n==0 || abs(Delta_x) > tolerance || abs(Delta_y) > tolerance){
        x=x_new;
        y=y_new;

        f=f_func(x,y);
        g=g_func(x,y);
        df_dx=dfdx(x,y);
        df_dy=dfdy(x,y);
        dg_dx=dgdx(x,y);
        dg_dy=dgdy(x,y);

        D=(df_dx*dg_dy)-(df_dy*dg_dx);
        if (D == 0) {
            cout << "Jacobian determinant is zero, the method fails." << endl;
            return -1;
        }
        Delta_x=((g*df_dy)-(f*dg_dy))/D;
        Delta_y=((f*dg_dx)-(g*df_dx))/D;
        x_new=x+Delta_x;
        y_new=y+Delta_y;
        n++;
    }
    cout << "x = " << x_new << endl;
    cout << "y = " << y_new << endl;
    cout<<"No. of iterations = "<<n;
    return 0;
}
