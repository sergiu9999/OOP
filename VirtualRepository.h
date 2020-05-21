#pragma once
#include "profiles.h"
#include <vector>


class VirtualRepository {
public:

	virtual void addProfile(const profiles& profile) = 0;
	virtual void updateProfile(const profiles& newprofile) = 0;
	virtual void deleteProfile(const profiles& profile) = 0;
	
	virtual std::vector<profiles> getAll() = 0;
	virtual void setFilePath(std::string filePath) = 0;
};

