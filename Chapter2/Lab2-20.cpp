/* Plindromes */

#include <iostream>

using namespace std;

int main(void)
{
    int vector[] = {1, 7, 3, 8, 3, 7, 1};
    bool isPalindrome = true;
    int n = sizeof(vector) / sizeof(vector[0]);

    for (int i = 0; i < n; i++)
    {
        if ( vector[i] != vector[n-i-1])
            isPalindrome = false;
    }

    if (isPalindrome)
        cout << "It's a palindrome";
    else
        cout << "It isn't a palindrome";

    cout << endl;

    return 0;
}
