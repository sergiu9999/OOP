#pragma once
#include "VirtualRepository.h"
#include "profilesValidator.h"

class profilesCSV : public VirtualRepository
{
private:
	std::string filePath;
public:
	profilesCSV() {}
	~profilesCSV() {}


	void addProfile(const profiles& entity) override;
	void updateProfile(const profiles& newEntity) override;
	void deleteProfile(const profiles& entity)override;

	void setFilePath(std::string filePath)override;
	std::vector<profiles> getAll() override;
	std::string getFilePath();
	std::vector<std::string> splitDelimiterr(std::string line, std::string delimiter);
};