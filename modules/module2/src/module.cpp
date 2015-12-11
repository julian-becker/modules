#include <iostream>

extern "C" void 
module_interface(void* args) {
	std::cout << "Hello from MODULE2!!!" << std::endl;
}
