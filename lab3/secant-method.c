#include <stdio.h>
#include <math.h>
//doubts:it gives bad  root for x0,x1=not on right side of root,for say f = x^3+3x^2-5
double f(double x)
{
    return x * x - sin(x);
}

int main()
{
    char function[30] = "x^3+3x^2-5";
    double x0, x1, c;
    printf("Enter the initial two points: ");
    scanf("%lf %lf", &x0, &x1);
    int count = 0;
    do
    {
        if (fabs(f(x1) - f(x0)) <= 0.000001)
        {
            printf("No root in given interval.");
            return 1;
        }
        c = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        x0 = x1;
        x1 = c;
        count++;
    } while (fabs(f(c)) >= 0.00005 && count < 50);

    if (count == 50)
    {
        printf("No root exits for this function, i.e. does not cut the x axis.\n");
    }
    else
    {
        printf("The approximated root is: %lf\n", c);
    }
}