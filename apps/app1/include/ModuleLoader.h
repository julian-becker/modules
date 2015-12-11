#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <Module.h>


class 
ModuleFile {
	const char* const fname;
	ModuleFile(const char* const fname);
	
public:
	static ModuleFile
	from(const char* const fnameIn);

	const char* get();
};

class 
ModuleLoader {
public:
	ModuleLoader() = default;

	Module 
	load(ModuleFile);
};




#endif