#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" void fn_80146574(void* p);
extern u8 g_Network[];
extern s32 lbl_805A02A0;

extern "C" void fn_800C753C(void) {
    if (g_muWifiInterfaceTask != 0) {
        fn_80146574(g_Network);
        g_muWifiInterfaceTask->unlink();
        delete g_muWifiInterfaceTask;
        g_muWifiInterfaceTask = 0;
        lbl_805A02A0 = 0;
    }
}
