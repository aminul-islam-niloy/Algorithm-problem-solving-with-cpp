#include <bits/stdc++.h>
using namespace std;

class Bisection
{
private:
    double eps;

private:
    double a, b, root, xa, xb, epsr, xrp, xr;

public:
    Bisection()
    {
        a = 0, b = 0, root = -1, xrp = 10, epsr = 1; // Initialize all variables
    }

public:
    double equation(double x)
    {
        return x * x * x - 2 * x - 5;
    }

public:
    void findInterval()
    {
        do
        {
            a = rand() % 10;
            b = rand() % 10;

            if (rand() % 2)
                a *= -1;

            if (rand() % 2)
                b *= -1;

        } while (equation(double(a)) * equation(double(b)) > 0);

        if (a > b)
            swap(a, b);

        return;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot(double eps)
    {
        findInterval();

        double xa = a;
        double xb = b;
        cout << xa << " " << xb << endl; // Randomly generated interval range

        do
        {
            xr = (xa + xb) / 2;

            if (equation(xr) == 0)
                break;

            else if (equation(xr) > 0)
                xb = xr;
            else
                xa = xr;

            epsr = abs((xr - xrp) / xr); // relative error
            xrp = xr;                    // previous root

        } while (epsr > eps);

        root = xr;
    }
};

int main()
{
    Bisection bisection;
    bisection.findRoot(.00001);
    printf("The root of the given equation : %0.10lf\n", bisection.getRoot());
}
