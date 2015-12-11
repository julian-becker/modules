#include <iostream>
#include <ModuleLoader.h>
#include <Module.h>

int main() {
	std::cout << "Hello World from APP1!" << std::endl;

	ModuleLoader loader;
	auto module1 = loader.load(ModuleFile::from("libmodule1.dylib"));
	auto iface = module1.getInterface();

	(*iface)((void*)0);
	return 0;	
}
