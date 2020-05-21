#pragma once
#include "profilesController.h"
#include "profilesValidator.h"
#include <vector>

#define sizeOfCommand 100

class profilesUI {

private:
	profilesController service;
	std::string mode;

public:

	profilesUI(const profilesController& serviceParameter) : service{ serviceParameter }, mode{ "" } {}

	void start();

private:

	std::string getCommandType(std::string command);
	void getCommand(std::string command, std::string commandWords[sizeOfCommand]);

	void listAll();
	void setFilePath(std::string filePath);
};

