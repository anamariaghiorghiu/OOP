#include <iostream>

using namespace std;
float operator"" _Kelvin(const char* x)
{
    return atof(x) - 273.15;
}
float operator"" _Fahrenheit(const char* x)
{
    return (atof(x) - 32) / 1.8;
}
int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << "300 de grade Kelvin inseamna " << a << " grade Celsius." << endl;
    cout << "120 de grade Fahrenheit inseamna " << b << " grade Celsius." << endl;
    return 0;
}