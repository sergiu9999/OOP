#pragma once
class Test {

public:
	void testAll();



	void AddElementFile_ValidInput_AddedToRepository();
	void AddElementFile_SameObjectTwice_ThrowException();
	void UpdateElementFile_ValidInput_UpdatedProfile();
	void UpdateElementFile_ProfileDoesNotExist_ThrowException();
	void DeleteEntiryFile_ValidInput_DeletedProfile();
	void DeleteEntiryFile_ProfileDoesNotExist_ThrowException();
	void GetAllFile_ValidInput_GetAllEntities();


	void AddElement_ValidInput_AddedToRepository();
	void AddElement_SameObjectTwice_ThrowException();
	void UpdateElement_ValidInput_UpdatedProfile();
	void UpdateElement_ProfileDoesNotExist_ThrowException();
	void DeleteEntiry_ValidInput_DeletedProfile();
	void DeleteEntiry_ProfileDoesNotExist_ThrowException();
	void GetAll_ValidInput_GetAllEntities();

	void AddProfile_ValidInput_AddedToRepository();
	void AddProfile_SameObjectTwice_ThrowException();
	void UpdateProfile_ValidInput_UpdatedProfile();
	void UpdateProfile_ProfileDoesNotExist_ThrowException();
	void DeleteProfileByName_ValidInput_DeletedProfile();
	void DeleteProfileByName_ProfileDoesNotExist_ThrowException();
	void Next_ShouldReturnExpectedFile();
	void Save_ShouldSaveTheWantedFile();
	void FilterProfessionAndAge_BothParameters_ShouldReturnFilteredProfiles();
	void FilterProfessionAndAge_OnlyAgeParameter_ShouldReturnFilteredProfiles();

	void GetName_ValidInput_ReturnName();
	void GetAge_ValidInput_ReturnAge();
	void GetProfession_ValidInput_ReturnProfession();
	void GetPhotograph_ValidInput_ReturnPhotograph();
	void SetName_ValidInput_SetName();
	void SetAge_ValidInput_SetAge();
	void SetProfession_ValidInput_SetProfession();
	void SetPhotograph_ValidInput_SetPhotograph();
	void GetFormat_ReturnExpectedFormat();

};

