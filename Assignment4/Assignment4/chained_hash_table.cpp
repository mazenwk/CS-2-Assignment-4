#include "chained_hash_table.h"

#include <iostream>

chained_hash_table::chained_hash_table(const int buckets) {
	this->size_ = buckets;
	for (int i = 0; i < this->size_; ++i) {
		this->table_.push_back(nullptr);
	}
}

void chained_hash_table::insert(const std::string& key, employee* value) {
	auto* new_node = new linked_node;
	new_node->key = value->get_name();
	new_node->value = value;
	new_node->next = nullptr;

	const unsigned int index = hash(key);

	if (this->table_[index] == nullptr) {
		this->table_[index] = new_node;
	} else {
		collisions_++;

		linked_node* itr = table_[index];
		while (itr->next != nullptr) {
			collisions_++;
			itr = itr->next;
		}
		itr->next = new_node;
	}

	this->count_++;
}

void chained_hash_table::remove(const std::string& key) {

	if (this->count_ > 0) {
		const unsigned int index = hash(key);

		if (this->table_[index]->key == key) {
			linked_node* t = this->table_[index]->next;
			delete this->table_[index]->value;
			delete this->table_[index];
			this->table_[index] = t;
		} else {
			linked_node* itr = table_[index];

			while (itr->next != nullptr && itr->next->key != key) {
				itr = itr->next;
			}

			if (itr->next != nullptr) {
				linked_node* t = itr->next->next;
				delete itr->next->value;
				delete itr->next;
				itr->next = t;
			}
		}

		this->count_--;
	} else {
		std::cout << "Hash table is empty!\n";
	}
}

void chained_hash_table::print() const {
	if (this->count_ > 0) {
		for (int i = 0; i < this->size_; ++i) {
			const linked_node* itr = this->table_[i];

			if (itr != nullptr) {
				std::cout << "[" << i << "] ";
				std::cout << itr->key << ": " << itr->value->get_age() << ", " << itr->value->get_salary() << ", " << itr->value->get_experience();

				while (itr->next != nullptr) {
					itr = itr->next;
					std::cout << " > " << itr->key << ":" << itr->value->get_age() << ", " << itr->value->get_salary() << ", " << itr->value->get_experience();
					i++;
				}

				std::cout << std::endl;
			} 
		}
	}
	else {
		std::cout << "Hash table is empty!\n";
	}
}

int chained_hash_table::get_size() const {
	return this->size_;
}

int chained_hash_table::get_count() const {
	return this->count_;
}

int chained_hash_table::get_collisions() const {
	return this->collisions_;
}

chained_hash_table::~chained_hash_table() {
	for (int i = 0; i < this->size_; ++i) {
		const linked_node* itr = this->table_[i];

		if (itr != nullptr) {
			while (itr != nullptr) {
				const linked_node* temp = itr->next;
				delete itr->value;
				delete itr;
				itr = temp;
			}
		}
	}
}

unsigned int chained_hash_table::hash(const std::string& key) const {
	constexpr int hash_constant { 31 };
	unsigned int hash_code{};

 	for (const char c : key) {
		hash_code = hash_code * hash_constant + c;
	}

	return hash_code % this->size_;
}
