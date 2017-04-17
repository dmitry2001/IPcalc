#pragma once
#include <iostream>
using namespace std;

class IPv4
{
public: 
	typedef unsigned long IPv4_t;
private:
	//internal math functions
	static unsigned powi(unsigned a, unsigned n);
	static IPv4_t maxmask(IPv4_t a, IPv4_t b);
	static IPv4_t prmask(unsigned prefix);
	static unsigned prclasses(IPv4_t addr);
	//ip field
	IPv4_t ip;
public:

	IPv4();
	IPv4(IPv4_t val);
	~IPv4();
	//interface operators
	friend ostream& operator<< (ostream&, const IPv4&);
	friend istream& operator>> (istream&, IPv4&);
	
	IPv4 operator| (const IPv4&);
	IPv4 operator& (const IPv4&);
	void operator|= (const IPv4&);
	void operator&= (const IPv4&);

	//interface static functions
	static IPv4 MaxMask(IPv4 a, IPv4 b);
	static IPv4 PrMask(unsigned prefix);
	static unsigned PrClasses(IPv4 addr);
};

