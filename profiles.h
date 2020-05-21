#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class profiles {

private:
	std::string name;
	std::string profession;
	int age;
	std::string photograph;

public:
	profiles(std::string name, std::string profession, int age, std::string photograph);
	profiles(std::string name);
	profiles();


	std::vector<std::string> splitDelimiter(std::string line, std::string delimiter);
	
	std::string  getName();
	std::string getProfession();
	int getAge();
	std::string getPhotograph();

	void setName(std::string newName);
	void setProfession(std::string newProfession);
	void setAge(int newAge);
	void setPhotograph(std::string newPhotograph);

	std::string getPrintFormat() const;
	std::string getCSVFormat() const; 

	bool operator==(const profiles& profile);
	friend std::istream& operator>>(std::istream& inputStream,  profiles& profile);
	friend std::ostream& operator<<(std::ostream& outputStream, const profiles& profile);


};

