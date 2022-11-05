#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "chained_hash_table.h"
#include "linear_hash_table.h"
#include <iostream>


void chained_hash_table_test() {
	auto* table = new chained_hash_table(21);

	table->insert("Mina", new employee("Mina", 30, 10000, 4));
	table->insert("Fawzy", new employee("Fawzy", 45, 5000, 8));
	table->insert("Yara", new employee("Yara", 19, 2000, 0));
	table->insert("Mariam", new employee("Mariam", 32, 8000, 2));
	table->insert("Ayman", new employee("Ayman", 33, 4000, 8));
	table->insert("Roshdy", new employee("Roshdy", 28, 9000, 3));
	table->insert("Aya", new employee("Aya", 26, 6000, 3));
	table->insert("Abdallah", new employee("Abdallah", 29, 5000, 4));
	table->insert("Fatma", new employee("Fatma", 21, 3000, 1));

	table->print();

	std::cout << '\n';
	table->remove("Mariam");
	table->print();

	std::cout << '\n';
	std::cout << "Collisions: " << table->get_collisions() << '\n';

	delete table;
}

void linear_hash_table_test() {
	auto* table = new linear_hash_table(21);

	table->insert("Mina", new employee("Mina", 30, 10000, 4));
	table->insert("Fawzy", new employee("Fawzy", 45, 5000, 8));
	table->insert("Yara", new employee("Yara", 19, 2000, 0));
	table->insert("Mariam", new employee("Mariam", 32, 8000, 2));
	table->insert("Ayman", new employee("Ayman", 33, 4000, 8));
	table->insert("Roshdy", new employee("Roshdy", 28, 9000, 3));
	table->insert("Aya", new employee("Aya", 26, 6000, 3));
	table->insert("Abdallah", new employee("Abdallah", 29, 5000, 4));
	table->insert("Fatma", new employee("Fatma", 21, 3000, 1));

	table->print();

	std::cout << '\n';
	table->remove("Mariam");
	table->print();

	std::cout << '\n';
	std::cout << "Collisions: " << table->get_collisions() << '\n';

	delete table;
}

int main()
{
	std::cout << "Chained Hash Table (Chaining): \n";
	chained_hash_table_test();

	std::cout << '\n';

	std::cout << "Linear Hash Table (Linear Probing): \n";
	linear_hash_table_test();

	std::cout << std::endl;

	_CrtDumpMemoryLeaks();
	return 0;
}