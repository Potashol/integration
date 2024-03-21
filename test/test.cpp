#include <iostream>
#include <cmath>

int T = 1, m = 1, L = 5; 

double fx(double x, double g)
{
	return -x * T / (m * L); 
}

double fy(double x, double g)
{
	return -x * T / (m * L) - m*g;
}

double trapezoidalIntegral(double f(double, double), double x0, double h, int steps)
{
	double sum = 0;
	double x = x0 + h; 

	for (int i = 0; i < steps; ++i)
	{
		sum += h*((x0 + x) / 2) + (f(x0, 0) + f(x, 0));
		x0 = x; 
		x += h; 
		std::cout << x0 << " " << x << " " << h << std::endl; 
	}
	return sum; 
}


int main()
{
	double x0 = 0; 
	double y0 = x0; 
	double h = (2 - x0)/100;
	std::cout << trapezoidalIntegral(fx, x0, h, 100); 
}