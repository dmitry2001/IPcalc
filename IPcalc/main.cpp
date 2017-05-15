#include <iostream>
#include <string>
#include <fstream>
#include "IPv4.h"
#include "WrongInputFormatException.h"
using namespace std;




int main()
{
	string cmd;

	while (true)
	{
		cmd = "";
		cin >> cmd;
		try{
			if (cmd == "help")
			{
				cout << "Awailable commands:\n"
					<< " 1. max_mask: counts maximum available mask of the net that can inlude both of given ip adresses\n"
					<< " 2. max_net.id: counts net.id with maximum mask of the net that can inlude both of given ip adresses\n"
					<< " 3. prefix_to_mask: turns the prefix of the net to the mask\n"
					<< " 4. prefix_classes: counts prefix of the given ip adress (class routing)\n"
					<< " 5. mask_classes: counts mask of the given ip adress (class routing)\n"
					<< " 6. net.id_classes: counts net.id of the given ip adress (class routing)\n"
					<< " 7. net.id_CIDR: counts net.id of the given ip adress using given prefix (CIDR)\n"
					<< " 8. open_file opens file, excecutes all commands in this file and writes results to the other file\n"
					<< " 9. close_file this command can be only used in files (not in console). closes both of files (in and out) immediatly and skips all the commands beyond\n"
					<< "\t if you don't use close file command your files will be never-the-less closed after finishing all the commands in them\n"
					<< " 10. exit this command can be only used in console. closes programm\n";
			}
			else if (cmd == "max_mask")
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
				if (cin.fail() || p > 32)
				{
					cin.clear();
					char c;
					do{
						c = cin.get();
					} while (c != '\n' && c != ' ');
					throw WrongInputFormatException("Wrong prefix format");
				}
				m = IPv4::PrMask(p);
				cout << m;
			}
			else if (cmd == "prefix_classes")
			{
				IPv4 a;
				cin >> a;

				unsigned pr = IPv4::PrClasses(a);
				cout << pr << endl;
			}
			else if (cmd == "mask_classes")
			{
				IPv4 a;
				cin >> a;

				unsigned pr = IPv4::PrClasses(a);
					a = IPv4::PrMask(pr);
					cout << a;
			}
			else if (cmd == "net.id_classes")
			{
				IPv4 a;
				cin >> a;

				unsigned pr = IPv4::PrClasses(a);
				a &= IPv4::PrMask(pr);
				cout << a;
			}
			else if (cmd == "net.id_CIDR")
			{
				IPv4 a;
				cin >> a;
				unsigned pr;
				cin >> pr;
				if (cin.fail() || pr > 32)
				{
					cin.clear();
					char c;
					do{
						c = cin.get();
					} while (c != '\n' && c != ' ');
					throw WrongInputFormatException("Wrong prefix format");
				}
				a &= IPv4::PrMask(pr);
				cout << a;
			}
			else if (cmd == "open_file")
			{
				string path_in, path_out;
				cin >> path_in >> path_out;
				ifstream fin(path_in); ofstream fout(path_out);
				while (!fin.eof())
				{
					cmd = "";
					fin >> cmd;
					try{
						if (cmd == "max_mask")
						{
							IPv4 a, b;

							fin >> a >> b;
							fout << IPv4::MaxMask(a, b);
						}
						else if (cmd == "max_net.id")
						{
							IPv4 a, b;
							fin >> a >> b;

							a = IPv4::MaxMask(a, b);
							b &= a;
							fout << b;
						}
						else if (cmd == "prefix_to_mask")
						{
							unsigned p; IPv4 m;
							fin >> p;
							if (fin.fail() || p > 32)
							{
								fin.clear();
								char c;
								do{
									c = fin.get();
								} while (c != '\n' && c != ' ');
								throw WrongInputFormatException("Wrong prefix format");
							}
							m = IPv4::PrMask(p);
							fout << m;
						}
						else if (cmd == "prefix_classes")
						{
							IPv4 a;
							fin >> a;

							unsigned pr = IPv4::PrClasses(a);
							fout << pr << endl;
						}
						else if (cmd == "mask_classes")
						{
							IPv4 a;
							fin >> a;

							unsigned pr = IPv4::PrClasses(a);

								a = IPv4::PrMask(pr);
								fout << a;
							
						}
						else if (cmd == "net.id_classes")
						{
							IPv4 a;
							fin >> a;

							unsigned pr = IPv4::PrClasses(a);
						
							a &= IPv4::PrMask(pr);
							fout << a;
							
						}
						else if (cmd == "net.id_CIDR")
						{
							IPv4 a;
							fin >> a;
							unsigned pr;
							fin >> pr;
							if (fin.fail() || pr > 32)
							{
								fin.clear();
								char c;
								do{
									c = fin.get();
								} while (c != '\n' && c != ' ');
								throw WrongInputFormatException("Wrong prefix format");
							}
							a &= IPv4::PrMask(pr);
							fout << a;
						}
						else if (cmd == "close_file")
						{
							break;
						}
					}
					catch (WrongInputFormatException& e){/*ignore*/}
				}
				fin.close();
				fout.close();
				cout << "Done!" << endl;
			}
			else if (cmd == "exit")
			{
				return 0;
			}
			else{
				throw WrongInputFormatException("No such command. Print help to watch awailable commands");
			}
		}
		catch (WrongInputFormatException& e)
		{
			cout << e.what() <<endl;
		}
	}
}
