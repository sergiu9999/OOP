#include "profilesUI.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>

#define inputIndexOfName 0
#define inputIndexOfProfession 1
#define inputIndexOfAge 2
#define inputIndexOfPhotograph 3

std::string profilesUI::getCommandType(std::string command)
{
	std::string commandType = "";
	for (auto letter : command)
	{
		if (letter == ' ' || letter == '\n')
		{
			return commandType;
		} else {
			commandType += letter;
		}
	}
	return commandType;
}

void profilesUI::getCommand(std::string command, std::string commandWords[sizeOfCommand])
{
	std::string word;
	int indexOfWord = 0;

	int indexToEraseCommandTypeFromCommand = 0;

	for (auto letter : command)
	{
		if (letter == ' ')
		{
			command.erase(0, indexToEraseCommandTypeFromCommand + 1);
			break;
		}
		else {
			indexToEraseCommandTypeFromCommand++;
		}
	}

	for (unsigned int i = 0; i < command.length(); i++)
	{
		if (command[i] == ',')
		{
			commandWords[indexOfWord++] = word;
			word = "";
			i++;
		}
		else {
			word += command[i];
		}
	}
	commandWords[indexOfWord++] = word;
}

void profilesUI::start() {

	std::string fileToOpen = "";
	while (true) {
		std::string choice;
		std::getline(std::cin, choice);

		if (choice == "exit")
			break;
		if (choice == "mode A") {
			this->mode = "mode A";
			continue;
		}
		if (choice == "mode B") {
			this->mode = "mode B";
			continue;
		}

		std::string commandType = getCommandType(choice);
		std::string command[sizeOfCommand];
		getCommand(choice, command);

		if (commandType == "fileLocation") {
			this->setFilePath(command[0]);
			continue;
		}

		if (commandType == "mylistLocation")
		{
			std::string html = ".html";
			std::string csv = ".csv";
			std::size_t foundHtml = command[0].find(html);
			std::size_t foundCsv = command[0].find(csv);

			if (foundHtml != std::string::npos && foundCsv == std::string::npos)
			{
				this->service.htmlQuarantined(command[0]);
			} else {
				if (foundHtml == std::string::npos && foundCsv != std::string::npos)
				{
					this->service.csvQuarantined(command[0]);
				}
				else {
					std::cout << "Incorrect file type!\n";
				}
			}
			fileToOpen = command[0];
		}

		if (this->mode == "mode A") {



			if (commandType == "list")
				this->listAll();
			if (commandType == "add")
			{
				std::string name = command[inputIndexOfName];
				std::string profession = command[inputIndexOfProfession];
				std::string photograph = command[inputIndexOfPhotograph];
				int age = std::stoi(command[inputIndexOfAge]);

				try {
					this->service.addProfile(name, profession, age, photograph);
				}
				catch (std::exception & e) {
					std::cout << e.what()<<'\n';
				}
			}
			if (commandType == "update")
			{
				std::string newName = command[inputIndexOfName];
				std::string newProfession = command[inputIndexOfProfession];
				std::string newPhotograph = command[inputIndexOfPhotograph];
				int newAge = std::stoi(command[inputIndexOfAge]);
			
				
				try {
					this->service.updateProfile(newName, newProfession, newAge, newPhotograph);
				}
				catch (std::runtime_error) {
					std::cout << "No!\n";
				}
			}
			if (commandType == "delete")
			{

				std::string name = command[inputIndexOfName];

				if (name.empty()) {
					std::cout << "No!\n";
					return;
				}

				try {
					this->service.deleteProfileByName(name);
				}
				catch (std::runtime_error) {
					std::cout << "No!\n";
				}
			}
		} else {
			if (commandType == "next")
			{
				try {
					profiles profile = this->service.next();
					std::cout << profile.getPrintFormat();
				}
				catch (std::runtime_error) {
					std::cout << "No\n";
				}
			}
			if (commandType == "save")
			{
				try {


					this->service.save(command[inputIndexOfName]);
				}
				catch (std::runtime_error) {
					std::cout << "No!\n";
				}
			}

			if (commandType == "list")
			{
				int ageIndex = 1;
				int professionIndex = 0;
				std::string profession = command[professionIndex];
				int age;
				try
				{
					age = std::stoi(command[ageIndex]);
				}
				catch (...)
				{
					age = std::stoi(command[0]);
					profession = "";
				}
				std::vector<profiles> allFiles = this->service.filterProfessionAndAge(profession, age);
				for (auto file : allFiles)
				{
					std::cout << file.getPrintFormat();
				}
			}
			if (commandType == "mylist")
			{
				std::vector<profiles> allFiles = this->service.getMyList();

				for (auto file : allFiles)
				{
					std::cout << file.getPrintFormat();
				}
					
			}

			if (commandType == "show")
			{
			
				system(fileToOpen.c_str());
			}
		}
	}
}

void profilesUI::listAll() {
	std::vector<profiles> allFiles = this->service.getAll();

	for (auto file : allFiles)
		std::cout << file.getPrintFormat();
}

void profilesUI::setFilePath(std::string filePath) {
	this->service.setFilePath(filePath);
}
