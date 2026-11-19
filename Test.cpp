#define NODLLEXPORT
#include "vdjDsp8.h"

const char* strDLLpath = "xxx\plugin.dll";

auto module = LoadLibraryA(strDLLpath);
using DllGetClassObjectNoExport = HRESULT (VDJ_API *)(const GUID&, const GUID&, void**);
auto plugin_DllGetClassObject = reinterpret_cast<DllGetClassObjectNoExport>(GetProcAddress(module, "DllGetClassObject"));

void* plugin_class = nullptr;
plugin_DllGetClassObject(CLSID_VdjPlugin8, IID_IVdjPluginDsp8, &plugin_class);
auto plugin = static_cast<IVdjPluginDsp8*>(plugin_class);

HRESULT hr;
hr = plugin->OnLoad();

TVdjPluginInfo8 infos;
hr = plugin->OnGetPluginInfo(&infos);
//infos->PluginName 

ULONG res;
res = plugin->Release();
