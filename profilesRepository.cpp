#include "profilesRepository.h"
#include <algorithm>


void profilesRepository::addProfile(const profiles& element) {
	if (std::find(data.begin(), data.end(), element) != data.end())
	{
		throw elementExists("Element already exists");
	}
	this->data.push_back(element);
}

void profilesRepository::updateProfile(const profiles& newElement) {
	auto iteratorToUpdate = std::find(data.begin(), data.end(), newElement);
	if (iteratorToUpdate == data.end())
	{
		throw elementNotFound("element not found");
	}
	(*iteratorToUpdate) = newElement;
}

void profilesRepository::deleteProfile(const profiles& element) {
	auto iteratorToDelete = std::find(data.begin(), data.end(), element);
	if (iteratorToDelete == data.end())
	{
		throw elementNotFound("Element not found");
	}
	this->data.erase(iteratorToDelete);
}

std::vector <profiles> profilesRepository::getAll() {
	return this->data;
}
