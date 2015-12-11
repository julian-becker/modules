#include <ModuleDefinition.h>
#include <iostream>

extern "C" void 
module_interface(void* args);

DEFINE_MODULE("Module2", module_interface, "718EB018-A00A-11E5-A42E-4F4C358CC448");


extern "C" void 
module_interface(void* args) {
	std::cout << "Hello from MODULE1!!!" << std::endl;
}
