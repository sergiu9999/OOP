#include "profilesHTML.h"

#include "exceptions.h"
#include <fstream>
#include <algorithm>
#include <regex>


#define inputIndexOfName 0
#define inputIndexOfProfession 1
#define inputIndexOfAge 2
#define inputIndexOfPhotograph 3


void profilesHTML::addProfile(const profiles& entity) {
	std::vector<profiles> listOfProfiles = this->getAll();

	if (std::find(listOfProfiles.begin(), listOfProfiles.end(), entity) != listOfProfiles.end())
		throw elementExists("Duplicate element!\n");

	listOfProfiles.push_back(entity);


	std::ofstream outFile(this->getFilePath());

	outFile << "<!DOCTYPE html>\n";
	outFile << "\t<html>\n";
	outFile << "\t\t<head>\n";
	outFile << "\t\t\t<title>Profiles</title>\n";
	outFile << "\t\t</head>\n";
	outFile << "\t<body>\n";
	outFile << "\t<table border=\"1\">\n";
	outFile << "\t<tr>\n";
	outFile << "\t\t<th>Name</th>\n";
	outFile << "\t\t<th>Profession</th>\n";
	outFile << "\t\t<th>Age</th>\n";
	outFile << "\t\t<th>Photograph</th>\n";
	outFile << "\t</tr>\n";

	for_each(listOfProfiles.begin(), listOfProfiles.end(), [&](profiles& file) { outFile << "\t<tr>\n";
			outFile << "\t\t<td>" + file.getName() + "</td>\n"; outFile << "\t\t<td>" + file.getProfession() + "</td>\n";
			outFile << "\t\t<td>" + std::to_string(file.getAge()) + "</td>\n"; outFile << "\t\t<td>" + file.getPhotograph() + "</td>\n";
			outFile << "\t</tr>\n"; });

	outFile << "\t</table>\n";
	outFile << "\t</body>\n";
	outFile << "\t</html>\n";
}


void profilesHTML::updateProfile(const profiles& newEntity) { }
void profilesHTML::deleteProfile(const profiles& entity) { }

void profilesHTML::setFilePath(std::string filePath) {
	std::ofstream open(filePath);
	this->filePath = filePath;
}

std::vector<profiles> profilesHTML::getAll() {

	std::ifstream inputFile(this->filePath);
	std::regex splitByTD("<td>(.*)</td>");
	std::vector<std::string> elements{};

	std::vector<std::string> newDataFromFile;
	std::vector<profiles> listOfProfiles{};

	while (!inputFile.eof())
	{
		std::string line;
		std::getline(inputFile, line);
		newDataFromFile.push_back(line);
	}


	for (unsigned int j = 0; j < newDataFromFile.size(); j++)
	{

		for (auto i = std::sregex_iterator(newDataFromFile[j].begin(), newDataFromFile[j].end(), splitByTD);
			i != std::sregex_iterator(); ++i) {
			std::smatch matched = *i;
			std::string element = matched.str();
			element.erase(0, 4);
			element.erase(element.end() - 5, element.end());
			elements.push_back(element);
		}
	}

	for (size_t i = 0; i < elements.size(); i += 4)
	{
		int age = std::stoi(elements[i + inputIndexOfAge]);
		std::string name = elements[i + inputIndexOfName];
		std::string profession = elements[i + inputIndexOfProfession];
		std::string photograph = elements[i + inputIndexOfPhotograph];

		profiles newProfile(name, profession, age, photograph);
		listOfProfiles.push_back(newProfile);
	}

	return listOfProfiles;
}

std::string profilesHTML::getFilePath() {
	return this->filePath;
}