#pragma once

#include "employee.h"
#include <string>

struct linked_node {
	std::string key{};
	employee* value{};
	linked_node* next{};
};
