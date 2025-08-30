#include <bits/stdc++.h>
using namespace std;

// Define constants
const long double R = 8.314;       // Gas constant J/(mol·K)
const long double P = 1.6e5;       // Pressure in Pa (1.6 atm)
const long double Fa_init = 0.0376; // Initial molar flow rate of A (mol/s)
const long double T_init = 833.15;  // Initial temperature in K
const long double V0_init = 0.0;    // Initial volume (m^3)
const long double h = 1.0e-5;       // Step size for volume (m^3)
const long double U = 110;          // Heat transfer coefficient (W/m^2·K)
const long double D = 0.0254;       // Reactor diameter (m)

// Reaction rate equations
long double fA(long double Fa, long double Fb, long double Fc, long double Fd, long double Fe, long double T) {
    return (-1) * (((1e9 * (1 / 3.59)) * (Fa * (pow(Fb, 0.5))) * exp(34 - 34000 / T)) / (pow((Fa + Fb + Fc + Fd + Fe), 1.5) * pow(T, 1.5)));
}

long double fB(long double Fa, long double Fb, long double Fc, long double Fd, long double Fe, long double T) {
    long double f1 = fA(Fa, Fb, Fc, Fd, Fe, T);
    return (f1 - (((1e9 * (1 / 3.59)) * ((Fc * pow(Fb, 0.5)) * exp(35 - 38000 / T))) / (pow(Fa + Fb + Fc + Fd + Fe, 1.5) * pow(T, 1.5))));
}

long double fC(long double Fa, long double Fb, long double Fc, long double Fd, long double Fe, long double T) {
    long double f1 = fA(Fa, Fb, Fc, Fd, Fe, T);
    long double f2 = fB(Fa, Fb, Fc, Fd, Fe, T);
    return (f2 - 2 * f1);
}

long double fD(long double Fa, long double Fb, long double Fc, long double Fd, long double Fe, long double T) {
    long double f2 = fB(Fa, Fb, Fc, Fd, Fe, T);
    return (-f2);
}

long double fE(long double Fa, long double Fb, long double Fc, long double Fd, long double Fe, long double T) {
    long double f1 = fA(Fa, Fb, Fc, Fd, Fe, T);
    long double f2 = fB(Fa, Fb, Fc, Fd, Fe, T);
    return (f1 - f2);
}

long double temp(long double Fa, long double Fb, long double Fc, long double Fd, long double Fe, long double T) {
    long double f1 = fA(Fa, Fb, Fc, Fd, Fe, T);
    long double f2 = fE(Fa, Fb, Fc, Fd, Fe, T);
    return ((((-1) * 1e5 * f1 - 75000 * f2)) / (160 * Fa + 140 * Fb + 75 * Fc + 90 * Fd + 150 * Fe));
}

int main() {
    long double Fa = 0.83583;
    long double Fb = 1.67417;
    long double Fc = 0.0;
    long double Fd = 0.0;
    long double Fe = 0.0;
    long double T = T_init;
    long double V0 = V0_init;
    long double V_max = 3.53;

    // Runge-Kutta method for solving ODEs
    while (V0 < V_max) {
        long double kA1 = h * fA(Fa, Fb, Fc, Fd, Fe, T);
        long double kB1 = h * fB(Fa, Fb, Fc, Fd, Fe, T);
        long double kC1 = h * fC(Fa, Fb, Fc, Fd, Fe, T);
        long double kD1 = h * fD(Fa, Fb, Fc, Fd, Fe, T);
        long double kE1 = h * fE(Fa, Fb, Fc, Fd, Fe, T);
        long double T1 = h * temp(Fa, Fb, Fc, Fd, Fe, T);

        long double kA2 = h * fA(Fa + kA1 / 2, Fb + kB1 / 2, Fc + kC1 / 2, Fd + kD1 / 2, Fe + kE1 / 2, T + T1 / 2);
        long double kB2 = h * fB(Fa + kA1 / 2, Fb + kB1 / 2, Fc + kC1 / 2, Fd + kD1 / 2, Fe + kE1 / 2, T + T1 / 2);
        long double kC2 = h * fC(Fa + kA1 / 2, Fb + kB1 / 2, Fc + kC1 / 2, Fd + kD1 / 2, Fe + kE1 / 2, T + T1 / 2);
        long double kD2 = h * fD(Fa + kA1 / 2, Fb + kB1 / 2, Fc + kC1 / 2, Fd + kD1 / 2, Fe + kE1 / 2, T + T1 / 2);
        long double kE2 = h * fE(Fa + kA1 / 2, Fb + kB1 / 2, Fc + kC1 / 2, Fd + kD1 / 2, Fe + kE1 / 2, T + T1 / 2);
        long double T2 = h * temp(Fa + kA1 / 2, Fb + kB1 / 2, Fc + kC1 / 2, Fd + kD1 / 2, Fe + kE1 / 2, T + T1 / 2);

        long double kA3 = h * fA(Fa + kA2 / 2, Fb + kB2 / 2, Fc + kC2 / 2, Fd + kD2 / 2, Fe + kE2 / 2, T + T2 / 2);
        long double kB3 = h * fB(Fa + kA2 / 2, Fb + kB2 / 2, Fc + kC2 / 2, Fd + kD2 / 2, Fe + kE2 / 2, T + T2 / 2);
        long double kC3 = h * fC(Fa + kA2 / 2, Fb + kB2 / 2, Fc + kC2 / 2, Fd + kD2 / 2, Fe + kE2 / 2, T + T2 / 2);
        long double kD3 = h * fD(Fa + kA2 / 2, Fb + kB2 / 2, Fc + kC2 / 2, Fd + kD2 / 2, Fe + kE2 / 2, T + T2 / 2);
        long double kE3 = h * fE(Fa + kA2 / 2, Fb + kB2 / 2, Fc + kC2 / 2, Fd + kD2 / 2, Fe + kE2 / 2, T + T2 / 2);
        long double T3 = h * temp(Fa + kA2 / 2, Fb + kB2 / 2, Fc + kC2 / 2, Fd + kD2 / 2, Fe + kE2 / 2, T + T2 / 2);

        long double kA4 = h * fA(Fa + kA3, Fb + kB3, Fc + kC3, Fd + kD3, Fe + kE3, T + T3);
        long double kB4 = h * fB(Fa + kA3, Fb + kB3, Fc + kC3, Fd + kD3, Fe + kE3, T + T3);
        long double kC4 = h * fC(Fa + kA3, Fb + kB3, Fc + kC3, Fd + kD3, Fe + kE3, T + T3);
        long double kD4 = h * fD(Fa + kA3, Fb + kB3, Fc + kC3, Fd + kD3, Fe + kE3, T + T3);
        long double kE4 = h * fE(Fa + kA3, Fb + kB3, Fc + kC3, Fd + kD3, Fe + kE3, T + T3);
        long double T4 = h * temp(Fa + kA3, Fb + kB3, Fc + kC3, Fd + kD3, Fe + kE3, T + T3);

        // Update values using RK4 formula
        long double Fa1 = Fa+ 1.0 / 6.0 * (kA1 + 2 * kA2 + 2 * kA3 + kA4);
        long double Fb1 = Fb+ 1.0 / 6.0 * (kB1 + 2 * kB2 + 2 * kB3 + kB4);
        long double Fc1 = Fc+ 1.0 / 6.0 * (kC1 + 2 * kC2 + 2 * kC3 + kC4);
        long double Fd1 = Fd +1.0 / 6.0 * (kD1 + 2 * kD2 + 2 * kD3 + kD4);
        long double Fe1 = Fe + 1.0 / 6.0 * (kE1 + 2 * kE2 + 2 * kE3 + kE4);
        long double Tf1 = T+ 1.0 / 6.0 * (T1 + 2 * T2 + 2 * T3 + T4);
        Fa=Fa1;
        Fb=Fb1;
        Fc=Fc1;
        Fd=Fd1;
        Fe=Fe1;
        T=Tf1;

        V0 += h;
    }

    cout << "Adiabatic Conditions" << endl;
    cout << "Fa: " << Fa << endl;
    cout << "Fb: " << Fb << endl;
    cout << "Fc: " << Fc << endl;
    cout << "Fd: " << Fd << endl;
    cout << "Fe: " << Fe << endl;
    cout << "T: " << T << endl;

    return 0;
}

// Yrr yeh code toh sahi hai,mere hisab se pta nahi kyun sari values Nan aa rhi,ek baar check karlo
// Main khana khake phir dekta hun