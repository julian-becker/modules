#ifndef MODULE_H
#define MODULE_H

#include <modules/ModuleDefinition.h>
#include <memory>

class Module {
	std::shared_ptr<void> handle;
	
public:
	Module(std::shared_ptr<void> handle);
	~Module();

	ModuleInterfaceFn
	getInterface();
};

#endif