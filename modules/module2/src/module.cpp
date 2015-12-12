#include <modules/ModuleDefinition.h>
#include <iostream>
#include <cstdint>
#include <unordered_map>

DEFINE_MODULE("Module1", module_interface, "BE719CA6-A04B-11E5-9F84-C2ED68A460B9");


extern "C" {
	void* say_hello();
	void* say_goodbye();
}

static std::unordered_map<uint64_t,void*> services {
	{0x0000000000000000ul,(void*)say_hello},
	{0x1000000000000000ul,(void*)say_goodbye}
};

extern "C" void* 
module_interface(uint64_t service) {
	return services[service];
}

extern "C" void* say_hello() {
	std::cout << "say_hello is called on module 2" << std::endl;
	return nullptr;
}

extern "C" void* say_goodbye() {
	std::cout << "say_goodbye is called on module 2" << std::endl;
	return nullptr;
}
