#include <iostream>
#include <ModuleLoader.h>
#include <Module.h>
#include <ModuleDefinition.h>

int main() {
	std::cout << "Hello World from APP1!" << std::endl;

	ModuleLoader loader;
	auto module1 = loader.load(ModuleFile::from("libmodule1.dylib"));
	auto module2 = loader.load(ModuleFile::from("libmodule2.dylib"));
	auto iface1 = module1.getInterface();
	auto iface2 = module2.getInterface();

	(*iface1)((void*)0);
	(*iface2)((void*)0);
	return 0;	
}
