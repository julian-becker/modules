#include <ModuleLoader.h>
#include <ModuleFile.h>
#include <dlfcn.h>
#include <iostream>


// ----------------------------------------


Module 
ModuleLoader::load(const ModuleFile& module) {
	auto lib = std::shared_ptr<void>(dlopen(module.get(), RTLD_LAZY), 
		[](void* p) { if(p) dlclose(p); });

	if (!lib) {
		throw dlerror();
	}

	return Module(std::move(lib));
}