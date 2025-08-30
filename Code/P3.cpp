#include <iostream>
#include <cmath>
using namespace std;

long double f1_func(long double X1, long double X2){
    return ((((X1 - X2) * (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2)) / ((1 - X1) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6))) - 0.574);
}

long double f2_func(long double X1, long double X2){
    return (((X2 * (3 * X1 + X2)) / ((X1 - X2) * (5 - X1 - X2))) - 2.21);
}

long double df1dx1(long double X1, long double X2){
    return (((12 * X1 -8* X2) * (3 * X1 + X2) * (3 * X1 + X2)) / (((1 - X1) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6))) - ((X1 - X2) * (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2) * (8 * X1 * X1 + 6 * X1 * X2 - 24 * X1 + 2 * X2 - 16)) / ((1 - X1) * (1 - X1) * (5 - X1 - X2) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6) * (2 * X1 + 6)));

}

long double df1dx2(long double X1, long double X2){
    return ((((((3 * (X1 - X2)) * (3 * X1 + X2) * (3 * X1 + X2)) - (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2))) / (((1 - X1) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6)))) - ((X1 - X2) * (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2)) / ((1 - X1) * (5 - X1 - X2) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6)));

}

long double df2dx1(long double X1, long double X2){
    return (((3 * X2) / ((X1 - X2) * (5 - X1 - X2))) - ((X2 * (3 * X1 + X2) * (5 - 2 * X1)) / ((X1 - X2) * (X1 - X2) * (5 - X1 - X2) * (5 - X1 - X2))));

}

long double df2dx2(long double X1, long double X2){
    return (((3 * X1 + 2 * X2) / ((X1 - X2) * (5 - X1 - X2))) - ((X2 * (3 * X1 + X2) * (2 * X2 - 5)) / ((X1 - X2) * (X1 - X2) * (5 - X1 - X2) * (5 - X1 - X2))));

}

int main(){
    long double x1, x2, x1_new, x2_new, f1, f2, df1_dx1, df1_dx2, df2_dx1, df2_dx2;
    long double D, Delta_x1, Delta_x2;
    int n;
    x1_new=8;
    x2_new=1;
    n=0;
    const long double tolerance = 1e-6; // Tolerance for convergence

    f1 = f1_func(x1_new, x2_new); 
    f2 = f2_func(x1_new, x2_new); 


while (n == 0 || (abs(Delta_x1) > tolerance && abs(Delta_x2) > tolerance)) 
    {

        x1=x1_new;
        x2=x2_new;

        f1=f1_func(x1,x2);
        f2=f2_func(x1,x2);
        df1_dx1=df1dx1(x1,x2);
        df1_dx2=df1dx2(x1,x2);
        df2_dx1=df2dx1(x1,x2);
        df2_dx2=df2dx2(x1,x2);

        D=(df1_dx1*df2_dx2)-(df1_dx2*df2_dx1);
        if (D == 0) {
            cout << "Jacobian determinant is zero, the method fails." << endl;
            return -1;
        }
        Delta_x1=((f2*df1_dx2)-(f1*df2_dx2))/D;
        Delta_x2=((f1*df2_dx1)-(f2*df1_dx1))/D;
        x1_new=x1+Delta_x1;
        x2_new=x2+Delta_x2;
        n++;
    }
    cout << "x1 = " << x1_new << endl;
    cout << "x2 = " << x2_new << endl;
    cout<<"CH4 = "<<(1-x1_new)<<endl;
    cout<<"H2O = "<<(5-x1_new-x2_new)<<endl;
    cout<<"Co = "<<(x1_new-x2_new)<<endl;
    cout<<"H2 = "<<(3*x1_new+x2_new)<<endl;
    cout<<"Co2 = "<<(x2_new)<<endl;
    cout<<"No. of iterations = "<<n;
    return 0;
}
