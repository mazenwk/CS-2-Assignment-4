#pragma once

#include "employee.h"
#include "linked_node.h"
#include <vector>

class chained_hash_table
{
public:
	explicit chained_hash_table(int buckets);
	void insert(const std::string& key, employee* value);
	void remove(const std::string& key);
	void print() const;
	int get_size() const;
	int get_count() const;
	int get_collisions() const;
	~chained_hash_table();

private:
	int size_{};
	int count_{};
	int collisions_{};
	std::vector<linked_node*> table_;
	unsigned int hash(const std::string& key) const;
};

