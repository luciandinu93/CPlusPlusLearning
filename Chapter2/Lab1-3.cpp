/* metric and imperial measurement systems
 * meter - as a real number
 * foot - as an integer
 * inch - a real number
 *
 * To Do:
 * Write a simple \"measurement converter\". 
 *
 * -> ask the user which system she/he uses to input data;
 *  we asume that 0 means "metric" and 1 means "imperial"
 * -> depending on the user's answer, ask either for meter or feet and inches
 * -> output the distance in proper (different_ units; either in feet and inchers or in meters;
 * -> a result outputed as metric should look like 123.4m;
 * -> a result outputted as imperial should look like 12'3.5\".
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int sys;
    float m, ft, in;

    cout << "Please select your unit system 0 - metrics / 1 - imperial: ";
    cin >> sys;

    if (sys)
    {
        cout << "Enter feet value: ";
        cin >> ft;
        cout << "Enter inch value: ";
        cin >> in;

        m = (ft * 12 + in) * 0.0254; 

        cout << ft << "\'" << in << "\" = " << m << "m" << endl;
    }
    else
    {
        cout << "Enter meter value: ";
        cin >> m;
        
        in = m / 0.02540;

        ft = (int)in / 12;
        in = abs(ft * 12 - in);

        cout << m << " meters = " << ft << "\'" << in << "\"" << endl;
    }

    return 0;
}
