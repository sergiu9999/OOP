#pragma once

#include <exception>
#include <stdexcept>
#include <string>


class validInput : public std::exception {
private:
	std::string message;
public:
	validInput(std::string message) : message{ message } {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};


class elementNotFound : public std::runtime_error {
public:
	elementNotFound(std::string message) : std::runtime_error(message) {}
};

class emptyList : public std::runtime_error {
public:
	emptyList(std::string message) : std::runtime_error(message) {}
};


class elementExists : public std::runtime_error {
public:
	elementExists(std::string message) : std::runtime_error(message) {}
};

