#ifndef MODULEDEFINITION_H
#define MODULEDEFINITION_H

#define MODULE_API_VERSION 1u

extern "C" {
  typedef void (*ModuleInterfaceFn)(void*);
}

typedef struct {
    const unsigned int apiVersion;
    const char* uuid;
    const char* pluginName;
    ModuleInterfaceFn interface;
} ModuleIdentity;

#define DEFINE_MODULE(pluginName, interface, uuid) \
  extern "C" {                                          \
      ModuleIdentity identity =  {                      \
          MODULE_API_VERSION,                           \
          uuid,                                         \
          pluginName,                                   \
          interface                                     \
      };                                                \
  }


#endif