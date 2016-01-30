#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <Module.h>

class ModuleFile;

class 
ModuleLoader {
public:
	ModuleLoader() = default;

	Module 
	load(const ModuleFile&);
};




#endif