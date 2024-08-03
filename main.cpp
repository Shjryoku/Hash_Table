/* INCLUDES */
#include <iostream>
#include "hash_table.h"
/* INIT */
int main() {
	map<int, int> mMap;

	mMap.include(52, 1);
	mMap.include(513, 2);
	mMap.include(525, 1);
	mMap.include(51252, 3);
	mMap.include(6574, 5);
	mMap.include(9682, 62);

	std::cout << "key: " << 1 << '\t' << mMap.findValue(1) << std::endl;
	std::cout << "key: " << 2 << '\t' << mMap.findValue(2) << std::endl;
	std::cout << "key: " << 1 << '\t' << mMap.findValue(1) << std::endl;
	std::cout << "key: " << 3 << '\t' << mMap.findValue(3) << std::endl;
	std::cout << "key: " << 5 << '\t' << mMap.findValue(5) << std::endl;
	std::cout << "key: " << 62 << '\t' << mMap.findValue(62) << std::endl;

	mMap.destroyAll();

	return 0;
}
