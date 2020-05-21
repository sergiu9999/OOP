#pragma once
#include "profilesRepository.h"
#include <vector>
#include "profiles.h"
#include "profilesHTML.h"
#include "profilesCSV.h"
#include "profilesFileRepository.h"
#include "profilesValidator.h"
#include "exceptions.h"

class profilesController {

private:

	VirtualRepository* repository;
	profilesRepository quarantined{ };
	VirtualRepository* newQuarantined;
	int isHtmlOrCsv;
	int indexNext;
	profilesValidator validator;

public:
	profilesController() {}
	profilesController(VirtualRepository* repository);

	void addProfile(std::string name, std::string profession, int age, std::string photograph);
	void updateProfile(std::string newName, std::string newProfession, int newAge, std::string newPhotograph);
	void deleteProfileByName(std::string name);

	std::vector<profiles> getAll();
	profiles next();
	void save(std::string name);

	std::vector<profiles> getMyList();
	std::vector<profiles> filterProfessionAndAge(std::string profession, int age);

	void setFilePath(std::string filePath);
	void htmlQuarantined(std::string filePath);
	void csvQuarantined(std::string filePath);

};

