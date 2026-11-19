#define NODLLEXPORT
#include "vdjDsp8.h"

const char* strDLLpath = "xxx\plugin.dll";

auto module = LoadLibraryA(strDLLpath);
using DllGetClassObjectNoExport = HRESULT (VDJ_API *)(const GUID&, const GUID&, void**);
auto __DllGetClassObject = reinterpret_cast<DllGetClassObjectNoExport>(GetProcAddress(module, "DllGetClassObject"));

void* plugin_class = nullptr;
__DllGetClassObject(CLSID_VdjPlugin8, IID_IVdjPluginDsp8, &plugin_class);
auto plugin = static_cast<IVdjPluginDsp8*>(plugin_class);

TVdjPluginInfo8 infos;
plugin->OnGetPluginInfo(&infos);
//infos->PluginName 
