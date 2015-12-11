#include <ModuleLoader.h>
#include <dlfcn.h>

typedef void* module_handle;


// ----------------------------------------

ModuleFile::ModuleFile(const char* const fname)
	: fname(fname)
{}


ModuleFile 
ModuleFile::from(const char* const fnameIn) {
	return ModuleFile{fnameIn};
}

const char* 
ModuleFile::get() {
	return fname;
}


// ----------------------------------------


Module 
ModuleLoader::load(ModuleFile) {
	module_handle lib = dlopen("libmodule1.dylib", RTLD_LAZY);

	if (lib == nullptr)
		throw "error loading module dylib";

	return Module(lib);
}

