#pragma once

#include <string>

class employee {
public:
	employee(const std::string& name, int age, double salary, int experience);
	std::string get_name();
	int get_age() const;
	double get_salary() const;
	int get_experience() const;

private:
	std::string name_{};
	int age_{};
	double salary_{};
	int experience_{};
};

