#include <iostream>
#include <iomanip>
#include <string>
#include "IPv4.h"
using namespace std;




int main()
{
	string cmd;

	while (true)
	{
		cmd = "";
		cin >> cmd;
		if (cmd == "max_mask")
		{	
			IPv4 a, b;

			cin >> a >> b;
			cout << IPv4::MaxMask(a, b);
		}
		else if (cmd == "max_net.id")
		{
			IPv4 a, b;
			cin >> a >> b;

			a = IPv4::MaxMask(a, b);
			b &= a;
			cout << b;
		}
		else if (cmd == "prefix_to_mask")
		{
			unsigned p; IPv4 m;
			cin >> p;
			m = IPv4::PrMask(p);
			cout << m;
		}
		else if (cmd == "prefix_classes")
		{
			IPv4 a;
			cin >> a;

			unsigned pr = IPv4::PrClasses(a);
			if (pr != ULONG_MAX) cout << pr << endl;
		}
		else if (cmd == "mask_classes")
		{
			IPv4 a;
			cin >> a;

			unsigned pr = IPv4::PrClasses(a);
			if (pr != ULONG_MAX)
			{
				a = IPv4::PrMask(pr);
				cout << a;
			}
		}
		else if (cmd == "net.id_classes")
		{
			IPv4 a;
			cin >> a;

			unsigned pr = IPv4::PrClasses(a);
			if (pr != ULONG_MAX)
			{	
				a &= IPv4::PrMask(pr);
				cout << a;
			}
		}
		else if (cmd == "net.id_CIDR")
		{
			IPv4 a;
			cin >> a;
			unsigned pr;
			cin >> pr;
			a &= IPv4::PrMask(pr);
			cout << a;
		}
		else if(cmd == "exit")
		{
			return 0;
		}
	}
}
