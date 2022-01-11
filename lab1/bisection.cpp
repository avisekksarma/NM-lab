#include <iostream>
#include <cmath>
#include <cstdlib>

double evaluate(double x)
{
    return x * x * cos(x) + cos(x) / sin(x);
}

int main()
{
    char function[30] = "x*x*cos(x)+ cos(x)/sin(x)";
    printf("The function is: %s\n", function);
    double a, b, c;
    int count = 0;
    double E;
    printf("Enter the lower and upper limit i.e. a and b: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the error precision: ");
    scanf("%lf", &E);

    if (evaluate(a) * evaluate(b) > 0)
    {
        printf("Error: There is no root in this interval.\n");
        return 0;
    }
    else if (evaluate(a) * evaluate(b) == 0)
    {
        if (evaluate(a) == 0)
        {
            printf("One root in the given interval is %lf.\n", a);
        }
        if (evaluate(b) == 0)
        {
            printf("One root in the given interval is %lf.\n", b);
        }
    }
    else
    {
        do
        {
            c = (a + b) / 2.0;
            if (evaluate(c) * evaluate(a) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
            count++;
        } while (fabs(evaluate(c)) > E && count < 50);
        if (count == 50)
        {
            printf("The function is discontinuous in the given interval.\n");
        }
        else
        {
            printf("The output root is: %lf\n", c);
        }
    }

    return 0;
}
