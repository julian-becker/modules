#ifndef MODULE_H
#define MODULE_H

extern "C" {
	typedef void (*module_interface_t)(void*);
}

class Module {
	void* handle;
	
public:
	Module(void* handle);
	~Module();

	module_interface_t
	getInterface();
};

#endif