#ifndef MODULEFILE_H
#define MODULEFILE_H

class 
ModuleFile {
	const char* const fname;
	ModuleFile(const char* const fname);
	
public:
	static ModuleFile
	from(const char* const fnameIn);

	const char* get() const;
};


#endif