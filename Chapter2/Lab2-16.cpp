/* Bitwise palindrome
 *
 * Write a program that checks if any int is a bitwise palindrome
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned short int val, val_reverse, val_aux, n;
    bool isPalindrome = false;

    cout << "value = ";
    cin >> val;
    
    n = sizeof(val) * 8;
    val_aux = val;
    val_reverse = 0;

    for (int i = 0; i < n; i++)
    {
        val_reverse = val_reverse << 1;
        val_reverse = val_reverse | (val_aux & 1);
        val_aux = val_aux >> 1;
    }

    if (val == val_reverse)
        isPalindrome = true;

    if (isPalindrome)
        cout << val << " is a bitwise palindrome" << endl;
    else
        cout << val << " is not a bitwise plindrome" << endl;

    return 0;
}
