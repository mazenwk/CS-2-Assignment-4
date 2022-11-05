#pragma once

#include "employee.h"
#include <string>
#include <vector>

class linear_hash_table
{
public:
	explicit linear_hash_table(int buckets);
	void insert(const std::string& key, employee* value);
	void remove(const std::string& key);
	void print() const;
	int get_size() const;
	int get_count() const;
	int get_collisions() const;
	~linear_hash_table();

private:
	int size_{};
	int count_{};
	int collisions_{};
	std::vector<employee*> table_;
	unsigned int hash(const std::string& key) const;
};

