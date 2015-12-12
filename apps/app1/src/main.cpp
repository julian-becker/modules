#include <iostream>
#include <ModuleLoader.h>
#include <Module.h>

int main() {
	std::cout << "Hello World from APP1!" << std::endl;

	ModuleLoader loader;
	auto module1 = loader.load(ModuleFile::from("libmodule1.dylib"));
	auto module2 = loader.load(ModuleFile::from("libmodule2.dylib"));
	auto iface1 = module1.getInterface();
	auto iface2 = module2.getInterface();

	auto say_hello = (void*(*)())(*iface1)(0x0000000000000000ul);
	say_hello();
	auto say_goodbye = (void*(*)())(*iface2)(0x1000000000000000ul);
	say_goodbye();
	return 0;	
}
