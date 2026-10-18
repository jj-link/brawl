#pragma force_active on
extern "C" {
struct muWifiInterfaceTask;
extern muWifiInterfaceTask* g_muWifiInterfaceTask;

muWifiInterfaceTask* fn_14_3EC() {
    return g_muWifiInterfaceTask;
}
}
