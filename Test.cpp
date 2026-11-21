#define NODLLEXPORT
#include "vdjDsp8.h"

const char* strDLLpath = "xxx\plugin.dll";

auto module = LoadLibraryA(strDLLpath);
using DllGetClassObjectNoExport = HRESULT (VDJ_API *)(const GUID&, const GUID&, void**);
auto plugin_DllGetClassObject = reinterpret_cast<DllGetClassObjectNoExport>(GetProcAddress(module, "DllGetClassObject"));

HRESULT hr;
void* plugin_class = nullptr;
hr = plugin_DllGetClassObject(CLSID_VdjPlugin8, IID_IVdjPluginDsp8, &plugin_class);
auto plugin = static_cast<IVdjPluginDsp8*>(plugin_class);
        
// TODO: define IVdjCallbacks8;


hr = plugin->OnLoad();

TVdjPluginInfo8 infos;
hr = plugin->OnGetPluginInfo(&infos);
//infos->PluginName 

ULONG res;
res = plugin->Release();
