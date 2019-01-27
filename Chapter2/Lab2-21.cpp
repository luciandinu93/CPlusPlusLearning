/* Ealuating different kinds of means
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double vector[] = {1., 2., 3., 4., 5.};
    int n = sizeof(vector) / sizeof(vector[0]);
    double ArithmeticMean;
    double HarmonicMean;
    double GeometricMean;
    double RootMeanSquare;

    ArithmeticMean = 0;
    HarmonicMean = 0;
    GeometricMean = 1;
    RootMeanSquare = 0;
    
    for (int i = 0; i < n; i++)
    {
        ArithmeticMean += vector[i];
        HarmonicMean += (1/vector[i]);
        GeometricMean *= vector[i];
        RootMeanSquare += pow(vector[i], 2);
    }

    ArithmeticMean = ArithmeticMean / n;
    HarmonicMean = n / HarmonicMean;
    GeometricMean = pow(GeometricMean, (1./n));
    RootMeanSquare = sqrt(RootMeanSquare / n);

    cout << "Arithmetic Mean = " << ArithmeticMean << endl;
    cout << "Harmonic Mean = " << HarmonicMean << endl;
    cout << "Geometric Mean = " << GeometricMean << endl;
    cout << "RootMean Sqare = " << RootMeanSquare << endl;

    cout << endl;

    return 0;
}
