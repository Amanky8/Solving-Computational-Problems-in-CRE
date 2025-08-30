#include <bits/stdc++.h>
using namespace std;

long double f_func(long double X1, long double X2) {
    return ((((X1 - X2) * (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2)) / ((1 - X1) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6))) - 0.574);
}

long double g_func(long double X1, long double X2) {
    return (((X2 * (3 * X1 + X2)) / ((X1 - X2) * (5 - X1 - X2))) - 2.21);
}

long double dfdx(long double X1, long double X2) {
    return (((12 * X1 - X2) * (3 * X1 + X2) * (3 * X1 + X2)) / (((1 - X1) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6))) - ((X1 - X2) * (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2) * (8 * X1 * X1 + 6 * X1 * X2 - 24 * X1 + 2 * X2 - 16)) / ((1 - X1) * (1 - X1) * (5 - X1 - X2) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6) * (2 * X1 + 6)));
}

long double dfdy(long double X1, long double X2) {
    return ((((((3 * (X1 - X2)) * (3 * X1 + X2) * (3 * X1 + X2)) - (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2))) / (((1 - X1) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6)))) - ((X1 - X2) * (3 * X1 + X2) * (3 * X1 + X2) * (3 * X1 + X2)) / ((1 - X1) * (5 - X1 - X2) * (5 - X1 - X2) * (2 * X1 + 6) * (2 * X1 + 6)));
}

long double dgdx(long double X1, long double X2) {
    return (((3 * X2) / ((X1 - X2) * (5 - X1 - X2))) - ((X2 * (3 * X1 + X2) * (5 - 2 * X1)) / ((X1 - X2) * (X1 - X2) * (5 - X1 - X2) * (5 - X1 - X2))));
}

long double dgdy(long double X1, long double X2) {
    return (((3 * X1 + 2 * X2) / ((X1 - X2) * (5 - X1 - X2))) - ((X2 * (3 * X1 + X2) * (2 * X2 - 5)) / ((X1 - X2) * (X1 - X2) * (5 - X1 - X2) * (5 - X1 - X2))));
}

int main() {
    long double x, y, X1_new, Y1_new, f, g, df_dx, df_dy, dg_dx, dg_dy;
    long double D, Delta_x, Delta_y;
    int n;
    X1_new = 0.99;
    Y1_new = 0.56;
    n = 0;
    const long double tolerance = 1e-6;

    f = f_func(X1_new, Y1_new);
    g = g_func(X1_new, Y1_new);

    while (n==0 || (abs(Delta_x)>tolerance && abs(Delta_y)>tolerance)) {
        x = X1_new;
        y = Y1_new;
        f = f_func(x, y);
        g = g_func(x, y);
        df_dx = dfdx(x, y);
        df_dy = dfdy(x, y);
        dg_dx = dgdx(x, y);
        dg_dy = dgdy(x, y);
        D = (df_dx * dg_dy) - (df_dy * dg_dx);
        if (D == 0) {
            cout << "Jacobian determinant is zero, the method fails." << endl;
            return -1;
        }
        Delta_x = ((g * df_dy) - (f * dg_dy)) / D;
        Delta_y = ((f * dg_dx) - (g * df_dx)) / D;
        X1_new = x + Delta_x;
        Y1_new = y + Delta_y;
        n++;
        
    }

    cout<< "X=" << X1_new << ",Y=" <<Y1_new<<endl;
    cout << "CH4= " << 1 - X1_new << endl;
    cout << "H20 = " << (5 - X1_new - Y1_new) << endl;
    cout << "CO = " << (X1_new - Y1_new) << endl;
    cout << "H2 = " << (3 * X1_new + Y1_new) << endl;
    cout << "CO2 = " << Y1_new << endl;
    cout << "No. of iterations = " << n;

    return 0;
}