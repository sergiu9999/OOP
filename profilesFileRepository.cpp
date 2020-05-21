#include "profilesFileRepository.h"
#include <fstream>
#include <algorithm>


profilesFileRepository::profilesFileRepository() {
	this->filePath = "";
}

void profilesFileRepository::addProfile(const profiles& profile) {

	std::ifstream input(this->filePath);
	std::vector<profiles> listOfProfiles;
	profiles currentProfile{};
	while (input >> currentProfile)
		listOfProfiles.push_back(currentProfile);

	auto iteratorToAdd = std::find(listOfProfiles.begin(), listOfProfiles.end(), profile);
	if (iteratorToAdd != listOfProfiles.end())
	{
		throw std::runtime_error("profile already exists");
	}
	listOfProfiles.push_back(profile);

	input.close();
	std::ofstream output(this->filePath);
	for_each(listOfProfiles.begin(), listOfProfiles.end(), [&output](auto& file) {output << file; });
}

void profilesFileRepository::updateProfile(const profiles& newprofile) {
	std::ifstream input(this->filePath);
	std::vector<profiles> listOfProfiles;
	profiles currentProfile{};
	while (input >> currentProfile)
		listOfProfiles.push_back(currentProfile);


	auto iteratorToUpdate = std::find(listOfProfiles.begin(), listOfProfiles.end(), newprofile);
	if (iteratorToUpdate == listOfProfiles.end())
	{
		throw std::runtime_error("profile not found");
	}
	(*iteratorToUpdate) = newprofile;

	input.close();
	std::ofstream output(this->filePath);
	for_each(listOfProfiles.begin(), listOfProfiles.end(), [&output](profiles file) {output << file; });
}

void profilesFileRepository::deleteProfile(const profiles& profile) {
	std::ifstream input(this->filePath);
	std::vector<profiles> listOfProfiles;
	profiles currentProfile;

	while (input >> currentProfile)
		listOfProfiles.push_back(currentProfile);


	auto iteratorToDelete = std::find(listOfProfiles.begin(), listOfProfiles.end(), profile);
	if (iteratorToDelete == listOfProfiles.end())
	{
		throw std::runtime_error("profile not found");
	}
	listOfProfiles.erase(iteratorToDelete);


	input.close();
	std::ofstream output(this->filePath);
	for_each(listOfProfiles.begin(), listOfProfiles.end(), [&output](profiles file) {output << file; });
}

std::vector<profiles> profilesFileRepository::getAll() {
	std::ifstream input(this->filePath);
	std::vector<profiles> listOfProfiles;


	profiles currentProfile;
	while (input >> currentProfile)
		listOfProfiles.push_back(currentProfile);

	return listOfProfiles;
}

void profilesFileRepository::setFilePath(std::string filePath) {
	this->filePath = filePath;
	std::ofstream open(filePath);
}
