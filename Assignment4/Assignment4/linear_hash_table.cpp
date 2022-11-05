#include "linear_hash_table.h"

#include <iostream>

linear_hash_table::linear_hash_table(const int buckets) {
	this->size_ = buckets;
	for (int i = 0; i < this->size_; ++i) {
		this->table_.push_back(nullptr);
	}
}

void linear_hash_table::insert(const std::string& key, employee* value) {
	unsigned int index = hash(key);

	if (this->table_[index] == nullptr) {
		this->table_[index] = value;
	} else {
		while (this->table_[index] != nullptr) {
			collisions_++;
			index++;
			if (index >= this->size_) {
				index = 0;
			}
		}
		this->table_[index] = value;
	}
}

void linear_hash_table::remove(const std::string& key) {
	unsigned int index = hash(key);

	while (this->table_[index] != nullptr && this->table_[index]->get_name() != key) {
		index++;
	}

	delete this->table_[index];
	this->table_[index] = nullptr;
}

void linear_hash_table::print() const {
	for (const auto& emp : this->table_) {
		if (emp != nullptr) {
			std::cout << emp->get_name() << ": " << emp->get_age() << ", " << emp->get_salary() << ", " << emp->get_experience() << '\n';
		}
	}
}

int linear_hash_table::get_size() const {
	return this->size_;
}

int linear_hash_table::get_count() const {
	return this->count_;
}

int linear_hash_table::get_collisions() const {
	return this->collisions_;
}

linear_hash_table::~linear_hash_table() {
	for (const auto& emp : this->table_) {
		delete emp;
	}
}

unsigned int linear_hash_table::hash(const std::string& key) const {
	constexpr int hash_constant{31};
	unsigned int hash_code{};

	for (const char c : key) {
		hash_code = hash_code * hash_constant + c;
	}

	return hash_code % this->size_;
}
