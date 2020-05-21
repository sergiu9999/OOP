#pragma once
#include "VirtualRepository.h"
#include <string>

class profilesHTML : public VirtualRepository {
public:
	std::string filePath;

public:
	profilesHTML() {}
	~profilesHTML() {}


	void addProfile(const profiles& entity) override;
	void updateProfile(const profiles& newEntity) override;
	void deleteProfile(const profiles& entity)override;

	void setFilePath(std::string filePath) override;
	std::vector<profiles> getAll() override;
	std::string getFilePath();
};

