#include <ModuleLoader.h>
#include <ModuleFile.h>
#include <dlfcn.h>

typedef void* module_handle;


// ----------------------------------------


Module 
ModuleLoader::load(const ModuleFile& module) {
	module_handle lib = dlopen(module.get(), RTLD_LAZY);

	if (lib == nullptr)
		throw "error loading module dylib";

	return Module(lib);
}

