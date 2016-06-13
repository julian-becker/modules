#include <iostream>
#include <ModuleLoader.h>
#include <ModuleFile.h>
#include <Module.h>

int main() {
	std::cout << "Hello World from APP1!" << std::endl;
	void(*say_hello)();
	try {
		ModuleLoader loader;
		auto module1 = loader.load(ModuleFile::from("libmodule1.dylib"));
		auto module2 = loader.load(ModuleFile::from("libmodule2.dylib"));
		auto iface1 = module1.getInterface();
		auto iface2 = module2.getInterface();

		say_hello   = (void(*)())(*iface1)("d6017c06-855b-4749-958a-4fbc32e61ed3");
		auto say_goodbye = (void(*)())(*iface2)("a8ae62a2-8192-4852-9895-91e3bfbc6eaa");
		say_hello();
		say_goodbye();

	}
	catch(const char* ex) {
		std::cerr << ex << std::endl;
	}

	return 0;	
}
