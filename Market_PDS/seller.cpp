#include "seller.h"
seller::seller(int id, string name, string email) : person(id, name, email) {
}

map <string, seller> seller::allseller;
map <string, seller>::iterator seller::itSeller;

void seller::IncrementCountRate() {
	ratcount++;
}
void seller::setrate(float rate) {
	this->rate = rate;
}
void seller::setCountRate(int ratcount) {
	this->ratcount = ratcount;
}
int seller::getratnum() { return ratcount; }

float seller::getRate() {
	return rate;
}