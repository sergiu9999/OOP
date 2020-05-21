#include "profilesCSV.h"
#include <regex>

#define inputIndexOfName 0
#define inputIndexOfProfession 1
#define inputIndexOfAge 2
#define inputIndexOfPhotograph 3

std::vector<std::string> profilesCSV::splitDelimiterr(std::string line, std::string delimiter) {
	std::vector<std::string> splitLine;
	int position = 0;
	while ((position = line.find(delimiter)) != std::string::npos) {
		std::string token = line.substr(0, position);
		splitLine.push_back(token);
		line.erase(0, delimiter.length() + position);
	}
	splitLine.push_back(line);
	return splitLine;
}

void profilesCSV::addProfile(const profiles& entity)
{
    std::vector<profiles> listOfProfiles = this->getAll();

    auto iteratorWhereTapeIsFound = std::find(listOfProfiles.begin(), listOfProfiles.end(), entity);
    if (iteratorWhereTapeIsFound != listOfProfiles.end())
        throw elementExists("Duplicate element!");
    listOfProfiles.push_back(entity);

    std::ofstream outFile(this->getFilePath());

    outFile << "Name, Profession, Age, Photograph\n";
    if (listOfProfiles.empty())
        return;
    for (profiles profileToStore : listOfProfiles) {
        outFile << '"' << profileToStore.getName() << "\","
            << '"' << profileToStore.getProfession() << "\","
            << '"' << profileToStore.getAge() << "\","
            << '"' << profileToStore.getPhotograph() << '"' << "\n";
    }
    outFile.close();
}


void profilesCSV::updateProfile(const profiles& newEntity) {}

void profilesCSV::deleteProfile(const profiles& entity) {}


void profilesCSV::setFilePath(std::string filePath)
{
	this->filePath = filePath;
}

std::vector<profiles> profilesCSV::getAll()
{
	std::ifstream inputFile(this->filePath);
	std::vector<std::string> elements{};
	std::string word;

	std::vector<std::vector<std::string>> newDataFromFile;
	std::vector<profiles> listOfProfiles{};
	std::string newLine;

	std::getline(inputFile, newLine);

	while (!inputFile.eof())
	{
		std::string line;
		std::getline(inputFile, line);
		newLine = "";
		if (line == "\n" || line == "")
		{
			break;
		}
		for (unsigned int i = 0; i < line.length(); i++)
		{
			if (line[i] != '"')
			{
				newLine += line[i];
			}
		}

		std::vector<std::string> tokens = this->splitDelimiterr(newLine, ",");
		newDataFromFile.push_back(tokens);
	}


	for (int i = 0; i < newDataFromFile.size(); i++)
	{
		profiles profileToAdd(newDataFromFile[i][0], newDataFromFile[i][1], std::stoi(newDataFromFile[i][2]), newDataFromFile[i][3]);
		listOfProfiles.push_back(profileToAdd);
	}

	inputFile.close();

	return listOfProfiles;
}

std::string profilesCSV::getFilePath()
{
	return this->filePath;
}