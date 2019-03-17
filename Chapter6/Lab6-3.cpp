/* Polymorphism part 3 */

#include <iostream>

class IPAddress
{
public:
	IPAddress(int x1, int x2, int x3, int x4) : x1(x1), x2(x2), x3(x3), x4(x4) { }
	IPAddress(const IPAddress &ip) {x1 = ip.x1; x2 = ip.x2; x3 = ip.x3; x4 = ip.x4;}
	virtual void print();
protected:
	int x1, x2, x3, x4;
};

class IPAddressChecked : public IPAddress
{
public:
	IPAddressChecked() : IPAddress(x1, x2, x3, x4);
private:
	bool isValid;
};

int main()
{
	return 0;
}