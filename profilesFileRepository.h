#pragma once
#include "profilesRepository.h"


class profilesFileRepository : public VirtualRepository {
private:
	std::string filePath;
public:

	profilesFileRepository();

	void addProfile(const profiles& profile);
	void updateProfile(const profiles& newprofile);
	void deleteProfile(const profiles& profile);

	std::vector<profiles> getAll();
	void setFilePath(std::string filePath);
};

