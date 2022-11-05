#include "employee.h"

employee::employee(const std::string& name, const int age, const double salary, const int experience) {
	this->name_ = name;
	this->age_ = age;
	this->salary_ = salary;
	this->experience_ = experience;
}

std::string employee::get_name() {
	return this->name_;
}

int employee::get_age() const {
	return this->age_;
}

double employee::get_salary() const {
	return this->salary_;
}

int employee::get_experience() const {
	return this->experience_;
}

