#include <iostream>
#include <cmath>

using namespace std;

double eval_z_deriv(double x = 0, double y = 0, double z = 0)
{
    // NOTE: z_deriv (z') = y''
    // NOTE: z = y' i.e z = y_deriv
    // return sin(x) - 4 * y - 3 * z;
    return z/x-8*x*x*pow(y,3);
}
double eval_y_deriv(double x = 0, double y = 0, double z = 0)
{
    //return 6 * x * x + 3;
    return z;
}
int main()
{
    // y0_deriv = z0 ,i.e. y_deriv = z i.e. z = y'
    double x0, y0, z0, xn, h; // z0 = y'(0)
    double k1, k2, k3, k4, k, l1, l2, l3, l4, l;
    int n;
    cout << "Enter the initial values(x0,y0,z0) at a point: ";
    cin >> x0 >> y0 >> z0;
    cout << "Enter the xn and number of steps(n): ";
    cin >> xn >> n;
    h = (xn - x0) / n;
    for (int i = 0; i < n; i++)
    {
        k1 = h * z0;
        l1 = h * eval_z_deriv(x0, y0, z0);
        k2 = h * (z0 + l1 / 2);
        l2 = h * eval_z_deriv(x0 + h / 2.0, y0 + k1 / 2, z0 + l1 / 2);
        k3 = h * (z0 + l2 / 2);
        l3 = h * eval_z_deriv(x0 + h / 2.0, y0 + k2 / 2, z0 + l2 / 2);
        k4 = h * (z0 + l3);
        l4 = h * eval_z_deriv(x0 + h, y0 + k3, z0 + l3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        y0 = y0 + k;
        z0 = z0 + l;
        x0 = x0 + h;
    }
    cout << "The y(" << xn << ") = " << y0 << endl;
    cout << "The y'(" << xn << ") = " << z0 << endl;

    return 0;
}