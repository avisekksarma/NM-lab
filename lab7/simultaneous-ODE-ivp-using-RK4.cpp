// this is solution to system of simultaneous ODE initial value problems
// using RK4 method
#include <iostream>
using namespace std;

double eval_y_deriv(double x = 0, double y = 0, double z = 0)
{
    return 2 * x;
}
double eval_z_deriv(double x = 0, double y = 0, double z = 0)
{
    return 6 * x * x + 3;
}
int main()
{
    char func_y[30] = "x^2+3";
    char func_z[30] = "2*x^3+3*x-10";
    double x0, y0, z0, xn, h;
    double k1, k2, k3, k4, k, l1, l2, l3, l4, l;
    int n;
    cout << "Enter the initial values(x0,y0,z0) at a point: ";
    cin >> x0 >> y0 >> z0;
    cout << "Enter the xn and number of steps(n): ";
    cin >> xn >> n;
    h = (xn - x0) / n;
    for (int i = 0; i < n; i++)
    {
        k1 = h * eval_y_deriv(x0, y0, z0);
        l1 = h * eval_z_deriv(x0, y0, z0);
        k2 = h * eval_y_deriv(x0 + h / 2.0, y0 + k1 / 2, z0 + l1 / 2);
        l2 = h * eval_z_deriv(x0 + h / 2.0, y0 + k1 / 2, z0 + l1 / 2);
        k3 = h * eval_y_deriv(x0 + h / 2.0, y0 + k2 / 2, z0 + l2 / 2);
        l3 = h * eval_z_deriv(x0 + h / 2.0, y0 + k2 / 2, z0 + l2 / 2);
        k4 = h * eval_y_deriv(x0 + h, y0 + k3, z0 + l3);
        l4 = h * eval_z_deriv(x0 + h, y0 + k3, z0 + l3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        y0 = y0 + k;
        z0 = z0 + l;
        x0 = x0 + h;
    }
    cout << "The y(" << xn << ") = " << y0 << endl;
    cout << "The z(" << xn << ") = " << z0 << endl;

    return 0;
}