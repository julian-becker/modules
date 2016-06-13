#include <Module.h>
#include <dlfcn.h>
#include <modules/ModuleDefinition.h>

Module::Module(std::shared_ptr<void> handle)
	: handle(std::move(handle))
{}

Module::~Module() {}

ModuleInterfaceFn
Module::getInterface() {
	auto identity = (const ModuleIdentity*)dlsym(handle.get(),"identity");

	if (identity == nullptr) {
		throw dlerror();
	}

	return identity->interface;
}
