#include <modules/ModuleDefinition.h>
#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <module.h>

DEFINE_MODULE("Module3", module_interface, "602E7992-C7A2-11E5-98A1-F78BDB915C80");


extern "C" void run_tests() {
	run_mpl_tests();
}

static std::unordered_map<uint64_t,void*> services {
	{0x0000000000000010ul,(void*)run_tests}
};

extern "C" void* 
module_interface(uint64_t service) {
	return services[service];
}

