#include <ModuleDefinition.h>
#include <iostream>

extern "C" void 
module_interface(void* args);

DEFINE_MODULE("Module2", module_interface, "3C7E20F8-A009-11E5-AB09-7F2F69A460B9");

extern "C" void 
module_interface(void* args) {
	std::cout << "Hello from MODULE2!!!" << std::endl;
}
