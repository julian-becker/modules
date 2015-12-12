#ifndef MODULEDEFINITION_H
#define MODULEDEFINITION_H

#include <cstdint>

#define MODULE_API_VERSION 1u

extern "C" {
  typedef void* (*ModuleInterfaceFn)(uint64_t service);
}

typedef struct {
    const unsigned int apiVersion;
    const char* uuid;
    const char* pluginName;
    ModuleInterfaceFn interface;
} ModuleIdentity;

#define DEFINE_MODULE(pluginName, interface, UUID)      \
  extern "C" {                                          \
      void* interface(uint64_t);       \
      ModuleIdentity identity =  {                      \
          MODULE_API_VERSION,                           \
          UUID,                                         \
          pluginName,                                   \
          interface                                     \
      };                                                \
  }


#endif