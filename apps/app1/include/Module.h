#ifndef MODULE_H
#define MODULE_H

#include <modules/ModuleDefinition.h>

class Module {
	void* handle;
	
public:
	Module(void* handle);
	~Module();

	ModuleInterfaceFn
	getInterface();
};

#endif