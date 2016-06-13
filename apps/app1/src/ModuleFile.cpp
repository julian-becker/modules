#include <ModuleFile.h>
#include <dlfcn.h>
#include <memory>

typedef std::shared_ptr<void> module_handle;


// ----------------------------------------

ModuleFile::ModuleFile(const char* const fname)
	: fname(fname)
{}


ModuleFile 
ModuleFile::from(const char* const fnameIn) {
	return ModuleFile{fnameIn};
}

const char* 
ModuleFile::get() const {
	return fname;
}
