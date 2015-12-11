#include <Module.h>
#include <dlfcn.h>
#include <ModuleDefinition.h>

Module::Module(void* handle)
	: handle(handle) 
{}

Module::~Module() {}

ModuleInterfaceFn
Module::getInterface() {
	auto identity = (const ModuleIdentity*)dlsym(handle,"identity");

	if (identity == nullptr)
		throw "error getting module interface";

	return identity->interface;
}
