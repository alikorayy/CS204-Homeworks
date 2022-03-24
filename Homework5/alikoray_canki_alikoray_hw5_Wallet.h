#include <iostream>
#include <string>
using namespace std;
struct Money
{
	string currency;
	double amount;
};

class Wallet
{
public:
Wallet();
Wallet(const Wallet &);
~Wallet();
 Wallet operator+(const Money &)const; // click
 const Wallet & operator=(const Wallet&); //click
Wallet operator-(const Money&)const; //click
const Wallet& operator+=(const Wallet&); //click
Wallet operator+(const Wallet&)const; //click
int getSize();
Money* getArray();
private:
	Money* w_array;
	int size;
};

ostream &  operator << (ostream & os,Wallet wt);
bool operator ==  (Wallet& lhs,Wallet& rhs);
bool operator >=  (Wallet& lhs,Money rhs);
bool operator <= (Money lhs, Wallet& rhs);