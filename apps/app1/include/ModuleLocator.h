#ifndef MODULELOCATOR_H
#define MODULELOCATOR_H


class ModuleFile;


class ModuleLocator {
public:
	ModuleLocator();
	~ModuleLocator();

	void addModule(const ModuleFile&);
};

#endif