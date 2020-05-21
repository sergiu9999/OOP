#include "Test.h"
#include <vector>
#include "profilesRepository.h"
#include "profilesController.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include "profilesFileRepository.h"


void Test::testAll() {
	Test::AddElementFile_ValidInput_AddedToRepository();
	Test::AddElementFile_SameObjectTwice_ThrowException();
	Test::UpdateElementFile_ValidInput_UpdatedProfile();
	Test::UpdateElementFile_ProfileDoesNotExist_ThrowException();
	Test::DeleteEntiryFile_ValidInput_DeletedProfile();
	Test::DeleteEntiryFile_ProfileDoesNotExist_ThrowException();
	Test::GetAllFile_ValidInput_GetAllEntities();
	
	Test::AddElement_ValidInput_AddedToRepository();
	Test::AddElement_SameObjectTwice_ThrowException();
	Test::UpdateElement_ValidInput_UpdatedProfile();
	Test::UpdateElement_ProfileDoesNotExist_ThrowException();
	Test::DeleteEntiry_ValidInput_DeletedProfile();
	Test::DeleteEntiry_ProfileDoesNotExist_ThrowException();
	Test::GetAll_ValidInput_GetAllEntities();

	Test::AddProfile_ValidInput_AddedToRepository();
	Test::AddProfile_SameObjectTwice_ThrowException();
	Test::UpdateProfile_ValidInput_UpdatedProfile();
	Test::UpdateProfile_ProfileDoesNotExist_ThrowException();
	Test::DeleteProfileByName_ValidInput_DeletedProfile();
	Test::DeleteProfileByName_ProfileDoesNotExist_ThrowException();
	Test::Next_ShouldReturnExpectedFile();
	Test::Save_ShouldSaveTheWantedFile();


	Test::FilterProfessionAndAge_BothParameters_ShouldReturnFilteredProfiles();
	Test::FilterProfessionAndAge_OnlyAgeParameter_ShouldReturnFilteredProfiles();

	Test::GetName_ValidInput_ReturnName();
	Test::GetAge_ValidInput_ReturnAge();
	Test::GetProfession_ValidInput_ReturnProfession();
	Test::GetPhotograph_ValidInput_ReturnPhotograph();
	Test::SetName_ValidInput_SetName();
	Test::SetAge_ValidInput_SetAge();
	Test::SetProfession_ValidInput_SetProfession();
	Test::SetPhotograph_ValidInput_SetPhotograph();
	Test::GetFormat_ReturnExpectedFormat();

}


void Test::AddElementFile_ValidInput_AddedToRepository() {
	profilesFileRepository repository{};
	repository.setFilePath("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	assert(repository.getAll()[0] == profile);
	remove("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
}

void Test::AddElementFile_SameObjectTwice_ThrowException() {
	profilesFileRepository repository{};
	repository.setFilePath("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	bool exceptionThrown = false;
	try {
		repository.addProfile(profile);}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	remove("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
}

void Test::UpdateElementFile_ValidInput_UpdatedProfile() {
	profilesFileRepository repository{};
	repository.setFilePath("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	profiles newfile{ "Andrei", "barosan", 19, "dude.jpg" };
	repository.updateProfile(newfile);
	assert(repository.getAll()[0].getAge() == 19);
	remove("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
}

void Test::UpdateElementFile_ProfileDoesNotExist_ThrowException() {
	profilesFileRepository repository{};
	repository.setFilePath("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
	profiles newFile{ "Andrei", "barosan", 10, "dude.jpg" };
	bool exceptionThrown = false;
	try {
		repository.updateProfile(newFile);}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	remove("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
}

void Test::DeleteEntiryFile_ValidInput_DeletedProfile() {
	profilesFileRepository repository{};
	repository.setFilePath("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	repository.deleteProfile(profile);
	assert(repository.getAll().size() == 0);
	remove("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
}

void Test::DeleteEntiryFile_ProfileDoesNotExist_ThrowException() {
	profilesFileRepository repository{};
	repository.setFilePath("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
	profiles newFile{ "Andrei", "barosan", 10, "dude.jpg" };
	bool exceptionThrown = false;
	try {
		repository.deleteProfile(newFile);}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	remove("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
}

void Test::GetAllFile_ValidInput_GetAllEntities() {
	profilesFileRepository repository{};
	repository.setFilePath("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	profiles newfile{ "Radu", "barosanus", 19, "myMan.jpg" };
	repository.addProfile(newfile);
	assert(repository.getAll().size() == 2);
	remove("C:\\Users\\flutu\\Desktop\\POO laboratoare visual\\NewBigShot\\NewBigShot\\NewBigShot\\profilesTestFile.txt");
}





void Test::AddElement_ValidInput_AddedToRepository() {
	profilesRepository repository{};
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	assert(repository.getAll()[0] == profile);
}


void Test::AddElement_SameObjectTwice_ThrowException() {
	profilesRepository repository{};
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	bool exceptionThrown = false;
	try {
		repository.addProfile(profile);}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
}


void Test::UpdateElement_ValidInput_UpdatedProfile() {
	profilesRepository repository{};
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	profiles newfile{ "Andrei", "bagabondu", 19, "dude.jpg" };
	repository.updateProfile(newfile);
	assert(repository.getAll()[0].getAge() == 19);
}


void Test::UpdateElement_ProfileDoesNotExist_ThrowException() {
	profilesRepository repository{};
	profiles newFile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.setFilePath("none");
	bool exceptionThrown = false;
	try {
		repository.updateProfile(newFile);}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
}


void Test::DeleteEntiry_ValidInput_DeletedProfile() {
	profilesRepository repository{};
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	repository.deleteProfile(profile);
	assert(repository.getAll().size() == 0);
}


void Test::DeleteEntiry_ProfileDoesNotExist_ThrowException() {
	profilesRepository repository{};
	profiles newFile{ "Andrei", "barosan", 10, "dude.jpg" };
	bool exceptionThrown = false;
	try {
		repository.deleteProfile(newFile);}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
}


void Test::GetAll_ValidInput_GetAllEntities() {
	profilesRepository repository{};
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	repository.addProfile(profile);
	profiles newfile{ "Radu", "barosanus", 19, "myMan.jpg" };
	repository.addProfile(newfile);
	assert(repository.getAll().size() == 2);
}


void Test::AddProfile_ValidInput_AddedToRepository() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	controller.addProfile("Andrei", "barosan", 10, "dude.jpg");
	assert(controller.getAll()[0].getAge() == 10);
	delete repository;
}


void Test::AddProfile_SameObjectTwice_ThrowException() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	controller.addProfile("Andrei", "barosan", 10, "dude.jpg");
	bool exceptionThrown = false;
	try {
		controller.addProfile("Andrei", "barosan", 10, "dude.jpg");}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	delete repository;
}


void Test::UpdateProfile_ValidInput_UpdatedProfile() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	controller.addProfile("Andrei", "barosan", 10, "dude.jpg");
	controller.updateProfile("Andrei", "barosan", 21, "dude.jpg");
	assert(controller.getAll()[0].getAge() == 21);
	delete repository;
}


void Test::UpdateProfile_ProfileDoesNotExist_ThrowException() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	bool exceptionThrown = false;
	try {
		controller.updateProfile("Andrei", "barosan", 10, "dude.jpg");}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	delete repository;
}


void Test::DeleteProfileByName_ValidInput_DeletedProfile() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	controller.addProfile("Andrei", "barosan", 10, "dude.jpg");
	controller.deleteProfileByName("Andrei");
	assert(controller.getAll().size() == 0);
	delete repository;
}

void Test::Next_ShouldReturnExpectedFile() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	bool exceptionThrown = false;

	try {
		controller.next();}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}

	assert(exceptionThrown);
	controller.addProfile("Andrei", "barosan", 10, "dude.jpg");
	assert(controller.next() == profiles("Andrei", "barosan", 10, "dude.jpg"));
	assert(controller.next() == profiles("Andrei", "barosan", 10, "dude.jpg"));
	delete repository;
}

void Test::Save_ShouldSaveTheWantedFile() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	controller.setFilePath("none");
	controller.addProfile("Andrei", "barosan", 10, "dude.jpg");

	bool exceptionThrown = false;
	try {
		controller.save("yes");}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	
	controller.save("Andrei");
	std::vector<profiles> myList = controller.getMyList();
	assert(myList.back() == profiles("Andrei", "barosan", 10, "dude.jpg"));
	delete repository;
}

void Test::FilterProfessionAndAge_BothParameters_ShouldReturnFilteredProfiles() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	controller.addProfile("Andrei", "barosan", 10, "qql.jpg");
	controller.addProfile("Radu", "piratu", 21, "qqQ.jpg");
	controller.addProfile("Peter", "jmecher", 25, "Ttt.jpg");
	controller.addProfile("BarbaNeagra", "barosan", 5, "qqq.jpg");

	std::vector<profiles> wantedFiles = controller.filterProfessionAndAge("barosan", 11);
	assert(wantedFiles.size() == 2);
	delete repository;
}

void Test::FilterProfessionAndAge_OnlyAgeParameter_ShouldReturnFilteredProfiles() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	controller.addProfile("Andrei", "barosan", 10, "qql.jpg");
	controller.addProfile("Radu", "piratu", 21, "qqQ.jpg");
	controller.addProfile("Peter", "jmecher", 25, "Ttt.jpg");
	controller.addProfile("BarbaNeagra", "barosan", 5, "qqq.jpg");

	std::vector<profiles> wantedFiles = controller.filterProfessionAndAge("", 30);
	assert(wantedFiles.size() == 4);
	delete repository;
}

void Test::DeleteProfileByName_ProfileDoesNotExist_ThrowException() {
	profilesRepository* repository = new profilesRepository{};
	profilesController controller{ repository };
	bool exceptionThrown = false;
	try {
		controller.deleteProfileByName("Andrei");}
	catch (std::runtime_error) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	delete repository;
}



void Test::GetName_ValidInput_ReturnName() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	assert(profile.getName() == "Andrei");
}



void Test::GetProfession_ValidInput_ReturnProfession() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	assert(profile.getProfession() == "barosan");
}

void Test::GetAge_ValidInput_ReturnAge() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	assert(profile.getAge() == 10);
}

void Test::GetPhotograph_ValidInput_ReturnPhotograph() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	assert(profile.getPhotograph() == "dude.jpg");
}


void Test::SetName_ValidInput_SetName() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	profile.setName("Qqq");
	assert(profile.getName() == "Qqq");
}


void Test::SetProfession_ValidInput_SetProfession() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	profile.setProfession("camatarSef");
	assert(profile.getProfession() == "camatarSef");
}


void Test::SetAge_ValidInput_SetAge() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	profile.setAge(20);
	assert(profile.getAge() == 20);
}


void Test::SetPhotograph_ValidInput_SetPhotograph() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };
	profile.setPhotograph("yeah.png");
	assert(profile.getPhotograph() == "yeah.png");
}

void Test::GetFormat_ReturnExpectedFormat() {
	profiles profile{ "Andrei", "barosan", 10, "dude.jpg" };

	assert(profile.getPrintFormat() == "Andrei barosan 10 dude.jpg\n");
	assert(profile.getCSVFormat() == "Andrei,barosan,10,dude.jpg\n");
}
