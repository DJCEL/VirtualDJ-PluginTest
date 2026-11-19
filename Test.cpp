#include "vdjDsp8.h"

const char* strDLLpath = "xxx\plugin.dll";

auto module = LoadLibraryA(strDLLpath);
using dll_entrypoint_function = HRESULT (VDJ_API *)(const GUID&, const GUID&, void**);
auto dll_entrypoint = reinterpret_cast<dll_entrypoint_function>(GetProcAddress(module, "DllGetClassObject"));
void* class_object = nullptr;
dll_entrypoint(CLSID_VdjPlugin8, IID_IVdjPluginDsp8, &class_object);
auto plugin = static_cast<IVdjPluginDsp8*>(class_object);

TVdjPluginInfo8 infos;
plugin-> OnGetPluginInfo(&infos);
//infos->PluginName 
