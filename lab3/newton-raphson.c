#include <stdio.h>
#include <math.h>

//doubts: it gives bad answer for x0=not on right side of root,for say f = x^3+3x^2-5

double f(double x)
{
    return x * x * x + 3 * x * x - 5;
}

double f_deriv(double x)
{
    return 3 * x * x + 6 * x;
}

int main()
{
    char function[30] = "x^3+3x^2-5";
    char func_deriv[30] = "3x^2+6x";
    double x0;
    printf("Enter the initial point: ");
    scanf("%lf", &x0);
    int count = 0;
    do
    {
        if(fabs(f_deriv(x0))<=0.000001){
            printf("No root due to denominator zero");
            return 1;
        }
        x0 = x0 - f(x0) / f_deriv(x0);
        count++;
    } while (fabs(f(x0)) >= 0.00005 && count < 50);

    if (count == 50)
    {
        printf("No root exits for this function, i.e. does not cut the x axis.");
    }
    else
    {
        printf("The approximated root is: %lf\n", x0);
    }
}