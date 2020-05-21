#include "profiles.h"
#include <string>

#define inputIndexOfName 0
#define inputIndexOfProfession 1
#define inputIndexOfAge 2
#define inputIndexOfPhotograph 3

profiles::profiles(std::string name, std::string profession, int age, std::string photograph) {
	this->name = name;
	this->profession = profession;
	this->age = age;
	this->photograph = photograph;
}

profiles::profiles(std::string name) {
	this->name = name;
	this->profession = "";
	this->age = 0;
	this->photograph = "";
}

profiles::profiles() {
	this->name = "";
	this->profession = "";
	this->age = 0;
	this->photograph = "";
}

bool profiles::operator==(const profiles& profiles) {
	if (this->name == profiles.name)
		return true;
	return false;
}



std::vector<std::string> profiles::splitDelimiter(std::string line, std::string delimiter) {
	std::vector<std::string> splitLine;
	int position = 0;
	while ((position = line.find(delimiter)) != std::string::npos) {
		std::string token = line.substr(0, position);
		splitLine.push_back(token);
		line.erase(0, delimiter.length() + position);
	}
	splitLine.push_back(line);
	return splitLine;
}

std::string profiles::getName() { return this->name; }

std::string profiles::getProfession() { return this->profession; }

int profiles::getAge() { return this->age; }

std::string profiles::getPhotograph() { return this->photograph; }


void profiles::setName(std::string newName) { this->name = newName; }

void profiles::setProfession(std::string newProfession) { this->profession = newProfession; }

void profiles::setAge(int newAge) { this->age = newAge; }

void profiles::setPhotograph(std::string newPhotograph) { this->photograph = newPhotograph; }


std::string profiles::getPrintFormat() const {
	return name + " " + profession + " " + std::to_string(age) + " " + photograph + "\n";
}

std::string profiles::getCSVFormat() const {
	return name + "," + profession + "," + std::to_string(age) + "," + photograph + "\n";
}


std::istream& operator>>(std::istream& inputStream,  profiles& profile) {


	std::string  line;
	std::getline(inputStream, line);

	std::vector<std::string> tokens = profile.splitDelimiter(line, ",");
	if (tokens.size() != 4)
		return inputStream;

	profile.name = tokens[inputIndexOfName];
	profile.profession = tokens[inputIndexOfProfession];
	profile.age = std::stoi(tokens[inputIndexOfAge]);
	profile.photograph = tokens[inputIndexOfPhotograph];
	return inputStream;

}

std::ostream& operator<<(std::ostream& outputStream, const profiles& profiles) {
	outputStream << profiles.getCSVFormat();
	return outputStream;
}
