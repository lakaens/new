#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"

#define NUM_MODULES 1

class Application
{
public:

	Module* modules[NUM_MODULES];

public:

	Application()
	{
		modules[0] = new ModuleDummy();
		// TODO 7: Create your new module "DummyESC"
		// it should check if player it ESC key use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
	}

	// INIT all modules
	bool Init() 
	{
		for(int i = 0; i < NUM_MODULES; ++i)
			modules[i]->Init();
		
		// TODO 5: Make sure that if Init() / PreUpdate/Update/PostUpdate/CleanUP return
		// an exit code App exits correctly.
		return true; 
	}

	// TODO 4: Add PreUpdate and PostUpdate calls

	// UPDATE all modules
		update_status Update() {
			for (int i = 0; i < NUM_MODULES; ++i)
				modules[i]->Update();
			return update_status::UPDATE_CONTINUE;
		}
	

	// EXIT Update 
	bool CleanUp()
	{
		for (int i = NUM_MODULES-1; i >= 0; --i)
			modules[i]->CleanUp();
		return true;
	}

};

#endif // __APPLICATION_H__