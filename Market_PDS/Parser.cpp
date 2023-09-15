#include "Parser.h"

vector<string> parser::split(string line)
{
	stringstream s(line);
	vector<string> info;
	string data;
	while (getline(s, data, '|'))
	{
		info.push_back(data);
	}
	return info;
}

seller parser::parserToSeller(string line) {
	vector<string> data = split(line);
	seller s(stoi(data[0]), data[1], data[2]);
	s.setrate(stof(data[3]));
	s.setCountRate(stoi(data[4]));
	return s;
}

customer parser::parserToCustomer(string line) {
	vector<string> data = split(line);
	customer c(stoi(data[0]), data[1], data[2], data[3], data[4]);
	return c;
}

product parser::parserToProduct(string line) {
	vector<string> data = split(line);
	product p(stoi(data[0]), data[1], stod(data[2]), data[3], stoi(data[4]), stoi(data[5]));
	p.setrate(stof(data[6]));
	p.setCountRate(stoi(data[7]));
	return p;
}