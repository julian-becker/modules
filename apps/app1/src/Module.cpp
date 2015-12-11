#include <Module.h>
#include <dlfcn.h>

Module::Module(void* handle)
	: handle(handle) 
{}

Module::~Module() {}

module_interface_t
Module::getInterface() {
	auto iface = (module_interface_t)dlsym(handle,"module_interface");

	if (iface == nullptr)
		throw "error getting module interface";

	return iface;
}
