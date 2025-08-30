#include <iostream>
#include <cmath>
using namespace std;

// Function definitions
float f1_func(float x1, float x2) {
    float n1 = (x1 - x2) * pow((3 * x1 + x2), 3);
    float d1 = (1 - x1) * (5 - x1 - x2) * pow((6 + 2 * x1), 2);
    return ((n1 / d1) - 0.574f);
}

float f2_func(float x1, float x2) {
    float n2 = x2 * (3 * x1 + x2);
    float d2 = (x1 - x2) * (5 - x1 - x2);
    return ((n2 / d2) - 2.21f);
}

float df1dx1(float x1, float x2) {
    float n3 = (12 * x1 - 8 * x2) * pow((3 * x1 + x2), 2);
    float d3 = (1 - x1) * (5 - x1 - x2) * pow((6 + 2 * x1), 2);
    float n4 = (x1 - x2) * (3 * x1 + x2) * (8 * pow(x1, 2) + 6 * x1 * x2 - 24 * x1 + 2 * x2 - 16);
    float d4 = pow((1 - x1), 2) * pow((5 - x1 - x2), 2) * pow((6 + 2 * x1), 3);
    return ((n3 / d3) - (n4 / d4));
}

float df1dx2(float x1, float x2) {
    float n5 = (3 * (x1 - x2) * pow((3 * x1 + x2), 2)) - pow((3 * x1 + x2), 3);
    float d5 = (1 - x1) * (5 - x1 - x2) * pow((6 + 2 * x1), 2);
    float n6 = (x1 - x2) * pow((3 * x1 + x2), 3);
    float d6 = (1 - x1) * pow((5 - x1 - x2), 2) * pow((6 + 2 * x1), 2);
    return ((n5 / d5) + (n6 / d6));
}

float df2dx1(float x1, float x2) {
    float n7 = 3 * x2;
    float d7 = (x1 - x2) * (5 - x1 - x2);
    float n8 = x2 * (3 * x1 + x2) * (5 - 2 * x1);
    float d8 = pow((x1 - x2), 2) * pow((5 - x1 - x2), 2);
    return ((n7 / d7) - (n8 / d8));
}

float df2dx2(float x1, float x2) {
    float n9 = 3 * x1 + 2 * x2;
    float d9 = (x1 - x2) * (5 - x1 - x2);
    float n10 = x2 * (3 * x1 + x2) * (2 * x2 - 5);
    float d10 = pow((x1 - x2), 2) * pow((5 - x1 - x2), 2);
    return ((n9 / d9) - (n10 / d10));
}

int main() {
    float x1_new = 2.5f, x2_new = 4.5f, f1, f2, df1_dx1, df1_dx2, df2_dx1, df2_dx2;
    float D, Delta_x1, Delta_x2;
    int n = 0;
    const float tolerance = 1e-6f; // Tolerance for convergence

    f1 = f1_func(x1_new, x2_new);
    f2 = f2_func(x1_new, x2_new);

    // Iterative process
    while (abs(f1) > tolerance || abs(f2) > tolerance) {
        float x1 = x1_new;
        float x2 = x2_new;

        f1 = f1_func(x1, x2);
        f2 = f2_func(x1, x2);
        df1_dx1 = df1dx1(x1, x2);
        df1_dx2 = df1dx2(x1, x2);
        df2_dx1 = df2dx1(x1, x2);
        df2_dx2 = df2dx2(x1, x2);

        D = (df1_dx1 * df2_dx2) - (df1_dx2 * df2_dx1);
        if (D == 0) {
            cout << "Jacobian determinant is zero, the method fails." << endl; // Error message for zero determinant
            return -1;
        }

        Delta_x1 = ((f2 * df1_dx2) - (f1 * df2_dx2)) / D;
        Delta_x2 = ((f1 * df2_dx1) - (f2 * df1_dx1)) / D;

        x1_new = x1 + Delta_x1;
        x2_new = x2 + Delta_x2;

        // Verbose output for each iteration
        cout << "Iteration " << n << ": f1 = " << f1 << ", f2 = " << f2 << ", x1 = " << x1_new << ", x2 = " << x2_new << endl;

        n++;
    }

    cout << "Final values: " << endl;  
    cout << "x1 = " << x1_new << endl;
    cout << "x2 = " << x2_new << endl;
    cout << "No. of iterations = " << n << endl;  

    return 0;
}
