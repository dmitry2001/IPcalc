#include "IPv4.h"


IPv4::IPv4() : ip(0)
{
}
IPv4::IPv4(IPv4_t val) : ip(val)
{
}

IPv4::~IPv4()
{
}
unsigned IPv4::powi(unsigned a, unsigned n)
{
	unsigned r = 1;
	for (size_t i = 0; i < n; i++)
	{
		r *= a;
	}
	return r;
}
IPv4::IPv4_t IPv4::maxmask(IPv4_t a, IPv4_t b)
{
	IPv4_t result = 0;
	for (int i = 31; i >= 0; i--)
	{

		unsigned bit = (a / powi(2, i)) % 2 == (b / powi(2, i)) % 2;
		if (bit)
			result += powi(2, i);
		else return result;
	}
	return result;
}
IPv4::IPv4_t IPv4::prmask(unsigned prefix)
{
	IPv4_t result = 0;
	for (int i = 31; i >= 32 - prefix; i--)
	{
		result += powi(2, i);
	}
	return result;
}
unsigned IPv4::prclasses(IPv4_t addr)
{
	unsigned b = addr / powi(2, 31);
	if (b == 0) return 8;
	b = addr / powi(2, 30);
	if (b == 2) return 16;
	b = addr / powi(2, 29);
	if (b == 6) return 24;
	b = addr / powi(2, 28);
	if (b == 14) throw WrongInputFormatException("class D (multicast)");
	if (b == 15)throw WrongInputFormatException("class E reserved");
}
IPv4 IPv4::MaxMask(IPv4 a, IPv4 b)
{
	return IPv4(maxmask(a.ip, b.ip));
}
IPv4 IPv4::PrMask(unsigned prefix)
{
	return IPv4(prmask(prefix));
}
unsigned IPv4::PrClasses(IPv4 addr)
{
	return prclasses(addr.ip);
}
IPv4 IPv4::operator| (const IPv4& val)
{
	return IPv4(this->ip | val.ip);
}
IPv4 IPv4::operator& (const IPv4& val)
{
	return IPv4(this->ip & val.ip);
}
void IPv4::operator|= (const IPv4&  val)
{
	this->ip |= val.ip;
}
void IPv4::operator&= (const IPv4& val)
{
	this->ip &= val.ip;
}
ostream& operator<< (ostream& out, const IPv4& ipcl)
{
	unsigned qw = 0;
	qw =  ipcl.ip/ IPv4::powi(2, 24);
	out << endl << qw << ".";
	qw = (ipcl.ip / IPv4::powi(2, 16)) % IPv4::powi(2, 8);
	out << qw << ".";
	qw = (ipcl.ip / IPv4::powi(2, 8)) % IPv4::powi(2, 8);
	out << qw << ".";
	qw = ipcl.ip  % IPv4::powi(2, 8);
	out << qw << endl;
	return out;
}
istream& operator>> (istream& in, IPv4& ipcl)
{
	ipcl.ip = 0;
	unsigned qw; char sep;
	in >> qw >> sep;
	if (in.fail() || qw > 255)
	{
		in.clear();
		char c;
		do{
			c = cin.get();
		} while (c != '\n' && c != ' ');
		throw WrongInputFormatException("Wrong ip format");
	}
	ipcl.ip += qw*IPv4::powi(2, 24);
	in >> qw >> sep;
	if (in.fail() || qw > 255)
	{
		in.clear();
		char c;
		do{
			c = cin.get();
		} while (c != '\n' && c != ' ');
		throw WrongInputFormatException("Wrong ip format");
	}
	ipcl.ip += qw*IPv4::powi(2, 16);
	in >> qw >> sep;
	if (in.fail() || qw > 255)	
	{
		in.clear();
		char c;
		do{
			c = cin.get();
		} while (c != '\n' && c != ' ');
		throw WrongInputFormatException("Wrong ip format");
	}
	ipcl.ip += qw*IPv4::powi(2, 8);
	in >> qw;
	if (in.fail() || qw > 255)	
	{
		in.clear();
		char c;
		do{
			c = cin.get();
		} while (c != '\n' && c != ' ');
		throw WrongInputFormatException("Wrong ip format");
	}
	ipcl.ip += qw;
	return in;
}
