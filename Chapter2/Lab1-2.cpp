/* Gross price = Net price + Tax
 * Tax = % of net price
 * 
 * To Do:
 * Simple Tax Calculator
 * Accepts tow values: a groos price and a tax rate expressed as a percentage (i.e. a value greater than - and less than 100)
 *
 * Verify if gross price > 0 and tax rate falls in mentioned range
 */

#include <iostream>

using namespace std;

int main(void) 
{
    float grossPrice, taxRate, netPrice, taxValue;
    bool correct_grossPrice, correct_taxRate;

    correct_grossPrice = false;
    correct_taxRate = false;
    
    while (!correct_grossPrice)
    {
        cout << "Enter a gross price: ";
        cin >> grossPrice;

        if (grossPrice > 0)
            correct_grossPrice = true;
        else
            cout << "Please enter a valid gross price." << endl;
    }

    while (!correct_taxRate)
    {
        cout << "Enter a tax rate: ";
        cin >> taxRate;
        
        if (taxRate > taxRate < 100)
            correct_taxRate = true;
        else
            cout << "Please enter a tax rate between (0 and 100.)" << endl;
    }

    netPrice = (100 * grossPrice) / (100 + taxRate); // TaxValue = percentage of net price
    taxValue = grossPrice - netPrice; // Gross price - Tax Value

    cout << "Net price: " << netPrice << endl;
    cout << "Tax value: " << taxValue << endl;

    return 0;
}
