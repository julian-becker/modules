#include <modules/ModuleDefinition.h>
#include <iostream>
#include <cstdint>
#include <unordered_map>

DEFINE_MODULE("Module2", module_interface, "BE719CA6-A04B-11E5-9F84-C2ED68A460B9");


extern "C" {
	void say_hello();
	void say_goodbye();
}

static std::unordered_map<std::string,void*> services {
	{"d6017c06-855b-4749-958a-4fbc32e61ed3",(void*)say_hello},
	{"a8ae62f2-8892-4452-9895-91e3bfbc6eaa",(void*)say_goodbye}
};

extern "C" void* 
module_interface(char const* service) {
	return services[service];
}

extern "C" void say_hello() {
	std::cout << "say_hello is called on module 1" << std::endl;
}

extern "C" void say_goodbye() {
	std::cout << "say_goodbye is called on module 1" << std::endl;
}
