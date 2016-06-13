#include <modules/ModuleDefinition.h>
#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <module.h>

DEFINE_MODULE("Module3", module_interface, "602E7992-C7A2-11E5-98A1-F78BDB915C80");


extern "C" void run_tests() {
	run_mpl_tests();
}

static std::unordered_map<std::string,void*> services {
	{"6f083237-c2a8-4f59-a8e8-17103a1f47a6",(void*)run_tests}
};

extern "C" void* 
module_interface(char const* service) {
	return services[service];
}

