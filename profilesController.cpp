#include <algorithm>
#include "profilesController.h"


profilesController::profilesController(VirtualRepository* repository) {
	this->repository = repository;
	this->indexNext = 0;
	this->isHtmlOrCsv = 0;
	this->newQuarantined = nullptr;
}

void profilesController::addProfile(std::string name, std::string Profession, int age, std::string photograph) {

	profiles profiles{ name, Profession, age, photograph };
	validator.profilesValid(profiles);
	this->repository->addProfile(profiles);
}

void profilesController::updateProfile(std::string newName, std::string newProfession, int newAge, std::string newPhotograph) {
	profiles newprofiles{ newName, newProfession, newAge, newPhotograph };
	validator.profilesValid(newprofiles);
	this->repository->updateProfile(newprofiles);
}

void profilesController::deleteProfileByName(std::string name) {
	profiles profilesToBeDeleted{ name };
	this->repository->deleteProfile(profilesToBeDeleted);
}


std::vector<profiles> profilesController::getAll() {
	return this->repository->getAll();
}


profiles profilesController::next() {
	std::vector<profiles> listOfProfiles = this->getAll();
	if (listOfProfiles.size() == 0)
	{
		throw emptyList("No profiles");
	}

	if (this->indexNext == listOfProfiles.size())
		this->indexNext = 0;

	profiles foundProfile = listOfProfiles[this->indexNext++];
	return foundProfile;
}


void profilesController::save(std::string name) {
	std::vector<profiles> listOfProfiles = this->getAll();
	
	auto currentProfile = std::find_if(listOfProfiles.begin(), listOfProfiles.end(), [name](auto profile) {return profile.getName() == name; });
	if (currentProfile == listOfProfiles.end())
	{
		throw elementNotFound("Profile not found");
	}
	if (this->isHtmlOrCsv)
	{
		this->newQuarantined->addProfile(*currentProfile);
	} else {
		this->quarantined.addProfile(*currentProfile);
	}
}


std::vector<profiles> profilesController::getMyList() {
	if (this->isHtmlOrCsv)
	{
		return this->newQuarantined->getAll();
	}
	return this->quarantined.getAll();
}


std::vector<profiles> profilesController::filterProfessionAndAge(std::string Profession, int age) {
	std::vector<profiles> listOfProfiles = this->getAll();
	std::vector<profiles> listOfFilteredProfiles(listOfProfiles.size());

	if (Profession != "")
	{
		auto lastIterator = std::copy_if(listOfProfiles.begin(), listOfProfiles.end(), listOfFilteredProfiles.begin(),
			[Profession, age](auto profile) {return profile.getProfession() == Profession && profile.getAge() < age; });
		listOfFilteredProfiles.resize(std::distance(listOfFilteredProfiles.begin(), lastIterator));
		return listOfFilteredProfiles; } else {
		auto lastIterator = std::copy_if(listOfProfiles.begin(), listOfProfiles.end(), listOfFilteredProfiles.begin(),
			[age](auto profile) {return profile.getAge() < age; });
		listOfFilteredProfiles.resize(std::distance(listOfFilteredProfiles.begin(), lastIterator));
		return listOfFilteredProfiles; } }


void profilesController::setFilePath(std::string filePath) {
	this->repository->setFilePath(filePath);
}

void profilesController::htmlQuarantined(std::string filePath)
{
	profilesHTML* newHtmlRepository = new profilesHTML;
	newHtmlRepository->setFilePath(filePath);
	this->newQuarantined = newHtmlRepository;
	this->isHtmlOrCsv = 1;
}

void profilesController::csvQuarantined(std::string filePath)
{
	profilesCSV* newCsvRepository = new profilesCSV;
	newCsvRepository->setFilePath(filePath);
	this->newQuarantined = newCsvRepository;
	this->isHtmlOrCsv = 1;
}

