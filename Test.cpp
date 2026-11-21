#define NODLLEXPORT
#include "vdjDsp8.h"

const char* strDLLpath = "xxx\plugin.dll";

auto module = LoadLibraryA(strDLLpath);
using DllGetClassObjectNoExport = HRESULT (VDJ_API *)(const GUID&, const GUID&, void**);
auto plugin_DllGetClassObject = reinterpret_cast<DllGetClassObjectNoExport>(GetProcAddress(module, "DllGetClassObject"));

HRESULT hr;
void* plugin_class = nullptr;
hr = plugin_DllGetClassObject(CLSID_VdjPlugin8, IID_IVdjPluginDsp8, &plugin_class);
// if (hr == CLASS_E_CLASSNOTAVAILABLE)
// if (hr == NO_ERROR)
auto plugin = static_cast<IVdjPluginDsp8*>(plugin_class);

plugin->hInstance = nullptr;
// TODO: IVdjCallbacks8 *cb;


hr = plugin->OnLoad();

TVdjPluginInfo8 infos;
hr = plugin->OnGetPluginInfo(&infos);
//infos->PluginName 

ULONG res;
res = plugin->Release();
