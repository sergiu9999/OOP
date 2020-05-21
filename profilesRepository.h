#pragma once
#include <stdexcept>
#include "profiles.h"
#include <vector>
#include "VirtualRepository.h"
#include "profilesValidator.h"
#include "exceptions.h"


class profilesRepository : public VirtualRepository {

private:
	std::vector<profiles> data;

public:
	profilesRepository() {}

	void addProfile(const profiles& element);
	void updateProfile(const profiles& newElement);
	void deleteProfile(const profiles& element);

	std::vector<profiles> getAll();
	void setFilePath(std::string filePath) {}
};


