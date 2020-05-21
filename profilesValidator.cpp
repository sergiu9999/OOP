#include "profilesValidator.h"

void profilesValidator::profilesValid( profiles profile) {
	int age = profile.getAge();
	std::string name = profile.getName();
	std::string profession = profile.getProfession();
	std::string photograph = profile.getPhotograph();

	

	if (age < 0)
	{
		throw validInput("Profile cannot have negative age!");
	}

	if (name == "")
	{
		throw validInput("Profile cannot have an empty name!");
	}
	std::string jpg = ".jpg";
	std::string png = ".png";
	std::size_t foundJpg = photograph.find(jpg);
	std::size_t foundPng = photograph.find(png);

	if (foundJpg == std::string::npos && foundPng == std::string::npos)
	{
		throw validInput("Profile cannot have a photograph with no type!");
	}


}
