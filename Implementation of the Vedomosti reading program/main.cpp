#include <iostream>
#include <fstream>

int main()
{
	std::ifstream word;
	word.open("E:\\word.txt");

	std::string name;
	std::string lastname;
	int bigPrice = 0;
	int price = 0;
	std::string data;
	int sum = 0;

	while (!word.eof()) {
		word >> name >> lastname >> price >> data;
		if (price>bigPrice) {
			bigPrice = price;
		}
		sum += price;
		std::cout<< name <<" "<< lastname << " " << price << " " << data<<"\n";
	}
	std::cout << bigPrice<<"\n";
	std::cout << sum<<"\n";
}