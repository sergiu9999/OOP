#include "profiles.h"
#include "profilesRepository.h"
#include "profilesController.h"
#include "profilesUI.h"
#include <assert.h>
#include <iostream>
#include <crtdbg.h>
#include "Test.h"



int main() {



//	Test test{};
	//test.testAll();

	
	profilesFileRepository* repository = new profilesFileRepository{};
	profilesController controller{ repository };
	profilesUI ui{ controller };

	ui.start();
	
	return 0;
}